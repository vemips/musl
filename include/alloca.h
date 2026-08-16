#ifndef	_ALLOCA_H
#define	_ALLOCA_H

#ifdef __cplusplus
extern "C" {
#endif

#define	__NEED_size_t
#include <bits/alltypes.h>

__MUSL_MALLOC __MUSL_ALLOCSIZE(1) __MUSL_LEAF __MUSL_WARN_DISCARD void *alloca(size_t);

#define alloca __builtin_alloca

#ifdef __cplusplus
}
#endif

#endif
