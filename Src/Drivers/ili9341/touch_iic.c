/***
	************************************************************************************************************************
	*	@file  	GT911_iic.c
	*	@version V1.0
	*  @date    2021-3-22
	*	@author  ���ͿƼ�
	*	@brief   ������IIC�ӿ���غ���
   ************************************************************************************************************************
   *  @description
	*
	*	ʵ��ƽ̨������STM32H743IIT6���İ� ���ͺţ�FK743M1-IIT6��
	*	�Ա���ַ��https://shop212360197.taobao.com
	*	QQ����Ⱥ��536665479
	*		
>>>>>	�ļ�˵����
	*
	*  1.��������ص�IIC����
	* 	2.ʹ��ģ��IIC
	*	3.ͨ���ٶ�Ĭ��Ϊ100KHz
	*
	************************************************************************************************************************
***/

#include "touch_iic.h"


i2c_handle_type hi2cx;
i2c_status_type i2c_status;

/*****************************************************************************************
*	�� �� ��: GT911_IIC_GPIO_Config
*	��ڲ���: ��
*	�� �� ֵ: ��
*	��������: ��ʼ��IIC��GPIO��,�������
*	˵    ��: ����IICͨ���ٶȲ��ߣ������IO���ٶ�����Ϊ2M����
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
*	�� �� ��: GT911_IIC_Delay
*	��ڲ���: a - ��ʱʱ��
*	�� �� ֵ: ��
*	��������: ����ʱ����
*	˵    ��: Ϊ����ֲ�ļ�����Ҷ���ʱ����Ҫ�󲻸ߣ����Բ���Ҫʹ�ö�ʱ������ʱ
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
*	�� �� ��: GT911_IIC_INT_Out
*	��ڲ���: ��
*	�� �� ֵ: ��
*	��������: ����IIC��INT��Ϊ���ģʽ
*	˵    ��: ��
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
*	�� �� ��: GT911_IIC_INT_In
*	��ڲ���: ��
*	�� �� ֵ: ��
*	��������: ����IIC��INT��Ϊ����ģʽ
*	˵    ��: ��
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
*	�� �� ��: GT911_IIC_Start
*	��ڲ���: ��
*	�� �� ֵ: ��
*	��������: IIC��ʼ�ź�
*	˵    ��: ��SCL���ڸߵ�ƽ�ڼ䣬SDA�ɸߵ�������Ϊ��ʼ�ź�
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
*	�� �� ��: GT911_IIC_Stop
*	��ڲ���: ��
*	�� �� ֵ: ��
*	��������: IICֹͣ�ź�
*	˵    ��: ��SCL���ڸߵ�ƽ�ڼ䣬SDA�ɵ͵�������Ϊ��ʼ�ź�
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
*	�� �� ��: GT911_IIC_ACK
*	��ڲ���: ��
*	�� �� ֵ: ��
*	��������: IICӦ���ź�
*	˵    ��: ��SCLΪ�ߵ�ƽ�ڼ䣬SDA�������Ϊ�͵�ƽ������Ӧ���ź�
******************************************************************************************/

void GT911_IIC_ACK(void)
{
	GT911_IIC_SCL(0);
	GT911_IIC_Delay(IIC_DelayVaule);
	GT911_IIC_SDA(0);
	GT911_IIC_Delay(IIC_DelayVaule);	
	GT911_IIC_SCL(1);
	GT911_IIC_Delay(IIC_DelayVaule);
	
	GT911_IIC_SCL(0);		// SCL�����ʱ��SDAӦ�������ߣ��ͷ�����
	GT911_IIC_SDA(1);		
	
	GT911_IIC_Delay(IIC_DelayVaule);

}

/*****************************************************************************************
*	�� �� ��: GT911_IIC_NoACK
*	��ڲ���: ��
*	�� �� ֵ: ��
*	��������: IIC��Ӧ���ź�
*	˵    ��: ��SCLΪ�ߵ�ƽ�ڼ䣬��SDA����Ϊ�ߵ�ƽ��������Ӧ���ź�
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
*	�� �� ��: GT911_IIC_WaitACK
*	��ڲ���: ��
*	�� �� ֵ: ��
*	��������: �ȴ������豸����Ӧ���ź�
*	˵    ��: ��SCLΪ�ߵ�ƽ�ڼ䣬����⵽SDA����Ϊ�͵�ƽ��������豸��Ӧ����
******************************************************************************************/

