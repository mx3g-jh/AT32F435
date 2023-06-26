#ifndef __FREERTOS_TASKS_H
#define __FREERTOS_TASKS_H

#include "at32f435_437.h"
#include "FreeRTOSConfig.h"
#include "stdio.h"

//FreeRTOS tasks
void Debug_print(void *pvParameters);
void Lvgl_task(void *pvParameters);
void Lvgl_display_task(void *pvParameters);
void GT911_touch_task(void *pvParameters);

void FreeRTOS_Init(void);

#endif
