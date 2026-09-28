# tpm2-tss - TPM2 software stack

This is a `build2` package repository for [`tpm2-tss`](https://github.com/tpm2-software/tpm2-tss),
the implementation of the TCG TPM2 Software Stack (TSS).

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`tpm2-tss` in your `build2`-based project, then instead see the accompanying
`PACKAGE-README.md` file of the package you are interested in:

* [`libtss2-headers`](libtss2-headers/PACKAGE-README.md)
* [`libtss2-mu`](libtss2-mu/PACKAGE-README.md)
* [`libtss2-rc`](libtss2-rc/PACKAGE-README.md)
* [`libtss2-sys`](libtss2-sys/PACKAGE-README.md)
* [`libtss2-tcti-device`](libtss2-tcti-device/PACKAGE-README.md)

The development setup for `tpm2-tss` uses the standard `bdep`-based workflow.
For example:

```
git clone --recurse-submodules .../tpm2-tss.git
cd tpm2-tss

bdep init -C @gcc cc config.c=gcc
bdep update
bdep test
```
