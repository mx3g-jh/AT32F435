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
/* USER CODE END Includes */
TaskHandle_t Debug_print_Handler;
TaskHandle_t Lvgl_task_Handler;
TaskHandle_t Lvgl_display_Handler;
TaskHandle_t GT911_touch_Handler;
TaskHandle_t Led_toggle_Handler;

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
void FreeRTOS_Init(void)
{
	taskENTER_CRITICAL();

  xTaskCreate((TaskFunction_t)Led_toggle,
            (const char *)"Led_toggle",
            (uint16_t)64,
            (void *)NULL,
            (UBaseType_t)1,
            (TaskHandle_t *)&Led_toggle_Handler);

	xTaskCreate((TaskFunction_t)Debug_print,
				(const char *)"Debug_print",
				(uint16_t)1560,
				(void *)NULL,
				(UBaseType_t)1,
				(TaskHandle_t *)&Debug_print_Handler);
  
  xTaskCreate((TaskFunction_t)Lvgl_task,
            (const char *)"lvgl_task",
            (uint16_t)1024,
            (void *)NULL,
            (UBaseType_t)1,
            (TaskHandle_t *)&Lvgl_task_Handler);

  xTaskCreate((TaskFunction_t)Lvgl_display_task,
            (const char *)"Lvgl_display_task",
            (uint16_t)512,
            (void *)NULL,
            (UBaseType_t)1,
            (TaskHandle_t *)&Lvgl_display_Handler);

  xTaskCreate((TaskFunction_t)GT911_touch_task,
            (const char *)"GT911_touch_task",
            (uint16_t)256,
            (void *)NULL,
            (UBaseType_t)1,
            (TaskHandle_t *)&GT911_touch_Handler);

	taskEXIT_CRITICAL();
	vTaskStartScheduler();
}
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */