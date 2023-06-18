/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *home;
	bool home_del;
	lv_obj_t *home_cont1;
	lv_obj_t *home_whitebg;
	lv_obj_t *home_cont2;
	lv_obj_t *home_labeldate;
	lv_obj_t *home_imgbtncopy;
	lv_obj_t *home_imgbtncopy_label;
	lv_obj_t *home_labelcopy;
	lv_obj_t *home_imgbtnset;
	lv_obj_t *home_imgbtnset_label;
	lv_obj_t *home_imgbtnscan;
	lv_obj_t *home_imgbtnscan_label;
	lv_obj_t *home_imgbtnprt;
	lv_obj_t *home_imgbtnprt_label;
	lv_obj_t *home_labelscan;
	lv_obj_t *home_labelprt;
	lv_obj_t *home_labelset;
	lv_obj_t *home_labelnote;
	lv_obj_t *home_contbars;
	lv_obj_t *home_bar1;
	lv_obj_t *home_bar2;
	lv_obj_t *home_bar3;
	lv_obj_t *home_bar4;
	lv_obj_t *home_wifi;
	lv_obj_t *home_tel;
	lv_obj_t *home_eco;
	lv_obj_t *home_pc;
	lv_obj_t *home_imgcopy;
	lv_obj_t *home_imgscan;
	lv_obj_t *home_imgprt;
	lv_obj_t *home_imgset;
	lv_obj_t *copyhome;
	bool copyhome_del;
	lv_obj_t *copyhome_cont1;
	lv_obj_t *copyhome_cont2;
	lv_obj_t *copyhome_label1;
	lv_obj_t *copyhome_img3;
	lv_obj_t *copyhome_cont4;
	lv_obj_t *copyhome_btncopynext;
	lv_obj_t *copyhome_btncopynext_label;
	lv_obj_t *copyhome_sliderhue;
	lv_obj_t *copyhome_sliderbright;
	lv_obj_t *copyhome_bright;
	lv_obj_t *copyhome_hue;
	lv_obj_t *copyhome_btncopyback;
	lv_obj_t *copyhome_btncopyback_label;
	lv_obj_t *copynext;
	bool copynext_del;
	lv_obj_t *copynext_cont1;
	lv_obj_t *copynext_cont2;
	lv_obj_t *copynext_label1;
	lv_obj_t *copynext_img3;
	lv_obj_t *copynext_cont4;
	lv_obj_t *copynext_ddlist2;
	lv_obj_t *copynext_btncopyback;
	lv_obj_t *copynext_btncopyback_label;
	lv_obj_t *copynext_swcolor;
	lv_obj_t *copynext_labelcopy;
	lv_obj_t *copynext_up;
	lv_obj_t *copynext_up_label;
	lv_obj_t *copynext_down;
	lv_obj_t *copynext_down_label;
	lv_obj_t *copynext_labelcnt;
	lv_obj_t *copynext_labelcolor;
	lv_obj_t *copynext_labelvert;
	lv_obj_t *copynext_swvert;
	lv_obj_t *copynext_ddlist1;
	lv_obj_t *copynext_print;
	lv_obj_t *copynext_print_label;
	lv_obj_t *scanhome;
	bool scanhome_del;
	lv_obj_t *scanhome_cont0;
	lv_obj_t *scanhome_label1;
	lv_obj_t *scanhome_cont2;
	lv_obj_t *scanhome_img3;
	lv_obj_t *scanhome_cont4;
	lv_obj_t *scanhome_btnscansave;
	lv_obj_t *scanhome_btnscansave_label;
	lv_obj_t *scanhome_sliderhue;
	lv_obj_t *scanhome_sliderbright;
	lv_obj_t *scanhome_bright;
	lv_obj_t *scanhome_hue;
	lv_obj_t *scanhome_btnscanback;
	lv_obj_t *scanhome_btnscanback_label;
	lv_obj_t *prthome;
	bool prthome_del;
	lv_obj_t *prthome_cont0;
	lv_obj_t *prthome_cont3;
	lv_obj_t *prthome_cont1;
	lv_obj_t *prthome_label4;
	lv_obj_t *prthome_imgbtnit;
	lv_obj_t *prthome_imgbtnit_label;
	lv_obj_t *prthome_imgbtnusb;
	lv_obj_t *prthome_imgbtnusb_label;
	lv_obj_t *prthome_imgbtnmobile;
	lv_obj_t *prthome_imgbtnmobile_label;
	lv_obj_t *prthome_labelusb;
	lv_obj_t *prthome_labelmobile;
	lv_obj_t *prthome_labelit;
	lv_obj_t *prthome_label2;
	lv_obj_t *prthome_usb;
	lv_obj_t *prthome_mobile;
	lv_obj_t *prthome_internet;
	lv_obj_t *prthome_btnprintback;
	lv_obj_t *prthome_btnprintback_label;
	lv_obj_t *prtusb;
	bool prtusb_del;
	lv_obj_t *prtusb_cont0;
	lv_obj_t *prtusb_cont2;
	lv_obj_t *prtusb_labeltitle;
	lv_obj_t *prtusb_cont4;
	lv_obj_t *prtusb_btnprint;
	lv_obj_t *prtusb_btnprint_label;
	lv_obj_t *prtusb_back;
	lv_obj_t *prtusb_back_label;
	lv_obj_t *prtusb_swcolor;
	lv_obj_t *prtusb_labelcopy;
	lv_obj_t *prtusb_up;
	lv_obj_t *prtusb_up_label;
	lv_obj_t *prtusb_down;
	lv_obj_t *prtusb_down_label;
	lv_obj_t *prtusb_labelcnt;
	lv_obj_t *prtusb_labelcolor;
	lv_obj_t *prtusb_labelvert;
	lv_obj_t *prtusb_swvert;
	lv_obj_t *prtusb_list16;
	lv_obj_t *prtusb_list16_item0;
	lv_obj_t *prtusb_list16_item1;
	lv_obj_t *prtusb_list16_item2;
	lv_obj_t *prtusb_list16_item3;
	lv_obj_t *prtusb_ddlist1;
	lv_obj_t *prtusb_ddlist2;
	lv_obj_t *prtmb;
	bool prtmb_del;
	lv_obj_t *prtmb_cont0;
	lv_obj_t *prtmb_btnback;
	lv_obj_t *prtmb_btnback_label;
	lv_obj_t *prtmb_label2;
	lv_obj_t *prtmb_printer;
	lv_obj_t *prtmb_img;
	lv_obj_t *prtmb_cloud;
	lv_obj_t *printit;
	bool printit_del;
	lv_obj_t *printit_cont0;
	lv_obj_t *printit_btnprtitback;
	lv_obj_t *printit_btnprtitback_label;
	lv_obj_t *printit_label2;
	lv_obj_t *printit_printer;
	lv_obj_t *printit_imgnotit;
	lv_obj_t *printit_cloud;
	lv_obj_t *setup;
	bool setup_del;
	lv_obj_t *setup_cont0;
	lv_obj_t *setup_btnsetback;
	lv_obj_t *setup_btnsetback_label;
	lv_obj_t *setup_label2;
	lv_obj_t *setup_printer;
	lv_obj_t *setup_img;
	lv_obj_t *setup_cloud;
	lv_obj_t *loader;
	bool loader_del;
	lv_obj_t *loader_cont0;
	lv_obj_t *loader_loadarc;
	lv_obj_t *loader_loadlabel;
	lv_obj_t *saved;
	bool saved_del;
	lv_obj_t *saved_cont0;
	lv_obj_t *saved_btnsavecontinue;
	lv_obj_t *saved_btnsavecontinue_label;
	lv_obj_t *saved_label2;
	lv_obj_t *saved_img1;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_home(lv_ui *ui);
