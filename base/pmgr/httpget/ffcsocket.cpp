/* Free Foundation Classes for network ver.0.3.0
 * 
 * This software is in the public domain.
 * There are no restrictions on any sort of usage of this software.
 */

#include "ffcsocket.h"

#include "ffcaddress.h"

#include <stdio.h>
#include <string.h>

#ifdef WIN32
#  include <stdlib.h>
#  define CLOSE(sock) closesocket(sock)
#  define SOCKLEN_T int
#else
#  include <sys/types.h>
#  include <sys/time.h>
#  include <unistd.h>
#  include <sys/socket.h>
#  include <arpa/inet.h>
#  define CLOSE(sock) ::close(sock)
#  define SOCKLEN_T int
#  ifndef INVALID_SOCKET
#    define INVALID_SOCKET (-1)
#  endif
#endif

static int socket_count = 0;


void FFCSocket::__init_class__()
{
  status = 0;
  cstatus = 0;
  clen = 0;
}


void FFCSocket::start()
{
  #ifdef WIN32
  WORD v = MAKEWORD(1, 1);
  WSADATA d;
  WSAStartup(v, &d);
  //atexit((void(*)())WSACleanup);
  #endif
}


void FFCSocket::end()
{
  #ifdef WIN32
  WSACleanup();
  #endif
}


FFCSocket::FFCSocket()
{
  __init_class__();
  
  status  = NONE;
  cstatus = NONE;
  
  if(socket_count == 0) start();
  socket_count++;
}


FFCSocket::~FFCSocket()
{
  close();
  
  socket_count--;
  if(socket_count == 0) end();
}


bool FFCSocket::connect(FFCAddress& addr, bool tcp /*= false*/)
{
  close();
  if(!addr.getStruct()) return false;
  
  if(tcp) {
    sock = socket(PF_INET, SOCK_STREAM, 0);
    status = CON_TCP;
  } else {
    sock = socket(PF_INET, SOCK_DGRAM, 0);
    status = CON_UDP;
  }
  if(sock == INVALID_SOCKET) {
    status = NONE;
    return false;
  }
  
  memset((char*)&saddr, 0, sizeof(saddr));
  saddr.sin_family = PF_INET;
  saddr.sin_addr = *addr.getStruct();
  saddr.sin_port = htons(addr.getPort());
  
  if(::connect(sock, (SOCKADDR*)&saddr, sizeof(saddr)) < 0) {
    CLOSE(sock);
    status = NONE;
    return false;
  }
  
  return true;
}


bool FFCSocket::bind(int port, bool tcp /*= false*/)
{
  close();
  
  if(tcp) {
    sock = socket(PF_INET, SOCK_STREAM, 0);
    status = BIND_TCP;
  } else {
    sock = socket(PF_INET, SOCK_DGRAM, 0);
    status = BIND_UDP;
  }
  if(sock == INVALID_SOCKET) {
    status = NONE;
    return false;
  }
  
  memset((char*)&saddr, 0, sizeof(saddr));
  saddr.sin_family = PF_INET;
  saddr.sin_addr.s_addr = htonl(INADDR_ANY);
  saddr.sin_port = htons(port);
  
  if(::bind(sock, (struct sockaddr*)&saddr, sizeof(saddr)) < 0) {
    CLOSE(sock);
    status = NONE;
    return false;
  }
  if(tcp && listen(sock, 5) < 0) {
    CLOSE(sock);
    status = NONE;
    return false;
  }
  
  return true;
}


bool FFCSocket::accept()
{
  if(status != BIND_TCP) return false;
  
  if(cstatus != NONE) {
    CLOSE(csock);
    cstatus = NONE;
  }
  
  clen = sizeof(caddr);
  csock = ::accept(sock, (struct sockaddr*)&caddr, (SOCKLEN_T*)&clen);
  if(csock < 0) return false;
  
  cstatus = CON_TCP;
  return true;
}


void FFCSocket::close()
{
  if(cstatus != NONE) {
    shutdown();
  }
  if(status != NONE) {
    CLOSE(sock);
    status = NONE;
  }
}


void FFCSocket::shutdown(int how /*= 2*/)
{
  if(cstatus != NONE) {
    //waitForReady();
    ::shutdown(csock, how);
    CLOSE(csock);
    cstatus = NONE;
  } else if(status != NONE) {
    ::shutdown(sock, how);
  }
}


SOCKET FFCSocket::getSocket() const
{
  if(status == NONE) return 0;
  if(status == BIND_TCP && cstatus == CON_TCP) return csock;
  return sock;
}


FFCSocket& FFCSocket::operator<<(const char* str)
{
  SOCKET s;
  int len = 0;
  int i = 0;
  int slen = 0;
  
  s = getSocket();
  if(s) {
    len = strlen(str);
    for(i = 0; i < len; i += slen) {
      waitForReady();
      slen = send(s, str + i, len - i, 0);
      if(slen <= 0) break;
    }
  }
  return *this;
}


FFCSocket& FFCSocket::operator<<(int num)
{
  char buf[16];
  snprintf(buf, 16, "%d", num);
  return operator<<(buf);
}


FFCSocket& FFCSocket::operator>>(std::string& str)
{
  SOCKET s;
  char c = 0;
  
  str.erase();
  
  s = getSocket();
  if(s) {
    for(;;) {
      waitForReady();
      if(::recv(s, &c, 1, 0) <= 0) break;
      if (c != '\r') str += c;
      if(c == '\n') break;
    }
  }
  
  return *this;
}


FFCSocket& FFCSocket::operator>>(char& ch)
{
  SOCKET s;
  
  ch = '\0';
  s = getSocket();
  if(s) {
    waitForReady();
    if(::recv(s, &ch, 1, 0) <= 0) ch = '\0';
  }
  return *this;
}


FFCSocket& FFCSocket::recv(std::string& str, int len /*= 1*/)
{
  SOCKET s;
  char* buf = 0;
  int buflen = 0;
  int result = 0;
  
  str.erase();
  
  s = getSocket();
  if(s && len > 0) {
    buf = new char[len + 1];
    while(buflen < len) {
      waitForReady();
      result = ::recv(s, buf + buflen, len - buflen, 0);
      if(result <= 0) break;
      buflen += result;
    }
    buf[buflen] = '\0';
    str = buf;
    delete [] buf;
  }
  
  return *this;
}


bool FFCSocket::waitForReady()
{
  SOCKET s;
  fd_set rfds;
  fd_set wfds;
  fd_set xfds;
  struct timeval tv;
  
  s = getSocket();
  if(!s) return false;
  
  tv.tv_sec  = 5;
  tv.tv_usec = 0;
  FD_ZERO(&rfds);
  FD_ZERO(&wfds);
  FD_ZERO(&xfds);
  FD_SET(s, &rfds);
  FD_SET(s, &wfds);
  FD_SET(s, &xfds);
  if(select(s + 1, &rfds, &wfds, &xfds, &tv) <= 0) return false;
  return true;
}
