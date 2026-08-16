#ifndef MALLOC_IMPL_H
#define MALLOC_IMPL_H

#include <sys/mman.h>
#include "dynlink.h"

struct chunk {
	size_t psize, csize;
	struct chunk *next, *prev;
};

struct bin {
	#if !MUSL_VEMIPS_WITHOUT_LOCKS
	volatile int lock[2];
	#endif
	struct chunk *head;
	struct chunk *tail;
};

#define SIZE_ALIGN (4*sizeof(size_t))
#define SIZE_MASK (-SIZE_ALIGN)
#define OVERHEAD (2*sizeof(size_t))
#if !MUSL_WITH_VEMIPS
#define MMAP_THRESHOLD (0x1c00*SIZE_ALIGN)
#endif
#define DONTCARE 16
#define RECLAIM 163840

#define CHUNK_SIZE(c) ((c)->csize & -2)
#define CHUNK_PSIZE(c) ((c)->psize & -2)
#define PREV_CHUNK(c) ((struct chunk *)((char *)(c) - CHUNK_PSIZE(c)))
#define NEXT_CHUNK(c) ((struct chunk *)((char *)(c) + CHUNK_SIZE(c)))
#define MEM_TO_CHUNK(p) (struct chunk *)((char *)(p) - OVERHEAD)
#define CHUNK_TO_MEM(c) (void *)((char *)(c) + OVERHEAD)
#define BIN_TO_CHUNK(i) (MEM_TO_CHUNK(&mal.bins[i].head))

#define C_INUSE  ((size_t)1)

#if MUSL_WITH_VEMIPS
#	define IS_MMAPPED(c) (0)
#else
#	define IS_MMAPPED(c) !((c)->csize & (C_INUSE))
#endif

hidden void __bin_chunk(struct chunk *);

#endif
