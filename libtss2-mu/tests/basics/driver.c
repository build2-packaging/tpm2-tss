#include <stddef.h>
#include <stdint.h>

#include <tss2/tss2_common.h>
#include <tss2/tss2_mu.h>

#undef NDEBUG
#include <assert.h>

int main (void)
{
  uint8_t b[8] = {0};

  /* Marshal is big-endian.
   */
  {
    size_t o = 0;
    assert (Tss2_MU_UINT32_Marshal (0x01020304, b, sizeof (b), &o) ==
            TSS2_RC_SUCCESS);
    assert (o == 4);
    assert (b[0] == 0x01 && b[1] == 0x02 && b[2] == 0x03 && b[3] == 0x04);
  }

  /* Round trip.
   */
  {
    size_t o = 0;
    UINT32 v = 0;
    assert (Tss2_MU_UINT32_Unmarshal (b, sizeof (b), &o, &v) ==
            TSS2_RC_SUCCESS);
    assert (o == 4 && v == 0x01020304);
  }

  /* Insufficient buffer.
   */
  {
    size_t o = 0;
    assert (Tss2_MU_UINT32_Marshal (1, b, 2, &o) ==
            TSS2_MU_RC_INSUFFICIENT_BUFFER);
  }

  return 0;
}
