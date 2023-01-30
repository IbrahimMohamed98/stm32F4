/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  RCC.c
*        \brief   This file includes the impelemntation of the RCC functions 
*
*      \details This file includes the function that Deliver -Initiation of System Clock
*                                                            -Prephiral Clock Enable and Disable
*
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../../Libs/BitMath.h"
#include "../../Libs/stmTypes.h"
#include "../../Libs/Registers.h"

#include "../Inc/RCC.h"
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
void RCC_initSystemClock(RCCClkSrc_t ClkSrc){
	if(ClkSrc == HSI){
	  RCC -> CFGR = 0x00000000;//choose the Clock source
		RCC -> CR   = (HSI_TRIM_VALUE << 3);//Adjust trimming value
    RCC -> CR  |= (1<<0);	//Enable the HSI clock	
	}else if(ClkSrc == HSE_CRYSTAL){
		RCC -> CFGR = (1 << 0);//choose the Clock source
    RCC -> CR   = (5 << 16);//Enable the HSE with crystal oscillator
	}else if(ClkSrc == HSE_RC){
		RCC -> CFGR = (1 << 0);//choose the Clock source
    RCC -> CR   = (1 << 16);//Enable the HSE with RC Circuit
	}else if(ClkSrc == PLL_HSE){
		RCC -> CFGR = (2 << 0);//choose the Clock source
		RCC ->PLLCFGR  = (1<<22);//Choose HSE as the PLL source
		RCC ->PLLCFGR |= (PLL_CLOCK_M_FACTOR << 0);//Adjust the M factor
		RCC ->PLLCFGR |= (PLL_CLOCK_N_FACTOR << 6);//Adjust the N factor
		RCC ->PLLCFGR |= (PLL_CLOCK_P_FACTOR << 16);//Adjust the P factor
		RCC -> CR      = (1<<24);//Enable the PLL
	}else if(ClkSrc == PLL_HSI){
		RCC -> CFGR    = (2 << 0);//choose the Clock source
		RCC ->PLLCFGR  = 0;//Choose HSI as the PLL source
		RCC ->PLLCFGR |= (PLL_CLOCK_M_FACTOR << 0);//Adjust the M factor
		RCC ->PLLCFGR |= (PLL_CLOCK_N_FACTOR << 6);//Adjust the N factor
		RCC ->PLLCFGR |= (PLL_CLOCK_P_FACTOR << 16);//Adjust the P factor
		RCC -> CR      = (1<<24);//Enable the PLL
	}else{
	}
}


void RCC_prephiralEnableClock(RCCBuses_t Bus,uint8 prepheralNum){
	if(prepheralNum < 31){
		switch(Bus){
			case AHB1:
								BIT_SET(RCC -> AHB1ENER,prepheralNum);
								break;
			case AHB2:
								BIT_SET(RCC -> AHB2ENER,prepheralNum);
								break;
			case APB1:
								BIT_SET(RCC -> APB1ENER,prepheralNum);
								break;
			case APB2:
								BIT_SET(RCC -> APB2ENER,prepheralNum);
								break;
			default:break;
		}
	}
}

void RCC_prephiralDisableClock(RCCBuses_t Bus,uint8 prepheralNum){
	if(prepheralNum < 31){
		switch(Bus){
			case AHB1:
								BIT_SET(RCC -> AHB1RSTR,prepheralNum);
								break;
			case AHB2:
								BIT_SET(RCC -> AHB2RSTR,prepheralNum);
								break;
			case APB1:
								BIT_SET(RCC -> APB1RSTR,prepheralNum);
								break;
			case APB2:
								BIT_SET(RCC -> APB2RSTR,prepheralNum);
								break;
			default:break;
		}
	}
}

/**********************************************************************************************************************
 *  END OF FILE: RCC.c
 *********************************************************************************************************************/


