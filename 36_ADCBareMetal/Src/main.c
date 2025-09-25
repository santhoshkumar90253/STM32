
#include "main.h"
I2C_Handle_t I2C1Handle;
USART_Handle_t usart2_handle;
uint8_t I2C_txData[] = "Hai.. ESP32";

void delay(void)
{
    for(uint32_t i = 0 ; i < 250000 ; i++);
}
void USART2_GPIOInits(void)
{
    GPIO_Handle_t usart2_gpio;
    memset(&usart2_gpio,0,sizeof(usart2_gpio));

    usart2_gpio.pGPIOx = GPIOA;
    usart2_gpio.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
    usart2_gpio.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    usart2_gpio.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
    usart2_gpio.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    usart2_gpio.GPIO_PinConfig.GPIO_PinAltFunMode = 7;

    // PA2 USART2 TX
    usart2_gpio.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;
    GPIOA_PCLK_EN();
    GPIO_Init(&usart2_gpio);

    // PA3 USART2 RX
    usart2_gpio.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_3;
    GPIO_Init(&usart2_gpio);
}
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


int main(void)
{
	uint16_t adcValue = RESET;
	uint8_t data[20];
	USART2_GPIOInits();
	USART2_Init();
	USART_PeripheralControl(USART2, ENABLE);
	ADC_init();
    while(1)
    {
    	ADC_startConvertion();
    	adcValue = ADC_read();
    	sprintf((char *)data,"ADC Value: %u\r\n", adcValue);
    	USART_SendData(&usart2_handle, data, strlen((char *)data));

    }
}
