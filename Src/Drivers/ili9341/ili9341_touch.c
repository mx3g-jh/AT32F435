/* vim: set ai et ts=4 sw=4: */

#include "ili9341_touch.h"

volatile TouchStructure touchInfo; 			//	触摸信息结构体，在函数 GT911_Scan() 里被调用，存储触摸数据
volatile static uint8_t Modify_Flag = 0;	// 触摸坐标修改标志位
	

/*************************************************************************************************************************************
*	函 数 名:	GT9XX_Reset
*	入口参数:	无
*	返 回 值:	无
*	函数功能:	复位GT911
*	说    明:	复位GT911，并将芯片的IIC地址配置为0xBA/0xBB
************************************************************************************************************************************/

void GT9XX_Reset(void)
{
	GT911_INT_Out();	//	将INT引脚配置为输出
	
	// 初始化引脚状态
	gpio_bits_reset(GPIOA,GPIO_PINS_2);  // INT输出低电平
	gpio_bits_set(GPIOA,GPIO_PINS_3);    // RST输出高	电平
	delay_ms(10);
	
	// 开始执行复位
	//	INT引脚保持低电平不变，将器件地址设置为0XBA/0XBB
	gpio_bits_reset(GPIOA,GPIO_PINS_3); // 拉低复位引脚，此时芯片执行复位
	delay_ms(150);			// 延时
	gpio_bits_set(GPIOA,GPIO_PINS_3);			// 拉高复位引脚，复位结束
	delay_ms(350);			// 延时
	GT911_INT_In();						// INT引脚转为浮空输入
	delay_ms(20);				// 延时
									
}
#ifdef SOFTWARE_IIC
/*************************************************************************************************************************************
*	函 数 名:	GT9XX_WriteHandle
*	入口参数:	addr - 要操作的寄存器
*	返 回 值:	SUCCESS - 操作成功
*					ERROR	  - 操作失败
*	函数功能:	GT9XX 写操作
*	说    明:	对指定的寄存器执行写操作
************************************************************************************************************************************/

uint8_t GT9XX_WriteHandle (uint16_t addr)
{
	uint8_t status;		// 状态标志位

	GT911_IIC_Start();	// 启动IIC通信
	if( GT911_IIC_WriteByte(GT9XX_IIC_WADDR) == ACK_OK ) //写数据指令
	{
		if( GT911_IIC_WriteByte((uint8_t)(addr >> 8)) == ACK_OK ) //写入16位地址
		{
			if( GT911_IIC_WriteByte((uint8_t)(addr)) != ACK_OK )
			{
				status = ERROR;	// 操作失败
			}			
		}
	}
	status = SUCCESS;	// 操作成功
	return status;	
}

/*************************************************************************************************************************************
*	函 数 名:	GT9XX_WriteData
*	入口参数:	addr - 要写入的寄存器
*					value - 要写入的数据
*	返 回 值:	SUCCESS - 操作成功
*					ERROR	  - 操作失败
*	函数功能:	GT9XX 写一字节数据
*	说    明:	对指定的寄存器写入一字节数据
************************************************************************************************************************************/

uint8_t GT9XX_WriteData (uint16_t addr,uint8_t value)
{
	uint8_t status;
	
	GT911_IIC_Start(); //启动IIC通讯

	if( GT9XX_WriteHandle(addr) == SUCCESS)	//写入要操作的寄存器
	{
		if (GT911_IIC_WriteByte(value) != ACK_OK) //写数据
		{
			status = ERROR;						
		}
	}	
	GT911_IIC_Stop(); // 停止通讯
	
	status = SUCCESS;	// 写入成功
	return status;
}

/*************************************************************************************************************************************
*	函 数 名:	GT9XX_WriteReg
*	入口参数:	addr - 要写入的寄存器区域首地址
*					cnt  - 数据长度
*					value - 要写入的数据区
*	返 回 值:	SUCCESS - 操作成功
*					ERROR	  - 操作失败
*	函数功能:	GT9XX 写寄存器
*	说    明:	往芯片的寄存器区写入指定长度的数据
************************************************************************************************************************************/

