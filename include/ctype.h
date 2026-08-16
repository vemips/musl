#ifndef	_CTYPE_H
#define	_CTYPE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

__MUSL_CONST __MUSL_LEAF int   isalnum(int);
__MUSL_CONST __MUSL_LEAF int   isalpha(int);
__MUSL_CONST __MUSL_LEAF int   isblank(int);
__MUSL_CONST __MUSL_LEAF int   iscntrl(int);
__MUSL_CONST __MUSL_LEAF int   isdigit(int);
__MUSL_CONST __MUSL_LEAF int   isgraph(int);
__MUSL_CONST __MUSL_LEAF int   islower(int);
__MUSL_CONST __MUSL_LEAF int   isprint(int);
__MUSL_CONST __MUSL_LEAF int   ispunct(int);
__MUSL_CONST __MUSL_LEAF int   isspace(int);
__MUSL_CONST __MUSL_LEAF int   isupper(int);
__MUSL_CONST __MUSL_LEAF int   isxdigit(int);
__MUSL_CONST __MUSL_LEAF int   tolower(int);
__MUSL_CONST __MUSL_LEAF int   toupper(int);

#ifndef __cplusplus
static __inline int __isspace(int _c)
{
	return _c == ' ' || (unsigned)_c-'\t' < 5;
}

#define isalpha(a) (0 ? isalpha(a) : (((unsigned)(a)|32)-'a') < 26)
#define isdigit(a) (0 ? isdigit(a) : ((unsigned)(a)-'0') < 10)
#define islower(a) (0 ? islower(a) : ((unsigned)(a)-'a') < 26)
#define isupper(a) (0 ? isupper(a) : ((unsigned)(a)-'A') < 26)
#define isprint(a) (0 ? isprint(a) : ((unsigned)(a)-0x20) < 0x5f)
#define isgraph(a) (0 ? isgraph(a) : ((unsigned)(a)-0x21) < 0x5e)
#define isspace(a) __isspace(a)
#endif


#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)

#define __NEED_locale_t
#include <bits/alltypes.h>

__MUSL_PURE __MUSL_LEAF int   isalnum_l(int, locale_t);
__MUSL_PURE __MUSL_LEAF int   isalpha_l(int, locale_t);
__MUSL_PURE __MUSL_LEAF int   isblank_l(int, locale_t);
__MUSL_PURE __MUSL_LEAF int   iscntrl_l(int, locale_t);
__MUSL_PURE __MUSL_LEAF int   isdigit_l(int, locale_t);
__MUSL_PURE __MUSL_LEAF int   isgraph_l(int, locale_t);
__MUSL_PURE __MUSL_LEAF int   islower_l(int, locale_t);
__MUSL_PURE __MUSL_LEAF int   isprint_l(int, locale_t);
__MUSL_PURE __MUSL_LEAF int   ispunct_l(int, locale_t);
__MUSL_PURE __MUSL_LEAF int   isspace_l(int, locale_t);
__MUSL_PURE __MUSL_LEAF int   isupper_l(int, locale_t);
__MUSL_PURE __MUSL_LEAF int   isxdigit_l(int, locale_t);
__MUSL_PURE __MUSL_LEAF int   tolower_l(int, locale_t);
__MUSL_PURE __MUSL_LEAF int   toupper_l(int, locale_t);

__MUSL_CONST __MUSL_LEAF int   isascii(int);
__MUSL_CONST __MUSL_LEAF int   toascii(int);
#define _tolower(a) ((a)|0x20)
#define _toupper(a) ((a)&0x5f)
#ifndef __cplusplus
#define isascii(a) (0 ? isascii(a) : (unsigned)(a) < 128)
#endif

#endif

#ifdef __cplusplus
}
#endif

#endif
