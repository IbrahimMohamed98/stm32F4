/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Registers.h
 *       Module:  -MCU register 
 *
 *  Description:  This files includes the MCU registers adresses     
 *  
 *********************************************************************************************************************/
#ifndef REGISTERS_H
#define REGISTERS_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 #include "stmTypes.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
//NVIC core prephiral
#define NVIC    ((volatile NVIC_t*)0xE000E100)
	
#define AIRCR  *((volatile uint32*)0xE000ED0C)
//DMA
#define DMA2 ((volatile DMA_t*)0x40026400)
#define DMA1 ((volatile DMA_t*)0x40026000)
//DIO ports	
#define PORTA ((volatile GPIO_t*)0x40020000)
#define PORTB ((volatile GPIO_t*)0x40020400)
#define PORTC ((volatile GPIO_t*)0x40020800)
#define PORTD ((volatile GPIO_t*)0x40020C00)
#define PORTE ((volatile GPIO_t*)0x40021000)
#define PORTH ((volatile GPIO_t*)0x40021C00)
//RCC
#define RCC ((volatile RCC_t*)0x40023800)
//EXTI	
#define EXTI ((volatile EXTI_t*)0x40013C00)
//SYSCFG
#define SYSCFG ((volatile SYSCFG_t*)0x40013800)
//UART
#define UART6 ((volatile UART_t*)0x40011400)
#define UART1 ((volatile UART_t*)0x40011000)
#define UART2 ((volatile UART_t*)0x40004400)
//SPI
#define SPI4  ((volatile SPI_t*)0x40013400)
#define SPI1  ((volatile SPI_t*)0x40013000)
#define SPI3  ((volatile SPI_t*)0x40003C00)
#define SPI2  ((volatile SPI_t*)0x40003800)
//ADC
#define ADC ((volatile ADC_t*)0x40012000)
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
//NVIC register
typedef struct{
	volatile uint32 ISER[8];
	volatile uint32 RESERVED0[24];
	volatile uint32 ICER[8];
	volatile uint32 RESERVED1[24];
	volatile uint32 ISPR[8];
	volatile uint32 RESERVED2[24];
	volatile uint32 ICPR[8];
	volatile uint32 RESERVED3[24];
	volatile uint32 IABR[8];
	volatile uint32 RESERVED4[24];
	volatile uint32 IPR[60];
	volatile uint32 RESERVED5[580];
	volatile uint32 STIR;
}NVIC_t;

//DIO registers
typedef struct{
	volatile uint32 MODER;
	volatile uint32 OTYPER;
	volatile uint32 OSPEEDR;
	volatile uint32 PUPDR;
	volatile uint32 IDR;
	volatile uint32 ODR;
	volatile uint32 BSRR;
	volatile uint32 LCKR;
	volatile uint32 AFR[2];
}GPIO_t;

//RCC registers
typedef struct{
	volatile uint32 CR;
	volatile uint32 PLLCFGR;
	volatile uint32 CFGR;
	volatile uint32 CIR;
	volatile uint32 AHB1RSTR;
	volatile uint32 AHB2RSTR;
	volatile uint32 RESERVED[2];
	volatile uint32 APB1RSTR;
	volatile uint32 APB2RSTR;
	volatile uint32 RESERVED1[2];
	volatile uint32 AHB1ENER;
	volatile uint32 AHB2ENER;
	volatile uint32 RESERVED2[2];
	volatile uint32 APB1ENER;
	volatile uint32 APB2ENER;
	volatile uint32 RESERVED3[2];
	volatile uint32 AHB1LPENR;
	volatile uint32 AHB2LPENR;
	volatile uint32 RESERVED4[2];
	volatile uint32 APB1LPENR;
	volatile uint32 APB2LPENR;
	volatile uint32 RESERVED5[2];
	volatile uint32 BDCR;
	volatile uint32 CSR;
	volatile uint32 RESERVED6[2];
	volatile uint32 SSCGR;
	volatile uint32 PLLI2SCFGR;
	volatile uint32 DCKCFGR;
}RCC_t;
//SYSCFG registers
typedef struct{
	volatile uint32 MEMRMP;
	volatile uint32 PMC;
  volatile uint32 EXTICR[4];
	volatile uint32 CMPCR;
}SYSCFG_t;
//EXTI registers
typedef struct{
	volatile uint32 IMR;
	volatile uint32 EMR;
	volatile uint32 RSTR;
	volatile uint32 FSTR;
	volatile uint32 SWIER;
	volatile uint32 PR;
}EXTI_t;
//UART registers
typedef enum{
	PE,
	FE,
	NF,
	ORE,
	IDLE,
	RXNE,
	TC,
	TXE,
	LBD,
	CTS
}UARTStatus_t;
typedef enum{
	SBK,
	RWU,
	RE,
	TE,
	IDLEIE,
	RXNEIE,
	TCIE,
	TXEIE,
	PEIE,
	PS,
	PCE,
	WAKE,
	M,
	UE,
	OVER8 = 15
}UARTControl1_t;

