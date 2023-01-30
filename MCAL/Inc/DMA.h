/**********************************************************************************************************************

*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*         File:  DMA.h
*       Module:  -Direct memory access
*
*  Description:  Header file contians the 1- DMA data types
*                                         2- DMA function prototypes
*                                         3- DMA MACRO like functions for designing functions for DMA    
*  
 *********************************************************************************************************************/
#ifndef DMA_H
#define DMA_H

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
//Selecting the DMA channel
#define DMA_SLCT_CHANNEL(DMA,STREAM,CHANNEL)    DMA->Stream[STREAM].CR = (DMA->Stream[STREAM].CR&0xF1FFFFFF)|(CHANNEL<<CHSEL0)
//Selecting the DMA prephiral and memory data size
#define DMA_SLCT_PREPH_SIZE(DMA,STREAM,SIZE)    DMA->Stream[STREAM].CR = (DMA->Stream[STREAM].CR&0xFFFFE7FF)|(SIZE<<PSIZE0)
#define DMA_SLCT_MEM_SIZE(DMA,STREAM,SIZE)      DMA->Stream[STREAM].CR = (DMA->Stream[STREAM].CR&0xFFFF9FFF)|(SIZE<<MSIZE0)
//Selecting the DMA priority
#define DMA_SLCT_PRIORITY(DMA,STREAM,PRIORITY)  DMA->Stream[STREAM].CR = (DMA->Stream[STREAM].CR&0xFFFCFFFF)|(PRIORITY<<PL0)
//Selecting the DMA direction
#define DMA_SLCT_DIRECTION(DMA,STREAM,DIR)      DMA->Stream[STREAM].CR = (DMA->Stream[STREAM].CR&0xFFFFFF3F)|(DIR<<DIR0)
//Choose the prephiral Aaddress growth
#define DMA_PREPH_ADD_INC(DMA,STREAM)           BIT_SET(DMA->Stream[STREAM].CR,PINC)
#define DMA_PREPH_ADD_FIXED(DMA,STREAM)         BIT_CLR(DMA->Stream[STREAM].CR,PINC)
//Choose the memory Adress growth
#define DMA_MEM_ADD_INC(DMA,STREAM)             BIT_SET(DMA->Stream[STREAM].CR,MINC)
#define DMA_MEM_ADD_FIXED(DMA,STREAM)           BIT_CLR(DMA->Stream[STREAM].CR,MINC)
//Make the dma control the flow
#define DMA_CTRL_FLOW(DMA,STREAM)               BIT_CLR(DMA->Stream[STREAM].CR,PFCTRL)
//Make the prephiral control the flow
#define DMA_PREPH_CTRL_FLOW(DMA,STREAM)         BIT_SET(DMA->Stream[STREAM].CR,PFCTRL)
//Enable and Disable the interrupt
#define DMA_ENABLE(DMA,STREAM)                  BIT_SET(DMA->Stream[STREAM].CR,EN)
#define DMA_DISABLE(DMA,STREAM)                 BIT_CLR(DMA->Stream[STREAM].CR,EN)
//Waits for the interrupts
#define DMA_WAIT_LOW_INTERRUPT(DMA,INTPIN)       while(!BIT_VAL(DMA->LISR,INTPIN))
#define DMA_WAIT_HIGH_INTERRUPT(DMA,INTPIN)      while(!BIT_VAL(DMA->HISR,INTPIN))
//Clears specific interrpts
#define DMA_CLEAR_LOW_INTERRUPT(DMA,INTPIN)     BIT_SET(DMA->LIFCR,INTPIN)
#define DMA_CLEAR_HIGH_INTERRUPT(DMA,INTPIN)    BIT_SET(DMA->HIFCR,INTPIN)
//Clears all stream interrupts
#define DMA_CLEAR_INTERRUPT_STEAM0(DMA)        DMA->LIFCR = 0x0000003D
#define DMA_CLEAR_INTERRUPT_STEAM1(DMA)        DMA->LIFCR = 0x00000F40 
#define DMA_CLEAR_INTERRUPT_STEAM2(DMA)        DMA->LIFCR = 0x003D0000 
#define DMA_CLEAR_INTERRUPT_STEAM3(DMA)        DMA->LIFCR = 0x0F400000
#define DMA_CLEAR_INTERRUPT_STEAM4(DMA)        DMA->HIFCR = 0x0000003D 
#define DMA_CLEAR_INTERRUPT_STEAM5(DMA)        DMA->HIFCR = 0x00000F40 
#define DMA_CLEAR_INTERRUPT_STEAM6(DMA)        DMA->HIFCR = 0x003D0000 
#define DMA_CLEAR_INTERRUPT_STEAM7(DMA)        DMA->HIFCR = 0x0F400000

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


typedef enum{
	DMA_FLOW_CONTROLLER,
	DMA_PREPHRAL_FLOW_CONTROLLER
}DMAFlowControl;

typedef enum{
	DMA_ADD_FIXED,
	DMA_ADD_INC
}DMAAddGrowth_t;

typedef enum{
	DMA_MEM_SIZE_BYTE,
	DMA_MEM_SIZE_HALFWORD,
	DMA_MEM_SIZE_WORD
}DMAMemSize_t;

typedef enum{
	DMA_LOW_PRIORITY,
	DMA_MEDUIM_PRIORITY,
	DMA_HIGH_PRIORITY,
	DMA_VERY_HIGH_PRIORITY
}DMAPriority_t;

typedef enum{
	DMA_CHANNEL0,
	DMA_CHANNEL1,
	DMA_CHANNEL2,
	DMA_CHANNEL3,
	DMA_CHANNEL4,
	DMA_CHANNEL5,
	DMA_CHANNEL6,
	DMA_CHANNEL7
}DMAChannel_t;
typedef enum{
	DMA_STREAM0,
	DMA_STREAM1,
	DMA_STREAM2,
	DMA_STREAM3,
	DMA_STREAM4,
	DMA_STREAM5,
	DMA_STREAM6,
	DMA_STREAM7
}DMAStreamNum_t;

typedef enum{
	DMA_PREPH_TO_MEM,
	DMA_MEM_TO_PREPH,
	DMA_MEM_TO_MEM
}DMATransDir_t;

typedef struct{
	volatile DMA_t* DMA;
  DMAStreamNum_t stream;
  DMAChannel_t channel;
  DMATransDir_t direction;
	DMAPriority_t priority;
	DMAMemSize_t pMemsize;
  DMAMemSize_t mMemsize;
  DMAAddGrowth_t pAddressGrowth;
  DMAAddGrowth_t mAddressGrowth;	
	uint16 numOfTrans;
	uint32* prephAddr;
	uint32* mem0Addr;
	uint32* mem1Addr;
}DMATransCnfg_t;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void DMA_transferCnfg(DMATransCnfg_t* cnf)        
* \Description     : sets the transfer configurations                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : DMATransCnfg_t* cnf -> the DMA transfer configurations                     
* \Parameters (out): None                                                      
* \Return value:   : void                                 
*******************************************************************************/
void DMA_transferCnfg(DMATransCnfg_t* cnf);
 
#endif  /* DMA_H */

/**********************************************************************************************************************
 *  END OF FILE: DMA.h
 *********************************************************************************************************************/
