/* Only added to the include path when the target compiler has no
 * sys/mman.h of its own (see libtss2-tcti-libtpms/src/buildfile).
 * tcti-libtpms.h includes it purely for size_t, which stddef.h provides
 * directly on such targets. (The mmap()-family functions and macros
 * themselves are handled separately, in tcti-libtpms.c.patch.)
 */
#ifndef LIBTSS2_TCTI_LIBTPMS_COMPAT_SYS_MMAN_H
#define LIBTSS2_TCTI_LIBTPMS_COMPAT_SYS_MMAN_H

#include <stddef.h>

#endif
