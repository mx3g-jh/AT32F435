#include "bsp_spi_lcd.h"

void LCD_GPIO_Init(void)
{
	crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE); 
	crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK, TRUE);

	gpio_init_type gpio_initstructure;
	gpio_default_para_init(&gpio_initstructure);

	gpio_initstructure.gpio_out_type       = GPIO_OUTPUT_PUSH_PULL;
	gpio_initstructure.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
	gpio_initstructure.gpio_mode           = GPIO_MODE_MUX;
	gpio_initstructure.gpio_pins           = GPIO_PINS_5 ;
	gpio_init(GPIOA, &gpio_initstructure);
	gpio_initstructure.gpio_pins           = GPIO_PINS_5; 
	gpio_init(GPIOB, &gpio_initstructure);

	gpio_initstructure.gpio_mode           = GPIO_MODE_OUTPUT;
	gpio_initstructure.gpio_pins           = GPIO_PINS_3 | GPIO_PINS_4; 
	gpio_init(GPIOA, &gpio_initstructure);
	gpio_initstructure.gpio_pins           = GPIO_PINS_3 | GPIO_PINS_0; 
	gpio_init(GPIOB, &gpio_initstructure);   

	gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE5, GPIO_MUX_5);
	gpio_pin_mux_config(GPIOB, GPIO_PINS_SOURCE5, GPIO_MUX_5);

	crm_periph_clock_enable(CRM_SPI1_PERIPH_CLOCK, TRUE);

	spi_init_type spi_init_struct;
	spi_default_para_init(&spi_init_struct);
	
	spi_init_struct.transmission_mode = SPI_TRANSMIT_HALF_DUPLEX_TX; 
	spi_init_struct.master_slave_mode = SPI_MODE_MASTER;
	spi_init_struct.mclk_freq_division = SPI_MCLK_DIV_2; 
	spi_init_struct.first_bit_transmission = SPI_FIRST_BIT_MSB;
	spi_init_struct.frame_bit_num = SPI_FRAME_8BIT;
	spi_init_struct.clock_polarity = SPI_CLOCK_POLARITY_HIGH;
	spi_init_struct.clock_phase = SPI_CLOCK_PHASE_2EDGE;
	spi_init_struct.cs_mode_selection = SPI_CS_SOFTWARE_MODE;
	spi_init(SPI1, &spi_init_struct);

	spi_i2s_dma_transmitter_enable(SPI1, TRUE);
			
	spi_enable(SPI1, TRUE);	    
	/* DMA外设 */
	crm_periph_clock_enable(CRM_DMA1_PERIPH_CLOCK, TRUE);

}

/**
 * @brief Set the rotation direction of the display
 * @param m -> rotation parameter(please refer it in st7789.h)
 * @return none
 */
void ST7789_SetRotation(u8 m)
{
	LCD_WR_REG(ST7789_MADCTL);	// MADCTL
	switch (m) {
	case 0:
		LCD_WR_DATA8(ST7789_MADCTL_MX | ST7789_MADCTL_MY | ST7789_MADCTL_RGB);
		break;
	case 1:
		LCD_WR_DATA8(ST7789_MADCTL_MY | ST7789_MADCTL_MV | ST7789_MADCTL_RGB);
		break;
	case 2:
		LCD_WR_DATA8(ST7789_MADCTL_RGB);
		break;
	case 3:
		LCD_WR_DATA8(ST7789_MADCTL_MX | ST7789_MADCTL_MV | ST7789_MADCTL_RGB);
		break;
	default:
		break;
	}
}

void LCD_Writ_Bus(u8 dat) 
{	
  LCD_CS_Clr();
  spi_frame_bit_num_set(SPI1, SPI_FRAME_8BIT);
  spi_i2s_data_transmit(SPI1, dat);
  while(spi_i2s_flag_get(SPI1, SPI_I2S_BF_FLAG) == SET); //等待传输完成
  LCD_CS_Set();	
}

void LCD_WR_DATA8(u8 dat)
{
	LCD_Writ_Bus(dat);
}

void LCD_WR_DATA(u16 dat)
{
	LCD_Writ_Bus(dat>>8);
	LCD_Writ_Bus(dat);
}


void LCD_WR_REG(u8 dat)
{
	LCD_DC_Clr();//写命令
	LCD_Writ_Bus(dat);
	LCD_DC_Set();//写数据
}

void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2)
{
	uint16_t x_start = x1 + X_SHIFT, x_end = x2 + X_SHIFT;
	uint16_t y_start = y1 + Y_SHIFT, y_end = y2 + Y_SHIFT;
	
	/* Column Address set */
	LCD_WR_REG(ST7789_CASET); 
	LCD_WR_DATA(x_start);
	LCD_WR_DATA(x_end);
	/* Row Address set */
	LCD_WR_REG(ST7789_RASET);
	LCD_WR_DATA(y_start);
	LCD_WR_DATA(y_end);

	LCD_WR_REG(0x2c);//储存器写
}

