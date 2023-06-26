#ifndef __IIC_H
#define __IIC_H

#include "at32f435_437.h"
#include "at32f435_437_board.h"
#include "i2c_application.h"

#define HARDWARE_IIC
// #define SOFTWARE_IIC

#define GT911_USE_DMA

/*----------------------------------------- IIIC 引脚配置宏 -----------------------------------------------*/
//#define I2Cx_CLKCTRL                   0xB170FFFF   //10K
//#define I2Cx_CLKCTRL                   0xC0E06969   //50K
#define I2Cx_CLKCTRL                     0x80504C4E   //100K
//#define I2Cx_CLKCTRL                   0x30F03C6B   //200K
/*------------------------------------------ IIC相关定义 -------------------------------------------------*/

/*------------------------------------ 寄存定义 -----------------------------------*/  		
#define I2C_TIMEOUT                      0xFFFFFFF

#define GT9XX_IIC_RADDR 0xBB			// IIC初始化地址
#define GT9XX_IIC_WADDR 0xBA

#define GT9XX_CFG_ADDR 	0x8047		// 固件配置信息寄存器和配置起始地址
#define GT9XX_READ_ADDR 0x814E		// 触摸信息寄存器
#define GT9XX_ID_ADDR 	0x8140		// 触摸面板ID寄存器

#define ACK_OK  	1  			// 响应正常
#define ACK_ERR 	0				// 响应错误

#ifdef SOFTWARE_IIC
// IIC通信延时，GT911_IIC_Delay()函数使用，
//	通信速度在100KHz左右
#define IIC_DelayVaule  20  	

/*-------------------------------------------- IO口操作 ---------------------------------------------------*/   

#define GT911_IIC_SCL(a)	if (a)	\
										gpio_bits_set(GPIOA,GPIO_PINS_0); \
									else		\
										gpio_bits_reset(GPIOA,GPIO_PINS_0)	

#define GT911_IIC_SDA(a)	if (a)	\
										gpio_bits_set(GPIOA,GPIO_PINS_1); \
									else		\
										gpio_bits_reset(GPIOA,GPIO_PINS_1)		

#endif
/*--------------------------------------------- 函数声明 --------------------------------------------------*/  		
					
void 		GT911_IIC_GPIO_Config (void);					// IIC引脚初始化
void		GT911_INT_Out(void);								// INT数据脚配置为输出模式
void		GT911_INT_In(void);								// INT数据脚配置为输入模式	

#ifdef SOFTWARE_IIC
void 		GT911_IIC_Delay(uint32_t a);					// IIC延时函数							
void 		GT911_IIC_Start(void);							// 启动IIC通信
void 		GT911_IIC_Stop(void);							// IIC停止信号
void 		GT911_IIC_ACK(void);								//	发送响应信号
void 		GT911_IIC_NoACK(void);							// 发送非应答信号
uint8_t 	GT911_IIC_WaitACK(void);						//	等待应答信号
uint8_t		GT911_IIC_WriteByte(uint8_t IIC_Data); 	// 写字节函数
uint8_t 	GT911_IIC_ReadByte(uint8_t ACK_Mode);		// 读字节函数
#else
uint8_t GT911_IIC_WriteReg(uint16_t addr, uint8_t cnt, uint8_t *value);
uint8_t GT911_IIC_ReadReg(uint16_t addr, uint8_t cnt, uint8_t *value);
#endif

#endif //__IIC_H
