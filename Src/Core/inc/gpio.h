#ifndef _GPIO_H_
#define _GPIO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "at32f435_437_conf.h"
#include "at32f435_437.h"

//lcd屏幕
//lcd_res
#define GPIO_LCD_RES_PIN        GPIO_PINS_1
#define GPIO_LCD_RES_PORT       GPIOB
#define _GPIO_LCD_RES_H()       gpio_bits_set(GPIO_LCD_RES_PORT, GPIO_LCD_RES_PIN)
#define _GPIO_LCD_RES_L()       gpio_bits_reset(GPIO_LCD_RES_PORT, GPIO_LCD_RES_PIN)
//lcd_dc
#define GPIO_LCD_DC_PIN         GPIO_PINS_0
#define GPIO_LCD_DC_PORT        GPIOB
#define _GPIO_LCD_DC_H()        gpio_bits_set(GPIO_LCD_DC_PORT, GPIO_LCD_DC_PIN)
#define _GPIO_LCD_DC_L()        gpio_bits_reset(GPIO_LCD_DC_PORT, GPIO_LCD_DC_PIN)
//lcd_cs
#define GPIO_LCD_CS_PIN         GPIO_PINS_2
#define GPIO_LCD_CS_PORT        GPIOB
#define _GPIO_LCD_CS_H()        gpio_bits_set(GPIO_LCD_CS_PORT, GPIO_LCD_CS_PIN)
#define _GPIO_LCD_CS_L()        gpio_bits_reset(GPIO_LCD_CS_PORT, GPIO_LCD_CS_PIN)
//lcd_blk
#define GPIO_LCD_BLK_PIN        GPIO_PINS_4
#define GPIO_LCD_BLK_PORT       GPIOA
#define _GPIO_LCD_BLK_H()       gpio_bits_set(GPIO_LCD_BLK_PORT, GPIO_LCD_BLK_PIN)
#define _GPIO_LCD_BLK_L()       gpio_bits_reset(GPIO_LCD_BLK_PORT, GPIO_LCD_BLK_PIN)

void Gpio_Init(void);

#ifdef __cplusplus
}
#endif

#endif