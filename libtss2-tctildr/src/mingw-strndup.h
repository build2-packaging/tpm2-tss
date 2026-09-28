/* tctildr.c calls strndup(), which glibc and MSVC's UCRT both provide (the
 * latter via this package's own upstream _MSC_VER fallback below in
 * tctildr.c), but which some mingw-w64 toolchain builds don't declare even
 * under _GNU_SOURCE (their <string.h> gates it on an older/narrower set of
 * feature-test macros than others do). Force-included on mingw32 only (see
 * buildfile) to provide a portable fallback without touching upstream
 * source: renaming the call site to our own implementation via macro
 * substitution sidesteps the question of whether the underlying toolchain
 * happens to declare (or even provide) its own strndup at all.
 */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#ifndef strndup
#define strndup tss2_tctildr_strndup

static char *
tss2_tctildr_strndup (const char *s, size_t n)
{
  size_t l = 0;
  char *r;

  while (l < n && s[l] != '\0')
    l++;

  r = (char *) malloc (l + 1);
  if (r == NULL)
    return NULL;

  memcpy (r, s, l);
  r[l] = '\0';
  return r;
}
#endif
