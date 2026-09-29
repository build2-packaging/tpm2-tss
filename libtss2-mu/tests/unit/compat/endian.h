/* SPDX-License-Identifier: BSD-2-Clause */
/*
 * No Windows toolchain here (MSVC or MinGW) ships glibc's <endian.h>, and
 * there is no big-endian Windows target, so le32toh()/le64toh() are always
 * a no-op on this platform.
 */
#ifndef COMPAT_ENDIAN_H
#define COMPAT_ENDIAN_H

#define le32toh(x) (x)
#define le64toh(x) (x)

#endif /* COMPAT_ENDIAN_H */
