################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Ass-05-All.c \
../Src/Ass-05-Image.c \
../Src/Ass-05-LCD.c \
../Src/Ass-05-Lib.c \
../Src/Ass-05-Serial.c \
../Src/Ass-05-Touch.c \
../Src/Ass-05.c \
../Src/adc.c \
../Src/dma.c \
../Src/fsmc.c \
../Src/gpio.c \
../Src/main_STM32.c \
../Src/spi.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_it.c \
../Src/syscalls.c \
../Src/system_stm32f4xx.c \
../Src/usart.c 

OBJS += \
./Src/Ass-05-All.o \
./Src/Ass-05-Image.o \
./Src/Ass-05-LCD.o \
./Src/Ass-05-Lib.o \
./Src/Ass-05-Serial.o \
./Src/Ass-05-Touch.o \
./Src/Ass-05.o \
./Src/adc.o \
./Src/dma.o \
./Src/fsmc.o \
./Src/gpio.o \
./Src/main_STM32.o \
./Src/spi.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_it.o \
./Src/syscalls.o \
./Src/system_stm32f4xx.o \
./Src/usart.o 

C_DEPS += \
./Src/Ass-05-All.d \
./Src/Ass-05-Image.d \
./Src/Ass-05-LCD.d \
./Src/Ass-05-Lib.d \
./Src/Ass-05-Serial.d \
./Src/Ass-05-Touch.d \
./Src/Ass-05.d \
./Src/adc.d \
./Src/dma.d \
./Src/fsmc.d \
./Src/gpio.d \
./Src/main_STM32.d \
./Src/spi.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_it.d \
./Src/syscalls.d \
./Src/system_stm32f4xx.d \
./Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F407xx -I"C:/Users/benja/Documents/year2/sem1/elec2720/ELEC2720-2019s1-Ass-05-Template-v04/Ass-05/Inc" -I"C:/Users/benja/Documents/year2/sem1/elec2720/ELEC2720-2019s1-Ass-05-Template-v04/Ass-05/Drivers/BSP" -I"C:/Users/benja/Documents/year2/sem1/elec2720/ELEC2720-2019s1-Ass-05-Template-v04/Ass-05/Drivers/Fonts" -I"C:/Users/benja/Documents/year2/sem1/elec2720/ELEC2720-2019s1-Ass-05-Template-v04/Ass-05/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/benja/Documents/year2/sem1/elec2720/ELEC2720-2019s1-Ass-05-Template-v04/Ass-05/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/benja/Documents/year2/sem1/elec2720/ELEC2720-2019s1-Ass-05-Template-v04/Ass-05/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/benja/Documents/year2/sem1/elec2720/ELEC2720-2019s1-Ass-05-Template-v04/Ass-05/Drivers/CMSIS/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


