/*
 * STM32Lxx_I2Cx_header.h
 *
 *  Created on: Sep 24, 2025
 *      Author: HP
 */

#ifndef INC_STM32LXX_I2CX_HEADER_H_
#define INC_STM32LXX_I2CX_HEADER_H_

/**********************************************************************************************************************
 * INCLUDE FILES
**********************************************************************************************************************/
#include"stm32L4xx.h"
/************************************************* END OF INCLUDE FILES **********************************************/

/**********************************************************************************************************************
 * MACROS
 *********************************************************************************************************************/
/* I2C SCL Speed */
#define I2C_SCL_SPEED_SM                 100000
#define I2C_SCL_SPEED_FM                 400000
#define I2C_SCL_SPEED_FM2K               200000

/* I2C ACK Control  */
#define I2C_ACK_DISABLE                  0
#define I2C_ACK_ENABLE                   1

/* I2C SR Control*/

#define I2C_SR_DISABLE                   0
#define I2C_SR_ENABLE                    1

/* I2C State */
#define I2C_READY                        0
#define I2C_BUSY_IN_RX                   1
#define I2C_BUSY_IN_TX                   2

#define I2C_EV_TX_CMPLT                  0
#define I2C_EV_RX_CMPLT                  1
#define I2C_EV_STOP                 	 2
#define I2C_ERROR_BERR 					 3
#define I2C_ERROR_ARLO 					 4
#define I2C_ERROR_AF   					 5
#define I2C_ERROR_OVR   				 6
#define I2C_ERROR_TIMEOUT 				 7
#define I2C_EV_DATA_REQ   				 8
#define I2C_EV_DATA_RCV   				 9

/****************************************************** ENF OF MACROS ************************************************/

/**********************************************************************************************************************
 * ENUMS
 *********************************************************************************************************************/

/****************************************************** END OF ENUM **************************************************/

/**********************************************************************************************************************
 * TYPEDEFS
 *********************************************************************************************************************/
typedef struct
{
	uint8_t I2C_DeviceAddress;
	uint8_t I2C_ACKControl;
}I2C_Config_t;

typedef struct
{
	I2C_RegDef_t *pI2Cx;
	I2C_Config_t I2C_Config;

	uint8_t *pTxBuffer;
	uint8_t *pRxBuffer;
	uint8_t txBufLen;
	uint8_t rxBufLen;

	uint8_t txRxState;
	uint8_t devAddr;
	uint32_t rxBufSize;
	uint8_t  startRepeat;

}I2C_Handle_t;
/****************************************************** END OF TYPEDEF ***********************************************/

/**********************************************************************************************************************
 * GLOBAL VARIABLES
 *********************************************************************************************************************/

/*************************************************** END OF GLOBAL VARIABLES******************************************/

/**********************************************************************************************************************
 * FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx, uint8_t state);
void I2C_PeripheralControl(I2C_RegDef_t *pI2Cx, uint8_t state);

void I2C_Init(I2C_Handle_t *pI2CHandle);
void I2C_DeInit(I2C_RegDef_t *pI2Cx);

void I2C_MasterTransmitData(I2C_Handle_t *pI2CHandle, uint8_t* pTxBuffer,uint8_t txBufLen,uint8_t SlaveAddr,uint8_t Sr);
void I2C_MasterReceiveData(I2C_Handle_t *pI2CHandle, uint8_t* pRxBuffer,uint8_t rxBufLen,uint8_t SlaveAddr,uint8_t Sr);

uint8_t I2C_MasterTransmitDataIT(I2C_Handle_t *pI2CHandle, uint8_t* pTxBuffer,uint8_t txBufLen,uint8_t SlaveAddr,uint8_t Sr);
uint8_t I2C_MasterReceiveDataIT(I2C_Handle_t *pI2CHandle, uint8_t* pRxBuffer,uint8_t rxBufLen,uint8_t SlaveAddr,uint8_t Sr);

void I2C_CloseTransmitData(I2C_Handle_t *pI2CHandle);
void I2C_CloseReceiveData(I2C_Handle_t *pI2CHandle);

void I2C_IRQInterruptConfig(uint8_t IRQNumber, uint8_t state);
void I2C_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);

void I2C_EV_IRQHandling(I2C_Handle_t *pI2CHandle);
void I2C_ER_IRQHandling(I2C_Handle_t *pI2CHandle);

void I2C_ManageAcking(I2C_RegDef_t * pI2Cx,uint8_t state);

void I2C_GenerateStartCondition(I2C_RegDef_t * pI2Cx);
void I2C_GenerateStopCondition(I2C_RegDef_t * pI2Cx);




uint8_t I2C_BurstWriteIT(I2C_Handle_t *pI2CHandle, uint8_t SlaveAddr, uint8_t RegAddr, uint8_t *pData, uint32_t Len);
void I2C_BurstWrite(I2C_Handle_t *pI2CHandle, uint8_t slaveAddr, uint8_t regAddr, uint8_t *pData, uint32_t len);

void I2C_BurstRead(I2C_Handle_t *pI2CHandle, uint8_t SlaveAddr, uint8_t RegAddr, uint8_t *pBuffer, uint32_t Len);
uint8_t I2C_BurstReadIT(I2C_Handle_t *pI2CHandle, uint8_t SlaveAddr, uint8_t RegAddr, uint8_t *pBuffer, uint32_t Len);


/************************************************** END OF FUNCTION PROTOTYPES ***************************************/

#endif /* INC_STM32LXX_I2CX_HEADER_H_ */
