#include "spi.h"

void Spi1_Init(void)
{

  gpio_init_type gpio_initstructure;
  crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);
  crm_periph_clock_enable(CRM_SPI1_PERIPH_CLOCK, TRUE);

  /* master sck pin */
  gpio_initstructure.gpio_out_type       = GPIO_OUTPUT_PUSH_PULL;
  gpio_initstructure.gpio_pull           = GPIO_PULL_DOWN;
  gpio_initstructure.gpio_mode           = GPIO_MODE_MUX;
  gpio_initstructure.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
  gpio_initstructure.gpio_pins           = GPIO_LCD_CLK_PIN;
  gpio_init(GPIO_LCD_CLK_PORT, &gpio_initstructure);
  gpio_pin_mux_config(GPIO_LCD_CLK_PORT, GPIO_LCD_CLK_PIN, GPIO_MUX_6);

    /* master mosi pin */
  gpio_initstructure.gpio_pull           = GPIO_PULL_UP;
  gpio_initstructure.gpio_pins           = GPIO_LCD_MOSI_PIN;
  gpio_init(GPIO_LCD_MOSI_PORT, &gpio_initstructure);
  gpio_pin_mux_config(GPIO_LCD_MOSI_PORT, GPIO_LCD_MOSI_PIN, GPIO_MUX_6);

  spi_init_type spi_init_struct;
//   spi_default_para_init(&spi_init_struct);
  spi_init_struct.transmission_mode = SPI_TRANSMIT_FULL_DUPLEX;
  spi_init_struct.master_slave_mode =SPI_MODE_MASTER;
  spi_init_struct.mclk_freq_division = SPI_MCLK_DIV_2;
  spi_init_struct.first_bit_transmission = SPI_FIRST_BIT_MSB;
  spi_init_struct.frame_bit_num = SPI_FRAME_8BIT;
  spi_init_struct.clock_polarity = SPI_CLOCK_POLARITY_LOW;
  spi_init_struct.clock_phase = SPI_CLOCK_PHASE_1EDGE;
  spi_init_struct.cs_mode_selection = SPI_CS_SOFTWARE_MODE;
  spi_init(SPI1, &spi_init_struct);
//   spi_half_duplex_direction_set(SPI1,SPI_HALF_DUPLEX_DIRECTION_TX);

  spi_enable(SPI1, TRUE);
  printf("usart printf example: retarget the c library printf function to the usart\r\n");
}