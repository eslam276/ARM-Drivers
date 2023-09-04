
#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

#include <stdint.h>


void SSD1_ON(void);
void SSD2_ON(void);
void SSD3_ON(void);




void SSD1_OFF(void);
void SSD2_OFF(void);
void SSD3_OFF(void);




void SSD_SendNumber(uint8_t Number );


/* the three SSDs */
void SSD_PinInit(void);




#endif