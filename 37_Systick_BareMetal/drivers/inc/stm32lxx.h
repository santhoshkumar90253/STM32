/*
 * STM32Lxx.h
 *
 *  Created on: Sep 11, 2025
 *      Author: HP
 */

#ifndef INC_STM32LXX_H_
#define INC_STM32LXX_H_
/**********************************************************************************************************************
 * INCLUDE FILES
**********************************************************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

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

#define SPI_FLAG_SET                1
#define SPI_FLAG_RESET              0
#define USART_FLAG_SET              1
#define USART_FLAG_RESET            0


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
//base address of systick
#define SYSTICK_BASE_ADDR                0xE000E010

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

/*RCC Peripheral Defintion */

#define RCC		                    ((RCC_RegDef_t *)RCC_BASE_ADDR)

#define EXTI		                ((EXTI_RegDef_t *)EXTI_BASE_ADDR)

#define SYSCFG		                ((SYSCFG_RegDef_t *)SYSCFG_BASE_ADDR)

#define SPI1						((SPI_RegDef_t *)SPI1_BASE_ADDR)
#define SPI2						((SPI_RegDef_t *)SPI2_BASE_ADDR)
#define SPI3						((SPI_RegDef_t *)SPI3_BASE_ADDR)

#define I2C1                         ((I2C_RegDef_t *)I2C1_BASE_ADDR)
#define I2C2                         ((I2C_RegDef_t *)I2C2_BASE_ADDR)
#define I2C3                         ((I2C_RegDef_t *)I2C3_BASE_ADDR)

#define USART1						((USART_RegDef_t *)USART1_BASE_ADDR)
#define USART2                      ((USART_RegDef_t *)USART2_BASE_ADDR)
#define USART3						((USART_RegDef_t *)USART3_BASE_ADDR)
#define UART4						((USART_RegDef_t *)UART4_BASE_ADDR)
#define UART5						((USART_RegDef_t *)UART5_BASE_ADDR)

#define ADC1                         ((ADC_RegDef_t*)ADC_BASE_ADDR)
#define ADCOM						 ((ADCOM_RegDef_t *)(ADC_BASE_ADDR+ 0X300UL))

#define TIM2                         ((Tim_RegDef_t *)TIM2_BASE_ADDR)
#define TIM3						 ((Tim_RegDef_t *)TIM3_BASE_ADDR)


// --- RCC (Reset and Clock Control) ---
#define RCC_AHB2ENR_ADCEN       (1U << 13)   // Enable ADC clock on AHB2 bus

// --- ADC Control Register (ADC_CR) ---
#define ADC_CR_ADEN             (1UL << 0U)  // Enable ADC
#define ADC_CR_ADDIS            (1UL << 1U)  // Disable ADC
#define ADC_CR_ADSTART          (1UL << 2U)  // Start regular conversion
#define ADC_CR_ADCAL            (1UL << 31U) // Start ADC calibration
#define ADC_CR_ADVREGEN         (1UL << 28U) // Enable ADC voltage regulator
#define ADC_CR_DEEPPWD          (1UL << 29U) // Enable deep-power-down mode

// --- ADC Common Control Register (ADC_CCR) ---
#define ADC_CCR_CKMODE_Msk      (0x3UL << 16U) // Mask for ADC clock mode bits
#define ADC_CCR_CKMODE          ADC_CCR_CKMODE_Msk
#define ADC_CCR_CKMODE_DIV1     (0x1UL << 16U) // Clock mode: HCLK / 1
#define ADC_CCR_CKMODE_DIV2     (0x2UL << 16U) // Clock mode: HCLK / 2

// --- ADC Interrupt and Status Register (ADC_ISR) ---
#define ADC_ISR_ADRDY           (1UL << 0U)  // ADC ready flag
#define ADC_ISR_EOC             (1UL << 2U)  // End of conversion flag

// --- ADC Regular Sequence Register 1 (ADC_SQR1) ---
#define ADC_SQR1_L_Msk          (0xFUL << 0U)  // Mask for regular channel sequence length
#define ADC_SQR1_L              ADC_SQR1_L_Msk // Sequence length configuration


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

#define GPIO_BASEADDR_TO_CODE(x)   (( x == GPIOA)? 0:\
									( x == GPIOB)? 1:\
									( x == GPIOC)? 2:\
									( x == GPIOD)? 3:\
									( x == GPIOE)? 4:\
									( x == GPIOF)? 5:\
									( x == GPIOG)? 6:\
									( x == GPIOH)? 7:0)
/* NVIC Configuration */
#define NVIC_ISER0     					((__vo uint32_t *) 0xE000E100)
#define NVIC_ISER1     					((__vo uint32_t *) 0xE000E104)
#define NVIC_ISER2     					((__vo uint32_t *) 0xE000E108)
#define NVIC_ISER3     					((__vo uint32_t *) 0xE000E10C)
#define NVIC_ISER4    		 			((__vo uint32_t *) 0xE000E110)
#define NVIC_ISER5     					((__vo uint32_t *) 0xE000E114)

#define NVIC_ICER0     					((__vo uint32_t *) 0XE000E180)
#define NVIC_ICER1     					((__vo uint32_t *) 0xE000E184)
#define NVIC_ICER2     					((__vo uint32_t *) 0xE000E188)
#define NVIC_ICER3     					((__vo uint32_t *) 0xE000E18C)
#define NVIC_ICER4     					((__vo uint32_t *) 0xE000E190)
#define NVIC_ICER5     					((__vo uint32_t *) 0xE000E194)

#define NVIC_PR_BASE_ADDR  				((__vo uint32_t *)  0xE000E400)
#define NO_PR_BITS_IMPLEMENTED   		4

/* EXT Interrupt Configuration no */

#define IRQ_NO_EXTI0   					6
#define IRQ_NO_EXTI1   					7
#define IRQ_NO_EXTI2   					8
#define IRQ_NO_EXTI3   					9
#define IRQ_NO_EXTI4   					10
#define IRQ_NO_EXTI9_5   				23
#define IRQ_NO_EXTI15_10   				40

#define IRQ_NO_USART1	    			37
#define IRQ_NO_USART2	    			38
#define IRQ_NO_USART3	    			39
#define IRQ_NO_UART4	    			52
#define IRQ_NO_UART5	    			53

#define IRQ_NO_SPI1						35
#define IRQ_NO_SPI2						36
#define IRQ_NO_SPI3						51

#define I2C_CR1_ACK     10
/* I2C_CR1 bits */
#define I2C_CR1_PE       0   /* Peripheral enable */
#define I2C_CR1_TXIE     1   /* TX interrupt enable */
#define I2C_CR1_RXIE     2   /* RX interrupt enable */
#define I2C_CR1_ADDRIE   3   /* Address match interrupt enable */
#define I2C_CR1_NACKIE   4   /* NACK received interrupt enable */
#define I2C_CR1_STOPIE   5   /* STOP detection interrupt enable */
#define I2C_CR1_TCIE     6   /* Transfer complete interrupt enable */
#define I2C_CR1_ERRIE    7   /* Error interrupt enable */
#define I2C_CR1_ACK      10  /* ACK enable */

/* I2C_ISR bits */
#define I2C_ISR_TXE      0   /* TXDR empty */
#define I2C_ISR_TXIS     1   /* TX interrupt status (TXDR empty and ready) */
#define I2C_ISR_RXNE     2   /* RXDR not empty */
#define I2C_ISR_ADDR     3   /* Address matched */
#define I2C_ISR_NACKF    4   /* NACK received */
#define I2C_ISR_STOPF    5   /* STOP detection */
#define I2C_ISR_TC       6   /* Transfer complete */
#define I2C_ISR_TCR      7   /* Transfer complete reload */
#define I2C_ISR_BERR     8   /* Bus error */
#define I2C_ISR_ARLO     9   /* Arbitration lost */
#define I2C_ISR_OVR      10  /* Overrun/underrun */

/* I2C_ICR bits (write 1 to clear) */
#define I2C_ICR_ADDRCF   3   /* Clear ADDR flag */
#define I2C_ICR_NACKCF   4   /* Clear NACK flag */
#define I2C_ICR_STOPCF   5   /* Clear STOP flag */
#define I2C_ICR_BERRCF   8   /* Clear Bus error */
#define I2C_ICR_ARLOCF   9   /* Clear Arbitration lost */
#define I2C_ICR_OVRCF    10  /* Clear Overrun/underrun */

