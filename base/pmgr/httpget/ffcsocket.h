/* Free Foundation Classes for network ver.0.3.0
 * 
 * This software is in the public domain.
 * There are no restrictions on any sort of usage of this software.
 */

#ifndef _FFCSOCKET_H_
#define _FFCSOCKET_H_

class FFCAddress;

#include <string>

#include <sys/types.h>

#ifdef WIN32
#  include <winsock2.h>
#else
#  include <netinet/in.h>
#  define SOCKET int
#  define SOCKADDR    struct sockaddr
#  define SOCKADDR_IN struct sockaddr_in
#endif


class FFCSocket
{
public:
  inline int getStatus() const { return status; }
  inline operator int() const { return sock; }

public:
  enum { NONE, CON_TCP, CON_UDP, BIND_TCP, BIND_UDP };
  
public:
  static void start();
  static void end();
  FFCSocket();
  virtual ~FFCSocket();
  bool connect(FFCAddress& addr, bool tcp = false);
  bool bind(int port, bool tcp = false);
  bool accept();
  void close();
  void shutdown(int how = 2);
  SOCKET getSocket() const;
  FFCSocket& operator<<(const char* str);
  FFCSocket& operator<<(int num);
  FFCSocket& operator>>(std::string& str);
  FFCSocket& operator>>(char& ch);
  FFCSocket& recv(std::string& str, int len = 1);
  bool waitForReady();
  
private:
  void __init_class__();
  
protected:
  int status;
  SOCKET sock;
  SOCKADDR_IN saddr;
  int cstatus;
  SOCKET csock;
  SOCKADDR_IN caddr;
  int clen;
};

#endif // _FFCSOCKET_H_
