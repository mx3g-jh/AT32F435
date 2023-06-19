/* vim: set ai et ts=4 sw=4: */
#ifndef __ILI9341_TOUCH_H__
#define __ILI9341_TOUCH_H__

#include <stdbool.h>
#include "main.h"
#include "at32f435_437.h"
#include "at32f435_437_board.h"
#include "ili9341.h"
/*** Redefine if necessary ***/

// Warning! Use SPI bus with < 1.3 Mbit speed, better ~650 Kbit to be save.

#define ILI9341_TOUCH_IRQ_Pin       GPIO_PINS_2
#define ILI9341_TOUCH_IRQ_GPIO_Port GPIOA
#define ILI9341_TOUCH_CS_Clr()  gpio_bits_reset(GPIOB,GPIO_PINS_2)//Touch_CS
#define ILI9341_TOUCH_CS_Set()  gpio_bits_set(GPIOB,GPIO_PINS_2)

// change depending on screen orientation
#define ILI9341_TOUCH_SCALE_X 240
#define ILI9341_TOUCH_SCALE_Y 320

// to calibrate uncomment UART_Printf line in ili9341_touch.c
#define ILI9341_TOUCH_MIN_RAW_X 1500
#define ILI9341_TOUCH_MAX_RAW_X 31000
#define ILI9341_TOUCH_MIN_RAW_Y 3276
#define ILI9341_TOUCH_MAX_RAW_Y 30110

// call before initializing any SPI devices
void ILI9341_Touch_GPIO_Init(void);
void ILI9341_Touch_Read_Bus(u16 *pRxData);
void ILI9341_Touch_WR_DATA(u16 dat);
void ILI9341_Touch_Writ_Bus(u8 dat);

bool ILI9341_TouchPressed();
bool ILI9341_TouchGetCoordinates(lv_coord_t * x, lv_coord_t * y);

#endif // __ILI9341_TOUCH_H__
