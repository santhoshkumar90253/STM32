################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/src/LCD.c \
../drivers/src/RTC.c \
../drivers/src/stm32L4xx_gpio_driver.c \
../drivers/src/stm32lxx_I2C_Driver.c \
../drivers/src/stm32lxx_USART_Driver.c 

OBJS += \
./drivers/src/LCD.o \
./drivers/src/RTC.o \
./drivers/src/stm32L4xx_gpio_driver.o \
./drivers/src/stm32lxx_I2C_Driver.o \
./drivers/src/stm32lxx_USART_Driver.o 

C_DEPS += \
./drivers/src/LCD.d \
./drivers/src/RTC.d \
./drivers/src/stm32L4xx_gpio_driver.d \
./drivers/src/stm32lxx_I2C_Driver.d \
./drivers/src/stm32lxx_USART_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/src/%.o drivers/src/%.su drivers/src/%.cyclo: ../drivers/src/%.c drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DNUCLEO_L476RG -DSTM32L476RGTx -c -I"C:/Users/Admin/STM32CubeIDE/workspace_1.19.0/26_16x2I_LCD/drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=hard -mthumb -o "$@"

clean: clean-drivers-2f-src

clean-drivers-2f-src:
	-$(RM) ./drivers/src/LCD.cyclo ./drivers/src/LCD.d ./drivers/src/LCD.o ./drivers/src/LCD.su ./drivers/src/RTC.cyclo ./drivers/src/RTC.d ./drivers/src/RTC.o ./drivers/src/RTC.su ./drivers/src/stm32L4xx_gpio_driver.cyclo ./drivers/src/stm32L4xx_gpio_driver.d ./drivers/src/stm32L4xx_gpio_driver.o ./drivers/src/stm32L4xx_gpio_driver.su ./drivers/src/stm32lxx_I2C_Driver.cyclo ./drivers/src/stm32lxx_I2C_Driver.d ./drivers/src/stm32lxx_I2C_Driver.o ./drivers/src/stm32lxx_I2C_Driver.su ./drivers/src/stm32lxx_USART_Driver.cyclo ./drivers/src/stm32lxx_USART_Driver.d ./drivers/src/stm32lxx_USART_Driver.o ./drivers/src/stm32lxx_USART_Driver.su

.PHONY: clean-drivers-2f-src

