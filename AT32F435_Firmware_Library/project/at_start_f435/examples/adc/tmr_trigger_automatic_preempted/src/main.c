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

#include "at32f435_437_board.h"
#include "at32f435_437_clock.h"

/** @addtogroup AT32F435_periph_examples
  * @{
  */

/** @addtogroup 435_ADC_tmr_trigger_automatic_preempted ADC_tmr_trigger_automatic_preempted
  * @{
  */

__IO uint16_t adc1_ordinary_valuetab[5][3] = {0};
__IO uint16_t adc1_preempt_valuetab[5][3] = {0};
__IO uint16_t dma_trans_complete_flag = 0;
__IO uint16_t preempt_conversion_count = 0;
__IO uint32_t adc1_overflow_flag = 0;

static void gpio_config(void);
static void tmr1_config(void);
static void dma_config(void);
static void adc_config(void);

/**
  * @brief  gpio configuration.
  * @param  none
  * @retval none
  */
static void gpio_config(void)
{
  gpio_init_type gpio_initstructure;
  crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);
  crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK, TRUE);

  gpio_default_para_init(&gpio_initstructure);

  /* config adc pin as analog input mode */
  gpio_initstructure.gpio_mode = GPIO_MODE_ANALOG;
  gpio_initstructure.gpio_pins = GPIO_PINS_4 | GPIO_PINS_5 | GPIO_PINS_6 | GPIO_PINS_7;
  gpio_init(GPIOA, &gpio_initstructure);

  gpio_initstructure.gpio_mode = GPIO_MODE_ANALOG;
  gpio_initstructure.gpio_pins = GPIO_PINS_0 | GPIO_PINS_1;
  gpio_init(GPIOB, &gpio_initstructure);
}

/**
  * @brief  dma configuration.
  * @param  none
  * @retval none
  */
static void dma_config(void)
{
  dma_init_type dma_init_struct;
  crm_periph_clock_enable(CRM_DMA1_PERIPH_CLOCK, TRUE);
  nvic_irq_enable(DMA1_Channel1_IRQn, 0, 0);

  dma_reset(DMA1_CHANNEL1);
  dma_default_para_init(&dma_init_struct);
  dma_init_struct.buffer_size = 15;
  dma_init_struct.direction = DMA_DIR_PERIPHERAL_TO_MEMORY;
  dma_init_struct.memory_base_addr = (uint32_t)adc1_ordinary_valuetab;
  dma_init_struct.memory_data_width = DMA_MEMORY_DATA_WIDTH_HALFWORD;
  dma_init_struct.memory_inc_enable = TRUE;
  dma_init_struct.peripheral_base_addr = (uint32_t)&(ADC1->odt);
  dma_init_struct.peripheral_data_width = DMA_PERIPHERAL_DATA_WIDTH_HALFWORD;
  dma_init_struct.peripheral_inc_enable = FALSE;
  dma_init_struct.priority = DMA_PRIORITY_HIGH;
  dma_init_struct.loop_mode_enable = FALSE;
  dma_init(DMA1_CHANNEL1, &dma_init_struct);

  dmamux_enable(DMA1, TRUE);
  dmamux_init(DMA1MUX_CHANNEL1, DMAMUX_DMAREQ_ID_ADC1);

  /* enable dma transfer complete interrupt */
  dma_interrupt_enable(DMA1_CHANNEL1, DMA_FDT_INT, TRUE);
  dma_channel_enable(DMA1_CHANNEL1, TRUE);
}

/**
  * @brief  tmr1 configuration.
  * @param  none
  * @retval none
  */
