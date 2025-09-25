/*
 * stm32l476xx.h
 *
 *  Created on: Sep 19, 2025
 *      Author: Admin
 */

#ifndef INC_STM32L476XX_H_
#define INC_STM32L476XX_H_

#include <stdint.h>
/************************************************* END OF INCLUDE FILES **********************************************/

/**********************************************************************************************************************
 * MACROS
 *********************************************************************************************************************/
/* Macro defined for volatile qualifier*/
#define __vo                        volatile

/*Generic Macro's */
#define ENABLE                      1
#define DISABLE                     0
#define SET                         1
#define RESET                       0
#define GPIO_PIN_SET   				1
#define GPIO_PIN_RESET 				0

/* base addresses of flash and SRAM memories */
/* Macro defined for flash base address */
#define FLASH_BASEADDR              0x08000000UL
/* Macro defined for SRAM 1 base address */
#define SRAM1_BASEADDR              0x20000000UL
/* Macro defined for SRAM 2 base address */
#define SRAM2_BASE_ADDR				0X20040000UL
/* Macro defined for ROM address */
#define ROM							0X1FFF0000UL
/* Macro defined for SRAM address */
#define SRAM                        SRAM1_BASEADDR

/* Base addresses of AHBx and APBx Bus peripheral */
/* Macro defined for peripheral base address */
#define PERIPH_BASE                 0X40000000UL
/* Macro defined for APB1 Base address */
#define APB1_BASE_ADDR              PERIPH_BASE
/* Macro defined for APB2 Base address */
#define APB2_BASE_ADDR              0X40010000UL
/* Macro defined for AHB1 Base address */
#define AHB1_BASE_ADDR              0X40020000UL
/* Macro defined for AHB2 Base address */
#define AHB2_BASE_ADDR              0X48000000UL

/* Base address of peripherals which are on AHB2 BUS */
/* Macro defined for GPIOA Base address */
#define GPIOA_BASE_ADDR				(AHB2_BASE_ADDR + 0X0000)
/* Macro defined for GPIOB Base address */
#define GPIOB_BASE_ADDR				(AHB2_BASE_ADDR + 0X0400)
/* Macro defined for GPIOC Base address */
#define GPIOC_BASE_ADDR				(AHB2_BASE_ADDR + 0X0800)
/* Macro defined for GPIOD Base address */
#define GPIOD_BASE_ADDR				(AHB2_BASE_ADDR + 0X0C00)
/* Macro defined for GPIOE Base address */
#define GPIOE_BASE_ADDR				(AHB2_BASE_ADDR + 0X1000)
/* Macro defined for GPIOF Base address */
#define GPIOF_BASE_ADDR				(AHB2_BASE_ADDR + 0X1400)
/* Macro defined for GPIOG Base address */
#define GPIOG_BASE_ADDR				(AHB2_BASE_ADDR + 0X1800)
/* Macro defined for GPIOH Base address */
#define GPIOH_BASE_ADDR				(AHB2_BASE_ADDR + 0X1C00)
/* Macro defined for OTG FS Base address */
#define OTG_FS_BASE_ADDR			0X50000000UL
/* Macro defined for ADC Base address */
#define ADC_BASE_ADDR				0X50040000UL
/* Macro defined for AES Base address */
#define AES_BASE_ADDR				0X50060000UL
/* Macro defined for RNG Base address */
#define RNG_BASE_ADDR				0X50060800UL

/* Base address of peripherals which are on AHB1 BUS */
/* Macro defined for DMA1 Base address */
#define DMA1_BASE_ADDR				(AHB1_BASE_ADDR + 0X0000)
/* Macro defined for DMA2 Base address */
#define DMA2_BASE_ADDR				(AHB1_BASE_ADDR + 0X0400)
/* Macro defined for RCC Base address */
#define RCC_BASE_ADDR				(AHB1_BASE_ADDR + 0X1000)
/* Macro defined for Flash Register Base address */
#define FLASHR_BASE_ADDR			(AHB1_BASE_ADDR + 0X2000)
/* Macro defined for CRC Base address */
#define CRC_BASE_ADDR				(AHB1_BASE_ADDR + 0X3000)
/* Macro defined for Touch sensing controller Base address */
#define TSC_BASE_ADDR               (AHB1_BASE_ADDR + 0X4000)


