/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        \brief  Include the impelentation of the DIO functions
 *
 *      \details  This file deliver the folowing functionality -DIO pins initiation
 *                                                             -DIO write logic operations
 *                                                             -DIO toggel
 *                                                             -DIO read operation
 *                                                             -DIO alternative function selection
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../../Libs/BitMath.h"
#include "../../Libs/stmTypes.h"
#include "../../Libs/Registers.h"

#include "../Inc/DIO.h"

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


void DIO_init(DIOCnfg_t *DioCng){
		if(DioCng -> mode == OUTPUT){//check for output mode 
			DioCng -> Port -> MODER &= ~(0x3<<((DioCng ->Pin)*2));//clear the mode bits
			VAL_SET(DioCng ->Port -> MODER,OUTPUT,((DioCng ->Pin)*2));//setting the mode
			DioCng ->Port -> OSPEEDR &= ~(0x3<<((DioCng ->Pin)*2));//clear the speed bits
      VAL_SET(DioCng ->Port -> OSPEEDR,DioCng ->speed,((DioCng ->Pin)*2));//set the speed 
		  BIT_CLR(DioCng ->Port -> OTYPER,((DioCng ->Pin)*2));//clear the output type bits
			VAL_SET(DioCng ->Port -> OTYPER,DioCng ->OutType,((DioCng ->Pin)*2));//set the output type 			
		}else if(DioCng -> mode == INPUT){//check for input mode
			DioCng -> Port -> MODER &= ~(0x3<<((DioCng ->Pin)*2));//clear the mode bits
			VAL_SET(DioCng -> Port -> MODER,INPUT,((DioCng ->Pin)*2));//setting the mode
			DioCng ->Port -> PUPDR &= ~(0x3<<((DioCng ->Pin)*2));//clear the attachment type bits
			VAL_SET((DioCng -> Port) -> PUPDR,DioCng ->InType,((DioCng ->Pin)*2));//sets the attachment type
		}else {
			DioCng -> Port -> MODER &= ~(0x3<<((DioCng ->Pin)*2));//clear the mode bits
			VAL_SET(DioCng -> Port -> MODER,DioCng -> mode,((DioCng ->Pin)*2));//setting the mode
		}
}

void DIO_write(volatile GPIO_t * Port,DIOPin_t Pin,DIOoutType_t PinLevel){
	if(PinLevel == HIGH_LEVEL){//check for the level
		BIT_SET(Port -> ODR,Pin);//Write High to the pin
	}else{
		BIT_CLR(Port  -> ODR,Pin);//Write low to the pin
	}
}

void DIO_toggel(volatile GPIO_t * Port,DIOPin_t Pin){
	BIT_TGL(Port -> ODR, Pin);//toggel the Pin
}

DIOoutType_t DIO_read(volatile GPIO_t * Port,DIOPin_t Pin){
	DIOoutType_t Input_Level = BIT_VAL(Port->IDR,Pin);
	return Input_Level;
}

void DIO_selectAF(volatile GPIO_t * Port,DIOPin_t Pin,DIOAf_t Af){
	uint32 reg = Pin/8;//get the pin register
	uint32 bit = Pin%8;//get the pin place in the register
	Port->AFR[reg] &= ~(0xF<<(bit*4));//clear the AFx bits
	Port->AFR[reg] |= (Af<<(bit*4));//Set the AFx  for the pin
}
