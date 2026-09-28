#include <tss2/tss2_common.h>
#include <tss2/tss2_tcti.h>
#include <tss2/tss2_tpm2_types.h>

#undef NDEBUG
#include <assert.h>

int main (void)
{
  /* The library is header-only so there is no function to call. Instead,
   * check that the headers are usable together and that their definitions
   * are visible.
   */
  TSS2_RC rc = TSS2_RC_SUCCESS;
  assert (rc == 0);

  assert (TPM2_MAX_COMMAND_SIZE > 0);
  assert (sizeof (TPMS_EMPTY) > 0);

  TSS2_TCTI_CONTEXT* ctx = NULL;
  assert (Tss2_Tcti_Transmit (ctx, 0, NULL) == TSS2_TCTI_RC_BAD_REFERENCE);

  return 0;
}
