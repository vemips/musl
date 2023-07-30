#ifndef __mips_soft_float

#include <bits/fenv.h>

/*
.set noreorder
*/

static __attribute__((always_inline, flatten)) int _fpu_getcw() {
	int result;
	__asm__ volatile inline ("cfc1 %0,$31" : "=r" (result));
	return result;
}

static __attribute__((always_inline, flatten)) void _fpu_setcw(int control_word) {
	__asm__ volatile inline ("ctc1 %0,$31" : : "r" (control_word));
}

/*
.global feclearexcept
.type  feclearexcept,@function
feclearexcept:
	and     $4, $4, 0x7c
	cfc1    $5, $31
	or      $5, $5, $4
	xor     $5, $5, $4
	ctc1    $5, $31
	jr      $ra
	li      $2, 0
*/

int feclearexcept(int excepts)
{
	excepts &= 0x7c;

	int cw = _fpu_getcw();
	cw |= excepts;
	cw ^= excepts;
	_fpu_setcw(cw);

	return 0;
}

/*
.global feraiseexcept
.type  feraiseexcept,@function
feraiseexcept:
	and     $4, $4, 0x7c
	cfc1    $5, $31
	or      $5, $5, $4
	ctc1    $5, $31
	jr      $ra
	li      $2, 0
*/

int feraiseexception(int excepts)
{
	excepts &= 0x7c;

	int cw = _fpu_getcw();
	cw |= excepts;
	_fpu_setcw(cw);

	return 0;
}

/*
.global fetestexcept
.type  fetestexcept,@function
fetestexcept:
	and     $4, $4, 0x7c
	cfc1    $2, $31
	jr      $ra
	and     $2, $2, $4
*/

int fetestexcept(int excepts)
{
	excepts &= 0x7c;

	int cw = _fpu_getcw();

	return cw & excepts;
}

/*
.global fegetround
.type  fegetround,@function
fegetround:
	cfc1    $2, $31
	jr      $ra
	andi    $2, $2, 3
*/

int fegetround()
{
	int cw = _fpu_getcw();

	return cw & 3;
}

/*
.global __fesetround
.hidden __fesetround
.type __fesetround,@function
__fesetround:
	cfc1    $5, $31
	li      $6, -4
	and     $5, $5, $6
	or      $5, $5, $4
	ctc1    $5, $31
	jr      $ra
	li      $2, 0
*/

int fesetround(int round)
{
	int cw = _fpu_getcw();
	cw &= ~3;
	cw |= round;
	_fpu_setcw(cw);

	return 0;
}

/*
.global fegetenv
.type  fegetenv,@function
fegetenv:
	cfc1    $5, $31
	sw      $5, 0($4)
	jr      $ra
	li      $2, 0
*/

int fegetenv(fenv_t* restrict envp)
{
	int cw = _fpu_getcw();
	envp->__cw = cw;
	return 0;
}

/*
.global fesetenv
.type  fesetenv,@function
fesetenv:
	addiu   $5, $4, 1
	beq     $5, $0, 1f
	 nop
	lw      $5, 0($4)
1:	ctc1    $5, $31
	jr      $ra
	li      $2, 0
*/

int fesetenv(const fenv_t* restrict envp)
{
	/* flush FPU pipeline */
	(void)_fpu_getcw();

	int control_word;

	if (envp == FE_DFL_ENV) {
#ifdef __mips_nan2008
		control_word = 0x000C0000;
#else
		control_word = 0x00000000;
#endif
	}
	else if (envp == FE_NOMASK_ENV) {
#ifdef __mips_nan2008
		control_word = 0x000C0F80;
#else
		control_word = 0x00000F80;
#endif
	}
	else {
		control_word = envp->__cw;
	}
	_fpu_setcw(control_word);

	return 0;
}

#endif
