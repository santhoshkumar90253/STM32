/*
 * STM32Lxx_LCD_header.h
 *
 *  Created on: Sep 24, 2025
 *      Author: HP
 */

#ifndef INC_STM32LXX_RTC_HEADER_H_
#define INC_STM32LXX_RTC_HEADER_H_
/**********************************************************************************************************************
 * INCLUDE FILES
**********************************************************************************************************************/
#include"STM32Lxx.h"
#include"STM32Lxx_I2Cx_header.h"
#include"STM32Lxx_gpio_header.h"
/************************************************* END OF INCLUDE FILES **********************************************/

/**********************************************************************************************************************
 * MACROS
 *********************************************************************************************************************/
/* RTC Application Configurable Item */

#define  RTC_I2C                       I2C1
#define  RTC_I2C_GPIO_PORT 			   GPIOB
#define  RTC_I2C_SDA_PIN               GPIO_PIN_NO_7
#define  RTC_I2C_SCK_PIN               GPIO_PIN_NO_6
#define  RTC_I2C_SPEED                 I2C_SCL_SPEED_SM
#define  RTC_I2C_PUPD                  GPIO_NO_PUPD

/* RTC Register Address */

#define RTC_ADDR_SEC                    0x00
#define RTC_ADDR_MIN                    0x01
#define RTC_ADDR_HRS                    0x02
#define RTC_ADDR_DAY                    0x03
#define RTC_ADDR_DATE                   0x04
#define RTC_ADDR_MONTH                  0x05
#define RTC_ADDR_YEAR                   0x06

/* RTC Time Format */

#define RTC_TIME_FORMAT_12HRS_AM        0
#define RTC_TIME_FORMAT_12HRS_PM        1
#define RTC_TIME_FORMAT_24HRS           2

/* I2C Address */
#define RTC_I2C_ADDRESS                 0x68

/* Days in a Week */
#define SUNDAY                          1
#define MONDAY                          2
#define TUESDAY                         3
#define WEDNESDAY                       4
#define THURSDAY                        5
#define FRIDAY                          6
#define SATURDAY                        7

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
	uint8_t date;
	uint8_t month;
	uint8_t year;
	uint8_t day;

}RTC_date_t;

typedef struct
{
	uint8_t second;
	uint8_t minutes;
	uint8_t hours;
	uint8_t timeFormat;

}RTC_time_t;

/****************************************************** END OF TYPEDEF ***********************************************/

/**********************************************************************************************************************
 * GLOBAL VARIABLES
 *********************************************************************************************************************/

/*************************************************** END OF GLOBAL VARIABLES******************************************/

/**********************************************************************************************************************
 * FUNCTION PROTOTYPES
 *********************************************************************************************************************/
uint8_t RTC_init(void);
void RTC_setCurrentTime(RTC_time_t*);
void RTC_getCurrentTime(RTC_time_t*);
void RTC_setCurrentDate(RTC_date_t*);
void RTC_getCurrentDate(RTC_date_t*);

/************************************************** END OF FUNCTION PROTOTYPES ***************************************/


#endif /* INC_STM32LXX_RTC_HEADER_H_ */
