/***
	************************************************************************************************************************
	*	@file  	GT911_iic.c
	*	@version V1.0
	*  @date    2021-3-22
	*	@author  反客科技
	*	@brief   触摸屏IIC接口相关函数
   ************************************************************************************************************************
   *  @description
	*
	*	实验平台：反客STM32H743IIT6核心板 （型号：FK743M1-IIT6）
	*	淘宝地址：https://shop212360197.taobao.com
	*	QQ交流群：536665479
	*		
>>>>>	文件说明：
	*
	*  1.触摸屏相关的IIC函数
	* 	2.使用模拟IIC
	*	3.通信速度默认为100KHz
	*
	************************************************************************************************************************
***/

#include "touch_iic.h"  


/*****************************************************************************************
*	函 数 名: GT911_IIC_GPIO_Config
*	入口参数: 无
*	返 回 值: 无
*	函数功能: 初始化IIC的GPIO口,推挽输出
*	说    明: 由于IIC通信速度不高，这里的IO口速度配置为2M即可
******************************************************************************************/
void GT911_IIC_GPIO_Config(void)
{

	crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE); 

	gpio_init_type gpio_initstructure;
	gpio_default_para_init(&gpio_initstructure);

    /* configure key pin as input with pull-down */
    gpio_initstructure.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
    gpio_initstructure.gpio_out_type  = GPIO_OUTPUT_OPEN_DRAIN;
    gpio_initstructure.gpio_mode = GPIO_MODE_OUTPUT;
    gpio_initstructure.gpio_pull = GPIO_PULL_NONE;
	gpio_initstructure.gpio_pins           = GPIO_PINS_0 | GPIO_PINS_1;
	gpio_init(GPIOA, &gpio_initstructure);

    gpio_initstructure.gpio_out_type  = GPIO_OUTPUT_PUSH_PULL;
    gpio_initstructure.gpio_mode = GPIO_MODE_OUTPUT;
    gpio_initstructure.gpio_pull = GPIO_PULL_UP;
	gpio_initstructure.gpio_pins           = GPIO_PINS_2 | GPIO_PINS_3;
	gpio_init(GPIOA, &gpio_initstructure);

	gpio_bits_set(GPIOA,GPIO_PINS_0);
	gpio_bits_set(GPIOA,GPIO_PINS_1);
	gpio_bits_reset(GPIOA,GPIO_PINS_2);
	gpio_bits_set(GPIOA,GPIO_PINS_3);
}

// void GT911_IIC_GPIO_Config (void)
// {
// 	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
// 	GT911_IIC_SCL_CLK_ENABLE;	//初始化IO口时钟
// 	GT911_IIC_SDA_CLK_ENABLE;
// 	GT911_INT_CLK_ENABLE;	
// 	GT911_RST_CLK_ENABLE;	
	
// 	GPIO_InitStruct.Pin 			= GT911_IIC_SCL_PIN;				// SCL引脚
// 	GPIO_InitStruct.Mode 		= GPIO_MODE_OUTPUT_OD;			// 开漏输出
// 	GPIO_InitStruct.Pull 		= GPIO_NOPULL;						// 不带上下拉
// 	GPIO_InitStruct.Speed 		= GPIO_SPEED_FREQ_LOW;			// 速度等级 
// 	HAL_GPIO_Init(GT911_IIC_SCL_PORT, &GPIO_InitStruct);

// 	GPIO_InitStruct.Pin 			= GT911_IIC_SDA_PIN;				// SDA引脚
// 	HAL_GPIO_Init(GT911_IIC_SDA_PORT, &GPIO_InitStruct);		

	
// 	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;      			// 推挽输出
// 	GPIO_InitStruct.Pull  = GPIO_PULLUP;		 					// 上拉	
	
// 	GPIO_InitStruct.Pin = GT911_INT_PIN; 							//	INT
// 	HAL_GPIO_Init(GT911_INT_PORT, &GPIO_InitStruct);				

// 	GPIO_InitStruct.Pin = GT911_RST_PIN; 							//	RST
// 	HAL_GPIO_Init(GT911_RST_PORT, &GPIO_InitStruct);					   

// 	HAL_GPIO_WritePin(GT911_IIC_SCL_PORT, GT911_IIC_SCL_PIN, GPIO_PIN_SET);		// SCL输出高电平
// 	HAL_GPIO_WritePin(GT911_IIC_SDA_PORT, GT911_IIC_SDA_PIN, GPIO_PIN_SET);    // SDA输出高电平
// 	HAL_GPIO_WritePin(GT911_INT_PORT, 	  GT911_INT_PIN,     GPIO_PIN_RESET);  // INT输出低电平
// 	HAL_GPIO_WritePin(GT911_RST_PORT,     GT911_RST_PIN,     GPIO_PIN_SET);    // RST输出高电平

