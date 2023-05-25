#ifndef _SYSTEM_TIMER_H_
#define _SYSTEM_TIMER_H_

#ifdef __cplusplus
extern "C" {
#endif

/* includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "lvgl.h"
#include <at32f435_437.h>
#include "at32f435_437_conf.h"

void System_Timer_Init(void);
void System_Timer_Flag_Set(uint8_t flag);
uint8_t System_Timer_Flag_Get();

#ifdef __cplusplus
}
#endif

#endif