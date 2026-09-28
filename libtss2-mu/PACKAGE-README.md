# libtss2-mu - TPM2 software stack marshaling and unmarshaling C library

This is a `build2` package for the
[`tpm2-tss`](https://github.com/tpm2-software/tpm2-tss) C library. It
provides the Marshaling/Unmarshaling (MU) API of the TCG TSS 2.0, which marshals and unmarshals all data types of the TPM 2.0 library specification.


## Usage

To start using `libtss2-mu` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libtss2-mu ^4.2.0
```

Then import the library in your `buildfile`:

```
import libs = libtss2-mu%lib{tss2-mu}
```


## Importable targets

This package provides the following importable targets:

```
lib{tss2-mu}
```

The library is declared in `<tss2/tss2_mu.h>`.


## Configuration variables

This package provides no configuration variables.