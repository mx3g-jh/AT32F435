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


void setup_scr_loader(lv_ui *ui){

	//Write codes loader
	ui->loader = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->loader, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_loader_main_main_default
	static lv_style_t style_loader_main_main_default;
	if (style_loader_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_loader_main_main_default);
	else
		lv_style_init(&style_loader_main_main_default);
	lv_style_set_bg_color(&style_loader_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_loader_main_main_default, 0);
	lv_obj_add_style(ui->loader, &style_loader_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes loader_cont0
	ui->loader_cont0 = lv_obj_create(ui->loader);
	lv_obj_set_pos(ui->loader_cont0, 0, 0);
	lv_obj_set_size(ui->loader_cont0, 480, 320);
	lv_obj_set_scrollbar_mode(ui->loader_cont0, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_loader_cont0_main_main_default
	static lv_style_t style_loader_cont0_main_main_default;
	if (style_loader_cont0_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_loader_cont0_main_main_default);
	else
		lv_style_init(&style_loader_cont0_main_main_default);
	lv_style_set_radius(&style_loader_cont0_main_main_default, 0);
	lv_style_set_bg_color(&style_loader_cont0_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_loader_cont0_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_loader_cont0_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_loader_cont0_main_main_default, 255);
	lv_style_set_shadow_width(&style_loader_cont0_main_main_default, 0);
	lv_style_set_shadow_color(&style_loader_cont0_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_loader_cont0_main_main_default, 255);
	lv_style_set_shadow_spread(&style_loader_cont0_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_loader_cont0_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_loader_cont0_main_main_default, 0);
	lv_style_set_border_color(&style_loader_cont0_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_loader_cont0_main_main_default, 0);
	lv_style_set_border_opa(&style_loader_cont0_main_main_default, 255);
	lv_style_set_pad_left(&style_loader_cont0_main_main_default, 0);
	lv_style_set_pad_right(&style_loader_cont0_main_main_default, 0);
	lv_style_set_pad_top(&style_loader_cont0_main_main_default, 0);
	lv_style_set_pad_bottom(&style_loader_cont0_main_main_default, 0);
	lv_obj_add_style(ui->loader_cont0, &style_loader_cont0_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes loader_loadarc
	ui->loader_loadarc = lv_arc_create(ui->loader);
	lv_obj_set_pos(ui->loader_loadarc, 180, 94);
	lv_obj_set_size(ui->loader_loadarc, 110, 129);
	lv_obj_set_scrollbar_mode(ui->loader_loadarc, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_loader_loadarc_main_main_default
	static lv_style_t style_loader_loadarc_main_main_default;
	if (style_loader_loadarc_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_loader_loadarc_main_main_default);
	else
		lv_style_init(&style_loader_loadarc_main_main_default);
	lv_style_set_radius(&style_loader_loadarc_main_main_default, 6);
	lv_style_set_bg_color(&style_loader_loadarc_main_main_default, lv_color_make(0x00, 0x23, 0x46));
	lv_style_set_bg_grad_color(&style_loader_loadarc_main_main_default, lv_color_make(0x00, 0x23, 0x46));
	lv_style_set_bg_grad_dir(&style_loader_loadarc_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_loader_loadarc_main_main_default, 0);
	lv_style_set_shadow_width(&style_loader_loadarc_main_main_default, 0);
	lv_style_set_shadow_color(&style_loader_loadarc_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_loader_loadarc_main_main_default, 255);
	lv_style_set_shadow_spread(&style_loader_loadarc_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_loader_loadarc_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_loader_loadarc_main_main_default, 0);
	lv_style_set_border_width(&style_loader_loadarc_main_main_default, 0);
	lv_style_set_pad_left(&style_loader_loadarc_main_main_default, 20);
	lv_style_set_pad_right(&style_loader_loadarc_main_main_default, 20);
	lv_style_set_pad_top(&style_loader_loadarc_main_main_default, 20);
	lv_style_set_pad_bottom(&style_loader_loadarc_main_main_default, 20);
	lv_style_set_arc_color(&style_loader_loadarc_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_arc_width(&style_loader_loadarc_main_main_default, 12);
	lv_obj_add_style(ui->loader_loadarc, &style_loader_loadarc_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_loader_loadarc_main_indicator_default
	static lv_style_t style_loader_loadarc_main_indicator_default;
	if (style_loader_loadarc_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_loader_loadarc_main_indicator_default);
	else
		lv_style_init(&style_loader_loadarc_main_indicator_default);
	lv_style_set_arc_color(&style_loader_loadarc_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_arc_width(&style_loader_loadarc_main_indicator_default, 12);
	lv_obj_add_style(ui->loader_loadarc, &style_loader_loadarc_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_loader_loadarc_main_knob_default
	static lv_style_t style_loader_loadarc_main_knob_default;
	if (style_loader_loadarc_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_loader_loadarc_main_knob_default);
	else
		lv_style_init(&style_loader_loadarc_main_knob_default);
	lv_style_set_bg_color(&style_loader_loadarc_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_loader_loadarc_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_loader_loadarc_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_loader_loadarc_main_knob_default, 255);
	lv_style_set_pad_all(&style_loader_loadarc_main_knob_default, 5);
	lv_obj_add_style(ui->loader_loadarc, &style_loader_loadarc_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_arc_set_mode(ui->loader_loadarc, LV_ARC_MODE_NORMAL);
	lv_arc_set_range(ui->loader_loadarc, 0, 100);
	lv_arc_set_bg_angles(ui->loader_loadarc, 0, 360);
	lv_arc_set_angles(ui->loader_loadarc, 271, 271);
	lv_arc_set_rotation(ui->loader_loadarc, 0);
	lv_obj_set_style_arc_rounded(ui->loader_loadarc, 0,  LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_rounded(ui->loader_loadarc, 0, LV_STATE_DEFAULT);

	//Write codes loader_loadlabel
	ui->loader_loadlabel = lv_label_create(ui->loader);
	lv_obj_set_pos(ui->loader_loadlabel, 201, 147);
	lv_obj_set_size(ui->loader_loadlabel, 80, 23);
	lv_obj_set_scrollbar_mode(ui->loader_loadlabel, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->loader_loadlabel, "0 %");
	lv_label_set_long_mode(ui->loader_loadlabel, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_loader_loadlabel_main_main_default
	static lv_style_t style_loader_loadlabel_main_main_default;
	if (style_loader_loadlabel_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_loader_loadlabel_main_main_default);
	else
		lv_style_init(&style_loader_loadlabel_main_main_default);
	lv_style_set_radius(&style_loader_loadlabel_main_main_default, 0);
	lv_style_set_bg_color(&style_loader_loadlabel_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_loader_loadlabel_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_loader_loadlabel_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_loader_loadlabel_main_main_default, 0);
	lv_style_set_shadow_width(&style_loader_loadlabel_main_main_default, 0);
	lv_style_set_shadow_color(&style_loader_loadlabel_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_loader_loadlabel_main_main_default, 255);
	lv_style_set_shadow_spread(&style_loader_loadlabel_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_loader_loadlabel_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_loader_loadlabel_main_main_default, 0);
	lv_style_set_text_color(&style_loader_loadlabel_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_loader_loadlabel_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_loader_loadlabel_main_main_default, 2);
	lv_style_set_text_line_space(&style_loader_loadlabel_main_main_default, 0);
	lv_style_set_text_align(&style_loader_loadlabel_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_loader_loadlabel_main_main_default, 0);
	lv_style_set_pad_right(&style_loader_loadlabel_main_main_default, 0);
	lv_style_set_pad_top(&style_loader_loadlabel_main_main_default, 0);
	lv_style_set_pad_bottom(&style_loader_loadlabel_main_main_default, 0);
	lv_obj_add_style(ui->loader_loadlabel, &style_loader_loadlabel_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
}