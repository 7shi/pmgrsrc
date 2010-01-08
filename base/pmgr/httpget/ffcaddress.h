/* Free Foundation Classes for network ver.0.3.0
 * 
 * This software is in the public domain.
 * There are no restrictions on any sort of usage of this software.
 */

#ifndef _FFCADDRESS_H_
#define _FFCADDRESS_H_

#include <string>

#include <sys/types.h>
#ifdef WIN32
#  include <winsock2.h>
#else
#  include <netinet/in.h>
#endif


class FFCAddress
{
public:
  inline std::string getAddress() const { return address; }
  inline operator const char*() const { return address.data(); }
  inline int getPort() const { return port; }
  inline void setPort(int p) { port = p; }
  inline operator const struct in_addr*() { return getStruct(); }
  
public:
  FFCAddress();
  FFCAddress(const char* ad);
  FFCAddress(const std::string& ad);
  FFCAddress(const std::string& ad, int p);
  FFCAddress(int ad1, int ad2, int ad3, int ad4, int p = 0);
  FFCAddress(const FFCAddress& ad);
  virtual ~FFCAddress();
  void clear();
  void setAddress(int ad1, int ad2, int ad3, int ad4, int p = 0);
  void setAddress(const std::string& ad);
  void setAddress(const std::string& ad, int p);
  FFCAddress& operator=(const std::string& ad);
  FFCAddress& operator=(const FFCAddress& ad);
  const struct in_addr* getStruct();
  
protected:
  void setStruct();
  
private:
  void __init_class__();
  
protected:
  struct in_addr addr;
  bool flag;
  std::string address;
  int port;
};

#endif // _FFCADDRESS_H_
