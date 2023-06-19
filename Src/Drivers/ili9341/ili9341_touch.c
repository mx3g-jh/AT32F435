/* vim: set ai et ts=4 sw=4: */

#include "ili9341_touch.h"

#define READ_X 0xD0
#define READ_Y 0x90

void ILI9341_Touch_GPIO_Init(void)
{

	crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE); 

	gpio_init_type gpio_initstructure;
	gpio_default_para_init(&gpio_initstructure);

    /* configure key pin as input with pull-down */
    gpio_initstructure.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
    gpio_initstructure.gpio_out_type  = GPIO_OUTPUT_PUSH_PULL;
    gpio_initstructure.gpio_mode = GPIO_MODE_INPUT;
    gpio_initstructure.gpio_pull = GPIO_PULL_UP;
	gpio_initstructure.gpio_pins           = GPIO_PINS_2;
	gpio_init(GPIOA, &gpio_initstructure);
}

void ILI9341_Touch_Read_Bus(u16 *pRxData) 
{	
  spi_frame_bit_num_set(SPI1, SPI_FRAME_16BIT);
  while(spi_i2s_flag_get(SPI1, SPI_I2S_RDBF_FLAG) == RESET);
  *pRxData = spi_i2s_data_receive(SPI1);
  while(spi_i2s_flag_get(SPI1, SPI_I2S_BF_FLAG) == SET); //等待传输完成
  spi_frame_bit_num_set(SPI1, SPI_FRAME_16BIT);

}

void ILI9341_Touch_WR_DATA(u16 dat)
{
	ILI9341_Touch_Writ_Bus(dat>>8);
	ILI9341_Touch_Writ_Bus(dat);
}

void ILI9341_Touch_Writ_Bus(u8 dat) 
{	
  spi_frame_bit_num_set(SPI1, SPI_FRAME_8BIT);
  spi_i2s_data_transmit(SPI1, dat);
  while(spi_i2s_flag_get(SPI1, SPI_I2S_BF_FLAG) == SET); //等待传输完成
}

bool ILI9341_TouchPressed() {
    return gpio_input_data_bit_read(ILI9341_TOUCH_IRQ_GPIO_Port, ILI9341_TOUCH_IRQ_Pin) == RESET;
}

bool ILI9341_TouchGetCoordinates(lv_coord_t * x, lv_coord_t * y) {
    static const uint8_t cmd_read_x[] = { READ_X };
    static const uint8_t cmd_read_y[] = { READ_Y };
    static const uint8_t zeroes_tx[] = { 0x00, 0x00 };

    ILI9341_TOUCH_CS_Clr();

    uint32_t avg_x = 0;
    uint32_t avg_y = 0;
    uint8_t nsamples = 0;
    for(uint8_t i = 0; i < 16; i++) {
        if(!ILI9341_TouchPressed())
            break;

        nsamples++;

        ILI9341_Touch_Writ_Bus(READ_Y);
        uint16_t y_raw;

        ILI9341_Touch_WR_DATA(0x00);
        ILI9341_Touch_Read_Bus(&y_raw);
        ILI9341_Touch_Writ_Bus(READ_X);
        uint16_t x_raw;
        ILI9341_Touch_WR_DATA(0x00);
        ILI9341_Touch_Read_Bus(&x_raw);

        avg_x += x_raw;
        avg_y += y_raw;
    }

   ILI9341_TOUCH_CS_Set();

    if(nsamples < 16)
        return false;

    uint32_t raw_x = (avg_x / 16);
    if(raw_x < ILI9341_TOUCH_MIN_RAW_X) raw_x = ILI9341_TOUCH_MIN_RAW_X;
    if(raw_x > ILI9341_TOUCH_MAX_RAW_X) raw_x = ILI9341_TOUCH_MAX_RAW_X;

    uint32_t raw_y = (avg_y / 16);
    if(raw_y < ILI9341_TOUCH_MIN_RAW_X) raw_y = ILI9341_TOUCH_MIN_RAW_Y;
    if(raw_y > ILI9341_TOUCH_MAX_RAW_Y) raw_y = ILI9341_TOUCH_MAX_RAW_Y;

    // Uncomment this line to calibrate touchscreen:
    // UART_Printf("raw_x = %d, raw_y = %d\r\n", x, y);

    *x = (raw_x - ILI9341_TOUCH_MIN_RAW_X) * ILI9341_TOUCH_SCALE_X / (ILI9341_TOUCH_MAX_RAW_X - ILI9341_TOUCH_MIN_RAW_X);
    *y = (raw_y - ILI9341_TOUCH_MIN_RAW_Y) * ILI9341_TOUCH_SCALE_Y / (ILI9341_TOUCH_MAX_RAW_Y - ILI9341_TOUCH_MIN_RAW_Y);

    return true;
}