void setup_scr_copyhome(lv_ui *ui);
void setup_scr_copynext(lv_ui *ui);
void setup_scr_scanhome(lv_ui *ui);
void setup_scr_prthome(lv_ui *ui);
void setup_scr_prtusb(lv_ui *ui);
void setup_scr_prtmb(lv_ui *ui);
void setup_scr_printit(lv_ui *ui);
void setup_scr_setup(lv_ui *ui);
void setup_scr_loader(lv_ui *ui);
void setup_scr_saved(lv_ui *ui);
LV_IMG_DECLARE(_hue_alpha_10x10);
LV_IMG_DECLARE(_btn2_alpha_57x123);
LV_IMG_DECLARE(_ready_alpha_50x50);
LV_IMG_DECLARE(_btn4_alpha_57x123);
LV_IMG_DECLARE(_btn3_alpha_57x123);
LV_IMG_DECLARE(_scan_alpha_14x14);
LV_IMG_DECLARE(_example_alpha_125x120);
LV_IMG_DECLARE(_internet_alpha_15x15);
LV_IMG_DECLARE(_setup_alpha_14x14);
LV_IMG_DECLARE(_usb_alpha_15x15);
LV_IMG_DECLARE(_phone_alpha_22x48);
LV_IMG_DECLARE(_print_alpha_14x14);
LV_IMG_DECLARE(_wave_alpha_12x12);
LV_IMG_DECLARE(_printer2_alpha_30x48);
LV_IMG_DECLARE(_btn_bg_1_alpha_42x88);
LV_IMG_DECLARE(_tel_alpha_10x10);
LV_IMG_DECLARE(_copy_alpha_14x14);
LV_IMG_DECLARE(_no_internet_alpha_12x12);
LV_IMG_DECLARE(_btn3_alpha_42x88);
LV_IMG_DECLARE(_btn4_alpha_42x88);
LV_IMG_DECLARE(_eco_alpha_10x10);
LV_IMG_DECLARE(_mobile_alpha_15x15);
LV_IMG_DECLARE(_cloud_alpha_27x35);
LV_IMG_DECLARE(_btn2_alpha_42x88);
LV_IMG_DECLARE(_pc_alpha_10x10);
LV_IMG_DECLARE(_bright_alpha_12x12);
LV_IMG_DECLARE(_example_alpha_150x151);
LV_IMG_DECLARE(_wifi_alpha_14x16);

#ifdef __cplusplus
}
#endif
#endif