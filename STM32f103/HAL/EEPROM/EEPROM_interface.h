/*********************************************************/
/*********************************************************/
/***********		Author: Eslam Nasr     	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: EEPROM       **************/
/***********		Version: 1.00		 	**************/
/*********************************************************/
/*********************************************************/


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_


uint8 EEPROM_u8SendDataByte(uint16 Copy_u16LocationAddress, uint8 Copy_u8Data);

uint8 EEPPROM_u8ReadDataByte(uint16 Copy_u16LocationAddress);


#endif