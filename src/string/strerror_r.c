/* vemips */
// #define _GNU_SOURCE
#include <string.h>
#include <errno.h>

/* vemips */
int __xpg_strerror_r(int err, char *buf, size_t buflen)
{
	char *msg = strerror(err);
	size_t l = strlen(msg);
	if (l >= buflen) {
		if (buflen) {
			memcpy(buf, msg, buflen-1);
			buf[buflen-1] = 0;
		}
		return ERANGE;
	}
	memcpy(buf, msg, l+1);
	return 0;
}

#if defined(_GNU_SOURCE)
char* strerror_r(int err, char *buf, size_t buflen)
{
	char *msg = strerror(err);
	size_t l = strlen(msg);
	if (l >= buflen) {
		if (buflen) {
			memcpy(buf, msg, buflen-1);
			buf[buflen-1] = 0;
		}
		return buf;
	}
	memcpy(buf, msg, l+1);
	return buf;
}
#else
weak_alias(__xpg_strerror_r, strerror_r);
#endif
