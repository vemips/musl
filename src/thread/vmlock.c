#include "pthread_impl.h"
#include "fork_impl.h"

#if !MUSL_VEMIPS_WITHOUT_LOCKS
static volatile int vmlock[2];
volatile int *const __vmlock_lockptr = vmlock;
#endif

void __vm_wait()
{
#if !MUSL_VEMIPS_WITHOUT_LOCKS
	int tmp;
	while ((tmp=vmlock[0]))
		__wait(vmlock, vmlock+1, tmp, 1);
#endif
}

void __vm_lock()
{
#if !MUSL_VEMIPS_WITHOUT_LOCKS
	a_inc(vmlock);
#endif
}

void __vm_unlock()
{
#if !MUSL_VEMIPS_WITHOUT_LOCKS
	if (a_fetch_add(vmlock, -1)==1 && vmlock[1])
		__wake(vmlock, -1, 1);
#endif
}
