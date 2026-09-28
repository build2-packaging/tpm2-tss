#include <string.h>

#include <tss2/tss2_common.h>
#include <tss2/tss2_rc.h>
#include <tss2/tss2_tpm2_types.h>

#undef NDEBUG
#include <assert.h>

int main (void)
{
  /* A TPM response code is decoded into a non-empty description.
   */
  {
    const char* s = Tss2_RC_Decode (TPM2_RC_INITIALIZE);
    assert (s != NULL && strlen (s) > 0);
  }

  /* Decoding is deterministic.
   */
  {
    const char* a = Tss2_RC_Decode (TSS2_BASE_RC_BAD_REFERENCE);
    const char* b = Tss2_RC_Decode (TSS2_BASE_RC_BAD_REFERENCE);
    assert (a != NULL && b != NULL && strcmp (a, b) == 0);
  }

  return 0;
}