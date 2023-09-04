



#include "STD_TYPES.h"
#include "LM35.h"

uint16 LM35_u16GetTemp(uint8 ADC_u8GetChannelReading )
{


    #if ADC_u8RESOLUTION == EIGHT_BITS

         return (uint16)(((uint32)ADC_u8GetChannelReading * 500UL) / 256UL);

    #elif ADC_u8RESOLUTION == TEN_BITSs

         return (uint16)(((uint32)ADC_u8GetChannelReading * 500UL) / 1024UL);

    #else 

        #error Wrong ADC_u8RESOLUTION confegration option 

    #endif



}
