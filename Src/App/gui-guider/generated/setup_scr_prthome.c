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


void setup_scr_prthome(lv_ui *ui){

	//Write codes prthome
	ui->prthome = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->prthome, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prthome_main_main_default
	static lv_style_t style_prthome_main_main_default;
	if (style_prthome_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prthome_main_main_default);
	else
		lv_style_init(&style_prthome_main_main_default);
	lv_style_set_bg_color(&style_prthome_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_prthome_main_main_default, 0);
	lv_obj_add_style(ui->prthome, &style_prthome_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prthome_cont0
	ui->prthome_cont0 = lv_obj_create(ui->prthome);
	lv_obj_set_pos(ui->prthome_cont0, 0, 0);
	lv_obj_set_size(ui->prthome_cont0, 480, 117);
	lv_obj_set_scrollbar_mode(ui->prthome_cont0, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prthome_cont0_main_main_default
	static lv_style_t style_prthome_cont0_main_main_default;
	if (style_prthome_cont0_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prthome_cont0_main_main_default);
	else
		lv_style_init(&style_prthome_cont0_main_main_default);
	lv_style_set_radius(&style_prthome_cont0_main_main_default, 0);
	lv_style_set_bg_color(&style_prthome_cont0_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_prthome_cont0_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_prthome_cont0_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prthome_cont0_main_main_default, 255);
	lv_style_set_shadow_width(&style_prthome_cont0_main_main_default, 0);
	lv_style_set_shadow_color(&style_prthome_cont0_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prthome_cont0_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prthome_cont0_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prthome_cont0_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prthome_cont0_main_main_default, 0);
	lv_style_set_border_color(&style_prthome_cont0_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_prthome_cont0_main_main_default, 0);
	lv_style_set_border_opa(&style_prthome_cont0_main_main_default, 255);
	lv_style_set_pad_left(&style_prthome_cont0_main_main_default, 0);
	lv_style_set_pad_right(&style_prthome_cont0_main_main_default, 0);
	lv_style_set_pad_top(&style_prthome_cont0_main_main_default, 0);
	lv_style_set_pad_bottom(&style_prthome_cont0_main_main_default, 0);
	lv_obj_add_style(ui->prthome_cont0, &style_prthome_cont0_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prthome_cont3
	ui->prthome_cont3 = lv_obj_create(ui->prthome);
	lv_obj_set_pos(ui->prthome_cont3, 0, 117);
	lv_obj_set_size(ui->prthome_cont3, 480, 202);
	lv_obj_set_scrollbar_mode(ui->prthome_cont3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prthome_cont3_main_main_default
	static lv_style_t style_prthome_cont3_main_main_default;
	if (style_prthome_cont3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prthome_cont3_main_main_default);
	else
		lv_style_init(&style_prthome_cont3_main_main_default);
	lv_style_set_radius(&style_prthome_cont3_main_main_default, 0);
	lv_style_set_bg_color(&style_prthome_cont3_main_main_default, lv_color_make(0xde, 0xde, 0xde));
	lv_style_set_bg_grad_color(&style_prthome_cont3_main_main_default, lv_color_make(0xde, 0xde, 0xde));
	lv_style_set_bg_grad_dir(&style_prthome_cont3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prthome_cont3_main_main_default, 255);
	lv_style_set_shadow_width(&style_prthome_cont3_main_main_default, 0);
	lv_style_set_shadow_color(&style_prthome_cont3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prthome_cont3_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prthome_cont3_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prthome_cont3_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prthome_cont3_main_main_default, 0);
	lv_style_set_border_color(&style_prthome_cont3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_prthome_cont3_main_main_default, 0);
	lv_style_set_border_opa(&style_prthome_cont3_main_main_default, 255);
	lv_style_set_pad_left(&style_prthome_cont3_main_main_default, 0);
	lv_style_set_pad_right(&style_prthome_cont3_main_main_default, 0);
	lv_style_set_pad_top(&style_prthome_cont3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_prthome_cont3_main_main_default, 0);
	lv_obj_add_style(ui->prthome_cont3, &style_prthome_cont3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prthome_cont1
	ui->prthome_cont1 = lv_obj_create(ui->prthome);
	lv_obj_set_pos(ui->prthome_cont1, 40, 70);
	lv_obj_set_size(ui->prthome_cont1, 400, 164);
	lv_obj_set_scrollbar_mode(ui->prthome_cont1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prthome_cont1_main_main_default
	static lv_style_t style_prthome_cont1_main_main_default;
	if (style_prthome_cont1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prthome_cont1_main_main_default);
	else
		lv_style_init(&style_prthome_cont1_main_main_default);
	lv_style_set_radius(&style_prthome_cont1_main_main_default, 0);
	lv_style_set_bg_color(&style_prthome_cont1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_prthome_cont1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_prthome_cont1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prthome_cont1_main_main_default, 255);
	lv_style_set_shadow_width(&style_prthome_cont1_main_main_default, 0);
	lv_style_set_shadow_color(&style_prthome_cont1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prthome_cont1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prthome_cont1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prthome_cont1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prthome_cont1_main_main_default, 0);
	lv_style_set_border_color(&style_prthome_cont1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_prthome_cont1_main_main_default, 0);
	lv_style_set_border_opa(&style_prthome_cont1_main_main_default, 255);
	lv_style_set_pad_left(&style_prthome_cont1_main_main_default, 0);
	lv_style_set_pad_right(&style_prthome_cont1_main_main_default, 0);
	lv_style_set_pad_top(&style_prthome_cont1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_prthome_cont1_main_main_default, 0);
	lv_obj_add_style(ui->prthome_cont1, &style_prthome_cont1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prthome_label4
	ui->prthome_label4 = lv_label_create(ui->prthome);
	lv_obj_set_pos(ui->prthome_label4, 169, 18);
	lv_obj_set_size(ui->prthome_label4, 137, 35);
	lv_obj_set_scrollbar_mode(ui->prthome_label4, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->prthome_label4, "PRINT MENU");
	lv_label_set_long_mode(ui->prthome_label4, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_prthome_label4_main_main_default
	static lv_style_t style_prthome_label4_main_main_default;
	if (style_prthome_label4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prthome_label4_main_main_default);
	else
		lv_style_init(&style_prthome_label4_main_main_default);
	lv_style_set_radius(&style_prthome_label4_main_main_default, 0);
	lv_style_set_bg_color(&style_prthome_label4_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_prthome_label4_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_prthome_label4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prthome_label4_main_main_default, 0);
	lv_style_set_shadow_width(&style_prthome_label4_main_main_default, 0);
	lv_style_set_shadow_color(&style_prthome_label4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prthome_label4_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prthome_label4_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prthome_label4_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prthome_label4_main_main_default, 0);
	lv_style_set_text_color(&style_prthome_label4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prthome_label4_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_prthome_label4_main_main_default, 2);
	lv_style_set_text_line_space(&style_prthome_label4_main_main_default, 0);
	lv_style_set_text_align(&style_prthome_label4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_prthome_label4_main_main_default, 0);
	lv_style_set_pad_right(&style_prthome_label4_main_main_default, 0);
	lv_style_set_pad_top(&style_prthome_label4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_prthome_label4_main_main_default, 0);
	lv_obj_add_style(ui->prthome_label4, &style_prthome_label4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prthome_imgbtnit
	ui->prthome_imgbtnit = lv_imgbtn_create(ui->prthome);
	lv_obj_set_pos(ui->prthome_imgbtnit, 325, 70);
	lv_obj_set_size(ui->prthome_imgbtnit, 115, 164);
	lv_obj_set_scrollbar_mode(ui->prthome_imgbtnit, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prthome_imgbtnit_main_main_default
	static lv_style_t style_prthome_imgbtnit_main_main_default;
	if (style_prthome_imgbtnit_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prthome_imgbtnit_main_main_default);
	else
		lv_style_init(&style_prthome_imgbtnit_main_main_default);
	lv_style_set_shadow_width(&style_prthome_imgbtnit_main_main_default, 0);
	lv_style_set_shadow_color(&style_prthome_imgbtnit_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prthome_imgbtnit_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prthome_imgbtnit_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prthome_imgbtnit_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prthome_imgbtnit_main_main_default, 0);
	lv_style_set_text_color(&style_prthome_imgbtnit_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_prthome_imgbtnit_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_prthome_imgbtnit_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_prthome_imgbtnit_main_main_default, 0);
	lv_style_set_img_opa(&style_prthome_imgbtnit_main_main_default, 255);
	lv_obj_add_style(ui->prthome_imgbtnit, &style_prthome_imgbtnit_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_prthome_imgbtnit_main_main_pressed
	static lv_style_t style_prthome_imgbtnit_main_main_pressed;
	if (style_prthome_imgbtnit_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_prthome_imgbtnit_main_main_pressed);
	else
		lv_style_init(&style_prthome_imgbtnit_main_main_pressed);
	lv_style_set_shadow_width(&style_prthome_imgbtnit_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_prthome_imgbtnit_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prthome_imgbtnit_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_prthome_imgbtnit_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_prthome_imgbtnit_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_prthome_imgbtnit_main_main_pressed, 0);
	lv_style_set_text_color(&style_prthome_imgbtnit_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_prthome_imgbtnit_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_prthome_imgbtnit_main_main_pressed, 0);
	lv_style_set_img_opa(&style_prthome_imgbtnit_main_main_pressed, 255);
	lv_obj_add_style(ui->prthome_imgbtnit, &style_prthome_imgbtnit_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_prthome_imgbtnit_main_main_checked
	static lv_style_t style_prthome_imgbtnit_main_main_checked;
	if (style_prthome_imgbtnit_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_prthome_imgbtnit_main_main_checked);
	else
		lv_style_init(&style_prthome_imgbtnit_main_main_checked);
	lv_style_set_shadow_width(&style_prthome_imgbtnit_main_main_checked, 0);
	lv_style_set_shadow_color(&style_prthome_imgbtnit_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prthome_imgbtnit_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_prthome_imgbtnit_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_prthome_imgbtnit_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_prthome_imgbtnit_main_main_checked, 0);
	lv_style_set_text_color(&style_prthome_imgbtnit_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_prthome_imgbtnit_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_prthome_imgbtnit_main_main_checked, 0);
	lv_style_set_img_opa(&style_prthome_imgbtnit_main_main_checked, 255);
	lv_obj_add_style(ui->prthome_imgbtnit, &style_prthome_imgbtnit_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->prthome_imgbtnit, LV_IMGBTN_STATE_RELEASED, NULL, &_btn4_alpha_115x164, NULL);
	lv_imgbtn_set_src(ui->prthome_imgbtnit, LV_IMGBTN_STATE_PRESSED, NULL, &_btn4_alpha_115x164, NULL);
	lv_imgbtn_set_src(ui->prthome_imgbtnit, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_btn4_alpha_115x164, NULL);
	lv_imgbtn_set_src(ui->prthome_imgbtnit, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_btn4_alpha_115x164, NULL);

	//Write codes prthome_imgbtnusb
	ui->prthome_imgbtnusb = lv_imgbtn_create(ui->prthome);
	lv_obj_set_pos(ui->prthome_imgbtnusb, 40, 70);
	lv_obj_set_size(ui->prthome_imgbtnusb, 115, 164);
	lv_obj_set_scrollbar_mode(ui->prthome_imgbtnusb, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prthome_imgbtnusb_main_main_default
	static lv_style_t style_prthome_imgbtnusb_main_main_default;
	if (style_prthome_imgbtnusb_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prthome_imgbtnusb_main_main_default);
	else
		lv_style_init(&style_prthome_imgbtnusb_main_main_default);
	lv_style_set_shadow_width(&style_prthome_imgbtnusb_main_main_default, 0);
	lv_style_set_shadow_color(&style_prthome_imgbtnusb_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prthome_imgbtnusb_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prthome_imgbtnusb_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prthome_imgbtnusb_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prthome_imgbtnusb_main_main_default, 0);
	lv_style_set_text_color(&style_prthome_imgbtnusb_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_prthome_imgbtnusb_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_prthome_imgbtnusb_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_prthome_imgbtnusb_main_main_default, 0);
	lv_style_set_img_opa(&style_prthome_imgbtnusb_main_main_default, 255);
	lv_obj_add_style(ui->prthome_imgbtnusb, &style_prthome_imgbtnusb_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_prthome_imgbtnusb_main_main_pressed
	static lv_style_t style_prthome_imgbtnusb_main_main_pressed;
	if (style_prthome_imgbtnusb_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_prthome_imgbtnusb_main_main_pressed);
	else
		lv_style_init(&style_prthome_imgbtnusb_main_main_pressed);
	lv_style_set_shadow_width(&style_prthome_imgbtnusb_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_prthome_imgbtnusb_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prthome_imgbtnusb_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_prthome_imgbtnusb_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_prthome_imgbtnusb_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_prthome_imgbtnusb_main_main_pressed, 0);
	lv_style_set_text_color(&style_prthome_imgbtnusb_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_prthome_imgbtnusb_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_prthome_imgbtnusb_main_main_pressed, 0);
	lv_style_set_img_opa(&style_prthome_imgbtnusb_main_main_pressed, 255);
	lv_obj_add_style(ui->prthome_imgbtnusb, &style_prthome_imgbtnusb_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_prthome_imgbtnusb_main_main_checked
	static lv_style_t style_prthome_imgbtnusb_main_main_checked;
	if (style_prthome_imgbtnusb_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_prthome_imgbtnusb_main_main_checked);
	else
		lv_style_init(&style_prthome_imgbtnusb_main_main_checked);
	lv_style_set_shadow_width(&style_prthome_imgbtnusb_main_main_checked, 0);
	lv_style_set_shadow_color(&style_prthome_imgbtnusb_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prthome_imgbtnusb_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_prthome_imgbtnusb_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_prthome_imgbtnusb_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_prthome_imgbtnusb_main_main_checked, 0);
	lv_style_set_text_color(&style_prthome_imgbtnusb_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_prthome_imgbtnusb_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_prthome_imgbtnusb_main_main_checked, 0);
	lv_style_set_img_opa(&style_prthome_imgbtnusb_main_main_checked, 255);
	lv_obj_add_style(ui->prthome_imgbtnusb, &style_prthome_imgbtnusb_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->prthome_imgbtnusb, LV_IMGBTN_STATE_RELEASED, NULL, &_btn2_alpha_115x164, NULL);
	lv_imgbtn_set_src(ui->prthome_imgbtnusb, LV_IMGBTN_STATE_PRESSED, NULL, &_btn2_alpha_115x164, NULL);
	lv_imgbtn_set_src(ui->prthome_imgbtnusb, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_btn2_alpha_115x164, NULL);
	lv_imgbtn_set_src(ui->prthome_imgbtnusb, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_btn2_alpha_115x164, NULL);

	//Write codes prthome_imgbtnmobile
	ui->prthome_imgbtnmobile = lv_imgbtn_create(ui->prthome);
	lv_obj_set_pos(ui->prthome_imgbtnmobile, 183, 70);
	lv_obj_set_size(ui->prthome_imgbtnmobile, 115, 164);
	lv_obj_set_scrollbar_mode(ui->prthome_imgbtnmobile, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prthome_imgbtnmobile_main_main_default
	static lv_style_t style_prthome_imgbtnmobile_main_main_default;
	if (style_prthome_imgbtnmobile_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prthome_imgbtnmobile_main_main_default);
	else
		lv_style_init(&style_prthome_imgbtnmobile_main_main_default);
	lv_style_set_shadow_width(&style_prthome_imgbtnmobile_main_main_default, 0);
	lv_style_set_shadow_color(&style_prthome_imgbtnmobile_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prthome_imgbtnmobile_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prthome_imgbtnmobile_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prthome_imgbtnmobile_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prthome_imgbtnmobile_main_main_default, 0);
	lv_style_set_text_color(&style_prthome_imgbtnmobile_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_prthome_imgbtnmobile_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_prthome_imgbtnmobile_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_prthome_imgbtnmobile_main_main_default, 0);
	lv_style_set_img_opa(&style_prthome_imgbtnmobile_main_main_default, 255);
	lv_obj_add_style(ui->prthome_imgbtnmobile, &style_prthome_imgbtnmobile_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_prthome_imgbtnmobile_main_main_pressed
	static lv_style_t style_prthome_imgbtnmobile_main_main_pressed;
	if (style_prthome_imgbtnmobile_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_prthome_imgbtnmobile_main_main_pressed);
	else
		lv_style_init(&style_prthome_imgbtnmobile_main_main_pressed);
	lv_style_set_shadow_width(&style_prthome_imgbtnmobile_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_prthome_imgbtnmobile_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prthome_imgbtnmobile_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_prthome_imgbtnmobile_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_prthome_imgbtnmobile_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_prthome_imgbtnmobile_main_main_pressed, 0);
	lv_style_set_text_color(&style_prthome_imgbtnmobile_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_prthome_imgbtnmobile_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_prthome_imgbtnmobile_main_main_pressed, 0);
	lv_style_set_img_opa(&style_prthome_imgbtnmobile_main_main_pressed, 255);
	lv_obj_add_style(ui->prthome_imgbtnmobile, &style_prthome_imgbtnmobile_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_prthome_imgbtnmobile_main_main_checked
	static lv_style_t style_prthome_imgbtnmobile_main_main_checked;
	if (style_prthome_imgbtnmobile_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_prthome_imgbtnmobile_main_main_checked);
	else
		lv_style_init(&style_prthome_imgbtnmobile_main_main_checked);
	lv_style_set_shadow_width(&style_prthome_imgbtnmobile_main_main_checked, 0);
	lv_style_set_shadow_color(&style_prthome_imgbtnmobile_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prthome_imgbtnmobile_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_prthome_imgbtnmobile_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_prthome_imgbtnmobile_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_prthome_imgbtnmobile_main_main_checked, 0);
	lv_style_set_text_color(&style_prthome_imgbtnmobile_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_prthome_imgbtnmobile_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_prthome_imgbtnmobile_main_main_checked, 0);
	lv_style_set_img_opa(&style_prthome_imgbtnmobile_main_main_checked, 255);
	lv_obj_add_style(ui->prthome_imgbtnmobile, &style_prthome_imgbtnmobile_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->prthome_imgbtnmobile, LV_IMGBTN_STATE_RELEASED, NULL, &_btn3_alpha_115x164, NULL);
	lv_imgbtn_set_src(ui->prthome_imgbtnmobile, LV_IMGBTN_STATE_PRESSED, NULL, &_btn3_alpha_115x164, NULL);
	lv_imgbtn_set_src(ui->prthome_imgbtnmobile, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_btn3_alpha_115x164, NULL);
	lv_imgbtn_set_src(ui->prthome_imgbtnmobile, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_btn3_alpha_115x164, NULL);

	//Write codes prthome_labelusb
	ui->prthome_labelusb = lv_label_create(ui->prthome);
	lv_obj_set_pos(ui->prthome_labelusb, 58, 188);
	lv_obj_set_size(ui->prthome_labelusb, 74, 23);
	lv_obj_set_scrollbar_mode(ui->prthome_labelusb, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->prthome_labelusb, "USB");
	lv_label_set_long_mode(ui->prthome_labelusb, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_prthome_labelusb_main_main_default
	static lv_style_t style_prthome_labelusb_main_main_default;
	if (style_prthome_labelusb_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prthome_labelusb_main_main_default);
	else
		lv_style_init(&style_prthome_labelusb_main_main_default);
	lv_style_set_radius(&style_prthome_labelusb_main_main_default, 0);
	lv_style_set_bg_color(&style_prthome_labelusb_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_prthome_labelusb_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_prthome_labelusb_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prthome_labelusb_main_main_default, 0);
	lv_style_set_shadow_width(&style_prthome_labelusb_main_main_default, 0);
	lv_style_set_shadow_color(&style_prthome_labelusb_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prthome_labelusb_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prthome_labelusb_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prthome_labelusb_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prthome_labelusb_main_main_default, 0);
	lv_style_set_text_color(&style_prthome_labelusb_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prthome_labelusb_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_prthome_labelusb_main_main_default, 2);
	lv_style_set_text_line_space(&style_prthome_labelusb_main_main_default, 0);
	lv_style_set_text_align(&style_prthome_labelusb_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_prthome_labelusb_main_main_default, 0);
	lv_style_set_pad_right(&style_prthome_labelusb_main_main_default, 0);
	lv_style_set_pad_top(&style_prthome_labelusb_main_main_default, 0);
	lv_style_set_pad_bottom(&style_prthome_labelusb_main_main_default, 0);
	lv_obj_add_style(ui->prthome_labelusb, &style_prthome_labelusb_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prthome_labelmobile
	ui->prthome_labelmobile = lv_label_create(ui->prthome);
	lv_obj_set_pos(ui->prthome_labelmobile, 198, 188);
	lv_obj_set_size(ui->prthome_labelmobile, 74, 23);
	lv_obj_set_scrollbar_mode(ui->prthome_labelmobile, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->prthome_labelmobile, "MOBILE");
	lv_label_set_long_mode(ui->prthome_labelmobile, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_prthome_labelmobile_main_main_default
	static lv_style_t style_prthome_labelmobile_main_main_default;
	if (style_prthome_labelmobile_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prthome_labelmobile_main_main_default);
	else
		lv_style_init(&style_prthome_labelmobile_main_main_default);
	lv_style_set_radius(&style_prthome_labelmobile_main_main_default, 0);
	lv_style_set_bg_color(&style_prthome_labelmobile_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_prthome_labelmobile_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_prthome_labelmobile_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prthome_labelmobile_main_main_default, 0);
	lv_style_set_shadow_width(&style_prthome_labelmobile_main_main_default, 0);
	lv_style_set_shadow_color(&style_prthome_labelmobile_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prthome_labelmobile_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prthome_labelmobile_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prthome_labelmobile_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prthome_labelmobile_main_main_default, 0);
	lv_style_set_text_color(&style_prthome_labelmobile_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prthome_labelmobile_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_prthome_labelmobile_main_main_default, 2);
	lv_style_set_text_line_space(&style_prthome_labelmobile_main_main_default, 0);
	lv_style_set_text_align(&style_prthome_labelmobile_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_prthome_labelmobile_main_main_default, 0);
	lv_style_set_pad_right(&style_prthome_labelmobile_main_main_default, 0);
	lv_style_set_pad_top(&style_prthome_labelmobile_main_main_default, 0);
	lv_style_set_pad_bottom(&style_prthome_labelmobile_main_main_default, 0);
	lv_obj_add_style(ui->prthome_labelmobile, &style_prthome_labelmobile_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prthome_labelit
	ui->prthome_labelit = lv_label_create(ui->prthome);
	lv_obj_set_pos(ui->prthome_labelit, 340, 188);
	lv_obj_set_size(ui->prthome_labelit, 85, 23);
	lv_obj_set_scrollbar_mode(ui->prthome_labelit, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->prthome_labelit, "INTERNET");
	lv_label_set_long_mode(ui->prthome_labelit, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_prthome_labelit_main_main_default
	static lv_style_t style_prthome_labelit_main_main_default;
	if (style_prthome_labelit_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prthome_labelit_main_main_default);
	else
		lv_style_init(&style_prthome_labelit_main_main_default);
	lv_style_set_radius(&style_prthome_labelit_main_main_default, 0);
	lv_style_set_bg_color(&style_prthome_labelit_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_prthome_labelit_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_prthome_labelit_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prthome_labelit_main_main_default, 0);
	lv_style_set_shadow_width(&style_prthome_labelit_main_main_default, 0);
	lv_style_set_shadow_color(&style_prthome_labelit_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prthome_labelit_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prthome_labelit_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prthome_labelit_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prthome_labelit_main_main_default, 0);
	lv_style_set_text_color(&style_prthome_labelit_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prthome_labelit_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_prthome_labelit_main_main_default, 2);
	lv_style_set_text_line_space(&style_prthome_labelit_main_main_default, 0);
	lv_style_set_text_align(&style_prthome_labelit_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_prthome_labelit_main_main_default, 0);
	lv_style_set_pad_right(&style_prthome_labelit_main_main_default, 0);
	lv_style_set_pad_top(&style_prthome_labelit_main_main_default, 0);
	lv_style_set_pad_bottom(&style_prthome_labelit_main_main_default, 0);
	lv_obj_add_style(ui->prthome_labelit, &style_prthome_labelit_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prthome_label2
	ui->prthome_label2 = lv_label_create(ui->prthome);
	lv_obj_set_pos(ui->prthome_label2, 16, 256);
	lv_obj_set_size(ui->prthome_label2, 440, 35);
	lv_obj_set_scrollbar_mode(ui->prthome_label2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->prthome_label2, "From where do you want to print ?");
	lv_label_set_long_mode(ui->prthome_label2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_prthome_label2_main_main_default
	static lv_style_t style_prthome_label2_main_main_default;
	if (style_prthome_label2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prthome_label2_main_main_default);
	else
		lv_style_init(&style_prthome_label2_main_main_default);
	lv_style_set_radius(&style_prthome_label2_main_main_default, 0);
	lv_style_set_bg_color(&style_prthome_label2_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_color(&style_prthome_label2_main_main_default, lv_color_make(0x4a, 0xb2, 0x41));
	lv_style_set_bg_grad_dir(&style_prthome_label2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prthome_label2_main_main_default, 0);
	lv_style_set_shadow_width(&style_prthome_label2_main_main_default, 0);
	lv_style_set_shadow_color(&style_prthome_label2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prthome_label2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_prthome_label2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prthome_label2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prthome_label2_main_main_default, 0);
	lv_style_set_text_color(&style_prthome_label2_main_main_default, lv_color_make(0x25, 0x1d, 0x1d));
	lv_style_set_text_font(&style_prthome_label2_main_main_default, &lv_font_arial_16);
	lv_style_set_text_letter_space(&style_prthome_label2_main_main_default, 2);
	lv_style_set_text_line_space(&style_prthome_label2_main_main_default, 0);
	lv_style_set_text_align(&style_prthome_label2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_prthome_label2_main_main_default, 0);
	lv_style_set_pad_right(&style_prthome_label2_main_main_default, 0);
	lv_style_set_pad_top(&style_prthome_label2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_prthome_label2_main_main_default, 0);
	lv_obj_add_style(ui->prthome_label2, &style_prthome_label2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prthome_usb
	ui->prthome_usb = lv_img_create(ui->prthome);
	lv_obj_set_pos(ui->prthome_usb, 100, 100);
	lv_obj_set_size(ui->prthome_usb, 30, 35);
	lv_obj_set_scrollbar_mode(ui->prthome_usb, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prthome_usb_main_main_default
	static lv_style_t style_prthome_usb_main_main_default;
	if (style_prthome_usb_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prthome_usb_main_main_default);
	else
		lv_style_init(&style_prthome_usb_main_main_default);
	lv_style_set_img_recolor(&style_prthome_usb_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_prthome_usb_main_main_default, 0);
	lv_style_set_img_opa(&style_prthome_usb_main_main_default, 255);
	lv_obj_add_style(ui->prthome_usb, &style_prthome_usb_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->prthome_usb, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->prthome_usb,&_usb_30x35);
	lv_img_set_pivot(ui->prthome_usb, 0,0);
	lv_img_set_angle(ui->prthome_usb, 0);

	//Write codes prthome_mobile
	ui->prthome_mobile = lv_img_create(ui->prthome);
	lv_obj_set_pos(ui->prthome_mobile, 242, 100);
	lv_obj_set_size(ui->prthome_mobile, 30, 35);
	lv_obj_set_scrollbar_mode(ui->prthome_mobile, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prthome_mobile_main_main_default
	static lv_style_t style_prthome_mobile_main_main_default;
	if (style_prthome_mobile_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prthome_mobile_main_main_default);
	else
		lv_style_init(&style_prthome_mobile_main_main_default);
	lv_style_set_img_recolor(&style_prthome_mobile_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_prthome_mobile_main_main_default, 0);
	lv_style_set_img_opa(&style_prthome_mobile_main_main_default, 255);
	lv_obj_add_style(ui->prthome_mobile, &style_prthome_mobile_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->prthome_mobile, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->prthome_mobile,&_mobile_30x35);
	lv_img_set_pivot(ui->prthome_mobile, 0,0);
	lv_img_set_angle(ui->prthome_mobile, 0);

	//Write codes prthome_internet
	ui->prthome_internet = lv_img_create(ui->prthome);
	lv_obj_set_pos(ui->prthome_internet, 383, 100);
	lv_obj_set_size(ui->prthome_internet, 30, 35);
	lv_obj_set_scrollbar_mode(ui->prthome_internet, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prthome_internet_main_main_default
	static lv_style_t style_prthome_internet_main_main_default;
	if (style_prthome_internet_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prthome_internet_main_main_default);
	else
		lv_style_init(&style_prthome_internet_main_main_default);
	lv_style_set_img_recolor(&style_prthome_internet_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_prthome_internet_main_main_default, 0);
	lv_style_set_img_opa(&style_prthome_internet_main_main_default, 255);
	lv_obj_add_style(ui->prthome_internet, &style_prthome_internet_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->prthome_internet, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->prthome_internet,&_internet_30x35);
	lv_img_set_pivot(ui->prthome_internet, 0,0);
	lv_img_set_angle(ui->prthome_internet, 0);

	//Write codes prthome_btnprintback
	ui->prthome_btnprintback = lv_btn_create(ui->prthome);
	lv_obj_set_pos(ui->prthome_btnprintback, 50, 15);
	lv_obj_set_size(ui->prthome_btnprintback, 30, 35);
	lv_obj_set_scrollbar_mode(ui->prthome_btnprintback, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_prthome_btnprintback_main_main_default
	static lv_style_t style_prthome_btnprintback_main_main_default;
	if (style_prthome_btnprintback_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_prthome_btnprintback_main_main_default);
	else
		lv_style_init(&style_prthome_btnprintback_main_main_default);
	lv_style_set_radius(&style_prthome_btnprintback_main_main_default, 50);
	lv_style_set_bg_color(&style_prthome_btnprintback_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_prthome_btnprintback_main_main_default, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_prthome_btnprintback_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prthome_btnprintback_main_main_default, 255);
	lv_style_set_shadow_width(&style_prthome_btnprintback_main_main_default, 0);
	lv_style_set_shadow_color(&style_prthome_btnprintback_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_prthome_btnprintback_main_main_default, 0);
	lv_style_set_shadow_spread(&style_prthome_btnprintback_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_prthome_btnprintback_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_prthome_btnprintback_main_main_default, 0);
	lv_style_set_border_color(&style_prthome_btnprintback_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_prthome_btnprintback_main_main_default, 0);
	lv_style_set_border_opa(&style_prthome_btnprintback_main_main_default, 255);
	lv_style_set_text_color(&style_prthome_btnprintback_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_prthome_btnprintback_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_align(&style_prthome_btnprintback_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->prthome_btnprintback, &style_prthome_btnprintback_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->prthome_btnprintback_label = lv_label_create(ui->prthome_btnprintback);
	lv_label_set_text(ui->prthome_btnprintback_label, "<");
	lv_obj_set_style_pad_all(ui->prthome_btnprintback, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->prthome_btnprintback_label, LV_ALIGN_CENTER, 0, 0);
}