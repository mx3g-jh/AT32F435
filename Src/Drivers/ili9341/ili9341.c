/* vim: set ai et ts=4 sw=4: */
#include "ili9341.h"

void ILI9341_GPIO_Init(void)
{
	crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE); 
	crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK, TRUE);

	gpio_init_type gpio_initstructure;
	gpio_default_para_init(&gpio_initstructure);

	gpio_initstructure.gpio_out_type       = GPIO_OUTPUT_PUSH_PULL;
	gpio_initstructure.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
	gpio_initstructure.gpio_mode           = GPIO_MODE_MUX;
	gpio_initstructure.gpio_pins           = GPIO_PINS_5 | GPIO_PINS_7;
	gpio_init(GPIOA, &gpio_initstructure);

	gpio_initstructure.gpio_mode           = GPIO_MODE_OUTPUT;
	gpio_initstructure.gpio_pins           = GPIO_PINS_3 | GPIO_PINS_4 | GPIO_PINS_6; 
	gpio_init(GPIOA, &gpio_initstructure);
	gpio_initstructure.gpio_pins           = GPIO_PINS_0; 
	gpio_init(GPIOB, &gpio_initstructure);   

	gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE5, GPIO_MUX_5);
	gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE7, GPIO_MUX_5);

	crm_periph_clock_enable(CRM_SPI1_PERIPH_CLOCK, TRUE);

	spi_init_type spi_init_struct;
	spi_default_para_init(&spi_init_struct);

	spi_init_struct.transmission_mode = SPI_TRANSMIT_HALF_DUPLEX_TX; 
	spi_init_struct.master_slave_mode = SPI_MODE_MASTER;
	spi_init_struct.mclk_freq_division = SPI_MCLK_DIV_3; 
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

void ILI9341_Reset() {
    ILI9341_RES_Clr();
    delay_ms(5);
    ILI9341_RES_Set();
}

void ILI9341_Writ_Bus(u8 dat) 
{	
  ILI9341_CS_Clr();
  spi_frame_bit_num_set(SPI1, SPI_FRAME_8BIT);
  spi_i2s_data_transmit(SPI1, dat);
  while(spi_i2s_flag_get(SPI1, SPI_I2S_BF_FLAG) == SET); //等待传输完成
  ILI9341_CS_Set();	
}


void ILI9341_WR_DATA8(u8 dat)
{
	ILI9341_Writ_Bus(dat);
}

void ILI9341_WR_DATA(u16 dat)
{
	ILI9341_Writ_Bus(dat>>8);
	ILI9341_Writ_Bus(dat);
}

void ILI9341_WR_DATA_LONG(uint8_t* buff, size_t buff_size)
{
    for(uint32_t i = 0; i < buff_size ; i++){
	    ILI9341_Writ_Bus(buff[i]);
    }

}

void ILI9341_WR_REG(u8 dat)
{
	ILI9341_DC_Clr();//写命令
	ILI9341_Writ_Bus(dat);
	ILI9341_DC_Set();//写数据
}

void ILI9341_WriteData(uint8_t* buff, size_t buff_size) {
    ILI9341_DC_Set();//写数据

    // split data in small chunks because HAL can't send more then 64K at once
    while(buff_size > 0) {
        uint16_t chunk_size = buff_size > 32768 ? 32768 : buff_size;
        ILI9341_WR_DATA_LONG(buff,chunk_size);
        buff += chunk_size;
        buff_size -= chunk_size;
    }
}

void ILI9341_SetAddressWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
    // column address set
    ILI9341_WR_REG(0x2A); // CASET
    {
        uint8_t data[] = { (x0 >> 8) & 0xFF, x0 & 0xFF, (x1 >> 8) & 0xFF, x1 & 0xFF };
        ILI9341_WriteData(data, sizeof(data));
    }

    // row address set
    ILI9341_WR_REG(0x2B); // RASET
    {
        uint8_t data[] = { (y0 >> 8) & 0xFF, y0 & 0xFF, (y1 >> 8) & 0xFF, y1 & 0xFF };
        ILI9341_WriteData(data, sizeof(data));
    }

    // write to RAM
    ILI9341_WR_REG(0x2C); // RAMWR
}

