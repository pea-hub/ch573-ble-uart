################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/015"}
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/pea/Desktop/À¶ÑÀÄ£¿éEVT202303132212/EVT/EXAM/BLE/HAL/MCU.c \
C:/Users/pea/Desktop/À¶ÑÀÄ£¿éEVT202303132212/EVT/EXAM/BLE/HAL/RTC.c \
C:/Users/pea/Desktop/À¶ÑÀÄ£¿éEVT202303132212/EVT/EXAM/BLE/HAL/SLEEP.c 

OBJS += \
./HAL/MCU.o \
./HAL/RTC.o \
./HAL/SLEEP.o 

C_DEPS += \
./HAL/MCU.d \
./HAL/RTC.d \
./HAL/SLEEP.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/MCU.o: C:/Users/pea/Desktop/À¶ÑÀÄ£¿éEVT202303132212/EVT/EXAM/BLE/HAL/MCU.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\SRC\Startup" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\include" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\BLE\HID_Consumer\Profile\include" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\BLE\HAL\include" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\SRC\Ld" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\BLE\LIB" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\SRC\RVMSIS" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\app_drv_fifo" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
HAL/RTC.o: C:/Users/pea/Desktop/À¶ÑÀÄ£¿éEVT202303132212/EVT/EXAM/BLE/HAL/RTC.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\SRC\Startup" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\include" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\BLE\HID_Consumer\Profile\include" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\BLE\HAL\include" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\SRC\Ld" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\BLE\LIB" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\SRC\RVMSIS" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\app_drv_fifo" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
HAL/SLEEP.o: C:/Users/pea/Desktop/À¶ÑÀÄ£¿éEVT202303132212/EVT/EXAM/BLE/HAL/SLEEP.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\SRC\Startup" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\include" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\BLE\HID_Consumer\Profile\include" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\BLE\HAL\include" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\SRC\Ld" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\BLE\LIB" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\SRC\RVMSIS" -I"C:\Users\pea\Desktop\À¶ÑÀÄ£¿éEVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\app_drv_fifo" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

