#ifndef SYSTIC_REGISTER_H
#define SYSTIC_REGISTER_H


#include "stdint.h"


#define SYSTIC_BASE_ADDRESS             0xE000E010UL

typedef struct 
{
    
    volatile uint32_t STK_CTRL ;
    volatile uint32_t STK_LOAD ;
    volatile uint32_t STK_VAL ;
    volatile uint32_t STK_CALIB ;



}SYSTIC_REG_t;


#define SYSTIC              ( (SYSTIC_REG_t*) SYSTIC_BASE_ADDRESS )



/* STK_CTRL Register bits */

#define STK_CTRL_COUNTFLAG                    16u
#define STK_CTRL_CLKSOURCE                    2u
#define STK_CTRL_TICKINT                      1u
#define STK_CTRL_ENABLE                       0u









#endif