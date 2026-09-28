#include <stddef.h>

#include <tss2/tss2_common.h>
#include <tss2/tss2_tcti.h>
#include <tss2/tss2_tctildr.h>

#undef NDEBUG
#include <assert.h>

int main (void)
{
  /* Loading a TCTI that does not exist fails cleanly and leaves the
   * context unset.
   */
  {
    TSS2_TCTI_CONTEXT* c = NULL;
    assert (Tss2_TctiLdr_Initialize ("tss2-no-such-tcti", &c) !=
            TSS2_RC_SUCCESS);
    assert (c == NULL);
  }

  /* Same for the information query.
   */
  {
    TSS2_TCTI_INFO* i = NULL;
    assert (Tss2_TctiLdr_GetInfo ("tss2-no-such-tcti", &i) !=
            TSS2_RC_SUCCESS);
    assert (i == NULL);
  }

  /* A missing output context is rejected.
   */
  assert (Tss2_TctiLdr_Initialize (NULL, NULL) != TSS2_RC_SUCCESS);

  return 0;
}
