#include "main.h"

SPI_Handle_t SPI2Handle;
uint8_t data = 15,rdata;



void delay(void)
{
    for(volatile int i = 0; i < 25000; i++);
}
extern  void initialise_monitor_handles(void);


void SPI2_GPIOInits(void)
{
    GPIO_Handle_t SPIPins;
    SPIPins.pGPIOx = GPIOB;
    SPIPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
    SPIPins.GPIO_PinConfig.GPIO_PinAltFunMode = 5;
    SPIPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    SPIPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    SPIPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
    GPIO_PeriClockControl(GPIOB, ENABLE);

    SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;  // NSS
    GPIO_Init(&SPIPins);

    SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;  // SCK
    GPIO_Init(&SPIPins);

    SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;  // MISO
    GPIO_Init(&SPIPins);

    SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;  // MOSI
    GPIO_Init(&SPIPins);
}


void SPI2_InitsMaster(void)
{
    SPI2Handle.pSPIx = SPI2;
    SPI2Handle.SPIConfig.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;
    SPI2Handle.SPIConfig.SPI_BusConfig = SPI_BUS_CONFIG_FD;
    SPI2Handle.SPIConfig.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV32;
    SPI2Handle.SPIConfig.SPI_DFF = SPI_DFF_8BITS;
    SPI2Handle.SPIConfig.SPI_CPOL = SPI_CPOL_LOW;
    SPI2Handle.SPIConfig.SPI_CPHA = SPI_CPHA_LOW;
    SPI2Handle.SPIConfig.SPI_SSM = SPI_SSM_DI;
    SPI_Init(&SPI2Handle);
}
void SPI2_InitSlave(void)
{
    SPI2Handle.pSPIx = SPI2;
    SPI2Handle.SPIConfig.SPI_DeviceMode = SPI_DEVICE_MODE_SLAVE;
    SPI2Handle.SPIConfig.SPI_BusConfig = SPI_BUS_CONFIG_FD;
    SPI2Handle.SPIConfig.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV32;
    SPI2Handle.SPIConfig.SPI_DFF = SPI_DFF_8BITS;
    SPI2Handle.SPIConfig.SPI_CPOL = SPI_CPOL_LOW;
    SPI2Handle.SPIConfig.SPI_CPHA = SPI_CPHA_LOW;
    SPI2Handle.SPIConfig.SPI_SSM = SPI_SSM_DI;
    SPI_Init(&SPI2Handle);
}
// SPI event callback
void SPI_ApplicationEventCallback(SPI_Handle_t *pSPIHandle, uint8_t AppEv)
{
    if(AppEv == SPI_EVENT_TX_CMPLT)                 // TX complete event
    {
        char msg[] = "SPI Transmit Complete!\r\n";
        printf("%s\n",msg);
    }
    else if(SPI_EVENT_RX_CMPLT == AppEv ){
    	char msg[] = "SPI Receive Complete!\r\n";
    	printf("%s\n",msg);
    }
}

// Main function
int main(void)
{
	initialise_monitor_handles();
    SPI2_GPIOInits();
    SPI2_InitsMaster();

    SPI_SSOEConfig(SPI2, ENABLE);
    SPI_PeripheralControl(SPI2, ENABLE);

    SPI_IRQInterruptConfig(IRQ_NO_SPI2, ENABLE);

    SPI_SendDataIT(&SPI2Handle, &data, 1);

    SPI2_InitSlave();
	SPI_SSOEConfig(SPI2, ENABLE);
	SPI_PeripheralControl(SPI2, ENABLE);

	SPI_IRQInterruptConfig(IRQ_NO_SPI2, ENABLE);

    SPI_ReceiveDataIT(&SPI2Handle,&rdata, 1);
    printf("Received Data %d\n",rdata);
    while(1)
    {
        // Wait here, work done in interrupt
    }
}


void SPI2_IRQHandler(void)
{
    const char msg[] = "SPI2 Interrupt generated\r\n";
    printf("%s\n",msg);
    SPI_IRQHandling(&SPI2Handle);
}
