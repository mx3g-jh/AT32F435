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


i2c_handle_type hi2cx;
i2c_status_type i2c_status;

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

#ifdef SOFTWARE_IIC
    /* configure key pin as input with pull-down */
    gpio_initstructure.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
    gpio_initstructure.gpio_out_type  = GPIO_OUTPUT_OPEN_DRAIN;
    gpio_initstructure.gpio_mode = GPIO_MODE_OUTPUT;
    gpio_initstructure.gpio_pull = GPIO_PULL_NONE;
	gpio_initstructure.gpio_pins           = GPIO_PINS_0 | GPIO_PINS_1;
	gpio_init(GPIOA, &gpio_initstructure);
#endif
    gpio_initstructure.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
    gpio_initstructure.gpio_out_type  = GPIO_OUTPUT_PUSH_PULL;
    gpio_initstructure.gpio_mode = GPIO_MODE_OUTPUT;
    gpio_initstructure.gpio_pull = GPIO_PULL_UP;
	gpio_initstructure.gpio_pins           = GPIO_PINS_2 | GPIO_PINS_3;
	gpio_init(GPIOA, &gpio_initstructure);

#ifdef SOFTWARE_IIC
	gpio_bits_set(GPIOA,GPIO_PINS_0);
	gpio_bits_set(GPIOA,GPIO_PINS_1);
#endif
	gpio_bits_reset(GPIOA,GPIO_PINS_2);
	gpio_bits_set(GPIOA,GPIO_PINS_3);

#ifdef HARDWARE_IIC
	//hardware iic
	/* i2c config */
	hi2cx.i2cx = I2C2;
  	i2c_config(&hi2cx);
#endif
}

#ifdef HARDWARE_IIC
/**
  * @brief  initializes peripherals used by the i2c.
  * @param  none
  * @retval none
  */
void i2c_lowlevel_init(i2c_handle_type* hi2c)
{
  gpio_init_type gpio_init_structure;

  if(hi2c->i2cx == I2C2)
  {
    /* i2c periph clock enable */
    crm_periph_clock_enable(CRM_I2C2_PERIPH_CLOCK, TRUE);
    crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);

    /* gpio configuration */
    gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE0, GPIO_MUX_4);

    gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE1, GPIO_MUX_4);

    /* configure i2c pins: scl */
    gpio_init_structure.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
    gpio_init_structure.gpio_mode           = GPIO_MODE_MUX;
    gpio_init_structure.gpio_out_type       = GPIO_OUTPUT_OPEN_DRAIN;
    gpio_init_structure.gpio_pull           = GPIO_PULL_UP;

    gpio_init_structure.gpio_pins           = GPIO_PINS_0;
    gpio_init(GPIOA, &gpio_init_structure);

    /* configure i2c pins: sda */
    gpio_init_structure.gpio_pins           = GPIO_PINS_1;
    gpio_init(GPIOA, &gpio_init_structure);

