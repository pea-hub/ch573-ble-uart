################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
H:/Project/AC_Charging_pile/CH573EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_adc.c \
H:/Project/AC_Charging_pile/CH573EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_clk.c \
H:/Project/AC_Charging_pile/CH573EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_flash.c \
H:/Project/AC_Charging_pile/CH573EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_gpio.c \
H:/Project/AC_Charging_pile/CH573EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_pwr.c \
H:/Project/AC_Charging_pile/CH573EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_sys.c \
H:/Project/AC_Charging_pile/CH573EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_timer0.c \
H:/Project/AC_Charging_pile/CH573EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_uart1.c \
H:/Project/AC_Charging_pile/CH573EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_uart3.c 

OBJS += \
./StdPeriphDriver/CH57x_adc.o \
./StdPeriphDriver/CH57x_clk.o \
./StdPeriphDriver/CH57x_flash.o \
./StdPeriphDriver/CH57x_gpio.o \
./StdPeriphDriver/CH57x_pwr.o \
./StdPeriphDriver/CH57x_sys.o \
./StdPeriphDriver/CH57x_timer0.o \
./StdPeriphDriver/CH57x_uart1.o \
./StdPeriphDriver/CH57x_uart3.o 

C_DEPS += \
./StdPeriphDriver/CH57x_adc.d \
./StdPeriphDriver/CH57x_clk.d \
./StdPeriphDriver/CH57x_flash.d \
./StdPeriphDriver/CH57x_gpio.d \
./StdPeriphDriver/CH57x_pwr.d \
./StdPeriphDriver/CH57x_sys.d \
./StdPeriphDriver/CH57x_timer0.d \
./StdPeriphDriver/CH57x_uart1.d \
./StdPeriphDriver/CH57x_uart3.d 


# Each subdirectory must supply rules for building sources it contributes
StdPeriphDriver/CH57x_adc.o: H:/Project/AC_Charging_pile/CH573EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_adc.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -DCH573 -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\Startup" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\Profile\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\HAL\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\Ld" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\LIB" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\RVMSIS" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\app_drv_fifo" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\ble_uart_service" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_clk.o: H:/Project/AC_Charging_pile/CH573EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_clk.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -DCH573 -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\Startup" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\Profile\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\HAL\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\Ld" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\LIB" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\RVMSIS" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\app_drv_fifo" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\ble_uart_service" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_flash.o: H:/Project/AC_Charging_pile/CH573EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_flash.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -DCH573 -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\Startup" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\Profile\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\HAL\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\Ld" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\LIB" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\RVMSIS" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\app_drv_fifo" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\ble_uart_service" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_gpio.o: H:/Project/AC_Charging_pile/CH573EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_gpio.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -DCH573 -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\Startup" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\Profile\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\HAL\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\Ld" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\LIB" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\RVMSIS" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\app_drv_fifo" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\ble_uart_service" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_pwr.o: H:/Project/AC_Charging_pile/CH573EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_pwr.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -DCH573 -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\Startup" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\Profile\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\HAL\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\Ld" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\LIB" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\RVMSIS" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\app_drv_fifo" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\ble_uart_service" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_sys.o: H:/Project/AC_Charging_pile/CH573EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_sys.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -DCH573 -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\Startup" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\Profile\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\HAL\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\Ld" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\LIB" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\RVMSIS" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\app_drv_fifo" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\ble_uart_service" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_timer0.o: H:/Project/AC_Charging_pile/CH573EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_timer0.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -DCH573 -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\Startup" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\Profile\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\HAL\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\Ld" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\LIB" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\RVMSIS" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\app_drv_fifo" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\ble_uart_service" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_uart1.o: H:/Project/AC_Charging_pile/CH573EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_uart1.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -DCH573 -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\Startup" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\Profile\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\HAL\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\Ld" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\LIB" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\RVMSIS" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\app_drv_fifo" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\ble_uart_service" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_uart3.o: H:/Project/AC_Charging_pile/CH573EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_uart3.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -DCH573 -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\Startup" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\Profile\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\HAL\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\Ld" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\LIB" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\RVMSIS" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\app_drv_fifo" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\ble_uart_service" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

