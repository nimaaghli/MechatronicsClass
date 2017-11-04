################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc.c \
../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_bot.c \
../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_scsi.c 

OBJS += \
./Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc.o \
./Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_bot.o \
./Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_scsi.o 

C_DEPS += \
./Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc.d \
./Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_bot.d \
./Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_scsi.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/%.o: ../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F407xx -I"/Users/nimaaghli/Documents/Couraea/MechatronicsClass/proj3/Inc" -I"/Users/nimaaghli/Documents/Couraea/MechatronicsClass/proj3/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/Users/nimaaghli/Documents/Couraea/MechatronicsClass/proj3/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/Users/nimaaghli/Documents/Couraea/MechatronicsClass/proj3/Middlewares/Third_Party/FatFs/src/drivers" -I"/Users/nimaaghli/Documents/Couraea/MechatronicsClass/proj3/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"/Users/nimaaghli/Documents/Couraea/MechatronicsClass/proj3/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc" -I"/Users/nimaaghli/Documents/Couraea/MechatronicsClass/proj3/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/Users/nimaaghli/Documents/Couraea/MechatronicsClass/proj3/Middlewares/Third_Party/FatFs/src" -I"/Users/nimaaghli/Documents/Couraea/MechatronicsClass/proj3/Drivers/CMSIS/Include" -I"/Users/nimaaghli/Documents/Couraea/MechatronicsClass/proj3/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


