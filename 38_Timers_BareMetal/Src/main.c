
#include "main.h"

int main(void)
{
	GPIO_Handle_t gpioLED;
	gpioLED.pGPIOx = GPIOA;
	gpioLED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	gpioLED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	gpioLED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	gpioLED.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpioLED.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	GPIO_Init(&gpioLED);
	Timer_HZ1_init();

    while(1)
    {
    	while(!(TIM2->SR & SR_UIF));
    	TIM2->SR &=~(SR_UIF);
    	GPIO_TogglePin(GPIOA, GPIO_PIN_NO_5);

    }
}