void TFT_ILI9341_Init() {
    ILI9341_CS_Clr();
    ILI9341_Reset();
    ILI9341_BLK_Set();
    // command list is based on https://github.com/martnak/STM32-ILI9341

    // SOFTWARE RESET
    ILI9341_WR_REG(0x01);
    delay_ms(1000);
        
    // POWER CONTROL A
    ILI9341_WR_REG(0xCB);
    {
        uint8_t data[] = { 0x39, 0x2C, 0x00, 0x34, 0x02 };
        ILI9341_WriteData(data, sizeof(data));
    }

    // POWER CONTROL B
    ILI9341_WR_REG(0xCF);
    {
        uint8_t data[] = { 0x00, 0xC1, 0x30 };
        ILI9341_WriteData(data, sizeof(data));
    }

    // DRIVER TIMING CONTROL A
    ILI9341_WR_REG(0xE8);
    {
        uint8_t data[] = { 0x85, 0x00, 0x78 };
        ILI9341_WriteData(data, sizeof(data));
    }

    // DRIVER TIMING CONTROL B
    ILI9341_WR_REG(0xEA);
    {
        uint8_t data[] = { 0x00, 0x00 };
        ILI9341_WriteData(data, sizeof(data));
    }

    // POWER ON SEQUENCE CONTROL
    ILI9341_WR_REG(0xED);
    {
        uint8_t data[] = { 0x64, 0x03, 0x12, 0x81 };
        ILI9341_WriteData(data, sizeof(data));
    }

    // PUMP RATIO CONTROL
    ILI9341_WR_REG(0xF7);
    {
        uint8_t data[] = { 0x20 };
        ILI9341_WriteData(data, sizeof(data));
    }

    // POWER CONTROL,VRH[5:0]
    ILI9341_WR_REG(0xC0);
    {
        uint8_t data[] = { 0x23 };
        ILI9341_WriteData(data, sizeof(data));
    }

    // POWER CONTROL,SAP[2:0];BT[3:0]
    ILI9341_WR_REG(0xC1);
    {
        uint8_t data[] = { 0x10 };
        ILI9341_WriteData(data, sizeof(data));
    }

    // VCM CONTROL
    ILI9341_WR_REG(0xC5);
    {
        uint8_t data[] = { 0x3E, 0x28 };
        ILI9341_WriteData(data, sizeof(data));
    }

    // VCM CONTROL 2
    ILI9341_WR_REG(0xC7);
    {
        uint8_t data[] = { 0x86 };
        ILI9341_WriteData(data, sizeof(data));
    }

    // MEMORY ACCESS CONTROL
    ILI9341_WR_REG(0x36);
    {
        uint8_t data[] = { 0x48 };
        ILI9341_WriteData(data, sizeof(data));
    }

    // PIXEL FORMAT
    ILI9341_WR_REG(0x3A);
    {
        uint8_t data[] = { 0x55 };
        ILI9341_WriteData(data, sizeof(data));
    }

    // FRAME RATIO CONTROL, STANDARD RGB COLOR
    ILI9341_WR_REG(0xB1);
    {
        uint8_t data[] = { 0x00, 0x18 };
        ILI9341_WriteData(data, sizeof(data));
    }

    // DISPLAY FUNCTION CONTROL
    ILI9341_WR_REG(0xB6);
    {
        uint8_t data[] = { 0x08, 0x82, 0x27 };
        ILI9341_WriteData(data, sizeof(data));
    }

    // 3GAMMA FUNCTION DISABLE
    ILI9341_WR_REG(0xF2);
    {
        uint8_t data[] = { 0x00 };
        ILI9341_WriteData(data, sizeof(data));
    }

    // GAMMA CURVE SELECTED
    ILI9341_WR_REG(0x26);
    {
        uint8_t data[] = { 0x01 };
        ILI9341_WriteData(data, sizeof(data));
    }

    // POSITIVE GAMMA CORRECTION
    ILI9341_WR_REG(0xE0);
    {
        uint8_t data[] = { 0x0F, 0x31, 0x2B, 0x0C, 0x0E, 0x08, 0x4E, 0xF1,
                           0x37, 0x07, 0x10, 0x03, 0x0E, 0x09, 0x00 };
        ILI9341_WriteData(data, sizeof(data));
    }

    // NEGATIVE GAMMA CORRECTION
    ILI9341_WR_REG(0xE1);
    {
        uint8_t data[] = { 0x00, 0x0E, 0x14, 0x03, 0x11, 0x07, 0x31, 0xC1,
                           0x48, 0x08, 0x0F, 0x0C, 0x31, 0x36, 0x0F };
        ILI9341_WriteData(data, sizeof(data));
    }

    // EXIT SLEEP
    ILI9341_WR_REG(0x11);
    delay_ms(120);

    // TURN ON DISPLAY
    ILI9341_WR_REG(0x29);

    // MADCTL
    ILI9341_WR_REG(0x36);
    {
        uint8_t data[] = { ILI9341_ROTATION };
        ILI9341_WriteData(data, sizeof(data));
    }
 
    ILI9341_CS_Set();
}