// }

/*****************************************************************************************
*	函 数 名: GT911_IIC_Delay
*	入口参数: a - 延时时间
*	返 回 值: 无
*	函数功能: 简单延时函数
*	说    明: 为了移植的简便性且对延时精度要求不高，所以不需要使用定时器做延时
******************************************************************************************/

void GT911_IIC_Delay(uint32_t a)
{
	volatile uint16_t i;
	while (a --)				
	{
		for (i = 0; i < 8; i++);
	}
}

/*****************************************************************************************
*	函 数 名: GT911_IIC_INT_Out
*	入口参数: 无
*	返 回 值: 无
*	函数功能: 配置IIC的INT脚为输出模式
*	说    明: 无
******************************************************************************************/

void GT911_INT_Out(void)
{

	// crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE); 

	gpio_init_type gpio_initstructure;
	gpio_default_para_init(&gpio_initstructure);

    /* configure key pin as input with pull-down */
    gpio_initstructure.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
    gpio_initstructure.gpio_out_type  = GPIO_OUTPUT_PUSH_PULL;
    gpio_initstructure.gpio_mode = GPIO_MODE_OUTPUT;
    gpio_initstructure.gpio_pull = GPIO_PULL_UP;
	gpio_initstructure.gpio_pins           = GPIO_PINS_2;
	gpio_init(GPIOA, &gpio_initstructure);

	// GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	// GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;      	// 输出模式
	// GPIO_InitStruct.Pull  = GPIO_PULLUP;		 			// 上拉	
	// GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;    	// 速度等级
	// GPIO_InitStruct.Pin   = GT911_INT_PIN ;  				// 初始化 INT 引脚
	
	// HAL_GPIO_Init(GT911_INT_PORT, &GPIO_InitStruct);		
}

/*****************************************************************************************
*	函 数 名: GT911_IIC_INT_In
*	入口参数: 无
*	返 回 值: 无
*	函数功能: 配置IIC的INT脚为输入模式
*	说    明: 无
******************************************************************************************/

void GT911_INT_In(void)
{

	gpio_init_type gpio_initstructure;
	gpio_default_para_init(&gpio_initstructure);

    /* configure key pin as input with pull-down */
    gpio_initstructure.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
    gpio_initstructure.gpio_out_type  = GPIO_OUTPUT_PUSH_PULL;
    gpio_initstructure.gpio_mode = GPIO_MODE_INPUT;
    gpio_initstructure.gpio_pull = GPIO_PULL_NONE;
	gpio_initstructure.gpio_pins           = GPIO_PINS_2;
	gpio_init(GPIOA, &gpio_initstructure);

	// GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	// GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;      		// 输入模式
	// GPIO_InitStruct.Pull  = GPIO_NOPULL;		 			// 浮空	
	// GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;    	// 速度等级
	// GPIO_InitStruct.Pin   = GT911_INT_PIN ;  				// 初始化 INT 引脚
	
	// HAL_GPIO_Init(GT911_INT_PORT, &GPIO_InitStruct);		

}

/*****************************************************************************************
*	函 数 名: GT911_IIC_Start
*	入口参数: 无
*	返 回 值: 无
*	函数功能: IIC起始信号
*	说    明: 在SCL处于高电平期间，SDA由高到低跳变为起始信号
******************************************************************************************/

void GT911_IIC_Start(void)
{
	GT911_IIC_SDA(1);		
	GT911_IIC_SCL(1);
	GT911_IIC_Delay(IIC_DelayVaule);
	
	GT911_IIC_SDA(0);
	GT911_IIC_Delay(IIC_DelayVaule);
	GT911_IIC_SCL(0);
	GT911_IIC_Delay(IIC_DelayVaule);
}

/*****************************************************************************************
*	函 数 名: GT911_IIC_Stop
*	入口参数: 无
*	返 回 值: 无
*	函数功能: IIC停止信号
*	说    明: 在SCL处于高电平期间，SDA由低到高跳变为起始信号
******************************************************************************************/

void GT911_IIC_Stop(void)
{
	GT911_IIC_SCL(0);
	GT911_IIC_Delay(IIC_DelayVaule);
	GT911_IIC_SDA(0);
	GT911_IIC_Delay(IIC_DelayVaule);
	
	GT911_IIC_SCL(1);
	GT911_IIC_Delay(IIC_DelayVaule);
	GT911_IIC_SDA(1);
	GT911_IIC_Delay(IIC_DelayVaule);
}

/*****************************************************************************************
*	函 数 名: GT911_IIC_ACK
*	入口参数: 无
*	返 回 值: 无
*	函数功能: IIC应答信号
*	说    明: 在SCL为高电平期间，SDA引脚输出为低电平，产生应答信号
******************************************************************************************/

