/**
 * @file lv_port_disp_templ.c
 *
 */

/*Copy this file as "lv_port_disp.c" and set this value to "1" to enable content*/

#if 1

#include "lv_port_disp.h"
#include <stdbool.h>
#include "bsp_spi_lcd.h"

#define ONE_FLUSH_SIZES    40
#define MY_DISP_HOR_RES    240
#define MY_DISP_VER_RES    240

static lv_color_t buf_2_1[MY_DISP_HOR_RES * ONE_FLUSH_SIZES];                       
static lv_color_t buf_2_2[MY_DISP_HOR_RES * ONE_FLUSH_SIZES];  

static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p)
{
	u32 size = (area->x2 - area->x1+1)*(area->y2 - area->y1+1);

	LCD_DC_Set();
	LCD_Address_Set(area->x1,area->y1,area->x2,area->y2);  //ÉèÖÃÏÔÊ¾·¶Î§

	spi_frame_bit_num_set(SPI1, SPI_FRAME_16BIT);
	LCD_CS_Clr(); //CS=0	
	
	dma_channel_enable(DMA1_CHANNEL1, FALSE);
	DMA1_CHANNEL1->maddr  = (uint32_t)color_p;
	DMA1_CHANNEL1->dtcnt = size;
	dma_channel_enable(DMA1_CHANNEL1, TRUE);
	
	while(!dma_flag_get(DMA1_FDT1_FLAG));
	while(spi_i2s_flag_get(SPI1, SPI_I2S_BF_FLAG) == SET); 
	
	LCD_CS_Set(); //CS=1
	
	lv_disp_flush_ready(disp_drv);
}

void lv_port_disp_init(void)
{
		crm_periph_clock_enable(CRM_DMA1_PERIPH_CLOCK, TRUE);

		spi_frame_bit_num_set(SPI1, SPI_FRAME_16BIT);
		dma_init_type dma_init_struct;
		dma_reset(DMA1_CHANNEL1);
		dma_default_para_init(&dma_init_struct);
		dma_init_struct.buffer_size = 0xfffe;
		dma_init_struct.direction = DMA_DIR_MEMORY_TO_PERIPHERAL;
		dma_init_struct.memory_base_addr = (uint32_t)&(SPI1->dt);
		dma_init_struct.memory_data_width = DMA_MEMORY_DATA_WIDTH_HALFWORD;
		dma_init_struct.memory_inc_enable = TRUE;
		dma_init_struct.peripheral_base_addr = (uint32_t)&(SPI1->dt);
		dma_init_struct.peripheral_data_width = DMA_PERIPHERAL_DATA_WIDTH_HALFWORD;
		dma_init_struct.peripheral_inc_enable = FALSE;
		dma_init_struct.priority = DMA_PRIORITY_MEDIUM;
		dma_init_struct.loop_mode_enable = FALSE;

		dma_init(DMA1_CHANNEL1, &dma_init_struct);
		dmamux_enable(DMA1, TRUE);
		dmamux_init(DMA1MUX_CHANNEL1, DMAMUX_DMAREQ_ID_SPI1_TX);
	
    static lv_disp_draw_buf_t draw_buf_dsc_2;                      
                     
    lv_disp_draw_buf_init(&draw_buf_dsc_2, buf_2_1, buf_2_2, MY_DISP_HOR_RES * ONE_FLUSH_SIZES);  

    static lv_disp_drv_t disp_drv;                       
    lv_disp_drv_init(&disp_drv);                  

    disp_drv.hor_res = MY_DISP_HOR_RES;
    disp_drv.ver_res = MY_DISP_VER_RES;
	
    disp_drv.flush_cb = disp_flush;
    disp_drv.draw_buf = &draw_buf_dsc_2;

    lv_disp_drv_register(&disp_drv);
}

#endif