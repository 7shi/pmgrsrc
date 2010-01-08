/* Copyright (c) 1996 by Internet Software Consortium.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS
 * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE
 * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

#ifndef INT16SZ
#define INT16SZ sizeof(apr_int16_t)
#endif

#ifndef __P
#define __P(x) x
#endif

/*
 * WARNING: Don't even consider trying to compile this on a system where
 * sizeof(int) < 4.  sizeof(int) > 4 is fine; all the world's not a VAX.
 */

static const char *inet_ntop4 __P((const unsigned char *src, char *dst, size_t size));

/* char *
 * inet_ntop(af, src, dst, size)
 *  convert a network format address to presentation format.
 * return:
 *  pointer to presentation format address (`dst'), or NULL (see errno).
 * author:
 *  Paul Vixie, 1996.
 */
const char *
inet_ntop(int af, const void *src, char *dst, size_t size)
{
    switch (af) {
    case AF_INET:
        return (inet_ntop4(src, dst, size));
    default:
        errno = EAFNOSUPPORT;
        return (NULL);
    }
    /* NOTREACHED */
}

/* const char *
 * inet_ntop4(src, dst, size)
 *  format an IPv4 address, more or less like inet_ntoa()
 * return:
 *  `dst' (as a const)
 * notes:
 *  (1) uses no statics
 *  (2) takes a u_char* not an in_addr as input
 * author:
 *  Paul Vixie, 1996.
 */
static const char *
inet_ntop4(const unsigned char *src, char *dst, size_t size)
{
    const size_t MIN_SIZE = 16; /* space for 255.255.255.255\0 */
    int n = 0;
    char *next = dst;

    if (size < MIN_SIZE) {
        errno = ENOSPC;
        return NULL;
    }
    do {
        unsigned char u = *src++;
        if (u > 99) {
        *next++ = '0' + u/100;
        u %= 100;
        *next++ = '0' + u/10;
        u %= 10;
        }
        else if (u > 9) {
        *next++ = '0' + u/10;
        u %= 10;
        }
        *next++ = '0' + u;
        *next++ = '.';
        n++;
    } while (n < 4);
    *--next = 0;
    return dst;
}
