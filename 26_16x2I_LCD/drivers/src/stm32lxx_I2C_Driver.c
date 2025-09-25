/*
 * STM32Lxx_I2C_Driver.c
 *
 *  Created on: Sep 24, 2025
 *      Author: HP
 */


/**********************************************************************************************************************
 * Include files
**********************************************************************************************************************/
#include"stm32L4xx.h"
#include"STM32Lxx_I2Cx_header.h"
#include"main.h"
/*********************************************** end of Include files ************************************************/

/**********************************************************************************************************************
 * PRAGMAS
**********************************************************************************************************************/

/******************************************** end of PRAGMAs *********************************************************/

/**********************************************************************************************************************
 * Global Variables
**********************************************************************************************************************/
/* Flags used to indicate updated data is received*/


/*************************************** end of Global Variables ****************************************************/

/*********************************************************************************************************************
 * Static Function Prototypes
*********************************************************************************************************************/
static void I2C_MasterHandleRXNEInterrupt(I2C_Handle_t *pI2CHandle );
static void I2C_MasterHandleTXEInterrupt(I2C_Handle_t *pI2CHandle );
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
void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx, uint8_t state)
{
	if( ENABLE == state)
	{
		if(I2C1 == pI2Cx)
		{
			I2C1_PCLK_EN();
		}
		else if(I2C2 == pI2Cx)
		{
			I2C2_PCLK_EN();
		}
		else if(I2C3 == pI2Cx)
		{
			I2C2_PCLK_EN();
		}
		else
		{

		}
	}
	else if(DISABLE == state)
	{
		if(I2C1 == pI2Cx)
		{
			I2C1_PCLK_DI();
		}
		else if(I2C2 == pI2Cx)
		{
			I2C2_PCLK_DI();
		}
		else if(I2C3 == pI2Cx)
		{
			I2C2_PCLK_DI();
		}
		else
		{

		}
	}
	else
	{

	}
}
void I2C_PeripheralControl(I2C_RegDef_t *pI2Cx, uint8_t state)
{

	if(ENABLE == state)
	{
		pI2Cx->CR1 |=(1<<0);
	}
	else if(DISABLE == state)
	{
		pI2Cx->CR1 &= ~(1<<0);
	}
	else
	{

	}

}
void I2C_Init(I2C_Handle_t *pI2CHandle)
{
	uint32_t tempReg = RESET;
	tempReg |= pI2CHandle->I2C_Config.I2C_ACKControl << 15;

	pI2CHandle->pI2Cx->CR2 |= tempReg;

	pI2CHandle->pI2Cx->TIMEINGR |= 0x411313;

	tempReg = pI2CHandle->I2C_Config.I2C_DeviceAddress << 1;
	pI2CHandle->pI2Cx->OAR1 |= tempReg;


}
void I2C_DeInit(I2C_RegDef_t *pI2Cx)
{

}
void I2C_MasterTransmitData(I2C_Handle_t *pI2CHandle, uint8_t* pTxBuffer,uint8_t txBufLen,uint8_t slaveAddr,uint8_t Sr)
{
	uint32_t cr2 = RESET;
	while (((pI2CHandle->pI2Cx->ISR >> 15) & 1));
	pI2CHandle->pI2Cx->CR2 |= (slaveAddr << 1) | (txBufLen << 16);

	if (I2C_SR_DISABLE == Sr )
	{
		cr2 |= (1 << 25);
	}
	pI2CHandle->pI2Cx->CR2 |= cr2;

	I2C_GenerateStartCondition(pI2CHandle->pI2Cx);

	while (txBufLen > 0)
	{
		while (!(pI2CHandle->pI2Cx->ISR & (1 << 0)));

		pI2CHandle->pI2Cx->TXDR = *pTxBuffer;

		pTxBuffer++;
		txBufLen--;
	}

	if (I2C_SR_DISABLE == Sr )
	{
		while (!(pI2CHandle->pI2Cx->ISR & (1 << 5)));

		pI2CHandle->pI2Cx->ICR |= (1 << 5);
	}
	else
	{

		while (!(pI2CHandle->pI2Cx->ISR & (1 << 6)));
	}
}
void I2C_MasterReceiveData(I2C_Handle_t *pI2CHandle, uint8_t* pRxBuffer,uint8_t rxBufLen,uint8_t slaveAddr,uint8_t Sr)
{
	uint32_t cr2 = RESET;
	while (((pI2CHandle->pI2Cx->ISR >> 15) & 1) == 0);

	cr2 |= (slaveAddr << 1);
	cr2 |= (rxBufLen << 16);
	cr2 |= (0 << 10);

	if (I2C_SR_DISABLE == Sr )
	{
		cr2 |= (1 << 25);
	}

	pI2CHandle->pI2Cx->CR2 |= cr2;

	I2C_GenerateStartCondition(pI2CHandle->pI2Cx);

	while (rxBufLen > 0)
	{
		while (!(pI2CHandle->pI2Cx->ISR & (1 << 2)));

		*pRxBuffer = (uint8_t)pI2CHandle->pI2Cx->RXDR;

		pRxBuffer++;
		rxBufLen--;
	}

	if (I2C_SR_DISABLE == Sr )
	{
		while (!(pI2CHandle->pI2Cx->ISR & (1 << 5)));

		pI2CHandle->pI2Cx->ICR |= (1 << 5);
	}
	else
	{
		while (!(pI2CHandle->pI2Cx->ISR & (1 << 6)));
	}
}


