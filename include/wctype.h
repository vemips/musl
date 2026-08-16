#ifndef _WCTYPE_H
#define _WCTYPE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define __NEED_wint_t
#define __NEED_wctype_t

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define __NEED_locale_t
#endif

#include <bits/alltypes.h>

typedef const int * wctrans_t;

#undef WEOF
#define WEOF 0xffffffffU

#undef iswdigit

__MUSL_CONST __MUSL_LEAF int       iswalnum(wint_t);
__MUSL_CONST __MUSL_LEAF int       iswalpha(wint_t);
__MUSL_CONST __MUSL_LEAF int       iswblank(wint_t);
__MUSL_CONST __MUSL_LEAF int       iswcntrl(wint_t);
__MUSL_CONST __MUSL_LEAF int       iswdigit(wint_t);
__MUSL_CONST __MUSL_LEAF int       iswgraph(wint_t);
__MUSL_CONST __MUSL_LEAF int       iswlower(wint_t);
__MUSL_CONST __MUSL_LEAF int       iswprint(wint_t);
__MUSL_CONST __MUSL_LEAF int       iswpunct(wint_t);
__MUSL_CONST __MUSL_LEAF int       iswspace(wint_t);
__MUSL_CONST __MUSL_LEAF int       iswupper(wint_t);
__MUSL_CONST __MUSL_LEAF int       iswxdigit(wint_t);
__MUSL_CONST __MUSL_LEAF int       iswctype(wint_t, wctype_t);
__MUSL_CONST __MUSL_LEAF wint_t    towctrans(wint_t, wctrans_t);
__MUSL_CONST __MUSL_LEAF wint_t    towlower(wint_t);
__MUSL_CONST __MUSL_LEAF wint_t    towupper(wint_t);
__MUSL_PURE __MUSL_LEAF wctrans_t wctrans(const char *);
__MUSL_PURE __MUSL_LEAF wctype_t  wctype(const char *);

#ifndef __cplusplus
#undef iswdigit
#define iswdigit(a) (0 ? iswdigit(a) : ((unsigned)(a)-'0') < 10)
#endif

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)

__MUSL_PURE __MUSL_LEAF int iswalnum_l(wint_t, locale_t);
__MUSL_PURE __MUSL_LEAF int iswalpha_l(wint_t, locale_t);
__MUSL_PURE __MUSL_LEAF int iswblank_l(wint_t, locale_t);
__MUSL_PURE __MUSL_LEAF int iswcntrl_l(wint_t, locale_t);
__MUSL_PURE __MUSL_LEAF int iswdigit_l(wint_t, locale_t);
__MUSL_PURE __MUSL_LEAF int iswgraph_l(wint_t, locale_t);
__MUSL_PURE __MUSL_LEAF int iswlower_l(wint_t, locale_t);
__MUSL_PURE __MUSL_LEAF int iswprint_l(wint_t, locale_t);
__MUSL_PURE __MUSL_LEAF int iswpunct_l(wint_t, locale_t);
__MUSL_PURE __MUSL_LEAF int iswspace_l(wint_t, locale_t);
__MUSL_PURE __MUSL_LEAF int iswupper_l(wint_t, locale_t);
__MUSL_PURE __MUSL_LEAF int iswxdigit_l(wint_t, locale_t);
__MUSL_PURE __MUSL_LEAF int iswctype_l(wint_t, wctype_t, locale_t);
__MUSL_PURE __MUSL_LEAF wint_t towlower_l(wint_t, locale_t);
__MUSL_PURE __MUSL_LEAF wint_t towupper_l(wint_t, locale_t);
__MUSL_PURE __MUSL_LEAF wint_t towctrans_l(wint_t, wctrans_t, locale_t);
__MUSL_PURE __MUSL_LEAF wctrans_t wctrans_l(const char *, locale_t);
__MUSL_PURE __MUSL_LEAF wctype_t  wctype_l(const char *, locale_t);

#endif

#ifdef __cplusplus
}
#endif

#endif
