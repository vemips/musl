#define _BSD_SOURCE
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include "syscall.h"

#if MUSL_WITH_VEMIPS
#include "../vemips_common.h"
#endif

void *sbrk(intptr_t inc)
{
#if MUSL_WITH_VEMIPS
#	if MUSL_WITH_VEMIPS_SYSCALL_ABI
	struct __syscall_result_vemips result = __syscall_vemips1(SYS_sbrk, (long)inc);
	if UNLIKELY(result.value1 < 0) {
		errno = -result.value1;
		return (void*)-1;
	}

	return (void*)result.value0;
#	else
	long result = (long)__syscall(SYS_sbrk, inc);
	if UNLIKELY(result < 0)
	{
		errno = ENOMEM;
		return (void*)-1;
	}

	return (void *)result;
#endif
#else
	if (inc) return (void *)__syscall_ret(-ENOMEM);
	return (void *)__syscall(SYS_brk, 0);
#endif
}
