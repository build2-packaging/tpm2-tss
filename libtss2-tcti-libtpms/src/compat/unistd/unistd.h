/* Only added to the include path when the target compiler has no unistd.h
 * of its own (see libtss2-tcti-libtpms/src/buildfile). Provides the handful
 * of declarations tcti-libtpms.c uses: close()/lseek() (aliased to the
 * MSVC CRT's underscore-prefixed equivalents), off_t and ssize_t, and a
 * truncate() stub. truncate() is only ever called on the state-file path,
 * which is rejected before it can run on this platform (see
 * tcti-libtpms.c.patch), so it does not need a real implementation.
 */
#ifndef LIBTSS2_TCTI_LIBTPMS_COMPAT_UNISTD_H
#define LIBTSS2_TCTI_LIBTPMS_COMPAT_UNISTD_H

#include <basetsd.h>   // for SSIZE_T
#include <io.h>
#include <sys/types.h> // for off_t

#define close _close
#define lseek _lseek

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
typedef SSIZE_T ssize_t;
#endif

static __inline int truncate(const char *path, off_t length)
{
    (void)path;
    (void)length;
    return -1;
}

#endif
