################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/system_stm32f4xx.c \
../src/tm_stm32f4_adc.c \
../src/tm_stm32f4_delay.c \
../src/tm_stm32f4_gpio.c \
../src/tm_stm32f4_hd44780.c \
../src/tm_stm32f4_pwm.c \
../src/tm_stm32f4_timer_properties.c 

OBJS += \
./src/main.o \
./src/system_stm32f4xx.o \
./src/tm_stm32f4_adc.o \
./src/tm_stm32f4_delay.o \
./src/tm_stm32f4_gpio.o \
./src/tm_stm32f4_hd44780.o \
./src/tm_stm32f4_pwm.o \
./src/tm_stm32f4_timer_properties.o 

C_DEPS += \
./src/main.d \
./src/system_stm32f4xx.d \
./src/tm_stm32f4_adc.d \
./src/tm_stm32f4_delay.d \
./src/tm_stm32f4_gpio.d \
./src/tm_stm32f4_hd44780.d \
./src/tm_stm32f4_pwm.d \
./src/tm_stm32f4_timer_properties.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F407VGTx -DSTM32F4 -DSTM32F4DISCOVERY -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F40XX -DSTM32F40_41xxx -I"/home/nima/MechatronicsClass/proj2/inc" -I"/home/nima/MechatronicsClass/proj2/CMSIS/core" -I"/home/nima/MechatronicsClass/proj2/CMSIS/device" -I"/home/nima/MechatronicsClass/proj2/Utilities" -I"/home/nima/MechatronicsClass/proj2/StdPeriph_Driver/inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


