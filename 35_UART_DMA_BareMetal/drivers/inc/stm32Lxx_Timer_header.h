/*
 * STM32Lxx_TImer_header.h
 *
 *  Created on: Sep 22, 2025
 *      Author: HP
 */

#ifndef INC_STM32LXX_TIMER_HEADER_H_
#define INC_STM32LXX_TIMER_HEADER_H_

#include "STM32Lxx_gpio_header.h"

#define SR_UIF                (1U<<0)
#define SR_CC1IF              (1U<<1)
#define TIM2EN                (1U<<0)
#define TIM3EN                (1U<<1)
#define CR1_CEN  			  (1U<<0)
#define GPIOA_EN              (1U<<0)
#define SR_UIF                (1U<<0)
#define DIER_UIE 			  (1U<<0)


void Timer_HZ1_init(void);
void Timer_PA5OutputCompare(void);
void Timer_PA6InputCompare(void);
void Timer_1HzInterruptInit(void);

#endif /* INC_STM32LXX_TIMER_HEADER_H_ */
