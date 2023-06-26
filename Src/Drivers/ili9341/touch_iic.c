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
	
// 	GT911_IIC_SCL_CLK_ENABLE;	//��ʼ��IO��ʱ��
// 	GT911_IIC_SDA_CLK_ENABLE;
// 	GT911_INT_CLK_ENABLE;	
// 	GT911_RST_CLK_ENABLE;	
	
// 	GPIO_InitStruct.Pin 			= GT911_IIC_SCL_PIN;				// SCL����
// 	GPIO_InitStruct.Mode 		= GPIO_MODE_OUTPUT_OD;			// ��©���
// 	GPIO_InitStruct.Pull 		= GPIO_NOPULL;						// ����������
// 	GPIO_InitStruct.Speed 		= GPIO_SPEED_FREQ_LOW;			// �ٶȵȼ� 
// 	HAL_GPIO_Init(GT911_IIC_SCL_PORT, &GPIO_InitStruct);

// 	GPIO_InitStruct.Pin 			= GT911_IIC_SDA_PIN;				// SDA����
// 	HAL_GPIO_Init(GT911_IIC_SDA_PORT, &GPIO_InitStruct);		

	
// 	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;      			// �������
// 	GPIO_InitStruct.Pull  = GPIO_PULLUP;		 					// ����	
	
// 	GPIO_InitStruct.Pin = GT911_INT_PIN; 							//	INT
// 	HAL_GPIO_Init(GT911_INT_PORT, &GPIO_InitStruct);				

// 	GPIO_InitStruct.Pin = GT911_RST_PIN; 							//	RST
// 	HAL_GPIO_Init(GT911_RST_PORT, &GPIO_InitStruct);					   

// 	HAL_GPIO_WritePin(GT911_IIC_SCL_PORT, GT911_IIC_SCL_PIN, GPIO_PIN_SET);		// SCL����ߵ�ƽ
// 	HAL_GPIO_WritePin(GT911_IIC_SDA_PORT, GT911_IIC_SDA_PIN, GPIO_PIN_SET);    // SDA����ߵ�ƽ
// 	HAL_GPIO_WritePin(GT911_INT_PORT, 	  GT911_INT_PIN,     GPIO_PIN_RESET);  // INT����͵�ƽ
// 	HAL_GPIO_WritePin(GT911_RST_PORT,     GT911_RST_PIN,     GPIO_PIN_SET);    // RST����ߵ�ƽ

// }

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

/*****************************************************************************************
*	�� �� ��: GT911_IIC_INT_Out
*	��ڲ���: ��
*	�� �� ֵ: ��
*	��������: ����IIC��INT��Ϊ���ģʽ
*	˵    ��: ��
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
	
	// GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;      	// ���ģʽ
	// GPIO_InitStruct.Pull  = GPIO_PULLUP;		 			// ����	
	// GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;    	// �ٶȵȼ�
	// GPIO_InitStruct.Pin   = GT911_INT_PIN ;  				// ��ʼ�� INT ����
	
	// HAL_GPIO_Init(GT911_INT_PORT, &GPIO_InitStruct);		
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

	// GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	// GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;      		// ����ģʽ
	// GPIO_InitStruct.Pull  = GPIO_NOPULL;		 			// ����	
	// GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;    	// �ٶȵȼ�
	// GPIO_InitStruct.Pin   = GT911_INT_PIN ;  				// ��ʼ�� INT ����
	
	// HAL_GPIO_Init(GT911_INT_PORT, &GPIO_InitStruct);		

}

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
