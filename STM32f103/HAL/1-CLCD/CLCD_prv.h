/**************************************************************/
/**************************************************************/
/*********		Author: Eslam Nasr   		*******************/
/*********		File: CLCD_prv.h			*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/

#ifndef CLCD_PRV_H_
#define CLCD_PRV_H_

static void voidSendEnablePulse(void);
static void voidSetLCDHalfDataPort(uint8_t Copy_u8Nipple);

#define EIGHT_BIT_MODE			1u
#define FOUR_BIT_MODE			2u


#define ENABLED					1u
#define DISABLED				2u


#endif
