/* Free Foundation Classes for network ver.0.3.0
 * 
 * This software is in the public domain.
 * There are no restrictions on any sort of usage of this software.
 */

#ifndef _FFCURL_H_
#define _FFCURL_H_

#include <string>
#include "ffcaddress.h"


class FFCURL: public FFCAddress
{
public:
  inline operator const char*() const { return getURL().data(); }
  inline std::string getPath() const { return path; }
  
public:
  FFCURL();
  FFCURL(const char* url);
  FFCURL(const std::string& url);
  FFCURL(const FFCURL& url);
  std::string getURL() const;
  void setURL(const std::string& url);
  void setURL(std::string url, FFCURL ref);
  std::string getFile() const;
  std::string getDir() const;
  std::string getUpDir() const;
  FFCURL& operator=(const std::string& url);
  FFCURL& operator=(const char* url);
  FFCURL& operator=(const FFCURL& url);
  static std::string encode(const std::string& s);
  
protected:
  std::string path;
};

#endif // _FFCURL_H_