uint8_t GT9XX_WriteReg (uint16_t addr, uint8_t cnt, uint8_t *value)
{
	uint8_t status;
	uint8_t i;

	GT911_IIC_Start();

	if( GT9XX_WriteHandle(addr) == SUCCESS) 	// 写入要操作的寄存器
	{
		for(i = 0 ; i < cnt; i++)			 	// 计数
		{
			GT911_IIC_WriteByte(value[i]);	// 写入数据
		}					
		GT911_IIC_Stop();		// 停止IIC通信
		status = SUCCESS;		// 写入成功
	}
	else
	{
		GT911_IIC_Stop();		// 停止IIC通信
		status = ERROR;		// 写入失败
	}
	return status;	
}

/*************************************************************************************************************************************
*	函 数 名:	GT9XX_ReadReg
*	入口参数:	addr - 要读取的寄存器区域首地址
*					cnt  - 数据长度
*					value - 要读取的数据区
*	返 回 值:	SUCCESS - 操作成功
*					ERROR	  - 操作失败
*	函数功能:	GT9XX 读寄存器
*	说    明:	从芯片的寄存器区读取指定长度的数据
************************************************************************************************************************************/

uint8_t GT9XX_ReadReg (uint16_t addr, uint8_t cnt, uint8_t *value)
{
	uint8_t status;
	uint8_t i;

	status = ERROR;
	GT911_IIC_Start();		// 启动IIC通信

	if( GT9XX_WriteHandle(addr) == SUCCESS) //写入要操作的寄存器
	{
		GT911_IIC_Start(); //重新启动IIC通讯

		if (GT911_IIC_WriteByte(GT9XX_IIC_RADDR) == ACK_OK)	// 发送读命令
		{	
			for(i = 0 ; i < cnt; i++)	// 计数
			{
				if (i == (cnt - 1))
				{
					value[i] = GT911_IIC_ReadByte(0);	// 读到最后一个数据时发送 非应答信号
				}
				else
				{
					value[i] = GT911_IIC_ReadByte(1);	// 发送应答信号
				}
			}					
			GT911_IIC_Stop();	// 停止IIC通信
			status = SUCCESS;
		}
	}
	GT911_IIC_Stop();	// 停止IIC通信
	return (status);	
}

#endif
/*************************************************************************************************************************************
*	函 数 名: PanelRecognition
*	入口参数: 无
*	返 回 值: 无    
*	函数功能: 识别屏幕的版本
*	说    明: 在 RGB070M1-800*480 V1.1 之前的硬件版本，触摸屏的分辨率为1024*600，
*				 为了程序上的兼容，这里进行判断处理，旧版本的RST和INT引脚并没有连接到核心板，
*				 因此可以根据这两个引脚的电平状态进行识别，此段代码只对旧版的7寸屏有用，
*				 其它尺寸的屏幕无需理会
************************************************************************************************************************************/

// void	PanelRecognition (void)
// {
// 	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
// 	GT911_INT_CLK_ENABLE;	//初始化IO口时钟
// 	GT911_RST_CLK_ENABLE;		

		
// 	GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;      		//	输入模式
// 	GPIO_InitStruct.Pull  = GPIO_PULLDOWN;		 			//	下拉输入
// 	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;    	// 速度等级
// 	GPIO_InitStruct.Pin   = GT911_INT_PIN ;  				// 初始化 INT 引脚
	
// 	HAL_GPIO_Init(GT911_INT_PORT, &GPIO_InitStruct);			

// 	GPIO_InitStruct.Pin  = GT911_RST_PIN; 					//	RST
// 	HAL_GPIO_Init(GT911_RST_PORT, &GPIO_InitStruct);					   

// 	GT911_IIC_Delay(4000);		// 延时
	
