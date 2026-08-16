#define _BSD_SOURCE
#include <unistd.h>
#include <errno.h>
#include "syscall.h"

/* vemips */
#include "../vemips_common.h"
/* ~vemips */

int brk(void *end)
{
#if MUSL_WITH_VEMIPS
#	if MUSL_WITH_VEMIPS_SYSCALL_ABI
	struct __syscall_result_vemips result = __syscall_vemips1(SYS_brk, (long)end);
	if UNLIKELY(result.value1 < 0) {
		errno = -result.value1;
		return -1;
	}

	return 0;
#	else
	long result = (long)__syscall(SYS_brk, end);
	if UNLIKELY(result < 0)
	{
		errno = ENOMEM;
		return -1;
	}

	return 0;
#endif
#else
	return __syscall_ret(-ENOMEM);
#endif
}
