# libtss2-tcti-libtpms - TPM2 software stack libtpms TCTI C library

This is a `build2` package for the
[`tpm2-tss`](https://github.com/tpm2-software/tpm2-tss) C library. It
provides the TPM command transmission interface (TCTI) module that talks
directly to a linked `libtpms` software TPM, without going through a
socket protocol.

Upstream's `tcti-libtpms.c` is patched to use a portable thread-local-storage
macro, since MSVC does not support the GNU/Clang `__thread` extension used
by the original source. It is also patched for FreeBSD and macOS, neither
of which has Linux's `mremap()` (and macOS also lacks `posix_fallocate()`):
on those two platforms, state-file persistence (a non-empty `conf` string)
is rejected at initialization; using this TCTI without a state file is
unaffected.


## Usage

To start using `libtss2-tcti-libtpms` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libtss2-tcti-libtpms ^4.2.0
```

Then import the library in your `buildfile`:

```
import libs = libtss2-tcti-libtpms%lib{tss2-tcti-libtpms}
```


## Importable targets

This package provides the following importable targets:

```
lib{tss2-tcti-libtpms}
```

The library is declared in `<tss2/tss2_tcti_libtpms.h>`. The TCTI loader
(`libtss2-tctildr`) finds this module by its shared library name at run time.


## Configuration variables

This package provides no configuration variables.
