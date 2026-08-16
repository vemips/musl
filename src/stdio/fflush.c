#include "stdio_impl.h"

/* stdout.c will override this if linked */
static FILE *volatile dummy = 0;
weak_alias(dummy, __stdout_used);
weak_alias(dummy, __stderr_used);

int fflush(FILE *f)
{
	if (!f) {
		int r = 0;
		if (__stdout_used) r |= fflush(__stdout_used);
		if (__stderr_used) r |= fflush(__stderr_used);

		for (f=*__ofl_lock(); f; f=f->next) {
#if !MUSL_VEMIPS_WITHOUT_LOCKS
			FLOCK(f);
#endif
			if (f->wpos != f->wbase) r |= fflush(f);
#if !MUSL_VEMIPS_WITHOUT_LOCKS
			FUNLOCK(f);
#endif
		}
		__ofl_unlock();

		return r;
	}

#if !MUSL_VEMIPS_WITHOUT_LOCKS
	FLOCK(f);
#endif

	/* If writing, flush output */
	if (f->wpos != f->wbase) {
		f->write(f, 0, 0);
		if (!f->wpos) {
#if !MUSL_VEMIPS_WITHOUT_LOCKS
			FUNLOCK(f);
#endif
			return EOF;
		}
	}

	/* If reading, sync position, per POSIX */
	if (f->rpos != f->rend) f->seek(f, f->rpos-f->rend, SEEK_CUR);

	/* Clear read and write modes */
	f->wpos = f->wbase = f->wend = 0;
	f->rpos = f->rend = 0;

#if !MUSL_VEMIPS_WITHOUT_LOCKS
	FUNLOCK(f);
#endif
	return 0;
}

weak_alias(fflush, fflush_unlocked);
