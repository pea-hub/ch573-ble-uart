################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/015"}
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/pea/Desktop/����ģ��EVT202303132212/EVT/EXAM/SRC/StdPeriphDriver/CH57x_adc.c \
C:/Users/pea/Desktop/����ģ��EVT202303132212/EVT/EXAM/SRC/StdPeriphDriver/CH57x_clk.c \
C:/Users/pea/Desktop/����ģ��EVT202303132212/EVT/EXAM/SRC/StdPeriphDriver/CH57x_flash.c \
C:/Users/pea/Desktop/����ģ��EVT202303132212/EVT/EXAM/SRC/StdPeriphDriver/CH57x_gpio.c \
C:/Users/pea/Desktop/����ģ��EVT202303132212/EVT/EXAM/SRC/StdPeriphDriver/CH57x_pwr.c \
C:/Users/pea/Desktop/����ģ��EVT202303132212/EVT/EXAM/SRC/StdPeriphDriver/CH57x_sys.c \
C:/Users/pea/Desktop/����ģ��EVT202303132212/EVT/EXAM/SRC/StdPeriphDriver/CH57x_uart0.c \
C:/Users/pea/Desktop/����ģ��EVT202303132212/EVT/EXAM/SRC/StdPeriphDriver/CH57x_uart1.c 

OBJS += \
./StdPeriphDriver/CH57x_adc.o \
./StdPeriphDriver/CH57x_clk.o \
./StdPeriphDriver/CH57x_flash.o \
./StdPeriphDriver/CH57x_gpio.o \
./StdPeriphDriver/CH57x_pwr.o \
./StdPeriphDriver/CH57x_sys.o \
./StdPeriphDriver/CH57x_uart0.o \
./StdPeriphDriver/CH57x_uart1.o 

C_DEPS += \
./StdPeriphDriver/CH57x_adc.d \
./StdPeriphDriver/CH57x_clk.d \
./StdPeriphDriver/CH57x_flash.d \
./StdPeriphDriver/CH57x_gpio.d \
./StdPeriphDriver/CH57x_pwr.d \
./StdPeriphDriver/CH57x_sys.d \
./StdPeriphDriver/CH57x_uart0.d \
./StdPeriphDriver/CH57x_uart1.d 


# Each subdirectory must supply rules for building sources it contributes
StdPeriphDriver/CH57x_adc.o: C:/Users/pea/Desktop/����ģ��EVT202303132212/EVT/EXAM/SRC/StdPeriphDriver/CH57x_adc.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\Startup" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\Profile\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HAL\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\Ld" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\LIB" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\RVMSIS" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\app_drv_fifo" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_clk.o: C:/Users/pea/Desktop/����ģ��EVT202303132212/EVT/EXAM/SRC/StdPeriphDriver/CH57x_clk.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\Startup" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\Profile\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HAL\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\Ld" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\LIB" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\RVMSIS" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\app_drv_fifo" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_flash.o: C:/Users/pea/Desktop/����ģ��EVT202303132212/EVT/EXAM/SRC/StdPeriphDriver/CH57x_flash.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\Startup" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\Profile\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HAL\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\Ld" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\LIB" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\RVMSIS" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\app_drv_fifo" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_gpio.o: C:/Users/pea/Desktop/����ģ��EVT202303132212/EVT/EXAM/SRC/StdPeriphDriver/CH57x_gpio.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\Startup" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\Profile\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HAL\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\Ld" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\LIB" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\RVMSIS" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\app_drv_fifo" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_pwr.o: C:/Users/pea/Desktop/����ģ��EVT202303132212/EVT/EXAM/SRC/StdPeriphDriver/CH57x_pwr.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\Startup" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\Profile\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HAL\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\Ld" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\LIB" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\RVMSIS" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\app_drv_fifo" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_sys.o: C:/Users/pea/Desktop/����ģ��EVT202303132212/EVT/EXAM/SRC/StdPeriphDriver/CH57x_sys.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\Startup" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\Profile\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HAL\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\Ld" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\LIB" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\RVMSIS" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\app_drv_fifo" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_uart0.o: C:/Users/pea/Desktop/����ģ��EVT202303132212/EVT/EXAM/SRC/StdPeriphDriver/CH57x_uart0.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\Startup" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\Profile\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HAL\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\Ld" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\LIB" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\RVMSIS" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\app_drv_fifo" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_uart1.o: C:/Users/pea/Desktop/����ģ��EVT202303132212/EVT/EXAM/SRC/StdPeriphDriver/CH57x_uart1.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\Startup" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\Profile\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HAL\include" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\Ld" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\LIB" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\SRC\RVMSIS" -I"C:\Users\pea\Desktop\����ģ��EVT202303132212\EVT\EXAM\BLE\HID_Consumer\APP\app_drv_fifo" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