uint8_t  I2C_MasterTransmitDataIT(I2C_Handle_t *pI2CHandle, uint8_t* pTxBuffer,uint8_t txBufLen,uint8_t SlaveAddr,uint8_t Sr)
{
	uint8_t busyState = pI2CHandle->txRxState;

	if((busyState != I2C_BUSY_IN_TX) && (busyState != I2C_BUSY_IN_RX))
	{

		pI2CHandle->pTxBuffer = pTxBuffer;
		pI2CHandle->txBufLen  = txBufLen;
		pI2CHandle->txRxState = I2C_BUSY_IN_TX;
		pI2CHandle->devAddr   = SlaveAddr;
		pI2CHandle->startRepeat        = Sr;


		while( (pI2CHandle->pI2Cx->ISR & (1U << 15)) != 0 );


		uint32_t tempBuf = pI2CHandle->pI2Cx->CR2;
		tempBuf &= ~((0x3FFU << 0) | (0xFFU << 16) | (1U<<24) | (1U<<25) | (1U<<10)); /* clear SADD, NBYTES, RELOAD, AUTOEND, RD_WRN */
		tempBuf |= ((uint32_t)(SlaveAddr & 0x3FFU) << 1);
		tempBuf |= ((txBufLen & 0xFFU) << 16);
		if(  I2C_SR_DISABLE == Sr)
		{
			tempBuf |= (1U << 25);
		}
		pI2CHandle->pI2Cx->CR2 = tempBuf;


		pI2CHandle->pI2Cx->CR2 |= (1U << 13);
		pI2CHandle->pI2Cx->CR1 |= (1U << I2C_CR1_TXIE) | (1U << I2C_CR1_ERRIE) | (1U << I2C_CR1_STOPIE);
	}

	return busyState;
}
uint8_t I2C_MasterReceiveDataIT(I2C_Handle_t *pI2CHandle, uint8_t* pRxBuffer,uint8_t rxBufLen,uint8_t slaveAddr,uint8_t Sr)
{
	 uint8_t busyState = pI2CHandle->txRxState;

	if((busyState != I2C_BUSY_IN_TX) && (busyState != I2C_BUSY_IN_RX))
	{

		pI2CHandle->pRxBuffer = pRxBuffer;
		pI2CHandle->rxBufLen     = rxBufLen;
		pI2CHandle->txRxState = I2C_BUSY_IN_RX;
		pI2CHandle->rxBufSize    = rxBufLen;
		pI2CHandle->devAddr   = slaveAddr;
		pI2CHandle->startRepeat        = Sr;

		pI2CHandle->pI2Cx->CR2  = 0;
		pI2CHandle->pI2Cx->CR2 |= (slaveAddr << 1);
		pI2CHandle->pI2Cx->CR2 |= (rxBufLen << 16);
		pI2CHandle->pI2Cx->CR2 |= (1 << 10);
		pI2CHandle->pI2Cx->CR2 |= (1 << 13);
		if (Sr == 0) pI2CHandle->pI2Cx->CR2 |= (1 << 25);

		pI2CHandle->pI2Cx->CR1 |= ((1<<1) | (1<<6) | (1<<7));
	}

	return busyState;
}
void I2C_CloseTransmitData(I2C_Handle_t *pI2CHandle)
{
	pI2CHandle->pI2Cx->CR2 &= ~(1 << 1);
	pI2CHandle->pI2Cx->CR2 &= ~(1 << 6);
	pI2CHandle->txRxState = I2C_READY;
	pI2CHandle->pTxBuffer = NULL;
	pI2CHandle->txBufLen  = 0;
}
void I2C_CloseReceiveData(I2C_Handle_t *pI2CHandle)
{
	pI2CHandle->pI2Cx->CR2 &= ~(1 << 1);
	pI2CHandle->pI2Cx->CR2 &= ~(1 << 6);


	pI2CHandle->txRxState = I2C_READY;
	pI2CHandle->pRxBuffer = NULL;
	pI2CHandle->rxBufLen     = 0;
	pI2CHandle->rxBufSize    = 0;

	if(pI2CHandle->I2C_Config.I2C_ACKControl == I2C_ACK_ENABLE)
	I2C_ManageAcking(pI2CHandle->pI2Cx,ENABLE);
}
void I2C_IRQInterruptConfig(uint8_t IRQNumber, uint8_t state)
{
	if(state == ENABLE)
	{
		 if(IRQNumber <= 31)
		{

			*NVIC_ISER0 |= (1 << IRQNumber);
		}
		else if(IRQNumber > 31 && IRQNumber < 64)
		{

			*NVIC_ISER1 |= (1 << (IRQNumber % 32));
		}
		else if(IRQNumber >= 64 && IRQNumber < 96)
		{

			*NVIC_ISER3 |= (1 << (IRQNumber % 64));
		}
	}
	else if(state == DISABLE)
	{
		if(IRQNumber <= 31)
		{
			*NVIC_ICER0 |= (1 << IRQNumber);
		}
		else if(IRQNumber > 31 && IRQNumber < 64)
		{
			*NVIC_ICER1 |= (1 << (IRQNumber % 32));
		}
		else if(IRQNumber >= 64 && IRQNumber < 96)
		{
			*NVIC_ICER3 |= (1 << (IRQNumber % 64));
		}
	}
	else
	{

	}
}
void I2C_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{

}
void I2C_EV_IRQHandling(I2C_Handle_t *pI2CHandle)
{
	 uint32_t isr = pI2CHandle->pI2Cx->ISR;
   // uint32_t cr1 = pI2CHandle->pI2Cx->CR1;

	if(isr & (1U << I2C_ISR_ADDR))
	{


		pI2CHandle->pI2Cx->ICR |= (1U << I2C_ICR_ADDRCF);
	}


	if(isr & (1U << I2C_ISR_TXIS))
	{
		if(pI2CHandle->txRxState == I2C_BUSY_IN_TX)
		{
			I2C_MasterHandleTXEInterrupt(pI2CHandle);
		}
	}


	if(isr & (1U << I2C_ISR_RXNE))
	{
		if(pI2CHandle->txRxState == I2C_BUSY_IN_RX)
		{

			*pI2CHandle->pRxBuffer = (uint8_t)pI2CHandle->pI2Cx->RXDR;
			pI2CHandle->pRxBuffer++;
			pI2CHandle->rxBufLen--;

			if(pI2CHandle->rxBufLen == 0)
			{
				I2C_MasterHandleRXNEInterrupt(pI2CHandle );
			}
		}
	}


	if(isr & (1U << I2C_ISR_STOPF))
	{

		pI2CHandle->pI2Cx->ICR |= (1U << I2C_ICR_STOPCF);

		if(pI2CHandle->txRxState == I2C_BUSY_IN_TX)
		{
			I2C_CloseTransmitData(pI2CHandle);
			I2C_ApplicationEventCallBack(pI2CHandle, I2C_EV_TX_CMPLT);
		}
		else if(pI2CHandle->txRxState == I2C_BUSY_IN_RX)
		{
			I2C_CloseReceiveData(pI2CHandle);
			I2C_ApplicationEventCallBack(pI2CHandle, I2C_EV_RX_CMPLT);
		}
	}

}
void I2C_ER_IRQHandling(I2C_Handle_t *pI2CHandle)
{
	uint32_t isr = pI2CHandle->pI2Cx->ISR;
	uint32_t cr1 = pI2CHandle->pI2Cx->CR1;

	if((isr & (1U << 8)) && (cr1 & (1U << 7)))
	{
		pI2CHandle->pI2Cx->ICR |= (1U << 8);
		I2C_ApplicationEventCallBack(pI2CHandle, I2C_ERROR_BERR);
	}

	if((isr & (1U << 9)) && (cr1 & (1U << 7)))
	{
		pI2CHandle->pI2Cx->ICR |= (1U << 9);
		I2C_ApplicationEventCallBack(pI2CHandle, I2C_ERROR_ARLO);
	}

	if((isr & (1U << 10)) && (cr1 & (1U << 7)))
	{
		pI2CHandle->pI2Cx->ICR |= (1U << 10);
		I2C_ApplicationEventCallBack(pI2CHandle, I2C_ERROR_AF);
	}

	if((isr & (1U << 11)) && (cr1 & (1U << 7)))
	{
		pI2CHandle->pI2Cx->ICR |= (1U << 11);
		I2C_ApplicationEventCallBack(pI2CHandle, I2C_ERROR_OVR);
	}

	if((isr & (1U << 12)) && (cr1 & (1U << 7)))
	{
		pI2CHandle->pI2Cx->ICR |= (1U << 12);
		I2C_ApplicationEventCallBack(pI2CHandle, I2C_ERROR_TIMEOUT);
	}
}

