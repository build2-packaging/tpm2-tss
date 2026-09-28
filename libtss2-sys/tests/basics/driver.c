#include <stddef.h>

#include <tss2/tss2_common.h>
#include <tss2/tss2_sys.h>
#include <tss2/tss2_tcti.h>
#include <tss2/tss2_tpm2_types.h>

#undef NDEBUG
#include <assert.h>

int main (void)
{
  /* The default context is large enough for a maximum size command.
   */
  size_t d = Tss2_Sys_GetContextSize (0);
  assert (d > TPM2_MAX_COMMAND_SIZE);

  /* A smaller maximum command size gives a smaller context.
   */
  size_t s = Tss2_Sys_GetContextSize (1);
  assert (s > 0 && s < d);

  /* Initialization rejects a missing context.
   */
  assert (Tss2_Sys_Initialize (NULL, d, NULL, NULL) ==
          TSS2_SYS_RC_BAD_REFERENCE);

  return 0;
}
