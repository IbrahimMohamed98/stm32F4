/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  UART.c
*        \brief  This file includes the impelemntation of the UART functions  
*
*      \details  This file includes the function that Deliver -Initiation of UART
*                                                             -UART send
*                                                             -UART receive
*                                                             -ISR's functions set
*
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <math.h>
#include "../../Libs/BitMath.h"
#include "../../Libs/stmTypes.h"
#include "../../Libs/Registers.h"

#include "../Inc/UART.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
CallBack_t (*UART_receiveCallBack)(void) = (void*)0;
CallBack_t (*UART_sendCallBack)(void)    = (void*)0;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
 
void UART_init(UARTCnfg_t *Cnfg){
	//select the mode
	UART_SELECT_MODE(Cnfg -> UART,Cnfg ->mode);
	//Setting the UART word length
	if(Cnfg->Wlength == UART_8BIT_WORD){
		BIT_CLR(Cnfg -> UART -> CR[0],M);//Set the UART 9bits word length
	}else{
		BIT_SET(Cnfg -> UART -> CR[0],M);//Set the UART 8bits word length
	}
	//set the over sample
	if(Cnfg -> overSmpl == UART_OVER_SAMPLE){
		BIT_SET(Cnfg -> UART -> CR[0],OVER8);//Enable overSampling
  }else{
		BIT_CLR(Cnfg -> UART -> CR[0],OVER8);//Disable overSampling
	}
	//Setting the UART BAUDRATE length
	uint64 baud      = ((double)F_CPU/(Cnfg->baudRate * 8 * (2 - Cnfg->overSmpl)));
	uint32 Maintessa = (uint32)baud;//Caculate the Maintessa
	uint8 Fraction  =  ceil((baud - Maintessa)*16);//Calculate the fraction
	Cnfg->UART->BRR  = Fraction;//setting the Fraction
	VAL_SET(Cnfg->UART->BRR,Maintessa,4);//setting the Maintessa
	UART_ENABLE(Cnfg -> UART);//Enable the UART
	
}

void UART_send(volatile UART_t *UART,uint8*msg,uint32 size){
	for(int i = 0;i<size;i++){//Loop over the message size
		UART -> DR = msg[i];//load the msg[i] into the data register
		UART_WAIT_INTERRUPT(UART,TC);//wait untill transfer complete
	}
}

void UART_recieve(volatile UART_t *UART,uint8 *msgBuffer,uint32 size){
	for(int i = 0;i<size;i++){//Loop over the message the size
		UART_WAIT_INTERRUPT(UART,RXNE);//wait untill receive complete
		msgBuffer[i] = UART -> DR;//Load the data register value into the message buffer
	}
}

void UART_setReceiveCallBack(CallBack_t (*callBackISR)(void)){
	UART_receiveCallBack = callBackISR;//set the Receive ISR
}

void UART_setSendCallBack(CallBack_t (*callBackISR)(void)){
	UART_sendCallBack = callBackISR;//set the Send ISR
}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
 