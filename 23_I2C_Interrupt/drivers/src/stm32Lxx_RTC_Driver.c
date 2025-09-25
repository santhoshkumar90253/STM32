/*
 * STM32Lxx_RTC_Driver.c
 *
 *  Created on: Sep 24, 2025
 *      Author: HP
 */
/**********************************************************************************************************************
 * Include files
**********************************************************************************************************************/
#include "STM32Lxx_RTC_header.h"

/*********************************************** end of Include files ************************************************/

/**********************************************************************************************************************
 * PRAGMAS
**********************************************************************************************************************/

/******************************************** end of PRAGMAs *********************************************************/

/**********************************************************************************************************************
 * Global Variables
**********************************************************************************************************************/
I2C_Handle_t g_RTCI2CHandle;


/*************************************** end of Global Variables ****************************************************/

/*********************************************************************************************************************
 * Static Function Prototypes
*********************************************************************************************************************/
static void RTC_I2CPinConfig(void);
static void RTC_I2CConfig(void);
static void RTC_write(uint8_t value, uint8_t regAddr);
static uint8_t RTC_read(uint8_t regAddr);
static uint8_t RTC_BCDToBinary(uint8_t val);
static uint8_t RTC_BinaryToBCD(uint8_t val);
/***************************************** end of Static Function Prototypes ****************************************/

/*********************************************************************************************************************
 * Function Definitions
*********************************************************************************************************************/

/*********************************************************************************************************************
* Function name      :
* Description        :
*
* Passing Arguments  : None
* Function Called By :
* Return value       : None
*********************************************************************************************************************/


/************************************************ end of Function Definitions ****************************************/
uint8_t RTC_init(void)
{
	RTC_I2CPinConfig();
	RTC_I2CConfig();
	I2C_PeripheralControl(RTC_I2C, ENABLE);

	RTC_write(0x00, RTC_ADDR_SEC);
	uint8_t clockState = RTC_read(RTC_ADDR_SEC);
	return ((clockState>>7)&0x1);
}
void RTC_setCurrentTime(RTC_time_t* rtcTime)
{
	uint8_t seconds =RESET, hrs= RESET;
	seconds = RTC_BinaryToBCD(rtcTime->second);
	seconds &= ~(1<<7);
	RTC_write(seconds, RTC_ADDR_SEC);

	RTC_write(rtcTime->minutes, RTC_ADDR_MIN);

	hrs = RTC_BinaryToBCD(rtcTime->hours);

	if(RTC_TIME_FORMAT_24HRS == rtcTime->timeFormat)
	{
		hrs &= ~(1<<6);
	}
	else
	{
		hrs |= (1<<6);
		hrs  =  RTC_TIME_FORMAT_12HRS_PM ==  rtcTime->timeFormat ?hrs|(1<<5) :hrs&~(1<<5);
	}

	RTC_write(hrs, RTC_ADDR_HRS);

}
void RTC_getCurrentTime(RTC_time_t* rtcTime)
{
	uint8_t seconds =RESET, hrs= RESET;
	seconds = RTC_read(RTC_ADDR_SEC);
	seconds &= (1<<7);

	rtcTime->second = RTC_BCDToBinary(seconds);
	rtcTime->minutes =  RTC_BCDToBinary(RTC_read(RTC_ADDR_MIN));

	hrs = RTC_read(RTC_ADDR_HRS);

	if(hrs &(1<<6))
	{
		rtcTime->timeFormat = !((hrs &(1<<5)) == 0);
		hrs &=~(0x03 << 5);
	}
	else
	{
		rtcTime->timeFormat = RTC_TIME_FORMAT_24HRS;
	}

	rtcTime->hours = RTC_BCDToBinary(hrs);
}

void RTC_setCurrentDate(RTC_date_t* rtcDate)
{
	RTC_write(RTC_BinaryToBCD(rtcDate->date),RTC_ADDR_DATE );
	RTC_write(RTC_BinaryToBCD(rtcDate->month),RTC_ADDR_MONTH );
	RTC_write(RTC_BinaryToBCD(rtcDate->year),RTC_ADDR_YEAR );
	RTC_write(RTC_BinaryToBCD(rtcDate->day),RTC_ADDR_DAY );

}
void RTC_getCurrentDate(RTC_date_t*)
{
}

static void RTC_I2CPinConfig(void)
{
	GPIO_Handle_t i2cSDA = {0},i2cSCK = {0};
	i2cSDA.pGPIOx = RTC_I2C_GPIO_PORT;
	i2cSDA.GPIO_PinConfig.GPIO_PinAltFunMode =4 ;
	i2cSDA.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	i2cSDA.GPIO_PinConfig.GPIO_PinNumber = RTC_I2C_SDA_PIN;
	i2cSDA.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
	i2cSDA.GPIO_PinConfig.GPIO_PinPuPdControl = RTC_I2C_PUPD;
	i2cSDA.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	GPIOB_PCLK_EN();
	GPIO_Init(&i2cSDA);
	i2cSDA.pGPIOx = RTC_I2C_GPIO_PORT;
	i2cSDA.GPIO_PinConfig.GPIO_PinAltFunMode =4 ;
	i2cSDA.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	i2cSDA.GPIO_PinConfig.GPIO_PinNumber = RTC_I2C_SCK_PIN;
	i2cSDA.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
	i2cSDA.GPIO_PinConfig.GPIO_PinPuPdControl = RTC_I2C_PUPD;
	i2cSDA.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	GPIO_Init(&i2cSCK);


}
static void RTC_I2CConfig(void)
{
	g_RTCI2CHandle.pI2Cx = RTC_I2C;
	g_RTCI2CHandle.I2C_Config.I2C_ACKControl = I2C_ACK_ENABLE;
	I2C_Init(&g_RTCI2CHandle);
}
static void RTC_write(uint8_t value, uint8_t regAddr)
{
	uint8_t txBuff[2];
	txBuff[0] = regAddr;
	txBuff[1] = value;
	I2C_MasterTransmitData(&g_RTCI2CHandle, txBuff, 2, RTC_I2C_ADDRESS, 0);

}
static uint8_t RTC_read(uint8_t regAddr)
{
	uint8_t data = RESET;
	I2C_MasterTransmitData(&g_RTCI2CHandle, &regAddr, 1, RTC_I2C_ADDRESS, 0);
	I2C_MasterReceiveData(&g_RTCI2CHandle, &data, 1, RTC_I2C_ADDRESS, 0);
	return data;
}
static uint8_t RTC_BinaryToBCD(uint8_t val)
{
	uint8_t a,b,bcd;
	a = b= bcd = RESET;
	bcd = val;
	while(val)
	{
		a = val / 10;
		b = val % 10;
		bcd = (a << 4 )| b;
	}
	return bcd;
}
static uint8_t RTC_BCDToBinary(uint8_t val)
{
	uint8_t a = RESET,b = RESET;
	a  = (uint8_t) ((val >> 4) *10);
	b  = val & (uint8_t) 0xF;
	return (a+b);
}
/************************************************ end of STM32Lxx_RTC_Driver.c ***************************************************/
