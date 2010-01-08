/* Free Foundation Classes for network ver.0.3.0
 * 
 * This software is in the public domain.
 * There are no restrictions on any sort of usage of this software.
 */

#include "ffchttp.h"


#include <stdio.h>

#define BUFSIZE 1024

#ifdef WIN32
#  define FILE_WRITE "wb"
#else
#  include <sys/socket.h>
#  define FILE_WRITE "w"
#endif

static std::string userAgent = "FFCHTTP/"FFCHTTPVER;


static std::string toLower(const std::string& str)
{
  std::string ret;
  const char* s = str.data();
  for (unsigned int i = 0; i < str.length(); i++) ret += (char)tolower(s[i]);
  return ret;
}


void FFCHTTP::__init_class__()
{
  result = 0;
  flgCancel = 0;
  count = 0;
}


FFCHTTP::FFCHTTP(): FFCSocket()
{
  __init_class__();
  
}


FFCHTTP::~FFCHTTP()
{
}


void FFCHTTP::setProxy(const FFCAddress& prx)
{
  proxy = prx;
}


void FFCHTTP::unsetProxy()
{
  proxy.clear();
}


bool FFCHTTP::connect(FFCAddress& addr)
{
  if(proxy.getStruct()) {
    return FFCSocket::connect(proxy, true);
  }
  return FFCSocket::connect(addr, true);
}


bool FFCHTTP::get(FFCURL url, const std::string& ref /*= ""*/)
{
  if(!request("GET ", url, ref)) return false;
  
  sendRequest("");
  return true;
}


/**
  POST / HTTP/1.1
  Content-Type: application/x-www-form-urlencoded
  Host: 192.168.0.101:50000
  Content-Length: 7
  Connection: close
  
  abc=123
*/

bool FFCHTTP::post(FFCURL url, const FFCStringMap& d, const std::string& ref /*= ""*/)
{
  std::string pd;
  std::string len;
  std::string line;
  
  if(!request("POST ", url, ref)) return false;
  
  pd = makePost(d);
  char buf[16];
  snprintf(buf, 16, "%d", pd.length());
  len = buf;
  sendRequest("Content-Length", len);
  sendRequest("");
  sendRequest(pd);
  return true;
}


bool FFCHTTP::request(const std::string& cmd, FFCURL& url, const std::string& ref /*= ""*/)
{
  dctRequest.clear();
  strRequest.erase();
  dctHeader.clear();
  header.erase();
  result = 0;
  if(count) *count = 0;
  
  if(!connect(url) || checkCancel()) return false;
  
  if(proxy.getStruct()) {
    sendRequest(cmd + url.getURL() + " HTTP/1.1");
  } else {
    sendRequest(cmd + url.getPath() + " HTTP/1.1");
  }
  
  if(url.getPort() == 80) {
    sendRequest("Host", url.getAddress());
  } else {
    char buf[16];
    snprintf(buf, 16, "%d", url.getPort());
    sendRequest("Host", url.getAddress() + ":" + buf);
  }
  
  sendRequest("User-Agent", userAgent);
  if(!ref.empty()) sendRequest("Referer", ref);
  sendRequest("Connection", "close");
  
  return true;
}


void FFCHTTP::sendRequest(const std::string& hdr, const std::string& val)
{
  if(status == NONE || checkCancel()) return;
  
  dctRequest[toLower(hdr)] = val;
  strRequest += hdr + ": " + val + "\n";
  *this << hdr.data() << ": " << val.data() << "\r\n";
}


void FFCHTTP::sendRequest(const std::string& rq)
{
  if(status == NONE || checkCancel()) return;
  
  strRequest += rq + "\n";
  *this << rq.data() << "\r\n";
}


bool FFCHTTP::readHeader()
{
  std::string line;
  int p1 = 0;
  int p2 = 0;
  
  if(status == NONE || checkCancel()) return false;
  
  result = 0;
  resultText.erase();
  while(line != "\n" && !checkCancel()) {
    *this >> line;
    int len = line.length();
    if(len == 0) {
      shutdown();
      close();
      return false;
    }
    if(header.empty()) {
      p1 = line.find(' ');
      if(p1 > 0) {
        p2 = line.find(' ', p1 + 1);
        if(p2 > 0) {
          result = atoi(line.substr(p1 + 1, p2 - p1 - 1).data());
          resultText = line.substr(0, len - 1);
        }
      }
    } else {
      p1 = line.find(':');
      if(p1 > 0) {
        p2 = p1 + 1;
        while(line[p2] == ' ' && p2 < len) p2++;
        if(p2 < len) {
          dctHeader[toLower(line.substr(0, p1))] = line.substr(p2, len - p2 - 1);
        }
      }
    }
    header += line;
  }
  
  return true;
}


/**
  ダウンロードしてファイルに保存
*/

bool FFCHTTP::save(const std::string& fn, void (*progress)(int, int))
{
  if(status == NONE || checkCancel()) return false;
  if(header.empty() && !readHeader()) return false;
  if(result != 200) return false;
  
  int len = 0, pos = 0;
  std::string slen = getHeader("Content-Length");
  if (!slen.empty()) len = atoi(slen.data());
  
  // Data
  FILE* f = fopen(fn.data(), FILE_WRITE);
  if(f) {
    SOCKET s = getSocket();
    char buf[BUFSIZE];
    for (bool finish = false; !finish;) {
      int bufsize = BUFSIZE;
      if (len == 0) {
        std::string line;
        if (pos > 0) *this >> line;
        *this >> line;
        bufsize = strtol(line.data(), NULL, 16);
        if (bufsize == 0) break;
      }
      while (bufsize > 0) {
        if (progress != NULL) (*progress)(pos, len);
        int readlen = bufsize;
        if (readlen > BUFSIZE) readlen = BUFSIZE;
        int recvlen = ::recv(s, buf, readlen, 0);
        if (recvlen <= 0 || checkCancel()) {
          finish = true;
          break;
        }
        bufsize -= recvlen;
        fwrite(buf, 1, recvlen, f);
        pos += recvlen;
        if (count) *count += recvlen;
      }
    }
    if (progress != NULL) (*progress)(pos, len);
    fclose(f);
  }
  
  shutdown();
  close();
  return f != NULL && !checkCancel();
}


std::string FFCHTTP::getHeader(const std::string& hdr)
{
  FFCStringMap::iterator it = dctHeader.find(toLower(hdr));
  return it == dctHeader.end() ? "" : it->second;
}


std::string FFCHTTP::makePost(FFCStringMap d)
{
  std::string ret;
  FFCStringMap::iterator it;
  
  for(it = d.begin(); it != d.end(); it++) {
    if(!ret.empty()) ret += "&";
    ret += it->first + "=" + FFCURL::encode(it->second);
  }
  return ret;
}


void FFCHTTP::setUserAgent(const std::string& agent)
{
  userAgent = agent;
}


std::string FFCHTTP::getUserAgent()
{
  return userAgent;
}
