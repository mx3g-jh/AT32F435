/**
  **************************************************************************
  * @file     main.c
  * @brief    main program
  **************************************************************************
  *                       Copyright notice & Disclaimer
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */

/* includes */
#include "at32f435_437_board.h"
#include "at32f435_437_clock.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_demos.h"
#include "main.h"
#include "st7789.h"
/** @addtogroup AT32F435_periph_examples
  * @{
  */

/** @addtogroup 435_GPIO_led_toggle GPIO_led_toggle
  * @{
  */
__IO uint32_t time_cnt = 0;
/**
  * @brief  main function.
  * @param  none
  * @retval none
  */
int main(void)
{
  system_clock_config();

  at32_board_init();
  uart_print_init(115200);
  Gpio_Init();
  nvic_priority_group_config(NVIC_PRIORITY_GROUP_4);
  Spi1_Init();
  ST7789_Init();

  // System_Timer_Init();
    //hardware init
  // LCD_Init();
  // LCD_Fill(0,0,240,240,0x001F);
  // lv_init();
  // lv_port_disp_init();
  // lv_demo_benchmark();
  crm_clocks_freq_type clocks_struct;
  crm_clocks_freq_get(&clocks_struct);
  while(1)
  {
    // delay_ms(500);
    // LCD_BLK_Set();
    delay_sec(1);
    at32_led_toggle(LED2);
    delay_ms(400);
    ST7789_Test();
    printf("flash id check success! id: %d %d %d %d\r\n", clocks_struct.ahb_freq,clocks_struct.apb1_freq,clocks_struct.apb2_freq,clocks_struct.sclk_freq);

    // lv_task_handler();
    // delay_ms(200);
    // at32_led_toggle(LED3);
    // delay_ms(200);
    // at32_led_toggle(LED4);
    // delay_ms(200);
  }
}

/**
  * @}
  */

/**
  * @}
  */
