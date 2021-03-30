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
#include "dmac.h"
#include "fpioa.h"
#include "psram.h"
#include "spi.h"
#include "sysctl.h"
#include "syslog.h"
#include "sleep.h"
#include "board_config.h"

static const char *TAG = "PSRAM";


uint32_t spi_bus_no = 0;
uint32_t spi_chip_select = 0;

void dump(uint8_t *data, uint32_t data_len)
{
    uint32_t count = 0;
    printf("-----------------------");
    while(count<data_len)
    {
        if (count %10 == 0){
            printf("\r\n%5d:  ", (count/10));
        }
        printf("%02X\t", data[count++]);
    }
    printf("\r\n-----------------------\r\n");
}

static psram_status_t psram_quad_reveive_data(uint32_t *cmd_buff, uint8_t cmd_len, uint8_t *rx_buff, uint32_t rx_len)
{
    spi_init_non_standard(spi_bus_no, 8,
                        24 /*address length*/,
                        6 /*wait cycles*/,
                        SPI_AITM_AS_FRAME_FORMAT /*spi address trans mode*/);
    spi_receive_data_multiple(spi_bus_no, spi_chip_select, cmd_buff, cmd_len, rx_buff, rx_len);
    return PSRAM_OK;
}

static psram_status_t psram_quad_send_data(uint32_t *cmd_buff, uint8_t cmd_len, uint8_t *tx_buff, uint32_t tx_len)
{
    spi_init_non_standard(spi_bus_no, 8,
                        24 /*address length*/,
                        0 /*wait cycles*/,
                        SPI_AITM_AS_FRAME_FORMAT /*spi address trans mode*/);

    spi_send_data_multiple(spi_bus_no, spi_chip_select, cmd_buff, cmd_len, tx_buff, tx_len);
    return PSRAM_OK;
}

static void psram_receive_data(uint8_t *cmd_buff, uint8_t cmd_len, uint8_t *rx_buff, uint32_t rx_len)
{
    spi_receive_data_standard(spi_bus_no, spi_chip_select, cmd_buff, cmd_len, rx_buff, rx_len);
}

static void psram_send_data(uint8_t *cmd_buff, uint8_t cmd_len, uint8_t *tx_buff, uint32_t tx_len)
{
    spi_send_data_standard(spi_bus_no, spi_chip_select, cmd_buff, cmd_len, tx_buff, tx_len);
}


psram_status_t psram_init(uint8_t spi_index, uint8_t spi_ss)
{
    spi_bus_no = spi_index;
    spi_chip_select = spi_ss;

    spi_init(spi_bus_no, SPI_WORK_MODE_0, SPI_FF_STANDARD, DATALENGTH, 0);
    uint32_t ret = spi_set_clk_rate(spi_bus_no,  30*1000*1000);//10Mhz
    LOGI(TAG, "spi clk is %d\r\n", ret);
    return PSRAM_OK;
}

//exit QPI mode(set back to SPI mode)
void psram_disable_quad_mode(void)
{
    printf("[%d|%s]\r\n", __LINE__, __FUNCTION__);
    uint32_t cmd[2];// 最少两条
    cmd[0] = PSRAM_EXIT_QMODE;

    spi_init(spi_bus_no, SPI_WORK_MODE_0, SPI_FF_QUAD, DATALENGTH, 0);
    psram_quad_send_data(cmd,2, NULL, 0);

    spi_init(spi_bus_no, SPI_WORK_MODE_0, SPI_FF_STANDARD, DATALENGTH, 0);
}

void psram_enable_quad_mode(void)
{
    printf("[%d|%s]\r\n", __LINE__, __FUNCTION__);
    uint8_t cmd[4];
    cmd[0] = PSRAM_ENTER_QMODE;

    spi_init(spi_bus_no, SPI_WORK_MODE_0, SPI_FF_STANDARD, DATALENGTH, 0);
    psram_send_data(cmd, sizeof(cmd), NULL, 0);

    spi_init(spi_bus_no, SPI_WORK_MODE_0, SPI_FF_QUAD, DATALENGTH, 0);

}

