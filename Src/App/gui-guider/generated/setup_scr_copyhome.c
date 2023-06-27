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


void setup_scr_copyhome(lv_ui *ui){

	//Write codes copyhome
	ui->copyhome = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->copyhome, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copyhome_main_main_default
	static lv_style_t style_copyhome_main_main_default;
	if (style_copyhome_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copyhome_main_main_default);
	else
		lv_style_init(&style_copyhome_main_main_default);
	lv_style_set_bg_color(&style_copyhome_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_copyhome_main_main_default, 0);
	lv_obj_add_style(ui->copyhome, &style_copyhome_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes copyhome_cont1
	ui->copyhome_cont1 = lv_obj_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_cont1, 0, 0);
	lv_obj_set_size(ui->copyhome_cont1, 480, 117);
	lv_obj_set_scrollbar_mode(ui->copyhome_cont1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copyhome_cont1_main_main_default
	static lv_style_t style_copyhome_cont1_main_main_default;
	if (style_copyhome_cont1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copyhome_cont1_main_main_default);
	else
		lv_style_init(&style_copyhome_cont1_main_main_default);
	lv_style_set_radius(&style_copyhome_cont1_main_main_default, 0);
	lv_style_set_bg_color(&style_copyhome_cont1_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_copyhome_cont1_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_copyhome_cont1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copyhome_cont1_main_main_default, 255);
	lv_style_set_shadow_width(&style_copyhome_cont1_main_main_default, 0);
	lv_style_set_shadow_color(&style_copyhome_cont1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copyhome_cont1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_copyhome_cont1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copyhome_cont1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copyhome_cont1_main_main_default, 0);
	lv_style_set_border_color(&style_copyhome_cont1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_copyhome_cont1_main_main_default, 0);
	lv_style_set_border_opa(&style_copyhome_cont1_main_main_default, 255);
	lv_style_set_pad_left(&style_copyhome_cont1_main_main_default, 0);
	lv_style_set_pad_right(&style_copyhome_cont1_main_main_default, 0);
	lv_style_set_pad_top(&style_copyhome_cont1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_copyhome_cont1_main_main_default, 0);
	lv_obj_add_style(ui->copyhome_cont1, &style_copyhome_cont1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes copyhome_cont2
	ui->copyhome_cont2 = lv_obj_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_cont2, 0, 117);
	lv_obj_set_size(ui->copyhome_cont2, 480, 202);
	lv_obj_set_scrollbar_mode(ui->copyhome_cont2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copyhome_cont2_main_main_default
	static lv_style_t style_copyhome_cont2_main_main_default;
	if (style_copyhome_cont2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copyhome_cont2_main_main_default);
	else
		lv_style_init(&style_copyhome_cont2_main_main_default);
	lv_style_set_radius(&style_copyhome_cont2_main_main_default, 0);
	lv_style_set_bg_color(&style_copyhome_cont2_main_main_default, lv_color_make(0xde, 0xde, 0xde));
	lv_style_set_bg_grad_color(&style_copyhome_cont2_main_main_default, lv_color_make(0xde, 0xde, 0xde));
	lv_style_set_bg_grad_dir(&style_copyhome_cont2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copyhome_cont2_main_main_default, 255);
	lv_style_set_shadow_width(&style_copyhome_cont2_main_main_default, 0);
	lv_style_set_shadow_color(&style_copyhome_cont2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copyhome_cont2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_copyhome_cont2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copyhome_cont2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copyhome_cont2_main_main_default, 0);
	lv_style_set_border_color(&style_copyhome_cont2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_copyhome_cont2_main_main_default, 0);
	lv_style_set_border_opa(&style_copyhome_cont2_main_main_default, 255);
	lv_style_set_pad_left(&style_copyhome_cont2_main_main_default, 0);
	lv_style_set_pad_right(&style_copyhome_cont2_main_main_default, 0);
	lv_style_set_pad_top(&style_copyhome_cont2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_copyhome_cont2_main_main_default, 0);
	lv_obj_add_style(ui->copyhome_cont2, &style_copyhome_cont2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes copyhome_label1
	ui->copyhome_label1 = lv_label_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_label1, 136, 35);
	lv_obj_set_size(ui->copyhome_label1, 225, 23);
	lv_obj_set_scrollbar_mode(ui->copyhome_label1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->copyhome_label1, "ADJUST IMAGE");
	lv_label_set_long_mode(ui->copyhome_label1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_copyhome_label1_main_main_default
	static lv_style_t style_copyhome_label1_main_main_default;
	if (style_copyhome_label1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copyhome_label1_main_main_default);
	else
		lv_style_init(&style_copyhome_label1_main_main_default);
	lv_style_set_radius(&style_copyhome_label1_main_main_default, 0);
	lv_style_set_bg_color(&style_copyhome_label1_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_copyhome_label1_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_copyhome_label1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copyhome_label1_main_main_default, 0);
	lv_style_set_shadow_width(&style_copyhome_label1_main_main_default, 0);
	lv_style_set_shadow_color(&style_copyhome_label1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copyhome_label1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_copyhome_label1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copyhome_label1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copyhome_label1_main_main_default, 0);
	lv_style_set_text_color(&style_copyhome_label1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_copyhome_label1_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_copyhome_label1_main_main_default, 2);
	lv_style_set_text_line_space(&style_copyhome_label1_main_main_default, 0);
	lv_style_set_text_align(&style_copyhome_label1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_copyhome_label1_main_main_default, 0);
	lv_style_set_pad_right(&style_copyhome_label1_main_main_default, 0);
	lv_style_set_pad_top(&style_copyhome_label1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_copyhome_label1_main_main_default, 0);
	lv_obj_add_style(ui->copyhome_label1, &style_copyhome_label1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes copyhome_img3
	ui->copyhome_img3 = lv_img_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_img3, 27, 88);
	lv_obj_set_size(ui->copyhome_img3, 300, 202);
	lv_obj_set_scrollbar_mode(ui->copyhome_img3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copyhome_img3_main_main_default
	static lv_style_t style_copyhome_img3_main_main_default;
	if (style_copyhome_img3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copyhome_img3_main_main_default);
	else
		lv_style_init(&style_copyhome_img3_main_main_default);
	lv_style_set_img_recolor(&style_copyhome_img3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_copyhome_img3_main_main_default, 0);
	lv_style_set_img_opa(&style_copyhome_img3_main_main_default, 255);
	lv_obj_add_style(ui->copyhome_img3, &style_copyhome_img3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->copyhome_img3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->copyhome_img3,&_example_300x202);
	lv_img_set_pivot(ui->copyhome_img3, 0,0);
	lv_img_set_angle(ui->copyhome_img3, 0);

	//Write codes copyhome_cont4
	ui->copyhome_cont4 = lv_obj_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_cont4, 368, 94);
	lv_obj_set_size(ui->copyhome_cont4, 80, 152);
	lv_obj_set_scrollbar_mode(ui->copyhome_cont4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copyhome_cont4_main_main_default
	static lv_style_t style_copyhome_cont4_main_main_default;
	if (style_copyhome_cont4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copyhome_cont4_main_main_default);
	else
		lv_style_init(&style_copyhome_cont4_main_main_default);
	lv_style_set_radius(&style_copyhome_cont4_main_main_default, 0);
	lv_style_set_bg_color(&style_copyhome_cont4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_copyhome_cont4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_copyhome_cont4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copyhome_cont4_main_main_default, 255);
	lv_style_set_shadow_width(&style_copyhome_cont4_main_main_default, 0);
	lv_style_set_shadow_color(&style_copyhome_cont4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copyhome_cont4_main_main_default, 255);
	lv_style_set_shadow_spread(&style_copyhome_cont4_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copyhome_cont4_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copyhome_cont4_main_main_default, 0);
	lv_style_set_border_color(&style_copyhome_cont4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_copyhome_cont4_main_main_default, 0);
	lv_style_set_border_opa(&style_copyhome_cont4_main_main_default, 255);
	lv_style_set_pad_left(&style_copyhome_cont4_main_main_default, 0);
	lv_style_set_pad_right(&style_copyhome_cont4_main_main_default, 0);
	lv_style_set_pad_top(&style_copyhome_cont4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_copyhome_cont4_main_main_default, 0);
	lv_obj_add_style(ui->copyhome_cont4, &style_copyhome_cont4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes copyhome_btncopynext
	ui->copyhome_btncopynext = lv_btn_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_btncopynext, 368, 260);
	lv_obj_set_size(ui->copyhome_btncopynext, 80, 47);
	lv_obj_set_scrollbar_mode(ui->copyhome_btncopynext, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copyhome_btncopynext_main_main_default
	static lv_style_t style_copyhome_btncopynext_main_main_default;
	if (style_copyhome_btncopynext_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copyhome_btncopynext_main_main_default);
	else
		lv_style_init(&style_copyhome_btncopynext_main_main_default);
	lv_style_set_radius(&style_copyhome_btncopynext_main_main_default, 50);
	lv_style_set_bg_color(&style_copyhome_btncopynext_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_copyhome_btncopynext_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_copyhome_btncopynext_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copyhome_btncopynext_main_main_default, 255);
	lv_style_set_shadow_width(&style_copyhome_btncopynext_main_main_default, 0);
	lv_style_set_shadow_color(&style_copyhome_btncopynext_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copyhome_btncopynext_main_main_default, 0);
	lv_style_set_shadow_spread(&style_copyhome_btncopynext_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copyhome_btncopynext_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copyhome_btncopynext_main_main_default, 0);
	lv_style_set_border_color(&style_copyhome_btncopynext_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_copyhome_btncopynext_main_main_default, 0);
	lv_style_set_border_opa(&style_copyhome_btncopynext_main_main_default, 255);
	lv_style_set_text_color(&style_copyhome_btncopynext_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_copyhome_btncopynext_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_align(&style_copyhome_btncopynext_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->copyhome_btncopynext, &style_copyhome_btncopynext_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->copyhome_btncopynext_label = lv_label_create(ui->copyhome_btncopynext);
	lv_label_set_text(ui->copyhome_btncopynext_label, "NEXT");
	lv_obj_set_style_pad_all(ui->copyhome_btncopynext, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->copyhome_btncopynext_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes copyhome_sliderhue
	ui->copyhome_sliderhue = lv_slider_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_sliderhue, 420, 135);
	lv_obj_set_size(ui->copyhome_sliderhue, 8, 94);
	lv_obj_set_scrollbar_mode(ui->copyhome_sliderhue, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copyhome_sliderhue_main_main_default
	static lv_style_t style_copyhome_sliderhue_main_main_default;
	if (style_copyhome_sliderhue_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copyhome_sliderhue_main_main_default);
	else
		lv_style_init(&style_copyhome_sliderhue_main_main_default);
	lv_style_set_radius(&style_copyhome_sliderhue_main_main_default, 50);
	lv_style_set_bg_color(&style_copyhome_sliderhue_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_copyhome_sliderhue_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_copyhome_sliderhue_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copyhome_sliderhue_main_main_default, 255);
	lv_style_set_shadow_width(&style_copyhome_sliderhue_main_main_default, 0);
	lv_style_set_shadow_color(&style_copyhome_sliderhue_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copyhome_sliderhue_main_main_default, 255);
	lv_style_set_shadow_spread(&style_copyhome_sliderhue_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copyhome_sliderhue_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copyhome_sliderhue_main_main_default, 0);
	lv_style_set_outline_color(&style_copyhome_sliderhue_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_outline_width(&style_copyhome_sliderhue_main_main_default, 0);
	lv_style_set_outline_opa(&style_copyhome_sliderhue_main_main_default, 0);
	lv_obj_add_style(ui->copyhome_sliderhue, &style_copyhome_sliderhue_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_copyhome_sliderhue_main_indicator_default
	static lv_style_t style_copyhome_sliderhue_main_indicator_default;
	if (style_copyhome_sliderhue_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_copyhome_sliderhue_main_indicator_default);
	else
		lv_style_init(&style_copyhome_sliderhue_main_indicator_default);
	lv_style_set_radius(&style_copyhome_sliderhue_main_indicator_default, 50);
	lv_style_set_bg_color(&style_copyhome_sliderhue_main_indicator_default, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_color(&style_copyhome_sliderhue_main_indicator_default, lv_color_make(0xdd, 0xd7, 0xd9));
	lv_style_set_bg_grad_dir(&style_copyhome_sliderhue_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copyhome_sliderhue_main_indicator_default, 255);
	lv_obj_add_style(ui->copyhome_sliderhue, &style_copyhome_sliderhue_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_copyhome_sliderhue_main_knob_default
	static lv_style_t style_copyhome_sliderhue_main_knob_default;
	if (style_copyhome_sliderhue_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_copyhome_sliderhue_main_knob_default);
	else
		lv_style_init(&style_copyhome_sliderhue_main_knob_default);
	lv_style_set_radius(&style_copyhome_sliderhue_main_knob_default, 50);
	lv_style_set_bg_color(&style_copyhome_sliderhue_main_knob_default, lv_color_make(0x29, 0x30, 0x41));
	lv_style_set_bg_grad_color(&style_copyhome_sliderhue_main_knob_default, lv_color_make(0x29, 0x30, 0x41));
	lv_style_set_bg_grad_dir(&style_copyhome_sliderhue_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copyhome_sliderhue_main_knob_default, 255);
	lv_obj_add_style(ui->copyhome_sliderhue, &style_copyhome_sliderhue_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_slider_set_range(ui->copyhome_sliderhue,0, 100);
	lv_slider_set_value(ui->copyhome_sliderhue,50,false);

	//Write codes copyhome_sliderbright
	ui->copyhome_sliderbright = lv_slider_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_sliderbright, 380, 135);
	lv_obj_set_size(ui->copyhome_sliderbright, 8, 94);
	lv_obj_set_scrollbar_mode(ui->copyhome_sliderbright, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copyhome_sliderbright_main_main_default
	static lv_style_t style_copyhome_sliderbright_main_main_default;
	if (style_copyhome_sliderbright_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copyhome_sliderbright_main_main_default);
	else
		lv_style_init(&style_copyhome_sliderbright_main_main_default);
	lv_style_set_radius(&style_copyhome_sliderbright_main_main_default, 50);
	lv_style_set_bg_color(&style_copyhome_sliderbright_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_copyhome_sliderbright_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_copyhome_sliderbright_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copyhome_sliderbright_main_main_default, 255);
	lv_style_set_shadow_width(&style_copyhome_sliderbright_main_main_default, 0);
	lv_style_set_shadow_color(&style_copyhome_sliderbright_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copyhome_sliderbright_main_main_default, 255);
	lv_style_set_shadow_spread(&style_copyhome_sliderbright_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copyhome_sliderbright_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copyhome_sliderbright_main_main_default, 0);
	lv_style_set_outline_color(&style_copyhome_sliderbright_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_outline_width(&style_copyhome_sliderbright_main_main_default, 0);
	lv_style_set_outline_opa(&style_copyhome_sliderbright_main_main_default, 0);
	lv_obj_add_style(ui->copyhome_sliderbright, &style_copyhome_sliderbright_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_copyhome_sliderbright_main_indicator_default
	static lv_style_t style_copyhome_sliderbright_main_indicator_default;
	if (style_copyhome_sliderbright_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_copyhome_sliderbright_main_indicator_default);
	else
		lv_style_init(&style_copyhome_sliderbright_main_indicator_default);
	lv_style_set_radius(&style_copyhome_sliderbright_main_indicator_default, 50);
	lv_style_set_bg_color(&style_copyhome_sliderbright_main_indicator_default, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_color(&style_copyhome_sliderbright_main_indicator_default, lv_color_make(0xdd, 0xd7, 0xd9));
	lv_style_set_bg_grad_dir(&style_copyhome_sliderbright_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copyhome_sliderbright_main_indicator_default, 255);
	lv_obj_add_style(ui->copyhome_sliderbright, &style_copyhome_sliderbright_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_copyhome_sliderbright_main_knob_default
	static lv_style_t style_copyhome_sliderbright_main_knob_default;
	if (style_copyhome_sliderbright_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_copyhome_sliderbright_main_knob_default);
	else
		lv_style_init(&style_copyhome_sliderbright_main_knob_default);
	lv_style_set_radius(&style_copyhome_sliderbright_main_knob_default, 50);
	lv_style_set_bg_color(&style_copyhome_sliderbright_main_knob_default, lv_color_make(0x29, 0x30, 0x41));
	lv_style_set_bg_grad_color(&style_copyhome_sliderbright_main_knob_default, lv_color_make(0x29, 0x30, 0x41));
	lv_style_set_bg_grad_dir(&style_copyhome_sliderbright_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copyhome_sliderbright_main_knob_default, 255);
	lv_obj_add_style(ui->copyhome_sliderbright, &style_copyhome_sliderbright_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_slider_set_range(ui->copyhome_sliderbright,0, 100);
	lv_slider_set_value(ui->copyhome_sliderbright,50,false);

	//Write codes copyhome_bright
	ui->copyhome_bright = lv_img_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_bright, 372, 96);
	lv_obj_set_size(ui->copyhome_bright, 24, 28);
	lv_obj_set_scrollbar_mode(ui->copyhome_bright, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copyhome_bright_main_main_default
	static lv_style_t style_copyhome_bright_main_main_default;
	if (style_copyhome_bright_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copyhome_bright_main_main_default);
	else
		lv_style_init(&style_copyhome_bright_main_main_default);
	lv_style_set_img_recolor(&style_copyhome_bright_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_copyhome_bright_main_main_default, 0);
	lv_style_set_img_opa(&style_copyhome_bright_main_main_default, 255);
	lv_obj_add_style(ui->copyhome_bright, &style_copyhome_bright_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->copyhome_bright, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->copyhome_bright,&_bright_24x28);
	lv_img_set_pivot(ui->copyhome_bright, 0,0);
	lv_img_set_angle(ui->copyhome_bright, 0);

	//Write codes copyhome_hue
	ui->copyhome_hue = lv_img_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_hue, 413, 97);
	lv_obj_set_size(ui->copyhome_hue, 21, 24);
	lv_obj_set_scrollbar_mode(ui->copyhome_hue, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copyhome_hue_main_main_default
	static lv_style_t style_copyhome_hue_main_main_default;
	if (style_copyhome_hue_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copyhome_hue_main_main_default);
	else
		lv_style_init(&style_copyhome_hue_main_main_default);
	lv_style_set_img_recolor(&style_copyhome_hue_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_copyhome_hue_main_main_default, 0);
	lv_style_set_img_opa(&style_copyhome_hue_main_main_default, 255);
	lv_obj_add_style(ui->copyhome_hue, &style_copyhome_hue_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->copyhome_hue, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->copyhome_hue,&_hue_21x24);
	lv_img_set_pivot(ui->copyhome_hue, 0,0);
	lv_img_set_angle(ui->copyhome_hue, 0);

	//Write codes copyhome_btncopyback
	ui->copyhome_btncopyback = lv_btn_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_btncopyback, 50, 29);
	lv_obj_set_size(ui->copyhome_btncopyback, 30, 35);
	lv_obj_set_scrollbar_mode(ui->copyhome_btncopyback, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copyhome_btncopyback_main_main_default
	static lv_style_t style_copyhome_btncopyback_main_main_default;
	if (style_copyhome_btncopyback_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copyhome_btncopyback_main_main_default);
	else
		lv_style_init(&style_copyhome_btncopyback_main_main_default);
	lv_style_set_radius(&style_copyhome_btncopyback_main_main_default, 50);
	lv_style_set_bg_color(&style_copyhome_btncopyback_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_copyhome_btncopyback_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_copyhome_btncopyback_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copyhome_btncopyback_main_main_default, 255);
	lv_style_set_shadow_width(&style_copyhome_btncopyback_main_main_default, 0);
	lv_style_set_shadow_color(&style_copyhome_btncopyback_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copyhome_btncopyback_main_main_default, 0);
	lv_style_set_shadow_spread(&style_copyhome_btncopyback_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copyhome_btncopyback_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copyhome_btncopyback_main_main_default, 0);
	lv_style_set_border_color(&style_copyhome_btncopyback_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_copyhome_btncopyback_main_main_default, 0);
	lv_style_set_border_opa(&style_copyhome_btncopyback_main_main_default, 255);
	lv_style_set_text_color(&style_copyhome_btncopyback_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_copyhome_btncopyback_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_align(&style_copyhome_btncopyback_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->copyhome_btncopyback, &style_copyhome_btncopyback_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->copyhome_btncopyback_label = lv_label_create(ui->copyhome_btncopyback);
	lv_label_set_text(ui->copyhome_btncopyback_label, "<");
	lv_obj_set_style_pad_all(ui->copyhome_btncopyback, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->copyhome_btncopyback_label, LV_ALIGN_CENTER, 0, 0);
}