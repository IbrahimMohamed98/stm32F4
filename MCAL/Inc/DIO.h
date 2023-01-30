/**********************************************************************************************************************

*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*         File:  DIO.h
*       Module:  -Digital input output
*
*  Description:  This file include the following  1-DIO basic types for configure the DIO
*                                                 2-Functions prototypes
*                                                 3-Ready MACROS of the pins configurations   
* 
*  
*********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Libs/stmTypes.h"
#include "../../Libs/Registers.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

//output mode options
#define PIN_OUTPUT_PUSHPULL_LOW_SPEED        OUTPUT,LOW,RESET,NON_INPUT_ATTACH
#define PIN_OUTPUT_OPENDRAIN_LOW_SPEED       OUTPUT,LOW,OPENDRAIN,NON_INPUT_ATTACH
#define PIN_OUTPUT_PUSHPULL_MEDUIM_SPEED     OUTPUT,MEDUIM,RESET,NON_INPUT_ATTACH
#define PIN_OUTPUT_OPENDRAIN_MEDUIM_SPEED    OUTPUT,MEDUIM,OPENDRAIN,NON_INPUT_ATTACH
#define PIN_OUTPUT_PUSHPULL_HIGH_SPEED       OUTPUT,HIGH,RESET,NON_INPUT_ATTACH
#define PIN_OUTPUT_OPENDRAIN_HIGH_SPEED      OUTPUT,HIGH,OPENDRAIN,NON_INPUT_ATTACH
#define PIN_OUTPUT_PUSHPULL_VERYHIGH_SPEED   OUTPUT,VERYHIGH,RESET,NON_INPUT_ATTACH
#define PIN_OUTPUT_OPENDRAIN_VERYHIGH_SPEED  OUTPUT,VERYHIGH,OPENDRAIN,NON_INPUT_ATTACH
//input modes options 
#define PIN_INPUT_PULLUP                     IN,NON_OUT_SPEED,NON_OUT_ATTACH,PULLUP                    
#define PIN_INPUT_PULLDOWN                   IN,NON_OUT_SPEED,NON_OUT_ATTACH,PULLDOWN
//Alternative function options																						 
#define PIN_ATERNATIVE_FUNCTION              AF,NON_OUT_SPEED,NON_OUT_ATTACH,NON_INPUT_ATTACH
//Analog mode option
#define PIN_ANALOG                           ANALOG,NON_OUT_SPEED,NON_OUT_ATTACH,NON_INPUT_ATTACH     
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
//Output level
typedef enum{
	LOW_LEVEL,
	HIGH_LEVEL
}DIOoutType_t;
//Input Attachment type
typedef enum{
	NO,
	PULLUP,
	PULLDOWN,
  NON_INPUT_ATTACH
}DIOPinInType_t;
//Output Attach type
typedef enum{
	RESET,
	OPENDRAIN,
	NON_OUT_ATTACH
}DIOPinOutType_t;
//Output speed type
typedef enum{
	LOW,
	MEDIUM,
	HIGH,
	VERYHIGH,
	NON_OUT_SPEED
}DIOPinSpeed_t;
//Pin mode type
typedef enum{
	INPUT,
	OUTPUT,
	AF,
	ANALOG
}DIOPinMode_t;
//Pins type
typedef enum{
	PIN0, 
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}DIOPin_t;
//Alternative function type
typedef enum{
	AF0, 
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15
}DIOAf_t;
//DIO configuration type
typedef struct{
	volatile GPIO_t * Port;
	DIOPin_t Pin;
	DIOPinMode_t mode;
	DIOPinSpeed_t speed;
	DIOPinOutType_t OutType;
  DIOPinInType_t InType;	
}DIOCnfg_t;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : void                                  
*******************************************************************************/
void DIO_init(DIOCnfg_t *DioCng);
/******************************************************************************
* \Syntax          : void DIO_write(volatile GPIO_t * Port,DIOPin_t Pin,DIOoutType_t PinLevel)        
* \Description     : Writes the pin output to be either HIGH_LEVEL or LOW_LEVEL                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : volatile GPIO_t * Port -> the pin port
*                    DIOPin_t Pin           -> the pin we want to operate on                     
* \Parameters (out): None                                                      
* \Return value:   : void                                  
*******************************************************************************/
void DIO_write(volatile GPIO_t * Port,DIOPin_t Pin,DIOoutType_t PinLevel);
/******************************************************************************
* \Syntax          : void DIO_toggel(volatile GPIO_t * Port,DIOPin_t Pin)        
* \Description     : Toggels a pin                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : volatile GPIO_t * Port -> the pin port
*                    DIOPin_t Pin           -> the pin we want to operate on                     
* \Parameters (out): None                                                      
* \Return value:   : void                                  
*******************************************************************************/
void DIO_toggel(volatile GPIO_t * Port,DIOPin_t Pin);
/******************************************************************************
* \Syntax          : DIOoutType_t DIO_read(volatile GPIO_t * Port,DIOPin_t Pin);        
* \Description     : returns the pin logic level                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : volatile GPIO_t * Port -> the pin port
*                    DIOPin_t Pin           -> the pin we want to operate on          
* \Parameters (out): None                                                      
* \Return value:   : DIOoutType_t                                  
*******************************************************************************/
DIOoutType_t DIO_read(volatile GPIO_t * Port,DIOPin_t Pin);
/******************************************************************************
* \Syntax          : void DIO_selectAF(volatile GPIO_t * Port,DIOPin_t Pin,DIOAf_t Af)        
* \Description     : Selects the pin Alternative function                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : volatile GPIO_t * Port -> the pin port
*                    DIOPin_t Pin           -> the pin we want to operate on
*                    DIOAf_t Af             -> the pin alternative function
* \Parameters (out): None                                                      
* \Return value:   : void                                  
*******************************************************************************/
void DIO_selectAF(volatile GPIO_t * Port,DIOPin_t Pin,DIOAf_t Af);
#endif  /* DIO_H */
/**********************************************************************************************************************
 *  END OF FILE: DIO.h
 *********************************************************************************************************************/

