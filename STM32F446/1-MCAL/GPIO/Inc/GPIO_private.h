/*****************************************************************/
/*****************************************************************/
/********************		Author: Eslam Nasr  	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: GPIO				**************/
/********************		Version: 1.00			**************/
/********************		Date: 31-8-2023			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_


#define GPIO_PERIPHRAL_NUM          8u

#define MODER_MASK                  0b11                
#define MODER_PIN_ACCESS            2u



#define PUPDR_MASK                  0b11                
#define PUPDR_PIN_ACCESS            2u


#define OTYPER_MASK                 1u




#define OSPEEDER_MASK                0b11                
#define OSPEEDER_PIN_ACCESS          2u



#define AFR_MASK                     0b1111                
#define AFR_PIN_ACCESS               4u


#define AFR_PIN_SHIFTING             8u



#endif