# libtss2-tcti-tbs - TPM2 software stack Windows TBS TCTI C library

This is a `build2` package for the
[`tpm2-tss`](https://github.com/tpm2-software/tpm2-tss) C library. It
provides the TPM command transmission interface (TCTI) module that talks to
the TPM through Windows' TBS (TPM Base Services) API.


## Usage

To start using `libtss2-tcti-tbs` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libtss2-tcti-tbs ^4.2.0
```

Then import the library in your `buildfile`:

```
import libs = libtss2-tcti-tbs%lib{tss2-tcti-tbs}
```


## Importable targets

This package provides the following importable targets:

```
lib{tss2-tcti-tbs}
```

The library is declared in `<tss2/tss2_tcti_tbs.h>`. The TCTI loader
(`libtss2-tctildr`) finds this module by its shared library name at run time.


## Configuration variables

This package provides no configuration variables.