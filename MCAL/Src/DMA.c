/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DMA.c
*        \brief  This file includes the impelemntation of the DMA functions
*
*      \details  This file includes the function that Deliver -Initiation of a DMA transfer
*
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../../Libs/BitMath.h"
#include "../../Libs/stmTypes.h"
#include "../../Libs/Registers.h"

#include "../Inc/DMA.h"

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
void DMA_transferCnfg(DMATransCnfg_t* cnfg){
	DMA_SLCT_CHANNEL(cnfg->DMA,cnfg->stream,cnfg->channel);//select the channel
	DMA_SLCT_DIRECTION(cnfg->DMA,cnfg->stream,cnfg->direction);//select the transfer direction
	DMA_SLCT_PRIORITY(cnfg->DMA,cnfg->stream,cnfg->priority);//select the transfer priority
	DMA_SLCT_PREPH_SIZE(cnfg->DMA,cnfg->stream,cnfg->pMemsize);//adjust the prephiral size
	DMA_SLCT_MEM_SIZE(cnfg->DMA,cnfg->stream,cnfg->mMemsize);//adjust the memory size
	
	if(cnfg -> mAddressGrowth == DMA_ADD_FIXED){//check for the memory address growth
		DMA_MEM_ADD_FIXED(cnfg->DMA,cnfg->stream);//choose the memory address to be fixed 
	}else{
		DMA_MEM_ADD_INC(cnfg->DMA,cnfg->stream);//choose the memory address to be increment
	}
	
	if(cnfg -> pAddressGrowth == DMA_ADD_FIXED){//check for the prephiral address growth
		DMA_PREPH_ADD_FIXED(cnfg->DMA,cnfg->stream);//choose the prephiral address to be fixed
	}else{
		DMA_PREPH_ADD_INC(cnfg->DMA,cnfg->stream);//choose the prephiral address to be increment
	}
	
	cnfg->DMA->Stream[(cnfg->stream)].NDTR = cnfg->numOfTrans;//adjust the number of tranfers
	cnfg->DMA->Stream[(cnfg->stream)].PAR  = (uint32)cnfg->prephAddr;//adjust the prephieral address
	cnfg->DMA->Stream[(cnfg->stream)].M0AR = (uint32)cnfg->mem0Addr;//adjust the memory0 buffer address
	cnfg->DMA->Stream[(cnfg->stream)].M1AR = (uint32)cnfg->mem1Addr;//adjust the memory1 buffer address
	
}
/**********************************************************************************************************************
 *  END OF FILE: DMA.c
 *********************************************************************************************************************/
 