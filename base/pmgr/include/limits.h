/* fixups */

#ifndef __LIMITS_H_FIXUPS__
#define __LIMITS_H_FIXUPS__

#include "/usr/include/limits.h"

#ifdef LONG_MIN
#undef LONG_MIN
#define LONG_MIN      (-9223372036854775807LL - 1)   /* 0x8000000000000000 */
#endif

#ifdef ULLONG_MAX
#undef ULLONG_MAX
#define ULLONG_MAX    0xffffffffffffffffULL       /* maximum unsigned long long int value */
#endif

#ifdef LLONG_MAX
#undef LLONG_MAX
#define LLONG_MAX     9223372036854775807LL       /* maximum signed long long int value */
#endif

#ifdef LLONG_MIN
#undef LLONG_MIN
#define LLONG_MIN     (-9223372036854775807LL - 1)  /* minimum signed long long int value */
#endif

#ifdef SIZE_T_MAX
#undef SIZE_T_MAX
#define SIZE_T_MAX	0xffffffffffffffffULL
#endif

#endif /* __LIMITS_H_FIXUPS__ */
