#ifndef _DEBUG_H
#define _DEBUG_H

#	if defined(_MUSL_VEMIPS)

#ifdef __cplusplus
extern "C" {
#endif

__MUSL_LEAF void vemips_dbg(long value0, ...);

#ifdef __cplusplus
}
#endif

#	endif // _MUSL_VEMIPS

#endif