/* Base address of peripherals which are on APB1 BUS */
/* Macro defined for Timer 2 Base address */
#define TIM2_BASE_ADDR				(APB1_BASE_ADDR + 0X0000)
/* Macro defined for Timer 3 Base address */
#define TIM3_BASE_ADDR              (APB1_BASE_ADDR + 0X0400)
/* Macro defined for Timer 4 Base address */
#define TIM4_BASE_ADDR              (APB1_BASE_ADDR + 0X0800)
/* Macro defined for Timer 5 Base address */
#define TIM5_BASE_ADDR              (APB1_BASE_ADDR + 0X0C00)
/* Macro defined for Timer 6 Base address */
#define TIM6_BASE_ADDR              (APB1_BASE_ADDR + 0X1000)
/* Macro defined for Timer 7 Base address */
#define TIM7_BASE_ADDR              (APB1_BASE_ADDR + 0X1400)
/* Macro defined for LCD Base address */
#define LCD_BASE_ADDR               (APB1_BASE_ADDR + 0X2400)
/* Macro defined for RTC Base address */
#define RTC_BASE_ADDR               (APB1_BASE_ADDR + 0X2800)
/* Macro defined for Window Watchdog  Base address */
#define WWDG_BASE_ADDR              (APB1_BASE_ADDR + 0X2C00)
/* Macro defined for Independent Watchdog  Base address */
#define IWDG_BASE_ADDR              (APB1_BASE_ADDR + 0X3000)
/* Macro defined for SPI2 Base address */
#define SPI2_BASE_ADDR              (APB1_BASE_ADDR + 0X3800)
/* Macro defined for SPI3 Base address */
#define SPI3_BASE_ADDR              (APB1_BASE_ADDR + 0X3C00)
/* Macro defined for USART2 Base address */
#define USART2_BASE_ADDR            (APB1_BASE_ADDR + 0X4400)
/* Macro defined for USART3 Base address */
#define USART3_BASE_ADDR            (APB1_BASE_ADDR + 0X4800)
/* Macro defined for UART4  Base address */
#define UART4_BASE_ADDR             (APB1_BASE_ADDR + 0X4C00)
/* Macro defined for UART5 Base address */
#define UART5_BASE_ADDR             (APB1_BASE_ADDR + 0X5000)
/* Macro defined for I2C1 Base address */
#define I2C1_BASE_ADDR              (APB1_BASE_ADDR + 0X5400)
/* Macro defined for I2C2 Base address */
#define I2C2_BASE_ADDR              (APB1_BASE_ADDR + 0X5800)
/* Macro defined for I2C3 Base address */
#define I2C3_BASE_ADDR              (APB1_BASE_ADDR + 0X5C00)
/* Macro defined for CAN1 Base address */
#define CAN1_BASE_ADDR              (APB1_BASE_ADDR + 0X6400)
/* Macro defined for Power control  Base address */
#define PWR_BASE_ADDR               (APB1_BASE_ADDR + 0X7000)
/* Macro defined for DAC1 Base address */
#define DAC1_BASE_ADDR              (APB1_BASE_ADDR + 0X7400)
/* Macro defined for OPAMp Base address */
#define OPAMP_BASE_ADDR             (APB1_BASE_ADDR + 0X7800)
/* Macro defined for Low-Power Timer1  Base address */
#define LPTIM1_BASE_ADDR            (APB1_BASE_ADDR + 0X7C00)
/* Macro defined for Low-Power UART Base address */
#define LPUART1_BASE_ADDR           (APB1_BASE_ADDR + 0X8000)
/* Macro defined for Single Wire Protocol master Base address */
#define SWPMI1_BASE_ADDR            (APB1_BASE_ADDR + 0X8800)
/* Macro defined for Low Power Timer2 Base address */
#define LPTIM2_BASE_ADDR			(APB1_BASE_ADDR + 0X9400)


