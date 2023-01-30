/**********************************************************************************************************************

*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*         File:  RCC.h
*       Module:  -Reset and clock control 
*
*  Description:  Header file contians the 1- RCC data types
*                                         2- RCC function prototypes
*                                         3- RCC MACROS for Clock calibration     
*  
*********************************************************************************************************************/
#ifndef RCC_H
#define RCC_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Libs/stmTypes.h"


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
//APB2 clocks
typedef enum{
	TIM1_CLK,
	USART1_CLK = 4,
	USART6_CLK,
	ADC1_CLK = 8,
	SDIO_CLK = 11,
	SPI1_CLK,
	SPI4_CLK,
	SYSCFG_CLK,
	TIM9_CLK = 16,
	TIM10_CLK,
	TIM11_CLK
}APB2prephirals_t;
//APB1 clocks
typedef enum{
	TIM2_CLK,
	TIM3_CLK,
	TIM4_CLK,
	TIM5_CLK,
	WWDG_CLK = 11,
	SPI_2_CLK = 14,
	SPI_3_CLK,
  USART2_CLK = 17,
  I2C_1_CLK = 21,
  I2C_2_CLK,
  I2C_3_CLK,
  PWR_CLK = 28  
}APB1prephirals_t;
//AHB2 clocks
typedef enum{
	OTG_CLK = 7
}AHB2prephirals_t;
//AHB1 clocks
typedef enum{
	GPIOA_CLK,
	GPIOB_CLK,
	GPIOC_CLK,
	GPIOD_CLK,
	GPIOH_CLK = 7,
	CRC_CLK = 12,
	DMA1_CLK = 21,
	DMA2_CLK = 22
}AHB1prephirals_t;
//MCU clock sources
typedef enum{
	HSI,
	HSE_CRYSTAL,
	HSE_RC,
	PLL_HSI,
	PLL_HSE
}RCCClkSrc_t;
//MCU Buses
typedef enum{
	AHB2,
	AHB1,
	APB2,
	APB1
}RCCBuses_t;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef F_CPU
  #define F_CPU                 16000000UL
#endif
#define RCC_CLK_SRC           HSI

#define PLL_CLOCK_M_FACTOR    16      //Takes the values from 2  -> 63
#define PLL_CLOCK_N_FACTOR    (168)   //Takes the values from 50 -> 432
#define PLL_CLOCK_P_FACTOR    0       //takes the values 2,4,6,8
#define PLL_CLOCK_Q_FACTOR    (10 - 2)//Takes the values from 2 -> 15

#define HSI_TRIM_VALUE        16

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void RCC_initSystemClock(RCCClkSrc_t ClkSrc)        
* \Description     : This function initiate the system clock source                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ClkSrc  -> The system clock source (HSI,HSE,PLL)                     
* \Parameters (out): None                                                      
* \Return value:   : viod                                 
*******************************************************************************/
void RCC_initSystemClock(RCCClkSrc_t ClkSrc);
/******************************************************************************
* \Syntax          : void RCC_prephiralEnableClock(RCCBuses_t Bus,uint8 prepheralNum)        
* \Description     : This function Enables a certian Bus prephiral                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Bus          -> the prephiral clock Bus 
*                    prepheralNum -> the prephiral  Enable pin in the Bus register                     
* \Parameters (out): None                                                      
* \Return value:   : viod                                 
*******************************************************************************/
void RCC_prephiralEnableClock(RCCBuses_t Bus,uint8 prepheralNum);
/******************************************************************************
* \Syntax          : void RCC_prephiralDisableClock(RCCBuses_t Bus,uint8 prepheralNum)        
* \Description     : This function Disables a certian Bus prephiral                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Bus          -> the prephiral clock Bus 
*                    prepheralNum -> the prephiral  Enable pin in the Bus register                     
* \Parameters (out): None                                                      
* \Return value:   : viod                                 
*******************************************************************************/
void RCC_prephiralDisableClock(RCCBuses_t Bus,uint8 prepheralNum);
 
#endif  /* RCC_H */

/**********************************************************************************************************************
 *  END OF FILE: RCC.h
 *********************************************************************************************************************/