/* Possible Priority level numbers */
#define NVIC_IRQ_PRI0                   0
#define NVIC_IRQ_PRI1                   1
#define NVIC_IRQ_PRI2                   2
#define NVIC_IRQ_PRI3                   3
#define NVIC_IRQ_PRI4                   4
#define NVIC_IRQ_PRI5                   5
#define NVIC_IRQ_PRI6                   6
#define NVIC_IRQ_PRI7                   7
#define NVIC_IRQ_PRI8                   8
#define NVIC_IRQ_PRI9                   9
#define NVIC_IRQ_PRI10                  10
#define NVIC_IRQ_PRI11                  11
#define NVIC_IRQ_PRI12                  12
#define NVIC_IRQ_PRI13                  13
#define NVIC_IRQ_PRI14                  14
#define NVIC_IRQ_PRI15                  15
#define NVIC_IRQ_PRI16                  16

/* Bit Position defination of SPI Peripheral */
#define SPI_CR1_CPHA                  0
#define SPI_CR1_CPOL                  1
#define SPI_CR1_MSTR                  2
#define SPI_CR1_BR                    3
#define SPI_CR1_DFF                   8
#define SPI_CR1_RXONLY                10
#define SPI_CR1_BIDIMODE              15

/* USART and UART Macro's */

#define USART_CR1_UE 					0
#define USART_CR1_UESM 					1
#define USART_CR1_RE  					2
#define USART_CR1_TE 					3
#define USART_CR1_IDLEIE 				4
#define USART_CR1_RXNEIE  				5
#define USART_CR1_TCIE					6
#define USART_CR1_TXEIE					7
#define USART_CR1_PEIE 					8
#define USART_CR1_PS 					9
#define USART_CR1_PCE 					10
#define USART_CR1_WAKE  				11
#define USART_CR1_M 					12
#define USART_CR1_OVER8  				15

#define USART_CR2_ADD   				4
#define USART_CR2_LBDL   				5
#define USART_CR2_LBDIE  				6
#define USART_CR2_LBCL   				8
#define USART_CR2_CPHA   				9
#define USART_CR2_CPOL   				10
#define USART_CR2_STOP   				12
#define USART_CR2_LINEN   				14

#define USART_CR3_EIE					0
#define USART_CR3_IREN					1
#define USART_CR3_IRLP					2
#define USART_CR3_HDSEL					3
#define USART_CR3_NACK					4
#define USART_CR3_SCEN					5
#define USART_CR3_DMAR					6
#define USART_CR3_DMAT					7
#define USART_CR3_RTSE					8
#define USART_CR3_CTSE					9
#define USART_CR3_CTSIE					10
#define USART_CR3_ONEBIT				11

#define USART_ISR_PE					0
#define USART_ISR_FE					1
#define USART_ISR_NF					2
#define USART_ISR_ORE					3
#define USART_ISR_IDLE					4
#define USART_ISR_RXNE					5
#define USART_ISR_TC					6
#define USART_ISR_TXE					7
#define USART_ISR_LBDF					8
#define USART_ISR_CTSIF					9
#define USART_ISR_CTS					10


#define SysTick 						((Systick_RegDef_t *)SYSTICK_BASE_ADDR)

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

/* peripheral register defination structure for EXTI */

typedef struct{
	__vo uint32_t IMR1;
	__vo uint32_t EMR1;
	__vo uint32_t RTSR1;
	__vo uint32_t FTSR1;
	__vo uint32_t SWIER1;
	__vo uint32_t PR1;
	__vo uint32_t reserved[2];
	__vo uint32_t IMR2;
	__vo uint32_t EMR2;
	__vo uint32_t RTSR2;
	__vo uint32_t FTSR2;
	__vo uint32_t SWIER2;
	__vo uint32_t PR2;
}EXTI_RegDef_t;

