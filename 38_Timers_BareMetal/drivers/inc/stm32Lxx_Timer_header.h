/*
 * STM32Lxx_TImer_header.h
 *
 *  Created on: Sep 24, 2025
 *      Author: HP
 */

#ifndef INC_STM32LXX_TIMER_HEADER_H_
#define INC_STM32LXX_TIMER_HEADER_H_


#define SR_UIF                (1U<<0)
#define SR_CC1IF              (1U<<1)
#define TIM2EN                (1U<<0)
#define TIM3EN                (1U<<1)
#define CR1_CEN  			  (1U<<0)
#define GPIOA_EN              (1U<<0)
#define SR_UIF                 (1U<<0)
void Timer_HZ1_init(void);
#endif /* INC_STM32LXX_TIMER_HEADER_H_ */
