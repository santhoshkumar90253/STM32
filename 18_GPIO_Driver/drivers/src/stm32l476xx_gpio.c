/*
 * stm32l476xx_gpio.c
 *
 *  Created on: Sep 19, 2025
 *      Author: HP
 */
/**********************************************************************************************************************
 * Include files
**********************************************************************************************************************/
#include"stm32l476xx.h"
#include"stm32l476xx_gpio.h"

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

/***************************************** end of Static Function Prototypes ****************************************/

/*********************************************************************************************************************
 * Function Definitions
*********************************************************************************************************************/

/*********************************************************************************************************************
* Function name      : void GPIO_PeriClockControl(GPIO_RegDef_t *GPIOx_p, uint8_t state_u8)
* Description        : This Function is Enable and Disable peripheral clock
*
*********************************************************************************************************************/
void GPIO_PeriClockControl(GPIO_RegDef_t *GPIOx_p, uint8_t state_u8)
{
	/* Check if the requested state is ENABLE */
	if(ENABLE == state_u8)
	{
	    /* If GPIOx_p points to GPIOA peripheral */
	    if(GPIOA == GPIOx_p)
	    {
	        /* Enable clock for GPIOA */
	        GPIOA_PCLK_EN();
	    }
	    /* Else if GPIOx_p points to GPIOB */
	    else if(GPIOB == GPIOx_p)
	    {
	        /* Enable clock for GPIOB */
	        GPIOB_PCLK_EN();
	    }
	    /* Else if GPIOx_p points to GPIOC */
	    else if(GPIOC == GPIOx_p)
	    {
	        /* Enable clock for GPIOC */
	        GPIOC_PCLK_EN();
	    }
	    /* Else if GPIOx_p points to GPIOD */
	    else if(GPIOD == GPIOx_p)
	    {
	        /* Enable clock for GPIOD */
	        GPIOD_PCLK_EN();
	    }
	    /* Else if GPIOx_p points to GPIOE */
	    else if(GPIOE  == GPIOx_p)
	    {
	        /* Enable clock for GPIOE */
	        GPIOE_PCLK_EN();
	    }
	    /* Else if GPIOx_p points to GPIOF */
	    else if(GPIOF == GPIOx_p)
	    {
	        /* Enable clock for GPIOF */
	        GPIOF_PCLK_EN();
	    }
	    /* Else if GPIOx_p points to GPIOG */
	    else if(GPIOG == GPIOx_p)
	    {
	        /* Enable clock for GPIOG */
	        GPIOG_PCLK_EN();
	    }
	    /* Else if GPIOx_p points to GPIOH */
	    else if(GPIOH == GPIOx_p)
	    {
	        /* Enable clock for GPIOH */
	        GPIOH_PCLK_EN();
	    }
	    /* If GPIOx_p doesn’t match any known GPIO */
	    else
	    {
	        /* Do nothing */
	    }
	}
	/* If requested state is DISABLE */
	else if(DISABLE == state_u8)
	{
	    /* If GPIOx_p points to GPIOA peripheral */
	    if(GPIOA == GPIOx_p)
	    {
	        /* Disable clock for GPIOA */
	        GPIOA_PCLK_DI();
	    }
	    /* Else if GPIOx_p points to GPIOB */
	    else if(GPIOB == GPIOx_p)
	    {
	        /* Disable clock for GPIOB */
	        GPIOB_PCLK_DI();
	    }
	    /* Else if GPIOx_p points to GPIOC */
	    else if(GPIOC == GPIOx_p)
	    {
	        /* Disable clock for GPIOC */
	        GPIOC_PCLK_DI();
	    }
	    /* Else if GPIOx_p points to GPIOD */
	    else if(GPIOD == GPIOx_p)
	    {
	        /* Disable clock for GPIOD */
	        GPIOD_PCLK_DI();
	    }
	    /* Else if GPIOx_p points to GPIOE */
	    else if(GPIOE  == GPIOx_p)
	    {
	        /* Disable clock for GPIOE */
	        GPIOE_PCLK_DI();
	    }
	    /* Else if GPIOx_p points to GPIOF */
	    else if(GPIOF == GPIOx_p)
	    {
	        /* Disable clock for GPIOF */
	        GPIOF_PCLK_DI();
	    }
	    /* Else if GPIOx_p points to GPIOG */
	    else if(GPIOG == GPIOx_p)
	    {
	        /* Disable clock for GPIOG */
	        GPIOG_PCLK_DI();
	    }
	    /* Else if GPIOx_p points to GPIOH */
	    else if(GPIOH == GPIOx_p)
	    {
	        /* Disable clock for GPIOH */
	        GPIOH_PCLK_DI();
	    }
	    /* If GPIOx_p doesn’t match any known GPIO */
	    else
	    {
	        /* Do nothing */
	    }
	}
	/* If state_u8 is neither ENABLE nor DISABLE */
	else
	{
	    /* Do nothing */
	}
}
/*********************************************************************************************************************
* Function name      : void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
* Description        : This Function to initialize the gpio port
*
*********************************************************************************************************************/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	/* Temporary variable used for bit manipulations */
	uint32_t temp =0;

	/* Check if the pin mode is input/output/analog (non-interrupt modes) */
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
	    /* Prepare the mode value: shift mode into correct position for the pin */
	    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode
	            << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

	    /* Clear the two mode bits for this pin in MODER register */
	    pGPIOHandle->pGPIOx->MODER &= ~(0x03 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

	    /* Write the new mode bits for this pin */
	    pGPIOHandle->pGPIOx->MODER |= temp;

	    /* Reset temp variable */
	    temp = 0;
	}
	else
	{
	    /* For interrupt modes: configuration will be handled separately here */
	}

	/* ---------------- Pin Speed Configuration ---------------- */

	/* Reset temp variable */
	temp = 0;

	/* Prepare speed value: shift speed into correct position for the pin */
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed
	        << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

	/* Clear the two speed bits for this pin in OSPEEDR register */
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x03 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

	/* Write the new speed bits */
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;

	/* Reset temp */
	temp = 0;

	/* ---------------- Pull-up / Pull-down Configuration ---------------- */

	/* Prepare pull-up/pull-down config */
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl
	        << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

	/* Clear the two PUPDR bits for this pin */
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x03 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

	/* Write new PUPDR value */
	pGPIOHandle->pGPIOx->PUPDR |= temp;

	/* Reset temp */
	temp = 0;

	/* ---------------- Output Type Configuration ---------------- */

	/* Prepare output type (push-pull or open-drain) */
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType
	        << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

	/* Clear the OTYPER bit for this pin */
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x01 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

	/* Write new OTYPER value */
	pGPIOHandle->pGPIOx->OTYPER |= temp;

	/* Reset temp */
	temp = 0;

	/* ---------------- Alternate Function Configuration ---------------- */

	/* If mode is alternate function */
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
	{
	    /* temp1: index of AFR register (0 = AFR[0] for pins 0–7, 1 = AFR[1] for pins 8–15) */
	    uint32_t temp1, temp2;

	    /* Which AFR register to use */
	    temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;

	    /* Position inside that AFR register */
	    temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;

	    /* Clear the 4 bits for this pin’s alternate function */
	    pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0x0F << (4 * temp2));

	    /* Set the new alternate function mode */
	    pGPIOHandle->pGPIOx->AFR[temp1] |=
	        (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));
	}

}
/*********************************************************************************************************************
* Function name      : void GPIO_DeInit(GPIO_RegDef_t *GPIOx_p)
* Description        : This Function to deinitialize the gpio port
*
*********************************************************************************************************************/
void GPIO_DeInit(GPIO_RegDef_t *GPIOx_p)
{
	/* If the GPIO port is GPIOA */
	if(GPIOA == GPIOx_p)
	{
	    /* Reset GPIOA registers */
	    GPIOA_REG_RESET();
	}
	/* Else if the GPIO port is GPIOB */
	else if(GPIOB == GPIOx_p)
	{
	    /* Reset GPIOB registers */
	    GPIOB_REG_RESET();
	}
	/* Else if the GPIO port is GPIOC */
	else if(GPIOC == GPIOx_p)
	{
	    /* Reset GPIOC registers */
	    GPIOC_REG_RESET();
	}
	/* Else if the GPIO port is GPIOD */
	else if(GPIOD == GPIOx_p)
	{
	    /* Reset GPIOD registers */
	    GPIOD_REG_RESET();
	}
	/* Else if the GPIO port is GPIOE */
	else if(GPIOE  == GPIOx_p)
	{
	    /* Reset GPIOE registers */
	    GPIOE_REG_RESET();
	}
	/* Else if the GPIO port is GPIOF */
	else if(GPIOF == GPIOx_p)
	{
	    /* Reset GPIOF registers */
	    GPIOF_REG_RESET();
	}
	/* Else if the GPIO port is GPIOG */
	else if(GPIOG == GPIOx_p)
	{
	    /* Reset GPIOG registers */
	    GPIOG_REG_RESET();
	}
	/* Else if the GPIO port is GPIOH */
	else if(GPIOH == GPIOx_p)
	{
	    /* Reset GPIOH registers */
	    GPIOH_REG_RESET();
	}
	/* If none of the above GPIO ports match */
	else
	{
	    /* Do nothing */
	}
}
/*********************************************************************************************************************
* Function name      : uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber_u8)
* Description        : This function is to read the status of GPIO pin
*
*********************************************************************************************************************/
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber_u8)
{
	/* Declare an 8-bit variable to hold the pin value */
	uint8_t value;

	/* Read the input data register (IDR).*/
	value = (uint8_t)((pGPIOx->IDR >> pinNumber_u8) & 0x01);

	/* Return the read value (0 or 1) */
	return value;
}
/*********************************************************************************************************************
* Function name      : uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
* Description        : This function is to read the status of GPIO port
*
*********************************************************************************************************************/
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	/* Declare an 8-bit variable to hold the pin value */
	uint8_t value;

	/* Read the input data register (IDR).*/
	value= (uint16_t) ( pGPIOx->IDR );

	/* Return the read value (0 or 1) */
	return value;
}
/*********************************************************************************************************************
* Function name      : void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber_u8,uint8_t state_u8)
* Description        : This function is to write the status for GPIO pin
*
*********************************************************************************************************************/
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber_u8,uint8_t state_u8)
{
	/* Check if the desired state is SET  */
	if(GPIO_PIN_SET == state_u8)
	{
	    /* Set the corresponding bit in the ODR register -> drives pin HIGH */
	    pGPIOx->ODR |= (1 << pinNumber_u8);
	}
	/* Else if the desired state is RESET */
	else if(GPIO_PIN_RESET == state_u8)
	{
	    /* Clear the corresponding bit in the ODR register -> drives pin LOW */
	    pGPIOx->ODR &= ~(1 << pinNumber_u8);
	}
	/* If state is neither SET nor RESET */
	else
	{
	    /* Do nothing (invalid state) */
	}
}
/*********************************************************************************************************************
* Function name      : void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint16_t state_u16)
* Description        : This function is to write the status for GPIO port
*********************************************************************************************************************/
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint16_t state_u16)
{
	/* Write the 16-bit value 'state_u16' directly into the ODR register */
	pGPIOx->ODR = state_u16;
}
/*********************************************************************************************************************
* Function name      : void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber_u8)
* Description        : This function is to toggle the status for GPIO pin
*
*********************************************************************************************************************/
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber_u8)
{
	/* Toggle the given pin by XOR-ing its bit in the ODR register */
	pGPIOx->ODR ^= (1 << pinNumber_u8);
}
/*********************************************************************************************************************
* Function name      : void GPIO_IRQConfig(uint8_t IRQNumber_u8,uint8_t IRQPriority, uint8_t state_u8)
* Description        :
*
*********************************************************************************************************************/
void GPIO_IRQConfig(uint8_t IRQNumber_u8,uint8_t IRQPriority, uint8_t state_u8)
{

}
/*********************************************************************************************************************
* Function name      : void GPIO_IRQHandler(uint8_t pinNumber_u8)
* Description        :
*
*********************************************************************************************************************/
void GPIO_IRQHandler(uint8_t pinNumber_u8)
{

}

/************************************************ end of STM32Lxx_gpio_driver.c ***************************************************/
