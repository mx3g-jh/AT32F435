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


void setup_scr_copynext(lv_ui *ui){

	//Write codes copynext
	ui->copynext = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->copynext, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copynext_main_main_default
	static lv_style_t style_copynext_main_main_default;
	if (style_copynext_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_main_main_default);
	else
		lv_style_init(&style_copynext_main_main_default);
	lv_style_set_bg_color(&style_copynext_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_copynext_main_main_default, 0);
	lv_obj_add_style(ui->copynext, &style_copynext_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes copynext_cont1
	ui->copynext_cont1 = lv_obj_create(ui->copynext);
	lv_obj_set_pos(ui->copynext_cont1, 0, 0);
	lv_obj_set_size(ui->copynext_cont1, 480, 117);
	lv_obj_set_scrollbar_mode(ui->copynext_cont1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copynext_cont1_main_main_default
	static lv_style_t style_copynext_cont1_main_main_default;
	if (style_copynext_cont1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_cont1_main_main_default);
	else
		lv_style_init(&style_copynext_cont1_main_main_default);
	lv_style_set_radius(&style_copynext_cont1_main_main_default, 0);
	lv_style_set_bg_color(&style_copynext_cont1_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_copynext_cont1_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_copynext_cont1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_cont1_main_main_default, 255);
	lv_style_set_shadow_width(&style_copynext_cont1_main_main_default, 0);
	lv_style_set_shadow_color(&style_copynext_cont1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copynext_cont1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_copynext_cont1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copynext_cont1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copynext_cont1_main_main_default, 0);
	lv_style_set_border_color(&style_copynext_cont1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_copynext_cont1_main_main_default, 0);
	lv_style_set_border_opa(&style_copynext_cont1_main_main_default, 255);
	lv_style_set_pad_left(&style_copynext_cont1_main_main_default, 0);
	lv_style_set_pad_right(&style_copynext_cont1_main_main_default, 0);
	lv_style_set_pad_top(&style_copynext_cont1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_copynext_cont1_main_main_default, 0);
	lv_obj_add_style(ui->copynext_cont1, &style_copynext_cont1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes copynext_cont2
	ui->copynext_cont2 = lv_obj_create(ui->copynext);
	lv_obj_set_pos(ui->copynext_cont2, 0, 117);
	lv_obj_set_size(ui->copynext_cont2, 480, 202);
	lv_obj_set_scrollbar_mode(ui->copynext_cont2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copynext_cont2_main_main_default
	static lv_style_t style_copynext_cont2_main_main_default;
	if (style_copynext_cont2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_cont2_main_main_default);
	else
		lv_style_init(&style_copynext_cont2_main_main_default);
	lv_style_set_radius(&style_copynext_cont2_main_main_default, 0);
	lv_style_set_bg_color(&style_copynext_cont2_main_main_default, lv_color_make(0xde, 0xde, 0xde));
	lv_style_set_bg_grad_color(&style_copynext_cont2_main_main_default, lv_color_make(0xde, 0xde, 0xde));
	lv_style_set_bg_grad_dir(&style_copynext_cont2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_cont2_main_main_default, 255);
	lv_style_set_shadow_width(&style_copynext_cont2_main_main_default, 0);
	lv_style_set_shadow_color(&style_copynext_cont2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copynext_cont2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_copynext_cont2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copynext_cont2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copynext_cont2_main_main_default, 0);
	lv_style_set_border_color(&style_copynext_cont2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_copynext_cont2_main_main_default, 0);
	lv_style_set_border_opa(&style_copynext_cont2_main_main_default, 255);
	lv_style_set_pad_left(&style_copynext_cont2_main_main_default, 0);
	lv_style_set_pad_right(&style_copynext_cont2_main_main_default, 0);
	lv_style_set_pad_top(&style_copynext_cont2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_copynext_cont2_main_main_default, 0);
	lv_obj_add_style(ui->copynext_cont2, &style_copynext_cont2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes copynext_label1
	ui->copynext_label1 = lv_label_create(ui->copynext);
	lv_obj_set_pos(ui->copynext_label1, 136, 35);
	lv_obj_set_size(ui->copynext_label1, 225, 23);
	lv_obj_set_scrollbar_mode(ui->copynext_label1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->copynext_label1, "ADJUST IMAGE");
	lv_label_set_long_mode(ui->copynext_label1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_copynext_label1_main_main_default
	static lv_style_t style_copynext_label1_main_main_default;
	if (style_copynext_label1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_label1_main_main_default);
	else
		lv_style_init(&style_copynext_label1_main_main_default);
	lv_style_set_radius(&style_copynext_label1_main_main_default, 0);
	lv_style_set_bg_color(&style_copynext_label1_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_copynext_label1_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_copynext_label1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_label1_main_main_default, 0);
	lv_style_set_shadow_width(&style_copynext_label1_main_main_default, 0);
	lv_style_set_shadow_color(&style_copynext_label1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copynext_label1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_copynext_label1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copynext_label1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copynext_label1_main_main_default, 0);
	lv_style_set_text_color(&style_copynext_label1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_copynext_label1_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_copynext_label1_main_main_default, 2);
	lv_style_set_text_line_space(&style_copynext_label1_main_main_default, 0);
	lv_style_set_text_align(&style_copynext_label1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_copynext_label1_main_main_default, 0);
	lv_style_set_pad_right(&style_copynext_label1_main_main_default, 0);
	lv_style_set_pad_top(&style_copynext_label1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_copynext_label1_main_main_default, 0);
	lv_obj_add_style(ui->copynext_label1, &style_copynext_label1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes copynext_img3
	ui->copynext_img3 = lv_img_create(ui->copynext);
	lv_obj_set_pos(ui->copynext_img3, 27, 88);
	lv_obj_set_size(ui->copynext_img3, 250, 161);
	lv_obj_set_scrollbar_mode(ui->copynext_img3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copynext_img3_main_main_default
	static lv_style_t style_copynext_img3_main_main_default;
	if (style_copynext_img3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_img3_main_main_default);
	else
		lv_style_init(&style_copynext_img3_main_main_default);
	lv_style_set_img_recolor(&style_copynext_img3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_copynext_img3_main_main_default, 0);
	lv_style_set_img_opa(&style_copynext_img3_main_main_default, 255);
	lv_obj_add_style(ui->copynext_img3, &style_copynext_img3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->copynext_img3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->copynext_img3,&_example_250x161);
	lv_img_set_pivot(ui->copynext_img3, 0,0);
	lv_img_set_angle(ui->copynext_img3, 0);

	//Write codes copynext_cont4
	ui->copynext_cont4 = lv_obj_create(ui->copynext);
	lv_obj_set_pos(ui->copynext_cont4, 305, 94);
	lv_obj_set_size(ui->copynext_cont4, 150, 152);
	lv_obj_set_scrollbar_mode(ui->copynext_cont4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copynext_cont4_main_main_default
	static lv_style_t style_copynext_cont4_main_main_default;
	if (style_copynext_cont4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_cont4_main_main_default);
	else
		lv_style_init(&style_copynext_cont4_main_main_default);
	lv_style_set_radius(&style_copynext_cont4_main_main_default, 0);
	lv_style_set_bg_color(&style_copynext_cont4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_copynext_cont4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_copynext_cont4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_cont4_main_main_default, 255);
	lv_style_set_shadow_width(&style_copynext_cont4_main_main_default, 0);
	lv_style_set_shadow_color(&style_copynext_cont4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copynext_cont4_main_main_default, 255);
	lv_style_set_shadow_spread(&style_copynext_cont4_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copynext_cont4_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copynext_cont4_main_main_default, 0);
	lv_style_set_border_color(&style_copynext_cont4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_copynext_cont4_main_main_default, 0);
	lv_style_set_border_opa(&style_copynext_cont4_main_main_default, 255);
	lv_style_set_pad_left(&style_copynext_cont4_main_main_default, 0);
	lv_style_set_pad_right(&style_copynext_cont4_main_main_default, 0);
	lv_style_set_pad_top(&style_copynext_cont4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_copynext_cont4_main_main_default, 0);
	lv_obj_add_style(ui->copynext_cont4, &style_copynext_cont4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes copynext_ddlist2
	ui->copynext_ddlist2 = lv_dropdown_create(ui->copynext);
	lv_obj_set_pos(ui->copynext_ddlist2, 166, 268);
	lv_obj_set_size(ui->copynext_ddlist2, 100, 23);
	lv_obj_set_scrollbar_mode(ui->copynext_ddlist2, LV_SCROLLBAR_MODE_OFF);
	lv_dropdown_set_options(ui->copynext_ddlist2, "72 DPI\n96 DPI\n150 DPI\n300 DPI\n600 DPI\n900 DPI\n1200 DPI");

	//Write style state: LV_STATE_DEFAULT for style_copynext_ddlist2_main_main_default
	static lv_style_t style_copynext_ddlist2_main_main_default;
	if (style_copynext_ddlist2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_ddlist2_main_main_default);
	else
		lv_style_init(&style_copynext_ddlist2_main_main_default);
	lv_style_set_radius(&style_copynext_ddlist2_main_main_default, 3);
	lv_style_set_bg_color(&style_copynext_ddlist2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_copynext_ddlist2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_copynext_ddlist2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_ddlist2_main_main_default, 255);
	lv_style_set_shadow_width(&style_copynext_ddlist2_main_main_default, 0);
	lv_style_set_shadow_color(&style_copynext_ddlist2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copynext_ddlist2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_copynext_ddlist2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copynext_ddlist2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copynext_ddlist2_main_main_default, 0);
	lv_style_set_border_color(&style_copynext_ddlist2_main_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_copynext_ddlist2_main_main_default, 1);
	lv_style_set_border_opa(&style_copynext_ddlist2_main_main_default, 255);
	lv_style_set_text_color(&style_copynext_ddlist2_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_copynext_ddlist2_main_main_default, &lv_font_arial_12);
	lv_style_set_pad_left(&style_copynext_ddlist2_main_main_default, 6);
	lv_style_set_pad_right(&style_copynext_ddlist2_main_main_default, 6);
	lv_style_set_pad_top(&style_copynext_ddlist2_main_main_default, 0);
	lv_obj_add_style(ui->copynext_ddlist2, &style_copynext_ddlist2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_copynext_ddlist2_extra_list_selected_checked
	static lv_style_t style_copynext_ddlist2_extra_list_selected_checked;
	if (style_copynext_ddlist2_extra_list_selected_checked.prop_cnt > 1)
		lv_style_reset(&style_copynext_ddlist2_extra_list_selected_checked);
	else
		lv_style_init(&style_copynext_ddlist2_extra_list_selected_checked);
	lv_style_set_radius(&style_copynext_ddlist2_extra_list_selected_checked, 3);
	lv_style_set_bg_color(&style_copynext_ddlist2_extra_list_selected_checked, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_color(&style_copynext_ddlist2_extra_list_selected_checked, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_dir(&style_copynext_ddlist2_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_copynext_ddlist2_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_copynext_ddlist2_extra_list_selected_checked, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_copynext_ddlist2_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_copynext_ddlist2_extra_list_selected_checked, 255);
	lv_style_set_text_color(&style_copynext_ddlist2_extra_list_selected_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_copynext_ddlist2_extra_list_selected_checked, &lv_font_montserratMedium_12);
	lv_obj_add_style(lv_dropdown_get_list(ui->copynext_ddlist2), &style_copynext_ddlist2_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for style_copynext_ddlist2_extra_list_main_default
	static lv_style_t style_copynext_ddlist2_extra_list_main_default;
	if (style_copynext_ddlist2_extra_list_main_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_ddlist2_extra_list_main_default);
	else
		lv_style_init(&style_copynext_ddlist2_extra_list_main_default);
	lv_style_set_radius(&style_copynext_ddlist2_extra_list_main_default, 3);
	lv_style_set_bg_color(&style_copynext_ddlist2_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_copynext_ddlist2_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_copynext_ddlist2_extra_list_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_ddlist2_extra_list_main_default, 255);
	lv_style_set_border_color(&style_copynext_ddlist2_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_copynext_ddlist2_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_copynext_ddlist2_extra_list_main_default, 255);
	lv_style_set_text_color(&style_copynext_ddlist2_extra_list_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_copynext_ddlist2_extra_list_main_default, &lv_font_arial_12);
	lv_style_set_max_height(&style_copynext_ddlist2_extra_list_main_default, 90);
	lv_obj_add_style(lv_dropdown_get_list(ui->copynext_ddlist2), &style_copynext_ddlist2_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_copynext_ddlist2_extra_list_scrollbar_default
	static lv_style_t style_copynext_ddlist2_extra_list_scrollbar_default;
	if (style_copynext_ddlist2_extra_list_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_ddlist2_extra_list_scrollbar_default);
	else
		lv_style_init(&style_copynext_ddlist2_extra_list_scrollbar_default);
	lv_style_set_radius(&style_copynext_ddlist2_extra_list_scrollbar_default, 3);
	lv_style_set_bg_color(&style_copynext_ddlist2_extra_list_scrollbar_default, lv_color_make(0x00, 0xff, 0x00));
	lv_style_set_bg_opa(&style_copynext_ddlist2_extra_list_scrollbar_default, 255);
	lv_obj_add_style(lv_dropdown_get_list(ui->copynext_ddlist2), &style_copynext_ddlist2_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes copynext_btncopyback
	ui->copynext_btncopyback = lv_btn_create(ui->copynext);
	lv_obj_set_pos(ui->copynext_btncopyback, 50, 29);
	lv_obj_set_size(ui->copynext_btncopyback, 30, 35);
	lv_obj_set_scrollbar_mode(ui->copynext_btncopyback, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copynext_btncopyback_main_main_default
	static lv_style_t style_copynext_btncopyback_main_main_default;
	if (style_copynext_btncopyback_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_btncopyback_main_main_default);
	else
		lv_style_init(&style_copynext_btncopyback_main_main_default);
	lv_style_set_radius(&style_copynext_btncopyback_main_main_default, 50);
	lv_style_set_bg_color(&style_copynext_btncopyback_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_copynext_btncopyback_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_copynext_btncopyback_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_btncopyback_main_main_default, 0);
	lv_style_set_shadow_width(&style_copynext_btncopyback_main_main_default, 0);
	lv_style_set_shadow_color(&style_copynext_btncopyback_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copynext_btncopyback_main_main_default, 0);
	lv_style_set_shadow_spread(&style_copynext_btncopyback_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copynext_btncopyback_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copynext_btncopyback_main_main_default, 0);
	lv_style_set_border_color(&style_copynext_btncopyback_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_copynext_btncopyback_main_main_default, 0);
	lv_style_set_border_opa(&style_copynext_btncopyback_main_main_default, 255);
	lv_style_set_text_color(&style_copynext_btncopyback_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_copynext_btncopyback_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_align(&style_copynext_btncopyback_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->copynext_btncopyback, &style_copynext_btncopyback_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->copynext_btncopyback_label = lv_label_create(ui->copynext_btncopyback);
	lv_label_set_text(ui->copynext_btncopyback_label, "<");
	lv_obj_set_style_pad_all(ui->copynext_btncopyback, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->copynext_btncopyback_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes copynext_swcolor
	ui->copynext_swcolor = lv_switch_create(ui->copynext);
	lv_obj_set_pos(ui->copynext_swcolor, 323, 205);
	lv_obj_set_size(ui->copynext_swcolor, 40, 23);
	lv_obj_set_scrollbar_mode(ui->copynext_swcolor, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copynext_swcolor_main_main_default
	static lv_style_t style_copynext_swcolor_main_main_default;
	if (style_copynext_swcolor_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_swcolor_main_main_default);
	else
		lv_style_init(&style_copynext_swcolor_main_main_default);
	lv_style_set_radius(&style_copynext_swcolor_main_main_default, 100);
	lv_style_set_bg_color(&style_copynext_swcolor_main_main_default, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_color(&style_copynext_swcolor_main_main_default, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_dir(&style_copynext_swcolor_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_swcolor_main_main_default, 255);
	lv_style_set_shadow_width(&style_copynext_swcolor_main_main_default, 0);
	lv_style_set_shadow_color(&style_copynext_swcolor_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copynext_swcolor_main_main_default, 255);
	lv_style_set_shadow_spread(&style_copynext_swcolor_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copynext_swcolor_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copynext_swcolor_main_main_default, 0);
	lv_style_set_border_color(&style_copynext_swcolor_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_copynext_swcolor_main_main_default, 0);
	lv_style_set_border_opa(&style_copynext_swcolor_main_main_default, 255);
	lv_obj_add_style(ui->copynext_swcolor, &style_copynext_swcolor_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_copynext_swcolor_main_indicator_checked
	static lv_style_t style_copynext_swcolor_main_indicator_checked;
	if (style_copynext_swcolor_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_copynext_swcolor_main_indicator_checked);
	else
		lv_style_init(&style_copynext_swcolor_main_indicator_checked);
	lv_style_set_bg_color(&style_copynext_swcolor_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_copynext_swcolor_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_copynext_swcolor_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_swcolor_main_indicator_checked, 255);
	lv_style_set_border_color(&style_copynext_swcolor_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_copynext_swcolor_main_indicator_checked, 0);
	lv_style_set_border_opa(&style_copynext_swcolor_main_indicator_checked, 255);
	lv_obj_add_style(ui->copynext_swcolor, &style_copynext_swcolor_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for style_copynext_swcolor_main_knob_default
	static lv_style_t style_copynext_swcolor_main_knob_default;
	if (style_copynext_swcolor_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_swcolor_main_knob_default);
	else
		lv_style_init(&style_copynext_swcolor_main_knob_default);
	lv_style_set_radius(&style_copynext_swcolor_main_knob_default, 100);
	lv_style_set_bg_color(&style_copynext_swcolor_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_copynext_swcolor_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_copynext_swcolor_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_swcolor_main_knob_default, 255);
	lv_style_set_border_color(&style_copynext_swcolor_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_copynext_swcolor_main_knob_default, 0);
	lv_style_set_border_opa(&style_copynext_swcolor_main_knob_default, 255);
	lv_obj_add_style(ui->copynext_swcolor, &style_copynext_swcolor_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes copynext_labelcopy
	ui->copynext_labelcopy = lv_label_create(ui->copynext);
	lv_obj_set_pos(ui->copynext_labelcopy, 346, 101);
	lv_obj_set_size(ui->copynext_labelcopy, 64, 23);
	lv_obj_set_scrollbar_mode(ui->copynext_labelcopy, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->copynext_labelcopy, "Copies");
	lv_label_set_long_mode(ui->copynext_labelcopy, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_copynext_labelcopy_main_main_default
	static lv_style_t style_copynext_labelcopy_main_main_default;
	if (style_copynext_labelcopy_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_labelcopy_main_main_default);
	else
		lv_style_init(&style_copynext_labelcopy_main_main_default);
	lv_style_set_radius(&style_copynext_labelcopy_main_main_default, 0);
	lv_style_set_bg_color(&style_copynext_labelcopy_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_copynext_labelcopy_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_copynext_labelcopy_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_labelcopy_main_main_default, 0);
	lv_style_set_shadow_width(&style_copynext_labelcopy_main_main_default, 0);
	lv_style_set_shadow_color(&style_copynext_labelcopy_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copynext_labelcopy_main_main_default, 255);
	lv_style_set_shadow_spread(&style_copynext_labelcopy_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copynext_labelcopy_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copynext_labelcopy_main_main_default, 0);
	lv_style_set_text_color(&style_copynext_labelcopy_main_main_default, lv_color_make(0x20, 0x18, 0x18));
	lv_style_set_text_font(&style_copynext_labelcopy_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_copynext_labelcopy_main_main_default, 2);
	lv_style_set_text_line_space(&style_copynext_labelcopy_main_main_default, 0);
	lv_style_set_text_align(&style_copynext_labelcopy_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_copynext_labelcopy_main_main_default, 0);
	lv_style_set_pad_right(&style_copynext_labelcopy_main_main_default, 0);
	lv_style_set_pad_top(&style_copynext_labelcopy_main_main_default, 0);
	lv_style_set_pad_bottom(&style_copynext_labelcopy_main_main_default, 0);
	lv_obj_add_style(ui->copynext_labelcopy, &style_copynext_labelcopy_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes copynext_up
	ui->copynext_up = lv_btn_create(ui->copynext);
	lv_obj_set_pos(ui->copynext_up, 417, 129);
	lv_obj_set_size(ui->copynext_up, 20, 23);
	lv_obj_set_scrollbar_mode(ui->copynext_up, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copynext_up_main_main_default
	static lv_style_t style_copynext_up_main_main_default;
	if (style_copynext_up_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_up_main_main_default);
	else
		lv_style_init(&style_copynext_up_main_main_default);
	lv_style_set_radius(&style_copynext_up_main_main_default, 4);
	lv_style_set_bg_color(&style_copynext_up_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_copynext_up_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_copynext_up_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_up_main_main_default, 255);
	lv_style_set_shadow_width(&style_copynext_up_main_main_default, 0);
	lv_style_set_shadow_color(&style_copynext_up_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copynext_up_main_main_default, 0);
	lv_style_set_shadow_spread(&style_copynext_up_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copynext_up_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copynext_up_main_main_default, 0);
	lv_style_set_border_color(&style_copynext_up_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_copynext_up_main_main_default, 0);
	lv_style_set_border_opa(&style_copynext_up_main_main_default, 255);
	lv_style_set_text_color(&style_copynext_up_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_copynext_up_main_main_default, &lv_font_simsun_18);
	lv_style_set_text_align(&style_copynext_up_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->copynext_up, &style_copynext_up_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->copynext_up_label = lv_label_create(ui->copynext_up);
	lv_label_set_text(ui->copynext_up_label, "+");
	lv_obj_set_style_pad_all(ui->copynext_up, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->copynext_up_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes copynext_down
	ui->copynext_down = lv_btn_create(ui->copynext);
	lv_obj_set_pos(ui->copynext_down, 322, 129);
	lv_obj_set_size(ui->copynext_down, 20, 23);
	lv_obj_set_scrollbar_mode(ui->copynext_down, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copynext_down_main_main_default
	static lv_style_t style_copynext_down_main_main_default;
	if (style_copynext_down_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_down_main_main_default);
	else
		lv_style_init(&style_copynext_down_main_main_default);
	lv_style_set_radius(&style_copynext_down_main_main_default, 4);
	lv_style_set_bg_color(&style_copynext_down_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_copynext_down_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_copynext_down_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_down_main_main_default, 255);
	lv_style_set_shadow_width(&style_copynext_down_main_main_default, 0);
	lv_style_set_shadow_color(&style_copynext_down_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copynext_down_main_main_default, 0);
	lv_style_set_shadow_spread(&style_copynext_down_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copynext_down_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copynext_down_main_main_default, 0);
	lv_style_set_border_color(&style_copynext_down_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_copynext_down_main_main_default, 0);
	lv_style_set_border_opa(&style_copynext_down_main_main_default, 255);
	lv_style_set_text_color(&style_copynext_down_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_copynext_down_main_main_default, &lv_font_simsun_18);
	lv_style_set_text_align(&style_copynext_down_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->copynext_down, &style_copynext_down_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->copynext_down_label = lv_label_create(ui->copynext_down);
	lv_label_set_text(ui->copynext_down_label, "-");
	lv_obj_set_style_pad_all(ui->copynext_down, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->copynext_down_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes copynext_labelcnt
	ui->copynext_labelcnt = lv_label_create(ui->copynext);
	lv_obj_set_pos(ui->copynext_labelcnt, 348, 132);
	lv_obj_set_size(ui->copynext_labelcnt, 56, 23);
	lv_obj_set_scrollbar_mode(ui->copynext_labelcnt, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->copynext_labelcnt, "1");
	lv_label_set_long_mode(ui->copynext_labelcnt, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_copynext_labelcnt_main_main_default
	static lv_style_t style_copynext_labelcnt_main_main_default;
	if (style_copynext_labelcnt_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_labelcnt_main_main_default);
	else
		lv_style_init(&style_copynext_labelcnt_main_main_default);
	lv_style_set_radius(&style_copynext_labelcnt_main_main_default, 0);
	lv_style_set_bg_color(&style_copynext_labelcnt_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_copynext_labelcnt_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_copynext_labelcnt_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_labelcnt_main_main_default, 0);
	lv_style_set_shadow_width(&style_copynext_labelcnt_main_main_default, 0);
	lv_style_set_shadow_color(&style_copynext_labelcnt_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copynext_labelcnt_main_main_default, 255);
	lv_style_set_shadow_spread(&style_copynext_labelcnt_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copynext_labelcnt_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copynext_labelcnt_main_main_default, 0);
	lv_style_set_text_color(&style_copynext_labelcnt_main_main_default, lv_color_make(0x0a, 0x06, 0x06));
	lv_style_set_text_font(&style_copynext_labelcnt_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_copynext_labelcnt_main_main_default, 2);
	lv_style_set_text_line_space(&style_copynext_labelcnt_main_main_default, 0);
	lv_style_set_text_align(&style_copynext_labelcnt_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_copynext_labelcnt_main_main_default, 0);
	lv_style_set_pad_right(&style_copynext_labelcnt_main_main_default, 0);
	lv_style_set_pad_top(&style_copynext_labelcnt_main_main_default, 0);
	lv_style_set_pad_bottom(&style_copynext_labelcnt_main_main_default, 0);
	lv_obj_add_style(ui->copynext_labelcnt, &style_copynext_labelcnt_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes copynext_labelcolor
	ui->copynext_labelcolor = lv_label_create(ui->copynext);
	lv_obj_set_pos(ui->copynext_labelcolor, 314, 171);
	lv_obj_set_size(ui->copynext_labelcolor, 50, 23);
	lv_obj_set_scrollbar_mode(ui->copynext_labelcolor, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->copynext_labelcolor, "Color");
	lv_label_set_long_mode(ui->copynext_labelcolor, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_copynext_labelcolor_main_main_default
	static lv_style_t style_copynext_labelcolor_main_main_default;
	if (style_copynext_labelcolor_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_labelcolor_main_main_default);
	else
		lv_style_init(&style_copynext_labelcolor_main_main_default);
	lv_style_set_radius(&style_copynext_labelcolor_main_main_default, 0);
	lv_style_set_bg_color(&style_copynext_labelcolor_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_copynext_labelcolor_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_copynext_labelcolor_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_labelcolor_main_main_default, 0);
	lv_style_set_shadow_width(&style_copynext_labelcolor_main_main_default, 0);
	lv_style_set_shadow_color(&style_copynext_labelcolor_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copynext_labelcolor_main_main_default, 255);
	lv_style_set_shadow_spread(&style_copynext_labelcolor_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copynext_labelcolor_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copynext_labelcolor_main_main_default, 0);
	lv_style_set_text_color(&style_copynext_labelcolor_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_copynext_labelcolor_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_copynext_labelcolor_main_main_default, 2);
	lv_style_set_text_line_space(&style_copynext_labelcolor_main_main_default, 0);
	lv_style_set_text_align(&style_copynext_labelcolor_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_copynext_labelcolor_main_main_default, 0);
	lv_style_set_pad_right(&style_copynext_labelcolor_main_main_default, 0);
	lv_style_set_pad_top(&style_copynext_labelcolor_main_main_default, 0);
	lv_style_set_pad_bottom(&style_copynext_labelcolor_main_main_default, 0);
	lv_obj_add_style(ui->copynext_labelcolor, &style_copynext_labelcolor_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes copynext_labelvert
	ui->copynext_labelvert = lv_label_create(ui->copynext);
	lv_obj_set_pos(ui->copynext_labelvert, 380, 171);
	lv_obj_set_size(ui->copynext_labelvert, 70, 23);
	lv_obj_set_scrollbar_mode(ui->copynext_labelvert, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->copynext_labelvert, "Vertical");
	lv_label_set_long_mode(ui->copynext_labelvert, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_copynext_labelvert_main_main_default
	static lv_style_t style_copynext_labelvert_main_main_default;
	if (style_copynext_labelvert_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_labelvert_main_main_default);
	else
		lv_style_init(&style_copynext_labelvert_main_main_default);
	lv_style_set_radius(&style_copynext_labelvert_main_main_default, 0);
	lv_style_set_bg_color(&style_copynext_labelvert_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_copynext_labelvert_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_copynext_labelvert_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_labelvert_main_main_default, 0);
	lv_style_set_shadow_width(&style_copynext_labelvert_main_main_default, 0);
	lv_style_set_shadow_color(&style_copynext_labelvert_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copynext_labelvert_main_main_default, 255);
	lv_style_set_shadow_spread(&style_copynext_labelvert_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copynext_labelvert_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copynext_labelvert_main_main_default, 0);
	lv_style_set_text_color(&style_copynext_labelvert_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_copynext_labelvert_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_copynext_labelvert_main_main_default, 2);
	lv_style_set_text_line_space(&style_copynext_labelvert_main_main_default, 0);
	lv_style_set_text_align(&style_copynext_labelvert_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_copynext_labelvert_main_main_default, 0);
	lv_style_set_pad_right(&style_copynext_labelvert_main_main_default, 0);
	lv_style_set_pad_top(&style_copynext_labelvert_main_main_default, 0);
	lv_style_set_pad_bottom(&style_copynext_labelvert_main_main_default, 0);
	lv_obj_add_style(ui->copynext_labelvert, &style_copynext_labelvert_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes copynext_swvert
	ui->copynext_swvert = lv_switch_create(ui->copynext);
	lv_obj_set_pos(ui->copynext_swvert, 390, 205);
	lv_obj_set_size(ui->copynext_swvert, 40, 23);
	lv_obj_set_scrollbar_mode(ui->copynext_swvert, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copynext_swvert_main_main_default
	static lv_style_t style_copynext_swvert_main_main_default;
	if (style_copynext_swvert_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_swvert_main_main_default);
	else
		lv_style_init(&style_copynext_swvert_main_main_default);
	lv_style_set_radius(&style_copynext_swvert_main_main_default, 100);
	lv_style_set_bg_color(&style_copynext_swvert_main_main_default, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_color(&style_copynext_swvert_main_main_default, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_dir(&style_copynext_swvert_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_swvert_main_main_default, 255);
	lv_style_set_shadow_width(&style_copynext_swvert_main_main_default, 0);
	lv_style_set_shadow_color(&style_copynext_swvert_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copynext_swvert_main_main_default, 255);
	lv_style_set_shadow_spread(&style_copynext_swvert_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copynext_swvert_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copynext_swvert_main_main_default, 0);
	lv_style_set_border_color(&style_copynext_swvert_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_copynext_swvert_main_main_default, 0);
	lv_style_set_border_opa(&style_copynext_swvert_main_main_default, 255);
	lv_obj_add_style(ui->copynext_swvert, &style_copynext_swvert_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_copynext_swvert_main_indicator_checked
	static lv_style_t style_copynext_swvert_main_indicator_checked;
	if (style_copynext_swvert_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_copynext_swvert_main_indicator_checked);
	else
		lv_style_init(&style_copynext_swvert_main_indicator_checked);
	lv_style_set_bg_color(&style_copynext_swvert_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_copynext_swvert_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_copynext_swvert_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_swvert_main_indicator_checked, 255);
	lv_style_set_border_color(&style_copynext_swvert_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_copynext_swvert_main_indicator_checked, 0);
	lv_style_set_border_opa(&style_copynext_swvert_main_indicator_checked, 255);
	lv_obj_add_style(ui->copynext_swvert, &style_copynext_swvert_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for style_copynext_swvert_main_knob_default
	static lv_style_t style_copynext_swvert_main_knob_default;
	if (style_copynext_swvert_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_swvert_main_knob_default);
	else
		lv_style_init(&style_copynext_swvert_main_knob_default);
	lv_style_set_radius(&style_copynext_swvert_main_knob_default, 100);
	lv_style_set_bg_color(&style_copynext_swvert_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_copynext_swvert_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_copynext_swvert_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_swvert_main_knob_default, 255);
	lv_style_set_border_color(&style_copynext_swvert_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_copynext_swvert_main_knob_default, 0);
	lv_style_set_border_opa(&style_copynext_swvert_main_knob_default, 255);
	lv_obj_add_style(ui->copynext_swvert, &style_copynext_swvert_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes copynext_ddlist1
	ui->copynext_ddlist1 = lv_dropdown_create(ui->copynext);
	lv_obj_set_pos(ui->copynext_ddlist1, 31, 267);
	lv_obj_set_size(ui->copynext_ddlist1, 100, 23);
	lv_obj_set_scrollbar_mode(ui->copynext_ddlist1, LV_SCROLLBAR_MODE_OFF);
	lv_dropdown_set_options(ui->copynext_ddlist1, "Best\nNormal\nDraft");

	//Write style state: LV_STATE_DEFAULT for style_copynext_ddlist1_main_main_default
	static lv_style_t style_copynext_ddlist1_main_main_default;
	if (style_copynext_ddlist1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_ddlist1_main_main_default);
	else
		lv_style_init(&style_copynext_ddlist1_main_main_default);
	lv_style_set_radius(&style_copynext_ddlist1_main_main_default, 3);
	lv_style_set_bg_color(&style_copynext_ddlist1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_copynext_ddlist1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_copynext_ddlist1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_ddlist1_main_main_default, 255);
	lv_style_set_shadow_width(&style_copynext_ddlist1_main_main_default, 0);
	lv_style_set_shadow_color(&style_copynext_ddlist1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copynext_ddlist1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_copynext_ddlist1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copynext_ddlist1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copynext_ddlist1_main_main_default, 0);
	lv_style_set_border_color(&style_copynext_ddlist1_main_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_copynext_ddlist1_main_main_default, 1);
	lv_style_set_border_opa(&style_copynext_ddlist1_main_main_default, 255);
	lv_style_set_text_color(&style_copynext_ddlist1_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_copynext_ddlist1_main_main_default, &lv_font_arial_12);
	lv_style_set_pad_left(&style_copynext_ddlist1_main_main_default, 6);
	lv_style_set_pad_right(&style_copynext_ddlist1_main_main_default, 6);
	lv_style_set_pad_top(&style_copynext_ddlist1_main_main_default, 0);
	lv_obj_add_style(ui->copynext_ddlist1, &style_copynext_ddlist1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_copynext_ddlist1_extra_list_selected_checked
	static lv_style_t style_copynext_ddlist1_extra_list_selected_checked;
	if (style_copynext_ddlist1_extra_list_selected_checked.prop_cnt > 1)
		lv_style_reset(&style_copynext_ddlist1_extra_list_selected_checked);
	else
		lv_style_init(&style_copynext_ddlist1_extra_list_selected_checked);
	lv_style_set_radius(&style_copynext_ddlist1_extra_list_selected_checked, 3);
	lv_style_set_bg_color(&style_copynext_ddlist1_extra_list_selected_checked, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_color(&style_copynext_ddlist1_extra_list_selected_checked, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_dir(&style_copynext_ddlist1_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_copynext_ddlist1_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_copynext_ddlist1_extra_list_selected_checked, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_copynext_ddlist1_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_copynext_ddlist1_extra_list_selected_checked, 255);
	lv_style_set_text_color(&style_copynext_ddlist1_extra_list_selected_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_copynext_ddlist1_extra_list_selected_checked, &lv_font_montserratMedium_12);
	lv_obj_add_style(lv_dropdown_get_list(ui->copynext_ddlist1), &style_copynext_ddlist1_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for style_copynext_ddlist1_extra_list_main_default
	static lv_style_t style_copynext_ddlist1_extra_list_main_default;
	if (style_copynext_ddlist1_extra_list_main_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_ddlist1_extra_list_main_default);
	else
		lv_style_init(&style_copynext_ddlist1_extra_list_main_default);
	lv_style_set_radius(&style_copynext_ddlist1_extra_list_main_default, 3);
	lv_style_set_bg_color(&style_copynext_ddlist1_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_copynext_ddlist1_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_copynext_ddlist1_extra_list_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_ddlist1_extra_list_main_default, 255);
	lv_style_set_border_color(&style_copynext_ddlist1_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_copynext_ddlist1_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_copynext_ddlist1_extra_list_main_default, 255);
	lv_style_set_text_color(&style_copynext_ddlist1_extra_list_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_copynext_ddlist1_extra_list_main_default, &lv_font_arial_12);
	lv_style_set_max_height(&style_copynext_ddlist1_extra_list_main_default, 90);
	lv_obj_add_style(lv_dropdown_get_list(ui->copynext_ddlist1), &style_copynext_ddlist1_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_copynext_ddlist1_extra_list_scrollbar_default
	static lv_style_t style_copynext_ddlist1_extra_list_scrollbar_default;
	if (style_copynext_ddlist1_extra_list_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_ddlist1_extra_list_scrollbar_default);
	else
		lv_style_init(&style_copynext_ddlist1_extra_list_scrollbar_default);
	lv_style_set_radius(&style_copynext_ddlist1_extra_list_scrollbar_default, 3);
	lv_style_set_bg_color(&style_copynext_ddlist1_extra_list_scrollbar_default, lv_color_make(0x00, 0xff, 0x00));
	lv_style_set_bg_opa(&style_copynext_ddlist1_extra_list_scrollbar_default, 255);
	lv_obj_add_style(lv_dropdown_get_list(ui->copynext_ddlist1), &style_copynext_ddlist1_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes copynext_print
	ui->copynext_print = lv_btn_create(ui->copynext);
	lv_obj_set_pos(ui->copynext_print, 320, 262);
	lv_obj_set_size(ui->copynext_print, 118, 47);
	lv_obj_set_scrollbar_mode(ui->copynext_print, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_copynext_print_main_main_default
	static lv_style_t style_copynext_print_main_main_default;
	if (style_copynext_print_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_copynext_print_main_main_default);
	else
		lv_style_init(&style_copynext_print_main_main_default);
	lv_style_set_radius(&style_copynext_print_main_main_default, 50);
	lv_style_set_bg_color(&style_copynext_print_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_copynext_print_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_copynext_print_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_copynext_print_main_main_default, 255);
	lv_style_set_shadow_width(&style_copynext_print_main_main_default, 0);
	lv_style_set_shadow_color(&style_copynext_print_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_copynext_print_main_main_default, 0);
	lv_style_set_shadow_spread(&style_copynext_print_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_copynext_print_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_copynext_print_main_main_default, 0);
	lv_style_set_border_color(&style_copynext_print_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_copynext_print_main_main_default, 0);
	lv_style_set_border_opa(&style_copynext_print_main_main_default, 255);
	lv_style_set_text_color(&style_copynext_print_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_copynext_print_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_align(&style_copynext_print_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->copynext_print, &style_copynext_print_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->copynext_print_label = lv_label_create(ui->copynext_print);
	lv_label_set_text(ui->copynext_print_label, "PRINT");
	lv_obj_set_style_pad_all(ui->copynext_print, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->copynext_print_label, LV_ALIGN_CENTER, 0, 0);
}