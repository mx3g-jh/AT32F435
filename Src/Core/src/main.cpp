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

#define BufferSize	240*240
uint16_t Buffer_Tx[BufferSize];

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
	nvic_priority_group_config(NVIC_PRIORITY_GROUP_4);
  nvic_irq_enable(DMA1_Channel1_IRQn, 1, 0);
  at32_board_init();
  uart_print_init(115200);

  LCD_Init();
  LCD_fill(0,0,240,240,YELLOW);

  // lv_init();
  // lv_port_disp_init();
  // lv_demo_benchmark();
  crm_clocks_freq_type clocks_struct;
  crm_clocks_freq_get(&clocks_struct);
  while(1)
  {

    at32_led_toggle(LED2);
    printf("flash id check success! id: %d %d %d %d\r\n", clocks_struct.ahb_freq,clocks_struct.apb1_freq,clocks_struct.apb2_freq,clocks_struct.sclk_freq);
		printf("doing\r\n");
		for(int i = 0; i < BufferSize; i++)
		{
			Buffer_Tx[i] = RED;
		}
		LCD_DMA_Fill(0,0,240,240,Buffer_Tx);
		delay_ms(100);
		
		printf("doing\r\n");
		for(int i = 0; i < BufferSize; i++)
		{
			Buffer_Tx[i] = LIGHTBLUE;
		}
		LCD_DMA_Fill(0,0,240,240,Buffer_Tx);
		delay_ms(100);

		printf("doing\r\n");
		for(int i = 0; i < BufferSize; i++)
		{
			Buffer_Tx[i] = LBBLUE;
		}
		LCD_DMA_Fill(0,0,240,240,Buffer_Tx);
		delay_ms(100);

		printf("doing\r\n");
		for(int i = 0; i < BufferSize; i++)
		{
			Buffer_Tx[i] = WHITE;
		}
		LCD_DMA_Fill(0,0,240,240,Buffer_Tx);
		delay_ms(100);	
  }
}

/**
  * @}
  */

/**
  * @}
  */
