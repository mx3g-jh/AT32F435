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

static lv_obj_t * g_kb_scanhome;
static void kb_scanhome_event_cb(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *kb = lv_event_get_target(e);
	if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL){
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}
__attribute__((unused)) static void ta_scanhome_event_cb(lv_event_t *e)
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

void setup_scr_scanhome(lv_ui *ui){

	//Write codes scanhome
	ui->scanhome = lv_obj_create(NULL);

	//Create keyboard on scanhome
	g_kb_scanhome = lv_keyboard_create(ui->scanhome);
	lv_obj_add_event_cb(g_kb_scanhome, kb_scanhome_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(g_kb_scanhome, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_style_text_font(g_kb_scanhome, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_scrollbar_mode(ui->scanhome, LV_SCROLLBAR_MODE_OFF);

	//Set style for scanhome. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_bg_color(ui->scanhome, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->scanhome, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scanhome, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scanhome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scanhome_cont0
	ui->scanhome_cont0 = lv_obj_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_cont0, 0, 0);
	lv_obj_set_size(ui->scanhome_cont0, 240, 88);
	lv_obj_set_scrollbar_mode(ui->scanhome_cont0, LV_SCROLLBAR_MODE_OFF);

	//Set style for scanhome_cont0. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->scanhome_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scanhome_cont0, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->scanhome_cont0, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scanhome_cont0, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scanhome_cont0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scanhome_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->scanhome_cont0, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->scanhome_cont0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->scanhome_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->scanhome_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->scanhome_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->scanhome_cont0, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scanhome_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->scanhome_cont0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scanhome_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scanhome_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scanhome_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scanhome_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scanhome_label1
	ui->scanhome_label1 = lv_label_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_label1, 68, 26);
	lv_obj_set_size(ui->scanhome_label1, 112, 17);
	lv_obj_set_scrollbar_mode(ui->scanhome_label1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->scanhome_label1, "ADJUST IMAGE");
	lv_label_set_long_mode(ui->scanhome_label1, LV_LABEL_LONG_WRAP);

	//Set style for scanhome_label1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->scanhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scanhome_label1, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->scanhome_label1, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scanhome_label1, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scanhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scanhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->scanhome_label1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->scanhome_label1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->scanhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->scanhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->scanhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scanhome_label1, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scanhome_label1, &lv_font_arial_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->scanhome_label1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->scanhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scanhome_label1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scanhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scanhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scanhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scanhome_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scanhome_cont2
	ui->scanhome_cont2 = lv_obj_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_cont2, 0, 88);
	lv_obj_set_size(ui->scanhome_cont2, 240, 151);
	lv_obj_set_scrollbar_mode(ui->scanhome_cont2, LV_SCROLLBAR_MODE_OFF);

	//Set style for scanhome_cont2. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->scanhome_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scanhome_cont2, lv_color_make(0xde, 0xde, 0xde), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->scanhome_cont2, lv_color_make(0xde, 0xde, 0xde), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scanhome_cont2, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scanhome_cont2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scanhome_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->scanhome_cont2, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->scanhome_cont2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->scanhome_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->scanhome_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->scanhome_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->scanhome_cont2, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scanhome_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->scanhome_cont2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scanhome_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scanhome_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scanhome_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scanhome_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scanhome_img3
	ui->scanhome_img3 = lv_img_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_img3, 13, 66);
	lv_obj_set_size(ui->scanhome_img3, 150, 151);
	lv_obj_set_scrollbar_mode(ui->scanhome_img3, LV_SCROLLBAR_MODE_OFF);

	//Set style for scanhome_img3. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->scanhome_img3, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->scanhome_img3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scanhome_img3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->scanhome_img3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scanhome_img3,&_example_alpha_150x151);
	lv_img_set_pivot(ui->scanhome_img3, 0,0);
	lv_img_set_angle(ui->scanhome_img3, 0);

	//Write codes scanhome_cont4
	ui->scanhome_cont4 = lv_obj_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_cont4, 184, 70);
	lv_obj_set_size(ui->scanhome_cont4, 40, 114);
	lv_obj_set_scrollbar_mode(ui->scanhome_cont4, LV_SCROLLBAR_MODE_OFF);

	//Set style for scanhome_cont4. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->scanhome_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scanhome_cont4, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->scanhome_cont4, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scanhome_cont4, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scanhome_cont4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scanhome_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->scanhome_cont4, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->scanhome_cont4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->scanhome_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->scanhome_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->scanhome_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->scanhome_cont4, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scanhome_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->scanhome_cont4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->scanhome_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->scanhome_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->scanhome_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->scanhome_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scanhome_btnscansave
	ui->scanhome_btnscansave = lv_btn_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_btnscansave, 184, 195);
	lv_obj_set_size(ui->scanhome_btnscansave, 40, 35);
	lv_obj_set_scrollbar_mode(ui->scanhome_btnscansave, LV_SCROLLBAR_MODE_OFF);

	//Set style for scanhome_btnscansave. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->scanhome_btnscansave, 44, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scanhome_btnscansave, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->scanhome_btnscansave, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scanhome_btnscansave, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scanhome_btnscansave, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scanhome_btnscansave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->scanhome_btnscansave, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->scanhome_btnscansave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->scanhome_btnscansave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->scanhome_btnscansave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->scanhome_btnscansave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->scanhome_btnscansave, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scanhome_btnscansave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->scanhome_btnscansave, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scanhome_btnscansave, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scanhome_btnscansave, &lv_font_simsun_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scanhome_btnscansave, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->scanhome_btnscansave_label = lv_label_create(ui->scanhome_btnscansave);
	lv_label_set_text(ui->scanhome_btnscansave_label, "SAVE");
	lv_obj_set_style_pad_all(ui->scanhome_btnscansave, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->scanhome_btnscansave_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes scanhome_sliderhue
	ui->scanhome_sliderhue = lv_slider_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_sliderhue, 210, 101);
	lv_obj_set_size(ui->scanhome_sliderhue, 4, 70);
	lv_obj_set_scrollbar_mode(ui->scanhome_sliderhue, LV_SCROLLBAR_MODE_OFF);

	//Set style for scanhome_sliderhue. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->scanhome_sliderhue, 44, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scanhome_sliderhue, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->scanhome_sliderhue, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scanhome_sliderhue, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scanhome_sliderhue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scanhome_sliderhue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->scanhome_sliderhue, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->scanhome_sliderhue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->scanhome_sliderhue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->scanhome_sliderhue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->scanhome_sliderhue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_color(ui->scanhome_sliderhue, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->scanhome_sliderhue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_opa(ui->scanhome_sliderhue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for scanhome_sliderhue. Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->scanhome_sliderhue, 44, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scanhome_sliderhue, lv_color_make(0xd4, 0xd7, 0xd9), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->scanhome_sliderhue, lv_color_make(0xdd, 0xd7, 0xd9), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scanhome_sliderhue, LV_GRAD_DIR_VER, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scanhome_sliderhue, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Set style for scanhome_sliderhue. Part: LV_PART_KNOB, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->scanhome_sliderhue, 44, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scanhome_sliderhue, lv_color_make(0x29, 0x30, 0x41), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->scanhome_sliderhue, lv_color_make(0x29, 0x30, 0x41), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scanhome_sliderhue, LV_GRAD_DIR_VER, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scanhome_sliderhue, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_slider_set_range(ui->scanhome_sliderhue,0, 100);
	lv_slider_set_value(ui->scanhome_sliderhue,50,false);

	//Write codes scanhome_sliderbright
	ui->scanhome_sliderbright = lv_slider_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_sliderbright, 190, 101);
	lv_obj_set_size(ui->scanhome_sliderbright, 4, 70);
	lv_obj_set_scrollbar_mode(ui->scanhome_sliderbright, LV_SCROLLBAR_MODE_OFF);

	//Set style for scanhome_sliderbright. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->scanhome_sliderbright, 44, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scanhome_sliderbright, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->scanhome_sliderbright, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scanhome_sliderbright, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scanhome_sliderbright, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scanhome_sliderbright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->scanhome_sliderbright, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->scanhome_sliderbright, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->scanhome_sliderbright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->scanhome_sliderbright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->scanhome_sliderbright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_color(ui->scanhome_sliderbright, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->scanhome_sliderbright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_opa(ui->scanhome_sliderbright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for scanhome_sliderbright. Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->scanhome_sliderbright, 44, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scanhome_sliderbright, lv_color_make(0xd4, 0xd7, 0xd9), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->scanhome_sliderbright, lv_color_make(0xdd, 0xd7, 0xd9), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scanhome_sliderbright, LV_GRAD_DIR_VER, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scanhome_sliderbright, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Set style for scanhome_sliderbright. Part: LV_PART_KNOB, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->scanhome_sliderbright, 44, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scanhome_sliderbright, lv_color_make(0x29, 0x30, 0x41), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->scanhome_sliderbright, lv_color_make(0x29, 0x30, 0x41), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scanhome_sliderbright, LV_GRAD_DIR_VER, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scanhome_sliderbright, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_slider_set_range(ui->scanhome_sliderbright,0, 100);
	lv_slider_set_value(ui->scanhome_sliderbright,50,false);

	//Write codes scanhome_bright
	ui->scanhome_bright = lv_img_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_bright, 186, 72);
	lv_obj_set_size(ui->scanhome_bright, 12, 12);
	lv_obj_set_scrollbar_mode(ui->scanhome_bright, LV_SCROLLBAR_MODE_OFF);

	//Set style for scanhome_bright. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->scanhome_bright, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->scanhome_bright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scanhome_bright, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->scanhome_bright, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scanhome_bright,&_bright_alpha_12x12);
	lv_img_set_pivot(ui->scanhome_bright, 0,0);
	lv_img_set_angle(ui->scanhome_bright, 0);

	//Write codes scanhome_hue
	ui->scanhome_hue = lv_img_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_hue, 206, 73);
	lv_obj_set_size(ui->scanhome_hue, 10, 10);
	lv_obj_set_scrollbar_mode(ui->scanhome_hue, LV_SCROLLBAR_MODE_OFF);

	//Set style for scanhome_hue. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->scanhome_hue, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->scanhome_hue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->scanhome_hue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->scanhome_hue, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scanhome_hue,&_hue_alpha_10x10);
	lv_img_set_pivot(ui->scanhome_hue, 0,0);
	lv_img_set_angle(ui->scanhome_hue, 0);

	//Write codes scanhome_btnscanback
	ui->scanhome_btnscanback = lv_btn_create(ui->scanhome);
	lv_obj_set_pos(ui->scanhome_btnscanback, 25, 22);
	lv_obj_set_size(ui->scanhome_btnscanback, 15, 15);
	lv_obj_set_scrollbar_mode(ui->scanhome_btnscanback, LV_SCROLLBAR_MODE_OFF);

	//Set style for scanhome_btnscanback. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->scanhome_btnscanback, 44, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->scanhome_btnscanback, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->scanhome_btnscanback, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->scanhome_btnscanback, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->scanhome_btnscanback, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->scanhome_btnscanback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->scanhome_btnscanback, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->scanhome_btnscanback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->scanhome_btnscanback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->scanhome_btnscanback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->scanhome_btnscanback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->scanhome_btnscanback, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->scanhome_btnscanback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->scanhome_btnscanback, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->scanhome_btnscanback, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->scanhome_btnscanback, &lv_font_simsun_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->scanhome_btnscanback, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->scanhome_btnscanback_label = lv_label_create(ui->scanhome_btnscanback);
	lv_label_set_text(ui->scanhome_btnscanback_label, "<");
	lv_obj_set_style_pad_all(ui->scanhome_btnscanback, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->scanhome_btnscanback_label, LV_ALIGN_CENTER, 0, 0);
}