static void tmr1_config(void)
{
  gpio_init_type gpio_initstructure;
  tmr_output_config_type tmr_oc_init_structure;
  crm_clocks_freq_type crm_clocks_freq_struct = {0};
  crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);

  gpio_default_para_init(&gpio_initstructure);
  gpio_initstructure.gpio_mode = GPIO_MODE_MUX;
  gpio_initstructure.gpio_pins = GPIO_PINS_8;
  gpio_initstructure.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_initstructure.gpio_pull = GPIO_PULL_NONE;
  gpio_initstructure.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
  gpio_init(GPIOA, &gpio_initstructure);
  gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE8, GPIO_MUX_1);

  /* get system clock */
  crm_clocks_freq_get(&crm_clocks_freq_struct);

  crm_periph_clock_enable(CRM_TMR1_PERIPH_CLOCK, TRUE);

  /* (systemclock/(systemclock/10000))/1000 = 10Hz(100ms) */
  tmr_base_init(TMR1, 999, (crm_clocks_freq_struct.sclk_freq/10000 - 1));
  tmr_cnt_dir_set(TMR1, TMR_COUNT_UP);
  tmr_clock_source_div_set(TMR1, TMR_CLOCK_DIV1);

  tmr_output_default_para_init(&tmr_oc_init_structure);
  tmr_oc_init_structure.oc_mode = TMR_OUTPUT_CONTROL_PWM_MODE_A;
  tmr_oc_init_structure.oc_polarity = TMR_OUTPUT_ACTIVE_LOW;
  tmr_oc_init_structure.oc_output_state = TRUE;
  tmr_oc_init_structure.oc_idle_state = FALSE;
  tmr_output_channel_config(TMR1, TMR_SELECT_CHANNEL_1, &tmr_oc_init_structure);
  tmr_channel_value_set(TMR1, TMR_SELECT_CHANNEL_1, 500);
  tmr_channel_enable(TMR1, TMR_SELECT_CHANNEL_1, TRUE);
  tmr_output_enable(TMR1, TRUE);
}

/**
  * @brief  adc configuration.
  * @param  none
  * @retval none
  */
static void adc_config(void)
{
  adc_common_config_type adc_common_struct;
  adc_base_config_type adc_base_struct;
  crm_periph_clock_enable(CRM_ADC1_PERIPH_CLOCK, TRUE);
  nvic_irq_enable(ADC1_2_3_IRQn, 0, 0);

  adc_common_default_para_init(&adc_common_struct);

  /* config combine mode */
  adc_common_struct.combine_mode = ADC_INDEPENDENT_MODE;

  /* config division,adcclk is division by hclk */
  adc_common_struct.div = ADC_HCLK_DIV_4;

  /* config common dma mode,it's not useful in independent mode */
  adc_common_struct.common_dma_mode = ADC_COMMON_DMAMODE_DISABLE;

  /* config common dma request repeat */
  adc_common_struct.common_dma_request_repeat_state = FALSE;

  /* config adjacent adc sampling interval,it's useful for ordinary shifting mode */
  adc_common_struct.sampling_interval = ADC_SAMPLING_INTERVAL_5CYCLES;

  /* config inner temperature sensor and vintrv */
  adc_common_struct.tempervintrv_state = FALSE;

  /* config voltage battery */
  adc_common_struct.vbat_state = FALSE;
  adc_common_config(&adc_common_struct);

  adc_base_default_para_init(&adc_base_struct);

  adc_base_struct.sequence_mode = TRUE;
  adc_base_struct.repeat_mode = FALSE;
  adc_base_struct.data_align = ADC_RIGHT_ALIGNMENT;
  adc_base_struct.ordinary_channel_length = 3;
  adc_base_config(ADC1, &adc_base_struct);
  adc_resolution_set(ADC1, ADC_RESOLUTION_12B);

  /* config ordinary channel */
  adc_ordinary_channel_set(ADC1, ADC_CHANNEL_4, 1, ADC_SAMPLETIME_47_5);
  adc_ordinary_channel_set(ADC1, ADC_CHANNEL_5, 2, ADC_SAMPLETIME_47_5);
  adc_ordinary_channel_set(ADC1, ADC_CHANNEL_6, 3, ADC_SAMPLETIME_47_5);

  /* config ordinary trigger source and trigger edge */
  adc_ordinary_conversion_trigger_set(ADC1, ADC_ORDINARY_TRIG_TMR1CH1, ADC_ORDINARY_TRIG_EDGE_RISING);

  /* config dma mode,it's not useful when common dma mode is use */
  adc_dma_mode_enable(ADC1, TRUE);

  /* config dma request repeat,it's not useful when common dma mode is use */
  adc_dma_request_repeat_enable(ADC1, FALSE);

  /* config preempt channel */
  adc_preempt_channel_length_set(ADC1, 3);
  adc_preempt_channel_set(ADC1, ADC_CHANNEL_7, 1, ADC_SAMPLETIME_47_5);
  adc_preempt_channel_set(ADC1, ADC_CHANNEL_8, 2, ADC_SAMPLETIME_47_5);
  adc_preempt_channel_set(ADC1, ADC_CHANNEL_9, 3, ADC_SAMPLETIME_47_5);

  /* config preempt trigger source and trigger edge */
  adc_preempt_conversion_trigger_set(ADC1, ADC_PREEMPT_TRIG_TMR1CH4, ADC_PREEMPT_TRIG_EDGE_NONE);

  /* preempt group automatic conversion after ordinary group */
  adc_preempt_auto_mode_enable(ADC1, TRUE);

  /* enable adc overflow interrupt */
  adc_interrupt_enable(ADC1, ADC_OCCO_INT, TRUE);

  /* enable adc preempt channels conversion end interrupt */
  adc_interrupt_enable(ADC1, ADC_PCCE_INT, TRUE);

  /* adc enable */
  adc_enable(ADC1, TRUE);
  while(adc_flag_get(ADC1, ADC_RDY_FLAG) == RESET);

  /* adc calibration */
  adc_calibration_init(ADC1);
  while(adc_calibration_init_status_get(ADC1));
  adc_calibration_start(ADC1);
  while(adc_calibration_status_get(ADC1));
}

