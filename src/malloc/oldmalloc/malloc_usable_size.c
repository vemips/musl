#include <malloc.h>
#include "malloc_impl.h"

hidden void *(*const __realloc_dep)(void *, size_t) __MUSL_WARN_DISCARD
#if defined(__GNUC__)
	__attribute__((__alloc_size__(2)))
#endif
= realloc;

size_t malloc_usable_size(void *p)
{
	return p ? CHUNK_SIZE(MEM_TO_CHUNK(p)) - OVERHEAD : 0;
}
