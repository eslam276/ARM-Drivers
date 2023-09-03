#ifndef SYSTIC_INTERFACE_H
#define SYSTIC_INTERFACE_H


#include <stdint.h>


#define AHB_CLOCK           8u   /* IN MHz */


uint8_t SYSTIC_delay_ms(uint32_t time);
uint8_t SYSTIC_delay_us(uint32_t time);











#endif
