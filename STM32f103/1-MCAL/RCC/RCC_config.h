#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


/* Choose the System Clock
 * Options: 1-HSI 	(High Speed Internal clock)
 * 			2-HSE 	(High Speed External clock)
 * 			3-PLL	(Phase Locked Loop clock)
 **/
#define RCC_SYSTEM_CLOCK	HSE


/* Activate or Disable Clock Sources
 * Options: 1-ENABLE
 * 			2-DISABLE
 */
#define RCC_HSI_EN			ENABLE		//activates High Speed Internal clock if 1, disable otherwise
#define RCC_HSE_EN			ENABLE		//activates High Speed External clock if 1, disable otherwise
#define RCC_PLL_EN			DISABLE		//activates Phase Locked Loop clock if 1, disable otherwise


/* Enable if High Speed External Clock is RC
 * Options: 1- ENABLE
 * 			2- DISABLE
 *
 * */
#define RC_HSE_BYPASS		DISABLE



#define RCC_TRIMMING_VALUE	16


/* Enable clock security if HSE is selected as System Clock
 * Options: 1-ENABLE
 * 			2-DISABLE
 **/
#define RCC_CSS_ENABLE		ENABLE


/* Choose the prescalar of AHB, if any
 * Options: 1- NONE
 * 			2- PRE2
 * 			3- PRE4
 * 			4- PRE8
 * 			5- PRE16
 * 			6- PRE64
 * 			7- PRE128
 * 			8- PRE256
 * 			9- PRE512
 **/
#define RCC_AHB_PRESCALAR	NONE


/* Choose the prescalar of APB1, if any
 * Options: 1- NONE
 * 			2- PRE2
 * 			3- PRE4
 * 			4- PRE8
 * 			5- PRE16
 **/
#define RCC_APB1_PRESCALAR	NONE


/* Choose the prescalar of APB2, if any
 * Options: 1- NONE
 * 			2- PRE2
 * 			3- PRE4
 * 			4- PRE8
 * 			5- PRE16
 **/
#define RCC_APB2_PRESCALAR	NONE



/* Choose the prescalar of ADC
 * Options: 1- PRE2
 * 			2- PRE4
 **/
#define RCC_ADC_PRESCALAR	PRE2

/* Choose the PLL source
 * Note: HSI is automatically divided by 2
 * Options: 1- HSI
 * 			2- HSE
 **/
#define RCC_PLL_SRC			HSE


/* Enable HSE divide by 2 prescalar if selected as PLL source
 * Options: 1-ENABLE
 * 			2-DISABLE
 **/
#define RCC_PLL_HSE_DIV		ENABLE


/* Select the PLL multiplication factor
 * Options: 1-  MUL_BY_2
 *			2-  MUL_BY_3
 *			3-  MUL_BY_4
 *          4-  MUL_BY_5
 *          5-  MUL_BY_6
 *          6-  MUL_BY_7
 *          7-  MUL_BY_8
 *          8-  MUL_BY_9
 *          9-  MUL_BY_10
 *          10- MUL_BY_11
 *          11- MUL_BY_12
 *          12- MUL_BY_13
 *          13- MUL_BY_14
 *          14- MUL_BY_15
 *          15- MUL_BY_16
 **/
#define RCC_PLL_MUL			MUL_BY_2




/* Select the microcontroller clock output source, if any
 * Note: PLL clock gets divided by 2 automatically
 * Options: 1- NOCLK
 *          2- SYSCLK
 * 			3- HSI
 * 			4- HSE
 * 			5- PLL
 **/
#define RCC_MCO_SRC			NOCLK



#endif
