


#include "STD_TYPES.h"
#include "LDR.h"


uint16 LDR_u16GetAnalogVolt(uint8 ADC_u8GetChannelReading)
{


    #if ADC_u8RESOLUTION == EIGHT_BITS

         return (uint16)(((uint32)ADC_u8GetChannelReading * 5000UL) / 256UL);

    #elif ADC_u8RESOLUTION == TEN_BITSs

         return (uint16)(((uint32)ADC_u8GetChannelReading * 5000UL) / 1024UL);

    #else 

        #error Wrong ADC_u8RESOLUTION confegration option 

    #endif


}