//read psram id, should issue `psram_disable_quad_mode` before calling this
psram_status_t psram_read_id(uint64_t *device_id)
{
    uint32_t psram_id[2] = {0};
    uint8_t cmd[4];
    cmd[0] = PSRAM_DEVICE_ID;
    
    psram_receive_data(cmd, sizeof(cmd), psram_id, sizeof(psram_id));
    *device_id = (uint64_t)(((uint64_t)psram_id[1] << 32) | psram_id[0]);

    dump(psram_id, sizeof(psram_id));
    LOGI(TAG, "device_id: 0x%X%X\r\n", psram_id[1], psram_id[0]);

    return PSRAM_OK;
}


void spi_user_psram_write(uint32_t address, uint32_t *data_buffer, uint32_t data_len)
{
    uint32_t cmd = ((address & 0x7fffff) << 8) | (PSRAM_WRITE);
    psram_send_data(&cmd, sizeof(cmd), data_buffer, data_len);
}

void spi_user_psram_read(uint32_t address, uint32_t *data_buffer, uint32_t data_len)
{
    uint32_t cmd =  ((address & 0x7fffff) << 8) | (PSRAM_READ);
    psram_receive_data(&cmd, sizeof(cmd), data_buffer, data_len);
}

void spi_user_psram_write_q(uint32_t address, uint32_t *data_buffer, uint32_t data_len)
{
    uint32_t cmd[2];
    cmd[0] = ((address & 0x7fffff) << 8) | (PSRAM_QUAD_WRITE);
    psram_quad_send_data(cmd, 2, data_buffer, data_len);
}

void spi_user_psram_read_q(uint32_t address, uint32_t *data_buffer, uint32_t data_len)
{
    uint32_t cmd[2];
    cmd[0] = ((address & 0x7fffff) << 8) | (PSRAM_FAST_READ_QUAD);
    psram_quad_reveive_data(cmd, 2, data_buffer, data_len);
}


uint8_t txBuf[] = "ffbbbbaaaa!!!";
#define SIZE sizeof(txBuf)
uint8_t RxBuf[SIZE];

int spi_flash_psram_test(void)
{
    LOGI(TAG, "spi%d master test\r\n", SPI_INDEX);

    psram_init(SPI_INDEX, SPI_CHIP_SELECT_NSS);
    
    uint64_t device_id;
    psram_disable_quad_mode();

    psram_read_id(&device_id);
    if (!PSRAM_IS_VALID(device_id)) {
        LOGE(TAG, "PSRAM_IS_INVALID\r\n");
        return -1;
    }
    else
    {
        printf("PSRAM IS VALID!\r\n");
        switch (PSRAM_SIZE_ID(device_id))
        {
        case PSRAM_EID_SIZE_16MBITS://2MB
            printf("PSRAM_EID_SIZE_16MBITS\r\n");
            break;

        case PSRAM_EID_SIZE_32MBITS://4MB
            printf("PSRAM_EID_SIZE_32MBITS\r\n");
            break;

        case PSRAM_EID_SIZE_64MBITS://8MB
            printf("PSRAM_EID_SIZE_64MBITS\r\n");
            break;
        
        default:
            break;
        }
    }
    psram_enable_quad_mode();
    while(1){
        printf("PSRAM START WRITE\r\n");
        spi_user_psram_write_q(0, txBuf, SIZE);
        printf("PSRAM START READ\r\n");
        spi_user_psram_read_q(0, RxBuf, SIZE);
        RxBuf[SIZE-1] = '\0';
        printf("rxbuf: %s\r\n", RxBuf);
        for(int i = 0; i< sizeof(RxBuf);i++)
        {
            if(txBuf[i] != RxBuf[i])
            {
            printf("READ ERROR\r\n");
            }
        }
    }
}
    