/* Base address of peripherals which are on APB2 BUS*/
/* Macro defined for system configuration Base address */
#define SYSCFG_BASE_ADDR 			(APB2_BASE_ADDR + 0X0000)
/* Macro defined for VREF Buffer Base address */
#define VREFBUF_BASE_ADDR 			(APB2_BASE_ADDR + 0X0030)
/* Macro defined for Comparator  Base address */
#define COMP_BASE_ADDR 			 	(APB2_BASE_ADDR + 0X0200)
/* Macro defined for EXIT  Base address */
#define EXTI_BASE_ADDR 			 	(APB2_BASE_ADDR + 0X0400)
/* Macro defined for Fire Wall  Base address */
#define FIREWALL_BASE_ADDR 			(APB2_BASE_ADDR + 0X1C00)
/* Macro defined for SDMMC1 Base address */
#define SDMMC1_BASE_ADDR 			(APB2_BASE_ADDR + 0X2800)
/* Macro defined for Timer 1 Base address */
#define TIM1_BASE_ADDR 			 	(APB2_BASE_ADDR + 0X2C00)
/* Macro defined for SPI 1 Base address */
#define SPI1_BASE_ADDR 			 	(APB2_BASE_ADDR + 0X3000)
/* Macro defined for Timer 8 Base address */
#define TIM8_BASE_ADDR 			 	(APB2_BASE_ADDR + 0X3400)
/* Macro defined for USART 1Base address */
#define USART1_BASE_ADDR 			(APB2_BASE_ADDR + 0X3800)
/* Macro defined for Timer 15 Base address */
#define TIM15_BASE_ADDR 			(APB2_BASE_ADDR + 0X4000)
/* Macro defined for Timer 16 Base address */
#define TIM16_BASE_ADDR 			(APB2_BASE_ADDR + 0X4400)
/* Macro defined for Timer 17 Base address */
#define TIM17_BASE_ADDR 			(APB2_BASE_ADDR + 0X4800)
/* Macro defined for Serial Audio Interface 1 Base address */
#define SAI1_BASE_ADDR 			 	(APB2_BASE_ADDR + 0X5400)
/* Macro defined for Serial Audio Interface 2 Base address */
#define SAI2_BASE_ADDR 			    (APB2_BASE_ADDR + 0X5800)
/* Macro defined for Digital Filter for Sigma-Delta Modulator Base address */
#define DFSDM1_BASE_ADDR 			(APB2_BASE_ADDR + 0X6000)

/* GPIO Peripheral Defintion*/
/* Macro defined for GPIO port A*/
#define GPIOA 						((GPIO_RegDef_t *)GPIOA_BASE_ADDR)
/* Macro defined for GPIO port B*/
#define GPIOB 						((GPIO_RegDef_t *)GPIOB_BASE_ADDR)
/* Macro defined for GPIO port C*/
#define GPIOC 						((GPIO_RegDef_t *)GPIOC_BASE_ADDR)
/* Macro defined for GPIO port D*/
#define GPIOD 						((GPIO_RegDef_t *)GPIOD_BASE_ADDR)
/* Macro defined for GPIO port E*/
#define GPIOE 						((GPIO_RegDef_t *)GPIOE_BASE_ADDR)
/* Macro defined for GPIO port F*/
#define GPIOF 						((GPIO_RegDef_t *)GPIOF_BASE_ADDR)
/* Macro defined for GPIO port G*/
#define GPIOG 						((GPIO_RegDef_t *)GPIOG_BASE_ADDR)
/* Macro defined for GPIO port H*/
#define GPIOH 						((GPIO_RegDef_t *)GPIOH_BASE_ADDR)
/*
 *  RCC Peripheral Defintion
 */

#define RCC		((RCC_RegDef_t *)RCC_BASE_ADDR)

/* Clock Enable Macros for GPIOx Peripherals */
/* Macro defined To Enable GPIOA Peripheral clock */
#define GPIOA_PCLK_EN()             (RCC -> AHB2ENR |= 1<<0)
/* Macro defined To Enable GPIOB Peripheral clock */
#define GPIOB_PCLK_EN()             (RCC -> AHB2ENR |= 1<<1)
/* Macro defined To Enable GPIOC Peripheral clock */
#define GPIOC_PCLK_EN()             (RCC -> AHB2ENR |= 1<<2)
/* Macro defined To Enable GPIOD Peripheral clock */
#define GPIOD_PCLK_EN()             (RCC -> AHB2ENR |= 1<<3)
/* Macro defined To Enable GPIOE Peripheral clock */
#define GPIOE_PCLK_EN()             (RCC -> AHB2ENR |= 1<<4)
/* Macro defined To Enable GPIOF Peripheral clock */
#define GPIOF_PCLK_EN()             (RCC -> AHB2ENR |= 1<<5)
/* Macro defined To Enable GPIOG Peripheral clock */
#define GPIOG_PCLK_EN()             (RCC -> AHB2ENR |= 1<<6)
/* Macro defined To Enable GPIOH Peripheral clock */
#define GPIOH_PCLK_EN()             (RCC -> AHB2ENR |= 1<<7)


