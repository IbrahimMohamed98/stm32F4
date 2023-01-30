/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  EXTI.h
 *       Module:  -External interrupt/event controller
 *
 *  Description:  Header file contians the 1- EXTI data types
*                                          2- EXTI function prototypes
*                                          3- EXTI MACRO like functions for designing functions for UART     
 *  
 *********************************************************************************************************************/
#ifndef EXTI_H
#define EXTI_H

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
//Enable an EXTI Line
#define EXTI_ENABLE(line)  BIT_SET(EXTI -> IMR,line)
//Select the EXTI port
#define EXTI_SLECT_PORT(line,port){uint8 reg = line/4;\
	                                 uint8 bit = line%4;\
	                                 SYSCFG ->EXTICR[reg] &= ~(0xF<<(bit<<4));\
	                                 VAL_SET(SYSCFG ->EXTICR[reg],port,line);}
//Selecting the Interrupt trigger source
#define EXTI_SELECT_TRIGER(line,triger) switch(triger){\
																												case EXTI_RISING:\
																													BIT_SET(EXTI -> RSTR,line);\
																													break;\
																												case EXTI_FALLING:\
																													BIT_SET(EXTI -> FSTR,line);\
																													break;\
																												case EXTI_ON_CHANGE:\
																													BIT_SET(EXTI -> RSTR,line);\
																													BIT_SET(EXTI -> FSTR,line);\
																													break;\
																												default:break;\
																											}


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


typedef enum{
	EXTI_PORTA,
	EXTI_PORTB,
	EXTI_PORTC,
	EXTI_PORTD,
	EXTI_PORTE,
	EXTI_PORTH = 7
}EXTIPort_t;

typedef enum{
	EXTI_RISING,
	EXTI_FALLING,
	EXTI_ON_CHANGE
}EXTITriger_t;

typedef enum{
	EXTI_LINE0, 
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,
	EXTI_LINE6,
	EXTI_LINE7,
	EXTI_LINE8,
	EXTI_LINE9,
	EXTI_LINE10,
	EXTI_LINE11,
	EXTI_LINE12,
	EXTI_LINE13,
	EXTI_LINE14,
	EXTI_LINE15
}EXTILine_t;
typedef struct{
	EXTIPort_t port;//The EXTI PORT
	EXTILine_t line;//The EXTI LINE
	EXTITriger_t triger;//The trigger source of the EXTI
}EXTICnfg_t;
 

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void EXTI_init(EXTICnfg_t *Cnfg);        
* \Description     : Init EXTI Line according to certian configuration                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : EXTICnfg_t *Cnfg -> the configuration for EXTI (Port,line,Trigger source)                     
* \Parameters (out): None                                                      
* \Return value:   : void                                  
*******************************************************************************/
void EXTI_init(EXTICnfg_t *Cnfg);
/******************************************************************************
* \Syntax          : void EXTI_disableLine(EXTILine_t line);        
* \Description     : Disable an EXTI line                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : void                                 
*******************************************************************************/
void EXTI_disableLine(EXTILine_t line);
/******************************************************************************
* \Syntax          : void EXTI_setPinding(EXTILine_t line);        
* \Description     : Set the pending flag for an EXTI Line                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : void                              
*******************************************************************************/
void EXTI_setPinding(EXTILine_t line); 
#endif  /* EXTI_H */

/**********************************************************************************************************************
 *  END OF FILE: EXTI.h
 *********************************************************************************************************************/