#include <stddef.h>
#include <string.h>

#include <tss2/tss2_common.h>
#include <tss2/tss2_tcti.h>
#include <tss2/tss2_tcti_mssim.h>

#undef NDEBUG
#include <assert.h>

/* Exported for symbol lookup, there is no header declaration.
 */
const TSS2_TCTI_INFO* Tss2_Tcti_Info (void);

int main (void)
{
  /* Querying the context size needs neither a context nor a TPM.
   */
  size_t n = 0;
  assert (Tss2_Tcti_Mssim_Init (NULL, &n, NULL) == TSS2_RC_SUCCESS);
  assert (n > 0);

  /* Exercise the exported info's init function pointer directly rather
   * than comparing it for equality with Tss2_Tcti_Mssim_Init: a
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
  assert (i->init (NULL, &n2, NULL) == TSS2_RC_SUCCESS);
  assert (n2 == n);

  return 0;
}
