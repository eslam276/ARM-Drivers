/**************************************************************/
/**************************************************************/
/*********		Author: Eslam Nasr   		*******************/
/*********		File: KPD_CFG.h			    *******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/

#ifndef KDP_CFG_H_
#define KDP_CFG_H_



#define KPD_u8COL_NUM               4u
#define KPD_u8ROW_NUM               4u

/*You can configure the KeyPad */
#define KPD_u8ROW_PORT             PORTA
#define KPD_u8ROW1_PIN             PIN4
#define KPD_u8ROW2_PIN             PIN5
#define KPD_u8ROW3_PIN             PIN6
#define KPD_u8ROW4_PIN             PIN7

#define KPD_u8COL_PORT             PORTB
#define KPD_u8COL1_PIN             PIN11
#define KPD_u8COL2_PIN             PIN10
#define KPD_u8COL3_PIN             PIN1
#define KPD_u8COL4_PIN             PIN0

#define KPD_u8BUTTON_ARR			{{1,2,3,4,},{5,6,7,8},{9,10,11,12},{13,14,15,16}}

#define KPD_u8NO_Pressed_KEY_VAL    0xff

#endif
