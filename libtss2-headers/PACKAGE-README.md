# libtss2-headers - TPM2 software stack base headers

This is a `build2` package for the
[`tpm2-tss`](https://github.com/tpm2-software/tpm2-tss) C library. It
provides the base headers shared by all libraries of the TCG TPM2 Software Stack (TSS): the common definitions, the TPM 2.0 data types, and the TPM command transmission interface (TCTI) declarations.


## Usage

To start using `libtss2-headers` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libtss2-headers ^4.2.0
```

Then import the library in your `buildfile`:

```
import libs = libtss2-headers%lib{tss2-headers}
```


## Importable targets

This package provides the following importable targets:

```
lib{tss2-headers}
```

The library is header-only. Its headers are included as
`<tss2/tss2_common.h>`, `<tss2/tss2_tcti.h>`, and
`<tss2/tss2_tpm2_types.h>`. The other packages of this project depend on it
for these headers.


## Configuration variables

This package provides no configuration variables.