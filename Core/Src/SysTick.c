/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SysTick.c
*        \brief  This file includes the impelemntation of the UART functions 
*
*      \details  This file includes the function that Deliver -Initiation of SysTick
*                                                             -SysTick  delay function
*                                                             -ISR functions set
*
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../../Libs/BitMath.h"
#include "../../Libs/stmTypes.h"
#include "../../Libs/Registers.h"

#include "../Inc/SysTick.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
CallBack_t (*SysTick_CallBack)(void) = (void*)0;

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void SysTick_init(SysTickCnfg_t *cnfg){
	if(cnfg->clkSrc == CLKSRC_AHB_DIV_8){//Choose the SysTick clock source
		SYSTICK_USE_DIV_CLKSRC();
	}else{
		SYSTICK_USE_CLKSRC();
	}
	if(cnfg->InterruptEnable == SYSTICK_INT_ENABLE){//choose the SysTick Interrupt
		SYSTICK_ENABLE_INTERRUPT();
	}else{
		SYSTICK_DISABLE_INTERRUPT();
	}
	
}

void SysTick_delayMs(uint32 period){
	SysTick -> VAL = 0;//Clear the Systick value
	SysTick -> LOAD = (F_SYSTICK/Ms)-1;//Update the systick counter
	SYSTICK_ENABLE();//Enable the SysTick
	//Loop until the delay period End
	for(int i = 0;i<period;i++){
		SYSTICK_WAIT_COUNT_END();
	}
	SYSTICK_DISABLE();//Disable the SysTick
}

void SysTick_setCallBack(CallBack_t (*CallBack)(void)){
	SysTick_CallBack = CallBack;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/