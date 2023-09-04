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
#define KPD_u8ROW_PORT              DIO_u8PORTB
#define KPD_u8ROW1_PIN             DIO_u8PIN4
#define KPD_u8ROW2_PIN             DIO_u8PIN5
#define KPD_u8ROW3_PIN             DIO_u8PIN6
#define KPD_u8ROW4_PIN             DIO_u8PIN7

#define KPD_u8COL_PORT              DIO_u8PORTD
#define KPD_u8COL1_PIN             DIO_u8PIN2
#define KPD_u8COL2_PIN             DIO_u8PIN3
#define KPD_u8COL3_PIN             DIO_u8PIN4
#define KPD_u8COL4_PIN             DIO_u8PIN5

#define KPD_u8BUTTON_ARR			{{1,2,3,4,},{5,6,7,8},{9,10,11,12},{13,14,15,16}}

#define KPD_u8NO_Pressed_KEY_VAL    0xff

#endif
