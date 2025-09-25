
#include "main.h"
I2C_Handle_t I2C1Handle;
USART_Handle_t usart2_handle;
uint8_t I2C_txData[] = "Hai.. ESP32";

void delay(void)
{
    for(uint32_t i = 0 ; i < 250000 ; i++);
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
