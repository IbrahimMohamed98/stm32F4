/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SPI.H
 *       Module:  -Nested vector Interrupt control
 *
 *  Description:  Header file include the followin 1-SPI basic data types needed for configurations
 *                                                 2-SPI send/receive functions prototypes
 *                                                 3-MACRO like functions for designing functions for the SPI  
 *  
 *********************************************************************************************************************/
#ifndef SPI_H
#define SPI_H

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
//Enable/Disable the SPI by SPE bit 
#define SPI_ENABLE(SPI)                       BIT_SET(SPI->CR,SPE)
#define SPI_DISABLE(SPI)                      BIT_CLR(SPI->CR,SPE)
//Writing the BUADRATE in Br[0:3]
#define SPI_SPI_SET_BAUD_RATE(SPI,BAUDRATE)   VAL_SET(SPI->CR,BAUDRATE,BR0)
//Choose SPI mode by MSTR bit
#define SPI_SET_MASTER(SPI)                   BIT_SET(SPI->CR,MSTR) 
#define SPI_SET_SLAVE(SPI)                    BIT_CLR(SPI->CR,MSTR)
//Choose SPI Data order By LSBFIRST bit
#define SPI_LSB_DATA_ORDER(SPI)               BIT_CLR(SPI->CR,LSBFIRST)
#define SPI_MSB_DATA_ORDER(SPI)               BIT_SET(SPI->CR,LSBFIRST)
//Enable and Disable Transferring to SPI by SSI
#define SPI_SLCT_SLAVE_SOFT(SPI)              BIT_CLR(SPI->CR,SSI)
#define SPI_UN_SLCT_SLAVE_SOFT(SPI)           BIT_SET(SPI->CR,SSI)
//Slave select Method by GPIO PIN 
#define SPI_SLCT_SLAVE_HARD(PORT,SLVPIN)         BIT_SET(PORT->BSRR,(SLVPIN+16))
#define SPI_UN_SLCT_SLAVE_HARD(PORT,SLVPIN)      BIT_SET(PORT->BSRR,SLVPIN)
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 //SPI slave select type
typedef enum{
	SPI_HARD_SLAVE_SLCT,
	SPI_SOFT_SLAVE_SLCT,
	SPI_NON_SLCT
}SPISlaveSelect_t;
//SPI clk source type
typedef enum{
	SPI_CLK_DIV2,
	SPI_CLK_DIV4,
	SPI_CLK_DIV8,
	SPI_CLK_DIV16,
	SPI_CLK_DIV64,
	SPI_CLK_DIV128,
	SPI_CLK_DIV256
}SPIBaudRate_t;
//SPI MODE type
typedef enum{
	SPI_SLAVE,
	SPI_MASTER
}SPIMode_t;
//SPI Data alignment type
typedef enum{
	SPI_LSB,
	SPI_MSB,
}SPIDataOrder_t;
//UART configuration type
typedef struct{
	volatile SPI_t* SPI;
	SPIMode_t mode;
	SPIDataOrder_t dataOrder;
	SPIBaudRate_t BaudRate;
	SPISlaveSelect_t slaveSlct;
}SPICnfg_t;
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void NVIC_init(NVICPriorityGrouping_t PriorityGrouping)        
* \Description     : Initiate the NVIC and set the priority grouping                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : SPICnfg_t *cnfg -> the configuration to init spi on                     
* \Parameters (out): None                                                     
* \Return value:   : None
*******************************************************************************/
void SPI_init(SPICnfg_t *cnfg);
/******************************************************************************
* \Syntax          : void NVIC_init(NVICPriorityGrouping_t PriorityGrouping)        
* \Description     : sends data over spi                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : volatile SPI_t* SPI -> The spi to receive data
*                    uint8*msg -> the message buffer
*										 uint16 size -> the message size                   
* \Parameters (out): None                                                     
* \Return value:   : None
*******************************************************************************/
void SPI_send(volatile SPI_t* SPI,uint8*msg,uint16 size);
/******************************************************************************
* \Syntax          : void SPI_receive(volatile SPI_t* SPI,uint8*msg,uint16 size)        
* \Description     : receive data over spi                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : volatile SPI_t* SPI -> The spi to receive data
*                    uint8*msg -> the message buffer
*										 uint16 size -> the message size                     
* \Parameters (out): None                                                     
* \Return value:   : None
*******************************************************************************/
void SPI_receive(volatile SPI_t* SPI,uint8*msg,uint16 size);
 
#endif  /* SPI_H */

/**********************************************************************************************************************
 *  END OF FILE: SPI.h
 *********************************************************************************************************************/
 