// 	//	旧版本的RST和INT引脚并没有连接到核心板，因此可以根据这两个引脚的电平状态进行识别，
// 	//	新版本的硬件这两个脚做了上拉处理
// 	if( (HAL_GPIO_ReadPin(GT911_RST_PORT,GT911_RST_PIN) != 1) && (HAL_GPIO_ReadPin(GT911_INT_PORT,GT911_INT_PIN) != 1)  )	
// 	{
// 		// 在 V1.1 之前的硬件版本，触摸屏的分辨率为1024*600，为了程序上的兼容，这里进行判断处理
// 		//	该变量标志主要用于判断是否需要软件修改采集到的触摸坐标
// 		// 此段代码只对旧版的7寸屏有用，其它尺寸的屏幕无需理会
// 		Modify_Flag	= 1;			
// 	}
// }

/*************************************************************************************************************************************
*	函 数 名: GT911_Init
*	入口参数: 无
*	返 回 值: SUCCESS  - 初始化成功
*            ERROR 	 - 错误，未检测到触摸屏	
*	函数功能: 触摸IC初始化，并读取相应信息发送到串口
*	说    明: 初始化触摸面板
************************************************************************************************************************************/

uint8_t GT911_Init(void)
{
	uint8_t GT9XX_Info[11];	// 触摸屏IC信息
	uint8_t cfgVersion = 0;	// 触摸配置版本

	
	// 识别屏幕的版本，在 RGB070M1-800*480 V1.1以及之后的硬件版本，无需理会此段代码	
	// 此段代码只对旧版的7寸屏有用，其它尺寸的屏幕无需理会
	// PanelRecognition();			
	
	GT911_IIC_GPIO_Config(); 	// 初始化IIC引脚
	GT9XX_Reset();					// 复位IC

#ifdef SOFTWARE_IIC		
	GT9XX_ReadReg (GT9XX_ID_ADDR,11,GT9XX_Info);		// 读触摸屏IC信息
	GT9XX_ReadReg (GT9XX_CFG_ADDR,1,&cfgVersion);	// 读触摸配置版本
#else
	GT911_IIC_ReadReg(GT9XX_ID_ADDR,11,GT9XX_Info);		// 读触摸屏IC信息
	GT911_IIC_ReadReg(GT9XX_CFG_ADDR,1,&cfgVersion);	// 读触摸配置版本
#endif

	if( GT9XX_Info[0] == '9' )	//判断第一个字符是否为 9
	{
		DC_LOG_INFO("Touch ID: GT%.4s ",GT9XX_Info);	//打印触摸芯片的ID
		DC_LOG_INFO("固件版本： 0X%.4x",(GT9XX_Info[5]<<8) + GT9XX_Info[4]);	// 芯片固件版本
		DC_LOG_INFO("触摸分辨率：%d * %d",(GT9XX_Info[7]<<8) + GT9XX_Info[6],(GT9XX_Info[9]<<8) +GT9XX_Info[8]);	// 当前触摸分辨率		
		DC_LOG_INFO("触摸参数配置版本： 0X%.2x ",cfgVersion);	// 触摸配置版本	

/*---------版本识别，RGB070M1-800*480 V1.1以及之后的硬件版本或者其它尺寸的屏幕，无需理会此段代码-----*/	
		
		if( ( (GT9XX_Info[7]<<8) + GT9XX_Info[6] ) == 1024 )		// 判断触摸屏的X轴分辨率是否为1024
		{
			// 在 RGB070M1-800*480 V1.1 之前的硬件版本，触摸屏的分辨率为1024*600，为了程序上的兼容，这里进行判断处理
			//	该变量标志主要用于判断是否需要软件修改采集到的触摸坐标
			Modify_Flag	= 1;	
		}
		else if( ( (GT9XX_Info[7]<<8) + GT9XX_Info[6] ) == 800 )	// 触摸屏的X轴分辨率为800
		{
			Modify_Flag	= 0;	// 置0标志位，无需做处理
		}
		
/*-------------------------------------------------------------------------------------------------*/			
		return SUCCESS;
	}
	else
	{
		DC_LOG_ERROR("Touch Error");	//错误，未检测到触摸屏
		return ERROR;
	}

}

