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


void setup_scr_saved(lv_ui *ui){

	//Write codes saved
	ui->saved = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->saved, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_saved_main_main_default
	static lv_style_t style_saved_main_main_default;
	if (style_saved_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_saved_main_main_default);
	else
		lv_style_init(&style_saved_main_main_default);
	lv_style_set_bg_color(&style_saved_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_saved_main_main_default, 0);
	lv_obj_add_style(ui->saved, &style_saved_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes saved_cont0
	ui->saved_cont0 = lv_obj_create(ui->saved);
	lv_obj_set_pos(ui->saved_cont0, 0, 0);
	lv_obj_set_size(ui->saved_cont0, 480, 320);
	lv_obj_set_scrollbar_mode(ui->saved_cont0, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_saved_cont0_main_main_default
	static lv_style_t style_saved_cont0_main_main_default;
	if (style_saved_cont0_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_saved_cont0_main_main_default);
	else
		lv_style_init(&style_saved_cont0_main_main_default);
	lv_style_set_radius(&style_saved_cont0_main_main_default, 0);
	lv_style_set_bg_color(&style_saved_cont0_main_main_default, lv_color_make(0x4a, 0xb2, 0x43));
	lv_style_set_bg_grad_color(&style_saved_cont0_main_main_default, lv_color_make(0x4a, 0xb2, 0x43));
	lv_style_set_bg_grad_dir(&style_saved_cont0_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_saved_cont0_main_main_default, 255);
	lv_style_set_shadow_width(&style_saved_cont0_main_main_default, 0);
	lv_style_set_shadow_color(&style_saved_cont0_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_saved_cont0_main_main_default, 255);
	lv_style_set_shadow_spread(&style_saved_cont0_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_saved_cont0_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_saved_cont0_main_main_default, 0);
	lv_style_set_border_color(&style_saved_cont0_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_saved_cont0_main_main_default, 0);
	lv_style_set_border_opa(&style_saved_cont0_main_main_default, 255);
	lv_style_set_pad_left(&style_saved_cont0_main_main_default, 0);
	lv_style_set_pad_right(&style_saved_cont0_main_main_default, 0);
	lv_style_set_pad_top(&style_saved_cont0_main_main_default, 0);
	lv_style_set_pad_bottom(&style_saved_cont0_main_main_default, 0);
	lv_obj_add_style(ui->saved_cont0, &style_saved_cont0_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes saved_btnsavecontinue
	ui->saved_btnsavecontinue = lv_btn_create(ui->saved);
	lv_obj_set_pos(ui->saved_btnsavecontinue, 168, 229);
	lv_obj_set_size(ui->saved_btnsavecontinue, 140, 47);
	lv_obj_set_scrollbar_mode(ui->saved_btnsavecontinue, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_saved_btnsavecontinue_main_main_default
	static lv_style_t style_saved_btnsavecontinue_main_main_default;
	if (style_saved_btnsavecontinue_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_saved_btnsavecontinue_main_main_default);
	else
		lv_style_init(&style_saved_btnsavecontinue_main_main_default);
	lv_style_set_radius(&style_saved_btnsavecontinue_main_main_default, 50);
	lv_style_set_bg_color(&style_saved_btnsavecontinue_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_saved_btnsavecontinue_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_saved_btnsavecontinue_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_saved_btnsavecontinue_main_main_default, 255);
	lv_style_set_shadow_width(&style_saved_btnsavecontinue_main_main_default, 0);
	lv_style_set_shadow_color(&style_saved_btnsavecontinue_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_saved_btnsavecontinue_main_main_default, 0);
	lv_style_set_shadow_spread(&style_saved_btnsavecontinue_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_saved_btnsavecontinue_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_saved_btnsavecontinue_main_main_default, 0);
	lv_style_set_border_color(&style_saved_btnsavecontinue_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_saved_btnsavecontinue_main_main_default, 2);
	lv_style_set_border_opa(&style_saved_btnsavecontinue_main_main_default, 255);
	lv_style_set_text_color(&style_saved_btnsavecontinue_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_saved_btnsavecontinue_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_align(&style_saved_btnsavecontinue_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->saved_btnsavecontinue, &style_saved_btnsavecontinue_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->saved_btnsavecontinue_label = lv_label_create(ui->saved_btnsavecontinue);
	lv_label_set_text(ui->saved_btnsavecontinue_label, "CONTINUE");
	lv_obj_set_style_pad_all(ui->saved_btnsavecontinue, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->saved_btnsavecontinue_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes saved_label2
	ui->saved_label2 = lv_label_create(ui->saved);
	lv_obj_set_pos(ui->saved_label2, 150, 188);
	lv_obj_set_size(ui->saved_label2, 180, 23);
	lv_obj_set_scrollbar_mode(ui->saved_label2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->saved_label2, "File saved");
	lv_label_set_long_mode(ui->saved_label2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_saved_label2_main_main_default
	static lv_style_t style_saved_label2_main_main_default;
	if (style_saved_label2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_saved_label2_main_main_default);
	else
		lv_style_init(&style_saved_label2_main_main_default);
	lv_style_set_radius(&style_saved_label2_main_main_default, 0);
	lv_style_set_bg_color(&style_saved_label2_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_saved_label2_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_saved_label2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_saved_label2_main_main_default, 0);
	lv_style_set_shadow_width(&style_saved_label2_main_main_default, 0);
	lv_style_set_shadow_color(&style_saved_label2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_saved_label2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_saved_label2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_saved_label2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_saved_label2_main_main_default, 0);
	lv_style_set_text_color(&style_saved_label2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_saved_label2_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_saved_label2_main_main_default, 2);
	lv_style_set_text_line_space(&style_saved_label2_main_main_default, 0);
	lv_style_set_text_align(&style_saved_label2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_saved_label2_main_main_default, 0);
	lv_style_set_pad_right(&style_saved_label2_main_main_default, 0);
	lv_style_set_pad_top(&style_saved_label2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_saved_label2_main_main_default, 0);
	lv_obj_add_style(ui->saved_label2, &style_saved_label2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes saved_img1
	ui->saved_img1 = lv_img_create(ui->saved);
	lv_obj_set_pos(ui->saved_img1, 185, 47);
	lv_obj_set_size(ui->saved_img1, 100, 117);
	lv_obj_set_scrollbar_mode(ui->saved_img1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_saved_img1_main_main_default
	static lv_style_t style_saved_img1_main_main_default;
	if (style_saved_img1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_saved_img1_main_main_default);
	else
		lv_style_init(&style_saved_img1_main_main_default);
	lv_style_set_img_recolor(&style_saved_img1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_saved_img1_main_main_default, 0);
	lv_style_set_img_opa(&style_saved_img1_main_main_default, 255);
	lv_obj_add_style(ui->saved_img1, &style_saved_img1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->saved_img1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->saved_img1,&_ready_100x117);
	lv_img_set_pivot(ui->saved_img1, 0,0);
	lv_img_set_angle(ui->saved_img1, 0);
}