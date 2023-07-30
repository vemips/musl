#include <string.h>
#include <libgen.h>

#ifdef _GNU_SOURCE
char *basename(const char *s)
#else
char *basename(char *s)
#endif
{
	size_t i;
	if (!s || !*s) return ".";
	i = strlen(s)-1;
	for (; i&&s[i]=='/'; i--) ((char*)s)[i] = 0;
	for (; i&&s[i-1]!='/'; i--);
	return s+i;
}

weak_alias(basename, __xpg_basename);
