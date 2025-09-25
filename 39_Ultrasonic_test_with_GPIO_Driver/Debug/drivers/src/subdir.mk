################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/src/stm32l476xx_gpio.c 

OBJS += \
./drivers/src/stm32l476xx_gpio.o 

C_DEPS += \
./drivers/src/stm32l476xx_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/src/%.o drivers/src/%.su drivers/src/%.cyclo: ../drivers/src/%.c drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DNUCLEO_L476RG -DSTM32L476RGTx -c -I"C:/Users/Admin/STM32CubeIDE/workspace_1.19.0/39_Ultrasonic_test_with_GPIO_Driver/drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=hard -mthumb -o "$@"

clean: clean-drivers-2f-src

clean-drivers-2f-src:
	-$(RM) ./drivers/src/stm32l476xx_gpio.cyclo ./drivers/src/stm32l476xx_gpio.d ./drivers/src/stm32l476xx_gpio.o ./drivers/src/stm32l476xx_gpio.su

.PHONY: clean-drivers-2f-src

