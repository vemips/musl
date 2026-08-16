#if MUSL_WITH_VEMIPS
#define _BSD_SOURCE
#include <unistd.h>
#include "syscall.h"
#include <stdarg.h>

void vemips_dbg(long value0, ...)
{
	va_list ap;
	long a,b,c,d,e,f;
	va_start(ap, value0);
	a=va_arg(ap, long);
	b=va_arg(ap, long);
	c=va_arg(ap, long);
	d=va_arg(ap, long);
	e=va_arg(ap, long);
	va_end(ap);
	(void)__syscall_ret(__syscall(SYS_debug,value0,a,b,c,d,e));
}
#endif
