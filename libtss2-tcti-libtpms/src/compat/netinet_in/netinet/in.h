/* Only added to the include path when the target compiler has no
 * netinet/in.h of its own (see libtss2-tcti-libtpms/src/buildfile).
 * tcti-libtpms.c includes it purely for the byte order conversions
 * (htonl(), ntohl()), which winsock2.h provides directly on such targets.
 */
#ifndef LIBTSS2_TCTI_LIBTPMS_COMPAT_NETINET_IN_H
#define LIBTSS2_TCTI_LIBTPMS_COMPAT_NETINET_IN_H

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <winsock2.h>

#endif
