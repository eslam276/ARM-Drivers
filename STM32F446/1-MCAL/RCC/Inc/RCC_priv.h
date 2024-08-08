#ifndef RCC_PRIV_H
#define RCC_PRIV_H

#define RCC_CLKTIMEOUT            50000u
#define RCC_SYS_CLK_STATUSMASK    0x0000000c
#define RCC_SYS_CLK_MASK          0xfffffffc

#define PLLMULL_FACTOR_MAX        432u
#define PLLMULL_FACTOR_MIN        50u

#define PLLMULL_FACTOR_MASK       0xffff803f
#define PLLINPUT_DIVFACTOR_MASK   0xffffffc0
#define PLLDIVFACTOT_MASK         0xfffcffff


#define CLK_EnableTimeout 4u
#define	CLK_DisableFail   5u
#define CLK_CFG_ERR       6u


#endif
