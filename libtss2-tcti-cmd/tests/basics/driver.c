#include <stddef.h>
#include <string.h>

#include <tss2/tss2_common.h>
#include <tss2/tss2_tcti.h>
#include <tss2/tss2_tcti_cmd.h>

#undef NDEBUG
#include <assert.h>

/* Exported for symbol lookup, there is no header declaration.
 */
const TSS2_TCTI_INFO* Tss2_Tcti_Info (void);

int main (void)
{
  /* Querying the context size needs no context or TPM, but this TCTI
   * requires a non-NULL configuration string even for the size query.
   */
  size_t n = 0;
  assert (Tss2_Tcti_Cmd_Init (NULL, &n, "") == TSS2_RC_SUCCESS);
  assert (n > 0);

  /* Exercise the exported info's init function pointer directly rather
   * than comparing it for equality with Tss2_Tcti_Cmd_Init: a
   * DLL-imported function's address as seen by the consumer is not
   * guaranteed to equal its address inside the DLL on Windows (MSVC's
   * own C4232 warns about exactly this), even though both refer to the
   * same function, so pointer identity across a shared-library
   * boundary is not portable. Calling through it and checking it
   * behaves like the same initializer works uniformly on every
   * platform and on both the static and shared variant.
   */
  const TSS2_TCTI_INFO* i = Tss2_Tcti_Info ();
  assert (i != NULL);
  assert (i->name != NULL && strlen (i->name) > 0);

  size_t n2 = 0;
  assert (i->init (NULL, &n2, "") == TSS2_RC_SUCCESS);
  assert (n2 == n);

  return 0;
}
