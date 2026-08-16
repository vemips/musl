#if __mips_isa_rev < 6
#define LLSC_M "m"
#else
#define LLSC_M "ZC"
#endif

#define a_ll a_ll
static inline int a_ll(volatile int *p)
{
	int v;
#if __mips < 2
	__asm__ __volatile__ (
		".set push ; .set mips2\n\t"
		"ll %0, %1"
		"\n\t.set pop"
		: "=r"(v) : "m"(*p));
#else
	__asm__ __volatile__ (
		"ll %0, %1"
		: "=r"(v) : LLSC_M(*p));
#endif
	return v;
}

#define a_sc a_sc
static inline int a_sc(volatile int *p, int v)
{
	int r;
#if __mips < 2
	__asm__ __volatile__ (
		".set push ; .set mips2\n\t"
		"sc %0, %1"
		"\n\t.set pop"
		: "=r"(r), "=m"(*p) : "0"(v) : "memory");
#else
	__asm__ __volatile__ (
		"sc %0, %1"
		: "=r"(r), "="LLSC_M(*p) : "0"(v) : "memory");
#endif
	return r;
}

#define a_barrier a_barrier
static inline void a_barrier()
{
#if __mips < 2
	/* mips2 sync, but using too many directives causes
	 * gcc not to inline it, so encode with .long instead. */
	__asm__ __volatile__ (".long 0xf" : : : "memory");
#else
	__asm__ __volatile__ ("sync" : : : "memory");
#endif
}

#define a_pre_llsc a_barrier
#define a_post_llsc a_barrier

#if __GNUC__ && MUSL_WITH_VEMIPS

#define a_crash a_crash
static inline __attribute__((__noreturn__)) void a_crash()
{
	__builtin_trap();
	__builtin_unreachable();
}

#if 0

#define a_cas a_cas
static inline int a_cas(volatile int *p, int t, int s)
{
	return __atomic_compare_exchange_n(p, &s, t, 0, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST);
}

#define a_cas_p a_cas_p
static inline void *a_cas_p(volatile void *p, void *t, void *s)
{
	__atomic_compare_exchange_n((volatile uintptr_t *)p, (uintptr_t*)&s, (uintptr_t)t, 0, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST);
	return s;
}

#define a_swap a_swap
static inline int a_swap(volatile int *p, int v)
{
	return __atomic_exchange_n(p, v, __ATOMIC_SEQ_CST);
}

#define a_fetch_add a_fetch_add
static inline int a_fetch_add(volatile int *p, int v)
{
	return __atomic_fetch_add(p, v, __ATOMIC_SEQ_CST);
}

#define a_fetch_and a_fetch_and
static inline int a_fetch_and(volatile int *p, int v)
{
	return __atomic_fetch_and(p, v, __ATOMIC_SEQ_CST);
}

#define a_fetch_or a_fetch_or
static inline int a_fetch_or(volatile int *p, int v)
{
	return __atomic_fetch_or(p, v, __ATOMIC_SEQ_CST);
}

#define a_and a_and
static inline void a_and(volatile int *p, int v)
{
	__atomic_and_fetch(p, v, __ATOMIC_SEQ_CST);
}

#define a_or a_or
static inline void a_or(volatile int *p, int v)
{
	__atomic_or_fetch(p, v, __ATOMIC_SEQ_CST);
}

#define a_and_64 a_and_64
static inline void a_and_64(volatile uint64_t *p, uint64_t v)
{
	__atomic_and_fetch(p, v, __ATOMIC_SEQ_CST);
}

#define a_or_64 a_or_64
static inline void a_or_64(volatile uint64_t *p, uint64_t v)
{
	__atomic_or_fetch(p, v, __ATOMIC_SEQ_CST);
}

#define a_inc a_inc
static inline void a_inc(volatile int *p)
{
	__atomic_add_fetch(p, 1, __ATOMIC_SEQ_CST);
}

#define a_dec a_dec
static inline void a_dec(volatile int *p)
{
	__atomic_sub_fetch(p, 1, __ATOMIC_SEQ_CST);
}

#define a_store a_store
static inline void a_store(volatile int *p, int x)
{
	__atomic_store_n(p, x, __ATOMIC_SEQ_CST);
}

#define a_ctz_32 a_ctz_32
static inline int a_ctz_32(uint32_t x)
{
	return __builtin_ctz(x);
}

#define a_clz_32 a_clz_32
static inline int a_clz_32(uint32_t x)
{
	return __builtin_clz(x);
}

#define a_ctz_64 a_ctz_64
static inline int a_ctz_64(uint64_t x)
{
	return __builtin_ctzll(x);
}

#define a_clz_64 a_clz_64
static inline int a_clz_64(uint64_t x)
{
	return __builtin_clzll(x);
}

#endif
#endif

#undef LLSC_M
