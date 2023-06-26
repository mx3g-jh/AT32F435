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

void Debug_print(void *pvParameters)
{

	crm_clocks_freq_type Get_Clocks;

	u8 task_buff[128];
	while (1)
	{
    vTaskDelay(1000);
		printf("====================Task===================\r\n");
		printf("  name       state     pri     stack    num\r\n");
		vTaskList((char *)task_buff);
		printf("%s", task_buff);
		printf("===========================================\r\n");
    crm_clocks_freq_get(&Get_Clocks);
    printf("SYSCLK_Frequency = %d\r\n", (uint32_t)Get_Clocks.sclk_freq);
	  printf("HCLK_Frequency   = %d\r\n", (uint32_t)Get_Clocks.ahb_freq);
	  printf("PCLK1_Frequency  = %d\r\n", (uint32_t)Get_Clocks.apb1_freq);
	  printf("PCLK2_Frequency  = %d\r\n", (uint32_t)Get_Clocks.apb2_freq);
    printf("systemcoreclock  = %d\r\n", (uint32_t)SystemCoreClock);
    at32_led_toggle(LED2);
		vTaskDelay(500);
	}
}
