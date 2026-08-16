#ifndef	_STRING_H
#define	_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#if __cplusplus >= 201103L
#define NULL nullptr
#elif defined(__cplusplus)
#define NULL 0L
#else
#define NULL ((void*)0)
#endif

#define __NEED_size_t
#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)
#define __NEED_locale_t
#endif

#include <bits/alltypes.h>

__MUSL_LEAF __MUSL_NOALIAS void *memcpy (void *__restrict, const void *__restrict, size_t);
__MUSL_LEAF __MUSL_NOALIAS void *memmove (void *, const void *, size_t);
__MUSL_LEAF __MUSL_NOALIAS void *memset (void *, int, size_t);
__MUSL_PURE __MUSL_LEAF int memcmp (const void *, const void *, size_t);
__MUSL_PURE __MUSL_LEAF void *memchr (const void *, int, size_t);

__MUSL_LEAF __MUSL_NOALIAS char *strcpy (char *__restrict, const char *__restrict);
__MUSL_LEAF __MUSL_NOALIAS char *strncpy (char *__restrict, const char *__restrict, size_t);

__MUSL_LEAF __MUSL_NOALIAS char *strcat (char *__restrict, const char *__restrict);
__MUSL_LEAF __MUSL_NOALIAS char *strncat (char *__restrict, const char *__restrict, size_t);

__MUSL_PURE __MUSL_LEAF int strcmp (const char *, const char *);
__MUSL_PURE __MUSL_LEAF int strncmp (const char *, const char *, size_t);

__MUSL_PURE __MUSL_LEAF int strcoll (const char *, const char *);
__MUSL_LEAF __MUSL_NOALIAS size_t strxfrm (char *__restrict, const char *__restrict, size_t);

__MUSL_PURE __MUSL_LEAF char *strchr (const char *, int);
__MUSL_PURE __MUSL_LEAF char *strrchr (const char *, int);

__MUSL_PURE __MUSL_LEAF size_t strcspn (const char *, const char *);
__MUSL_PURE __MUSL_LEAF size_t strspn (const char *, const char *);
__MUSL_PURE __MUSL_LEAF char *strpbrk (const char *, const char *);
__MUSL_PURE __MUSL_LEAF char *strstr (const char *, const char *);
__MUSL_LEAF __MUSL_NOALIAS char *strtok (char *__restrict, const char *__restrict);

__MUSL_PURE __MUSL_LEAF size_t strlen (const char *);

__MUSL_CONST __MUSL_LEAF char *strerror (int);

#if defined(_BSD_SOURCE) || defined(_GNU_SOURCE)
#include <strings.h>
#endif

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)
__MUSL_LEAF __MUSL_NOALIAS char *strtok_r (char *__restrict, const char *__restrict, char **__restrict);
#if defined(_MUSL_VEMIPS)

#	if defined(_GNU_SOURCE)
__MUSL_LEAF __MUSL_NOALIAS char *strerror_r (int, char *, size_t);
#	else
__MUSL_LEAF __MUSL_NOALIAS int strerror_r (int, char *, size_t);
#	endif

#endif // _MUSL_VEMIPS
__MUSL_LEAF __MUSL_NOALIAS char *stpcpy(char *__restrict, const char *__restrict);
__MUSL_LEAF __MUSL_NOALIAS char *stpncpy(char *__restrict, const char *__restrict, size_t);
__MUSL_PURE __MUSL_LEAF size_t strnlen (const char *, size_t);
__MUSL_MALLOCA(free, 1) __MUSL_LEAF __MUSL_WARN_DISCARD char *strdup (const char *);
__MUSL_MALLOCA(free, 1) __MUSL_LEAF __MUSL_WARN_DISCARD char *strndup (const char *, size_t);
__MUSL_CONST __MUSL_LEAF char *strsignal(int);
__MUSL_PURE __MUSL_LEAF char *strerror_l (int, locale_t);
__MUSL_PURE __MUSL_LEAF int strcoll_l (const char *, const char *, locale_t);
__MUSL_LEAF __MUSL_NOALIAS size_t strxfrm_l (char *__restrict, const char *__restrict, size_t, locale_t);
__MUSL_PURE __MUSL_LEAF void *memmem(const void *, size_t, const void *, size_t);
#endif

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)
__MUSL_LEAF __MUSL_NOALIAS void *memccpy (void *__restrict, const void *__restrict, int, size_t);
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
__MUSL_LEAF __MUSL_NOALIAS char *strsep(char **, const char *);
__MUSL_LEAF __MUSL_NOALIAS size_t strlcat (char *, const char *, size_t);
__MUSL_LEAF __MUSL_NOALIAS size_t strlcpy (char *, const char *, size_t);
__MUSL_LEAF __MUSL_NOALIAS void explicit_bzero (void *, size_t);
#endif

#ifdef _GNU_SOURCE
#define	strdupa(x)	strcpy(alloca(strlen(x)+1),x)
__MUSL_PURE __MUSL_LEAF int strverscmp (const char *, const char *);
__MUSL_PURE __MUSL_LEAF char *strchrnul(const char *, int);
__MUSL_PURE __MUSL_LEAF char *strcasestr(const char *, const char *);
__MUSL_PURE __MUSL_LEAF void *memrchr(const void *, int, size_t);
__MUSL_LEAF __MUSL_NOALIAS void *mempcpy(void *, const void *, size_t);
#ifndef __cplusplus
__MUSL_PURE __MUSL_LEAF char *basename(const char *);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
