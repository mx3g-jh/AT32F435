#ifndef _MAIN_H_
#define _MAIN_H_

#ifdef __cplusplus
extern "C" {
#endif

/* includes ------------------------------------------------------------------*/
//system
#include "at32f435_437.h"
#include "at32f435_437_board.h"
#include "at32f435_437_clock.h"

//bsp
#include "timer.h"
#include "ui.h"
//hardware
#include "bsp_spi_lcd.h"
#include "ili9341.h"
#include "ili9341_touch.h"
#include "mpu6050.h"
//application
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "lv_demos.h"

#include "DataCenterLog.h"

#include "events_init.h"
#include "gui_guider.h"
//middleware
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "event_groups.h"
#include "timers.h"
#include "stream_buffer.h"
#include "message_buffer.h"
#include "semphr.h"
#include "freertos_tasks.h"
#include "lv_tick_custom.h"

#include "mavlink.h"
#define MAVLINK_USE_CONVENIENCE_FUNCTIONS
extern mavlink_system_t mavlink_system;
void System_Init(void);

#ifdef __cplusplus
}
#endif

#endif
