################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/ble_uart_service/ble_uart_service_16bit.c 

OBJS += \
./APP/ble_uart_service/ble_uart_service_16bit.o 

C_DEPS += \
./APP/ble_uart_service/ble_uart_service_16bit.d 


# Each subdirectory must supply rules for building sources it contributes
APP/ble_uart_service/%.o: ../APP/ble_uart_service/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -DCH573 -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\Startup" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\Profile\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\HAL\include" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\Ld" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\LIB" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\SRC\RVMSIS" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\app_drv_fifo" -I"H:\Project\AC_Charging_pile\CH573EVT\EVT\EXAM\BLE\BLE_UART\APP\ble_uart_service" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

