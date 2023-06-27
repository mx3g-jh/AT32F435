/* vim: set ai et ts=4 sw=4: */
#ifndef __ILI9341_H__
#define __ILI9341_H__

#include "fonts.h"
#include <stdbool.h>
#include "main.h"

#include "at32f435_437.h"
#include "at32f435_437_board.h"

#define ILI9341_MADCTL_MY  0x80
#define ILI9341_MADCTL_MX  0x40
#define ILI9341_MADCTL_MV  0x20
#define ILI9341_MADCTL_ML  0x10
#define ILI9341_MADCTL_RGB 0x00
#define ILI9341_MADCTL_BGR 0x08
#define ILI9341_MADCTL_MH  0x04

/*** Redefine if necessary ***/

#define ILI9341_RES_Clr()  gpio_bits_reset(GPIOA,GPIO_PINS_3)//RES
#define ILI9341_RES_Set()  gpio_bits_set(GPIOA,GPIO_PINS_3)
#define ILI9341_DC_Clr()   gpio_bits_reset(GPIOA,GPIO_PINS_4)//DC
#define ILI9341_DC_Set()   gpio_bits_set(GPIOA,GPIO_PINS_4) 
#define ILI9341_CS_Clr()   gpio_bits_reset(GPIOB,GPIO_PINS_0)//CS
#define ILI9341_CS_Set()   gpio_bits_set(GPIOB,GPIO_PINS_0)
#define ILI9341_BLK_Clr()  gpio_bits_reset(GPIOB,GPIO_PINS_1)//BLK
#define ILI9341_BLK_Set()  gpio_bits_set(GPIOB,GPIO_PINS_1)

// default orientation
// #define ROTATION_NONE
// #define ILI9341_WIDTH  320
// #define ILI9341_HEIGHT 480
// #define ILI9341_ROTATION (ILI9341_MADCTL_MX | ILI9341_MADCTL_BGR)

// rotate right
#define ROTATION_RIGHT
#define ILI9341_WIDTH  480
#define ILI9341_HEIGHT 320
#define ILI9341_ROTATION (ILI9341_MADCTL_MX | ILI9341_MADCTL_MY | ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR)

// rotate left
// #define ROTATION_LEFT
// #define ILI9341_WIDTH  480
// #define ILI9341_HEIGHT 320
// #define ILI9341_ROTATION (ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR)


// upside down
// #define ROTATION_UPSIDE_DOWN
// #define ILI9341_WIDTH  320
// #define ILI9341_HEIGHT 480
// #define ILI9341_ROTATION (ILI9341_MADCTL_MY | ILI9341_MADCTL_BGR)


/****************************/

// Color definitions
#define	ILI9341_BLACK   0x0000
#define	ILI9341_BLUE    0x001F
#define	ILI9341_RED     0xF800
#define	ILI9341_GREEN   0x07E0
#define ILI9341_CYAN    0x07FF
#define ILI9341_MAGENTA 0xF81F
#define ILI9341_YELLOW  0xFFE0
#define ILI9341_WHITE   0xFFFF
#define ILI9341_COLOR565(r, g, b) (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b & 0xF8) >> 3))

void ILI9341_GPIO_Init(void);

// call before initializing any SPI devices
void ILI9341_Reset();
void ILI9341_Writ_Bus(u8 dat);
void ILI9341_WR_DATA8(u8 dat);
void ILI9341_WR_DATA(u16 dat);
void ILI9341_WR_DATA_LONG(uint8_t* buff, size_t buff_size);
void ILI9341_WR_REG(u8 dat);
void ILI9341_WriteData(uint8_t* buff, size_t buff_size);
void ILI9341_SetAddressWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);

void TFT_ILI9341_Init(void);
void ILI9341_DrawPixel(uint16_t x, uint16_t y, uint16_t color);
void ILI9341_WriteString(uint16_t x, uint16_t y, const char* str, TFT_FontDef font, uint16_t color, uint16_t bgcolor);
void ILI9341_FillRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
void ILI9341_FillScreen(uint16_t color);
void ILI9341_DrawImage(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t* data);
void ILI9341_InvertColors(bool invert);

void ILI9341_DMA_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 *color);
#endif // __ILI9341_H__
