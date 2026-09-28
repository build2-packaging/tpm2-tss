/* tctildr.c uses a bare __attribute__((weak)) (unlike this project's other
 * sources, which guard GNU attributes behind util/aux_util.h's
 * COMPILER_ATTR()), which MSVC's compiler does not understand. Force-included
 * on MSVC only (see buildfile) to neutralize it without touching upstream
 * source.
 */
#ifndef __attribute__
#define __attribute__(x)
#endif

/* Dropping "weak" above is only safe as long as nothing else defines these
 * symbols for it to yield to -- true when this comment was written, no
 * longer true since tctildr-nodl.c started statically requiring
 * libtss2-tcti-tbs on Windows: tcti-tbs.c unconditionally defines its own,
 * non-weak Tss2_Tcti_Info(), so linking both into the same binary (as
 * tctildr's own test does) now hits LNK2005 "already defined" on MSVC.
 * On GCC/Clang, tbs's strong definition already silently wins over
 * tctildr.c's weak one (standard weak/strong symbol resolution), and
 * neither tctildr-nodl.c nor any test here ever actually calls
 * Tss2_Tcti_Info() on tctildr's own definition -- it exists only so a
 * consumer that links *only* libtss2-tctildr (no other TCTI) still gets
 * something back. Renaming it here, rather than also stripping it
 * outright, matches that same "tbs wins when both are linked" outcome on
 * MSVC too, without touching upstream source.
 */
#define Tss2_Tcti_Info tss2_tctildr_unused_info
