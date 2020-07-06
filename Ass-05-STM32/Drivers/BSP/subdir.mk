################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/ili9325.c \
../Drivers/BSP/openx07v_c_lcd.c \
../Drivers/BSP/touch_panel.c 

OBJS += \
./Drivers/BSP/ili9325.o \
./Drivers/BSP/openx07v_c_lcd.o \
./Drivers/BSP/touch_panel.o 

C_DEPS += \
./Drivers/BSP/ili9325.d \
./Drivers/BSP/openx07v_c_lcd.d \
./Drivers/BSP/touch_panel.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/%.o: ../Drivers/BSP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F407xx -I"C:/Users/benja/Documents/year2/sem1/elec2720/ELEC2720-2019s1-Ass-05-Template-v04/Ass-05/Inc" -I"C:/Users/benja/Documents/year2/sem1/elec2720/ELEC2720-2019s1-Ass-05-Template-v04/Ass-05/Drivers/BSP" -I"C:/Users/benja/Documents/year2/sem1/elec2720/ELEC2720-2019s1-Ass-05-Template-v04/Ass-05/Drivers/Fonts" -I"C:/Users/benja/Documents/year2/sem1/elec2720/ELEC2720-2019s1-Ass-05-Template-v04/Ass-05/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/benja/Documents/year2/sem1/elec2720/ELEC2720-2019s1-Ass-05-Template-v04/Ass-05/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/benja/Documents/year2/sem1/elec2720/ELEC2720-2019s1-Ass-05-Template-v04/Ass-05/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/benja/Documents/year2/sem1/elec2720/ELEC2720-2019s1-Ass-05-Template-v04/Ass-05/Drivers/CMSIS/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