void ILI9341_DrawPixel(uint16_t x, uint16_t y, uint16_t color) {
    if((x >= ILI9341_WIDTH) || (y >= ILI9341_HEIGHT))
        return;

    ILI9341_CS_Clr();

    ILI9341_SetAddressWindow(x, y, x+1, y+1);
    uint8_t data[] = { color >> 8, color & 0xFF };
    ILI9341_WriteData(data, sizeof(data));

    ILI9341_CS_Set();
}

static void ILI9341_WriteChar(uint16_t x, uint16_t y, char ch, TFT_FontDef font, uint16_t color, uint16_t bgcolor) {
    uint32_t i, b, j;

    ILI9341_SetAddressWindow(x, y, x+font.width-1, y+font.height-1);

    for(i = 0; i < font.height; i++) {
        b = font.data[(ch - 32) * font.height + i];
        for(j = 0; j < font.width; j++) {
            if((b << j) & 0x8000)  {
                uint8_t data[] = { color >> 8, color & 0xFF };
                ILI9341_WriteData(data, sizeof(data));
            } else {
                uint8_t data[] = { bgcolor >> 8, bgcolor & 0xFF };
                ILI9341_WriteData(data, sizeof(data));
            }
        }
    }
}

void ILI9341_WriteString(uint16_t x, uint16_t y, const char* str, TFT_FontDef font, uint16_t color, uint16_t bgcolor) {
    ILI9341_CS_Clr();

    while(*str) {
        if(x + font.width >= ILI9341_WIDTH) {
            x = 0;
            y += font.height;
            if(y + font.height >= ILI9341_HEIGHT) {
                break;
            }

            if(*str == ' ') {
                // skip spaces in the beginning of the new line
                str++;
                continue;
            }
        }

        ILI9341_WriteChar(x, y, *str, font, color, bgcolor);
        x += font.width;
        str++;
    }

    ILI9341_CS_Set();
}

void ILI9341_FillRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color) {
    // clipping
    if((x >= ILI9341_WIDTH) || (y >= ILI9341_HEIGHT)) return;
    if((x + w - 1) >= ILI9341_WIDTH) w = ILI9341_WIDTH - x;
    if((y + h - 1) >= ILI9341_HEIGHT) h = ILI9341_HEIGHT - y;

    ILI9341_CS_Clr();
    ILI9341_SetAddressWindow(x, y, x+w-1, y+h-1);

    ILI9341_DC_Set();
    for(y = h; y > 0; y--) {
        for(x = w; x > 0; x--) {
            ILI9341_WR_DATA(color);
        }
    }

    ILI9341_CS_Set();
}

void ILI9341_FillScreen(uint16_t color) {
    ILI9341_FillRectangle(0, 0, ILI9341_WIDTH, ILI9341_HEIGHT, color);
}

void ILI9341_DrawImage(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t* data) {
    if((x >= ILI9341_WIDTH) || (y >= ILI9341_HEIGHT)) return;
    if((x + w - 1) >= ILI9341_WIDTH) return;
    if((y + h - 1) >= ILI9341_HEIGHT) return;

    ILI9341_CS_Clr();
    ILI9341_SetAddressWindow(x, y, x+w-1, y+h-1);
    ILI9341_WriteData((uint8_t*)data, sizeof(uint16_t)*w*h);
    ILI9341_CS_Set();
}

void ILI9341_InvertColors(bool invert) {
    ILI9341_CS_Clr();
    ILI9341_WR_REG(invert ? 0x21 /* INVON */ : 0x20 /* INVOFF */);
    ILI9341_CS_Set();
}

void ILI9341_DMA_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 *color)
{
	uint32_t num = (xend-xsta+1)*(yend-ysta+1);
	//printf("num:%d\r\n",num);

    ILI9341_SetAddressWindow(xsta,ysta,xend-1,yend-1);//设置显示范围)
	// LCD_Address_Set(xsta,ysta,xend-1,yend-1);//设置显示范围

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
	
	ILI9341_CS_Clr(); //CS=0	
	dma_channel_enable(DMA1_CHANNEL1, TRUE); //启动传输	
	
	while(!dma_flag_get(DMA1_FDT1_FLAG));
	dma_channel_enable(DMA1_CHANNEL1, FALSE); //启动传输	
	ILI9341_CS_Set(); //CS=1
}
