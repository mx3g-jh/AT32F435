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

static lv_obj_t * g_kb_copyhome;
static void kb_copyhome_event_cb(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *kb = lv_event_get_target(e);
	if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL){
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}
__attribute__((unused)) static void ta_copyhome_event_cb(lv_event_t *e)
{

	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *ta = lv_event_get_target(e);
	lv_obj_t *kb = lv_event_get_user_data(e);
	if (code == LV_EVENT_FOCUSED || code == LV_EVENT_CLICKED)
	{
		lv_keyboard_set_textarea(kb, ta);
		lv_obj_move_foreground(kb);
		lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
	if (code == LV_EVENT_CANCEL || code == LV_EVENT_DEFOCUSED)
	{
		lv_keyboard_set_textarea(kb, NULL);
		lv_obj_move_background(kb);
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}

void setup_scr_copyhome(lv_ui *ui){

	//Write codes copyhome
	ui->copyhome = lv_obj_create(NULL);

	//Create keyboard on copyhome
	g_kb_copyhome = lv_keyboard_create(ui->copyhome);
	lv_obj_add_event_cb(g_kb_copyhome, kb_copyhome_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(g_kb_copyhome, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_style_text_font(g_kb_copyhome, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_scrollbar_mode(ui->copyhome, LV_SCROLLBAR_MODE_OFF);

	//Set style for copyhome. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_bg_color(ui->copyhome, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->copyhome, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->copyhome, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->copyhome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes copyhome_cont1
	ui->copyhome_cont1 = lv_obj_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_cont1, 0, 0);
	lv_obj_set_size(ui->copyhome_cont1, 240, 88);
	lv_obj_set_scrollbar_mode(ui->copyhome_cont1, LV_SCROLLBAR_MODE_OFF);

	//Set style for copyhome_cont1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->copyhome_cont1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->copyhome_cont1, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->copyhome_cont1, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->copyhome_cont1, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->copyhome_cont1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->copyhome_cont1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->copyhome_cont1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->copyhome_cont1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->copyhome_cont1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->copyhome_cont1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->copyhome_cont1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->copyhome_cont1, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->copyhome_cont1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->copyhome_cont1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->copyhome_cont1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->copyhome_cont1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->copyhome_cont1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->copyhome_cont1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes copyhome_cont2
	ui->copyhome_cont2 = lv_obj_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_cont2, 0, 88);
	lv_obj_set_size(ui->copyhome_cont2, 240, 151);
	lv_obj_set_scrollbar_mode(ui->copyhome_cont2, LV_SCROLLBAR_MODE_OFF);

	//Set style for copyhome_cont2. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->copyhome_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->copyhome_cont2, lv_color_make(0xde, 0xde, 0xde), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->copyhome_cont2, lv_color_make(0xde, 0xde, 0xde), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->copyhome_cont2, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->copyhome_cont2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->copyhome_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->copyhome_cont2, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->copyhome_cont2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->copyhome_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->copyhome_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->copyhome_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->copyhome_cont2, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->copyhome_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->copyhome_cont2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->copyhome_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->copyhome_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->copyhome_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->copyhome_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes copyhome_label1
	ui->copyhome_label1 = lv_label_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_label1, 68, 26);
	lv_obj_set_size(ui->copyhome_label1, 112, 17);
	lv_obj_set_scrollbar_mode(ui->copyhome_label1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->copyhome_label1, "ADJUST IMAGE");
	lv_label_set_long_mode(ui->copyhome_label1, LV_LABEL_LONG_WRAP);

	//Set style for copyhome_label1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->copyhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->copyhome_label1, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->copyhome_label1, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->copyhome_label1, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->copyhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->copyhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->copyhome_label1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->copyhome_label1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->copyhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->copyhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->copyhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->copyhome_label1, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->copyhome_label1, &lv_font_arial_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->copyhome_label1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->copyhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->copyhome_label1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->copyhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->copyhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->copyhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->copyhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes copyhome_img3
	ui->copyhome_img3 = lv_img_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_img3, 13, 66);
	lv_obj_set_size(ui->copyhome_img3, 150, 151);
	lv_obj_set_scrollbar_mode(ui->copyhome_img3, LV_SCROLLBAR_MODE_OFF);

	//Set style for copyhome_img3. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->copyhome_img3, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->copyhome_img3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->copyhome_img3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->copyhome_img3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->copyhome_img3,&_example_alpha_150x151);
	lv_img_set_pivot(ui->copyhome_img3, 0,0);
	lv_img_set_angle(ui->copyhome_img3, 0);

	//Write codes copyhome_cont4
	ui->copyhome_cont4 = lv_obj_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_cont4, 184, 70);
	lv_obj_set_size(ui->copyhome_cont4, 40, 114);
	lv_obj_set_scrollbar_mode(ui->copyhome_cont4, LV_SCROLLBAR_MODE_OFF);

	//Set style for copyhome_cont4. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->copyhome_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->copyhome_cont4, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->copyhome_cont4, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->copyhome_cont4, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->copyhome_cont4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->copyhome_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->copyhome_cont4, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->copyhome_cont4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->copyhome_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->copyhome_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->copyhome_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->copyhome_cont4, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->copyhome_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->copyhome_cont4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->copyhome_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->copyhome_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->copyhome_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->copyhome_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes copyhome_btncopynext
	ui->copyhome_btncopynext = lv_btn_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_btncopynext, 184, 195);
	lv_obj_set_size(ui->copyhome_btncopynext, 40, 35);
	lv_obj_set_scrollbar_mode(ui->copyhome_btncopynext, LV_SCROLLBAR_MODE_OFF);

	//Set style for copyhome_btncopynext. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->copyhome_btncopynext, 44, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->copyhome_btncopynext, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->copyhome_btncopynext, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->copyhome_btncopynext, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->copyhome_btncopynext, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->copyhome_btncopynext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->copyhome_btncopynext, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->copyhome_btncopynext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->copyhome_btncopynext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->copyhome_btncopynext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->copyhome_btncopynext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->copyhome_btncopynext, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->copyhome_btncopynext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->copyhome_btncopynext, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->copyhome_btncopynext, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->copyhome_btncopynext, &lv_font_simsun_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->copyhome_btncopynext, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->copyhome_btncopynext_label = lv_label_create(ui->copyhome_btncopynext);
	lv_label_set_text(ui->copyhome_btncopynext_label, "NEXT");
	lv_obj_set_style_pad_all(ui->copyhome_btncopynext, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->copyhome_btncopynext_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes copyhome_sliderhue
	ui->copyhome_sliderhue = lv_slider_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_sliderhue, 210, 101);
	lv_obj_set_size(ui->copyhome_sliderhue, 4, 70);
	lv_obj_set_scrollbar_mode(ui->copyhome_sliderhue, LV_SCROLLBAR_MODE_OFF);

	//Set style for copyhome_sliderhue. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->copyhome_sliderhue, 44, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->copyhome_sliderhue, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->copyhome_sliderhue, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->copyhome_sliderhue, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->copyhome_sliderhue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->copyhome_sliderhue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->copyhome_sliderhue, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->copyhome_sliderhue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->copyhome_sliderhue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->copyhome_sliderhue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->copyhome_sliderhue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_color(ui->copyhome_sliderhue, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->copyhome_sliderhue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_opa(ui->copyhome_sliderhue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for copyhome_sliderhue. Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->copyhome_sliderhue, 44, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->copyhome_sliderhue, lv_color_make(0xd4, 0xd7, 0xd9), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->copyhome_sliderhue, lv_color_make(0xdd, 0xd7, 0xd9), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->copyhome_sliderhue, LV_GRAD_DIR_VER, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->copyhome_sliderhue, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Set style for copyhome_sliderhue. Part: LV_PART_KNOB, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->copyhome_sliderhue, 44, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->copyhome_sliderhue, lv_color_make(0x29, 0x30, 0x41), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->copyhome_sliderhue, lv_color_make(0x29, 0x30, 0x41), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->copyhome_sliderhue, LV_GRAD_DIR_VER, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->copyhome_sliderhue, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_slider_set_range(ui->copyhome_sliderhue,0, 100);
	lv_slider_set_value(ui->copyhome_sliderhue,50,false);

	//Write codes copyhome_sliderbright
	ui->copyhome_sliderbright = lv_slider_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_sliderbright, 190, 101);
	lv_obj_set_size(ui->copyhome_sliderbright, 4, 70);
	lv_obj_set_scrollbar_mode(ui->copyhome_sliderbright, LV_SCROLLBAR_MODE_OFF);

	//Set style for copyhome_sliderbright. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->copyhome_sliderbright, 44, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->copyhome_sliderbright, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->copyhome_sliderbright, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->copyhome_sliderbright, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->copyhome_sliderbright, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->copyhome_sliderbright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->copyhome_sliderbright, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->copyhome_sliderbright, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->copyhome_sliderbright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->copyhome_sliderbright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->copyhome_sliderbright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_color(ui->copyhome_sliderbright, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->copyhome_sliderbright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_opa(ui->copyhome_sliderbright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for copyhome_sliderbright. Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->copyhome_sliderbright, 44, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->copyhome_sliderbright, lv_color_make(0xd4, 0xd7, 0xd9), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->copyhome_sliderbright, lv_color_make(0xdd, 0xd7, 0xd9), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->copyhome_sliderbright, LV_GRAD_DIR_VER, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->copyhome_sliderbright, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Set style for copyhome_sliderbright. Part: LV_PART_KNOB, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->copyhome_sliderbright, 44, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->copyhome_sliderbright, lv_color_make(0x29, 0x30, 0x41), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->copyhome_sliderbright, lv_color_make(0x29, 0x30, 0x41), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->copyhome_sliderbright, LV_GRAD_DIR_VER, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->copyhome_sliderbright, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_slider_set_range(ui->copyhome_sliderbright,0, 100);
	lv_slider_set_value(ui->copyhome_sliderbright,50,false);

	//Write codes copyhome_bright
	ui->copyhome_bright = lv_img_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_bright, 186, 72);
	lv_obj_set_size(ui->copyhome_bright, 12, 12);
	lv_obj_set_scrollbar_mode(ui->copyhome_bright, LV_SCROLLBAR_MODE_OFF);

	//Set style for copyhome_bright. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->copyhome_bright, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->copyhome_bright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->copyhome_bright, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->copyhome_bright, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->copyhome_bright,&_bright_alpha_12x12);
	lv_img_set_pivot(ui->copyhome_bright, 0,0);
	lv_img_set_angle(ui->copyhome_bright, 0);

	//Write codes copyhome_hue
	ui->copyhome_hue = lv_img_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_hue, 206, 73);
	lv_obj_set_size(ui->copyhome_hue, 10, 10);
	lv_obj_set_scrollbar_mode(ui->copyhome_hue, LV_SCROLLBAR_MODE_OFF);

	//Set style for copyhome_hue. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->copyhome_hue, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->copyhome_hue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->copyhome_hue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->copyhome_hue, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->copyhome_hue,&_hue_alpha_10x10);
	lv_img_set_pivot(ui->copyhome_hue, 0,0);
	lv_img_set_angle(ui->copyhome_hue, 0);

	//Write codes copyhome_btncopyback
	ui->copyhome_btncopyback = lv_btn_create(ui->copyhome);
	lv_obj_set_pos(ui->copyhome_btncopyback, 25, 22);
	lv_obj_set_size(ui->copyhome_btncopyback, 15, 15);
	lv_obj_set_scrollbar_mode(ui->copyhome_btncopyback, LV_SCROLLBAR_MODE_OFF);

	//Set style for copyhome_btncopyback. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->copyhome_btncopyback, 44, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->copyhome_btncopyback, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->copyhome_btncopyback, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->copyhome_btncopyback, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->copyhome_btncopyback, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->copyhome_btncopyback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->copyhome_btncopyback, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->copyhome_btncopyback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->copyhome_btncopyback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->copyhome_btncopyback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->copyhome_btncopyback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->copyhome_btncopyback, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->copyhome_btncopyback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->copyhome_btncopyback, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->copyhome_btncopyback, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->copyhome_btncopyback, &lv_font_simsun_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->copyhome_btncopyback, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->copyhome_btncopyback_label = lv_label_create(ui->copyhome_btncopyback);
	lv_label_set_text(ui->copyhome_btncopyback_label, "<");
	lv_obj_set_style_pad_all(ui->copyhome_btncopyback, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->copyhome_btncopyback_label, LV_ALIGN_CENTER, 0, 0);
}