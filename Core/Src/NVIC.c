/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  NVIC.c
 *        \brief  The impelementation of NVIC functions
 *
 *      \details  The functions in this file delevier the following 1-Initiate the Interrupt grouping
 *                                                                  2-Enable/Disable interrupts
 *                                                                  3-Set/Clear the pinding state
 *                                                                  4-Set the inpterrupt priority
 *                                                                  5-Check if the interrupt is active or not
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../../Libs/BitMath.h"
#include "../../Libs/stmTypes.h"
#include "../../Libs/Registers.h"

#include "../Inc/NVIC.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

void NVIC_init(NVICPriorityGrouping_t PriorityGrouping){
	AIRCR = 0x0F5A0000 | (PriorityGrouping<<8);//Set the priority Grouping at the AIRCR
}
void NVIC_enableInterrupt(NVICExc_t Exception){
	uint8 ExceptionRegister = Exception/32;//The exception register
	uint8 ExceptionBit      = Exception%32;//The exception register bit
	BIT_SET(NVIC -> ISER[ExceptionRegister],ExceptionBit);//Enable the exception  
}
void NVIC_disableInterrupt(NVICExc_t Exception){
	uint8 ExceptionRegister = Exception/32;//The exception register
	uint8 ExceptionBit      = Exception%32;//The exception register bit
	BIT_SET(NVIC -> ICER[ExceptionRegister],ExceptionBit);//Disable the exception,ExceptionBit);  
}
void NVIC_setPinding(NVICExc_t Exception){
	uint8 ExceptionRegister = Exception/32;//The exception register
	uint8 ExceptionBit      = Exception%32;//The exception register bit
	BIT_SET(NVIC -> ISPR[ExceptionRegister],ExceptionBit);//Set the exception pinding flag
}
void NVIC_clearPinding(NVICExc_t Exception){
	uint8 ExceptionRegister = Exception/32;//The exception register
	uint8 ExceptionBit      = Exception%32;//The exception register bit
	BIT_SET(NVIC -> ICPR[ExceptionRegister],ExceptionBit);//Clear the exception pinding flag
}
uint8 NVIC_isActiveInterrupt(NVICExc_t Exception){
	uint8 ExceptionRegister = Exception/32;//The exception register
	uint8 ExceptionBit      = Exception%32;//The exception register bit
	uint8 ExceptionStatus;//a local variable for the exception status
	ExceptionStatus = BIT_VAL(NVIC -> IABR[ExceptionRegister],ExceptionBit);//Read the exception status
	return ExceptionStatus;//return  the exception status
}	
void NVIC_setPriority(NVICExc_t Exception,uint8 priority){
	uint8 ExceptionRegister = Exception/4;//The exception register
	uint8 ExceptionBit      = Exception%4;//The exception register bit
	VAL_SET(NVIC -> IPR[ExceptionRegister],priority,ExceptionBit);//set the exception priority value  
}	
/**********************************************************************************************************************
 *  END OF FILE: NVIC.c
 *********************************************************************************************************************/
 