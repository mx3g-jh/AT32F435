/**
  **************************************************************************
  * @file     at32f435_437_int.c
  * @brief    main interrupt service routines.
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

/* includes ------------------------------------------------------------------*/
#include "at32f435_437_int.h"

/** @addtogroup AT32F435_periph_examples
  * @{
  */

/** @addtogroup 435_TMR_oc_toggle_tmr3
  * @{
  */

uint32_t capture = 0;
extern __IO uint16_t ccr1_val;
extern __IO uint16_t ccr2_val;
extern __IO uint16_t ccr3_val;
extern __IO uint16_t ccr4_val;

/**
  * @brief  this function handles nmi exception.
  * @param  none
  * @retval none
  */
void NMI_Handler(void)
{
}

/**
  * @brief  this function handles hard fault exception.
  * @param  none
  * @retval none
  */
void HardFault_Handler(void)
{
  /* go to infinite loop when hard fault exception occurs */
  while(1)
  {
  }
}

/**
  * @brief  this function handles memory manage exception.
  * @param  none
  * @retval none
  */
void MemManage_Handler(void)
{
  /* go to infinite loop when memory manage exception occurs */
  while(1)
  {
  }
}

/**
  * @brief  this function handles bus fault exception.
  * @param  none
  * @retval none
  */
void BusFault_Handler(void)
{
  /* go to infinite loop when bus fault exception occurs */
  while(1)
  {
  }
}

/**
  * @brief  this function handles usage fault exception.
  * @param  none
  * @retval none
  */
void UsageFault_Handler(void)
{
  /* go to infinite loop when usage fault exception occurs */
  while(1)
  {
  }
}

/**
  * @brief  this function handles svcall exception.
  * @param  none
  * @retval none
  */
void SVC_Handler(void)
{
}

/**
  * @brief  this function handles debug monitor exception.
  * @param  none
  * @retval none
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  this function handles pendsv_handler exception.
  * @param  none
  * @retval none
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  this function handles systick handler.
  * @param  none
  * @retval none
  */
void SysTick_Handler(void)
{
}

/**
  * @brief  this function handles tmr3 global interrupt request.
  * @param  none
  * @retval none
  */
void TMR3_GLOBAL_IRQHandler(void)
{
  /* TMR3_CH1 toggling with frequency = 183.1 Hz */
  if (tmr_flag_get(TMR3, TMR_C1_FLAG) != RESET)
  {
    tmr_flag_clear(TMR3, TMR_C1_FLAG );
    capture = tmr_channel_value_get(TMR3, TMR_SELECT_CHANNEL_1);
    tmr_channel_value_set(TMR3, TMR_SELECT_CHANNEL_1, capture + ccr1_val);
  }

  /* TMR3_CH2 toggling with frequency = 366.2 Hz */
  if (tmr_flag_get(TMR3, TMR_C2_FLAG) != RESET)
  {
    tmr_flag_clear(TMR3, TMR_C2_FLAG);
    capture = tmr_channel_value_get(TMR3, TMR_SELECT_CHANNEL_2);
    tmr_channel_value_set(TMR3, TMR_SELECT_CHANNEL_2, capture + ccr2_val);
  }

  /* TMR3_CH3 toggling with frequency = 732.4 Hz */
  if (tmr_flag_get(TMR3, TMR_C3_FLAG) != RESET)
  {
    tmr_flag_clear(TMR3, TMR_C3_FLAG);
    capture = tmr_channel_value_get(TMR3, TMR_SELECT_CHANNEL_3);
    tmr_channel_value_set(TMR3, TMR_SELECT_CHANNEL_3, capture + ccr3_val);
  }

  /* TMR3_CH4 toggling with frequency = 1464.8 Hz */
  if (tmr_flag_get(TMR3, TMR_C4_FLAG) != RESET)
  {
    tmr_flag_clear(TMR3, TMR_C4_FLAG);
    capture = tmr_channel_value_get(TMR3, TMR_SELECT_CHANNEL_4);
    tmr_channel_value_set(TMR3, TMR_SELECT_CHANNEL_4, capture + ccr4_val);
  }
}

/**
  * @}
  */

/**
  * @}
  */