void I2C_ManageAcking(I2C_RegDef_t * pI2Cx,uint8_t state)
{
	if(ENABLE == state)
	{
		pI2Cx->CR1 |= (1<< I2C_CR1_ACK);
	}
	else if (DISABLE == state)
	{
		pI2Cx->CR1 &= ~(1<< I2C_CR1_ACK);
	}
}
void I2C_GenerateStartCondition(I2C_RegDef_t * pI2Cx)
{
	pI2Cx->CR2 |= (1<<13);
}
void I2C_GenerateStopCondition(I2C_RegDef_t * pI2Cx)
{
	pI2Cx->CR2 |= (1<<14);
}
static void I2C_MasterHandleRXNEInterrupt(I2C_Handle_t *pI2CHandle )
{
	if(pI2CHandle->rxBufSize == 1)
	{
		*pI2CHandle->pRxBuffer = pI2CHandle->pI2Cx->RXDR;
		pI2CHandle->rxBufLen--;
	}
	else if(pI2CHandle->rxBufSize > 1)
	{
		if(pI2CHandle->rxBufLen == 2) I2C_ManageAcking(pI2CHandle->pI2Cx,DISABLE);

		*pI2CHandle->pRxBuffer = pI2CHandle->pI2Cx->RXDR;
		pI2CHandle->pRxBuffer++;
		pI2CHandle->rxBufLen--;
	}

	if(pI2CHandle->rxBufLen == 0)
	{
		if(pI2CHandle->startRepeat == I2C_SR_DISABLE)
		{
			I2C_GenerateStopCondition(pI2CHandle->pI2Cx);
		}

		I2C_CloseReceiveData(pI2CHandle);
		I2C_ApplicationEventCallBack(pI2CHandle,I2C_EV_RX_CMPLT);
	}
}
static void I2C_MasterHandleTXEInterrupt(I2C_Handle_t *pI2CHandle )
{
	if(pI2CHandle->txBufLen > 0)
	{
		pI2CHandle->pI2Cx->TXDR = *(pI2CHandle->pTxBuffer);
		pI2CHandle->pTxBuffer++;
		pI2CHandle->txBufLen--;
	}
	else
	{

	}
}
void I2C_BurstWrite(I2C_Handle_t *pI2CHandle, uint8_t slaveAddr, uint8_t regAddr, uint8_t *pData, uint32_t len)
{

    uint8_t *buffer = malloc(len + 1);
    if (!buffer)
    	return;

    buffer[0] = regAddr;
    memcpy(&buffer[1], pData, len);


    I2C_MasterTransmitData(pI2CHandle, buffer, len + 1, slaveAddr, I2C_SR_DISABLE);

    free(buffer);
}
uint8_t I2C_BurstWriteIT(I2C_Handle_t *pI2CHandle, uint8_t SlaveAddr, uint8_t RegAddr, uint8_t *pData, uint32_t Len)
{
    uint8_t *buffer = malloc(Len + 1);
    if (!buffer)
    	return 1;

    buffer[0] = RegAddr;
    memcpy(&buffer[1], pData, Len);

    uint8_t status = I2C_MasterTransmitDataIT(pI2CHandle, buffer, Len + 1, SlaveAddr, I2C_SR_DISABLE);


    return status;
}



