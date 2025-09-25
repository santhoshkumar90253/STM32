/*
 * STM32Lxx_gpio_header.h
 *
 *  Created on: Sep 11, 2025
 *      Author: HP
 */

#ifndef INC_STM32LXX_GPIO_HEADER_H_
#define INC_STM32LXX_GPIO_HEADER_H_
/**********************************************************************************************************************
 * INCLUDE FILES
**********************************************************************************************************************/
#include"STM32Lxx.H"
/************************************************* END OF INCLUDE FILES **********************************************/

/**********************************************************************************************************************
 * MACROS
 *********************************************************************************************************************/
/* GPIO pin Possible modes */
#define GPIO_MODE_IN            0
#define GPIO_MODE_OUT           1
#define GPIO_MODE_ALTFN         2
#define GPIO_MODE_ANALOG        3
#define GPIO_MODE_IT_FI         4
#define GPIO_MODE_IT_RI         5
#define GPIO_MODE_IT_RFI        6

/* GPIO Pin possible output types */
#define GPIO_OP_TYPE_PP         0
#define GPIO_OP_TYPE_OD         1

/*GPIO Pin possible speeds*/


#define GPIO_SPEED_LOW     0
#define GPIO_SPEED_MEDIUM  1
#define GPIO_SPEED_FAST    2
#define GPIO_SPEED_HIGH    3

/* GPIO Pin Pull Up and Pull Down configuration macros*/

#define GPIO_NO_PUPD   0
#define GPIO_PIN_PU    1
#define GPIO_PIN_PD    2

/* GPIO Pin numbers */

#define GPIO_PIN_NO_0     0
#define GPIO_PIN_NO_1     1
#define GPIO_PIN_NO_2     2
#define GPIO_PIN_NO_3     3
#define GPIO_PIN_NO_4     4
#define GPIO_PIN_NO_5     5
#define GPIO_PIN_NO_6     6
#define GPIO_PIN_NO_7     7
#define GPIO_PIN_NO_8     8
#define GPIO_PIN_NO_9     9
#define GPIO_PIN_NO_10    10
#define GPIO_PIN_NO_11    11
#define GPIO_PIN_NO_12    12
#define GPIO_PIN_NO_13    13
#define GPIO_PIN_NO_14    14
#define GPIO_PIN_NO_15    15
/****************************************************** ENF OF MACROS ************************************************/

/**********************************************************************************************************************
 * ENUMS
 *********************************************************************************************************************/

/****************************************************** END OF ENUM **************************************************/

/**********************************************************************************************************************
 * TYPEDEFS
 *********************************************************************************************************************/
/* Configuration structure for a GPIO pin*/
typedef struct{
    /** Pin number */
    uint8_t GPIO_PinNumber;

    /** Pin mode  */
    uint8_t GPIO_PinMode;

    /** Pin speed (low, medium, high, very high) */
    uint8_t GPIO_PinSpeed;

    /** Pull-up /Pull-down control */
    uint8_t GPIO_PinPuPdControl;

    /** Output type */
    uint8_t GPIO_PinOPType;

    /** Alternate function mode */
    uint8_t GPIO_PinAltFunMode;
} GPIO_PinConfig_t;


/* Handle structure for a GPIO pin */

typedef struct{
    /* Pointer to GPIO port base address*/
	GPIO_RegDef_t *pGPIOx;

    /* GPIO pin configuration settings */
    GPIO_PinConfig_t GPIO_PinConfig;
} GPIO_Handle_t;



/****************************************************** END OF TYPEDEF ***********************************************/

/**********************************************************************************************************************
 * GLOBAL VARIABLES
 *********************************************************************************************************************/

/*************************************************** END OF GLOBAL VARIABLES******************************************/

/**********************************************************************************************************************
 * FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void GPIO_PeriClockControl(GPIO_RegDef_t *GPIOx_p, uint8_t state_u8);         			  // Function to control peripheral clock /
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);                                              // Function to Initialize GPIO Pin
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);                                                 // Function to Deinitialize GPIO Pin
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber_u8);              // Function to read the state of GPIO Pin
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);                                  // Function to read the state of GPIO Port
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber_u8,uint8_t state_u8);// Function to Write the State to GPIO Pin
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint16_t state_u16);                   // Function to Write the State to GPIO Port
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber_u8);                        // Function to Toggle the State to GPIO Pin
void GPIO_IRQITConfig(uint8_t IRQNumber, uint8_t state_u8);                             // Function to IRQ Configuration
void GPIO_IRQHandler(uint8_t pinNumber_u8);                           // Function to IRQ Handling
void GPIO_IRQProrityConfig(uint8_t IRQNumber, uint8_t IRQPriority);                                       // Function to IRQ Priority Configuration

/************************************************** END OF FUNCTION PROTOTYPES ***************************************/


#endif /* INC_STM32LXX_GPIO_HEADER_H_ */
