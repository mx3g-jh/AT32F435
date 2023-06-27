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


void setup_scr_printit(lv_ui *ui){

	//Write codes printit
	ui->printit = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->printit, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_printit_main_main_default
	static lv_style_t style_printit_main_main_default;
	if (style_printit_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printit_main_main_default);
	else
		lv_style_init(&style_printit_main_main_default);
	lv_style_set_bg_color(&style_printit_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_printit_main_main_default, 0);
	lv_obj_add_style(ui->printit, &style_printit_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printit_cont0
	ui->printit_cont0 = lv_obj_create(ui->printit);
	lv_obj_set_pos(ui->printit_cont0, 0, 0);
	lv_obj_set_size(ui->printit_cont0, 480, 320);
	lv_obj_set_scrollbar_mode(ui->printit_cont0, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_printit_cont0_main_main_default
	static lv_style_t style_printit_cont0_main_main_default;
	if (style_printit_cont0_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printit_cont0_main_main_default);
	else
		lv_style_init(&style_printit_cont0_main_main_default);
	lv_style_set_radius(&style_printit_cont0_main_main_default, 0);
	lv_style_set_bg_color(&style_printit_cont0_main_main_default, lv_color_make(0xd2, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_printit_cont0_main_main_default, lv_color_make(0xd2, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_printit_cont0_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printit_cont0_main_main_default, 255);
	lv_style_set_shadow_width(&style_printit_cont0_main_main_default, 0);
	lv_style_set_shadow_color(&style_printit_cont0_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_printit_cont0_main_main_default, 255);
	lv_style_set_shadow_spread(&style_printit_cont0_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_printit_cont0_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_printit_cont0_main_main_default, 0);
	lv_style_set_border_color(&style_printit_cont0_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_printit_cont0_main_main_default, 0);
	lv_style_set_border_opa(&style_printit_cont0_main_main_default, 255);
	lv_style_set_pad_left(&style_printit_cont0_main_main_default, 0);
	lv_style_set_pad_right(&style_printit_cont0_main_main_default, 0);
	lv_style_set_pad_top(&style_printit_cont0_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printit_cont0_main_main_default, 0);
	lv_obj_add_style(ui->printit_cont0, &style_printit_cont0_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printit_btnprtitback
	ui->printit_btnprtitback = lv_btn_create(ui->printit);
	lv_obj_set_pos(ui->printit_btnprtitback, 163, 223);
	lv_obj_set_size(ui->printit_btnprtitback, 134, 45);
	lv_obj_set_scrollbar_mode(ui->printit_btnprtitback, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_printit_btnprtitback_main_main_default
	static lv_style_t style_printit_btnprtitback_main_main_default;
	if (style_printit_btnprtitback_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printit_btnprtitback_main_main_default);
	else
		lv_style_init(&style_printit_btnprtitback_main_main_default);
	lv_style_set_radius(&style_printit_btnprtitback_main_main_default, 50);
	lv_style_set_bg_color(&style_printit_btnprtitback_main_main_default, lv_color_make(0xd2, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_printit_btnprtitback_main_main_default, lv_color_make(0xd2, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_printit_btnprtitback_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printit_btnprtitback_main_main_default, 255);
	lv_style_set_shadow_width(&style_printit_btnprtitback_main_main_default, 0);
	lv_style_set_shadow_color(&style_printit_btnprtitback_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_printit_btnprtitback_main_main_default, 0);
	lv_style_set_shadow_spread(&style_printit_btnprtitback_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_printit_btnprtitback_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_printit_btnprtitback_main_main_default, 0);
	lv_style_set_border_color(&style_printit_btnprtitback_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_printit_btnprtitback_main_main_default, 2);
	lv_style_set_border_opa(&style_printit_btnprtitback_main_main_default, 255);
	lv_style_set_text_color(&style_printit_btnprtitback_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_printit_btnprtitback_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_align(&style_printit_btnprtitback_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->printit_btnprtitback, &style_printit_btnprtitback_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->printit_btnprtitback_label = lv_label_create(ui->printit_btnprtitback);
	lv_label_set_text(ui->printit_btnprtitback_label, "BACK");
	lv_obj_set_style_pad_all(ui->printit_btnprtitback, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->printit_btnprtitback_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes printit_label2
	ui->printit_label2 = lv_label_create(ui->printit);
	lv_obj_set_pos(ui->printit_label2, 10, 171);
	lv_obj_set_size(ui->printit_label2, 460, 35);
	lv_obj_set_scrollbar_mode(ui->printit_label2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->printit_label2, "No internet connection");
	lv_label_set_long_mode(ui->printit_label2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_printit_label2_main_main_default
	static lv_style_t style_printit_label2_main_main_default;
	if (style_printit_label2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printit_label2_main_main_default);
	else
		lv_style_init(&style_printit_label2_main_main_default);
	lv_style_set_radius(&style_printit_label2_main_main_default, 0);
	lv_style_set_bg_color(&style_printit_label2_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_printit_label2_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_printit_label2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printit_label2_main_main_default, 0);
	lv_style_set_shadow_width(&style_printit_label2_main_main_default, 0);
	lv_style_set_shadow_color(&style_printit_label2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_printit_label2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_printit_label2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_printit_label2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_printit_label2_main_main_default, 0);
	lv_style_set_text_color(&style_printit_label2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_printit_label2_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_printit_label2_main_main_default, 2);
	lv_style_set_text_line_space(&style_printit_label2_main_main_default, 0);
	lv_style_set_text_align(&style_printit_label2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_printit_label2_main_main_default, 0);
	lv_style_set_pad_right(&style_printit_label2_main_main_default, 0);
	lv_style_set_pad_top(&style_printit_label2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printit_label2_main_main_default, 0);
	lv_obj_add_style(ui->printit_label2, &style_printit_label2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printit_printer
	ui->printit_printer = lv_img_create(ui->printit);
	lv_obj_set_pos(ui->printit_printer, 154, 82);
	lv_obj_set_size(ui->printit_printer, 60, 64);
	lv_obj_set_scrollbar_mode(ui->printit_printer, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_printit_printer_main_main_default
	static lv_style_t style_printit_printer_main_main_default;
	if (style_printit_printer_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printit_printer_main_main_default);
	else
		lv_style_init(&style_printit_printer_main_main_default);
	lv_style_set_img_recolor(&style_printit_printer_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_printit_printer_main_main_default, 0);
	lv_style_set_img_opa(&style_printit_printer_main_main_default, 255);
	lv_obj_add_style(ui->printit_printer, &style_printit_printer_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->printit_printer, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->printit_printer,&_printer2_60x64);
	lv_img_set_pivot(ui->printit_printer, 0,0);
	lv_img_set_angle(ui->printit_printer, 0);

	//Write codes printit_imgnotit
	ui->printit_imgnotit = lv_img_create(ui->printit);
	lv_obj_set_pos(ui->printit_imgnotit, 217, 72);
	lv_obj_set_size(ui->printit_imgnotit, 25, 29);
	lv_obj_set_scrollbar_mode(ui->printit_imgnotit, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_printit_imgnotit_main_main_default
	static lv_style_t style_printit_imgnotit_main_main_default;
	if (style_printit_imgnotit_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printit_imgnotit_main_main_default);
	else
		lv_style_init(&style_printit_imgnotit_main_main_default);
	lv_style_set_img_recolor(&style_printit_imgnotit_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_printit_imgnotit_main_main_default, 0);
	lv_style_set_img_opa(&style_printit_imgnotit_main_main_default, 255);
	lv_obj_add_style(ui->printit_imgnotit, &style_printit_imgnotit_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->printit_imgnotit, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->printit_imgnotit,&_no_internet_25x29);
	lv_img_set_pivot(ui->printit_imgnotit, 0,0);
	lv_img_set_angle(ui->printit_imgnotit, 0);

	//Write codes printit_cloud
	ui->printit_cloud = lv_img_create(ui->printit);
	lv_obj_set_pos(ui->printit_cloud, 258, 35);
	lv_obj_set_size(ui->printit_cloud, 55, 47);
	lv_obj_set_scrollbar_mode(ui->printit_cloud, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_printit_cloud_main_main_default
	static lv_style_t style_printit_cloud_main_main_default;
	if (style_printit_cloud_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printit_cloud_main_main_default);
	else
		lv_style_init(&style_printit_cloud_main_main_default);
	lv_style_set_img_recolor(&style_printit_cloud_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_printit_cloud_main_main_default, 0);
	lv_style_set_img_opa(&style_printit_cloud_main_main_default, 255);
	lv_obj_add_style(ui->printit_cloud, &style_printit_cloud_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->printit_cloud, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->printit_cloud,&_cloud_55x47);
	lv_img_set_pivot(ui->printit_cloud, 0,0);
	lv_img_set_angle(ui->printit_cloud, 0);
}