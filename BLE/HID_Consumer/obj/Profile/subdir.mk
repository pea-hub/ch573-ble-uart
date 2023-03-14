################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/015"}
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Profile/battservice.c \
../Profile/devinfoservice.c \
../Profile/gattprofile.c \
../Profile/hidconsumerservice.c \
../Profile/hiddev.c \
../Profile/scanparamservice.c 

OBJS += \
./Profile/battservice.o \
./Profile/devinfoservice.o \
./Profile/gattprofile.o \
./Profile/hidconsumerservice.o \
./Profile/hiddev.o \
./Profile/scanparamservice.o 

C_DEPS += \
./Profile/battservice.d \
./Profile/devinfoservice.d \
./Profile/gattprofile.d \
./Profile/hidconsumerservice.d \
./Profile/hiddev.d \
./Profile/scanparamservice.d 


# Each subdirectory must supply rules for building sources it contributes
Profile/%.o: ../Profile/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\SRC\Startup" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\include" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\BLE\HID_Consumer\Profile\include" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\BLE\HAL\include" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\SRC\Ld" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\BLE\LIB" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\SRC\RVMSIS" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\app_drv_fifo" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

