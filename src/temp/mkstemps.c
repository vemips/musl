#define _BSD_SOURCE
#include <stdlib.h>

int mkstemps(char *template, int len)
{
	return __mkostemps(template, len, 0);
}

/* vemips */
#if defined(O_LARGEFILE) && O_LARGEFILE != 0
int mkstemps64(char *template, int len) {
	return __mkostemps(template, len, O_LARGEFILE);
}
#else
weak_alias(mkstemps, mkstemps64);
#endif
