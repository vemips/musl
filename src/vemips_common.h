#pragma once

#ifndef VEMIPS_COMMON_H
#define VEMIPS_COMMON_H

#if defined(__clang__) || defined(__GNUC__)
#	define LIKELY(expr) (__builtin_expect(!!(expr), 1))
#	define UNLIKELY(expr) (__builtin_expect((expr), 0))
#	if defined(__clang__)
#		define UNPREDICTABLE(expr) (__builtin_unpredictable(expr))
#		define ASSUME(expr) __builtin_assume(expr)
#	else
#		define UNPREDICTABLE(expr) (expr)
#		define ASSUME(expr) do { if (!(expr)) __builtin_unreachable(); } while(false)
#	endif
#else
#	define LIKELY(expr) (expr)
#	define UNLIKELY(expr) (expr)
#	define UNPREDICTABLE(expr) (expr)
#	define ASSUME(expr)
#endif

#endif /* VEMIPS_COMMON_H */
