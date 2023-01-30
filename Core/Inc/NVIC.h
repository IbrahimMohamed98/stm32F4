/**********************************************************************************************************************

*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*         File:  NVIC.H
*       Module:  -Nested vector Interrupt control
*
*  Description:  -This file include the following 1-NVIC Exceptions
*                                                 2-NVIC functions prototypes
*  
*********************************************************************************************************************/
#ifndef NVIC_H
#define NVIC_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Libs/BitMath.h"
#include "../../Libs/stmTypes.h"
#include "../../Libs/Registers.h"



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

	
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


typedef enum{
	WWDG_EXC,
	EXTI16_PVD_EXC,
	EXTI21_TAM_STAMP_EXC,
	EXTI22_RTC_WKUP_EXC,
	FLASH_EXC,
	RCC_EXC,
	EXTI0_EXC,
	EXTI1_EXC,
	EXTI2_EXC,
	EXTI3_EXC,
	EXTI4_EXC,
	DMA1_Stream0_EXC,
	DMA1_Stream1_EXC,
	DMA1_Stream2_EXC,
	DMA1_Stream3_EXC,
	DMA1_Stream4_EXC,
	DMA1_Stream5_EXC,
	DMA1_Stream6_EXC,
	ADC_EXC,
	EXTI19_5_EXC = 23,
	TIM1_BRK_TIM9_EXC,
	TIM1_UP_TIM10,
	TIM1_TRG_COM_TIM11_EXC,
	TIM1_CC_EXC,
	TIM2_EXC,
	TIM3_EXC,
	TIM4_EXC,
	I2C1_EV_EXC,
	I2C1_ER_EXC,
	I2C2_EV_EXC,
	I2C2_ER_EXC,
	SPI1_EXC,
	SPI2_EXC,
	UART1_EXC,
	UART2_EXC,
	EXTI_15_10_EXC =40,
	EXTI_17_RTC_ALARM_EXC,
	EXTI_18_OTG_FS_WKUP,
	DMA1_Stream7_EXC=47,
	SDIO_EXC=49,
	TIM5_EXC,
	SPI3_EXC,
	DMA2_Stream0_EXC = 56,
	DMA2_Stream1_EXC,
	DMA2_Stream2_EXC,
	DMA2_Stream3_EXC,
	DMA2_Stream4_EXC,
	OTG_FS_EXC = 67,
	DMA2_Stream5_EXC,
	DMA2_Stream6_EXC,
	DMA2_Stream7_EXC,
	UART6_EXC,
	I2C3_EV_EXC,
	I2C3_ER_EXC,
	FPU_EXC,
	SPI4_EXC
}NVICExc_t;

typedef enum{
	_16GROUPS,
	_8GROUPS_2SUBGROUPS = 4,
	_4GROUPS_4SUBGROUPS,
	_2GROUPS_8SUBGROUPS,
	_16SUBGROUP
}NVICPriorityGrouping_t;



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void NVIC_init(NVICPriorityGrouping_t PriorityGrouping)        
* \Description     : Initiate the NVIC and set the priority grouping                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PriorityGrouping -> the priority grouping type                     
* \Parameters (out): None                                                     
* \Return value:   : None
*******************************************************************************/
void NVIC_init(NVICPriorityGrouping_t PriorityGrouping);

/******************************************************************************
* \Syntax          : void NVIC_enableInterrupt(NVICExc_t Exception)        
* \Description     : Enable the exception                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PriorityGrouping -> the priority grouping type            
* \Parameters (out): None                                                      
* \Return value:   : None                                    
*******************************************************************************/
void NVIC_enableInterrupt(NVICExc_t Exception);
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Disable the exception                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PriorityGrouping -> the priority grouping type            
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/
void NVIC_disableInterrupt(NVICExc_t Exception);
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : set the Exception pending flag                          
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PriorityGrouping -> the priority grouping type            
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/
void NVIC_setPinding(NVICExc_t Exception);
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Clear the Exception pending Flag                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PriorityGrouping -> the priority grouping type            
* \Parameters (out): None                                                      
* \Return value:   : None                                    
*******************************************************************************/
void NVIC_clearPinding(NVICExc_t Exception);
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Returns the exception status                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PriorityGrouping -> the priority grouping type            
* \Parameters (out): None                                                      
* \Return value:   : uint8                                    
*******************************************************************************/
uint8 NVIC_isActiveInterrupt(NVICExc_t Exception);
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Set the Exception priority                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PriorityGrouping -> the priority grouping type            
* \Parameters (out): None                                                      
* \Return value:   : None                                    
*******************************************************************************/
void NVIC_setPriority(NVICExc_t Exception,uint8 priority);
 
#endif  /* NVIC_H */

/**********************************************************************************************************************
 *  END OF FILE: NVIC.h
 *********************************************************************************************************************/
 