typedef struct{
	volatile uint32 SR;
	volatile uint32 DR;
	volatile uint32 BRR;
	volatile uint32 CR[3];
	volatile uint32 GPTR;
}UART_t;
//SPI
typedef enum{
	SPI_RXNE,
	SPI_TXE,
	CHSIDE,
	UDR,
	CRCERR,
	MODF,
	OVR,
	BSY,
	FRE
}SPIStatus_t;
typedef enum{
	RXDMAEN,
	TXDMAEN,
	SSOE,
	Res,
	FRF,
	ERRIE,
	SPI_RXNEIE,
	SPI_TXEIE,
}SPIControl2_t;
typedef enum{
	SPI_CPHA,
	SPI_CPOL,
	MSTR,
	BR0,
	BR1,
	BR2,
	SPE,
	LSBFIRST,
	SSI,
	SSM,
	RXONLY,
	DFF,
	CRCNEXT,
	BIDIOE,
	BIDIMODE
}SPIControl1_t;
typedef struct{
	volatile uint32 CR;
	volatile uint32 CR2;
	volatile uint32 SR;
	volatile uint32 DR;
	volatile uint32 CRCPR;
	volatile uint32 RXCRCR;
	volatile uint32 TXCRCR;
	volatile uint32 I2SCFGR;
	volatile uint32 I2SPR;
}SPI_t; 
//DMA
typedef enum{
	EN,
	DMA_DMEIE,
	DMA_TEIE,
	DMA_HTIE,
	DMA_TCIE,
	PFCTRL,
	DIR0,
	DIR1,
	CIRC,
	PINC,
	MINC,
	PSIZE0,
	PSIZE1,
	MSIZE0,
	MSIZE1,
	PINCOS,
	PL0,
	PL1,
	DBM,
	CT,
	PBURST0 = 21,
	PBURST1,
	MBURST0,
	MBURST1,
	CHSEL0,
	CHSEL1,
	CHSEL2
}DMAControl_t;
typedef struct{
	volatile uint32 CR;
	volatile uint32 NDTR;
	volatile uint32 PAR;
	volatile uint32 M0AR;
	volatile uint32 M1AR;
	volatile uint32 FCR;
}DMAstream_t;

typedef struct{
	volatile uint32 LISR;
	volatile uint32 HISR;
	volatile uint32 LIFCR;
	volatile uint32 HIFCR;
	DMAstream_t Stream[8];
}DMA_t;

typedef enum{
	FEIF4,
 DMEIF4 = 2,
	TEIF4,
	HTIF4,
	TCIF4,
	FEIF5,
 DMEIF5 = 8,
	TEIF5,
	HTIF5,
	TCIF5,
	FEIF6 = 16,
 DMEIF6 = 18,
	TEIF6,
	HTIF6,
	TCIF6,
	FEIF7,
 DMEIF7 = 24,
	TEIF7,
	HTIF7,
	TCIF7
}DMAHighInterrupt_t;
typedef enum{
	FEIF0,
	DMEIF0 = 2,
	TEIF0,
	HTIF0,
	TCIF0,
	FEIF1,
 DMEIF1 = 8,
	TEIF1,
	HTIF1,
	TCIF1,
	FEIF2 = 16,
 DMEIF2 = 18,
	TEIF2,
	HTIF2,
	TCIF2,
	FEIF3,
 DMEIF3 = 24,
	TEIF3,
	HTIF3,
	TCIF3
}DMALowInterrupt_t;

//ADC
typedef enum{
	AWDH0,
	AWDH1,
	AWDH2,
	AWDH3,
	AWDH4,
	EOCIE,
  AWDIE,
	JEOCIE,
	SCAN,
	AWDSGL,
	JAUTO,
	DISCEN,
	JDISCEN,
	DISCNUM0,
	DISCNUM1,
	DISCNUM2,
	JAWDEN = 22,
	AWDEN,
	RES0,
	RES1,
	OVRIE
}ADCControl1_t;
typedef struct{
	volatile uint32 SR;
	volatile uint32 CR[2];
  volatile uint32 SMPR[2];
	volatile uint32 JOFR[4];
	volatile uint32 HTR;
	volatile uint32 LTR;
	volatile uint32 SQR[3];
	volatile uint32 JSQR;
	volatile uint32 JSDR[4];
	volatile uint32 DR;
	volatile uint32 CCR;
}ADC_t;
#endif  /* REGISTERS_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
 