/*Clock Enable Macros for I2C Peripherals*/
/* Macro defined To Enable I2C1 Peripheral clock */
#define I2C1_PCLK_EN()              (RCC -> APB1ENR1 |= 1<<21)
/* Macro defined To Enable I2C2 Peripheral clock */
#define I2C2_PCLK_EN()              (RCC -> APB1ENR1 |= 1<<22)
/* Macro defined To Enable I2C3 Peripheral clock */
#define I2C3_PCLK_EN()              (RCC -> APB1ENR1 |= 1<<23)


/*Clock Enable Macros for SPI Peripherals*/
/* Macro defined To Enable SPI1 Peripheral clock */
#define SPI1_PCLK_EN()              (RCC -> APB2ENR  |= 1<<12)
/* Macro defined To Enable SPI2 Peripheral clock */
#define SPI2_PCLK_EN()              (RCC -> APB1ENR1 |= 1<<14)
/* Macro defined To Enable SPI3 Peripheral clock */
#define SPI3_PCLK_EN()              (RCC -> APB1ENR1 |= 1<<15)

/*Clock Enable Macros for UART Peripherals*/
/* Macro defined To Enable USART1 Peripheral clock */
#define USART1_PCLK_EN()       	    (RCC -> APB2ENR  |= 1<<14)
/* Macro defined To Enable USART2 Peripheral clock */
#define USART2_PCLK_EN()		    (RCC -> APB1ENR1 |= 1<<17)
/* Macro defined To Enable USART3 Peripheral clock */
#define USART3_PCLK_EN()		    (RCC -> APB1ENR1 |= 1<<18)
/* Macro defined To Enable UART4 Peripheral clock */
#define UART4_PCLK_EN()		        (RCC -> APB1ENR1 |= 1<<19)
/* Macro defined To Enable UART5 Peripheral clock */
#define UART5_PCLK_EN()		        (RCC -> APB1ENR1 |= 1<<20)

/*Clock Enable Macros for SYSCFG*/
/* Macro defined To Enable System Config   Peripheral clock */
#define SYSCFG_PCLK_EN()            (RCC -> APB2ENR |=1<<0)


/* Clock Disable Macros for GPIO Peripherals  */
/* Macro defined To Disable GPIOA Peripheral clock */
#define GPIOA_PCLK_DI()             (RCC -> AHB2ENR &= ~(1<<0))
/* Macro defined To Disable GPIOB Peripheral clock */
#define GPIOB_PCLK_DI()             (RCC -> AHB2ENR &= ~(1<<1))
/* Macro defined To Disable GPIOC Peripheral clock */
#define GPIOC_PCLK_DI()             (RCC -> AHB2ENR &= ~(1<<2))
/* Macro defined To Disable GPIOD Peripheral clock */
#define GPIOD_PCLK_DI()             (RCC -> AHB2ENR &= ~(1<<3))
/* Macro defined To Disable GPIOE Peripheral clock */
#define GPIOE_PCLK_DI()             (RCC -> AHB2ENR &= ~(1<<4))
/* Macro defined To Disable GPIOF Peripheral clock */
#define GPIOF_PCLK_DI()             (RCC -> AHB2ENR &= ~(1<<5))
/* Macro defined To Disable GPIOG Peripheral clock */
#define GPIOG_PCLK_DI()             (RCC -> AHB2ENR &= ~(1<<6))
/* Macro defined To Disable GPIOH Peripheral clock */
#define GPIOH_PCLK_DI()             (RCC -> AHB2ENR &= ~(1<<7))

/*Clock Disable Macros for I2C Peripherals*/
/* Macro defined To Disable I2C1 Peripheral clock */
#define I2C1_PCLK_DI()              (RCC -> APB1ENR1 &= ~(1<<21))
/* Macro defined To Disable I2C2 Peripheral clock */
#define I2C2_PCLK_DI()              (RCC -> APB1ENR1 &= ~(1<<22))
/* Macro defined To Disable I2C3 Peripheral clock */
#define I2C3_PCLK_DI()              (RCC -> APB1ENR1 &= ~(1<<23))

