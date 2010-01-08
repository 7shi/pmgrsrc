/* Free Foundation Classes for network ver.0.3.0
 * 
 * This software is in the public domain.
 * There are no restrictions on any sort of usage of this software.
 */

#include "ffcurl.h"


FFCURL::FFCURL(): FFCAddress()
{
}


FFCURL::FFCURL(const char* url): FFCAddress()
{
  setURL(url);
}


FFCURL::FFCURL(const std::string& url): FFCAddress()
{
  setURL(url);
}


FFCURL::FFCURL(const FFCURL& url)
{
  operator=(url);
}


std::string FFCURL::getURL() const
{
  std::string ret;
  
  ret = "http://" + address;
  if(port != 80){
    char buf[16];
    snprintf(buf, 16, ":%d", port);
    ret += buf;
  }
  ret += path;
  return ret;
}


void FFCURL::setURL(const std::string& url)
{
  std::string ad;
  int p = 0;
  
  clear();
  path.erase();
  
  if(url.substr(0, 7) == "http://") {
    ad = url.substr(7);
  } else {
    ad = url;
  }
  
  p = ad.find('/');
  if(p < 0) {
    path = "/";
  } else {
    path = ad.substr(p);
    ad = ad.substr(0, p);
  }
  
  p = ad.find(':');
  if(p == 0) {
    address = "127.0.0.1";
  } else if(p > 0) {
    address = ad.substr(0, p);
    port = atoi(ad.substr(p + 1).data());
  } else {
    address = ad;
  }
  if(port == 0) port = 80;
}


void FFCURL::setURL(std::string url, FFCURL ref)
{
  if(url.substr(0, 7) == "http://") {
    setURL(url);
    return;
  }
  
  clear();
  path = "/";
  address = ref.getAddress();
  port = ref.getPort();
  
  if(url.substr(0, 1) == "/") {
    path = url;
    return;
  }
  
  for(;;) {
    if(url.substr(0, 2) == "./") {
      url = url.substr(2);
    } else if(url.substr(0, 3) == "../") {
      ref.setURL(ref.getUpDir(), ref);
      url = url.substr(3);
    } else {
      break;
    }
  }
  path = ref.getDir() + url;
  return;
}


std::string FFCURL::getFile() const
{
  std::string ret;
  int p = 0;
  
  if(address.empty()) return "";
  
  p = path.rfind('/');
  if(p < 0 || p + 1 == path.size()) return "index.html";
  
  return path.substr(p + 1);
}


std::string FFCURL::getDir() const
{
  std::string ret;
  int p = 0;
  
  if(address.empty()) return "";
  
  p = path.rfind('/');
  if(p < 0) return "/";
  
  return path.substr(0, p + 1);
}


std::string FFCURL::getUpDir() const
{
  std::string ret;
  int p = 0;
  
  ret = getDir();
  if(ret.empty() || ret == "/") return ret;
  
  ret = ret.substr(0, ret.size() - 1);
  p = ret.rfind('/');
  if(p < 0) return "/";
  
  return ret.substr(0, p + 1);
}


FFCURL& FFCURL::operator=(const std::string& url)
{
  setURL(url);
  return *this;
}


FFCURL& FFCURL::operator=(const char* url)
{
  setURL(url);
  return *this;
}


FFCURL& FFCURL::operator=(const FFCURL& url)
{
  FFCAddress::operator=(url);
  path = url.path;
  return *this;
}


std::string FFCURL::encode(const std::string& s)
{
  std::string ret;
  std::string x;
  int len = 0;
  int i = 0;
  int ch = 0;
  
  len = s.length();
  for(i = 0; i < len; i++) {
    ch = (unsigned char)s[i];
    if(
         ch == '*' || ch == '_' || ch == '.' || ch == '@' || ch == '-'
      || ('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z')
      || ('0' <= ch && ch <= '9')
    ) {
      ret += char(ch);
    } else {
      char buf[16];
      snprintf(buf, 16, "%%%02x", int(ch));
      ret += buf;
    }
  }
  return ret;
}