void LCD_Init(void)
{
	LCD_GPIO_Init();//初始化GPIO
	
	LCD_RES_Clr();//复位
	delay_ms(100);
	LCD_RES_Set();
	delay_ms(100);
	
	LCD_BLK_Set();//打开背光
  	delay_ms(100);
	
	LCD_WR_REG(0x11); //Sleep out 
	delay_ms(120);    //Delay 120ms 

	LCD_WR_REG(0x36);
	LCD_WR_DATA8(0x00);

	LCD_WR_REG(0x3A);			
	LCD_WR_DATA8(0x05);

	LCD_WR_REG(0xB2);			
	LCD_WR_DATA8(0x0C);
	LCD_WR_DATA8(0x0C); 
	LCD_WR_DATA8(0x00); 
	LCD_WR_DATA8(0x33); 
	LCD_WR_DATA8(0x33); 			

	ST7789_SetRotation(ST7789_ROTATION);	//	MADCTL (Display Rotation)

	LCD_WR_REG(0xB7);			
	LCD_WR_DATA8(0x35);

	LCD_WR_REG(0xBB);			
	LCD_WR_DATA8(0x19); 
					
	LCD_WR_REG(0xC0);
	LCD_WR_DATA8(0x2C);

	LCD_WR_REG(0xC2);			
	LCD_WR_DATA8(0x01); 
	LCD_WR_REG(0xC3);			
	LCD_WR_DATA8(0x12); 
	LCD_WR_REG(0xC4);			
	LCD_WR_DATA8(0x20); //0x0F:60Hz   

	LCD_WR_REG(0xC6);  //Frame Rate Control in Normal Mode
	LCD_WR_DATA8(0x0F);

	LCD_WR_REG(0xD0);			
	LCD_WR_DATA8(0xA4);
	LCD_WR_DATA8(0xA1); 

	LCD_WR_REG(0xE0);  //Positive Voltage Gamma Control
	LCD_WR_DATA8(0xD0);
	LCD_WR_DATA8(0x04);
	LCD_WR_DATA8(0x0D);
	LCD_WR_DATA8(0x11);
	LCD_WR_DATA8(0x13);
	LCD_WR_DATA8(0x2B);
	LCD_WR_DATA8(0x3F);
	LCD_WR_DATA8(0x54);
	LCD_WR_DATA8(0x4C);
	LCD_WR_DATA8(0x18);
	LCD_WR_DATA8(0x0D);
	LCD_WR_DATA8(0x0B);
	LCD_WR_DATA8(0x1F);
	LCD_WR_DATA8(0x23);  

	LCD_WR_REG(0xE1);  //Negative Voltage Gamma Control
	LCD_WR_DATA8(0xD0);
	LCD_WR_DATA8(0x04);
	LCD_WR_DATA8(0x0C);
	LCD_WR_DATA8(0x11);
	LCD_WR_DATA8(0x13);
	LCD_WR_DATA8(0x2C);
	LCD_WR_DATA8(0x3F);
	LCD_WR_DATA8(0x44);
	LCD_WR_DATA8(0x51);
	LCD_WR_DATA8(0x2F);
	LCD_WR_DATA8(0x1F);
	LCD_WR_DATA8(0x1F);
	LCD_WR_DATA8(0x20);
	LCD_WR_DATA8(0x23);

	LCD_WR_REG(0x21);
	LCD_WR_REG(0x11);
	LCD_WR_REG(0x29);
  	LCD_fill(0,0,240,240,BLACK);
} 

void LCD_fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color)
{          
	u16 i,j; 
	LCD_Address_Set(xsta,ysta,xend-1,yend-1);//设置显示范围
	for(i=ysta;i<yend;i++)
	{													   	 	
		for(j=xsta;j<xend;j++)
		{
			LCD_WR_DATA(color);
		}
	} 					  	    
}


void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 *color)
{
	u16 i,j; 
	LCD_Address_Set(xsta,ysta,xend-1,yend-1);//设置显示范围
	for(i=ysta;i<yend;i++)
	{													   	 	
		for(j=xsta;j<xend;j++)
		{
			LCD_WR_DATA(*color++);
		}
	} 	
}

void LCD_DMA_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 *color)
{
	uint32_t num = (xend-xsta+1)*(yend-ysta+1);
	//printf("num:%d\r\n",num);
	LCD_DC_Set();
	LCD_Address_Set(xsta,ysta,xend-1,yend-1);//设置显示范围

	crm_periph_clock_enable(CRM_DMA1_PERIPH_CLOCK, TRUE);
	
	spi_frame_bit_num_set(SPI1, SPI_FRAME_16BIT);
	
	dma_init_type dma_init_struct;
	dma_reset(DMA1_CHANNEL1);
  	dma_default_para_init(&dma_init_struct);
	dma_init_struct.buffer_size = num;
	dma_init_struct.direction = DMA_DIR_MEMORY_TO_PERIPHERAL;
	dma_init_struct.memory_base_addr = (uint32_t)color;
	dma_init_struct.memory_data_width = DMA_PERIPHERAL_DATA_WIDTH_BYTE;
	dma_init_struct.memory_inc_enable = TRUE;
	dma_init_struct.peripheral_base_addr = (uint32_t)&(SPI1->dt);
	dma_init_struct.peripheral_data_width = DMA_PERIPHERAL_DATA_WIDTH_BYTE;
	dma_init_struct.peripheral_inc_enable = FALSE;
	dma_init_struct.priority = DMA_PRIORITY_MEDIUM;
	dma_init_struct.loop_mode_enable = FALSE;
	
	dma_init(DMA1_CHANNEL1, &dma_init_struct);
	

	dmamux_enable(DMA1, TRUE);
  	dmamux_init(DMA1MUX_CHANNEL1, DMAMUX_DMAREQ_ID_SPI1_TX);
	
	gpio_bits_reset(GPIOA, GPIO_PINS_4); //CS=0	
	dma_channel_enable(DMA1_CHANNEL1, TRUE); //启动传输	
	
	while(!dma_flag_get(DMA1_FDT1_FLAG));
	dma_channel_enable(DMA1_CHANNEL1, FALSE); //启动传输	
	gpio_bits_set(GPIOA, GPIO_PINS_4); //CS=1
}


