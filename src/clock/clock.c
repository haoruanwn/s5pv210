#include "s5pv210.h"
#include "clock.h"

void clock_init()
{
	/* 1. Set PLL lock time registers (using default values) */

	/* 2. Set PLL CON registers (using recommended values from datasheet) */
	APLLCON0 = (1 << 31) | (125 << 16) | (3 << 8) | (1 << 0); /* FOUT = 1000MHz */
	MPLLCON  = (1 << 31) | (667 << 16) | (12 << 8)| (1 << 0); /* FOUT = 667MHz */
	EPLLCON0 = (1 << 31) | (48 << 16)  | (3 << 8) | (2 << 0); /* FOUT = 96MHz */
	VPLLCON  = (1 << 31) | (108 << 16) | (6 << 8) | (3 << 0); /* FOUT = 54MHz */

	/* 3. Select PLL as the source clock */
	CLK_SRC0 = (1 << 12) | (1 << 8) | (1 << 4) | (1 << 0);

	/* 4. Set system clock dividers */
	CLK_DIV0 = (1 << 28) | (4 << 24) | (1 << 20) | (3 << 16) | (1 << 12) | (4 << 8) | (0 << 0);
}