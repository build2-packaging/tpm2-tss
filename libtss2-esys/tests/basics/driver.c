#include <stddef.h>
#include <stdint.h>

#include <tss2/tss2_common.h>
#include <tss2/tss2_esys.h>
#include <tss2/tss2_sys.h>
#include <tss2/tss2_tcti.h>

#undef NDEBUG
#include <assert.h>

/* A TCTI that is never asked to talk to a TPM, just enough to build an ESYS
 * context on top of.
 */
static TSS2_RC
transmit (TSS2_TCTI_CONTEXT* c, size_t n, const uint8_t* b)
{
  (void) c; (void) n; (void) b;
  return TSS2_TCTI_RC_NOT_IMPLEMENTED;
}

static TSS2_RC
receive (TSS2_TCTI_CONTEXT* c, size_t* n, uint8_t* r, int32_t t)
{
  (void) c; (void) n; (void) r; (void) t;
  return TSS2_TCTI_RC_NOT_IMPLEMENTED;
}

static void
finalize (TSS2_TCTI_CONTEXT* c)
{
  (void) c;
}

static TSS2_RC
cancel (TSS2_TCTI_CONTEXT* c)
{
  (void) c;
  return TSS2_TCTI_RC_NOT_IMPLEMENTED;
}

static TSS2_RC
get_poll_handles (TSS2_TCTI_CONTEXT* c, TSS2_TCTI_POLL_HANDLE* h, size_t* n)
{
  (void) c; (void) h; (void) n;
  return TSS2_TCTI_RC_NOT_IMPLEMENTED;
}

static TSS2_RC
set_locality (TSS2_TCTI_CONTEXT* c, uint8_t l)
{
  (void) c; (void) l;
  return TSS2_TCTI_RC_NOT_IMPLEMENTED;
}

int main (void)
{
  TSS2_TCTI_CONTEXT_COMMON_V1 tcti = {
    .magic = 0x1,
    .version = 1,
    .transmit = transmit,
    .receive = receive,
    .finalize = finalize,
    .cancel = cancel,
    .getPollHandles = get_poll_handles,
    .setLocality = set_locality};

  ESYS_CONTEXT* e = NULL;
  assert (Esys_Initialize (&e, (TSS2_TCTI_CONTEXT*) &tcti, NULL) ==
          TSS2_RC_SUCCESS);
  assert (e != NULL);

  /* The ESYS context sits on top of a SYS context and the TCTI we gave it.
   */
  TSS2_SYS_CONTEXT* s = NULL;
  assert (Esys_GetSysContext (e, &s) == TSS2_RC_SUCCESS);
  assert (s != NULL);

  TSS2_TCTI_CONTEXT* t = NULL;
  assert (Esys_GetTcti (e, &t) == TSS2_RC_SUCCESS);
  assert (t == (TSS2_TCTI_CONTEXT*) &tcti);

  Esys_Finalize (&e);
  assert (e == NULL);

  return 0;
}
