#ifndef __BSP_LED_H_
#define __BSP_LED_H_

#include "FreeRTOS.h"
#include "task.h"

void led_on(void);

void led_off(void);

extern void led_task(void *pvParameters);

#endif //__BSP_LED_H_