/**
  * @brief  main function.
  * @param  none
  * @retval none
  */
int main(void)
{
  __IO uint32_t index = 0;
  nvic_priority_group_config(NVIC_PRIORITY_GROUP_4);

  /* config the system clock */
  system_clock_config();

  /* init at start board */
  at32_board_init();
  at32_led_off(LED2);
  at32_led_off(LED3);
  at32_led_off(LED4);
  uart_print_init(115200);
  gpio_config();
  tmr1_config();
  dma_config();
  adc_config();
  printf("tmr_trigger_automatic_preempt \r\n");
  tmr_counter_enable(TMR1, TRUE);
  while(preempt_conversion_count < 5);
  while(dma_trans_complete_flag == 0);
  tmr_counter_enable(TMR1, FALSE);
  if(adc1_overflow_flag != 0)
  {
    /* printf flag when error occur */
    at32_led_on(LED3);
    at32_led_on(LED4);
    printf("error occur\r\n");
    printf("adc1_overflow_flag = %d\r\n",adc1_overflow_flag);
  }
  else
  {
    /* printf data when conversion end without error */
    printf("conversion end without error\r\n");
    for(index = 0; index < 5; index++)
    {
      printf("adc1_ordinary_valuetab[%d][0] = 0x%x\r\n", index, adc1_ordinary_valuetab[index][0]);
      printf("adc1_ordinary_valuetab[%d][1] = 0x%x\r\n", index, adc1_ordinary_valuetab[index][1]);
      printf("adc1_ordinary_valuetab[%d][2] = 0x%x\r\n", index, adc1_ordinary_valuetab[index][2]);
      printf("adc1_preempt_valuetab[%d][0] = 0x%x\r\n", index, adc1_preempt_valuetab[index][0]);
      printf("adc1_preempt_valuetab[%d][1] = 0x%x\r\n", index, adc1_preempt_valuetab[index][1]);
      printf("adc1_preempt_valuetab[%d][2] = 0x%x\r\n", index, adc1_preempt_valuetab[index][2]);
      printf("\r\n");
    }
  }
  at32_led_on(LED2);
  while(1)
  {
  }
}

/**
  * @}
  */

/**
  * @}
  */

