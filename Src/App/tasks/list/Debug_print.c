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
#include "mpu6050.h"
void Debug_print(void *pvParameters)
{

	crm_clocks_freq_type Get_Clocks;

	u8 task_buff[256];
  MPU6050_t imu;
	while (1)
	{
    // vTaskDelay(1000);
		// _DC_LOG("====================Task===================");
		// _DC_LOG("  name       state     pri     stack    num");
		// vTaskList((char *)task_buff);
		// _DC_LOG("%s", task_buff);
		// _DC_LOG("===========================================");
    // crm_clocks_freq_get(&Get_Clocks);
    // DC_LOG_INFO("SYSCLK_Frequency = %d", (uint32_t)Get_Clocks.sclk_freq);
	  // DC_LOG_INFO("HCLK_Frequency   = %d", (uint32_t)Get_Clocks.ahb_freq);
	  // DC_LOG_INFO("PCLK1_Frequency  = %d", (uint32_t)Get_Clocks.apb1_freq);
	  // DC_LOG_INFO("PCLK2_Frequency  = %d", (uint32_t)Get_Clocks.apb2_freq);
    // DC_LOG_INFO("systemcoreclock  = %d", (uint32_t)SystemCoreClock);
    MPU6050_Read_All(&imu);
    DC_LOG_INFO("Gx = %3.2f", (double)imu.KalmanAngleX);
	  DC_LOG_INFO("Gy = %3.2f", (double)imu.KalmanAngleY);
	  // DC_LOG_INFO("Gz = %3.2f", (double)imu.Az);
	  DC_LOG_INFO("Temperature  = %3.2f", (float)imu.Temperature);
		vTaskDelay(100);
	}
}
