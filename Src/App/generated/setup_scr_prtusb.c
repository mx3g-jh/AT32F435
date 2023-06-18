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

static lv_obj_t * g_kb_prtusb;
static void kb_prtusb_event_cb(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *kb = lv_event_get_target(e);
	if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL){
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}
__attribute__((unused)) static void ta_prtusb_event_cb(lv_event_t *e)
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

void setup_scr_prtusb(lv_ui *ui){

	//Write codes prtusb
	ui->prtusb = lv_obj_create(NULL);

	//Create keyboard on prtusb
	g_kb_prtusb = lv_keyboard_create(ui->prtusb);
	lv_obj_add_event_cb(g_kb_prtusb, kb_prtusb_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(g_kb_prtusb, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_style_text_font(g_kb_prtusb, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_scrollbar_mode(ui->prtusb, LV_SCROLLBAR_MODE_OFF);

	//Set style for prtusb. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_bg_color(ui->prtusb, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtusb, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtusb, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtusb, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtusb_cont0
	ui->prtusb_cont0 = lv_obj_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_cont0, 0, 0);
	lv_obj_set_size(ui->prtusb_cont0, 240, 88);
	lv_obj_set_scrollbar_mode(ui->prtusb_cont0, LV_SCROLLBAR_MODE_OFF);

	//Set style for prtusb_cont0. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtusb_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtusb_cont0, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtusb_cont0, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtusb_cont0, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtusb_cont0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->prtusb_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->prtusb_cont0, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->prtusb_cont0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->prtusb_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->prtusb_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->prtusb_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->prtusb_cont0, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->prtusb_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->prtusb_cont0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->prtusb_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->prtusb_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->prtusb_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->prtusb_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtusb_cont2
	ui->prtusb_cont2 = lv_obj_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_cont2, 0, 88);
	lv_obj_set_size(ui->prtusb_cont2, 240, 151);
	lv_obj_set_scrollbar_mode(ui->prtusb_cont2, LV_SCROLLBAR_MODE_OFF);

	//Set style for prtusb_cont2. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtusb_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtusb_cont2, lv_color_make(0xde, 0xde, 0xde), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtusb_cont2, lv_color_make(0xde, 0xde, 0xde), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtusb_cont2, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtusb_cont2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->prtusb_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->prtusb_cont2, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->prtusb_cont2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->prtusb_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->prtusb_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->prtusb_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->prtusb_cont2, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->prtusb_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->prtusb_cont2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->prtusb_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->prtusb_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->prtusb_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->prtusb_cont2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtusb_labeltitle
	ui->prtusb_labeltitle = lv_label_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_labeltitle, 68, 26);
	lv_obj_set_size(ui->prtusb_labeltitle, 112, 26);
	lv_obj_set_scrollbar_mode(ui->prtusb_labeltitle, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->prtusb_labeltitle, "PRINTING FROM USB");
	lv_label_set_long_mode(ui->prtusb_labeltitle, LV_LABEL_LONG_WRAP);

	//Set style for prtusb_labeltitle. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtusb_labeltitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtusb_labeltitle, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtusb_labeltitle, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtusb_labeltitle, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtusb_labeltitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->prtusb_labeltitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->prtusb_labeltitle, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->prtusb_labeltitle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->prtusb_labeltitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->prtusb_labeltitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->prtusb_labeltitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->prtusb_labeltitle, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->prtusb_labeltitle, &lv_font_arial_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->prtusb_labeltitle, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->prtusb_labeltitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->prtusb_labeltitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->prtusb_labeltitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->prtusb_labeltitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->prtusb_labeltitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->prtusb_labeltitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtusb_cont4
	ui->prtusb_cont4 = lv_obj_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_cont4, 152, 70);
	lv_obj_set_size(ui->prtusb_cont4, 75, 114);
	lv_obj_set_scrollbar_mode(ui->prtusb_cont4, LV_SCROLLBAR_MODE_OFF);

	//Set style for prtusb_cont4. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtusb_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtusb_cont4, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtusb_cont4, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtusb_cont4, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtusb_cont4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->prtusb_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->prtusb_cont4, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->prtusb_cont4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->prtusb_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->prtusb_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->prtusb_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->prtusb_cont4, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->prtusb_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->prtusb_cont4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->prtusb_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->prtusb_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->prtusb_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->prtusb_cont4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtusb_btnprint
	ui->prtusb_btnprint = lv_btn_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_btnprint, 160, 196);
	lv_obj_set_size(ui->prtusb_btnprint, 59, 35);
	lv_obj_set_scrollbar_mode(ui->prtusb_btnprint, LV_SCROLLBAR_MODE_OFF);

	//Set style for prtusb_btnprint. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtusb_btnprint, 44, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtusb_btnprint, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtusb_btnprint, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtusb_btnprint, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtusb_btnprint, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->prtusb_btnprint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->prtusb_btnprint, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->prtusb_btnprint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->prtusb_btnprint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->prtusb_btnprint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->prtusb_btnprint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->prtusb_btnprint, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->prtusb_btnprint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->prtusb_btnprint, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->prtusb_btnprint, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->prtusb_btnprint, &lv_font_simsun_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->prtusb_btnprint, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->prtusb_btnprint_label = lv_label_create(ui->prtusb_btnprint);
	lv_label_set_text(ui->prtusb_btnprint_label, "PRINT");
	lv_obj_set_style_pad_all(ui->prtusb_btnprint, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->prtusb_btnprint_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes prtusb_back
	ui->prtusb_back = lv_btn_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_back, 25, 22);
	lv_obj_set_size(ui->prtusb_back, 15, 15);
	lv_obj_set_scrollbar_mode(ui->prtusb_back, LV_SCROLLBAR_MODE_OFF);

	//Set style for prtusb_back. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtusb_back, 44, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtusb_back, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtusb_back, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtusb_back, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtusb_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->prtusb_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->prtusb_back, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->prtusb_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->prtusb_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->prtusb_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->prtusb_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->prtusb_back, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->prtusb_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->prtusb_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->prtusb_back, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->prtusb_back, &lv_font_simsun_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->prtusb_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->prtusb_back_label = lv_label_create(ui->prtusb_back);
	lv_label_set_text(ui->prtusb_back_label, "<");
	lv_obj_set_style_pad_all(ui->prtusb_back, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->prtusb_back_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes prtusb_swcolor
	ui->prtusb_swcolor = lv_switch_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_swcolor, 161, 154);
	lv_obj_set_size(ui->prtusb_swcolor, 20, 17);
	lv_obj_set_scrollbar_mode(ui->prtusb_swcolor, LV_SCROLLBAR_MODE_OFF);

	//Set style for prtusb_swcolor. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtusb_swcolor, 88, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtusb_swcolor, lv_color_make(0xd4, 0xd7, 0xd9), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtusb_swcolor, lv_color_make(0xd4, 0xd7, 0xd9), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtusb_swcolor, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtusb_swcolor, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->prtusb_swcolor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->prtusb_swcolor, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->prtusb_swcolor, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->prtusb_swcolor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->prtusb_swcolor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->prtusb_swcolor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->prtusb_swcolor, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->prtusb_swcolor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->prtusb_swcolor, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for prtusb_swcolor. Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED
	lv_obj_set_style_bg_color(ui->prtusb_swcolor, lv_color_make(0x21, 0x95, 0xf6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_color(ui->prtusb_swcolor, lv_color_make(0x21, 0x95, 0xf6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->prtusb_swcolor, LV_GRAD_DIR_VER, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_opa(ui->prtusb_swcolor, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->prtusb_swcolor, lv_color_make(0x21, 0x95, 0xf6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->prtusb_swcolor, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_opa(ui->prtusb_swcolor, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Set style for prtusb_swcolor. Part: LV_PART_KNOB, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtusb_swcolor, 88, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtusb_swcolor, lv_color_make(0xff, 0xff, 0xff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtusb_swcolor, lv_color_make(0xff, 0xff, 0xff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtusb_swcolor, LV_GRAD_DIR_VER, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtusb_swcolor, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->prtusb_swcolor, lv_color_make(0x21, 0x95, 0xf6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->prtusb_swcolor, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->prtusb_swcolor, 255, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes prtusb_labelcopy
	ui->prtusb_labelcopy = lv_label_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_labelcopy, 172, 76);
	lv_obj_set_size(ui->prtusb_labelcopy, 32, 17);
	lv_obj_set_scrollbar_mode(ui->prtusb_labelcopy, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->prtusb_labelcopy, "Copies");
	lv_label_set_long_mode(ui->prtusb_labelcopy, LV_LABEL_LONG_WRAP);

	//Set style for prtusb_labelcopy. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtusb_labelcopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtusb_labelcopy, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtusb_labelcopy, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtusb_labelcopy, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtusb_labelcopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->prtusb_labelcopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->prtusb_labelcopy, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->prtusb_labelcopy, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->prtusb_labelcopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->prtusb_labelcopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->prtusb_labelcopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->prtusb_labelcopy, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->prtusb_labelcopy, &lv_font_arial_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->prtusb_labelcopy, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->prtusb_labelcopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->prtusb_labelcopy, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->prtusb_labelcopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->prtusb_labelcopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->prtusb_labelcopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->prtusb_labelcopy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtusb_up
	ui->prtusb_up = lv_btn_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_up, 205, 97);
	lv_obj_set_size(ui->prtusb_up, 10, 10);
	lv_obj_set_scrollbar_mode(ui->prtusb_up, LV_SCROLLBAR_MODE_OFF);

	//Set style for prtusb_up. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtusb_up, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtusb_up, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtusb_up, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtusb_up, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtusb_up, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->prtusb_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->prtusb_up, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->prtusb_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->prtusb_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->prtusb_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->prtusb_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->prtusb_up, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->prtusb_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->prtusb_up, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->prtusb_up, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->prtusb_up, &lv_font_simsun_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->prtusb_up, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->prtusb_up_label = lv_label_create(ui->prtusb_up);
	lv_label_set_text(ui->prtusb_up_label, "+");
	lv_obj_set_style_pad_all(ui->prtusb_up, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->prtusb_up_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes prtusb_down
	ui->prtusb_down = lv_btn_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_down, 161, 97);
	lv_obj_set_size(ui->prtusb_down, 10, 10);
	lv_obj_set_scrollbar_mode(ui->prtusb_down, LV_SCROLLBAR_MODE_OFF);

	//Set style for prtusb_down. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtusb_down, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtusb_down, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtusb_down, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtusb_down, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtusb_down, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->prtusb_down, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->prtusb_down, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->prtusb_down, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->prtusb_down, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->prtusb_down, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->prtusb_down, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->prtusb_down, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->prtusb_down, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->prtusb_down, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->prtusb_down, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->prtusb_down, &lv_font_simsun_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->prtusb_down, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->prtusb_down_label = lv_label_create(ui->prtusb_down);
	lv_label_set_text(ui->prtusb_down_label, "-");
	lv_obj_set_style_pad_all(ui->prtusb_down, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->prtusb_down_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes prtusb_labelcnt
	ui->prtusb_labelcnt = lv_label_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_labelcnt, 166, 97);
	lv_obj_set_size(ui->prtusb_labelcnt, 45, 26);
	lv_obj_set_scrollbar_mode(ui->prtusb_labelcnt, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->prtusb_labelcnt, "1");
	lv_label_set_long_mode(ui->prtusb_labelcnt, LV_LABEL_LONG_WRAP);

	//Set style for prtusb_labelcnt. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtusb_labelcnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtusb_labelcnt, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtusb_labelcnt, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtusb_labelcnt, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtusb_labelcnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->prtusb_labelcnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->prtusb_labelcnt, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->prtusb_labelcnt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->prtusb_labelcnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->prtusb_labelcnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->prtusb_labelcnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->prtusb_labelcnt, lv_color_make(0x14, 0x10, 0x10), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->prtusb_labelcnt, &lv_font_arial_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->prtusb_labelcnt, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->prtusb_labelcnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->prtusb_labelcnt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->prtusb_labelcnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->prtusb_labelcnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->prtusb_labelcnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->prtusb_labelcnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtusb_labelcolor
	ui->prtusb_labelcolor = lv_label_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_labelcolor, 157, 128);
	lv_obj_set_size(ui->prtusb_labelcolor, 25, 17);
	lv_obj_set_scrollbar_mode(ui->prtusb_labelcolor, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->prtusb_labelcolor, "Color");
	lv_label_set_long_mode(ui->prtusb_labelcolor, LV_LABEL_LONG_WRAP);

	//Set style for prtusb_labelcolor. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtusb_labelcolor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtusb_labelcolor, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtusb_labelcolor, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtusb_labelcolor, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtusb_labelcolor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->prtusb_labelcolor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->prtusb_labelcolor, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->prtusb_labelcolor, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->prtusb_labelcolor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->prtusb_labelcolor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->prtusb_labelcolor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->prtusb_labelcolor, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->prtusb_labelcolor, &lv_font_arial_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->prtusb_labelcolor, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->prtusb_labelcolor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->prtusb_labelcolor, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->prtusb_labelcolor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->prtusb_labelcolor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->prtusb_labelcolor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->prtusb_labelcolor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtusb_labelvert
	ui->prtusb_labelvert = lv_label_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_labelvert, 190, 128);
	lv_obj_set_size(ui->prtusb_labelvert, 35, 17);
	lv_obj_set_scrollbar_mode(ui->prtusb_labelvert, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->prtusb_labelvert, "Vertical");
	lv_label_set_long_mode(ui->prtusb_labelvert, LV_LABEL_LONG_WRAP);

	//Set style for prtusb_labelvert. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtusb_labelvert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtusb_labelvert, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtusb_labelvert, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtusb_labelvert, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtusb_labelvert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->prtusb_labelvert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->prtusb_labelvert, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->prtusb_labelvert, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->prtusb_labelvert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->prtusb_labelvert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->prtusb_labelvert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->prtusb_labelvert, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->prtusb_labelvert, &lv_font_arial_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->prtusb_labelvert, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->prtusb_labelvert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->prtusb_labelvert, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->prtusb_labelvert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->prtusb_labelvert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->prtusb_labelvert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->prtusb_labelvert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtusb_swvert
	ui->prtusb_swvert = lv_switch_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_swvert, 195, 154);
	lv_obj_set_size(ui->prtusb_swvert, 20, 17);
	lv_obj_set_scrollbar_mode(ui->prtusb_swvert, LV_SCROLLBAR_MODE_OFF);

	//Set style for prtusb_swvert. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtusb_swvert, 88, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtusb_swvert, lv_color_make(0xd4, 0xd7, 0xd9), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtusb_swvert, lv_color_make(0xd4, 0xd7, 0xd9), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtusb_swvert, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtusb_swvert, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->prtusb_swvert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->prtusb_swvert, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->prtusb_swvert, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->prtusb_swvert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->prtusb_swvert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->prtusb_swvert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->prtusb_swvert, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->prtusb_swvert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->prtusb_swvert, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for prtusb_swvert. Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED
	lv_obj_set_style_bg_color(ui->prtusb_swvert, lv_color_make(0x21, 0x95, 0xf6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_color(ui->prtusb_swvert, lv_color_make(0x21, 0x95, 0xf6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->prtusb_swvert, LV_GRAD_DIR_VER, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_opa(ui->prtusb_swvert, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->prtusb_swvert, lv_color_make(0x21, 0x95, 0xf6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->prtusb_swvert, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_opa(ui->prtusb_swvert, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Set style for prtusb_swvert. Part: LV_PART_KNOB, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtusb_swvert, 88, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtusb_swvert, lv_color_make(0xff, 0xff, 0xff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtusb_swvert, lv_color_make(0xff, 0xff, 0xff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtusb_swvert, LV_GRAD_DIR_VER, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtusb_swvert, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->prtusb_swvert, lv_color_make(0x21, 0x95, 0xf6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->prtusb_swvert, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->prtusb_swvert, 255, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes prtusb_list16
	ui->prtusb_list16 = lv_list_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_list16, 15, 73);
	lv_obj_set_size(ui->prtusb_list16, 120, 109);
	lv_obj_set_scrollbar_mode(ui->prtusb_list16, LV_SCROLLBAR_MODE_OFF);

	//Set style for prtusb_list16. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtusb_list16, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtusb_list16, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtusb_list16, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtusb_list16, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtusb_list16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->prtusb_list16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->prtusb_list16, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->prtusb_list16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->prtusb_list16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->prtusb_list16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->prtusb_list16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->prtusb_list16, lv_color_make(0xe1, 0xe6, 0xee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->prtusb_list16, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->prtusb_list16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->prtusb_list16, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->prtusb_list16, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->prtusb_list16, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->prtusb_list16, 5, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for prtusb_list16. Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtusb_list16, 2, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtusb_list16, lv_color_make(0xff, 0xff, 0xff), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtusb_list16, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Set style state: LV_STATE_DEFAULT for style_prtusb_list16_extra_btns_main_default
	static lv_style_t style_prtusb_list16_extra_btns_main_default;
	ui_init_style(&style_prtusb_list16_extra_btns_main_default);
	lv_style_set_radius(&style_prtusb_list16_extra_btns_main_default, 2);
	lv_style_set_bg_color(&style_prtusb_list16_extra_btns_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_prtusb_list16_extra_btns_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_prtusb_list16_extra_btns_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_list16_extra_btns_main_default, 255);
	lv_style_set_text_color(&style_prtusb_list16_extra_btns_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_prtusb_list16_extra_btns_main_default, &lv_font_arial_10);

	//Set style state: LV_STATE_DEFAULT for style_prtusb_list16_extra_texts_main_default
	static lv_style_t style_prtusb_list16_extra_texts_main_default;
	ui_init_style(&style_prtusb_list16_extra_texts_main_default);
	lv_style_set_radius(&style_prtusb_list16_extra_texts_main_default, 3);
	lv_style_set_bg_color(&style_prtusb_list16_extra_texts_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_prtusb_list16_extra_texts_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_prtusb_list16_extra_texts_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_prtusb_list16_extra_texts_main_default, 255);
	lv_style_set_text_color(&style_prtusb_list16_extra_texts_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_prtusb_list16_extra_texts_main_default, &lv_font_montserratMedium_12);

	lv_obj_t *prtusb_list16_item;
	prtusb_list16_item = lv_list_add_btn(ui->prtusb_list16, LV_SYMBOL_FILE, "Contract 12.pdf");
	ui->prtusb_list16_item0 = prtusb_list16_item;
	lv_obj_add_style(prtusb_list16_item, &style_prtusb_list16_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	prtusb_list16_item = lv_list_add_btn(ui->prtusb_list16, LV_SYMBOL_FILE, "Scanned_05_21.pdf");
	ui->prtusb_list16_item1 = prtusb_list16_item;
	lv_obj_add_style(prtusb_list16_item, &style_prtusb_list16_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	prtusb_list16_item = lv_list_add_btn(ui->prtusb_list16, LV_SYMBOL_FILE, "Photo_2.jpg");
	ui->prtusb_list16_item2 = prtusb_list16_item;
	lv_obj_add_style(prtusb_list16_item, &style_prtusb_list16_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	prtusb_list16_item = lv_list_add_btn(ui->prtusb_list16, LV_SYMBOL_FILE, "Photo_3.jpg");
	ui->prtusb_list16_item3 = prtusb_list16_item;
	lv_obj_add_style(prtusb_list16_item, &style_prtusb_list16_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);


	//Write codes prtusb_ddlist1
	ui->prtusb_ddlist1 = lv_dropdown_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_ddlist1, 14, 194);
	lv_obj_set_size(ui->prtusb_ddlist1, 50, 18);
	lv_obj_set_scrollbar_mode(ui->prtusb_ddlist1, LV_SCROLLBAR_MODE_OFF);
	lv_dropdown_set_options(ui->prtusb_ddlist1, "Best\nNormal\nDraft");

	//Set style for prtusb_ddlist1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtusb_ddlist1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtusb_ddlist1, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtusb_ddlist1, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtusb_ddlist1, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtusb_ddlist1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->prtusb_ddlist1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->prtusb_ddlist1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->prtusb_ddlist1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->prtusb_ddlist1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->prtusb_ddlist1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->prtusb_ddlist1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->prtusb_ddlist1, lv_color_make(0xe1, 0xe6, 0xee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->prtusb_ddlist1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->prtusb_ddlist1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->prtusb_ddlist1, lv_color_make(0x0D, 0x30, 0x55), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->prtusb_ddlist1, &lv_font_arial_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->prtusb_ddlist1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->prtusb_ddlist1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->prtusb_ddlist1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style state: LV_STATE_CHECKED for style_prtusb_ddlist1_extra_list_selected_checked
	static lv_style_t style_prtusb_ddlist1_extra_list_selected_checked;
	ui_init_style(&style_prtusb_ddlist1_extra_list_selected_checked);
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

	//Set style state: LV_STATE_DEFAULT for style_prtusb_ddlist1_extra_list_main_default
	static lv_style_t style_prtusb_ddlist1_extra_list_main_default;
	ui_init_style(&style_prtusb_ddlist1_extra_list_main_default);
	lv_style_set_radius(&style_prtusb_ddlist1_extra_list_main_default, 2);
	lv_style_set_bg_color(&style_prtusb_ddlist1_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_prtusb_ddlist1_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_prtusb_ddlist1_extra_list_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_ddlist1_extra_list_main_default, 255);
	lv_style_set_border_color(&style_prtusb_ddlist1_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_prtusb_ddlist1_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_prtusb_ddlist1_extra_list_main_default, 255);
	lv_style_set_text_color(&style_prtusb_ddlist1_extra_list_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_prtusb_ddlist1_extra_list_main_default, &lv_font_arial_10);
	lv_style_set_max_height(&style_prtusb_ddlist1_extra_list_main_default, 90);
	lv_obj_add_style(lv_dropdown_get_list(ui->prtusb_ddlist1), &style_prtusb_ddlist1_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style state: LV_STATE_DEFAULT for style_prtusb_ddlist1_extra_list_scrollbar_default
	static lv_style_t style_prtusb_ddlist1_extra_list_scrollbar_default;
	ui_init_style(&style_prtusb_ddlist1_extra_list_scrollbar_default);
	lv_style_set_radius(&style_prtusb_ddlist1_extra_list_scrollbar_default, 2);
	lv_style_set_bg_color(&style_prtusb_ddlist1_extra_list_scrollbar_default, lv_color_make(0x00, 0xff, 0x00));
	lv_style_set_bg_opa(&style_prtusb_ddlist1_extra_list_scrollbar_default, 255);
	lv_obj_add_style(lv_dropdown_get_list(ui->prtusb_ddlist1), &style_prtusb_ddlist1_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes prtusb_ddlist2
	ui->prtusb_ddlist2 = lv_dropdown_create(ui->prtusb);
	lv_obj_set_pos(ui->prtusb_ddlist2, 83, 194);
	lv_obj_set_size(ui->prtusb_ddlist2, 50, 20);
	lv_obj_set_scrollbar_mode(ui->prtusb_ddlist2, LV_SCROLLBAR_MODE_OFF);
	lv_dropdown_set_options(ui->prtusb_ddlist2, "72 DPI\n96 DPI\n150 DPI\n300 DPI\n600 DPI\n900 DPI\n1200 DPI");

	//Set style for prtusb_ddlist2. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtusb_ddlist2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtusb_ddlist2, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtusb_ddlist2, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtusb_ddlist2, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtusb_ddlist2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->prtusb_ddlist2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->prtusb_ddlist2, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->prtusb_ddlist2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->prtusb_ddlist2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->prtusb_ddlist2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->prtusb_ddlist2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->prtusb_ddlist2, lv_color_make(0xe1, 0xe6, 0xee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->prtusb_ddlist2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->prtusb_ddlist2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->prtusb_ddlist2, lv_color_make(0x0D, 0x30, 0x55), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->prtusb_ddlist2, &lv_font_arial_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->prtusb_ddlist2, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->prtusb_ddlist2, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->prtusb_ddlist2, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style state: LV_STATE_CHECKED for style_prtusb_ddlist2_extra_list_selected_checked
	static lv_style_t style_prtusb_ddlist2_extra_list_selected_checked;
	ui_init_style(&style_prtusb_ddlist2_extra_list_selected_checked);
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

	//Set style state: LV_STATE_DEFAULT for style_prtusb_ddlist2_extra_list_main_default
	static lv_style_t style_prtusb_ddlist2_extra_list_main_default;
	ui_init_style(&style_prtusb_ddlist2_extra_list_main_default);
	lv_style_set_radius(&style_prtusb_ddlist2_extra_list_main_default, 2);
	lv_style_set_bg_color(&style_prtusb_ddlist2_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_prtusb_ddlist2_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_prtusb_ddlist2_extra_list_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prtusb_ddlist2_extra_list_main_default, 255);
	lv_style_set_border_color(&style_prtusb_ddlist2_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_prtusb_ddlist2_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_prtusb_ddlist2_extra_list_main_default, 255);
	lv_style_set_text_color(&style_prtusb_ddlist2_extra_list_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_prtusb_ddlist2_extra_list_main_default, &lv_font_arial_10);
	lv_style_set_max_height(&style_prtusb_ddlist2_extra_list_main_default, 90);
	lv_obj_add_style(lv_dropdown_get_list(ui->prtusb_ddlist2), &style_prtusb_ddlist2_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style state: LV_STATE_DEFAULT for style_prtusb_ddlist2_extra_list_scrollbar_default
	static lv_style_t style_prtusb_ddlist2_extra_list_scrollbar_default;
	ui_init_style(&style_prtusb_ddlist2_extra_list_scrollbar_default);
	lv_style_set_radius(&style_prtusb_ddlist2_extra_list_scrollbar_default, 2);
	lv_style_set_bg_color(&style_prtusb_ddlist2_extra_list_scrollbar_default, lv_color_make(0x00, 0xff, 0x00));
	lv_style_set_bg_opa(&style_prtusb_ddlist2_extra_list_scrollbar_default, 255);
	lv_obj_add_style(lv_dropdown_get_list(ui->prtusb_ddlist2), &style_prtusb_ddlist2_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
}