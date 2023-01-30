/******************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------*/
/**         \file   BitMath.h
 *         \brief   Macros used for Bit Manipulation.
 *         
 *       \details   -
 *****************************************************************************/


#ifndef BITMATH_H_
#define BITMATH_H_


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define BIT_SET(REG,PIN)   (REG |=  (1<<PIN)) //Set the pin to one.  
#define BIT_CLR(REG,PIN)   (REG &= ~(1<<PIN)) //Clear the pin.
#define BIT_TGL(REG,PIN)   (REG ^=  (1<<PIN)) //Toggle the pin.
#define BIT_VAL(REG,PIN)   ((REG>>PIN)&1)   //Read the bin if it is high or low

#define VAL_SET(REG,VAL,STARTPIN)   (REG  |=  (VAL<<STARTPIN))   //Set a value in a specific place in the Register.
#define VAL_CLR(REG,VAL,STARTPIN)   (REG  &= ~(VAL<<STARTPIN))    //Clear a value in a specific place in the Register.




#endif /* BITMATH_H_ */
/**********************************************************************************************************************
 *  END OF FILE: BitMath.h
 *********************************************************************************************************************/
