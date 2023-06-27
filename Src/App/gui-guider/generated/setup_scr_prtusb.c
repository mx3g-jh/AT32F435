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


void setup_scr_prtusb(lv_ui *ui){

	//Write codes prtusb
	ui->prtusb = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->prtusb, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_main_main_default
	static lv_style_t style_prtusb_main_main_default;
	if (style_prtusb_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_main_main_default);
	else
		lv_style_init(&style_prtusb_main_main_default);
	lv_style_set_bg_color(&style_prtusb_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_prtusb_main_main_default, 0);
	lv_obj_add_style(ui->prtusb, &style_prtusb_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtusb_cont0
	ui->prtusb_cont0 = lv_obj_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_cont0, 0, 0);
	lv_obj_set_size(ui->prtusb_cont0, 480, 117);
	lv_obj_set_scrollbar_mode(ui->prtusb_cont0, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_cont0_main_main_default
	static lv_style_t style_prtusb_cont0_main_main_default;
	if (style_prtusb_cont0_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_cont0_main_main_default);
	else
		lv_style_init(&style_prtusb_cont0_main_main_default);
	lv_style_set_radius(&style_prtusb_cont0_main_main_default, 0);
	lv_style_set_bg_color(&style_prtusb_cont0_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_prtusb_cont0_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_prtusb_cont0_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_cont0_main_main_default, 255);
	lv_style_set_shadow_width(&style_prtusb_cont0_main_main_default, 0);
	lv_style_set_shadow_color(&style_prtusb_cont0_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prtusb_cont0_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prtusb_cont0_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prtusb_cont0_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prtusb_cont0_main_main_default, 0);
	lv_style_set_border_color(&style_prtusb_cont0_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_prtusb_cont0_main_main_default, 0);
	lv_style_set_border_opa(&style_prtusb_cont0_main_main_default, 255);
	lv_style_set_pad_left(&style_prtusb_cont0_main_main_default, 0);
	lv_style_set_pad_right(&style_prtusb_cont0_main_main_default, 0);
	lv_style_set_pad_top(&style_prtusb_cont0_main_main_default, 0);
	lv_style_set_pad_bottom(&style_prtusb_cont0_main_main_default, 0);
	lv_obj_add_style(ui->prtusb_cont0, &style_prtusb_cont0_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtusb_cont2
	ui->prtusb_cont2 = lv_obj_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_cont2, 0, 117);
	lv_obj_set_size(ui->prtusb_cont2, 480, 202);
	lv_obj_set_scrollbar_mode(ui->prtusb_cont2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_cont2_main_main_default
	static lv_style_t style_prtusb_cont2_main_main_default;
	if (style_prtusb_cont2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_cont2_main_main_default);
	else
		lv_style_init(&style_prtusb_cont2_main_main_default);
	lv_style_set_radius(&style_prtusb_cont2_main_main_default, 0);
	lv_style_set_bg_color(&style_prtusb_cont2_main_main_default, lv_color_make(0xde, 0xde, 0xde));
	lv_style_set_bg_grad_color(&style_prtusb_cont2_main_main_default, lv_color_make(0xde, 0xde, 0xde));
	lv_style_set_bg_grad_dir(&style_prtusb_cont2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_cont2_main_main_default, 255);
	lv_style_set_shadow_width(&style_prtusb_cont2_main_main_default, 0);
	lv_style_set_shadow_color(&style_prtusb_cont2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prtusb_cont2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prtusb_cont2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prtusb_cont2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prtusb_cont2_main_main_default, 0);
	lv_style_set_border_color(&style_prtusb_cont2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_prtusb_cont2_main_main_default, 0);
	lv_style_set_border_opa(&style_prtusb_cont2_main_main_default, 255);
	lv_style_set_pad_left(&style_prtusb_cont2_main_main_default, 0);
	lv_style_set_pad_right(&style_prtusb_cont2_main_main_default, 0);
	lv_style_set_pad_top(&style_prtusb_cont2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_prtusb_cont2_main_main_default, 0);
	lv_obj_add_style(ui->prtusb_cont2, &style_prtusb_cont2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtusb_labeltitle
	ui->prtusb_labeltitle = lv_label_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_labeltitle, 136, 35);
	lv_obj_set_size(ui->prtusb_labeltitle, 225, 35);
	lv_obj_set_scrollbar_mode(ui->prtusb_labeltitle, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->prtusb_labeltitle, "PRINTING FROM USB");
	lv_label_set_long_mode(ui->prtusb_labeltitle, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_labeltitle_main_main_default
	static lv_style_t style_prtusb_labeltitle_main_main_default;
	if (style_prtusb_labeltitle_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_labeltitle_main_main_default);
	else
		lv_style_init(&style_prtusb_labeltitle_main_main_default);
	lv_style_set_radius(&style_prtusb_labeltitle_main_main_default, 0);
	lv_style_set_bg_color(&style_prtusb_labeltitle_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_prtusb_labeltitle_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_prtusb_labeltitle_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_labeltitle_main_main_default, 0);
	lv_style_set_shadow_width(&style_prtusb_labeltitle_main_main_default, 0);
	lv_style_set_shadow_color(&style_prtusb_labeltitle_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prtusb_labeltitle_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prtusb_labeltitle_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prtusb_labeltitle_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prtusb_labeltitle_main_main_default, 0);
	lv_style_set_text_color(&style_prtusb_labeltitle_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prtusb_labeltitle_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_prtusb_labeltitle_main_main_default, 2);
	lv_style_set_text_line_space(&style_prtusb_labeltitle_main_main_default, 0);
	lv_style_set_text_align(&style_prtusb_labeltitle_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_prtusb_labeltitle_main_main_default, 0);
	lv_style_set_pad_right(&style_prtusb_labeltitle_main_main_default, 0);
	lv_style_set_pad_top(&style_prtusb_labeltitle_main_main_default, 0);
	lv_style_set_pad_bottom(&style_prtusb_labeltitle_main_main_default, 0);
	lv_obj_add_style(ui->prtusb_labeltitle, &style_prtusb_labeltitle_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtusb_cont4
	ui->prtusb_cont4 = lv_obj_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_cont4, 305, 94);
	lv_obj_set_size(ui->prtusb_cont4, 150, 152);
	lv_obj_set_scrollbar_mode(ui->prtusb_cont4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_cont4_main_main_default
	static lv_style_t style_prtusb_cont4_main_main_default;
	if (style_prtusb_cont4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_cont4_main_main_default);
	else
		lv_style_init(&style_prtusb_cont4_main_main_default);
	lv_style_set_radius(&style_prtusb_cont4_main_main_default, 0);
	lv_style_set_bg_color(&style_prtusb_cont4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_prtusb_cont4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_prtusb_cont4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_cont4_main_main_default, 255);
	lv_style_set_shadow_width(&style_prtusb_cont4_main_main_default, 0);
	lv_style_set_shadow_color(&style_prtusb_cont4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prtusb_cont4_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prtusb_cont4_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prtusb_cont4_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prtusb_cont4_main_main_default, 0);
	lv_style_set_border_color(&style_prtusb_cont4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_prtusb_cont4_main_main_default, 0);
	lv_style_set_border_opa(&style_prtusb_cont4_main_main_default, 255);
	lv_style_set_pad_left(&style_prtusb_cont4_main_main_default, 0);
	lv_style_set_pad_right(&style_prtusb_cont4_main_main_default, 0);
	lv_style_set_pad_top(&style_prtusb_cont4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_prtusb_cont4_main_main_default, 0);
	lv_obj_add_style(ui->prtusb_cont4, &style_prtusb_cont4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtusb_btnprint
	ui->prtusb_btnprint = lv_btn_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_btnprint, 320, 262);
	lv_obj_set_size(ui->prtusb_btnprint, 118, 47);
	lv_obj_set_scrollbar_mode(ui->prtusb_btnprint, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_btnprint_main_main_default
	static lv_style_t style_prtusb_btnprint_main_main_default;
	if (style_prtusb_btnprint_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_btnprint_main_main_default);
	else
		lv_style_init(&style_prtusb_btnprint_main_main_default);
	lv_style_set_radius(&style_prtusb_btnprint_main_main_default, 50);
	lv_style_set_bg_color(&style_prtusb_btnprint_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_prtusb_btnprint_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_prtusb_btnprint_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_btnprint_main_main_default, 255);
	lv_style_set_shadow_width(&style_prtusb_btnprint_main_main_default, 0);
	lv_style_set_shadow_color(&style_prtusb_btnprint_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prtusb_btnprint_main_main_default, 0);
	lv_style_set_shadow_spread(&style_prtusb_btnprint_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prtusb_btnprint_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prtusb_btnprint_main_main_default, 0);
	lv_style_set_border_color(&style_prtusb_btnprint_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_prtusb_btnprint_main_main_default, 0);
	lv_style_set_border_opa(&style_prtusb_btnprint_main_main_default, 255);
	lv_style_set_text_color(&style_prtusb_btnprint_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_prtusb_btnprint_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_align(&style_prtusb_btnprint_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->prtusb_btnprint, &style_prtusb_btnprint_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->prtusb_btnprint_label = lv_label_create(ui->prtusb_btnprint);
	lv_label_set_text(ui->prtusb_btnprint_label, "PRINT");
	lv_obj_set_style_pad_all(ui->prtusb_btnprint, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->prtusb_btnprint_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes prtusb_back
	ui->prtusb_back = lv_btn_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_back, 50, 29);
	lv_obj_set_size(ui->prtusb_back, 30, 35);
	lv_obj_set_scrollbar_mode(ui->prtusb_back, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_back_main_main_default
	static lv_style_t style_prtusb_back_main_main_default;
	if (style_prtusb_back_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_back_main_main_default);
	else
		lv_style_init(&style_prtusb_back_main_main_default);
	lv_style_set_radius(&style_prtusb_back_main_main_default, 50);
	lv_style_set_bg_color(&style_prtusb_back_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_prtusb_back_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_prtusb_back_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_back_main_main_default, 255);
	lv_style_set_shadow_width(&style_prtusb_back_main_main_default, 0);
	lv_style_set_shadow_color(&style_prtusb_back_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prtusb_back_main_main_default, 0);
	lv_style_set_shadow_spread(&style_prtusb_back_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prtusb_back_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prtusb_back_main_main_default, 0);
	lv_style_set_border_color(&style_prtusb_back_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_prtusb_back_main_main_default, 0);
	lv_style_set_border_opa(&style_prtusb_back_main_main_default, 255);
	lv_style_set_text_color(&style_prtusb_back_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_prtusb_back_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_align(&style_prtusb_back_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->prtusb_back, &style_prtusb_back_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->prtusb_back_label = lv_label_create(ui->prtusb_back);
	lv_label_set_text(ui->prtusb_back_label, "<");
	lv_obj_set_style_pad_all(ui->prtusb_back, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->prtusb_back_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes prtusb_swcolor
	ui->prtusb_swcolor = lv_switch_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_swcolor, 323, 205);
	lv_obj_set_size(ui->prtusb_swcolor, 40, 23);
	lv_obj_set_scrollbar_mode(ui->prtusb_swcolor, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_swcolor_main_main_default
	static lv_style_t style_prtusb_swcolor_main_main_default;
	if (style_prtusb_swcolor_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_swcolor_main_main_default);
	else
		lv_style_init(&style_prtusb_swcolor_main_main_default);
	lv_style_set_radius(&style_prtusb_swcolor_main_main_default, 100);
	lv_style_set_bg_color(&style_prtusb_swcolor_main_main_default, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_color(&style_prtusb_swcolor_main_main_default, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_dir(&style_prtusb_swcolor_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_swcolor_main_main_default, 255);
	lv_style_set_shadow_width(&style_prtusb_swcolor_main_main_default, 0);
	lv_style_set_shadow_color(&style_prtusb_swcolor_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prtusb_swcolor_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prtusb_swcolor_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prtusb_swcolor_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prtusb_swcolor_main_main_default, 0);
	lv_style_set_border_color(&style_prtusb_swcolor_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_prtusb_swcolor_main_main_default, 0);
	lv_style_set_border_opa(&style_prtusb_swcolor_main_main_default, 255);
	lv_obj_add_style(ui->prtusb_swcolor, &style_prtusb_swcolor_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_prtusb_swcolor_main_indicator_checked
	static lv_style_t style_prtusb_swcolor_main_indicator_checked;
	if (style_prtusb_swcolor_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_prtusb_swcolor_main_indicator_checked);
	else
		lv_style_init(&style_prtusb_swcolor_main_indicator_checked);
	lv_style_set_bg_color(&style_prtusb_swcolor_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_prtusb_swcolor_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_prtusb_swcolor_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_swcolor_main_indicator_checked, 255);
	lv_style_set_border_color(&style_prtusb_swcolor_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_prtusb_swcolor_main_indicator_checked, 0);
	lv_style_set_border_opa(&style_prtusb_swcolor_main_indicator_checked, 255);
	lv_obj_add_style(ui->prtusb_swcolor, &style_prtusb_swcolor_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_swcolor_main_knob_default
	static lv_style_t style_prtusb_swcolor_main_knob_default;
	if (style_prtusb_swcolor_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_swcolor_main_knob_default);
	else
		lv_style_init(&style_prtusb_swcolor_main_knob_default);
	lv_style_set_radius(&style_prtusb_swcolor_main_knob_default, 100);
	lv_style_set_bg_color(&style_prtusb_swcolor_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_prtusb_swcolor_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_prtusb_swcolor_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_swcolor_main_knob_default, 255);
	lv_style_set_border_color(&style_prtusb_swcolor_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_prtusb_swcolor_main_knob_default, 0);
	lv_style_set_border_opa(&style_prtusb_swcolor_main_knob_default, 255);
	lv_obj_add_style(ui->prtusb_swcolor, &style_prtusb_swcolor_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes prtusb_labelcopy
	ui->prtusb_labelcopy = lv_label_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_labelcopy, 345, 102);
	lv_obj_set_size(ui->prtusb_labelcopy, 64, 23);
	lv_obj_set_scrollbar_mode(ui->prtusb_labelcopy, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->prtusb_labelcopy, "Copies");
	lv_label_set_long_mode(ui->prtusb_labelcopy, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_labelcopy_main_main_default
	static lv_style_t style_prtusb_labelcopy_main_main_default;
	if (style_prtusb_labelcopy_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_labelcopy_main_main_default);
	else
		lv_style_init(&style_prtusb_labelcopy_main_main_default);
	lv_style_set_radius(&style_prtusb_labelcopy_main_main_default, 0);
	lv_style_set_bg_color(&style_prtusb_labelcopy_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_prtusb_labelcopy_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_prtusb_labelcopy_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_labelcopy_main_main_default, 0);
	lv_style_set_shadow_width(&style_prtusb_labelcopy_main_main_default, 0);
	lv_style_set_shadow_color(&style_prtusb_labelcopy_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prtusb_labelcopy_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prtusb_labelcopy_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prtusb_labelcopy_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prtusb_labelcopy_main_main_default, 0);
	lv_style_set_text_color(&style_prtusb_labelcopy_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_prtusb_labelcopy_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_prtusb_labelcopy_main_main_default, 2);
	lv_style_set_text_line_space(&style_prtusb_labelcopy_main_main_default, 0);
	lv_style_set_text_align(&style_prtusb_labelcopy_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_prtusb_labelcopy_main_main_default, 0);
	lv_style_set_pad_right(&style_prtusb_labelcopy_main_main_default, 0);
	lv_style_set_pad_top(&style_prtusb_labelcopy_main_main_default, 0);
	lv_style_set_pad_bottom(&style_prtusb_labelcopy_main_main_default, 0);
	lv_obj_add_style(ui->prtusb_labelcopy, &style_prtusb_labelcopy_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtusb_up
	ui->prtusb_up = lv_btn_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_up, 410, 129);
	lv_obj_set_size(ui->prtusb_up, 20, 23);
	lv_obj_set_scrollbar_mode(ui->prtusb_up, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_up_main_main_default
	static lv_style_t style_prtusb_up_main_main_default;
	if (style_prtusb_up_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_up_main_main_default);
	else
		lv_style_init(&style_prtusb_up_main_main_default);
	lv_style_set_radius(&style_prtusb_up_main_main_default, 4);
	lv_style_set_bg_color(&style_prtusb_up_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_prtusb_up_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_prtusb_up_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_up_main_main_default, 255);
	lv_style_set_shadow_width(&style_prtusb_up_main_main_default, 0);
	lv_style_set_shadow_color(&style_prtusb_up_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prtusb_up_main_main_default, 0);
	lv_style_set_shadow_spread(&style_prtusb_up_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prtusb_up_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prtusb_up_main_main_default, 0);
	lv_style_set_border_color(&style_prtusb_up_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_prtusb_up_main_main_default, 0);
	lv_style_set_border_opa(&style_prtusb_up_main_main_default, 255);
	lv_style_set_text_color(&style_prtusb_up_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prtusb_up_main_main_default, &lv_font_simsun_18);
	lv_style_set_text_align(&style_prtusb_up_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->prtusb_up, &style_prtusb_up_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->prtusb_up_label = lv_label_create(ui->prtusb_up);
	lv_label_set_text(ui->prtusb_up_label, "+");
	lv_obj_set_style_pad_all(ui->prtusb_up, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->prtusb_up_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes prtusb_down
	ui->prtusb_down = lv_btn_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_down, 322, 129);
	lv_obj_set_size(ui->prtusb_down, 20, 23);
	lv_obj_set_scrollbar_mode(ui->prtusb_down, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_down_main_main_default
	static lv_style_t style_prtusb_down_main_main_default;
	if (style_prtusb_down_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_down_main_main_default);
	else
		lv_style_init(&style_prtusb_down_main_main_default);
	lv_style_set_radius(&style_prtusb_down_main_main_default, 4);
	lv_style_set_bg_color(&style_prtusb_down_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_prtusb_down_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_prtusb_down_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_down_main_main_default, 255);
	lv_style_set_shadow_width(&style_prtusb_down_main_main_default, 0);
	lv_style_set_shadow_color(&style_prtusb_down_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prtusb_down_main_main_default, 0);
	lv_style_set_shadow_spread(&style_prtusb_down_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prtusb_down_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prtusb_down_main_main_default, 0);
	lv_style_set_border_color(&style_prtusb_down_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_prtusb_down_main_main_default, 0);
	lv_style_set_border_opa(&style_prtusb_down_main_main_default, 255);
	lv_style_set_text_color(&style_prtusb_down_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prtusb_down_main_main_default, &lv_font_simsun_18);
	lv_style_set_text_align(&style_prtusb_down_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->prtusb_down, &style_prtusb_down_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->prtusb_down_label = lv_label_create(ui->prtusb_down);
	lv_label_set_text(ui->prtusb_down_label, "-");
	lv_obj_set_style_pad_all(ui->prtusb_down, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->prtusb_down_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes prtusb_labelcnt
	ui->prtusb_labelcnt = lv_label_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_labelcnt, 332, 129);
	lv_obj_set_size(ui->prtusb_labelcnt, 90, 35);
	lv_obj_set_scrollbar_mode(ui->prtusb_labelcnt, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->prtusb_labelcnt, "1");
	lv_label_set_long_mode(ui->prtusb_labelcnt, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_labelcnt_main_main_default
	static lv_style_t style_prtusb_labelcnt_main_main_default;
	if (style_prtusb_labelcnt_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_labelcnt_main_main_default);
	else
		lv_style_init(&style_prtusb_labelcnt_main_main_default);
	lv_style_set_radius(&style_prtusb_labelcnt_main_main_default, 0);
	lv_style_set_bg_color(&style_prtusb_labelcnt_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_prtusb_labelcnt_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_prtusb_labelcnt_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_labelcnt_main_main_default, 0);
	lv_style_set_shadow_width(&style_prtusb_labelcnt_main_main_default, 0);
	lv_style_set_shadow_color(&style_prtusb_labelcnt_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prtusb_labelcnt_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prtusb_labelcnt_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prtusb_labelcnt_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prtusb_labelcnt_main_main_default, 0);
	lv_style_set_text_color(&style_prtusb_labelcnt_main_main_default, lv_color_make(0x14, 0x10, 0x10));
	lv_style_set_text_font(&style_prtusb_labelcnt_main_main_default, &lv_font_arial_21);
	lv_style_set_text_letter_space(&style_prtusb_labelcnt_main_main_default, 2);
	lv_style_set_text_line_space(&style_prtusb_labelcnt_main_main_default, 0);
	lv_style_set_text_align(&style_prtusb_labelcnt_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_prtusb_labelcnt_main_main_default, 0);
	lv_style_set_pad_right(&style_prtusb_labelcnt_main_main_default, 0);
	lv_style_set_pad_top(&style_prtusb_labelcnt_main_main_default, 0);
	lv_style_set_pad_bottom(&style_prtusb_labelcnt_main_main_default, 0);
	lv_obj_add_style(ui->prtusb_labelcnt, &style_prtusb_labelcnt_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtusb_labelcolor
	ui->prtusb_labelcolor = lv_label_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_labelcolor, 314, 171);
	lv_obj_set_size(ui->prtusb_labelcolor, 50, 23);
	lv_obj_set_scrollbar_mode(ui->prtusb_labelcolor, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->prtusb_labelcolor, "Color");
	lv_label_set_long_mode(ui->prtusb_labelcolor, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_labelcolor_main_main_default
	static lv_style_t style_prtusb_labelcolor_main_main_default;
	if (style_prtusb_labelcolor_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_labelcolor_main_main_default);
	else
		lv_style_init(&style_prtusb_labelcolor_main_main_default);
	lv_style_set_radius(&style_prtusb_labelcolor_main_main_default, 0);
	lv_style_set_bg_color(&style_prtusb_labelcolor_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_prtusb_labelcolor_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_prtusb_labelcolor_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_labelcolor_main_main_default, 0);
	lv_style_set_shadow_width(&style_prtusb_labelcolor_main_main_default, 0);
	lv_style_set_shadow_color(&style_prtusb_labelcolor_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prtusb_labelcolor_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prtusb_labelcolor_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prtusb_labelcolor_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prtusb_labelcolor_main_main_default, 0);
	lv_style_set_text_color(&style_prtusb_labelcolor_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_prtusb_labelcolor_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_prtusb_labelcolor_main_main_default, 2);
	lv_style_set_text_line_space(&style_prtusb_labelcolor_main_main_default, 0);
	lv_style_set_text_align(&style_prtusb_labelcolor_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_prtusb_labelcolor_main_main_default, 0);
	lv_style_set_pad_right(&style_prtusb_labelcolor_main_main_default, 0);
	lv_style_set_pad_top(&style_prtusb_labelcolor_main_main_default, 0);
	lv_style_set_pad_bottom(&style_prtusb_labelcolor_main_main_default, 0);
	lv_obj_add_style(ui->prtusb_labelcolor, &style_prtusb_labelcolor_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtusb_labelvert
	ui->prtusb_labelvert = lv_label_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_labelvert, 380, 171);
	lv_obj_set_size(ui->prtusb_labelvert, 70, 23);
	lv_obj_set_scrollbar_mode(ui->prtusb_labelvert, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->prtusb_labelvert, "Vertical");
	lv_label_set_long_mode(ui->prtusb_labelvert, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_labelvert_main_main_default
	static lv_style_t style_prtusb_labelvert_main_main_default;
	if (style_prtusb_labelvert_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_labelvert_main_main_default);
	else
		lv_style_init(&style_prtusb_labelvert_main_main_default);
	lv_style_set_radius(&style_prtusb_labelvert_main_main_default, 0);
	lv_style_set_bg_color(&style_prtusb_labelvert_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_prtusb_labelvert_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_prtusb_labelvert_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_labelvert_main_main_default, 0);
	lv_style_set_shadow_width(&style_prtusb_labelvert_main_main_default, 0);
	lv_style_set_shadow_color(&style_prtusb_labelvert_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prtusb_labelvert_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prtusb_labelvert_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prtusb_labelvert_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prtusb_labelvert_main_main_default, 0);
	lv_style_set_text_color(&style_prtusb_labelvert_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_prtusb_labelvert_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_prtusb_labelvert_main_main_default, 2);
	lv_style_set_text_line_space(&style_prtusb_labelvert_main_main_default, 0);
	lv_style_set_text_align(&style_prtusb_labelvert_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_prtusb_labelvert_main_main_default, 0);
	lv_style_set_pad_right(&style_prtusb_labelvert_main_main_default, 0);
	lv_style_set_pad_top(&style_prtusb_labelvert_main_main_default, 0);
	lv_style_set_pad_bottom(&style_prtusb_labelvert_main_main_default, 0);
	lv_obj_add_style(ui->prtusb_labelvert, &style_prtusb_labelvert_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtusb_swvert
	ui->prtusb_swvert = lv_switch_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_swvert, 390, 205);
	lv_obj_set_size(ui->prtusb_swvert, 40, 23);
	lv_obj_set_scrollbar_mode(ui->prtusb_swvert, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_swvert_main_main_default
	static lv_style_t style_prtusb_swvert_main_main_default;
	if (style_prtusb_swvert_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_swvert_main_main_default);
	else
		lv_style_init(&style_prtusb_swvert_main_main_default);
	lv_style_set_radius(&style_prtusb_swvert_main_main_default, 100);
	lv_style_set_bg_color(&style_prtusb_swvert_main_main_default, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_color(&style_prtusb_swvert_main_main_default, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_dir(&style_prtusb_swvert_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_swvert_main_main_default, 255);
	lv_style_set_shadow_width(&style_prtusb_swvert_main_main_default, 0);
	lv_style_set_shadow_color(&style_prtusb_swvert_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prtusb_swvert_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prtusb_swvert_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prtusb_swvert_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prtusb_swvert_main_main_default, 0);
	lv_style_set_border_color(&style_prtusb_swvert_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_prtusb_swvert_main_main_default, 0);
	lv_style_set_border_opa(&style_prtusb_swvert_main_main_default, 255);
	lv_obj_add_style(ui->prtusb_swvert, &style_prtusb_swvert_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_prtusb_swvert_main_indicator_checked
	static lv_style_t style_prtusb_swvert_main_indicator_checked;
	if (style_prtusb_swvert_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_prtusb_swvert_main_indicator_checked);
	else
		lv_style_init(&style_prtusb_swvert_main_indicator_checked);
	lv_style_set_bg_color(&style_prtusb_swvert_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_prtusb_swvert_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_prtusb_swvert_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_swvert_main_indicator_checked, 255);
	lv_style_set_border_color(&style_prtusb_swvert_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_prtusb_swvert_main_indicator_checked, 0);
	lv_style_set_border_opa(&style_prtusb_swvert_main_indicator_checked, 255);
	lv_obj_add_style(ui->prtusb_swvert, &style_prtusb_swvert_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_swvert_main_knob_default
	static lv_style_t style_prtusb_swvert_main_knob_default;
	if (style_prtusb_swvert_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_swvert_main_knob_default);
	else
		lv_style_init(&style_prtusb_swvert_main_knob_default);
	lv_style_set_radius(&style_prtusb_swvert_main_knob_default, 100);
	lv_style_set_bg_color(&style_prtusb_swvert_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_prtusb_swvert_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_prtusb_swvert_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_swvert_main_knob_default, 255);
	lv_style_set_border_color(&style_prtusb_swvert_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_prtusb_swvert_main_knob_default, 0);
	lv_style_set_border_opa(&style_prtusb_swvert_main_knob_default, 255);
	lv_obj_add_style(ui->prtusb_swvert, &style_prtusb_swvert_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes prtusb_list16
	ui->prtusb_list16 = lv_list_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_list16, 31, 97);
	lv_obj_set_size(ui->prtusb_list16, 240, 145);
	lv_obj_set_scrollbar_mode(ui->prtusb_list16, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_list16_main_main_default
	static lv_style_t style_prtusb_list16_main_main_default;
	if (style_prtusb_list16_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_list16_main_main_default);
	else
		lv_style_init(&style_prtusb_list16_main_main_default);
	lv_style_set_radius(&style_prtusb_list16_main_main_default, 3);
	lv_style_set_bg_color(&style_prtusb_list16_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_prtusb_list16_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_prtusb_list16_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_list16_main_main_default, 255);
	lv_style_set_shadow_width(&style_prtusb_list16_main_main_default, 0);
	lv_style_set_shadow_color(&style_prtusb_list16_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prtusb_list16_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prtusb_list16_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prtusb_list16_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prtusb_list16_main_main_default, 0);
	lv_style_set_border_color(&style_prtusb_list16_main_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_prtusb_list16_main_main_default, 1);
	lv_style_set_border_opa(&style_prtusb_list16_main_main_default, 255);
	lv_style_set_pad_left(&style_prtusb_list16_main_main_default, 5);
	lv_style_set_pad_right(&style_prtusb_list16_main_main_default, 5);
	lv_style_set_pad_top(&style_prtusb_list16_main_main_default, 5);
	lv_style_set_pad_bottom(&style_prtusb_list16_main_main_default, 5);
	lv_obj_add_style(ui->prtusb_list16, &style_prtusb_list16_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_list16_main_scrollbar_default
	static lv_style_t style_prtusb_list16_main_scrollbar_default;
	if (style_prtusb_list16_main_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_list16_main_scrollbar_default);
	else
		lv_style_init(&style_prtusb_list16_main_scrollbar_default);
	lv_style_set_radius(&style_prtusb_list16_main_scrollbar_default, 3);
	lv_style_set_bg_color(&style_prtusb_list16_main_scrollbar_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_prtusb_list16_main_scrollbar_default, 255);
	lv_obj_add_style(ui->prtusb_list16, &style_prtusb_list16_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_list16_extra_btns_main_default
	static lv_style_t style_prtusb_list16_extra_btns_main_default;
	if (style_prtusb_list16_extra_btns_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_list16_extra_btns_main_default);
	else
		lv_style_init(&style_prtusb_list16_extra_btns_main_default);
	lv_style_set_radius(&style_prtusb_list16_extra_btns_main_default, 3);
	lv_style_set_bg_color(&style_prtusb_list16_extra_btns_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_prtusb_list16_extra_btns_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_prtusb_list16_extra_btns_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_list16_extra_btns_main_default, 255);
	lv_style_set_text_color(&style_prtusb_list16_extra_btns_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_prtusb_list16_extra_btns_main_default, &lv_font_arial_12);

	lv_obj_t *prtusb_list16_item;
	prtusb_list16_item = lv_list_add_btn(ui->prtusb_list16, NULL, "Contract 12.pdf");
	ui->prtusb_list16_item0 = prtusb_list16_item;
	lv_obj_add_style(prtusb_list16_item, &style_prtusb_list16_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	prtusb_list16_item = lv_list_add_btn(ui->prtusb_list16, NULL, "Scanned_05_21.pdf");
	ui->prtusb_list16_item1 = prtusb_list16_item;
	lv_obj_add_style(prtusb_list16_item, &style_prtusb_list16_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	prtusb_list16_item = lv_list_add_btn(ui->prtusb_list16, NULL, "Photo_2.jpg");
	ui->prtusb_list16_item2 = prtusb_list16_item;
	lv_obj_add_style(prtusb_list16_item, &style_prtusb_list16_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	prtusb_list16_item = lv_list_add_btn(ui->prtusb_list16, NULL, "Photo_3.jpg");
	ui->prtusb_list16_item3 = prtusb_list16_item;
	lv_obj_add_style(prtusb_list16_item, &style_prtusb_list16_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);


	//Write codes prtusb_ddlist1
	ui->prtusb_ddlist1 = lv_dropdown_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_ddlist1, 28, 258);
	lv_obj_set_size(ui->prtusb_ddlist1, 100, 24);
	lv_obj_set_scrollbar_mode(ui->prtusb_ddlist1, LV_SCROLLBAR_MODE_OFF);
	lv_dropdown_set_options(ui->prtusb_ddlist1, "Best\nNormal\nDraft");

	//Write style state: LV_STATE_DEFAULT for style_prtusb_ddlist1_main_main_default
	static lv_style_t style_prtusb_ddlist1_main_main_default;
	if (style_prtusb_ddlist1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_ddlist1_main_main_default);
	else
		lv_style_init(&style_prtusb_ddlist1_main_main_default);
	lv_style_set_radius(&style_prtusb_ddlist1_main_main_default, 3);
	lv_style_set_bg_color(&style_prtusb_ddlist1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_prtusb_ddlist1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_prtusb_ddlist1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_ddlist1_main_main_default, 255);
	lv_style_set_shadow_width(&style_prtusb_ddlist1_main_main_default, 0);
	lv_style_set_shadow_color(&style_prtusb_ddlist1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prtusb_ddlist1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prtusb_ddlist1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prtusb_ddlist1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prtusb_ddlist1_main_main_default, 0);
	lv_style_set_border_color(&style_prtusb_ddlist1_main_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_prtusb_ddlist1_main_main_default, 1);
	lv_style_set_border_opa(&style_prtusb_ddlist1_main_main_default, 255);
	lv_style_set_text_color(&style_prtusb_ddlist1_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_prtusb_ddlist1_main_main_default, &lv_font_arial_12);
	lv_style_set_pad_left(&style_prtusb_ddlist1_main_main_default, 6);
	lv_style_set_pad_right(&style_prtusb_ddlist1_main_main_default, 6);
	lv_style_set_pad_top(&style_prtusb_ddlist1_main_main_default, 4);
	lv_obj_add_style(ui->prtusb_ddlist1, &style_prtusb_ddlist1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_prtusb_ddlist1_extra_list_selected_checked
	static lv_style_t style_prtusb_ddlist1_extra_list_selected_checked;
	if (style_prtusb_ddlist1_extra_list_selected_checked.prop_cnt > 1)
		lv_style_reset(&style_prtusb_ddlist1_extra_list_selected_checked);
	else
		lv_style_init(&style_prtusb_ddlist1_extra_list_selected_checked);
	lv_style_set_radius(&style_prtusb_ddlist1_extra_list_selected_checked, 3);
	lv_style_set_bg_color(&style_prtusb_ddlist1_extra_list_selected_checked, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_color(&style_prtusb_ddlist1_extra_list_selected_checked, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_dir(&style_prtusb_ddlist1_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_prtusb_ddlist1_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_prtusb_ddlist1_extra_list_selected_checked, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_prtusb_ddlist1_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_prtusb_ddlist1_extra_list_selected_checked, 255);
	lv_style_set_text_color(&style_prtusb_ddlist1_extra_list_selected_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prtusb_ddlist1_extra_list_selected_checked, &lv_font_montserratMedium_12);
	lv_obj_add_style(lv_dropdown_get_list(ui->prtusb_ddlist1), &style_prtusb_ddlist1_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_ddlist1_extra_list_main_default
	static lv_style_t style_prtusb_ddlist1_extra_list_main_default;
	if (style_prtusb_ddlist1_extra_list_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_ddlist1_extra_list_main_default);
	else
		lv_style_init(&style_prtusb_ddlist1_extra_list_main_default);
	lv_style_set_radius(&style_prtusb_ddlist1_extra_list_main_default, 3);
	lv_style_set_bg_color(&style_prtusb_ddlist1_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_prtusb_ddlist1_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_prtusb_ddlist1_extra_list_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_ddlist1_extra_list_main_default, 255);
	lv_style_set_border_color(&style_prtusb_ddlist1_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_prtusb_ddlist1_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_prtusb_ddlist1_extra_list_main_default, 255);
	lv_style_set_text_color(&style_prtusb_ddlist1_extra_list_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_prtusb_ddlist1_extra_list_main_default, &lv_font_arial_12);
	lv_style_set_max_height(&style_prtusb_ddlist1_extra_list_main_default, 90);
	lv_obj_add_style(lv_dropdown_get_list(ui->prtusb_ddlist1), &style_prtusb_ddlist1_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_ddlist1_extra_list_scrollbar_default
	static lv_style_t style_prtusb_ddlist1_extra_list_scrollbar_default;
	if (style_prtusb_ddlist1_extra_list_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_ddlist1_extra_list_scrollbar_default);
	else
		lv_style_init(&style_prtusb_ddlist1_extra_list_scrollbar_default);
	lv_style_set_radius(&style_prtusb_ddlist1_extra_list_scrollbar_default, 3);
	lv_style_set_bg_color(&style_prtusb_ddlist1_extra_list_scrollbar_default, lv_color_make(0x00, 0xff, 0x00));
	lv_style_set_bg_opa(&style_prtusb_ddlist1_extra_list_scrollbar_default, 255);
	lv_obj_add_style(lv_dropdown_get_list(ui->prtusb_ddlist1), &style_prtusb_ddlist1_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes prtusb_ddlist2
	ui->prtusb_ddlist2 = lv_dropdown_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_ddlist2, 166, 258);
	lv_obj_set_size(ui->prtusb_ddlist2, 100, 27);
	lv_obj_set_scrollbar_mode(ui->prtusb_ddlist2, LV_SCROLLBAR_MODE_OFF);
	lv_dropdown_set_options(ui->prtusb_ddlist2, "72 DPI\n96 DPI\n150 DPI\n300 DPI\n600 DPI\n900 DPI\n1200 DPI");

	//Write style state: LV_STATE_DEFAULT for style_prtusb_ddlist2_main_main_default
	static lv_style_t style_prtusb_ddlist2_main_main_default;
	if (style_prtusb_ddlist2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_ddlist2_main_main_default);
	else
		lv_style_init(&style_prtusb_ddlist2_main_main_default);
	lv_style_set_radius(&style_prtusb_ddlist2_main_main_default, 3);
	lv_style_set_bg_color(&style_prtusb_ddlist2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_prtusb_ddlist2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_prtusb_ddlist2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_ddlist2_main_main_default, 255);
	lv_style_set_shadow_width(&style_prtusb_ddlist2_main_main_default, 0);
	lv_style_set_shadow_color(&style_prtusb_ddlist2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prtusb_ddlist2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prtusb_ddlist2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prtusb_ddlist2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prtusb_ddlist2_main_main_default, 0);
	lv_style_set_border_color(&style_prtusb_ddlist2_main_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_prtusb_ddlist2_main_main_default, 1);
	lv_style_set_border_opa(&style_prtusb_ddlist2_main_main_default, 255);
	lv_style_set_text_color(&style_prtusb_ddlist2_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_prtusb_ddlist2_main_main_default, &lv_font_arial_12);
	lv_style_set_pad_left(&style_prtusb_ddlist2_main_main_default, 6);
	lv_style_set_pad_right(&style_prtusb_ddlist2_main_main_default, 6);
	lv_style_set_pad_top(&style_prtusb_ddlist2_main_main_default, 4);
	lv_obj_add_style(ui->prtusb_ddlist2, &style_prtusb_ddlist2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_prtusb_ddlist2_extra_list_selected_checked
	static lv_style_t style_prtusb_ddlist2_extra_list_selected_checked;
	if (style_prtusb_ddlist2_extra_list_selected_checked.prop_cnt > 1)
		lv_style_reset(&style_prtusb_ddlist2_extra_list_selected_checked);
	else
		lv_style_init(&style_prtusb_ddlist2_extra_list_selected_checked);
	lv_style_set_radius(&style_prtusb_ddlist2_extra_list_selected_checked, 3);
	lv_style_set_bg_color(&style_prtusb_ddlist2_extra_list_selected_checked, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_color(&style_prtusb_ddlist2_extra_list_selected_checked, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_dir(&style_prtusb_ddlist2_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_prtusb_ddlist2_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_prtusb_ddlist2_extra_list_selected_checked, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_prtusb_ddlist2_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_prtusb_ddlist2_extra_list_selected_checked, 255);
	lv_style_set_text_color(&style_prtusb_ddlist2_extra_list_selected_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prtusb_ddlist2_extra_list_selected_checked, &lv_font_montserratMedium_12);
	lv_obj_add_style(lv_dropdown_get_list(ui->prtusb_ddlist2), &style_prtusb_ddlist2_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_ddlist2_extra_list_main_default
	static lv_style_t style_prtusb_ddlist2_extra_list_main_default;
	if (style_prtusb_ddlist2_extra_list_main_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_ddlist2_extra_list_main_default);
	else
		lv_style_init(&style_prtusb_ddlist2_extra_list_main_default);
	lv_style_set_radius(&style_prtusb_ddlist2_extra_list_main_default, 3);
	lv_style_set_bg_color(&style_prtusb_ddlist2_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_prtusb_ddlist2_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_prtusb_ddlist2_extra_list_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_ddlist2_extra_list_main_default, 255);
	lv_style_set_border_color(&style_prtusb_ddlist2_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_prtusb_ddlist2_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_prtusb_ddlist2_extra_list_main_default, 255);
	lv_style_set_text_color(&style_prtusb_ddlist2_extra_list_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_prtusb_ddlist2_extra_list_main_default, &lv_font_arial_12);
	lv_style_set_max_height(&style_prtusb_ddlist2_extra_list_main_default, 90);
	lv_obj_add_style(lv_dropdown_get_list(ui->prtusb_ddlist2), &style_prtusb_ddlist2_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_prtusb_ddlist2_extra_list_scrollbar_default
	static lv_style_t style_prtusb_ddlist2_extra_list_scrollbar_default;
	if (style_prtusb_ddlist2_extra_list_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_prtusb_ddlist2_extra_list_scrollbar_default);
	else
		lv_style_init(&style_prtusb_ddlist2_extra_list_scrollbar_default);
	lv_style_set_radius(&style_prtusb_ddlist2_extra_list_scrollbar_default, 3);
	lv_style_set_bg_color(&style_prtusb_ddlist2_extra_list_scrollbar_default, lv_color_make(0x00, 0xff, 0x00));
	lv_style_set_bg_opa(&style_prtusb_ddlist2_extra_list_scrollbar_default, 255);
	lv_obj_add_style(lv_dropdown_get_list(ui->prtusb_ddlist2), &style_prtusb_ddlist2_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
}