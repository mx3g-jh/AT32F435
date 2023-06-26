#ifndef __IIC_H
#define __IIC_H

#include "at32f435_437.h"
#include "at32f435_437_board.h"

/*----------------------------------------- IIIC �������ú� -----------------------------------------------*/
 

// #define GT911_IIC_SCL_CLK_ENABLE     __HAL_RCC_GPIOI_CLK_ENABLE()		// SCL ����ʱ��
// #define GT911_IIC_SCL_PORT   			 GPIOI                 				// SCL ���Ŷ˿�
// #define GT911_IIC_SCL_PIN     		 GPIO_PIN_11  							// SCL ����
         
// #define GT911_IIC_SDA_CLK_ENABLE     __HAL_RCC_GPIOI_CLK_ENABLE() 	// SDA ����ʱ��
// #define GT911_IIC_SDA_PORT   			 GPIOI                   			// SDA ���Ŷ˿�
// #define GT911_IIC_SDA_PIN    			 GPIO_PIN_8              			// SDA ����

// #define GT911_INT_CLK_ENABLE    		 __HAL_RCC_GPIOG_CLK_ENABLE()		// INT ����ʱ��
// #define GT911_INT_PORT   				 GPIOG                   			// INT ���Ŷ˿�
// #define GT911_INT_PIN    				 GPIO_PIN_3             			// INT ����

// #define GT911_RST_CLK_ENABLE   		 __HAL_RCC_GPIOH_CLK_ENABLE()		// RST ����ʱ��
// #define GT911_RST_PORT   				 GPIOH                   			// RST ���Ŷ˿�
// #define GT911_RST_PIN    				 GPIO_PIN_4           				// RST ����

/*------------------------------------------ IIC��ض��� -------------------------------------------------*/

#define ACK_OK  	1  			// ��Ӧ����
#define ACK_ERR 	0				// ��Ӧ����

// IICͨ����ʱ��GT911_IIC_Delay()����ʹ�ã�
//	ͨ���ٶ���100KHz����
#define IIC_DelayVaule  20  	

/*-------------------------------------------- IO�ڲ��� ---------------------------------------------------*/   

#define GT911_IIC_SCL(a)	if (a)	\
										gpio_bits_set(GPIOA,GPIO_PINS_0); \
									else		\
										gpio_bits_reset(GPIOA,GPIO_PINS_0)	

#define GT911_IIC_SDA(a)	if (a)	\
										gpio_bits_set(GPIOA,GPIO_PINS_1); \
									else		\
										gpio_bits_reset(GPIOA,GPIO_PINS_1)	

/*--------------------------------------------- �������� --------------------------------------------------*/  		
					
void 		GT911_IIC_GPIO_Config (void);					// IIC���ų�ʼ��
void 		GT911_IIC_Delay(uint32_t a);					// IIC��ʱ����
void		GT911_INT_Out(void);								// INT���ݽ�����Ϊ���ģʽ
void		GT911_INT_In(void);								// INT���ݽ�����Ϊ����ģʽ								
void 		GT911_IIC_Start(void);							// ����IICͨ��
void 		GT911_IIC_Stop(void);							// IICֹͣ�ź�
void 		GT911_IIC_ACK(void);								//	������Ӧ�ź�
void 		GT911_IIC_NoACK(void);							// ���ͷ�Ӧ���ź�
uint8_t 	GT911_IIC_WaitACK(void);						//	�ȴ�Ӧ���ź�
uint8_t	GT911_IIC_WriteByte(uint8_t IIC_Data); 	// д�ֽں���
uint8_t 	GT911_IIC_ReadByte(uint8_t ACK_Mode);		// ���ֽں���
		
#endif //__IIC_H
