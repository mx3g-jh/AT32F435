#ifndef __BSP_LCD_H
#define __BSP_LCD_H

#include "stdio.h"
#include "at32f435_437.h"
#include "at32f435_437_board.h"

#define LCD_W 240
#define LCD_H 240


//画笔颜色
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE           	 0x001F  
#define BRED             0XF81F
#define GRED 			       0XFFE0
#define GBLUE			       0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			     0XBC40 //棕色
#define BRRED 			     0XFC07 //棕红色
#define GRAY  			     0X8430 //灰色
#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色
#define LIGHTGREEN     	 0X841F //浅绿色
#define LGRAY 			     0XC618 //浅灰色(PANNEL),窗体背景色
#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)

/* Control Registers and constant codes */
#define ST7789_NOP     0x00
#define ST7789_SWRESET 0x01
#define ST7789_RDDID   0x04
#define ST7789_RDDST   0x09

#define ST7789_SLPIN   0x10
#define ST7789_SLPOUT  0x11
#define ST7789_PTLON   0x12
#define ST7789_NORON   0x13

#define ST7789_INVOFF  0x20
#define ST7789_INVON   0x21
#define ST7789_DISPOFF 0x28
#define ST7789_DISPON  0x29
#define ST7789_CASET   0x2A
#define ST7789_RASET   0x2B
#define ST7789_RAMWR   0x2C
#define ST7789_RAMRD   0x2E

#define ST7789_PTLAR   0x30
#define ST7789_COLMOD  0x3A
#define ST7789_MADCTL  0x36

/* Choose a display rotation you want to use: (0-3) */
// #define ST7789_ROTATION 0
// #define ST7789_ROTATION 1
// #define ST7789_ROTATION 2				//  use Normally on 240x240
#define ST7789_ROTATION 3

#if ST7789_ROTATION == 0
    #define X_SHIFT 0
    #define Y_SHIFT 80
#elif ST7789_ROTATION == 1
    #define X_SHIFT 80
    #define Y_SHIFT 0
#elif ST7789_ROTATION == 2
    #define X_SHIFT 0
    #define Y_SHIFT 0
#elif ST7789_ROTATION == 3
    #define X_SHIFT 0
    #define Y_SHIFT 0
#endif

/**
 * Memory Data Access Control Register (0x36H)
 * MAP:     D7  D6  D5  D4  D3  D2  D1  D0
 * param:   MY  MX  MV  ML  RGB MH  -   -
 *
 */

/* Page Address Order ('0': Top to Bottom, '1': the opposite) */
#define ST7789_MADCTL_MY  0x80
/* Column Address Order ('0': Left to Right, '1': the opposite) */
#define ST7789_MADCTL_MX  0x40
/* Page/Column Order ('0' = Normal Mode, '1' = Reverse Mode) */
#define ST7789_MADCTL_MV  0x20
/* Line Address Order ('0' = LCD Refresh Top to Bottom, '1' = the opposite) */
#define ST7789_MADCTL_ML  0x10
/* RGB/BGR Order ('0' = RGB, '1' = BGR) */
#define ST7789_MADCTL_RGB 0x00

#define LCD_RES_Clr()  gpio_bits_reset(GPIOA,GPIO_PINS_3)//RES
#define LCD_RES_Set()  gpio_bits_set(GPIOA,GPIO_PINS_3)
#define LCD_DC_Clr()   gpio_bits_reset(GPIOA,GPIO_PINS_4)//DC
#define LCD_DC_Set()   gpio_bits_set(GPIOA,GPIO_PINS_4) 
#define LCD_CS_Clr()   gpio_bits_reset(GPIOB,GPIO_PINS_0)//CS
#define LCD_CS_Set()   gpio_bits_set(GPIOB,GPIO_PINS_0)
#define LCD_BLK_Clr()  gpio_bits_reset(GPIOB,GPIO_PINS_1)//BLK
#define LCD_BLK_Set()  gpio_bits_set(GPIOB,GPIO_PINS_1)
#define LCD_TOUCH_Clr()  gpio_bits_reset(GPIOB,GPIO_PINS_2)//Touch_CS
#define LCD_TOUCH_Set()  gpio_bits_set(GPIOB,GPIO_PINS_2)

void LCD_GPIO_Init(void);//初始化GPIO

void ST7789_SetRotation(u8 m);

void LCD_Writ_Bus(u8 dat);//模拟SPI时序
void LCD_WR_DATA8(u8 dat);//写入一个字节
void LCD_WR_DATA(u16 dat);//写入两个字节
void lcd_send_data(const uint8_t *data, uint8_t len);
void LCD_WR_REG(u8 dat);//写入一个指令
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2);//设置坐标函数
void LCD_Init(void);//LCD初始化

void LCD_fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color);
void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 *color);
void LCD_DMA_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 *color);



#endif