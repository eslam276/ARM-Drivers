



#include <stdint.h>

#include "SCB_interface.h"
#include "SCB_register.h"
#include "SCB_private.h"



void SCB_voidSetPriorityGroup(PRI_Group_t Copy_enPriorityGroup)
{
    uint32_t Local_u32AIRCR ;

    Local_u32AIRCR =  VECTKEY << VECTKEY_SHIFT ;

    Local_u32AIRCR |=  Copy_enPriorityGroup << PRIGROUP_SHIFT ;

    SCB->AIRCR = Local_u32AIRCR ;



}