
#include "main.h"

#define TXBUFFSIZE 30

uint8_t txBuf[TXBUFFSIZE];
USART_Handle_t usart2_handle;


void USART2_Init(void)
{
    usart2_handle.pUSARTx = USART2;
    usart2_handle.USART_Config.USART_Baud = USART_STD_BAUD_115200;
    usart2_handle.USART_Config.USART_HWFlowControl = USART_HW_FLOW_CTRL_NONE;
    usart2_handle.USART_Config.USART_Mode = USART_MODE_TXRX;
    usart2_handle.USART_Config.USART_NoOfStopBits = USART_STOPBITS_1;
    usart2_handle.USART_Config.USART_WordLength = USART_WORDLEN_8BITS;
    usart2_handle.USART_Config.USART_ParityControl = USART_PARITY_DISABLE;
    USART_Init(&usart2_handle);
}


void USART2_GPIOInit(void)
{
    GPIO_Handle_t usart2_gpio;
    memset(&usart2_gpio,0,sizeof(usart2_gpio));

    usart2_gpio.pGPIOx = GPIOA;
    usart2_gpio.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
    usart2_gpio.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    usart2_gpio.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
    usart2_gpio.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    usart2_gpio.GPIO_PinConfig.GPIO_PinAltFunMode = 7;

    usart2_gpio.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;
    GPIOA_PCLK_EN();
    GPIO_Init(&usart2_gpio);
    usart2_gpio.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_3;
    GPIO_Init(&usart2_gpio);
}


void delay()
{
    for(uint32_t i=0; i<500000; i++);
}


int __io_putchar(int ch)
{
    USART_SendData(&usart2_handle, (uint8_t*)&ch, 1);
    return ch;
}
void USART_DMATxInit(void)
{
	RCC->AHB1ENR |= (1<<0);

	DMA1_CSELR->CSELR &= ~(0xF << (4*(7-1)));
	DMA1_CSELR->CSELR |=  (0x02000000);

	DMA1_Channel7->CCR &=~(1<<0);
	DMA1_Channel7->CPAR = (uint32_t)&USART2->TDR;
	DMA1_Channel7->CMAR = (uint32_t)txBuf;
	DMA1_Channel7 ->CNDTR = strlen((char*)txBuf);
	DMA1_Channel7 ->CCR =(1<<4)|(1<<7)|(1<<13);

	USART2->CR3 |=(1<<7);
	DMA1_Channel7->CCR|=(1<<0);
}

int main()
{


    USART2_GPIOInit();
    USART2_Init();
    USART_PeripheralControl(USART2, ENABLE);
    printf("DMA Demo \r\n");
    USART_DMATxInit();
    while(1)
    {
    	while((DMA1_Channel7->CNDTR)!=0);
    	DMA1_Channel7->CCR &=~(1<<0);
    	strcpy((char*)txBuf, "DMA Data Transmit\r\n");
    	DMA1_Channel7 ->CNDTR = strlen((char*)txBuf);
    	DMA1_Channel7 ->CCR |=(1<<0);

    }
}
