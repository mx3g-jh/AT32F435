/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "freertos_tasks.h"

lv_ui guider_ui;

void Lvgl_display_task(void *pvParameters)
{

  lv_init();
  lv_ms_tick_tim();
  lv_port_disp_init();
  lv_port_indev_init();
  // setup_ui(&guider_ui);
  // events_init(&guider_ui);
  // ui_init();
  // lv_demo_benchmark();
  lv_demo_widgets();

  while (1)
  {
    vTaskDelay(1000);
  }
}
