/**************************************************************/
/**************************************************************/
/*********		Author: Eslam Nasr   		*******************/
/*********		File: SYSTIC_program.c	    *******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/
#include <stdint.h>

#include "SYSTIC_interface.h"
#include "SYSTIC_register.h"

#include "defines.h"
#include "BIT_MATH.h"



uint8_t SYSTIC_delay_ms(uint32_t time)
{
    uint8_t LOCAL_u8ErrorState = OK ;

    uint32_t LOCAL_u32Value = (time *1000 *  AHB_CLOCK / 8 );

    /* check if the value > the Register  available bits  */
    if(LOCAL_u32Value > 0xffffff)
    {
    	LOCAL_u32Value = 0xffffff ;
    }



    
    /* Set the SYSTIC CLOCK to the Processor clock source / 8  */
    CLR_BIT(SYSTIC->STK_CTRL,STK_CTRL_CLKSOURCE);

    /* RESET the count falg */
    CLR_BIT(SYSTIC->STK_CTRL,STK_CTRL_COUNTFLAG);

    /* Clear the value in the SysTick reload value register */
    SYSTIC->STK_LOAD &= 0b11111111<<24;

    /* set the value in the SysTick reload value register */
    SYSTIC->STK_LOAD |= LOCAL_u32Value ;

    /* Clear the VAL Register to load the start of the down counter from the LOAD register */
       SYSTIC->STK_VAL &= 0b11111111<<24;


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



uint8_t SYSTIC_delay_us(uint32_t time)
{
    uint8_t LOCAL_u8ErrorState = OK ;

    uint32_t LOCAL_u32Value = (time  *  AHB_CLOCK / 8 );

    /* check if the value > the Register  available bits  */
    if(LOCAL_u32Value > 0xffffff)
    {
    	LOCAL_u32Value = 0xffffff ;
    }



    
    /* Set the SYSTIC CLOCK to the Processor clock source / 8  */
    CLR_BIT(SYSTIC->STK_CTRL,STK_CTRL_CLKSOURCE);

    /* RESET the count falg */
    CLR_BIT(SYSTIC->STK_CTRL,STK_CTRL_COUNTFLAG);

    /* Clear the value in the SysTick reload value register */
    SYSTIC->STK_LOAD &= 0b11111111<<24;

    /* set the value in the SysTick reload value register */
    SYSTIC->STK_LOAD |= LOCAL_u32Value ;

    /* Clear the VAL Register to load the start of the down counter from the LOAD register */
       SYSTIC->STK_VAL &= 0b11111111<<24;


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
