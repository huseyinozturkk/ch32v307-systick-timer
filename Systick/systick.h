/*
 * systick.h
 *
 *  Created on: Nov 22, 2022
 *      Author: huseyin ozturk
 */

#ifndef _SYSTICK_H_
#define _SYSTICK_H_

#include "ch32v30x.h"

#define DEBUG_SYSTICK       1

typedef enum
{
    SYSTICK_OK,
    SYSTICK_ERR,
    SYSTICK_TASK_LIMIT_EXCEED,
    SYSTICK_TASK_ERR_NULL,
    SYSTICK_TASK_NOT_EMPTY,
    SYSTICK_TASK_PERIOD_ERR
} systick_status_e;


systick_status_e systick_init(void);
uint32_t systick_get_counter(void);

#endif /* _SYSTICK_H_ */
