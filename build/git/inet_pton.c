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

#ifndef INADDRSZ
#define INADDRSZ    4
#endif

#ifndef __P
#define __P(x) x
#endif

/*
 * WARNING: Don't even consider trying to compile this on a system where
 * sizeof(int) < 4.  sizeof(int) > 4 is fine; all the world's not a VAX.
 */

static int  inet_pton4 __P((const char *src, unsigned char *dst));

/* int
 * inet_pton(af, src, dst)
 *  convert from presentation format (which usually means ASCII printable)
 *  to network format (which is usually some kind of binary format).
 * return:
 *  1 if the address was valid for the specified address family
 *  0 if the address wasn't valid (`dst' is untouched in this case)
 *  -1 if some other error occurred (`dst' is untouched in this case, too)
 * author:
 *  Paul Vixie, 1996.
 */
int
inet_pton(int af, const char *src, void *dst)
{
    switch (af) {
    case AF_INET:
        return (inet_pton4(src, dst));
    default:
        errno = EAFNOSUPPORT;
        return (-1);
    }
    /* NOTREACHED */
}

/* int
 * inet_pton4(src, dst)
 *  like inet_aton() but without all the hexadecimal and shorthand.
 * return:
 *  1 if `src' is a valid dotted quad, else 0.
 * notice:
 *  does not touch `dst' unless it's returning 1.
 * author:
 *  Paul Vixie, 1996.
 */
static int
inet_pton4(const char *src, unsigned char *dst)
{
    static const char digits[] = "0123456789";
    int saw_digit, octets, ch;
    unsigned char tmp[INADDRSZ], *tp;

    saw_digit = 0;
    octets = 0;
    *(tp = tmp) = 0;
    while ((ch = *src++) != '\0') {
    const char *pch;

    if ((pch = strchr(digits, ch)) != NULL) {
        unsigned int new = *tp * 10 + (unsigned int)(pch - digits);

        if (new > 255)
        return (0);
        *tp = new;
        if (! saw_digit) {
        if (++octets > 4)
            return (0);
        saw_digit = 1;
        }
    } else if (ch == '.' && saw_digit) {
        if (octets == 4)
        return (0);
        *++tp = 0;
        saw_digit = 0;
    } else
        return (0);
    }
    if (octets < 4)
    return (0);

    memcpy(dst, tmp, INADDRSZ);
    return (1);
}
