#include"main.h"

void delay(void);                     // Function prototype for delay
void SPI2_GPIOInits(void);            // Function prototype for SPI2 GPIO setup
extern  void initialise_monitor_handles(void);

// Function to configure GPIO pins for SPI2
void SPI2_GPIOInits(void)
{
    GPIO_Handle_t SPIPins;                              // Handle for GPIO config
    SPIPins.pGPIOx = GPIOB;                             // Use GPIOB port
    SPIPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;     // Alternate function mode
    SPIPins.GPIO_PinConfig.GPIO_PinAltFunMode = 5;             // AF5 = SPI2
    SPIPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;   // Push-pull output
    SPIPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD; // No pull-up/pull-down
    SPIPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;    // High speed output
    GPIO_PeriClockControl(GPIOB, ENABLE);                      // Enable GPIOB clock

    // Configure NSS pin (PB12)
    SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
    GPIO_Init(&SPIPins);

    // Configure SCK pin (PB13)
    SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
    GPIO_Init(&SPIPins);

    // Configure MISO pin (PB14)
    SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
    GPIO_Init(&SPIPins);

    // Configure MOSI pin (PB15)
    SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
    GPIO_Init(&SPIPins);
}


// Function to configure SPI2 peripheral
void SPI2_Inits_master(void)
{
    SPI_Handle_t SPI2Handle;                         // Handle for SPI config
    SPI2Handle.pSPIx = SPI2;                         // Use SPI2 peripheral
    SPI2Handle.SPIConfig.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER; // Set as master
    SPI2Handle.SPIConfig.SPI_BusConfig = SPI_BUS_CONFIG_FD;       // Full-duplex
    SPI2Handle.SPIConfig.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV32;    // Clock speed = PCLK/32
    SPI2Handle.SPIConfig.SPI_DFF = SPI_DFF_8BITS;                 // 8-bit data frame
    SPI2Handle.SPIConfig.SPI_CPOL = SPI_CPOL_LOW;                 // Clock polarity = 0
    SPI2Handle.SPIConfig.SPI_CPHA = SPI_CPHA_LOW;                 // Clock phase = 0
    //SPI2Handle.SPIConfig.SPI_SSM = SPI_SSM_DI;
    SPI2Handle.SPIConfig.SPI_SSM = SPI_SSM_EN;
    SPI_SSIConfig(SPI2, ENABLE);// Hardware NSS management

    SPI_Init(&SPI2Handle);  // Initialize SPI2 with this configuration
}
void SPI2_Inits_Slave(void)
{
    SPI_Handle_t SPI2Handle;                         // Handle for SPI config
    SPI2Handle.pSPIx = SPI2;                         // Use SPI2 peripheral
    SPI2Handle.SPIConfig.SPI_DeviceMode = SPI_DEVICE_MODE_SLAVE; // Set as master
    SPI2Handle.SPIConfig.SPI_BusConfig = SPI_BUS_CONFIG_FD;       // Full-duplex
    SPI2Handle.SPIConfig.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV32;    // Clock speed = PCLK/32
    SPI2Handle.SPIConfig.SPI_DFF = SPI_DFF_8BITS;                 // 8-bit data frame
    SPI2Handle.SPIConfig.SPI_CPOL = SPI_CPOL_LOW;                 // Clock polarity = 0
    SPI2Handle.SPIConfig.SPI_CPHA = SPI_CPHA_LOW;                 // Clock phase = 0
    SPI2Handle.SPIConfig.SPI_SSM = SPI_SSM_DI;                    // Hardware NSS management

    SPI_Init(&SPI2Handle);
}


// SD card chip select
#define SD_CS_PORT GPIOB
#define SD_CS_PIN  GPIO_PIN_NO_12
#define SD_CS_LOW()  GPIO_WriteToOutputPin(SD_CS_PORT, SD_CS_PIN, RESET)
#define SD_CS_HIGH() GPIO_WriteToOutputPin(SD_CS_PORT, SD_CS_PIN, SET)

// ---------------- SD BUFFER ----------------
uint8_t sd_write_buf[512], sd_read_buf[512];

