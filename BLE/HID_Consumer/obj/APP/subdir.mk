################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/015"}
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/UserCode.c \
../APP/hidconsumer.c \
../APP/hidconsumer_main.c \
../APP/peripheral.c 

OBJS += \
./APP/UserCode.o \
./APP/hidconsumer.o \
./APP/hidconsumer_main.o \
./APP/peripheral.o 

C_DEPS += \
./APP/UserCode.d \
./APP/hidconsumer.d \
./APP/hidconsumer_main.d \
./APP/peripheral.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\Startup" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\Profile\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HAL\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\Ld" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\LIB" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\RVMSIS" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\app_drv_fifo" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

