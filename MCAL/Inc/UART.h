/**********************************************************************************************************************
*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*         File:  UART.h
*       Module:  - Universal asynchronous receiver
*
*  Description:  Header file contians the 1- UART data types
*                                         2- UART function prototypes
*                                         3- UART MACRO like functions for designing functions for UART
*
*********************************************************************************************************************/
#ifndef UART_H
#define UART_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include <math.h>
#include "../../Libs/BitMath.h"
#include "../../Libs/stmTypes.h"
#include "../../Libs/Registers.h"



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef F_CPU
	#define F_CPU 16000000
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
//Enable the UART
#define UART_ENABLE(UART)                  BIT_SET(UART->CR[0],UE)
//Selects the UART mode 
#define UART_SELECT_MODE(UART,MODE)        VAL_SET(UART->CR[0],MODE,RE)
//Waits for Any Interrupt of Type UARTStatus_t
#define UART_WAIT_INTERRUPT(UART,INTPIN)   while(!BIT_VAL(UART->SR,INTPIN))
//Enable UART  DMAT	
#define UART_ENABLE_TRANSMIT_DMA(UART)     BIT_SET(UART->CR[2],7)
//Enable UART  DMAR
#define UART_ENABLE_RECEIVE_DMA(UART)      BIT_SET(UART->CR[2],6)
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
//Word length type
typedef enum{
	UART_8BIT_WORD,
	UART_9BIT_WORD
}UARTWordLength_t;
//UART mode type
typedef enum{
	UART_RECEIVER = 1,
	UART_TRANSMITTER,
	UART_HALF_DUPLEX
}UARTMode_t;
//Sampling Type
typedef enum{
	UART_NOT_OVER_SAMPLE,
	UART_OVER_SAMPLE
}UARTOverSmaple_t;
//UART configuration type
typedef struct{
	volatile UART_t* UART;
	UARTMode_t  mode;
	uint32 baudRate;
	UARTWordLength_t Wlength;
	UARTOverSmaple_t overSmpl;
}UARTCnfg_t;
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void UART_init(UARTCnfg_t *Cnfg)        
* \Description     : Initiate the UART to certian configuration                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : UARTCnfg_t *Cnfg -> The configuration for uart initiation                     
* \Parameters (out): None                                                      
* \Return value:   : void                                  
*******************************************************************************/
void UART_init(UARTCnfg_t *Cnfg);
/******************************************************************************
* \Syntax          : void UART_send(volatile UART_t *UART,uint8*msg,uint32 size)        
* \Description     : Sends a message over UART                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : volatile UART_t *UART -> The UART to use either UART1,2,6
*                    uint8*msg             -> The message we want to send
*                    uint32 size           -> The sent message Buffer size
* \Parameters (out): None                                                      
* \Return value:   : void                                  
*******************************************************************************/
void UART_send(volatile UART_t *UART,uint8*msg,uint32 size);
/******************************************************************************
* \Syntax          : void UART_recieve(volatile UART_t *UART,uint8 *msgBuffer,uint32 size)        
* \Description     : Recieve a message over UART                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : volatile UART_t *UART -> The UART to use either UART1,2,6
*                    uint8*msg             -> The message buffer for data reception
*                    uint32 size           -> The recieved message Buffer size                     
* \Parameters (out): None                                                      
* \Return value:   : void                                  
*******************************************************************************/
void UART_recieve(volatile UART_t *UART,uint8 *msgBuffer,uint32 size);
/******************************************************************************
* \Syntax          : void UART_setReceiveCallBack(CallBack_t (*callBackISR)(void))        
* \Description     : Set the UART send CallBack function                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : CallBack_t (*callBackISR)(void) -> UART send ISR call Back function                     
* \Parameters (out): None                                                      
* \Return value:   : void                                  
*******************************************************************************/
void UART_setReceiveCallBack(CallBack_t (*callBackISR)(void));
/******************************************************************************
* \Syntax          : void UART_setSendCallBack(CallBack_t (*callBackISR)(void))       
* \Description     : Set the UART receive CallBack function                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : CallBack_t (*callBackISR)(void) -> UART recieve ISR call Back function                     
* \Parameters (out): None                                                      
* \Return value:   : void                                  
*******************************************************************************/
void UART_setSendCallBack(CallBack_t (*callBackISR)(void));
#endif  /* UART_H */

/**********************************************************************************************************************
 *  END OF FILE: UART.h
 *********************************************************************************************************************/