void GT911_IIC_ACK(void)
{
	GT911_IIC_SCL(0);
	GT911_IIC_Delay(IIC_DelayVaule);
	GT911_IIC_SDA(0);
	GT911_IIC_Delay(IIC_DelayVaule);	
	GT911_IIC_SCL(1);
	GT911_IIC_Delay(IIC_DelayVaule);
	
	GT911_IIC_SCL(0);		// SCL输出低时，SDA应立即拉高，释放总线
	GT911_IIC_SDA(1);		
	
	GT911_IIC_Delay(IIC_DelayVaule);

}

/*****************************************************************************************
*	函 数 名: GT911_IIC_NoACK
*	入口参数: 无
*	返 回 值: 无
*	函数功能: IIC非应答信号
*	说    明: 在SCL为高电平期间，若SDA引脚为高电平，产生非应答信号
******************************************************************************************/

void GT911_IIC_NoACK(void)
{
	GT911_IIC_SCL(0);	
	GT911_IIC_Delay(IIC_DelayVaule);
	GT911_IIC_SDA(1);
	GT911_IIC_Delay(IIC_DelayVaule);
	GT911_IIC_SCL(1);
	GT911_IIC_Delay(IIC_DelayVaule);
	
	GT911_IIC_SCL(0);
	GT911_IIC_Delay(IIC_DelayVaule);
}

/*****************************************************************************************
*	函 数 名: GT911_IIC_WaitACK
*	入口参数: 无
*	返 回 值: 无
*	函数功能: 等待接收设备发出应答信号
*	说    明: 在SCL为高电平期间，若检测到SDA引脚为低电平，则接收设备响应正常
******************************************************************************************/

uint8_t GT911_IIC_WaitACK(void)
{
	GT911_IIC_SDA(1);
	GT911_IIC_Delay(IIC_DelayVaule);
	GT911_IIC_SCL(1);
	GT911_IIC_Delay(IIC_DelayVaule);	
	
	if( gpio_input_data_bit_read(GPIOA, GPIO_PINS_1) != 0) //判断设备是否有做出响应		
	{
		GT911_IIC_SCL(0);	
		GT911_IIC_Delay( IIC_DelayVaule );		
		return ACK_ERR;	//无应答
	}
	else
	{
		GT911_IIC_SCL(0);	
		GT911_IIC_Delay( IIC_DelayVaule );		
		return ACK_OK;	//应答正常
	}
}

/*****************************************************************************************
*	函 数 名:	GT911_IIC_WriteByte
*	入口参数:	IIC_Data - 要写入的8位数据
*	返 回 值:	ACK_OK  - 设备响应正常
*          	ACK_ERR - 设备响应错误
*	函数功能:	写一字节数据
*	说    明:高位在前
******************************************************************************************/

uint8_t GT911_IIC_WriteByte(uint8_t IIC_Data)
{
	uint8_t i;

	for (i = 0; i < 8; i++)
	{
		GT911_IIC_SDA(IIC_Data & 0x80);
		
		GT911_IIC_Delay( IIC_DelayVaule );
		GT911_IIC_SCL(1);
		GT911_IIC_Delay( IIC_DelayVaule );
		GT911_IIC_SCL(0);		
		if(i == 7)
		{
			GT911_IIC_SDA(1);			
		}
		IIC_Data <<= 1;
	}

	return GT911_IIC_WaitACK(); //等待设备响应
}

/*****************************************************************************************
*	函 数 名:	GT911_IIC_ReadByte
*	入口参数:	ACK_Mode - 响应模式，输入1则发出应答信号，输入0发出非应答信号
*	返 回 值:	ACK_OK  - 设备响应正常
*          	ACK_ERR - 设备响应错误
*	函数功能:读一字节数据
*	说    明:1.高位在前
*				2.应在主机接收最后一字节数据时发送非应答信号
******************************************************************************************/

uint8_t GT911_IIC_ReadByte(uint8_t ACK_Mode)
{
	uint8_t IIC_Data = 0;
	uint8_t i = 0;
	
	for (i = 0; i < 8; i++)
	{
		IIC_Data <<= 1;
		
		GT911_IIC_SCL(1);
		GT911_IIC_Delay( IIC_DelayVaule );
		IIC_Data |= (gpio_input_data_bit_read(GPIOA, GPIO_PINS_1) & 0x01);	
		GT911_IIC_SCL(0);
		GT911_IIC_Delay( IIC_DelayVaule );
	}
	
	if ( ACK_Mode == 1 )				//	应答信号
		GT911_IIC_ACK();
	else
		GT911_IIC_NoACK();		 	// 非应答信号
	
	return IIC_Data; 
}

/********************************************************************************************/
