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


void setup_scr_setup(lv_ui *ui){

	//Write codes setup
	ui->setup = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->setup, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_setup_main_main_default
	static lv_style_t style_setup_main_main_default;
	if (style_setup_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_setup_main_main_default);
	else
		lv_style_init(&style_setup_main_main_default);
	lv_style_set_bg_color(&style_setup_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_setup_main_main_default, 0);
	lv_obj_add_style(ui->setup, &style_setup_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes setup_cont0
	ui->setup_cont0 = lv_obj_create(ui->setup);
	lv_obj_set_pos(ui->setup_cont0, 0, 0);
	lv_obj_set_size(ui->setup_cont0, 480, 320);
	lv_obj_set_scrollbar_mode(ui->setup_cont0, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_setup_cont0_main_main_default
	static lv_style_t style_setup_cont0_main_main_default;
	if (style_setup_cont0_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_setup_cont0_main_main_default);
	else
		lv_style_init(&style_setup_cont0_main_main_default);
	lv_style_set_radius(&style_setup_cont0_main_main_default, 0);
	lv_style_set_bg_color(&style_setup_cont0_main_main_default, lv_color_make(0xd2, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_setup_cont0_main_main_default, lv_color_make(0xd2, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_setup_cont0_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setup_cont0_main_main_default, 255);
	lv_style_set_shadow_width(&style_setup_cont0_main_main_default, 0);
	lv_style_set_shadow_color(&style_setup_cont0_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_setup_cont0_main_main_default, 255);
	lv_style_set_shadow_spread(&style_setup_cont0_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_setup_cont0_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_setup_cont0_main_main_default, 0);
	lv_style_set_border_color(&style_setup_cont0_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_setup_cont0_main_main_default, 0);
	lv_style_set_border_opa(&style_setup_cont0_main_main_default, 255);
	lv_style_set_pad_left(&style_setup_cont0_main_main_default, 0);
	lv_style_set_pad_right(&style_setup_cont0_main_main_default, 0);
	lv_style_set_pad_top(&style_setup_cont0_main_main_default, 0);
	lv_style_set_pad_bottom(&style_setup_cont0_main_main_default, 0);
	lv_obj_add_style(ui->setup_cont0, &style_setup_cont0_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes setup_btnsetback
	ui->setup_btnsetback = lv_btn_create(ui->setup);
	lv_obj_set_pos(ui->setup_btnsetback, 161, 230);
	lv_obj_set_size(ui->setup_btnsetback, 134, 45);
	lv_obj_set_scrollbar_mode(ui->setup_btnsetback, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_setup_btnsetback_main_main_default
	static lv_style_t style_setup_btnsetback_main_main_default;
	if (style_setup_btnsetback_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_setup_btnsetback_main_main_default);
	else
		lv_style_init(&style_setup_btnsetback_main_main_default);
	lv_style_set_radius(&style_setup_btnsetback_main_main_default, 50);
	lv_style_set_bg_color(&style_setup_btnsetback_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_setup_btnsetback_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_setup_btnsetback_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setup_btnsetback_main_main_default, 0);
	lv_style_set_shadow_width(&style_setup_btnsetback_main_main_default, 0);
	lv_style_set_shadow_color(&style_setup_btnsetback_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_setup_btnsetback_main_main_default, 0);
	lv_style_set_shadow_spread(&style_setup_btnsetback_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_setup_btnsetback_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_setup_btnsetback_main_main_default, 0);
	lv_style_set_border_color(&style_setup_btnsetback_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_setup_btnsetback_main_main_default, 2);
	lv_style_set_border_opa(&style_setup_btnsetback_main_main_default, 255);
	lv_style_set_text_color(&style_setup_btnsetback_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_setup_btnsetback_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_align(&style_setup_btnsetback_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->setup_btnsetback, &style_setup_btnsetback_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->setup_btnsetback_label = lv_label_create(ui->setup_btnsetback);
	lv_label_set_text(ui->setup_btnsetback_label, "BACK");
	lv_obj_set_style_pad_all(ui->setup_btnsetback, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->setup_btnsetback_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes setup_label2
	ui->setup_label2 = lv_label_create(ui->setup);
	lv_obj_set_pos(ui->setup_label2, 10, 171);
	lv_obj_set_size(ui->setup_label2, 460, 35);
	lv_obj_set_scrollbar_mode(ui->setup_label2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->setup_label2, "You have no permission to change the settings");
	lv_label_set_long_mode(ui->setup_label2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_setup_label2_main_main_default
	static lv_style_t style_setup_label2_main_main_default;
	if (style_setup_label2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_setup_label2_main_main_default);
	else
		lv_style_init(&style_setup_label2_main_main_default);
	lv_style_set_radius(&style_setup_label2_main_main_default, 0);
	lv_style_set_bg_color(&style_setup_label2_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_setup_label2_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_setup_label2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setup_label2_main_main_default, 0);
	lv_style_set_shadow_width(&style_setup_label2_main_main_default, 0);
	lv_style_set_shadow_color(&style_setup_label2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_setup_label2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_setup_label2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_setup_label2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_setup_label2_main_main_default, 0);
	lv_style_set_text_color(&style_setup_label2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_setup_label2_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_setup_label2_main_main_default, 2);
	lv_style_set_text_line_space(&style_setup_label2_main_main_default, 0);
	lv_style_set_text_align(&style_setup_label2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_setup_label2_main_main_default, 0);
	lv_style_set_pad_right(&style_setup_label2_main_main_default, 0);
	lv_style_set_pad_top(&style_setup_label2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_setup_label2_main_main_default, 0);
	lv_obj_add_style(ui->setup_label2, &style_setup_label2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes setup_printer
	ui->setup_printer = lv_img_create(ui->setup);
	lv_obj_set_pos(ui->setup_printer, 154, 82);
	lv_obj_set_size(ui->setup_printer, 60, 64);
	lv_obj_set_scrollbar_mode(ui->setup_printer, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_setup_printer_main_main_default
	static lv_style_t style_setup_printer_main_main_default;
	if (style_setup_printer_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_setup_printer_main_main_default);
	else
		lv_style_init(&style_setup_printer_main_main_default);
	lv_style_set_img_recolor(&style_setup_printer_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_setup_printer_main_main_default, 0);
	lv_style_set_img_opa(&style_setup_printer_main_main_default, 255);
	lv_obj_add_style(ui->setup_printer, &style_setup_printer_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->setup_printer, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->setup_printer,&_printer2_60x64);
	lv_img_set_pivot(ui->setup_printer, 0,0);
	lv_img_set_angle(ui->setup_printer, 0);

	//Write codes setup_img
	ui->setup_img = lv_img_create(ui->setup);
	lv_obj_set_pos(ui->setup_img, 217, 72);
	lv_obj_set_size(ui->setup_img, 25, 29);
	lv_obj_set_scrollbar_mode(ui->setup_img, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_setup_img_main_main_default
	static lv_style_t style_setup_img_main_main_default;
	if (style_setup_img_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_setup_img_main_main_default);
	else
		lv_style_init(&style_setup_img_main_main_default);
	lv_style_set_img_recolor(&style_setup_img_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_setup_img_main_main_default, 0);
	lv_style_set_img_opa(&style_setup_img_main_main_default, 255);
	lv_obj_add_style(ui->setup_img, &style_setup_img_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->setup_img, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->setup_img,&_no_internet_25x29);
	lv_img_set_pivot(ui->setup_img, 0,0);
	lv_img_set_angle(ui->setup_img, 0);

	//Write codes setup_cloud
	ui->setup_cloud = lv_img_create(ui->setup);
	lv_obj_set_pos(ui->setup_cloud, 258, 35);
	lv_obj_set_size(ui->setup_cloud, 55, 47);
	lv_obj_set_scrollbar_mode(ui->setup_cloud, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_setup_cloud_main_main_default
	static lv_style_t style_setup_cloud_main_main_default;
	if (style_setup_cloud_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_setup_cloud_main_main_default);
	else
		lv_style_init(&style_setup_cloud_main_main_default);
	lv_style_set_img_recolor(&style_setup_cloud_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_setup_cloud_main_main_default, 0);
	lv_style_set_img_opa(&style_setup_cloud_main_main_default, 255);
	lv_obj_add_style(ui->setup_cloud, &style_setup_cloud_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->setup_cloud, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->setup_cloud,&_cloud_55x47);
	lv_img_set_pivot(ui->setup_cloud, 0,0);
	lv_img_set_angle(ui->setup_cloud, 0);
}