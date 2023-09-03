
#include <stdint.h>

#include "SYSTIC_interface.h"
#include "SYSTIC_register.h"

#include "defines.h"
#include "BIT_MATH.h"



uint8_t SYSTIC_delay_ms(uint16_t time)
{
    uint8_t LOCAL_u8ErrorState = OK ;

    
    /* Set the SYSTIC CLOCK to the Processor clock source */
    SET_BIT(SYSTIC->STK_CTRL,STK_CTRL_CLKSOURCE);

    /* RESET the count falg */
    CLR_BIT(SYSTIC->STK_CTRL,STK_CTRL_COUNTFLAG);

    /* set the value in the SysTick reload value register */
    SYSTIC->STK_LOAD |= (time * 1000 * AHB_CLOCK);


    /* Enable SYSTIC */
     SET_BIT(SYSTIC->STK_CTRL,STK_CTRL_ENABLE);

    /* wait the flag*/

    while ( (GET_BIT(SYSTIC->STK_CTRL,STK_CTRL_COUNTFLAG)) == 0 )
    {
        /* code */
    }


     /* Disable SYSTIC */
     CLR_BIT(SYSTIC->STK_CTRL,STK_CTRL_ENABLE);
    

    return LOCAL_u8ErrorState ;

}



uint8_t SYSTIC_delay_us(uint16_t time)
{
    uint8_t LOCAL_u8ErrorState = OK ;

    /* Set the SYSTIC CLOCK to the Processor clock source */
    SET_BIT(SYSTIC->STK_CTRL,STK_CTRL_CLKSOURCE);

    /* RESET the count falg */
    CLR_BIT(SYSTIC->STK_CTRL,STK_CTRL_COUNTFLAG);

    /* set the value in the SysTick reload value register */
    SYSTIC->STK_LOAD |= (time  * AHB_CLOCK);


    /* Enable SYSTIC */
     SET_BIT(SYSTIC->STK_CTRL,STK_CTRL_ENABLE);

    /* wait the flag*/

    while ( (GET_BIT(SYSTIC->STK_CTRL,STK_CTRL_COUNTFLAG)) == 0 )
    {
        /* code */
    }


     /* Disable SYSTIC */
     CLR_BIT(SYSTIC->STK_CTRL,STK_CTRL_ENABLE);


    return LOCAL_u8ErrorState ;

}