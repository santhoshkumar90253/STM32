
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
void I2C1_GPIOInit(void)
{
	GPIO_Handle_t I2Cpins;

	I2Cpins.pGPIOx = GPIOB;
	I2Cpins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	I2Cpins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
	I2Cpins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	I2Cpins.GPIO_PinConfig.GPIO_PinAltFunMode = 4;
	I2Cpins.GPIO_PinConfig.GPIO_PinSpeed      = GPIO_SPEED_FAST;

	I2Cpins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_6; // SCK
	GPIO_Init(&I2Cpins);

	I2Cpins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_7; // SDA
	GPIO_Init(&I2Cpins);
}

void I2C1_Init(void)
{
	I2C1Handle.pI2Cx = I2C1;
	I2C1Handle.I2C_Config.I2C_ACKControl = I2C_ACK_ENABLE;
	I2C1Handle.I2C_Config.I2C_DeviceAddress = I2C_MASTERADDR;

	I2C_Init(&I2C1Handle);
}
void I2C_ApplicationEventCallBack(I2C_Handle_t *pI2CHandle, uint8_t AppEv)
{
    if(AppEv == I2C_EV_TX_CMPLT)
    {
        uint8_t msg1[] = "[I2C] TX Complete Interrupt Triggered\r\n";
        USART_SendData(&usart2_handle, msg1, sizeof(msg1)-1);

        delay();
        // Send data again in interrupt mode
        I2C_MasterTransmitDataIT(pI2CHandle, I2C_txData, sizeof(I2C_txData)-1, I2C_SLAVEADDR, 0);


    }
    else if(AppEv == I2C_ERROR_AF)
    {
        uint8_t msg2[] = "[I2C] NACK Received (AF Error)\r\n";
        USART_SendData(&usart2_handle, msg2, sizeof(msg2)-1);
    }
}
/*I2C*/
int main(void)
{
	I2C_PeriClockControl(I2C1, ENABLE);
	I2C1_GPIOInit();
	I2C1_Init();
	I2C_PeripheralControl(I2C1, ENABLE);
    while(1)
    {
    	I2C_MasterTransmitData(&I2C1Handle, I2C_txData, sizeof(I2C_txData)-1, I2C_SLAVEADDR, 0);
    	delay();
    }
}
/*
// I2C Interrutp main
int main(void)
{
    // Initialize USART2 for debugging messages
    USART2_GPIOInits();
    USART2_Init();
    USART_PeripheralControl(USART2, ENABLE);

    uint8_t start_msg[] = "Starting I2C Transmission via Interrupts...\r\n";
    USART_SendData(&usart2_handle, start_msg, sizeof(start_msg)-1);

    // Initialize I2C1
    I2C_PeriClockControl(I2C1, ENABLE);
    I2C1_GPIOInits();
    I2C1_Inits();
    I2C_PeripheralControl(I2C1, ENABLE);

    // Enable I2C interrupts (event + error)
    I2C_IRQInterruptConfig(IRQ_NO_I2C1_EV, ENABLE);
    I2C_IRQInterruptConfig(IRQ_NO_I2C1_ER, ENABLE);

    // Start sending data via I2C (interrupt mode)
    I2C_MasterSendDataIT(&I2C1Handle, some_data, sizeof(some_data)-1, SLAVE_ADDR, 0);

    while(1)
    {
        // Infinite loop - main work is done in interrupts
    }
}
*/
// ------------------- IRQ Handlers -------------------
void I2C1_EV_IRQHandler(void)
{
    I2C_EV_IRQHandling(&I2C1Handle); // Handle I2C event interrupt
}

void I2C1_ER_IRQHandler(void)
{
    I2C_ER_IRQHandling(&I2C1Handle); // Handle I2C error interrupt
}
