/* Free Foundation Classes for network ver.0.3.0
 * 
 * This software is in the public domain.
 * There are no restrictions on any sort of usage of this software.
 */

#ifndef _FFCHTTP_H_
#define _FFCHTTP_H_

#include "ffcaddress.h"
#include "ffcurl.h"

#include <string>
#include <map>
typedef std::map<std::string, std::string> FFCStringMap;

#include "ffcsocket.h"
#include <stdlib.h>

#define FFCHTTPVER "0.3.0"


class FFCHTTP: public FFCSocket
{
public:
  inline const std::string& getRequest() const { return strRequest; }
  inline const std::string& getHeader() const { return header; }
  inline const FFCStringMap& getRequestDict() const { return dctRequest; }
  inline const FFCStringMap& getHeaderDict() const { return dctHeader; }
  inline int getResult() const { return result; }
  inline const std::string& getResultText() const { return resultText; }
  inline bool checkCancel() const { return flgCancel && *flgCancel; }
  inline void setCancel(bool* flg) { flgCancel = flg; }
  inline void setCount(int* c) { count = c; }
  
public:
  FFCHTTP();
  virtual ~FFCHTTP();
  void setProxy(const FFCAddress& prx);
  void unsetProxy();
  bool connect(FFCAddress& addr);
  bool get(FFCURL url, const std::string& ref = "");
  bool post(FFCURL url, const FFCStringMap& d, const std::string& ref = "");
  bool readHeader();
  bool save(const std::string& fn, void (*progress)(int, int) = 0);
  std::string getHeader(const std::string& hdr);
  static std::string makePost(FFCStringMap d);
  static void setUserAgent(const std::string& agent);
  static std::string getUserAgent();
  
protected:
  bool request(const std::string& cmd, FFCURL& url, const std::string& ref = "");
  void sendRequest(const std::string& hdr, const std::string& val);
  void sendRequest(const std::string& rq);
  
private:
  void __init_class__();
  
protected:
  FFCAddress proxy;
  FFCStringMap dctRequest;
  std::string strRequest;
  FFCStringMap dctHeader;
  int result;
  std::string resultText;
  std::string header;
  bool* flgCancel;
  int* count;
};

#endif // _FFCHTTP_H_
