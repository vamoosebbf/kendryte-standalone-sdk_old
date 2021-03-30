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
#include <sysctl.h>
#include <sleep.h>
#include <fpioa.h>
#include <gpiohs.h>
#ifndef __CACHE_MEM_H
#define __CACHE_MEM_H

#define _IS_IOMEM(x) (!((uint64_t)(&(x))&0x80000000))
#define _IS_CACHEMEM(x) ((uint64_t)(&(x))&0x80000000)
#define _IS_IOMEMP(x) (!((uint64_t)(x)&0x80000000))
#define _IS_CACHEMEMP(x) ((uint64_t)(x)&0x80000000)

#define _IOMEM(x, type) (*(type *)(((uint64_t)&(x))-0x40000000))
#define _IOMEM_UINT8(x) (*(uint8_t *)(((uint64_t)&(x))-0x40000000))
#define _IOMEM_ADDR(x) (_IS_IOMEM(x)?(uint64_t)(x):(((uint64_t)&(x))-0x40000000))
#define _IOMEM_PADDR(p) (_IS_IOMEMP(p)?(uint64_t)(p):(((uint64_t)(p))-0x40000000))
#define _ADDR(x)	((uint64_t)(x))
#define _IN_BUF(x, buf)	(_ADDR(x)>=_ADDR(buf) && _ADDR(x)<_ADDR(buf)+sizeof(buf))
#define CHECK_IOMEM(x) configASSERT(_IS_IOMEM(x))
#define CHECK_IOMEMP(x) configASSERT(_IS_IOMEMP(x))

#define _CACHE_ADDR(x)                          (_IS_CACHEMEM(x)?(uint64_t)(x):(((uint64_t)&(x))+0x40000000))
#define _CACHE_PADDR(p)                         (_IS_CACHEMEMP(p)?(uint64_t)(p):(((uint64_t)(p))+0x40000000))

#endif /* __CACHE_MEM_H */

int core1_function(void *ctx)
{
    uint64_t core = current_coreid();
    printf("Core %ld Hello world\n", core);
    while(1);
}

 void test(uint8_t *a){
    printf("a+2: %p\r\n", a);
    printf("a+2: %p\r\n", a);
    printf("a+2: %p\r\n", a);
}

void test1(){
    printf("OutHighLevel\r\n");
    msleep(10);
    for(int pin = 0; pin < FPIOA_NUM_IO; pin++){
        fpioa_set_function(pin,    FUNC_GPIOHS0);
        gpiohs_set_drive_mode(0, GPIO_DM_OUTPUT);
        gpiohs_set_pin(0, 1);
    }

    printf("sleep_3s\r\n");
    sleep(3);

    printf("out low level\r\n");
    for(int pin = 0; pin < FPIOA_NUM_IO; pin++){
        fpioa_set_function(pin,    FUNC_GPIOHS0);
        gpiohs_set_drive_mode(0, GPIO_DM_OUTPUT);
        gpiohs_set_pin(0, 0);
    }

    printf("sleep 3 s\r\n");
    sleep(3);
}

void test2(){
    printf("out high level\r\n");
    msleep(10);
    for(int pin = 0; pin < 32; pin++){
        fpioa_set_function(pin,    FUNC_GPIOHS0 + pin);
        gpiohs_set_drive_mode(pin, GPIO_DM_OUTPUT);
        gpiohs_set_pin(pin, 1);
    }
    printf("sleep 3 s\r\n");
    sleep(3);
    printf("out low level\r\n");
    sleep(100);
    for(int pin = 0; pin < 32; pin++){
        fpioa_set_function(pin,    FUNC_GPIOHS0 + pin);
        gpiohs_set_drive_mode(pin, GPIO_DM_OUTPUT);
        gpiohs_set_pin(pin, 0);
    }
    printf("sleep 3 s\r\n");
    sleep(3);
}

#include "iomem.h"
int main(void)
{

    test2();
    while(1)
        continue;
    return 0;
}
