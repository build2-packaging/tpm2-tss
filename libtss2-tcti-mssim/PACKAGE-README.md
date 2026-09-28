# libtss2-tcti-mssim - TPM2 software stack Microsoft simulator TCTI C library

This is a `build2` package for the
[`tpm2-tss`](https://github.com/tpm2-software/tpm2-tss) C library. It
provides the TPM command transmission interface (TCTI) module that talks to the Microsoft TPM 2.0 reference simulator over sockets.


## Usage

To start using `libtss2-tcti-mssim` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libtss2-tcti-mssim ^4.2.0
```

Then import the library in your `buildfile`:

```
import libs = libtss2-tcti-mssim%lib{tss2-tcti-mssim}
```


## Importable targets

This package provides the following importable targets:

```
lib{tss2-tcti-mssim}
```

The library is declared in `<tss2/tss2_tcti_mssim.h>`. The TCTI loader
(`libtss2-tctildr`) finds this module by its shared library name at run time.


## Configuration variables

This package provides no configuration variables.