/* Peripheral register defination structure for SYSCFG */
typedef struct{
	__vo uint32_t MEMRMP;
	__vo uint32_t CFGR1;
	__vo uint32_t EXTICR[4];
	__vo uint32_t SCSR;
	__vo uint32_t CFGR2;
	__vo uint32_t SWPR;
	__vo uint32_t SKR;
	uint8_t reserved0;
	__vo uint32_t SWPR2;

}SYSCFG_RegDef_t;

/* SPI Structure definition */

typedef struct{
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t SR;
	__vo uint32_t DR;
	__vo uint32_t CRCPR;
	__vo uint32_t RXCRCR;
	__vo uint32_t TXCRCR;
}SPI_RegDef_t;

/* USART Structure Defination */
typedef struct
{
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t CR3;
	__vo uint32_t BRR;
	__vo uint32_t GTPR;
	// uint16_t res0;
	__vo uint32_t RTQR;
	__vo uint32_t RQR;
	// uint16_t res1;
	__vo uint32_t ISR;
	__vo uint32_t ICR;
	__vo uint32_t RDR;
	// uint16_t res2;
	__vo uint32_t TDR;
	// uint16_t res3;
}USART_RegDef_t;

/* I2C Structure Defination */
typedef struct
{
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t OAR1;
	__vo uint32_t OAR2;
	__vo uint32_t TIMEINGR;
	__vo uint32_t TIMEOUTR;
	__vo uint32_t ISR;
	__vo uint32_t ICR;
	__vo uint32_t PECR;
	__vo uint32_t RXDR;
	__vo uint32_t TXDR;
}I2C_RegDef_t;
/* DMA Structure Defination */
typedef struct
{
	__vo uint32_t CCR;
	__vo uint32_t CNDTR;
	__vo uint32_t CPAR;
	__vo uint32_t CMAR;
}DMA1_RegDef_t;

typedef struct
{
	__vo uint32_t CSELR;
}DMA1_CSELR_RegDef_t;

typedef struct {
	__vo uint32_t ISR;
	__vo uint32_t IFCR;
}DMA_RegDef_t;
/*
 *  ADC Structure Definition
 */

typedef struct{
	__vo uint32_t ISR;
	__vo uint32_t IER;
	__vo uint32_t CR;
	__vo uint32_t CFGR;
	__vo uint32_t CFGR2;
	__vo uint32_t SMPR1;
	__vo uint32_t SMPR2;
	__vo uint32_t res0;
	__vo uint32_t TR1;
	__vo uint32_t TR2;
	__vo uint32_t TR3;
	__vo uint32_t SQR1;
	__vo uint32_t SQR2;
	__vo uint32_t SQR3;
	__vo uint32_t SQR4;
	__vo uint32_t DR;

}ADC_RegDef_t;


/* ADC Common Register Structure */

typedef struct{
	__vo uint32_t CSR;
	uint32_t res0;
	__vo uint32_t CCR;
	__vo uint32_t CDR;
}ADCOM_RegDef_t;


/* Timer Register Structure */

typedef struct{
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t SMCR;
	__vo uint32_t DIER;
	__vo uint32_t SR;
	__vo uint32_t EGR;
	__vo uint32_t CCMR1;
	__vo uint32_t CCMR2;
	__vo uint32_t CCER;
	__vo uint32_t CNT;
	__vo uint32_t PSC;
	__vo uint32_t ARR;
	__vo uint32_t CCR1;
	__vo uint32_t CCR2;
	__vo uint32_t CCR3;
	__vo uint32_t CCR4;

}Tim_RegDef_t;

/*systick register definiton*/
typedef struct{
	__vo uint32_t CSR;
	__vo uint32_t RVR;
	__vo uint32_t CVR;
	__vo uint32_t CALIB;
}Systick_RegDef_t;

/****************************************************** END OF TYPEDEF ***********************************************/


/**********************************************************************************************************************
 * GLOBAL VARIABLES
 *********************************************************************************************************************/

/*************************************************** END OF GLOBAL VARIABLES******************************************/

/**********************************************************************************************************************
 * FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/************************************************** END OF FUNCTION PROTOTYPES ***************************************/



#endif /* INC_STM32LXX_H_ */
