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
#include <bsp.h>
#include <stdio.h>
#include <sysctl.h>
#include "board_config.h"
#include "syslog.h"

#include "fpioa.h"
#include "uarths.h"
#include "psram.h"
#include "dmac.h"

#define TEST_NUMBER (40 * 1024 + 5)
#define DATA_ADDRESS 0xB00000

uint8_t data_buf[TEST_NUMBER];

static const char *TAG = "main";

int core1_function(void *ctx)
{
    uint64_t core = current_coreid();
    LOGI(TAG, "Core %ld Hello world", core);
    while(1)
        ;
}

void spi_io_mux_init(void)
{
    fpioa_set_function(SPI_PSRAM_CS_PIN_NUM,    FUNC_SPI0_SS0);   // CS
    fpioa_set_function(SPI_PSRAM_SCK_PIN_NUM,   FUNC_SPI0_SCLK); // SCLK
    fpioa_set_function(SPI_PSRAM_MOSI_PIN_NUM,  FUNC_SPI0_D0);  // MOSI
    fpioa_set_function(SPI_PSRAM_MISO_PIN_NUM,  FUNC_SPI0_D1);  // MISO

    fpioa_set_function(SPI_PSRAM_D2_PIN_NUM,    FUNC_SPI0_D2); // D2
    fpioa_set_function(SPI_PSRAM_D3_PIN_NUM,    FUNC_SPI0_D3); // D3
}


#include "iomem.h"

int main(void)
{
    uint32_t freq = 0;
    freq = sysctl_pll_set_freq(SYSCTL_PLL0, 800000000);
    uint64_t core = current_coreid();
    int data;
    printk(LOG_COLOR_W "-------------------------------\r\n");
    printk(LOG_COLOR_W "Sipeed@QinYUN575\r\n");
    printk(LOG_COLOR_W "Compile@ %s %s\r\n", __DATE__, __TIME__);
    printk(LOG_COLOR_W "Board: " LOG_COLOR_E BOARD_NAME "\r\n");
    printk(LOG_COLOR_W "pll freq: %dhz\r\n", freq);
    printk(LOG_COLOR_W "-------------------------------\r\n");

    spi_io_mux_init();
    uint8_t *a = malloc(10);

    uint8_t *b = malloc(1000000);
    memset(b, 0, 1000000);
    mb();
    printf("a+2: %p\r\n", a+2);
    printf("a+2: %d\r\n", (((uint32_t *)(a+2))[0]));

    extern __thread char _tdata_begin, _tdata_end, _tbss_end;

    size_t tdata_size = &_tdata_end - &_tdata_begin;


    size_t tbss_size = &_tbss_end - &_tdata_end;


    printf("%d\r\n", _tdata_begin);

    spi_flash_psram_test();

    printk(LOG_COLOR_W "-------------END---------------\r\n");
    return 0;
}

// a+2: 0x80026c92
// a+2: 0
// 255