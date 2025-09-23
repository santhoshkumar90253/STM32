

#include "main.h"


uint8_t msg[50] = "UART Interrupt\r\n",rxData[5];


USART_Handle_t usart2_handle;


void delay(void)
{
    for(uint32_t i = 0 ; i < 250000 ; i++);
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

    // TX pin (PA2)
    usart2_gpio.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;
    GPIOA_PCLK_EN(); // enable clock for GPIOA
    GPIO_Init(&usart2_gpio);

    // RX pin (PA3)
    usart2_gpio.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_3;
    GPIO_Init(&usart2_gpio);
}

int main(void)
{


    USART2_GPIOInit();
    USART2_Init();

    USART_IRQInterruptConfig(IRQ_NO_USART2, ENABLE);
    USART_PeripheralControl(USART2, ENABLE);
    USART_SendData(&usart2_handle, msg, strlen((char*)msg));
    uint8_t msg[] = "ENTER CHAR:\r\n";
    USART_SendData(&usart2_handle, msg, strlen((char*)msg));
    delay();
    USART_ReceiveDataIT(&usart2_handle, rxData, 5);

    while(1)
    {
    }
}
void USART2_IRQHandler(void)
{
    USART_IRQHandling(&usart2_handle);
}

void USART_ApplicationEventCallback(USART_Handle_t *pUSARTHandle, uint8_t ApEv)
{
    if (ApEv == USART_EVENT_RX_CMPLT)
    {
        char msg[] = "Interrupt Trigger\r\n";
        USART_SendData(pUSARTHandle, (uint8_t*)msg, strlen(msg));
        USART_ReceiveDataIT(pUSARTHandle, rxData, 5);
        USART_SendData(&usart2_handle, rxData, 5);
        USART_SendData(pUSARTHandle, (uint8_t*)"\r\n", 2);
    }
}