// ---------------- SD CARD FUNCTIONS ----------------
uint8_t SPI2_Transfer(uint8_t data)
{
    uint8_t rx;
    SPI_SendData(SPI2, &data, 1);
    SPI_ReceiveData(SPI2, &rx, 1);
    return rx;
}

void SD_Command(uint8_t cmd, uint32_t arg, uint8_t crc)
{
    SPI2_Transfer(cmd | 0x40);
    SPI2_Transfer(arg >> 24);
    SPI2_Transfer(arg >> 16);
    SPI2_Transfer(arg >> 8);
    SPI2_Transfer(arg);
    SPI2_Transfer(crc);
}

uint8_t SD_WaitR1(void)
{
    uint8_t res;
    for (int i = 0; i < 100; i++)
    {
        res = SPI2_Transfer(0xFF);
        if ((res & 0x80) == 0) return res;
    }
    return 0xFF;
}

void SD_WaitNotBusy(void)
{
    while (SPI2_Transfer(0xFF) != 0xFF);
}

int SD_Init(void)
{
    SD_CS_HIGH();
    for (int i = 0; i < 10; i++) SPI2_Transfer(0xFF);

    SD_CS_LOW();
    SD_Command(0, 0, 0x95);
    if (SD_WaitR1() != 0x01)
    {
        SD_CS_HIGH();
        return -1;
    }
    SD_CS_HIGH();
    SPI2_Transfer(0xFF);
    return 0;
}

int SD_ReadBlock(uint8_t *buf, uint32_t addr)
{
    uint8_t token;
    SD_CS_LOW();
    SD_Command(17, addr, 0xFF);
    if (SD_WaitR1() != 0x00) { SD_CS_HIGH(); return -1; }

    for (int i = 0; i < 1000; i++)
    {
        token = SPI2_Transfer(0xFF);
        if (token == 0xFE) break;
    }
    if (token != 0xFE) { SD_CS_HIGH(); return -2; }

    for (int i = 0; i < 512; i++) buf[i] = SPI2_Transfer(0xFF);
    SPI2_Transfer(0xFF);
    SPI2_Transfer(0xFF);
    SD_CS_HIGH();
    SPI2_Transfer(0xFF);
    return 0;
}

uint8_t SD_WriteBlock(uint8_t *buf, uint32_t addr)
{
    uint8_t response;
    SD_CS_LOW();
    SD_Command(24, addr, 0xFF);
    if (SD_WaitR1() != 0x00) { SD_CS_HIGH(); return 1; }

    SPI2_Transfer(0xFE);
    for (int i = 0; i < 512; i++) SPI2_Transfer(buf[i]);

    SPI2_Transfer(0xFF);
    SPI2_Transfer(0xFF);

    response = SPI2_Transfer(0xFF);
    if ((response & 0x1F) != 0x05) { SD_CS_HIGH(); return 2; }

    SD_WaitNotBusy();
    SD_CS_HIGH();
    SPI2_Transfer(0xFF);
    return 0;
}

// ---------------- MAIN ----------------
int main(void)
{
    // GPIO Button Init (PC13)
    GPIO_Handle_t GPIOBtn;
    memset(&GPIOBtn,0,sizeof(GPIOBtn));
    GPIOBtn.pGPIOx = GPIOC;
    GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
    GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
    GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    GPIO_Init(&GPIOBtn);

    // SPI2 Init
    SPI2_GPIOInits();
    SPI2_Inits_master();
    SPI_SSOEConfig(SPI2, ENABLE);
    SPI_PeripheralControl(SPI2, ENABLE);

    // SD Card Init
    if (SD_Init() != 0)
    {
        while (1); // SD Init Failed
    }

    // Fill write buffer
    for (int i = 0, j = 0; i < 512; i++, j++)
    {
        sd_write_buf[i] = 'A' + (j % 26);
        if (j == 25) j = 0;
    }

    SD_WriteBlock(sd_write_buf, 0x00000000);
    SD_ReadBlock(sd_read_buf, 0x00000000);

    while(1);
}
