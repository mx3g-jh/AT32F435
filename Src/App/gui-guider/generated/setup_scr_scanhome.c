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


void setup_scr_scanhome(lv_ui *ui){

	//Write codes scanhome
	ui->scanhome = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->scanhome, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_scanhome_main_main_default
	static lv_style_t style_scanhome_main_main_default;
	if (style_scanhome_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_scanhome_main_main_default);
	else
		lv_style_init(&style_scanhome_main_main_default);
	lv_style_set_bg_color(&style_scanhome_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_scanhome_main_main_default, 0);
	lv_obj_add_style(ui->scanhome, &style_scanhome_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scanhome_cont0
	ui->scanhome_cont0 = lv_obj_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_cont0, 0, 0);
	lv_obj_set_size(ui->scanhome_cont0, 480, 117);
	lv_obj_set_scrollbar_mode(ui->scanhome_cont0, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_scanhome_cont0_main_main_default
	static lv_style_t style_scanhome_cont0_main_main_default;
	if (style_scanhome_cont0_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_scanhome_cont0_main_main_default);
	else
		lv_style_init(&style_scanhome_cont0_main_main_default);
	lv_style_set_radius(&style_scanhome_cont0_main_main_default, 0);
	lv_style_set_bg_color(&style_scanhome_cont0_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_scanhome_cont0_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_scanhome_cont0_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_scanhome_cont0_main_main_default, 255);
	lv_style_set_shadow_width(&style_scanhome_cont0_main_main_default, 0);
	lv_style_set_shadow_color(&style_scanhome_cont0_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_scanhome_cont0_main_main_default, 255);
	lv_style_set_shadow_spread(&style_scanhome_cont0_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_scanhome_cont0_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_scanhome_cont0_main_main_default, 0);
	lv_style_set_border_color(&style_scanhome_cont0_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_scanhome_cont0_main_main_default, 0);
	lv_style_set_border_opa(&style_scanhome_cont0_main_main_default, 255);
	lv_style_set_pad_left(&style_scanhome_cont0_main_main_default, 0);
	lv_style_set_pad_right(&style_scanhome_cont0_main_main_default, 0);
	lv_style_set_pad_top(&style_scanhome_cont0_main_main_default, 0);
	lv_style_set_pad_bottom(&style_scanhome_cont0_main_main_default, 0);
	lv_obj_add_style(ui->scanhome_cont0, &style_scanhome_cont0_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scanhome_label1
	ui->scanhome_label1 = lv_label_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_label1, 136, 35);
	lv_obj_set_size(ui->scanhome_label1, 225, 23);
	lv_obj_set_scrollbar_mode(ui->scanhome_label1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->scanhome_label1, "ADJUST IMAGE");
	lv_label_set_long_mode(ui->scanhome_label1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_scanhome_label1_main_main_default
	static lv_style_t style_scanhome_label1_main_main_default;
	if (style_scanhome_label1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_scanhome_label1_main_main_default);
	else
		lv_style_init(&style_scanhome_label1_main_main_default);
	lv_style_set_radius(&style_scanhome_label1_main_main_default, 0);
	lv_style_set_bg_color(&style_scanhome_label1_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_scanhome_label1_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_scanhome_label1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_scanhome_label1_main_main_default, 0);
	lv_style_set_shadow_width(&style_scanhome_label1_main_main_default, 0);
	lv_style_set_shadow_color(&style_scanhome_label1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_scanhome_label1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_scanhome_label1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_scanhome_label1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_scanhome_label1_main_main_default, 0);
	lv_style_set_text_color(&style_scanhome_label1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_scanhome_label1_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_scanhome_label1_main_main_default, 2);
	lv_style_set_text_line_space(&style_scanhome_label1_main_main_default, 0);
	lv_style_set_text_align(&style_scanhome_label1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_scanhome_label1_main_main_default, 0);
	lv_style_set_pad_right(&style_scanhome_label1_main_main_default, 0);
	lv_style_set_pad_top(&style_scanhome_label1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_scanhome_label1_main_main_default, 0);
	lv_obj_add_style(ui->scanhome_label1, &style_scanhome_label1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scanhome_cont2
	ui->scanhome_cont2 = lv_obj_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_cont2, 0, 117);
	lv_obj_set_size(ui->scanhome_cont2, 480, 202);
	lv_obj_set_scrollbar_mode(ui->scanhome_cont2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_scanhome_cont2_main_main_default
	static lv_style_t style_scanhome_cont2_main_main_default;
	if (style_scanhome_cont2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_scanhome_cont2_main_main_default);
	else
		lv_style_init(&style_scanhome_cont2_main_main_default);
	lv_style_set_radius(&style_scanhome_cont2_main_main_default, 0);
	lv_style_set_bg_color(&style_scanhome_cont2_main_main_default, lv_color_make(0xde, 0xde, 0xde));
	lv_style_set_bg_grad_color(&style_scanhome_cont2_main_main_default, lv_color_make(0xde, 0xde, 0xde));
	lv_style_set_bg_grad_dir(&style_scanhome_cont2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_scanhome_cont2_main_main_default, 255);
	lv_style_set_shadow_width(&style_scanhome_cont2_main_main_default, 0);
	lv_style_set_shadow_color(&style_scanhome_cont2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_scanhome_cont2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_scanhome_cont2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_scanhome_cont2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_scanhome_cont2_main_main_default, 0);
	lv_style_set_border_color(&style_scanhome_cont2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_scanhome_cont2_main_main_default, 0);
	lv_style_set_border_opa(&style_scanhome_cont2_main_main_default, 255);
	lv_style_set_pad_left(&style_scanhome_cont2_main_main_default, 0);
	lv_style_set_pad_right(&style_scanhome_cont2_main_main_default, 0);
	lv_style_set_pad_top(&style_scanhome_cont2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_scanhome_cont2_main_main_default, 0);
	lv_obj_add_style(ui->scanhome_cont2, &style_scanhome_cont2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scanhome_img3
	ui->scanhome_img3 = lv_img_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_img3, 27, 88);
	lv_obj_set_size(ui->scanhome_img3, 300, 202);
	lv_obj_set_scrollbar_mode(ui->scanhome_img3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_scanhome_img3_main_main_default
	static lv_style_t style_scanhome_img3_main_main_default;
	if (style_scanhome_img3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_scanhome_img3_main_main_default);
	else
		lv_style_init(&style_scanhome_img3_main_main_default);
	lv_style_set_img_recolor(&style_scanhome_img3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_scanhome_img3_main_main_default, 0);
	lv_style_set_img_opa(&style_scanhome_img3_main_main_default, 255);
	lv_obj_add_style(ui->scanhome_img3, &style_scanhome_img3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->scanhome_img3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scanhome_img3,&_example_300x202);
	lv_img_set_pivot(ui->scanhome_img3, 0,0);
	lv_img_set_angle(ui->scanhome_img3, 0);

	//Write codes scanhome_cont4
	ui->scanhome_cont4 = lv_obj_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_cont4, 368, 94);
	lv_obj_set_size(ui->scanhome_cont4, 80, 152);
	lv_obj_set_scrollbar_mode(ui->scanhome_cont4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_scanhome_cont4_main_main_default
	static lv_style_t style_scanhome_cont4_main_main_default;
	if (style_scanhome_cont4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_scanhome_cont4_main_main_default);
	else
		lv_style_init(&style_scanhome_cont4_main_main_default);
	lv_style_set_radius(&style_scanhome_cont4_main_main_default, 0);
	lv_style_set_bg_color(&style_scanhome_cont4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_scanhome_cont4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_scanhome_cont4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_scanhome_cont4_main_main_default, 255);
	lv_style_set_shadow_width(&style_scanhome_cont4_main_main_default, 0);
	lv_style_set_shadow_color(&style_scanhome_cont4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_scanhome_cont4_main_main_default, 255);
	lv_style_set_shadow_spread(&style_scanhome_cont4_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_scanhome_cont4_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_scanhome_cont4_main_main_default, 0);
	lv_style_set_border_color(&style_scanhome_cont4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_scanhome_cont4_main_main_default, 0);
	lv_style_set_border_opa(&style_scanhome_cont4_main_main_default, 255);
	lv_style_set_pad_left(&style_scanhome_cont4_main_main_default, 0);
	lv_style_set_pad_right(&style_scanhome_cont4_main_main_default, 0);
	lv_style_set_pad_top(&style_scanhome_cont4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_scanhome_cont4_main_main_default, 0);
	lv_obj_add_style(ui->scanhome_cont4, &style_scanhome_cont4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scanhome_btnscansave
	ui->scanhome_btnscansave = lv_btn_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_btnscansave, 368, 260);
	lv_obj_set_size(ui->scanhome_btnscansave, 80, 47);
	lv_obj_set_scrollbar_mode(ui->scanhome_btnscansave, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_scanhome_btnscansave_main_main_default
	static lv_style_t style_scanhome_btnscansave_main_main_default;
	if (style_scanhome_btnscansave_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_scanhome_btnscansave_main_main_default);
	else
		lv_style_init(&style_scanhome_btnscansave_main_main_default);
	lv_style_set_radius(&style_scanhome_btnscansave_main_main_default, 50);
	lv_style_set_bg_color(&style_scanhome_btnscansave_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_scanhome_btnscansave_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_scanhome_btnscansave_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_scanhome_btnscansave_main_main_default, 255);
	lv_style_set_shadow_width(&style_scanhome_btnscansave_main_main_default, 0);
	lv_style_set_shadow_color(&style_scanhome_btnscansave_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_scanhome_btnscansave_main_main_default, 0);
	lv_style_set_shadow_spread(&style_scanhome_btnscansave_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_scanhome_btnscansave_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_scanhome_btnscansave_main_main_default, 0);
	lv_style_set_border_color(&style_scanhome_btnscansave_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_scanhome_btnscansave_main_main_default, 0);
	lv_style_set_border_opa(&style_scanhome_btnscansave_main_main_default, 255);
	lv_style_set_text_color(&style_scanhome_btnscansave_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_scanhome_btnscansave_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_align(&style_scanhome_btnscansave_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->scanhome_btnscansave, &style_scanhome_btnscansave_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->scanhome_btnscansave_label = lv_label_create(ui->scanhome_btnscansave);
	lv_label_set_text(ui->scanhome_btnscansave_label, "SAVE");
	lv_obj_set_style_pad_all(ui->scanhome_btnscansave, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->scanhome_btnscansave_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes scanhome_sliderhue
	ui->scanhome_sliderhue = lv_slider_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_sliderhue, 420, 135);
	lv_obj_set_size(ui->scanhome_sliderhue, 8, 94);
	lv_obj_set_scrollbar_mode(ui->scanhome_sliderhue, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_scanhome_sliderhue_main_main_default
	static lv_style_t style_scanhome_sliderhue_main_main_default;
	if (style_scanhome_sliderhue_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_scanhome_sliderhue_main_main_default);
	else
		lv_style_init(&style_scanhome_sliderhue_main_main_default);
	lv_style_set_radius(&style_scanhome_sliderhue_main_main_default, 50);
	lv_style_set_bg_color(&style_scanhome_sliderhue_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_scanhome_sliderhue_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_scanhome_sliderhue_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_scanhome_sliderhue_main_main_default, 255);
	lv_style_set_shadow_width(&style_scanhome_sliderhue_main_main_default, 0);
	lv_style_set_shadow_color(&style_scanhome_sliderhue_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_scanhome_sliderhue_main_main_default, 255);
	lv_style_set_shadow_spread(&style_scanhome_sliderhue_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_scanhome_sliderhue_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_scanhome_sliderhue_main_main_default, 0);
	lv_style_set_outline_color(&style_scanhome_sliderhue_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_outline_width(&style_scanhome_sliderhue_main_main_default, 0);
	lv_style_set_outline_opa(&style_scanhome_sliderhue_main_main_default, 0);
	lv_obj_add_style(ui->scanhome_sliderhue, &style_scanhome_sliderhue_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_scanhome_sliderhue_main_indicator_default
	static lv_style_t style_scanhome_sliderhue_main_indicator_default;
	if (style_scanhome_sliderhue_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_scanhome_sliderhue_main_indicator_default);
	else
		lv_style_init(&style_scanhome_sliderhue_main_indicator_default);
	lv_style_set_radius(&style_scanhome_sliderhue_main_indicator_default, 50);
	lv_style_set_bg_color(&style_scanhome_sliderhue_main_indicator_default, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_color(&style_scanhome_sliderhue_main_indicator_default, lv_color_make(0xdd, 0xd7, 0xd9));
	lv_style_set_bg_grad_dir(&style_scanhome_sliderhue_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_scanhome_sliderhue_main_indicator_default, 255);
	lv_obj_add_style(ui->scanhome_sliderhue, &style_scanhome_sliderhue_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_scanhome_sliderhue_main_knob_default
	static lv_style_t style_scanhome_sliderhue_main_knob_default;
	if (style_scanhome_sliderhue_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_scanhome_sliderhue_main_knob_default);
	else
		lv_style_init(&style_scanhome_sliderhue_main_knob_default);
	lv_style_set_radius(&style_scanhome_sliderhue_main_knob_default, 50);
	lv_style_set_bg_color(&style_scanhome_sliderhue_main_knob_default, lv_color_make(0x29, 0x30, 0x41));
	lv_style_set_bg_grad_color(&style_scanhome_sliderhue_main_knob_default, lv_color_make(0x29, 0x30, 0x41));
	lv_style_set_bg_grad_dir(&style_scanhome_sliderhue_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_scanhome_sliderhue_main_knob_default, 255);
	lv_obj_add_style(ui->scanhome_sliderhue, &style_scanhome_sliderhue_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_slider_set_range(ui->scanhome_sliderhue,0, 100);
	lv_slider_set_value(ui->scanhome_sliderhue,50,false);

	//Write codes scanhome_sliderbright
	ui->scanhome_sliderbright = lv_slider_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_sliderbright, 380, 135);
	lv_obj_set_size(ui->scanhome_sliderbright, 8, 94);
	lv_obj_set_scrollbar_mode(ui->scanhome_sliderbright, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_scanhome_sliderbright_main_main_default
	static lv_style_t style_scanhome_sliderbright_main_main_default;
	if (style_scanhome_sliderbright_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_scanhome_sliderbright_main_main_default);
	else
		lv_style_init(&style_scanhome_sliderbright_main_main_default);
	lv_style_set_radius(&style_scanhome_sliderbright_main_main_default, 50);
	lv_style_set_bg_color(&style_scanhome_sliderbright_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_scanhome_sliderbright_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_scanhome_sliderbright_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_scanhome_sliderbright_main_main_default, 255);
	lv_style_set_shadow_width(&style_scanhome_sliderbright_main_main_default, 0);
	lv_style_set_shadow_color(&style_scanhome_sliderbright_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_scanhome_sliderbright_main_main_default, 255);
	lv_style_set_shadow_spread(&style_scanhome_sliderbright_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_scanhome_sliderbright_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_scanhome_sliderbright_main_main_default, 0);
	lv_style_set_outline_color(&style_scanhome_sliderbright_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_outline_width(&style_scanhome_sliderbright_main_main_default, 0);
	lv_style_set_outline_opa(&style_scanhome_sliderbright_main_main_default, 0);
	lv_obj_add_style(ui->scanhome_sliderbright, &style_scanhome_sliderbright_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_scanhome_sliderbright_main_indicator_default
	static lv_style_t style_scanhome_sliderbright_main_indicator_default;
	if (style_scanhome_sliderbright_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_scanhome_sliderbright_main_indicator_default);
	else
		lv_style_init(&style_scanhome_sliderbright_main_indicator_default);
	lv_style_set_radius(&style_scanhome_sliderbright_main_indicator_default, 50);
	lv_style_set_bg_color(&style_scanhome_sliderbright_main_indicator_default, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_color(&style_scanhome_sliderbright_main_indicator_default, lv_color_make(0xdd, 0xd7, 0xd9));
	lv_style_set_bg_grad_dir(&style_scanhome_sliderbright_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_scanhome_sliderbright_main_indicator_default, 255);
	lv_obj_add_style(ui->scanhome_sliderbright, &style_scanhome_sliderbright_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_scanhome_sliderbright_main_knob_default
	static lv_style_t style_scanhome_sliderbright_main_knob_default;
	if (style_scanhome_sliderbright_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_scanhome_sliderbright_main_knob_default);
	else
		lv_style_init(&style_scanhome_sliderbright_main_knob_default);
	lv_style_set_radius(&style_scanhome_sliderbright_main_knob_default, 50);
	lv_style_set_bg_color(&style_scanhome_sliderbright_main_knob_default, lv_color_make(0x29, 0x30, 0x41));
	lv_style_set_bg_grad_color(&style_scanhome_sliderbright_main_knob_default, lv_color_make(0x29, 0x30, 0x41));
	lv_style_set_bg_grad_dir(&style_scanhome_sliderbright_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_scanhome_sliderbright_main_knob_default, 255);
	lv_obj_add_style(ui->scanhome_sliderbright, &style_scanhome_sliderbright_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_slider_set_range(ui->scanhome_sliderbright,0, 100);
	lv_slider_set_value(ui->scanhome_sliderbright,50,false);

	//Write codes scanhome_bright
	ui->scanhome_bright = lv_img_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_bright, 372, 96);
	lv_obj_set_size(ui->scanhome_bright, 24, 28);
	lv_obj_set_scrollbar_mode(ui->scanhome_bright, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_scanhome_bright_main_main_default
	static lv_style_t style_scanhome_bright_main_main_default;
	if (style_scanhome_bright_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_scanhome_bright_main_main_default);
	else
		lv_style_init(&style_scanhome_bright_main_main_default);
	lv_style_set_img_recolor(&style_scanhome_bright_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_scanhome_bright_main_main_default, 0);
	lv_style_set_img_opa(&style_scanhome_bright_main_main_default, 255);
	lv_obj_add_style(ui->scanhome_bright, &style_scanhome_bright_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->scanhome_bright, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scanhome_bright,&_bright_24x28);
	lv_img_set_pivot(ui->scanhome_bright, 0,0);
	lv_img_set_angle(ui->scanhome_bright, 0);

	//Write codes scanhome_hue
	ui->scanhome_hue = lv_img_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_hue, 413, 97);
	lv_obj_set_size(ui->scanhome_hue, 21, 24);
	lv_obj_set_scrollbar_mode(ui->scanhome_hue, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_scanhome_hue_main_main_default
	static lv_style_t style_scanhome_hue_main_main_default;
	if (style_scanhome_hue_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_scanhome_hue_main_main_default);
	else
		lv_style_init(&style_scanhome_hue_main_main_default);
	lv_style_set_img_recolor(&style_scanhome_hue_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_scanhome_hue_main_main_default, 0);
	lv_style_set_img_opa(&style_scanhome_hue_main_main_default, 255);
	lv_obj_add_style(ui->scanhome_hue, &style_scanhome_hue_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->scanhome_hue, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scanhome_hue,&_hue_21x24);
	lv_img_set_pivot(ui->scanhome_hue, 0,0);
	lv_img_set_angle(ui->scanhome_hue, 0);

	//Write codes scanhome_btnscanback
	ui->scanhome_btnscanback = lv_btn_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_btnscanback, 50, 29);
	lv_obj_set_size(ui->scanhome_btnscanback, 30, 35);
	lv_obj_set_scrollbar_mode(ui->scanhome_btnscanback, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_scanhome_btnscanback_main_main_default
	static lv_style_t style_scanhome_btnscanback_main_main_default;
	if (style_scanhome_btnscanback_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_scanhome_btnscanback_main_main_default);
	else
		lv_style_init(&style_scanhome_btnscanback_main_main_default);
	lv_style_set_radius(&style_scanhome_btnscanback_main_main_default, 50);
	lv_style_set_bg_color(&style_scanhome_btnscanback_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_scanhome_btnscanback_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_scanhome_btnscanback_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_scanhome_btnscanback_main_main_default, 255);
	lv_style_set_shadow_width(&style_scanhome_btnscanback_main_main_default, 0);
	lv_style_set_shadow_color(&style_scanhome_btnscanback_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_scanhome_btnscanback_main_main_default, 0);
	lv_style_set_shadow_spread(&style_scanhome_btnscanback_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_scanhome_btnscanback_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_scanhome_btnscanback_main_main_default, 0);
	lv_style_set_border_color(&style_scanhome_btnscanback_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_scanhome_btnscanback_main_main_default, 0);
	lv_style_set_border_opa(&style_scanhome_btnscanback_main_main_default, 255);
	lv_style_set_text_color(&style_scanhome_btnscanback_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_scanhome_btnscanback_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_align(&style_scanhome_btnscanback_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->scanhome_btnscanback, &style_scanhome_btnscanback_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->scanhome_btnscanback_label = lv_label_create(ui->scanhome_btnscanback);
	lv_label_set_text(ui->scanhome_btnscanback_label, "<");
	lv_obj_set_style_pad_all(ui->scanhome_btnscanback, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->scanhome_btnscanback_label, LV_ALIGN_CENTER, 0, 0);
}