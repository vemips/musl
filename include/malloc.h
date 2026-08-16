#ifndef _MALLOC_H
#define _MALLOC_H

#ifdef __cplusplus
extern "C" {
#endif

#define __NEED_size_t

#include <features.h>

#include <bits/alltypes.h>

__MUSL_MALLOCA(free, 1) __MUSL_ALLOCSIZE(1) __MUSL_LEAF __MUSL_WARN_DISCARD void *malloc (size_t);
__MUSL_MALLOCA(free, 1) __MUSL_ALLOCSIZE(1, 2) __MUSL_LEAF __MUSL_WARN_DISCARD void *calloc (size_t, size_t);
__MUSL_ALLOCSIZE(2) __MUSL_LEAF __MUSL_WARN_DISCARD void *realloc (void *, size_t);
__MUSL_LEAF void free (void *);
__MUSL_MALLOCA(free, 1) __MUSL_ALLOCSIZE(1) __MUSL_LEAF __MUSL_WARN_DISCARD void *valloc (size_t);
__MUSL_MALLOCA(free, 1) __MUSL_ALLOCALIGN(1) __MUSL_ALLOCSIZE(2) __MUSL_LEAF __MUSL_WARN_DISCARD void *memalign(size_t, size_t);

__MUSL_PURE __MUSL_LEAF __MUSL_WARN_DISCARD size_t malloc_usable_size(void *);

#ifdef __cplusplus
}
#endif

#endif
