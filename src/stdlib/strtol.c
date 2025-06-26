#include "stdio_impl.h"
#include "intscan.h"
#include "shgetc.h"
#include <inttypes.h>
#include <limits.h>
#include <ctype.h>

static unsigned long long strtox(const char *s, char **p, int base, unsigned long long lim)
{
	FILE f;
	sh_fromstring(&f, s);
	shlim(&f, 0);
	unsigned long long y = __intscan(&f, base, 1, lim);
	if (p) {
		size_t cnt = shcnt(&f);
		*p = (char *)s + cnt;
	}
	return y;
}

unsigned long long strtoull(const char *restrict s, char **restrict p, int base)
{
	return strtox(s, p, base, ULLONG_MAX);
}

long long strtoll(const char *restrict s, char **restrict p, int base)
{
	return strtox(s, p, base, LLONG_MIN);
}

unsigned long strtoul(const char *restrict s, char **restrict p, int base)
{
	return strtox(s, p, base, ULONG_MAX);
}

long strtol(const char *restrict s, char **restrict p, int base)
{
	return strtox(s, p, base, 0UL+LONG_MIN);
}

intmax_t strtoimax(const char *restrict s, char **restrict p, int base)
{
	return strtoll(s, p, base);
}

uintmax_t strtoumax(const char *restrict s, char **restrict p, int base)
{
	return strtoull(s, p, base);
}

#if MUSL_WITH_VEMIPS

long strtol_l(const char *__restrict s, char **__restrict p, int base, struct __locale_struct *)
{
	return strtol(s, p, base);
}

unsigned long strtoul_l(const char *__restrict s, char **__restrict p, int base, struct __locale_struct *)
{
	return strtoul(s, p, base);
}

long long strtoll_l(const char *__restrict s, char **__restrict p, int base, struct __locale_struct *)
{
	return strtoll(s, p, base);
}

unsigned long long strtoull_l(const char *__restrict s, char **__restrict p, int base, struct __locale_struct *)
{
	return strtoull(s, p, base);
}

#endif

weak_alias(strtol, __strtol_internal);
weak_alias(strtoul, __strtoul_internal);
weak_alias(strtoll, __strtoll_internal);
weak_alias(strtoull, __strtoull_internal);
weak_alias(strtoimax, __strtoimax_internal);
weak_alias(strtoumax, __strtoumax_internal);
#if MUSL_WITH_VEMIPS
weak_alias(strtol_l, __strtol_l_internal);
weak_alias(strtoul_l, __strtoul_l_internal);
weak_alias(strtoll_l, __strtoll_l_internal);
weak_alias(strtoull_l, __strtoull_l_internal);
#endif
