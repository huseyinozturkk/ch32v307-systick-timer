/*
 * systick.c
 *
 *  Created on: Nov 22, 2022
 *      Author: huseyin ozturk
 */

#include "systick.h"

void SysTick_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

static uint8_t systick_config(void);
volatile uint32_t SysTick_counter;


static uint8_t systick_config()
{

    // reset
    SysTick->CTLR = 0x00000000;
    SysTick->SR = 0x00000000;
    SysTick->CNT = 0x00000000;
    SysTick->CMP = (SystemCoreClock / 8000);

    // set irq
    NVIC_SetPriority(SysTicK_IRQn, 15);
    NVIC_EnableIRQ(SysTicK_IRQn);

    // Clock Source HCLK/8
    // En irq
    // En STK
    SysTick->CTLR |= 0x0000000B;

    return 0;
}

systick_status_e systick_init()
{
    systick_status_e status = SYSTICK_OK;

    if (systick_config() != 0) {
        status = SYSTICK_ERR;
        goto error;
    }

error:
    return status;
}

uint32_t systick_get_counter()
{
    return SysTick_counter;
}

void SysTick_Handler(void)
{
    SysTick_counter ++;

    // SYSTICK START



    // SYSTICK END

#if DEBUG_SYSTICK
    //printf("SysTick Counter: %d\r\n",SysTick_counter);
    if (SysTick_counter % 1000 == 0) {
        printf("SysTick IRQ 1 second   cnt : %d\r\n", SysTick_counter);
    }
#endif

    SysTick->SR = 0;
}
