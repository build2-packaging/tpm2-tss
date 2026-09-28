# libtss2-tctildr - TPM2 software stack TCTI loader C library

This is a `build2` package for the
[`tpm2-tss`](https://github.com/tpm2-software/tpm2-tss) C library. It
provides the TPM command transmission interface (TCTI) loader, which selects and loads a TCTI module by name at run time.


## Usage

To start using `libtss2-tctildr` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libtss2-tctildr ^4.2.0
```

Then import the library in your `buildfile`:

```
import libs = libtss2-tctildr%lib{tss2-tctildr}
```


## Importable targets

This package provides the following importable targets:

```
lib{tss2-tctildr}
```

The library is declared in `<tss2/tss2_tctildr.h>`. It loads the TCTI modules
by their shared library names (for example `libtss2-tcti-device.so.0`), so the
corresponding `libtss2-tcti-*` packages have to be installed where the dynamic
loader can find them.


## Configuration variables

This package provides no configuration variables.