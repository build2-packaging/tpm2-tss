# libtss2-sys - TPM2 software stack system API C library

This is a `build2` package for the
[`tpm2-tss`](https://github.com/tpm2-software/tpm2-tss) C library. It
provides the System API (SAPI) of the TCG TSS 2.0, a one-to-one mapping of the TPM 2.0 commands that includes asynchronous calls.


## Usage

To start using `libtss2-sys` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libtss2-sys ^4.2.0
```

Then import the library in your `buildfile`:

```
import libs = libtss2-sys%lib{tss2-sys}
```


## Importable targets

This package provides the following importable targets:

```
lib{tss2-sys}
```

The library is declared in `<tss2/tss2_sys.h>`. It talks to a TPM through a
TCTI module, see `libtss2-tcti-device`, `libtss2-tcti-mssim`, and
`libtss2-tcti-swtpm`.


## Configuration variables

This package provides no configuration variables.