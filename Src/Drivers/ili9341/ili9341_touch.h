/* vim: set ai et ts=4 sw=4: */
#ifndef __ILI9341_TOUCH_H__
#define __ILI9341_TOUCH_H__

#include <stdbool.h>
#include "touch_iic.h"
#include "ili9341.h"
/*------------------------------------ 相关定义 -----------------------------------*/  	
#define GT911_WIDTH ILI9341_WIDTH
#define GT911_HEIGHT ILI9341_HEIGHT

#define GT911_MAX   5	//最大触摸点数

typedef struct 
{
	uint8_t  flag;			//	触摸标志位，为1时表示有触摸操作
	uint8_t  num;				//	触摸点数
	uint16_t x[GT911_MAX];	//	x坐标
	uint16_t y[GT911_MAX];	//	y坐标
}TouchStructure;

extern volatile TouchStructure touchInfo;	// 触摸数据结构体声明	

/*------------------------------------ 函数声明 -----------------------------------*/  		

uint8_t 	GT911_Init(void);		// 触摸屏初始化
void 		GT911_Scan(void);		// 触摸扫描

void 		rotation_gt911(volatile TouchStructure *touch_structure);
void  		GT9XX_Reset(void);	// 执行复位操作
void 		GT9XX_SendCfg(void);	// 发送GT911配置参数
void 		GT9XX_ReadCfg(void);	// 读取GT911配置参数

#endif // __ILI9341_TOUCH_H__
