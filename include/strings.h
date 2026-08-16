#ifndef	_STRINGS_H
#define	_STRINGS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define __NEED_size_t
#define __NEED_locale_t
#include <bits/alltypes.h>

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE) || defined(_POSIX_SOURCE) \
 || (defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE+0 < 200809L) \
 || (defined(_XOPEN_SOURCE) && _XOPEN_SOURCE+0 < 700)
__MUSL_PURE __MUSL_LEAF int bcmp (const void *, const void *, size_t);
__MUSL_LEAF __MUSL_NOALIAS void bcopy (const void *, void *, size_t);
__MUSL_LEAF __MUSL_NOALIAS void bzero (void *, size_t);
__MUSL_PURE __MUSL_LEAF char *index (const char *, int);
__MUSL_PURE __MUSL_LEAF char *rindex (const char *, int);
#endif

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE)  || defined(_BSD_SOURCE)
__MUSL_CONST __MUSL_LEAF int ffs (int);
__MUSL_CONST __MUSL_LEAF int ffsl (long);
__MUSL_CONST __MUSL_LEAF int ffsll (long long);
#endif

__MUSL_PURE __MUSL_LEAF int strcasecmp (const char *, const char *);
__MUSL_PURE __MUSL_LEAF int strncasecmp (const char *, const char *, size_t);

__MUSL_PURE __MUSL_LEAF int strcasecmp_l (const char *, const char *, locale_t);
__MUSL_PURE __MUSL_LEAF int strncasecmp_l (const char *, const char *, size_t, locale_t);

#ifdef __cplusplus
}
#endif

#endif
