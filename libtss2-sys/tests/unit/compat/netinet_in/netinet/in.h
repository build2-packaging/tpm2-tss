/* Only added to the include path when the target compiler has no
 * netinet/in.h of its own (see libtss2-sys/tests/unit/buildfile).
 * CopyCommandHeader.c includes it purely for the byte order conversions
 * (htonl(), htons()), which winsock2.h provides directly on such targets.
 */
#ifndef LIBTSS2_SYS_TESTS_COMPAT_NETINET_IN_H
#define LIBTSS2_SYS_TESTS_COMPAT_NETINET_IN_H

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <winsock2.h>

#endif
