################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FatFs/src/drivers/usbh_diskio.c 

OBJS += \
./Middlewares/Third_Party/FatFs/src/drivers/usbh_diskio.o 

C_DEPS += \
./Middlewares/Third_Party/FatFs/src/drivers/usbh_diskio.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FatFs/src/drivers/%.o: ../Middlewares/Third_Party/FatFs/src/drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F407xx -I"/Users/nimaaghli/Documents/Couraea/MechatronicsClass/proj3/Inc" -I"/Users/nimaaghli/Documents/Couraea/MechatronicsClass/proj3/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/Users/nimaaghli/Documents/Couraea/MechatronicsClass/proj3/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/Users/nimaaghli/Documents/Couraea/MechatronicsClass/proj3/Middlewares/Third_Party/FatFs/src/drivers" -I"/Users/nimaaghli/Documents/Couraea/MechatronicsClass/proj3/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"/Users/nimaaghli/Documents/Couraea/MechatronicsClass/proj3/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc" -I"/Users/nimaaghli/Documents/Couraea/MechatronicsClass/proj3/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/Users/nimaaghli/Documents/Couraea/MechatronicsClass/proj3/Middlewares/Third_Party/FatFs/src" -I"/Users/nimaaghli/Documents/Couraea/MechatronicsClass/proj3/Drivers/CMSIS/Include" -I"/Users/nimaaghli/Documents/Couraea/MechatronicsClass/proj3/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


