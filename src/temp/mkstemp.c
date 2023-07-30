#include <stdlib.h>

int mkstemp(char *template)
{
	return __mkostemps(template, 0, 0);
}

/* vemips */
#if defined(O_LARGEFILE) && O_LARGEFILE != 0
int mkstemp64(char *template) {
	return __mkostemps(template, 0, O_LARGEFILE);
}
#else
weak_alias(mkstemp, mkstemp64);
#endif