void I2C_BurstRead(I2C_Handle_t *pI2CHandle, uint8_t SlaveAddr, uint8_t RegAddr, uint8_t *pBuffer, uint32_t Len)
{
	I2C_MasterTransmitData(pI2CHandle, &RegAddr, 1, SlaveAddr, I2C_SR_ENABLE);
	I2C_MasterReceiveData(pI2CHandle, pBuffer, Len, SlaveAddr, I2C_SR_DISABLE);
}

uint8_t I2C_BurstReadIT(I2C_Handle_t *pI2CHandle, uint8_t SlaveAddr, uint8_t RegAddr, uint8_t *pBuffer, uint32_t Len)
{
    uint8_t status = I2C_MasterTransmitDataIT(pI2CHandle, &RegAddr, 1, SlaveAddr, I2C_SR_ENABLE);
    return status;
}

/*static void I2C_ExecuteAddressPhaseWrite(I2C_RegDef_t *pI2Cx, uint8_t SlaveAddr)
{
	pI2Cx->CR2 &= ~(0x3FFU << 0);
	pI2Cx->CR2 |= ((uint32_t)SlaveAddr << 1) & (0x3FFU << 0);
	pI2Cx->CR2 &= ~(1U << 10);
}


static void I2C_ExecuteAddressPhaseRead(I2C_RegDef_t *pI2Cx, uint8_t SlaveAddr)
{
    pI2Cx->CR2 &= ~(0x3FFU << 0);
    pI2Cx->CR2 |= ((uint32_t)SlaveAddr << 1) & (0x3FFU << 0);
    pI2Cx->CR2 |= (1U << 10);
}*/

/************************************************ end of Samples_APP.c ***************************************************/
