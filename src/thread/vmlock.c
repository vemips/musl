#include "pthread_impl.h"
#include "fork_impl.h"

#ifndef _MUSL_VEMIPS
static volatile int vmlock[2];
volatile int *const __vmlock_lockptr = vmlock;
#endif

void __vm_wait()
{
#ifndef _MUSL_VEMIPS
	int tmp;
	while ((tmp=vmlock[0]))
		__wait(vmlock, vmlock+1, tmp, 1);
#endif
}

void __vm_lock()
{
#ifndef _MUSL_VEMIPS
	a_inc(vmlock);
#endif
}

void __vm_unlock()
{
#ifndef _MUSL_VEMIPS
	if (a_fetch_add(vmlock, -1)==1 && vmlock[1])
		__wake(vmlock, -1, 1);
#endif
}
