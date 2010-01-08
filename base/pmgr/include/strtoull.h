#ifndef __STRTOLL__
#define __STRTOLL__

#ifdef __cplusplus
extern "C" {
#endif

extern unsigned long long
strtoull(const char * __restrict nptr, char ** __restrict endptr, int base);

#ifdef __cplusplus
}
#endif

#endif
