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

#define LCD_RES_Clr()  gpio_bits_reset(GPIOB,GPIO_PINS_3)//RES
#define LCD_RES_Set()  gpio_bits_set(GPIOB,GPIO_PINS_3)
#define LCD_DC_Clr()   gpio_bits_reset(GPIOB,GPIO_PINS_0)//DC
#define LCD_DC_Set()   gpio_bits_set(GPIOB,GPIO_PINS_0) 
#define LCD_CS_Clr()   gpio_bits_reset(GPIOA,GPIO_PINS_4)//CS
#define LCD_CS_Set()   gpio_bits_set(GPIOA,GPIO_PINS_4)
#define LCD_BLK_Clr()  gpio_bits_reset(GPIOA,GPIO_PINS_3)//BLK
#define LCD_BLK_Set()  gpio_bits_set(GPIOA,GPIO_PINS_3)

void LCD_GPIO_Init(void);//初始化GPIO
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