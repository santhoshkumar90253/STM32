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

	TIM2->PSC = 4000-1;
	TIM2->ARR = 1000-1;
	TIM2->CNT = 0;
	TIM2->CR1 = CR1_CEN;
}

void Timer_PA5OutputCompare(void)
{
	RCC->AHB2ENR |= GPIOA_EN;

	GPIOA->MODER &=~(3U<<10);
	GPIOA->MODER |=(2U<<10);

	GPIOA->AFR[0] &= ~(0xF << 20);
	GPIOA->AFR[0] |= (0x1 << 20);

	RCC->APB1ENR1 |= TIM2EN;

	TIM2->PSC = 4000-1;
	TIM2->ARR = 1000-1;

	TIM2->CCMR1 &= ~(7U<< 4);
	TIM2->CCMR1 |= (3U<< 4);

	TIM2->CCER = (1U<< 0);

	TIM2->CNT = 0;
	TIM2->CR1 = CR1_CEN;



}
void Timer_PA6InputCompare(void)
{
	RCC->AHB2ENR |= GPIOA_EN;

	    GPIOA->MODER &= ~(3U << 12);
	    GPIOA->MODER |=  (2U << 12);

	    GPIOA->AFR[0] &= ~(0xF << 24);
	    GPIOA->AFR[0] |=  (2U << 24);

	    RCC->APB1ENR1 |= TIM3EN;

	    TIM3->PSC = 4 - 1;

	    TIM3->CCMR1 &= ~(3U << 0);
	    TIM3->CCMR1 |=  (1U << 0);

	    TIM3->CCER &= ~(1U << 1);
	    TIM3->CCER |=  (1U << 0);

	    TIM3->CR1 = CR1_CEN;
}

void Timer_1HzInterruptInit(void)
{
	 RCC->APB1ENR1 |= TIM2EN;
	TIM2->PSC = 4000 - 1;
	TIM2->ARR = 1000 - 1;
	TIM2->CNT = 0;
	TIM2->CR1 = CR1_CEN;
	TIM2->DIER |= DIER_UIE;
	GPIO_IRQITConfig(28, ENABLE);
}
