#ifndef _STDLIB_H
#define _STDLIB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#if __cplusplus >= 201103L
#define NULL nullptr
#elif defined(__cplusplus)
#define NULL 0L
#else
#define NULL ((void*)0)
#endif

#define __NEED_size_t
#define __NEED_wchar_t

#include <bits/alltypes.h>

__MUSL_PURE __MUSL_LEAF __MUSL_STRING_ARG(1) __MUSL_NONNULL(1) int atoi (const char *);
__MUSL_PURE __MUSL_LEAF __MUSL_STRING_ARG(1) __MUSL_NONNULL(1) long atol (const char *);
__MUSL_PURE __MUSL_LEAF __MUSL_STRING_ARG(1) __MUSL_NONNULL(1) long long atoll (const char *);
__MUSL_PURE __MUSL_LEAF __MUSL_STRING_ARG(1) __MUSL_NONNULL(1) double atof (const char *);

__MUSL_LEAF __MUSL_STRING_ARG(1) __MUSL_NONNULL(1) float strtof (const char *__restrict, char **__restrict);
__MUSL_LEAF __MUSL_STRING_ARG(1) __MUSL_NONNULL(1) double strtod (const char *__restrict, char **__restrict);
__MUSL_LEAF __MUSL_STRING_ARG(1) __MUSL_NONNULL(1) long double strtold (const char *__restrict, char **__restrict);

__MUSL_LEAF __MUSL_STRING_ARG(1) __MUSL_NONNULL(1) long strtol (const char *__restrict, char **__restrict, int);
__MUSL_LEAF __MUSL_STRING_ARG(1) __MUSL_NONNULL(1) unsigned long strtoul (const char *__restrict, char **__restrict, int);
__MUSL_LEAF __MUSL_STRING_ARG(1) __MUSL_NONNULL(1) long long strtoll (const char *__restrict, char **__restrict, int);
__MUSL_LEAF __MUSL_STRING_ARG(1) __MUSL_NONNULL(1) unsigned long long strtoull (const char *__restrict, char **__restrict, int);

int rand (void);
void srand (unsigned);

__MUSL_MALLOCA(free, 1) __MUSL_ALLOCSIZE(1) __MUSL_LEAF __MUSL_WARN_DISCARD void *malloc (size_t);
__MUSL_MALLOCA(free, 1) __MUSL_ALLOCSIZE(1, 2) __MUSL_LEAF __MUSL_WARN_DISCARD void *calloc (size_t, size_t);
__MUSL_ALLOCSIZE(2) __MUSL_LEAF __MUSL_WARN_DISCARD void *realloc (void *, size_t);
__MUSL_LEAF void free (void *);
__MUSL_MALLOCA(free, 1) __MUSL_ALLOCALIGN(1) __MUSL_ALLOCSIZE(2) __MUSL_LEAF __MUSL_WARN_DISCARD void *aligned_alloc(size_t, size_t);

_Noreturn void abort (void);
int atexit (void (*) (void));
_Noreturn void exit (int);
_Noreturn void _Exit (int);
int at_quick_exit (void (*) (void));
_Noreturn void quick_exit (int);

char *getenv (const char *);

int system (const char *);

void *bsearch (const void *, const void *, size_t, size_t, int (*)(const void *, const void *));
void qsort (void *, size_t, size_t, int (*)(const void *, const void *));

__MUSL_CONST __MUSL_LEAF int abs (int);
__MUSL_CONST __MUSL_LEAF long labs (long);
__MUSL_CONST __MUSL_LEAF long long llabs (long long);

typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;
typedef struct { long long quot, rem; } lldiv_t;

__MUSL_CONST __MUSL_LEAF div_t div (int, int);
__MUSL_CONST __MUSL_LEAF ldiv_t ldiv (long, long);
__MUSL_CONST __MUSL_LEAF lldiv_t lldiv (long long, long long);

__MUSL_LEAF __MUSL_STRING_ARG(1) int mblen (const char *, size_t);
__MUSL_LEAF __MUSL_STRING_ARG(1) __MUSL_STRING_ARG(2) int mbtowc (wchar_t *__restrict, const char *__restrict, size_t);
__MUSL_LEAF __MUSL_STRING_ARG(1); int wctomb (char *, wchar_t);
__MUSL_LEAF __MUSL_STRING_ARG(1) __MUSL_STRING_ARG(2) size_t mbstowcs (wchar_t *__restrict, const char *__restrict, size_t);
__MUSL_LEAF __MUSL_STRING_ARG(1) __MUSL_STRING_ARG(2) size_t wcstombs (char *__restrict, const wchar_t *__restrict, size_t);

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

__MUSL_CONST __MUSL_LEAF size_t __ctype_get_mb_cur_max(void);
#define MB_CUR_MAX (__ctype_get_mb_cur_max())

#define RAND_MAX (0x7fffffff)


#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)