/*************************************************************************************************************************************
*	函 数 名: GT911_Scan
*	入口参数: 无
*	返 回 值: 无
*	函数功能: 触摸扫描
*	说    明: 在程序里周期性的调用该函数，用以检测触摸操作，触摸信息存储在 touchInfo 结构体
************************************************************************************************************************************/

void GT911_Scan(void)
{
 	uint8_t  touchData[2 + 8 * GT911_MAX ]; 		// 用于存储触摸数据
	uint8_t  i = 0;	
#ifdef SOFTWARE_IIC	
	GT9XX_ReadReg (GT9XX_READ_ADDR,2 + 8 * GT911_MAX ,touchData);	// 读数据
	GT9XX_WriteData (GT9XX_READ_ADDR,0);									//	清除触摸芯片的寄存器标志位
#else
	GT911_IIC_ReadReg(GT9XX_READ_ADDR,2 + 8 * GT911_MAX ,touchData);	// 读数据
	GT911_IIC_WriteReg(GT9XX_READ_ADDR, 1, 0);									//	清除触摸芯片的寄存器标志位
#endif

	touchInfo.num = touchData[0] & 0x0f;									// 取当前的触摸点数
	
	if ( (touchInfo.num >= 1) && (touchInfo.num <=5) ) 	//	当触摸数在 1-5 之间时
	{
		for(i=0;i<touchInfo.num;i++)		// 取相应的触摸坐标
		{
			touchInfo.y[i] = (touchData[5+8*i]<<8) | touchData[4+8*i];	// 获取Y坐标
			touchInfo.x[i] = (touchData[3+8*i]<<8) | touchData[2+8*i];	//	获取X坐标
		    // printf("触摸id[%d]: X %d Y %d",i,touchInfo.x[i],touchInfo.y[i]);	// 当前触摸分辨率	
/*---------版本识别，RGB070M1-800*480 V1.1以及之后的硬件版本或者其它尺寸的屏幕，无需理会此段代码-----*/	
	
			// 在 V1.1 之前的硬件版本，触摸屏的分辨率为1024*600，为了程序上的兼容，这里进行判断处理
			//	该变量标志主要用于判断是否需要软件修改采集到的触摸坐标
			if( Modify_Flag == 1)
			{
				touchInfo.y[i] *= 0.8;		// 将1024*600分辨率的触摸坐标换算成800*480的分辨率
				touchInfo.x[i] *= 0.78;		// 将1024*600分辨率的触摸坐标换算成800*480的分辨率
			}		
/*-------------------------------------------------------------------------------------------------*/			
			
		}
		rotation_gt911(&touchInfo);
		touchInfo.flag = 1;	// 触摸标志位置1，代表有触摸动作发生
	}
	else                       
	{
		touchInfo.flag = 0;	// 触摸标志位置0，无触摸动作
	}
}

void rotation_gt911(volatile TouchStructure *touch_structure)
{

for (int i = 0; i< GT911_MAX; i++){
	uint16_t mid;
#ifdef ROTATION_RIGHT

    mid = touch_structure->x[i];
    touch_structure->x[i] = GT911_WIDTH - touch_structure->y[i];
   	touch_structure->y[i] = mid;
#endif

#ifdef ROTATION_LEFT
    mid = GT911_HEIGHT -  touch_structure->x[i];
    touch_structure->x[i] = touch_structure->y[i];
   	touch_structure->y[i] = mid;
#endif

#ifdef ROTATION_UPSIDE_DOWN
    touch_structure->x[i] = GT911_WIDTH - touch_structure->x[i];
   	touch_structure->y[i] = GT911_HEIGHT - touch_structure->y[i];
#endif

#ifdef ROTATION_NONE
	// pass
#endif
}
}
/*************************************************************************************************************************************************************************************************FANKE****/
