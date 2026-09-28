# libtss2-esys - TPM2 software stack enhanced system API C library

This is a `build2` package for the
[`tpm2-tss`](https://github.com/tpm2-software/tpm2-tss) C library. It
provides the Enhanced System API (ESAPI) of the TCG TSS 2.0, a one-to-one mapping of the TPM 2.0 commands with session handling, tracking of TPM object metadata, and asynchronous calls. Cryptographic operations use OpenSSL.

Upstream's `esys_iutil.c` is patched to replace two C99 variable-length
arrays used on the session parameter-encryption path with heap
allocations, since MSVC does not support VLAs. The replacement is
behavior-preserving (same sizes, same error handling), but this
package's own test only exercises a plain, unencrypted session setup;
it does not exercise the encrypted-session round trip this code
actually implements.


## Usage

To start using `libtss2-esys` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libtss2-esys ^4.2.0
```

Then import the library in your `buildfile`:

```
import libs = libtss2-esys%lib{tss2-esys}
```


## Importable targets

This package provides the following importable targets:

```
lib{tss2-esys}
```

The library is declared in `<tss2/tss2_esys.h>`. It loads a TCTI module through
`libtss2-tctildr` when no TCTI context is passed to `Esys_Initialize()`.


## Configuration variables

This package provides no configuration variables.