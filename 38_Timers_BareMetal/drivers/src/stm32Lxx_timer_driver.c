/*
 * STM32Lxx_timer_driver.c
 *
 *  Created on: Sep 24, 2025
 *      Author: HP
 */
#include "STM32Lxx.h"
#include "STM32Lxx_TImer_header.h"

void Timer_HZ1_init(void)
{
	RCC->APB1ENR1 |= TIM2EN;

	TIM2->PSC = 16000-1;
	TIM2->ARR = 1000-1;
	TIM2->CNT = 0;
	TIM2->CR1 = CR1_CEN;
}
