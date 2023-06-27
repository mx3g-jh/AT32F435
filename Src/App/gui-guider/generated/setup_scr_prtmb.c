/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_prtmb(lv_ui *ui){

	//Write codes prtmb
	ui->prtmb = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->prtmb, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prtmb_main_main_default
	static lv_style_t style_prtmb_main_main_default;
	if (style_prtmb_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtmb_main_main_default);
	else
		lv_style_init(&style_prtmb_main_main_default);
	lv_style_set_bg_color(&style_prtmb_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_prtmb_main_main_default, 0);
	lv_obj_add_style(ui->prtmb, &style_prtmb_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtmb_cont0
	ui->prtmb_cont0 = lv_obj_create(ui->prtmb);
	lv_obj_set_pos(ui->prtmb_cont0, 0, 0);
	lv_obj_set_size(ui->prtmb_cont0, 480, 320);
	lv_obj_set_scrollbar_mode(ui->prtmb_cont0, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prtmb_cont0_main_main_default
	static lv_style_t style_prtmb_cont0_main_main_default;
	if (style_prtmb_cont0_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtmb_cont0_main_main_default);
	else
		lv_style_init(&style_prtmb_cont0_main_main_default);
	lv_style_set_radius(&style_prtmb_cont0_main_main_default, 0);
	lv_style_set_bg_color(&style_prtmb_cont0_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_prtmb_cont0_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_prtmb_cont0_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtmb_cont0_main_main_default, 255);
	lv_style_set_shadow_width(&style_prtmb_cont0_main_main_default, 0);
	lv_style_set_shadow_color(&style_prtmb_cont0_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prtmb_cont0_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prtmb_cont0_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prtmb_cont0_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prtmb_cont0_main_main_default, 0);
	lv_style_set_border_color(&style_prtmb_cont0_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_prtmb_cont0_main_main_default, 0);
	lv_style_set_border_opa(&style_prtmb_cont0_main_main_default, 255);
	lv_style_set_pad_left(&style_prtmb_cont0_main_main_default, 0);
	lv_style_set_pad_right(&style_prtmb_cont0_main_main_default, 0);
	lv_style_set_pad_top(&style_prtmb_cont0_main_main_default, 0);
	lv_style_set_pad_bottom(&style_prtmb_cont0_main_main_default, 0);
	lv_obj_add_style(ui->prtmb_cont0, &style_prtmb_cont0_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtmb_btnback
	ui->prtmb_btnback = lv_btn_create(ui->prtmb);
	lv_obj_set_pos(ui->prtmb_btnback, 171, 230);
	lv_obj_set_size(ui->prtmb_btnback, 134, 45);
	lv_obj_set_scrollbar_mode(ui->prtmb_btnback, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prtmb_btnback_main_main_default
	static lv_style_t style_prtmb_btnback_main_main_default;
	if (style_prtmb_btnback_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtmb_btnback_main_main_default);
	else
		lv_style_init(&style_prtmb_btnback_main_main_default);
	lv_style_set_radius(&style_prtmb_btnback_main_main_default, 50);
	lv_style_set_bg_color(&style_prtmb_btnback_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_prtmb_btnback_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_prtmb_btnback_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtmb_btnback_main_main_default, 255);
	lv_style_set_shadow_width(&style_prtmb_btnback_main_main_default, 0);
	lv_style_set_shadow_color(&style_prtmb_btnback_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prtmb_btnback_main_main_default, 0);
	lv_style_set_shadow_spread(&style_prtmb_btnback_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prtmb_btnback_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prtmb_btnback_main_main_default, 0);
	lv_style_set_border_color(&style_prtmb_btnback_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_prtmb_btnback_main_main_default, 2);
	lv_style_set_border_opa(&style_prtmb_btnback_main_main_default, 255);
	lv_style_set_text_color(&style_prtmb_btnback_main_main_default, lv_color_make(0xf4, 0xec, 0xec));
	lv_style_set_text_font(&style_prtmb_btnback_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_align(&style_prtmb_btnback_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->prtmb_btnback, &style_prtmb_btnback_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->prtmb_btnback_label = lv_label_create(ui->prtmb_btnback);
	lv_label_set_text(ui->prtmb_btnback_label, "BACK");
	lv_obj_set_style_pad_all(ui->prtmb_btnback, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->prtmb_btnback_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes prtmb_label2
	ui->prtmb_label2 = lv_label_create(ui->prtmb);
	lv_obj_set_pos(ui->prtmb_label2, 10, 171);
	lv_obj_set_size(ui->prtmb_label2, 460, 35);
	lv_obj_set_scrollbar_mode(ui->prtmb_label2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->prtmb_label2, "Put your phone near to the printer");
	lv_label_set_long_mode(ui->prtmb_label2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_prtmb_label2_main_main_default
	static lv_style_t style_prtmb_label2_main_main_default;
	if (style_prtmb_label2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtmb_label2_main_main_default);
	else
		lv_style_init(&style_prtmb_label2_main_main_default);
	lv_style_set_radius(&style_prtmb_label2_main_main_default, 0);
	lv_style_set_bg_color(&style_prtmb_label2_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_prtmb_label2_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_prtmb_label2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtmb_label2_main_main_default, 0);
	lv_style_set_shadow_width(&style_prtmb_label2_main_main_default, 0);
	lv_style_set_shadow_color(&style_prtmb_label2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prtmb_label2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prtmb_label2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prtmb_label2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prtmb_label2_main_main_default, 0);
	lv_style_set_text_color(&style_prtmb_label2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prtmb_label2_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_prtmb_label2_main_main_default, 2);
	lv_style_set_text_line_space(&style_prtmb_label2_main_main_default, 0);
	lv_style_set_text_align(&style_prtmb_label2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_prtmb_label2_main_main_default, 0);
	lv_style_set_pad_right(&style_prtmb_label2_main_main_default, 0);
	lv_style_set_pad_top(&style_prtmb_label2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_prtmb_label2_main_main_default, 0);
	lv_obj_add_style(ui->prtmb_label2, &style_prtmb_label2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtmb_printer
	ui->prtmb_printer = lv_img_create(ui->prtmb);
	lv_obj_set_pos(ui->prtmb_printer, 154, 82);
	lv_obj_set_size(ui->prtmb_printer, 60, 64);
	lv_obj_set_scrollbar_mode(ui->prtmb_printer, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prtmb_printer_main_main_default
	static lv_style_t style_prtmb_printer_main_main_default;
	if (style_prtmb_printer_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtmb_printer_main_main_default);
	else
		lv_style_init(&style_prtmb_printer_main_main_default);
	lv_style_set_img_recolor(&style_prtmb_printer_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_prtmb_printer_main_main_default, 0);
	lv_style_set_img_opa(&style_prtmb_printer_main_main_default, 255);
	lv_obj_add_style(ui->prtmb_printer, &style_prtmb_printer_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->prtmb_printer, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->prtmb_printer,&_printer2_60x64);
	lv_img_set_pivot(ui->prtmb_printer, 0,0);
	lv_img_set_angle(ui->prtmb_printer, 0);

	//Write codes prtmb_img
	ui->prtmb_img = lv_img_create(ui->prtmb);
	lv_obj_set_pos(ui->prtmb_img, 235, 97);
	lv_obj_set_size(ui->prtmb_img, 25, 29);
	lv_obj_set_scrollbar_mode(ui->prtmb_img, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prtmb_img_main_main_default
	static lv_style_t style_prtmb_img_main_main_default;
	if (style_prtmb_img_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtmb_img_main_main_default);
	else
		lv_style_init(&style_prtmb_img_main_main_default);
	lv_style_set_img_recolor(&style_prtmb_img_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_prtmb_img_main_main_default, 0);
	lv_style_set_img_opa(&style_prtmb_img_main_main_default, 255);
	lv_obj_add_style(ui->prtmb_img, &style_prtmb_img_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->prtmb_img, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->prtmb_img,&_wave_25x29);
	lv_img_set_pivot(ui->prtmb_img, 0,0);
	lv_img_set_angle(ui->prtmb_img, 0);

	//Write codes prtmb_cloud
	ui->prtmb_cloud = lv_img_create(ui->prtmb);
	lv_obj_set_pos(ui->prtmb_cloud, 280, 84);
	lv_obj_set_size(ui->prtmb_cloud, 45, 64);
	lv_obj_set_scrollbar_mode(ui->prtmb_cloud, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prtmb_cloud_main_main_default
	static lv_style_t style_prtmb_cloud_main_main_default;
	if (style_prtmb_cloud_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtmb_cloud_main_main_default);
	else
		lv_style_init(&style_prtmb_cloud_main_main_default);
	lv_style_set_img_recolor(&style_prtmb_cloud_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_prtmb_cloud_main_main_default, 0);
	lv_style_set_img_opa(&style_prtmb_cloud_main_main_default, 255);
	lv_obj_add_style(ui->prtmb_cloud, &style_prtmb_cloud_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->prtmb_cloud, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->prtmb_cloud,&_phone_45x64);
	lv_img_set_pivot(ui->prtmb_cloud, 0,0);
	lv_img_set_angle(ui->prtmb_cloud, 0);
}