#ifdef GT911_USE_DMA
    /* configure and enable i2c interrupt */
    // nvic_irq_enable(I2C2_EVT_IRQn, 0, 0);
    // nvic_irq_enable(I2C2_ERR_IRQn, 0, 0);

    /* configure and enable i2c dma channel interrupt */
    // nvic_irq_enable(DMA1_Channel2_IRQn, 0, 0);
    // nvic_irq_enable(DMA1_Channel3_IRQn, 0, 0);

    /* i2c dma tx and rx channels configuration */
    /* enable the dma clock */
    crm_periph_clock_enable(CRM_DMA1_PERIPH_CLOCK, TRUE);

    /* i2c dma channel configuration */
    dma_reset(hi2c->dma_tx_channel);
    dma_reset(hi2c->dma_rx_channel);

    hi2c->dma_tx_channel = DMA1_CHANNEL2;
    hi2c->dma_rx_channel = DMA1_CHANNEL3;

    hi2c->dma_init_struct.peripheral_base_addr    = (uint32_t)&hi2c->i2cx->txdt;
    hi2c->dma_init_struct.memory_base_addr        = 0;
    hi2c->dma_init_struct.direction               = DMA_DIR_MEMORY_TO_PERIPHERAL;
    hi2c->dma_init_struct.buffer_size             = 0xFFFF;
    hi2c->dma_init_struct.peripheral_inc_enable   = FALSE;
    hi2c->dma_init_struct.memory_inc_enable       = TRUE;
    hi2c->dma_init_struct.peripheral_data_width   = DMA_PERIPHERAL_DATA_WIDTH_BYTE;
    hi2c->dma_init_struct.memory_data_width       = DMA_MEMORY_DATA_WIDTH_BYTE;
    hi2c->dma_init_struct.loop_mode_enable        = FALSE;
    hi2c->dma_init_struct.priority                = DMA_PRIORITY_LOW;

    dma_init(hi2c->dma_tx_channel, &hi2c->dma_init_struct);
    dma_init(hi2c->dma_rx_channel, &hi2c->dma_init_struct);

    dmamux_init(DMA1MUX_CHANNEL2, DMAMUX_DMAREQ_ID_I2C2_TX);
    dmamux_init(DMA1MUX_CHANNEL3, DMAMUX_DMAREQ_ID_I2C2_RX);

    dmamux_enable(DMA1, TRUE);

#endif
    /* config i2c */
    i2c_init(hi2c->i2cx, 0x0F, I2Cx_CLKCTRL);

    i2c_own_address1_set(hi2c->i2cx, I2C_ADDRESS_MODE_7BIT, GT9XX_IIC_WADDR);
	printf("TouchPad GT911 init\r\n");
  }
}

#endif

#ifdef SOFTWARE_IIC
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
#endif
/*****************************************************************************************
*	函 数 名: GT911_IIC_INT_Out
*	入口参数: 无
*	返 回 值: 无
*	函数功能: 配置IIC的INT脚为输出模式
*	说    明: 无
******************************************************************************************/

void GT911_INT_Out(void)
{
	gpio_init_type gpio_initstructure;
	gpio_default_para_init(&gpio_initstructure);

    /* configure key pin as input with pull-down */
    gpio_initstructure.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
    gpio_initstructure.gpio_out_type  = GPIO_OUTPUT_PUSH_PULL;
    gpio_initstructure.gpio_mode = GPIO_MODE_OUTPUT;
    gpio_initstructure.gpio_pull = GPIO_PULL_UP;
	gpio_initstructure.gpio_pins           = GPIO_PINS_2;
	gpio_init(GPIOA, &gpio_initstructure);
	
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

}

#ifdef SOFTWARE_IIC
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
#endif

#ifdef HARDWARE_IIC
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

uint8_t GT911_IIC_WriteReg(uint16_t addr, uint8_t cnt, uint8_t *value)
{
	uint8_t status = SUCCESS;
#ifdef GT911_USE_DMA
	if((i2c_memory_write_dma(&hi2cx, I2C_MEM_ADDR_WIDIH_16, GT9XX_IIC_WADDR, addr, value, cnt, I2C_TIMEOUT)) != I2C_OK){
		status = ERROR;		// 写入失败
	}
#else
	if((i2c_memory_write(&hi2cx, I2C_MEM_ADDR_WIDIH_16, GT9XX_IIC_WADDR, addr, value, cnt, I2C_TIMEOUT)) != I2C_OK){
		status = ERROR;		// 写入失败
	}
#endif
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

uint8_t GT911_IIC_ReadReg(uint16_t addr, uint8_t cnt, uint8_t *value)
{
	uint8_t status = SUCCESS;
#ifdef GT911_USE_DMA
	if(i2c_memory_read_dma(&hi2cx, I2C_MEM_ADDR_WIDIH_16, GT9XX_IIC_RADDR, addr, value, cnt , I2C_TIMEOUT) != I2C_OK)
	{
		status = ERROR;
	}
#else
	if(i2c_memory_read(&hi2cx, I2C_MEM_ADDR_WIDIH_16, GT9XX_IIC_RADDR, addr, value, cnt , I2C_TIMEOUT) != I2C_OK)
	{
		status = ERROR;
	}
#endif
	return (status);	
}

#endif