#define WNOHANG    1
#define WUNTRACED  2

#define WEXITSTATUS(s) (((s) & 0xff00) >> 8)
#define WTERMSIG(s) ((s) & 0x7f)
#define WSTOPSIG(s) WEXITSTATUS(s)
#define WIFEXITED(s) (!WTERMSIG(s))
#define WIFSTOPPED(s) ((short)((((s)&0xffff)*0x10001U)>>8) > 0x7f00)
#define WIFSIGNALED(s) (((s)&0xffff)-1U < 0xffu)

__MUSL_LEAF int posix_memalign (void **, size_t, size_t);
int setenv (const char *, const char *, int);
int unsetenv (const char *);
int mkstemp (char *);
int mkostemp (char *, int);
char *mkdtemp (char *);
int getsubopt (char **, char *const *, char **);
int rand_r (unsigned *);

#endif


#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)
char *realpath (const char *__restrict, char *__restrict);
long int random (void);
void srandom (unsigned int);
char *initstate (unsigned int, char *, size_t);
char *setstate (char *);
int putenv (char *);
int posix_openpt (int);
int grantpt (int);
int unlockpt (int);
char *ptsname (int);
__MUSL_PURE __MUSL_LEAF __MUSL_NONNULL_RETURN char *l64a (long);
__MUSL_PURE __MUSL_LEAF __MUSL_STRING_ARG(1) __MUSL_WARN_DISCARD long a64l (const char *);
void setkey (const char *);
double drand48 (void);
double erand48 (unsigned short [3]);
long int lrand48 (void);
long int nrand48 (unsigned short [3]);
long mrand48 (void);
long jrand48 (unsigned short [3]);
void srand48 (long);
unsigned short *seed48 (unsigned short [3]);
void lcong48 (unsigned short [7]);
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#include <alloca.h>
char *mktemp (char *);
int mkstemps (char *, int);
int mkostemps (char *, int, int);
__MUSL_MALLOCA(free, 1) __MUSL_ALLOCSIZE(1) __MUSL_LEAF __MUSL_WARN_DISCARD void *valloc (size_t);
__MUSL_MALLOCA(free, 1) __MUSL_ALLOCALIGN(1) __MUSL_ALLOCSIZE(2) __MUSL_LEAF __MUSL_WARN_DISCARD void *memalign(size_t, size_t);
int getloadavg(double *, int);
int clearenv(void);
#define WCOREDUMP(s) ((s) & 0x80)
#define WIFCONTINUED(s) ((s) == 0xffff)
__MUSL_ALLOCSIZE(2, 3) __MUSL_LEAF __MUSL_WARN_DISCARD void *reallocarray (void *, size_t, size_t);
void qsort_r (void *, size_t, size_t, int (*)(const void *, const void *, void *), void *);
#endif

#ifdef _GNU_SOURCE
int ptsname_r(int, char *, size_t);
__MUSL_LEAF __MUSL_NOALIAS char *ecvt(double, int, int *, int *);
__MUSL_LEAF __MUSL_NOALIAS char *fcvt(double, int, int *, int *);
__MUSL_LEAF __MUSL_NOALIAS char *gcvt(double, int, char *);
char *secure_getenv(const char *);
struct __locale_struct;
__MUSL_LEAF __MUSL_NONNULL(1) __MUSL_STRING_ARG(1) float strtof_l(const char *__restrict, char **__restrict, struct __locale_struct *);
__MUSL_LEAF __MUSL_NONNULL(1) __MUSL_STRING_ARG(1) double strtod_l(const char *__restrict, char **__restrict, struct __locale_struct *);
__MUSL_LEAF __MUSL_NONNULL(1) __MUSL_STRING_ARG(1) long double strtold_l(const char *__restrict, char **__restrict, struct __locale_struct *);

	#if defined(_MUSL_VEMIPS)
__MUSL_LEAF __MUSL_NONNULL(1) __MUSL_STRING_ARG(1) long strtol_l(const char *__restrict, char **__restrict, int, struct __locale_struct *);
__MUSL_LEAF __MUSL_NONNULL(1) __MUSL_STRING_ARG(1) unsigned long strtoul_l(const char *__restrict, char **__restrict, int, struct __locale_struct *);
__MUSL_LEAF __MUSL_NONNULL(1) __MUSL_STRING_ARG(1) long long strtoll_l(const char *__restrict, char **__restrict, int, struct __locale_struct *);
__MUSL_LEAF __MUSL_NONNULL(1) __MUSL_STRING_ARG(1) unsigned long long strtoull_l(const char *__restrict, char **__restrict, int, struct __locale_struct *);
	#endif // _MUSL_VEMIPS
#endif

#if defined(_LARGEFILE64_SOURCE)
#define mkstemp64 mkstemp
#define mkostemp64 mkostemp
#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define mkstemps64 mkstemps
#define mkostemps64 mkostemps
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