/*Clock Disable Macros for SPI Peripherals*/
/* Macro defined To Disable SPI1 Peripheral clock */
#define SPI1_PCLK_DI()              (RCC -> APB2ENR  &= ~(1<<12))
/* Macro defined To Disable SPI2 Peripheral clock */
#define SPI2_PCLK_DI()              (RCC -> APB1ENR1 &= ~(1<<14))
/* Macro defined To Disable SPI3 Peripheral clock */
#define SPI3_PCLK_DI()              (RCC -> APB1ENR1 &= ~(1<<15))

/*Clock Disable Macros for UART Peripherals*/
/* Macro defined To Disable USART1 Peripheral clock */
#define USART1_PCLK_DI()       	    (RCC -> APB2ENR  &= ~(1<<14))
/* Macro defined To Disable USART2 Peripheral clock */
#define USART2_PCLK_DI()		    (RCC -> APB1ENR1 &= ~(1<<17))
/* Macro defined To Disable USART3 Peripheral clock */
#define USART3_PCLK_DI()		    (RCC -> APB1ENR1 &= ~(1<<18))
/* Macro defined To Disable UART4 Peripheral clock */
#define UART4_PCLK_DI()		        (RCC -> APB1ENR1 &= ~(1<<19))
/* Macro defined To Disable UART5 Peripheral clock */
#define UART5_PCLK_DI()		        (RCC -> APB1ENR1 &= ~(1<<20))

/*  Clock Disable Macros for SYSCFG */
/* Macro defined To Disable System Config   Peripheral clock */
#define SYSCFG_PCLK_DI()            (RCC -> APB2ENR &=~(1<<0))

/*Macros to Reset GPIOx Peripherals */
/* Macro defined for GPIOA Reset Register */
#define GPIOA_REG_RESET()			do{(RCC -> AHB2RSTR |= (1<<0)); RCC -> AHB2RSTR &= ~(1<<0);}while(0)
/* Macro defined for GPIOB Reset Register */
#define GPIOB_REG_RESET()			do{(RCC -> AHB2RSTR |= (1<<1)); RCC -> AHB2RSTR &= ~(1<<1);}while(0)
/* Macro defined for GPIOC Reset Register */
#define GPIOC_REG_RESET()			do{(RCC -> AHB2RSTR |= (1<<2)); RCC -> AHB2RSTR &= ~(1<<2);}while(0)
/* Macro defined for GPIOD Reset Register */
#define GPIOD_REG_RESET()			do{(RCC -> AHB2RSTR |= (1<<3)); RCC -> AHB2RSTR &= ~(1<<3);}while(0)
/* Macro defined for GPIOE Reset Register */
#define GPIOE_REG_RESET()			do{(RCC -> AHB2RSTR |= (1<<4)); RCC -> AHB2RSTR &= ~(1<<4);}while(0)
/* Macro defined for GPIOF Reset Register */
#define GPIOF_REG_RESET()			do{(RCC -> AHB2RSTR |= (1<<5)); RCC -> AHB2RSTR &= ~(1<<5);}while(0)
/* Macro defined for GPIOG Reset Register */
#define GPIOG_REG_RESET()			do{(RCC -> AHB2RSTR |= (1<<6)); RCC -> AHB2RSTR &= ~(1<<6);}while(0)
/* Macro defined for GPIOH Reset Register */
#define GPIOH_REG_RESET()			do{(RCC -> AHB2RSTR |= (1<<7)); RCC -> AHB2RSTR &= ~(1<<7);}while(0)

/****************************************************** ENF OF MACROS ************************************************/

/**********************************************************************************************************************
 * ENUMS
 *********************************************************************************************************************/

/****************************************************** END OF ENUM **************************************************/
/**********************************************************************************************************************
 * TYPEDEFS
 *********************************************************************************************************************/

typedef struct
{
	/** GPIO port mode register */
	__vo uint32_t MODER;

	/** GPIO port output type register */
	__vo uint32_t OTYPER;

	/** GPIO port output speed register */
	__vo uint32_t OSPEEDR;

	/** GPIO port pull-up/pull-down register */
	__vo uint32_t PUPDR;

	/** GPIO port input data register */
	__vo uint32_t IDR;

	/** GPIO port output data register */
	__vo uint32_t ODR;

	/** GPIO port bit set/reset register */
	__vo uint32_t BSRR;

	/** GPIO port configuration lock register */
	__vo uint32_t LCKR;

	/** GPIO alternate function registers AFR[0] = AFRL , AFR[1] = AFRH  */
	__vo uint32_t AFR[2];

	/** GPIO port bit reset register */
	__vo uint32_t BRR;

	/** GPIO analog switch control register */
	__vo uint32_t ASCR;

}GPIO_RegDef_t;

