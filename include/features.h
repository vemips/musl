#ifndef _FEATURES_H
#define _FEATURES_H

/* vemips */

#define _MUSL_VEMIPS 1
#define __MUSL_VER_MAJOR__ 1
#define __MUSL_VER_MINOR__ 2
#define __MUSL_VER_PATCH__ 5

#if defined(__GNUC__)
#define __MUSL_MALLOC __attribute__((__malloc__))
#if defined(__clang__)
#define __MUSL_MALLOCA(...) __attribute__((__malloc__))
#else
#define __MUSL_MALLOCA(...) __attribute__((__malloc__((__VA_ARGS__))))
#endif
#define __MUSL_ALLOCSIZE(index, ...) __attribute__((__alloc_size__(index, ##__VA_ARGS__)))
#define __MUSL_ALLOCALIGN(align, ...) __attribute__((__alloc_align__(align, ##__VA_ARGS__)))
#define __MUSL_NONNULL(index, ...) __attribute__((__nonnull__(index, ##__VA_ARGS__)))
#define __MUSL_NONNULL_RETURN __attribute__((__returns_nonnull__))
#define __MUSL_STRING_ARG(index) __attribute__((__null_terminated_string_arg__(index)))
#define __MUSL_WARN_DISCARD __attribute__((__warn_unused_result__))
#define __MUSL_PURE __attribute__((__pure__))
#define __MUSL_CONST __attribute__((__const__))
#define __MUSL_LEAF __attribute__((__leaf__))
#if defined(__clang__) && __has_declspec_attribute(__noalias__)
#define __MUSL_NOALIAS __declspec(__noalias__)
#else
#define __MUSL_NOALIAS
#endif
#else
#define __MUSL_MALLOC
#define __MUSL_MALLOCA(...)
#define __MUSL_ALLOCSIZE(index, ...)
#define __MUSL_ALLOCALIGN(align, ...)
#define __MUSL_NONNULL(index, ...)
#define __MUSL_NONNULL_RETURN
#define __MUSL_STRING_ARG(index)
#define __MUSL_WARN_DISCARD
#define __MUSL_PURE
#define __MUSL_CONST
#define __MUSL_LEAF
#define __MUSL_NOALIAS
#endif

/*
#ifndef _XOPEN_SOURCE
#	define _XOPEN_SOURCE 700
#endif
#ifndef _POSIX_SOURCE
#	define _POSIX_SOURCE 1
#endif
#ifndef _GNU_SOURCE
#	define _GNU_SOURCE 1
#endif
#ifndef _POSIX_C_SOURCE
#	define _POSIX_C_SOURCE 1
#endif

#ifndef __GNUC_PREREQ
#	define __GNUC_PREREQ(x, y) 1
#endif
#ifndef __GLIBC_PREREQ
#	define __GLIBC_PREREQ(x, y) 1
#endif
*/

/* vemips */

#if defined(_ALL_SOURCE) && !defined(_GNU_SOURCE)
#define _GNU_SOURCE 1
#endif

#if defined(_DEFAULT_SOURCE) && !defined(_BSD_SOURCE)
#define _BSD_SOURCE 1
#endif

#if !defined(_POSIX_SOURCE) && !defined(_POSIX_C_SOURCE) \
 && !defined(_XOPEN_SOURCE) && !defined(_GNU_SOURCE) \
 && !defined(_BSD_SOURCE) && !defined(__STRICT_ANSI__)
#define _BSD_SOURCE 1
#define _XOPEN_SOURCE 700
#endif

#if __STDC_VERSION__ >= 199901L
#define __restrict restrict
#elif !defined(__GNUC__)
#define __restrict
#endif

#if __STDC_VERSION__ >= 199901L || defined(__cplusplus)
#define __inline inline
#elif !defined(__GNUC__)
#define __inline
#endif

#if __STDC_VERSION__ >= 201112L
#elif defined(__GNUC__)
#define _Noreturn __attribute__((__noreturn__))
#elif defined(__cplusplus) && __has_cpp_attribute(noreturn)
#define _Noreturn [[noreturn]]
#else
#define _Noreturn
#endif

#define __REDIR(x,y) __typeof__(x) x __asm__(#y)

#if defined(_MUSL_VEMIPS)
#include "debug.h"
#endif

#endif
