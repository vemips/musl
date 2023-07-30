#define _BSD_SOURCE
#include <stdlib.h>

int mkostemp(char *template, int flags)
{
	return __mkostemps(template, 0, flags);
}

/* vemips */
#if defined(O_LARGEFILE) && O_LARGEFILE != 0
int mkostemp64(char *template, int flags) {
	return __mkostemps(template, 0, flags | O_LARGEFILE);
}
#else
weak_alias(mkostemp, mkostemp64);
#endif