typedef struct
{
	 /** Clock control register */
	    __vo uint32_t CR;

	    /** Internal clock sources calibration register */
	    __vo uint32_t ICSCR;

	    /** Clock configuration register */
	    __vo uint32_t CFGR;

	    /** PLL configuration register */
	    __vo uint32_t PLLCFGR;

	    /** PLLSAI1 configuration register */
	    __vo uint32_t PLLSAI1CFGR;

	    /** PLLSAI2 configuration register */
	    __vo uint32_t PLLSAI2CFGR;

	    /** Clock interrupt enable register */
	    __vo uint32_t CIER;

	    /** Clock interrupt flag register */
	    __vo uint32_t CIFR;

	    /** Clock interrupt clear register */
	    __vo uint32_t CICR;

	    /** Reserved */
	    __vo uint32_t RESERVED0;

	    /** AHB1 peripheral reset register */
	    __vo uint32_t AHB1RSTR;

	    /** AHB2 peripheral reset register */
	    __vo uint32_t AHB2RSTR;

	    /** AHB3 peripheral reset register */
	    __vo uint32_t AHB3RSTR;

	    /** Reserved */
	    __vo uint32_t RESERVED1;

	    /** APB1 peripheral reset register 1 */
	    __vo uint32_t APB1RSTR1;

	    /** APB1 peripheral reset register 2 */
	    __vo uint32_t APB1RSTR2;

	    /** APB2 peripheral reset register */
	    __vo uint32_t APB2RSTR;

	    /** Reserved */
	    __vo uint32_t RESERVED2;

	    /** AHB1 peripheral clock enable register */
	    __vo uint32_t AHB1ENR;

	    /** AHB2 peripheral clock enable register */
	    __vo uint32_t AHB2ENR;

	    /** AHB3 peripheral clock enable register */
	    __vo uint32_t AHB3ENR;

	    /** Reserved */
	    __vo uint32_t RESERVED3;

	    /** APB1 peripheral clock enable register 1 */
	    __vo uint32_t APB1ENR1;

	    /** APB1 peripheral clock enable register 2 */
	    __vo uint32_t APB1ENR2;

	    /** APB2 peripheral clock enable register */
	    __vo uint32_t APB2ENR;

	    /** Reserved */
	    __vo uint32_t RESERVED4;

	    /** AHB1 peripheral clock enable in sleep mode register */
	    __vo uint32_t AHB1SMENR;

	    /** AHB2 peripheral clock enable in sleep mode register */
	    __vo uint32_t AHB2SMENR;

	    /** AHB3 peripheral clock enable in sleep mode register */
	    __vo uint32_t AHB3SMENR;

	    /** Reserved */
	    __vo uint32_t RESERVED5;

	    /** APB1 peripheral clock enable in sleep mode register 1 */
	    __vo uint32_t APB1SMENR1;

	    /** APB1 peripheral clock enable in sleep mode register 2 */
	    __vo uint32_t APB1SMENR2;

	    /** APB2 peripheral clock enable in sleep mode register */
	    __vo uint32_t APB2SMENR;

	    /** Reserved */
	    __vo uint32_t RESERVED6;

	    /** Peripherals independent clock configuration register */
	    __vo uint32_t CCIPR;

	    /** Reserved */
	    __vo uint32_t RESERVED7;

	    /** Backup domain control register */
	    __vo uint32_t BDCR;

	    /** Control/status register */
	    __vo uint32_t CSR;

	    /** Clock recovery RC register */
	    __vo uint32_t CRRCR;

	    /** Peripherals independent clock configuration register 2 */
	    __vo uint32_t CCIPR2;

}RCC_RegDef_t;


/****************************************************** END OF TYPEDEF ***********************************************/


/**********************************************************************************************************************
 * GLOBAL VARIABLES
 *********************************************************************************************************************/

/*************************************************** END OF GLOBAL VARIABLES******************************************/

/**********************************************************************************************************************
 * FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/************************************************** END OF FUNCTION PROTOTYPES ***************************************/


#endif /* INC_STM32L476XX_H_ */
