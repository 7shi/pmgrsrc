/* Free Foundation Classes for network ver.0.3.0
 * 
 * This software is in the public domain.
 * There are no restrictions on any sort of usage of this software.
 */

#include "ffcaddress.h"

#include <stdio.h>
#ifndef WIN32
#  include <sys/socket.h>
#  include <arpa/inet.h>
#  include <netdb.h>
#endif


void FFCAddress::__init_class__()
{
  flag = false;
  port = 0;
}


FFCAddress::FFCAddress()
{
  __init_class__();
  
  clear();
}


FFCAddress::FFCAddress(const char* ad)
{
  __init_class__();
  
  setAddress(ad);
}


FFCAddress::FFCAddress(const std::string& ad)
{
  __init_class__();
  
  setAddress(ad);
}


FFCAddress::FFCAddress(const std::string& ad, int p)
{
  __init_class__();
  
  setAddress(ad, p);
}


FFCAddress::FFCAddress(int ad1, int ad2, int ad3, int ad4, int p /*= 0*/)
{
  __init_class__();
  
  setAddress(ad1, ad2, ad3, ad4, p);
}


FFCAddress::FFCAddress(const FFCAddress& ad)
{
  __init_class__();
  
  operator=(ad);
}


FFCAddress::~FFCAddress()
{
}


void FFCAddress::clear()
{
  addr.s_addr = INADDR_NONE;
  address.erase();
  port = 0;
  flag = false;
}


void FFCAddress::setAddress(int ad1, int ad2, int ad3, int ad4, int p /*= 0*/)
{
  clear();
  if(ad1 < 0 || ad1 > 255) return;
  if(ad2 < 0 || ad2 > 255) return;
  if(ad3 < 0 || ad3 > 255) return;
  if(ad4 < 0 || ad4 > 255) return;
  
  char buf[64];
  snprintf(buf, 64, "%d.%d.%d.%d", ad1, ad2, ad3, ad4);
  address = buf;
  port = p;
}


void FFCAddress::setAddress(const std::string& ad)
{
  int p = 0;
  
  clear();
  
  p = ad.find(':');
  if(p < 0) {
    address = ad;
  } else {
    address = ad.substr(0, p);
    port = atoi(ad.substr(p + 1).data());
  }
}


void FFCAddress::setAddress(const std::string& ad, int p)
{
  address = ad;
  port = p;
}


FFCAddress& FFCAddress::operator=(const std::string& ad)
{
  setAddress(ad);
  return *this;
}


FFCAddress& FFCAddress::operator=(const FFCAddress& ad)
{
  addr = ad.addr;
  address = ad.address;
  port = ad.port;
  flag = ad.flag;
  return *this;
}


const struct in_addr* FFCAddress::getStruct()
{
  if(!flag && !address.empty()) {
    setStruct();
    flag = true;
  }
  if(addr.s_addr == INADDR_NONE) return NULL;
  return &addr;
}


void FFCAddress::setStruct()
{
  addr.s_addr = inet_addr(address.data()); // a.b.c.d?
  if(addr.s_addr != INADDR_NONE) return;
  
  struct hostent* host = gethostbyname(address.data());
  if(host) addr = *(struct in_addr*)*host->h_addr_list;
}