uint8_t GT911_IIC_WaitACK(void)
{
	GT911_IIC_SDA(1);
	GT911_IIC_Delay(IIC_DelayVaule);
	GT911_IIC_SCL(1);
	GT911_IIC_Delay(IIC_DelayVaule);	
	
	if( gpio_input_data_bit_read(GPIOA, GPIO_PINS_1) != 0) //�ж��豸�Ƿ���������Ӧ		
	{
		GT911_IIC_SCL(0);	
		GT911_IIC_Delay( IIC_DelayVaule );		
		return ACK_ERR;	//��Ӧ��
	}
	else
	{
		GT911_IIC_SCL(0);	
		GT911_IIC_Delay( IIC_DelayVaule );		
		return ACK_OK;	//Ӧ������
	}
}

/*****************************************************************************************
*	�� �� ��:	GT911_IIC_WriteByte
*	��ڲ���:	IIC_Data - Ҫд���8λ����
*	�� �� ֵ:	ACK_OK  - �豸��Ӧ����
*          	ACK_ERR - �豸��Ӧ����
*	��������:	дһ�ֽ�����
*	˵    ��:��λ��ǰ
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

	return GT911_IIC_WaitACK(); //�ȴ��豸��Ӧ
}

/*****************************************************************************************
*	�� �� ��:	GT911_IIC_ReadByte
*	��ڲ���:	ACK_Mode - ��Ӧģʽ������1�򷢳�Ӧ���źţ�����0������Ӧ���ź�
*	�� �� ֵ:	ACK_OK  - �豸��Ӧ����
*          	ACK_ERR - �豸��Ӧ����
*	��������:��һ�ֽ�����
*	˵    ��:1.��λ��ǰ
*				2.Ӧ�������������һ�ֽ�����ʱ���ͷ�Ӧ���ź�
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
	
	if ( ACK_Mode == 1 )				//	Ӧ���ź�
		GT911_IIC_ACK();
	else
		GT911_IIC_NoACK();		 	// ��Ӧ���ź�
	
	return IIC_Data; 
}

/********************************************************************************************/
#endif

#ifdef HARDWARE_IIC
/*************************************************************************************************************************************
*	�� �� ��:	GT9XX_WriteReg
*	��ڲ���:	addr - Ҫд��ļĴ��������׵�ַ
*					cnt  - ���ݳ���
*					value - Ҫд���������
*	�� �� ֵ:	SUCCESS - �����ɹ�
*					ERROR	  - ����ʧ��
*	��������:	GT9XX д�Ĵ���
*	˵    ��:	��оƬ�ļĴ�����д��ָ�����ȵ�����
************************************************************************************************************************************/

uint8_t GT911_IIC_WriteReg(uint16_t addr, uint8_t cnt, uint8_t *value)
{
	uint8_t status = SUCCESS;
#ifdef GT911_USE_DMA
	if((i2c_memory_write_dma(&hi2cx, I2C_MEM_ADDR_WIDIH_16, GT9XX_IIC_WADDR, addr, value, cnt, I2C_TIMEOUT)) != I2C_OK){
		status = ERROR;		// д��ʧ��
	}
#else
	if((i2c_memory_write(&hi2cx, I2C_MEM_ADDR_WIDIH_16, GT9XX_IIC_WADDR, addr, value, cnt, I2C_TIMEOUT)) != I2C_OK){
		status = ERROR;		// д��ʧ��
	}
#endif
	return status;	
}

/*************************************************************************************************************************************
*	�� �� ��:	GT9XX_ReadReg
*	��ڲ���:	addr - Ҫ��ȡ�ļĴ��������׵�ַ
*					cnt  - ���ݳ���
*					value - Ҫ��ȡ��������
*	�� �� ֵ:	SUCCESS - �����ɹ�
*					ERROR	  - ����ʧ��
*	��������:	GT9XX ���Ĵ���
*	˵    ��:	��оƬ�ļĴ�������ȡָ�����ȵ�����
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