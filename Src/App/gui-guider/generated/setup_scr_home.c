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


void setup_scr_home(lv_ui *ui){

	//Write codes home
	ui->home = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->home, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_main_main_default
	static lv_style_t style_home_main_main_default;
	if (style_home_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_main_main_default);
	else
		lv_style_init(&style_home_main_main_default);
	lv_style_set_bg_color(&style_home_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_home_main_main_default, 0);
	lv_obj_add_style(ui->home, &style_home_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_cont1
	ui->home_cont1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->home_cont1, 0, 0);
	lv_obj_set_size(ui->home_cont1, 480, 117);
	lv_obj_set_scrollbar_mode(ui->home_cont1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_cont1_main_main_default
	static lv_style_t style_home_cont1_main_main_default;
	if (style_home_cont1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_cont1_main_main_default);
	else
		lv_style_init(&style_home_cont1_main_main_default);
	lv_style_set_radius(&style_home_cont1_main_main_default, 0);
	lv_style_set_bg_color(&style_home_cont1_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_home_cont1_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_home_cont1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_cont1_main_main_default, 255);
	lv_style_set_shadow_width(&style_home_cont1_main_main_default, 0);
	lv_style_set_shadow_color(&style_home_cont1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_cont1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_home_cont1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_home_cont1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_home_cont1_main_main_default, 0);
	lv_style_set_border_color(&style_home_cont1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_home_cont1_main_main_default, 0);
	lv_style_set_border_opa(&style_home_cont1_main_main_default, 255);
	lv_style_set_pad_left(&style_home_cont1_main_main_default, 0);
	lv_style_set_pad_right(&style_home_cont1_main_main_default, 0);
	lv_style_set_pad_top(&style_home_cont1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_cont1_main_main_default, 0);
	lv_obj_add_style(ui->home_cont1, &style_home_cont1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_whitebg
	ui->home_whitebg = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->home_whitebg, 0, 117);
	lv_obj_set_size(ui->home_whitebg, 480, 202);
	lv_obj_set_scrollbar_mode(ui->home_whitebg, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_whitebg_main_main_default
	static lv_style_t style_home_whitebg_main_main_default;
	if (style_home_whitebg_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_whitebg_main_main_default);
	else
		lv_style_init(&style_home_whitebg_main_main_default);
	lv_style_set_radius(&style_home_whitebg_main_main_default, 0);
	lv_style_set_bg_color(&style_home_whitebg_main_main_default, lv_color_make(0xd6, 0xdc, 0xd6));
	lv_style_set_bg_grad_color(&style_home_whitebg_main_main_default, lv_color_make(0xd9, 0xd9, 0xd9));
	lv_style_set_bg_grad_dir(&style_home_whitebg_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_whitebg_main_main_default, 255);
	lv_style_set_shadow_width(&style_home_whitebg_main_main_default, 0);
	lv_style_set_shadow_color(&style_home_whitebg_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_whitebg_main_main_default, 255);
	lv_style_set_shadow_spread(&style_home_whitebg_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_home_whitebg_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_home_whitebg_main_main_default, 0);
	lv_style_set_border_color(&style_home_whitebg_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_home_whitebg_main_main_default, 0);
	lv_style_set_border_opa(&style_home_whitebg_main_main_default, 255);
	lv_style_set_pad_left(&style_home_whitebg_main_main_default, 0);
	lv_style_set_pad_right(&style_home_whitebg_main_main_default, 0);
	lv_style_set_pad_top(&style_home_whitebg_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_whitebg_main_main_default, 0);
	lv_obj_add_style(ui->home_whitebg, &style_home_whitebg_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_cont2
	ui->home_cont2 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->home_cont2, 40, 94);
	lv_obj_set_size(ui->home_cont2, 380, 141);
	lv_obj_set_scrollbar_mode(ui->home_cont2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_cont2_main_main_default
	static lv_style_t style_home_cont2_main_main_default;
	if (style_home_cont2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_cont2_main_main_default);
	else
		lv_style_init(&style_home_cont2_main_main_default);
	lv_style_set_radius(&style_home_cont2_main_main_default, 0);
	lv_style_set_bg_color(&style_home_cont2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_home_cont2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_home_cont2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_cont2_main_main_default, 255);
	lv_style_set_shadow_width(&style_home_cont2_main_main_default, 0);
	lv_style_set_shadow_color(&style_home_cont2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_cont2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_home_cont2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_home_cont2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_home_cont2_main_main_default, 0);
	lv_style_set_border_color(&style_home_cont2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_home_cont2_main_main_default, 0);
	lv_style_set_border_opa(&style_home_cont2_main_main_default, 255);
	lv_style_set_pad_left(&style_home_cont2_main_main_default, 0);
	lv_style_set_pad_right(&style_home_cont2_main_main_default, 0);
	lv_style_set_pad_top(&style_home_cont2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_cont2_main_main_default, 0);
	lv_obj_add_style(ui->home_cont2, &style_home_cont2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_labeldate
	ui->home_labeldate = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_labeldate, 240, 35);
	lv_obj_set_size(ui->home_labeldate, 225, 35);
	lv_obj_set_scrollbar_mode(ui->home_labeldate, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_labeldate, "20 Nov 2020 08:08");
	lv_label_set_long_mode(ui->home_labeldate, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_labeldate_main_main_default
	static lv_style_t style_home_labeldate_main_main_default;
	if (style_home_labeldate_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_labeldate_main_main_default);
	else
		lv_style_init(&style_home_labeldate_main_main_default);
	lv_style_set_radius(&style_home_labeldate_main_main_default, 0);
	lv_style_set_bg_color(&style_home_labeldate_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_home_labeldate_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_home_labeldate_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_labeldate_main_main_default, 0);
	lv_style_set_shadow_width(&style_home_labeldate_main_main_default, 0);
	lv_style_set_shadow_color(&style_home_labeldate_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_labeldate_main_main_default, 255);
	lv_style_set_shadow_spread(&style_home_labeldate_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_home_labeldate_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_home_labeldate_main_main_default, 0);
	lv_style_set_text_color(&style_home_labeldate_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_home_labeldate_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_home_labeldate_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_labeldate_main_main_default, 0);
	lv_style_set_text_align(&style_home_labeldate_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_labeldate_main_main_default, 0);
	lv_style_set_pad_right(&style_home_labeldate_main_main_default, 0);
	lv_style_set_pad_top(&style_home_labeldate_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_labeldate_main_main_default, 0);
	lv_obj_add_style(ui->home_labeldate, &style_home_labeldate_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_imgbtncopy
	ui->home_imgbtncopy = lv_imgbtn_create(ui->home);
	lv_obj_set_pos(ui->home_imgbtncopy, 50, 105);
	lv_obj_set_size(ui->home_imgbtncopy, 85, 117);
	lv_obj_set_scrollbar_mode(ui->home_imgbtncopy, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_imgbtncopy_main_main_default
	static lv_style_t style_home_imgbtncopy_main_main_default;
	if (style_home_imgbtncopy_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_imgbtncopy_main_main_default);
	else
		lv_style_init(&style_home_imgbtncopy_main_main_default);
	lv_style_set_shadow_width(&style_home_imgbtncopy_main_main_default, 0);
	lv_style_set_shadow_color(&style_home_imgbtncopy_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_imgbtncopy_main_main_default, 255);
	lv_style_set_shadow_spread(&style_home_imgbtncopy_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_home_imgbtncopy_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_home_imgbtncopy_main_main_default, 0);
	lv_style_set_text_color(&style_home_imgbtncopy_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_home_imgbtncopy_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_home_imgbtncopy_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_home_imgbtncopy_main_main_default, 0);
	lv_style_set_img_opa(&style_home_imgbtncopy_main_main_default, 255);
	lv_obj_add_style(ui->home_imgbtncopy, &style_home_imgbtncopy_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_home_imgbtncopy_main_main_pressed
	static lv_style_t style_home_imgbtncopy_main_main_pressed;
	if (style_home_imgbtncopy_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_home_imgbtncopy_main_main_pressed);
	else
		lv_style_init(&style_home_imgbtncopy_main_main_pressed);
	lv_style_set_shadow_width(&style_home_imgbtncopy_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_home_imgbtncopy_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_imgbtncopy_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_home_imgbtncopy_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_home_imgbtncopy_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_home_imgbtncopy_main_main_pressed, 0);
	lv_style_set_text_color(&style_home_imgbtncopy_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_home_imgbtncopy_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_home_imgbtncopy_main_main_pressed, 0);
	lv_style_set_img_opa(&style_home_imgbtncopy_main_main_pressed, 255);
	lv_obj_add_style(ui->home_imgbtncopy, &style_home_imgbtncopy_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_home_imgbtncopy_main_main_checked
	static lv_style_t style_home_imgbtncopy_main_main_checked;
	if (style_home_imgbtncopy_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_home_imgbtncopy_main_main_checked);
	else
		lv_style_init(&style_home_imgbtncopy_main_main_checked);
	lv_style_set_shadow_width(&style_home_imgbtncopy_main_main_checked, 0);
	lv_style_set_shadow_color(&style_home_imgbtncopy_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_imgbtncopy_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_home_imgbtncopy_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_home_imgbtncopy_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_home_imgbtncopy_main_main_checked, 0);
	lv_style_set_text_color(&style_home_imgbtncopy_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_home_imgbtncopy_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_home_imgbtncopy_main_main_checked, 0);
	lv_style_set_img_opa(&style_home_imgbtncopy_main_main_checked, 255);
	lv_obj_add_style(ui->home_imgbtncopy, &style_home_imgbtncopy_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->home_imgbtncopy, LV_IMGBTN_STATE_RELEASED, NULL, &_btn_bg_1_alpha_85x117, NULL);
	lv_imgbtn_set_src(ui->home_imgbtncopy, LV_IMGBTN_STATE_PRESSED, NULL, &_btn_bg_1_alpha_85x117, NULL);
	lv_imgbtn_set_src(ui->home_imgbtncopy, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_btn_bg_1_alpha_85x117, NULL);
	lv_imgbtn_set_src(ui->home_imgbtncopy, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_btn_bg_1_alpha_85x117, NULL);

	//Write codes home_labelcopy
	ui->home_labelcopy = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_labelcopy, 60, 182);
	lv_obj_set_size(ui->home_labelcopy, 62, 23);
	lv_obj_set_scrollbar_mode(ui->home_labelcopy, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_labelcopy, "COPY");
	lv_label_set_long_mode(ui->home_labelcopy, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_labelcopy_main_main_default
	static lv_style_t style_home_labelcopy_main_main_default;
	if (style_home_labelcopy_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_labelcopy_main_main_default);
	else
		lv_style_init(&style_home_labelcopy_main_main_default);
	lv_style_set_radius(&style_home_labelcopy_main_main_default, 0);
	lv_style_set_bg_color(&style_home_labelcopy_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_home_labelcopy_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_home_labelcopy_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_labelcopy_main_main_default, 0);
	lv_style_set_shadow_width(&style_home_labelcopy_main_main_default, 0);
	lv_style_set_shadow_color(&style_home_labelcopy_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_labelcopy_main_main_default, 255);
	lv_style_set_shadow_spread(&style_home_labelcopy_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_home_labelcopy_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_home_labelcopy_main_main_default, 0);
	lv_style_set_text_color(&style_home_labelcopy_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_home_labelcopy_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_home_labelcopy_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_labelcopy_main_main_default, 0);
	lv_style_set_text_align(&style_home_labelcopy_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_labelcopy_main_main_default, 0);
	lv_style_set_pad_right(&style_home_labelcopy_main_main_default, 0);
	lv_style_set_pad_top(&style_home_labelcopy_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_labelcopy_main_main_default, 0);
	lv_obj_add_style(ui->home_labelcopy, &style_home_labelcopy_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_imgbtnset
	ui->home_imgbtnset = lv_imgbtn_create(ui->home);
	lv_obj_set_pos(ui->home_imgbtnset, 320, 105);
	lv_obj_set_size(ui->home_imgbtnset, 85, 117);
	lv_obj_set_scrollbar_mode(ui->home_imgbtnset, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_imgbtnset_main_main_default
	static lv_style_t style_home_imgbtnset_main_main_default;
	if (style_home_imgbtnset_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_imgbtnset_main_main_default);
	else
		lv_style_init(&style_home_imgbtnset_main_main_default);
	lv_style_set_shadow_width(&style_home_imgbtnset_main_main_default, 0);
	lv_style_set_shadow_color(&style_home_imgbtnset_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_imgbtnset_main_main_default, 255);
	lv_style_set_shadow_spread(&style_home_imgbtnset_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_home_imgbtnset_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_home_imgbtnset_main_main_default, 0);
	lv_style_set_text_color(&style_home_imgbtnset_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_home_imgbtnset_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_home_imgbtnset_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_home_imgbtnset_main_main_default, 0);
	lv_style_set_img_opa(&style_home_imgbtnset_main_main_default, 255);
	lv_obj_add_style(ui->home_imgbtnset, &style_home_imgbtnset_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_home_imgbtnset_main_main_pressed
	static lv_style_t style_home_imgbtnset_main_main_pressed;
	if (style_home_imgbtnset_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_home_imgbtnset_main_main_pressed);
	else
		lv_style_init(&style_home_imgbtnset_main_main_pressed);
	lv_style_set_shadow_width(&style_home_imgbtnset_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_home_imgbtnset_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_imgbtnset_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_home_imgbtnset_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_home_imgbtnset_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_home_imgbtnset_main_main_pressed, 0);
	lv_style_set_text_color(&style_home_imgbtnset_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_home_imgbtnset_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_home_imgbtnset_main_main_pressed, 0);
	lv_style_set_img_opa(&style_home_imgbtnset_main_main_pressed, 255);
	lv_obj_add_style(ui->home_imgbtnset, &style_home_imgbtnset_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_home_imgbtnset_main_main_checked
	static lv_style_t style_home_imgbtnset_main_main_checked;
	if (style_home_imgbtnset_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_home_imgbtnset_main_main_checked);
	else
		lv_style_init(&style_home_imgbtnset_main_main_checked);
	lv_style_set_shadow_width(&style_home_imgbtnset_main_main_checked, 0);
	lv_style_set_shadow_color(&style_home_imgbtnset_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_imgbtnset_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_home_imgbtnset_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_home_imgbtnset_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_home_imgbtnset_main_main_checked, 0);
	lv_style_set_text_color(&style_home_imgbtnset_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_home_imgbtnset_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_home_imgbtnset_main_main_checked, 0);
	lv_style_set_img_opa(&style_home_imgbtnset_main_main_checked, 255);
	lv_obj_add_style(ui->home_imgbtnset, &style_home_imgbtnset_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->home_imgbtnset, LV_IMGBTN_STATE_RELEASED, NULL, &_btn4_alpha_85x117, NULL);
	lv_imgbtn_set_src(ui->home_imgbtnset, LV_IMGBTN_STATE_PRESSED, NULL, &_btn4_alpha_85x117, NULL);
	lv_imgbtn_set_src(ui->home_imgbtnset, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_btn4_alpha_85x117, NULL);
	lv_imgbtn_set_src(ui->home_imgbtnset, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_btn4_alpha_85x117, NULL);

	//Write codes home_imgbtnscan
	ui->home_imgbtnscan = lv_imgbtn_create(ui->home);
	lv_obj_set_pos(ui->home_imgbtnscan, 140, 105);
	lv_obj_set_size(ui->home_imgbtnscan, 85, 117);
	lv_obj_set_scrollbar_mode(ui->home_imgbtnscan, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_imgbtnscan_main_main_default
	static lv_style_t style_home_imgbtnscan_main_main_default;
	if (style_home_imgbtnscan_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_imgbtnscan_main_main_default);
	else
		lv_style_init(&style_home_imgbtnscan_main_main_default);
	lv_style_set_shadow_width(&style_home_imgbtnscan_main_main_default, 0);
	lv_style_set_shadow_color(&style_home_imgbtnscan_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_imgbtnscan_main_main_default, 255);
	lv_style_set_shadow_spread(&style_home_imgbtnscan_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_home_imgbtnscan_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_home_imgbtnscan_main_main_default, 0);
	lv_style_set_text_color(&style_home_imgbtnscan_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_home_imgbtnscan_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_home_imgbtnscan_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_home_imgbtnscan_main_main_default, 0);
	lv_style_set_img_opa(&style_home_imgbtnscan_main_main_default, 255);
	lv_obj_add_style(ui->home_imgbtnscan, &style_home_imgbtnscan_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_home_imgbtnscan_main_main_pressed
	static lv_style_t style_home_imgbtnscan_main_main_pressed;
	if (style_home_imgbtnscan_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_home_imgbtnscan_main_main_pressed);
	else
		lv_style_init(&style_home_imgbtnscan_main_main_pressed);
	lv_style_set_shadow_width(&style_home_imgbtnscan_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_home_imgbtnscan_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_imgbtnscan_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_home_imgbtnscan_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_home_imgbtnscan_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_home_imgbtnscan_main_main_pressed, 0);
	lv_style_set_text_color(&style_home_imgbtnscan_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_home_imgbtnscan_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_home_imgbtnscan_main_main_pressed, 0);
	lv_style_set_img_opa(&style_home_imgbtnscan_main_main_pressed, 255);
	lv_obj_add_style(ui->home_imgbtnscan, &style_home_imgbtnscan_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_home_imgbtnscan_main_main_checked
	static lv_style_t style_home_imgbtnscan_main_main_checked;
	if (style_home_imgbtnscan_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_home_imgbtnscan_main_main_checked);
	else
		lv_style_init(&style_home_imgbtnscan_main_main_checked);
	lv_style_set_shadow_width(&style_home_imgbtnscan_main_main_checked, 0);
	lv_style_set_shadow_color(&style_home_imgbtnscan_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_imgbtnscan_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_home_imgbtnscan_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_home_imgbtnscan_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_home_imgbtnscan_main_main_checked, 0);
	lv_style_set_text_color(&style_home_imgbtnscan_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_home_imgbtnscan_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_home_imgbtnscan_main_main_checked, 0);
	lv_style_set_img_opa(&style_home_imgbtnscan_main_main_checked, 255);
	lv_obj_add_style(ui->home_imgbtnscan, &style_home_imgbtnscan_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->home_imgbtnscan, LV_IMGBTN_STATE_RELEASED, NULL, &_btn2_alpha_85x117, NULL);
	lv_imgbtn_set_src(ui->home_imgbtnscan, LV_IMGBTN_STATE_PRESSED, NULL, &_btn2_alpha_85x117, NULL);
	lv_imgbtn_set_src(ui->home_imgbtnscan, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_btn2_alpha_85x117, NULL);
	lv_imgbtn_set_src(ui->home_imgbtnscan, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_btn2_alpha_85x117, NULL);

	//Write codes home_imgbtnprt
	ui->home_imgbtnprt = lv_imgbtn_create(ui->home);
	lv_obj_set_pos(ui->home_imgbtnprt, 230, 105);
	lv_obj_set_size(ui->home_imgbtnprt, 85, 117);
	lv_obj_set_scrollbar_mode(ui->home_imgbtnprt, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_imgbtnprt_main_main_default
	static lv_style_t style_home_imgbtnprt_main_main_default;
	if (style_home_imgbtnprt_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_imgbtnprt_main_main_default);
	else
		lv_style_init(&style_home_imgbtnprt_main_main_default);
	lv_style_set_shadow_width(&style_home_imgbtnprt_main_main_default, 0);
	lv_style_set_shadow_color(&style_home_imgbtnprt_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_imgbtnprt_main_main_default, 255);
	lv_style_set_shadow_spread(&style_home_imgbtnprt_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_home_imgbtnprt_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_home_imgbtnprt_main_main_default, 0);
	lv_style_set_text_color(&style_home_imgbtnprt_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_home_imgbtnprt_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_home_imgbtnprt_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_home_imgbtnprt_main_main_default, 0);
	lv_style_set_img_opa(&style_home_imgbtnprt_main_main_default, 255);
	lv_obj_add_style(ui->home_imgbtnprt, &style_home_imgbtnprt_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_home_imgbtnprt_main_main_pressed
	static lv_style_t style_home_imgbtnprt_main_main_pressed;
	if (style_home_imgbtnprt_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_home_imgbtnprt_main_main_pressed);
	else
		lv_style_init(&style_home_imgbtnprt_main_main_pressed);
	lv_style_set_shadow_width(&style_home_imgbtnprt_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_home_imgbtnprt_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_imgbtnprt_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_home_imgbtnprt_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_home_imgbtnprt_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_home_imgbtnprt_main_main_pressed, 0);
	lv_style_set_text_color(&style_home_imgbtnprt_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_home_imgbtnprt_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_home_imgbtnprt_main_main_pressed, 0);
	lv_style_set_img_opa(&style_home_imgbtnprt_main_main_pressed, 255);
	lv_obj_add_style(ui->home_imgbtnprt, &style_home_imgbtnprt_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_home_imgbtnprt_main_main_checked
	static lv_style_t style_home_imgbtnprt_main_main_checked;
	if (style_home_imgbtnprt_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_home_imgbtnprt_main_main_checked);
	else
		lv_style_init(&style_home_imgbtnprt_main_main_checked);
	lv_style_set_shadow_width(&style_home_imgbtnprt_main_main_checked, 0);
	lv_style_set_shadow_color(&style_home_imgbtnprt_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_imgbtnprt_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_home_imgbtnprt_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_home_imgbtnprt_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_home_imgbtnprt_main_main_checked, 0);
	lv_style_set_text_color(&style_home_imgbtnprt_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_home_imgbtnprt_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_home_imgbtnprt_main_main_checked, 0);
	lv_style_set_img_opa(&style_home_imgbtnprt_main_main_checked, 255);
	lv_obj_add_style(ui->home_imgbtnprt, &style_home_imgbtnprt_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->home_imgbtnprt, LV_IMGBTN_STATE_RELEASED, NULL, &_btn3_alpha_85x117, NULL);
	lv_imgbtn_set_src(ui->home_imgbtnprt, LV_IMGBTN_STATE_PRESSED, NULL, &_btn3_alpha_85x117, NULL);
	lv_imgbtn_set_src(ui->home_imgbtnprt, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_btn3_alpha_85x117, NULL);
	lv_imgbtn_set_src(ui->home_imgbtnprt, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_btn3_alpha_85x117, NULL);

	//Write codes home_labelscan
	ui->home_labelscan = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_labelscan, 150, 182);
	lv_obj_set_size(ui->home_labelscan, 60, 23);
	lv_obj_set_scrollbar_mode(ui->home_labelscan, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_labelscan, "SCAN");
	lv_label_set_long_mode(ui->home_labelscan, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_labelscan_main_main_default
	static lv_style_t style_home_labelscan_main_main_default;
	if (style_home_labelscan_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_labelscan_main_main_default);
	else
		lv_style_init(&style_home_labelscan_main_main_default);
	lv_style_set_radius(&style_home_labelscan_main_main_default, 0);
	lv_style_set_bg_color(&style_home_labelscan_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_home_labelscan_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_home_labelscan_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_labelscan_main_main_default, 0);
	lv_style_set_shadow_width(&style_home_labelscan_main_main_default, 0);
	lv_style_set_shadow_color(&style_home_labelscan_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_labelscan_main_main_default, 255);
	lv_style_set_shadow_spread(&style_home_labelscan_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_home_labelscan_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_home_labelscan_main_main_default, 0);
	lv_style_set_text_color(&style_home_labelscan_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_home_labelscan_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_home_labelscan_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_labelscan_main_main_default, 0);
	lv_style_set_text_align(&style_home_labelscan_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_labelscan_main_main_default, 0);
	lv_style_set_pad_right(&style_home_labelscan_main_main_default, 0);
	lv_style_set_pad_top(&style_home_labelscan_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_labelscan_main_main_default, 0);
	lv_obj_add_style(ui->home_labelscan, &style_home_labelscan_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_labelprt
	ui->home_labelprt = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_labelprt, 240, 182);
	lv_obj_set_size(ui->home_labelprt, 70, 23);
	lv_obj_set_scrollbar_mode(ui->home_labelprt, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_labelprt, "PRINT");
	lv_label_set_long_mode(ui->home_labelprt, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_labelprt_main_main_default
	static lv_style_t style_home_labelprt_main_main_default;
	if (style_home_labelprt_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_labelprt_main_main_default);
	else
		lv_style_init(&style_home_labelprt_main_main_default);
	lv_style_set_radius(&style_home_labelprt_main_main_default, 0);
	lv_style_set_bg_color(&style_home_labelprt_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_home_labelprt_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_home_labelprt_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_labelprt_main_main_default, 0);
	lv_style_set_shadow_width(&style_home_labelprt_main_main_default, 0);
	lv_style_set_shadow_color(&style_home_labelprt_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_labelprt_main_main_default, 255);
	lv_style_set_shadow_spread(&style_home_labelprt_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_home_labelprt_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_home_labelprt_main_main_default, 0);
	lv_style_set_text_color(&style_home_labelprt_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_home_labelprt_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_home_labelprt_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_labelprt_main_main_default, 0);
	lv_style_set_text_align(&style_home_labelprt_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_labelprt_main_main_default, 0);
	lv_style_set_pad_right(&style_home_labelprt_main_main_default, 0);
	lv_style_set_pad_top(&style_home_labelprt_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_labelprt_main_main_default, 0);
	lv_obj_add_style(ui->home_labelprt, &style_home_labelprt_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_labelset
	ui->home_labelset = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_labelset, 328, 182);
	lv_obj_set_size(ui->home_labelset, 75, 23);
	lv_obj_set_scrollbar_mode(ui->home_labelset, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_labelset, "SETUP");
	lv_label_set_long_mode(ui->home_labelset, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_labelset_main_main_default
	static lv_style_t style_home_labelset_main_main_default;
	if (style_home_labelset_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_labelset_main_main_default);
	else
		lv_style_init(&style_home_labelset_main_main_default);
	lv_style_set_radius(&style_home_labelset_main_main_default, 0);
	lv_style_set_bg_color(&style_home_labelset_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_home_labelset_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_home_labelset_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_labelset_main_main_default, 0);
	lv_style_set_shadow_width(&style_home_labelset_main_main_default, 0);
	lv_style_set_shadow_color(&style_home_labelset_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_labelset_main_main_default, 255);
	lv_style_set_shadow_spread(&style_home_labelset_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_home_labelset_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_home_labelset_main_main_default, 0);
	lv_style_set_text_color(&style_home_labelset_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_home_labelset_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_home_labelset_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_labelset_main_main_default, 0);
	lv_style_set_text_align(&style_home_labelset_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_labelset_main_main_default, 0);
	lv_style_set_pad_right(&style_home_labelset_main_main_default, 0);
	lv_style_set_pad_top(&style_home_labelset_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_labelset_main_main_default, 0);
	lv_obj_add_style(ui->home_labelset, &style_home_labelset_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_labelnote
	ui->home_labelnote = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_labelnote, 16, 264);
	lv_obj_set_size(ui->home_labelnote, 276, 23);
	lv_obj_set_scrollbar_mode(ui->home_labelnote, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_labelnote, "What do you want to do today?");
	lv_label_set_long_mode(ui->home_labelnote, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_labelnote_main_main_default
	static lv_style_t style_home_labelnote_main_main_default;
	if (style_home_labelnote_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_labelnote_main_main_default);
	else
		lv_style_init(&style_home_labelnote_main_main_default);
	lv_style_set_radius(&style_home_labelnote_main_main_default, 0);
	lv_style_set_bg_color(&style_home_labelnote_main_main_default, lv_color_make(0xf6, 0xfa, 0xff));
	lv_style_set_bg_grad_color(&style_home_labelnote_main_main_default, lv_color_make(0xf6, 0xfa, 0xff));
	lv_style_set_bg_grad_dir(&style_home_labelnote_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_labelnote_main_main_default, 0);
	lv_style_set_shadow_width(&style_home_labelnote_main_main_default, 0);
	lv_style_set_shadow_color(&style_home_labelnote_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_labelnote_main_main_default, 255);
	lv_style_set_shadow_spread(&style_home_labelnote_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_home_labelnote_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_home_labelnote_main_main_default, 0);
	lv_style_set_text_color(&style_home_labelnote_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_labelnote_main_main_default, &lv_font_arial_14);
	lv_style_set_text_letter_space(&style_home_labelnote_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_labelnote_main_main_default, 0);
	lv_style_set_text_align(&style_home_labelnote_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_labelnote_main_main_default, 0);
	lv_style_set_pad_right(&style_home_labelnote_main_main_default, 0);
	lv_style_set_pad_top(&style_home_labelnote_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_labelnote_main_main_default, 0);
	lv_obj_add_style(ui->home_labelnote, &style_home_labelnote_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_contbars
	ui->home_contbars = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->home_contbars, 300, 241);
	lv_obj_set_size(ui->home_contbars, 150, 58);
	lv_obj_set_scrollbar_mode(ui->home_contbars, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_contbars_main_main_default
	static lv_style_t style_home_contbars_main_main_default;
	if (style_home_contbars_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_contbars_main_main_default);
	else
		lv_style_init(&style_home_contbars_main_main_default);
	lv_style_set_radius(&style_home_contbars_main_main_default, 0);
	lv_style_set_bg_color(&style_home_contbars_main_main_default, lv_color_make(0xde, 0xde, 0xde));
	lv_style_set_bg_grad_color(&style_home_contbars_main_main_default, lv_color_make(0xd9, 0xd9, 0xd9));
	lv_style_set_bg_grad_dir(&style_home_contbars_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_contbars_main_main_default, 255);
	lv_style_set_shadow_width(&style_home_contbars_main_main_default, 0);
	lv_style_set_shadow_color(&style_home_contbars_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_contbars_main_main_default, 255);
	lv_style_set_shadow_spread(&style_home_contbars_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_home_contbars_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_home_contbars_main_main_default, 0);
	lv_style_set_border_color(&style_home_contbars_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_home_contbars_main_main_default, 0);
	lv_style_set_border_opa(&style_home_contbars_main_main_default, 255);
	lv_style_set_pad_left(&style_home_contbars_main_main_default, 0);
	lv_style_set_pad_right(&style_home_contbars_main_main_default, 0);
	lv_style_set_pad_top(&style_home_contbars_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_contbars_main_main_default, 0);
	lv_obj_add_style(ui->home_contbars, &style_home_contbars_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_bar1
	ui->home_bar1 = lv_bar_create(ui->home);
	lv_obj_set_pos(ui->home_bar1, 315, 258);
	lv_obj_set_size(ui->home_bar1, 20, 35);
	lv_obj_set_scrollbar_mode(ui->home_bar1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_bar1_main_main_default
	static lv_style_t style_home_bar1_main_main_default;
	if (style_home_bar1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_bar1_main_main_default);
	else
		lv_style_init(&style_home_bar1_main_main_default);
	lv_style_set_radius(&style_home_bar1_main_main_default, 5);
	lv_style_set_bg_color(&style_home_bar1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_home_bar1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_home_bar1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_bar1_main_main_default, 255);
	lv_style_set_shadow_width(&style_home_bar1_main_main_default, 0);
	lv_style_set_shadow_color(&style_home_bar1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_bar1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_home_bar1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_home_bar1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_home_bar1_main_main_default, 0);
	lv_obj_add_style(ui->home_bar1, &style_home_bar1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_home_bar1_main_indicator_default
	static lv_style_t style_home_bar1_main_indicator_default;
	if (style_home_bar1_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_home_bar1_main_indicator_default);
	else
		lv_style_init(&style_home_bar1_main_indicator_default);
	lv_style_set_radius(&style_home_bar1_main_indicator_default, 5);
	lv_style_set_bg_color(&style_home_bar1_main_indicator_default, lv_color_make(0x2e, 0xdc, 0xb0));
	lv_style_set_bg_grad_color(&style_home_bar1_main_indicator_default, lv_color_make(0x05, 0xd6, 0xa2));
	lv_style_set_bg_grad_dir(&style_home_bar1_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_bar1_main_indicator_default, 255);
	lv_obj_add_style(ui->home_bar1, &style_home_bar1_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_anim_time(ui->home_bar1, 1000, 0);
	lv_bar_set_mode(ui->home_bar1, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->home_bar1, 60, LV_ANIM_ON);

	//Write codes home_bar2
	ui->home_bar2 = lv_bar_create(ui->home);
	lv_obj_set_pos(ui->home_bar2, 350, 258);
	lv_obj_set_size(ui->home_bar2, 20, 35);
	lv_obj_set_scrollbar_mode(ui->home_bar2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_bar2_main_main_default
	static lv_style_t style_home_bar2_main_main_default;
	if (style_home_bar2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_bar2_main_main_default);
	else
		lv_style_init(&style_home_bar2_main_main_default);
	lv_style_set_radius(&style_home_bar2_main_main_default, 5);
	lv_style_set_bg_color(&style_home_bar2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_home_bar2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_home_bar2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_bar2_main_main_default, 255);
	lv_style_set_shadow_width(&style_home_bar2_main_main_default, 0);
	lv_style_set_shadow_color(&style_home_bar2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_bar2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_home_bar2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_home_bar2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_home_bar2_main_main_default, 0);
	lv_obj_add_style(ui->home_bar2, &style_home_bar2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_home_bar2_main_indicator_default
	static lv_style_t style_home_bar2_main_indicator_default;
	if (style_home_bar2_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_home_bar2_main_indicator_default);
	else
		lv_style_init(&style_home_bar2_main_indicator_default);
	lv_style_set_radius(&style_home_bar2_main_indicator_default, 5);
	lv_style_set_bg_color(&style_home_bar2_main_indicator_default, lv_color_make(0xe5, 0xe9, 0x07));
	lv_style_set_bg_grad_color(&style_home_bar2_main_indicator_default, lv_color_make(0xf2, 0xf6, 0x09));
	lv_style_set_bg_grad_dir(&style_home_bar2_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_bar2_main_indicator_default, 255);
	lv_obj_add_style(ui->home_bar2, &style_home_bar2_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_anim_time(ui->home_bar2, 1000, 0);
	lv_bar_set_mode(ui->home_bar2, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->home_bar2, 40, LV_ANIM_ON);

	//Write codes home_bar3
	ui->home_bar3 = lv_bar_create(ui->home);
	lv_obj_set_pos(ui->home_bar3, 385, 258);
	lv_obj_set_size(ui->home_bar3, 20, 35);
	lv_obj_set_scrollbar_mode(ui->home_bar3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_bar3_main_main_default
	static lv_style_t style_home_bar3_main_main_default;
	if (style_home_bar3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_bar3_main_main_default);
	else
		lv_style_init(&style_home_bar3_main_main_default);
	lv_style_set_radius(&style_home_bar3_main_main_default, 5);
	lv_style_set_bg_color(&style_home_bar3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_home_bar3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_home_bar3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_bar3_main_main_default, 255);
	lv_style_set_shadow_width(&style_home_bar3_main_main_default, 0);
	lv_style_set_shadow_color(&style_home_bar3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_bar3_main_main_default, 255);
	lv_style_set_shadow_spread(&style_home_bar3_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_home_bar3_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_home_bar3_main_main_default, 0);
	lv_obj_add_style(ui->home_bar3, &style_home_bar3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_home_bar3_main_indicator_default
	static lv_style_t style_home_bar3_main_indicator_default;
	if (style_home_bar3_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_home_bar3_main_indicator_default);
	else
		lv_style_init(&style_home_bar3_main_indicator_default);
	lv_style_set_radius(&style_home_bar3_main_indicator_default, 5);
	lv_style_set_bg_color(&style_home_bar3_main_indicator_default, lv_color_make(0xa2, 0x0e, 0xd8));
	lv_style_set_bg_grad_color(&style_home_bar3_main_indicator_default, lv_color_make(0xae, 0x00, 0xd1));
	lv_style_set_bg_grad_dir(&style_home_bar3_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_bar3_main_indicator_default, 255);
	lv_obj_add_style(ui->home_bar3, &style_home_bar3_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_anim_time(ui->home_bar3, 1000, 0);
	lv_bar_set_mode(ui->home_bar3, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->home_bar3, 80, LV_ANIM_ON);

	//Write codes home_bar4
	ui->home_bar4 = lv_bar_create(ui->home);
	lv_obj_set_pos(ui->home_bar4, 425, 258);
	lv_obj_set_size(ui->home_bar4, 20, 35);
	lv_obj_set_scrollbar_mode(ui->home_bar4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_bar4_main_main_default
	static lv_style_t style_home_bar4_main_main_default;
	if (style_home_bar4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_bar4_main_main_default);
	else
		lv_style_init(&style_home_bar4_main_main_default);
	lv_style_set_radius(&style_home_bar4_main_main_default, 5);
	lv_style_set_bg_color(&style_home_bar4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_home_bar4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_home_bar4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_bar4_main_main_default, 255);
	lv_style_set_shadow_width(&style_home_bar4_main_main_default, 0);
	lv_style_set_shadow_color(&style_home_bar4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_home_bar4_main_main_default, 255);
	lv_style_set_shadow_spread(&style_home_bar4_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_home_bar4_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_home_bar4_main_main_default, 0);
	lv_obj_add_style(ui->home_bar4, &style_home_bar4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_home_bar4_main_indicator_default
	static lv_style_t style_home_bar4_main_indicator_default;
	if (style_home_bar4_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_home_bar4_main_indicator_default);
	else
		lv_style_init(&style_home_bar4_main_indicator_default);
	lv_style_set_radius(&style_home_bar4_main_indicator_default, 5);
	lv_style_set_bg_color(&style_home_bar4_main_indicator_default, lv_color_make(0x98, 0xe5, 0x24));
	lv_style_set_bg_grad_color(&style_home_bar4_main_indicator_default, lv_color_make(0x8c, 0xed, 0x2c));
	lv_style_set_bg_grad_dir(&style_home_bar4_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_bar4_main_indicator_default, 255);
	lv_obj_add_style(ui->home_bar4, &style_home_bar4_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_anim_time(ui->home_bar4, 1000, 0);
	lv_bar_set_mode(ui->home_bar4, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->home_bar4, 30, LV_ANIM_ON);

	//Write codes home_wifi
	ui->home_wifi = lv_img_create(ui->home);
	lv_obj_set_pos(ui->home_wifi, 56, 36);
	lv_obj_set_size(ui->home_wifi, 29, 22);
	lv_obj_set_scrollbar_mode(ui->home_wifi, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_wifi_main_main_default
	static lv_style_t style_home_wifi_main_main_default;
	if (style_home_wifi_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_wifi_main_main_default);
	else
		lv_style_init(&style_home_wifi_main_main_default);
	lv_style_set_img_recolor(&style_home_wifi_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_home_wifi_main_main_default, 0);
	lv_style_set_img_opa(&style_home_wifi_main_main_default, 255);
	lv_obj_add_style(ui->home_wifi, &style_home_wifi_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->home_wifi, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->home_wifi,&_wifi_29x22);
	lv_img_set_pivot(ui->home_wifi, 0,0);
	lv_img_set_angle(ui->home_wifi, 0);

	//Write codes home_tel
	ui->home_tel = lv_img_create(ui->home);
	lv_obj_set_pos(ui->home_tel, 105, 35);
	lv_obj_set_size(ui->home_tel, 21, 24);
	lv_obj_set_scrollbar_mode(ui->home_tel, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_tel_main_main_default
	static lv_style_t style_home_tel_main_main_default;
	if (style_home_tel_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_tel_main_main_default);
	else
		lv_style_init(&style_home_tel_main_main_default);
	lv_style_set_img_recolor(&style_home_tel_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_home_tel_main_main_default, 0);
	lv_style_set_img_opa(&style_home_tel_main_main_default, 255);
	lv_obj_add_style(ui->home_tel, &style_home_tel_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->home_tel, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->home_tel,&_tel_21x24);
	lv_img_set_pivot(ui->home_tel, 0,0);
	lv_img_set_angle(ui->home_tel, 0);

	//Write codes home_eco
	ui->home_eco = lv_img_create(ui->home);
	lv_obj_set_pos(ui->home_eco, 147, 35);
	lv_obj_set_size(ui->home_eco, 21, 24);
	lv_obj_set_scrollbar_mode(ui->home_eco, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_eco_main_main_default
	static lv_style_t style_home_eco_main_main_default;
	if (style_home_eco_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_eco_main_main_default);
	else
		lv_style_init(&style_home_eco_main_main_default);
	lv_style_set_img_recolor(&style_home_eco_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_home_eco_main_main_default, 0);
	lv_style_set_img_opa(&style_home_eco_main_main_default, 255);
	lv_obj_add_style(ui->home_eco, &style_home_eco_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->home_eco, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->home_eco,&_eco_21x24);
	lv_img_set_pivot(ui->home_eco, 0,0);
	lv_img_set_angle(ui->home_eco, 0);

	//Write codes home_pc
	ui->home_pc = lv_img_create(ui->home);
	lv_obj_set_pos(ui->home_pc, 198, 35);
	lv_obj_set_size(ui->home_pc, 21, 24);
	lv_obj_set_scrollbar_mode(ui->home_pc, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_pc_main_main_default
	static lv_style_t style_home_pc_main_main_default;
	if (style_home_pc_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_pc_main_main_default);
	else
		lv_style_init(&style_home_pc_main_main_default);
	lv_style_set_img_recolor(&style_home_pc_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_home_pc_main_main_default, 0);
	lv_style_set_img_opa(&style_home_pc_main_main_default, 255);
	lv_obj_add_style(ui->home_pc, &style_home_pc_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->home_pc, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->home_pc,&_pc_21x24);
	lv_img_set_pivot(ui->home_pc, 0,0);
	lv_img_set_angle(ui->home_pc, 0);

	//Write codes home_imgcopy
	ui->home_imgcopy = lv_img_create(ui->home);
	lv_obj_set_pos(ui->home_imgcopy, 90, 127);
	lv_obj_set_size(ui->home_imgcopy, 29, 34);
	lv_obj_set_scrollbar_mode(ui->home_imgcopy, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_imgcopy_main_main_default
	static lv_style_t style_home_imgcopy_main_main_default;
	if (style_home_imgcopy_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_imgcopy_main_main_default);
	else
		lv_style_init(&style_home_imgcopy_main_main_default);
	lv_style_set_img_recolor(&style_home_imgcopy_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_home_imgcopy_main_main_default, 0);
	lv_style_set_img_opa(&style_home_imgcopy_main_main_default, 255);
	lv_obj_add_style(ui->home_imgcopy, &style_home_imgcopy_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->home_imgcopy, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->home_imgcopy,&_copy_29x34);
	lv_img_set_pivot(ui->home_imgcopy, 0,0);
	lv_img_set_angle(ui->home_imgcopy, 0);

	//Write codes home_imgscan
	ui->home_imgscan = lv_img_create(ui->home);
	lv_obj_set_pos(ui->home_imgscan, 180, 127);
	lv_obj_set_size(ui->home_imgscan, 29, 34);
	lv_obj_set_scrollbar_mode(ui->home_imgscan, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_imgscan_main_main_default
	static lv_style_t style_home_imgscan_main_main_default;
	if (style_home_imgscan_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_imgscan_main_main_default);
	else
		lv_style_init(&style_home_imgscan_main_main_default);
	lv_style_set_img_recolor(&style_home_imgscan_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_home_imgscan_main_main_default, 0);
	lv_style_set_img_opa(&style_home_imgscan_main_main_default, 255);
	lv_obj_add_style(ui->home_imgscan, &style_home_imgscan_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->home_imgscan, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->home_imgscan,&_scan_29x34);
	lv_img_set_pivot(ui->home_imgscan, 0,0);
	lv_img_set_angle(ui->home_imgscan, 0);

	//Write codes home_imgprt
	ui->home_imgprt = lv_img_create(ui->home);
	lv_obj_set_pos(ui->home_imgprt, 270, 127);
	lv_obj_set_size(ui->home_imgprt, 29, 34);
	lv_obj_set_scrollbar_mode(ui->home_imgprt, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_imgprt_main_main_default
	static lv_style_t style_home_imgprt_main_main_default;
	if (style_home_imgprt_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_imgprt_main_main_default);
	else
		lv_style_init(&style_home_imgprt_main_main_default);
	lv_style_set_img_recolor(&style_home_imgprt_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_home_imgprt_main_main_default, 0);
	lv_style_set_img_opa(&style_home_imgprt_main_main_default, 255);
	lv_obj_add_style(ui->home_imgprt, &style_home_imgprt_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->home_imgprt, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->home_imgprt,&_print_29x34);
	lv_img_set_pivot(ui->home_imgprt, 0,0);
	lv_img_set_angle(ui->home_imgprt, 0);

	//Write codes home_imgset
	ui->home_imgset = lv_img_create(ui->home);
	lv_obj_set_pos(ui->home_imgset, 360, 127);
	lv_obj_set_size(ui->home_imgset, 29, 34);
	lv_obj_set_scrollbar_mode(ui->home_imgset, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_imgset_main_main_default
	static lv_style_t style_home_imgset_main_main_default;
	if (style_home_imgset_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_imgset_main_main_default);
	else
		lv_style_init(&style_home_imgset_main_main_default);
	lv_style_set_img_recolor(&style_home_imgset_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_home_imgset_main_main_default, 0);
	lv_style_set_img_opa(&style_home_imgset_main_main_default, 255);
	lv_obj_add_style(ui->home_imgset, &style_home_imgset_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->home_imgset, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->home_imgset,&_setup_29x34);
	lv_img_set_pivot(ui->home_imgset, 0,0);
	lv_img_set_angle(ui->home_imgset, 0);

	//Init events for screen
	events_init_home(ui);
}