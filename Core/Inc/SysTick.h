/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SysTick.h
 *       Module:  -SysTick timer
 *
 *  Description:  Header file for the SysTick includes the SysTick -Basic types
 *                                                                 -Prototypes
 *                                                                 -Macros																																	   
 *********************************************************************************************************************/
#ifndef SYSTICK_H
#define SYSTICK_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Libs/BitMath.h"
#include "../../Libs/stmTypes.h"
#include "../../Libs/Registers.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#ifndef F_SYSTICK
  #define F_SYSTICK                 16000000UL
#endif

#define SysTick ((volatile SysTick_t *)0xE000E010)
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define SYSTICK_ENABLE_INTERRUPT()   BIT_SET(SysTick->CTRL,TICKINT)
#define SYSTICK_DISABLE_INTERRUPT()  BIT_CLR(SysTick->CTRL,TICKINT)

#define SYSTICK_ENABLE()             BIT_SET(SysTick->CTRL,ENABLE)
#define SYSTICK_DISABLE()            BIT_CLR(SysTick->CTRL,ENABLE)

#define SYSTICK_USE_DIV_CLKSRC()         BIT_CLR(SysTick->CTRL,CLKSOURCE)
#define SYSTICK_USE_CLKSRC()             BIT_SET(SysTick->CTRL,CLKSOURCE)

#define SYSTICK_WAIT_COUNT_END()         while(!BIT_VAL(SysTick->CTRL,COUNTFLAG))
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


typedef enum{
	CLKSRC_AHB_DIV_8,
	CLKSRC_AHB
}SysTickClksrc_t;

typedef enum{
	SYSTICK_INT_DISABLE,
	SYSTICK_INT_ENABLE
}SysTickInterruptEnable_t;

typedef enum{
	s,
  Ms = 1000,
  Us = 1000000	
}SysTickDelayUnit_t;

typedef enum{
	ENABLE,
	TICKINT,
	CLKSOURCE,
	COUNTFLAG = 16
}SysTickControl_t;
typedef struct{
	SysTickClksrc_t clkSrc;
	SysTickInterruptEnable_t InterruptEnable;
}SysTickCnfg_t;
typedef struct{
	volatile uint32 CTRL;
	volatile uint32 LOAD;
	volatile uint32 VAL;
	volatile uint32 CALIB;
}SysTick_t;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void SysTick_init(SysTickCnfg_t *cnfg);
void SysTick_delayMs(uint32 period);
void SysTick_setCallBack(CallBack_t (*CallBack)(void)); 
#endif  /* SYSTICK_H */

/**********************************************************************************************************************
 *  END OF FILE: SysTick.h
 *********************************************************************************************************************/
 