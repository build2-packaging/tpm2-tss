# libtss2-rc - TPM2 software stack response code decoding C library

This is a `build2` package for the
[`tpm2-tss`](https://github.com/tpm2-software/tpm2-tss) C library. It
provides decoding of TSS and TPM 2.0 response codes into human-readable descriptions.

Upstream's `tss2_rc.c` is patched to use a portable thread-local-storage
macro, since MSVC does not support the GNU/Clang `__thread` extension used
by the original source.


## Usage

To start using `libtss2-rc` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libtss2-rc ^4.2.0
```

Then import the library in your `buildfile`:

```
import libs = libtss2-rc%lib{tss2-rc}
```


## Importable targets

This package provides the following importable targets:

```
lib{tss2-rc}
```

The library is declared in `<tss2/tss2_rc.h>`.


## Configuration variables

This package provides no configuration variables.