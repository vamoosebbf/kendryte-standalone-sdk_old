/* Copyright 2018 Canaan Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <stdio.h>
#include "fpioa.h"
#include <string.h>
#include "board_config.h"
#include "syslog.h"
#include "uart.h"
#include "gpiohs.h"
#include "sysctl.h"

#define RECV_LENTH  4

#define CLOSLIGHT   0x55555555
#define OPENLIGHT   0xAAAAAAAA

#define UART_NUM    UART_DEVICE_3

int release_cmd(char *cmd)
{
    switch(*((int *)cmd)){
        case CLOSLIGHT:
        gpiohs_set_pin(3, GPIO_PV_LOW);
        break;
        case OPENLIGHT:
        gpiohs_set_pin(3, GPIO_PV_HIGH);
        break;
    }
    return 0;
}

void io_mux_init(void)
{

    fpioa_set_function(6, FUNC_UART1_RX + UART_NUM * 2);
    fpioa_set_function(7, FUNC_UART1_TX + UART_NUM * 2);
    fpioa_set_function(24, FUNC_GPIOHS3);
}

int main()
{

    uint32_t freq = 0;
    freq = sysctl_pll_set_freq(SYSCTL_PLL0, 800000000);
    uint64_t core = current_coreid();
    printk(LOG_COLOR_W "-------------------------------\r\n");
    printk(LOG_COLOR_W "Sipeed@QinYUN575\r\n");
    printk(LOG_COLOR_W "Compile@ %s %s\r\n", __DATE__, __TIME__);
    printk(LOG_COLOR_W "Board: " LOG_COLOR_E BOARD_NAME "\r\n");
    printk(LOG_COLOR_W "pll freq: %dhz\r\n", freq);
    printk(LOG_COLOR_W "-------------------------------\r\n");
    
    io_mux_init();
    plic_init();
    sysctl_enable_irq();

    gpiohs_set_drive_mode(3, GPIO_DM_OUTPUT);
    gpio_pin_value_t value = GPIO_PV_HIGH;
    gpiohs_set_pin(3, value);

    uart_init(UART_NUM);
    uart_configure(UART_NUM, 115200, 8, UART_STOP_1, UART_PARITY_NONE);

    char *hel = {"hello world!\n"};
    uart_send_data(UART_NUM, hel, strlen(hel));

    while (1)
    {
        uart_send_data(UART_NUM, hel, strlen(hel));
    }
}

