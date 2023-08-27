#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_




typedef enum {
	NOCLK,
	SYSCLK = 4,
	HSI    = 5,
	HSE    = 6,
	PLL    = 7
}system_clock_t;

typedef enum {

	NONE,
	PRE2   = 8,
	PRE4   = 9,
	PRE8   = 10,
	PRE16  = 11,
	PRE64  = 12,
	PRE128 = 13,
	PRE256 = 15,
	PRE512 = 16
}RCC_PRE;


typedef enum{

	MUL_BY_2,
	MUL_BY_3,
	MUL_BY_4,
	MUL_BY_5,
	MUL_BY_6,
	MUL_BY_7,
	MUL_BY_8,
	MUL_BY_9,
	MUL_BY_10,
	MUL_BY_11,
	MUL_BY_12,
	MUL_BY_13,
	MUL_BY_14,
	MUL_BY_15,
	MUL_BY_16

}RCC_PLL_MUL;



#define DISABLE			0
#define ENABLE			1





#endif


