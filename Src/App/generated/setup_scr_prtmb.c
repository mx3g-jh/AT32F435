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

static lv_obj_t * g_kb_prtmb;
static void kb_prtmb_event_cb(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *kb = lv_event_get_target(e);
	if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL){
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}
__attribute__((unused)) static void ta_prtmb_event_cb(lv_event_t *e)
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

void setup_scr_prtmb(lv_ui *ui){

	//Write codes prtmb
	ui->prtmb = lv_obj_create(NULL);

	//Create keyboard on prtmb
	g_kb_prtmb = lv_keyboard_create(ui->prtmb);
	lv_obj_add_event_cb(g_kb_prtmb, kb_prtmb_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(g_kb_prtmb, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_style_text_font(g_kb_prtmb, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_scrollbar_mode(ui->prtmb, LV_SCROLLBAR_MODE_OFF);

	//Set style for prtmb. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_bg_color(ui->prtmb, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtmb, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtmb, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtmb, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtmb_cont0
	ui->prtmb_cont0 = lv_obj_create(ui->prtmb);
	lv_obj_set_pos(ui->prtmb_cont0, 0, 0);
	lv_obj_set_size(ui->prtmb_cont0, 240, 240);
	lv_obj_set_scrollbar_mode(ui->prtmb_cont0, LV_SCROLLBAR_MODE_OFF);

	//Set style for prtmb_cont0. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtmb_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtmb_cont0, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtmb_cont0, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtmb_cont0, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtmb_cont0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->prtmb_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->prtmb_cont0, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->prtmb_cont0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->prtmb_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->prtmb_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->prtmb_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->prtmb_cont0, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->prtmb_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->prtmb_cont0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->prtmb_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->prtmb_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->prtmb_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->prtmb_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtmb_btnback
	ui->prtmb_btnback = lv_btn_create(ui->prtmb);
	lv_obj_set_pos(ui->prtmb_btnback, 85, 172);
	lv_obj_set_size(ui->prtmb_btnback, 67, 34);
	lv_obj_set_scrollbar_mode(ui->prtmb_btnback, LV_SCROLLBAR_MODE_OFF);

	//Set style for prtmb_btnback. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtmb_btnback, 44, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtmb_btnback, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtmb_btnback, lv_color_make(0x2f, 0x32, 0x43), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtmb_btnback, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtmb_btnback, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->prtmb_btnback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->prtmb_btnback, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->prtmb_btnback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->prtmb_btnback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->prtmb_btnback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->prtmb_btnback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->prtmb_btnback, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->prtmb_btnback, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->prtmb_btnback, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->prtmb_btnback, lv_color_make(0xf4, 0xec, 0xec), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->prtmb_btnback, &lv_font_simsun_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->prtmb_btnback, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->prtmb_btnback_label = lv_label_create(ui->prtmb_btnback);
	lv_label_set_text(ui->prtmb_btnback_label, "BACK");
	lv_obj_set_style_pad_all(ui->prtmb_btnback, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->prtmb_btnback_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes prtmb_label2
	ui->prtmb_label2 = lv_label_create(ui->prtmb);
	lv_obj_set_pos(ui->prtmb_label2, 5, 128);
	lv_obj_set_size(ui->prtmb_label2, 230, 26);
	lv_obj_set_scrollbar_mode(ui->prtmb_label2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->prtmb_label2, "Put your phone near to the printer");
	lv_label_set_long_mode(ui->prtmb_label2, LV_LABEL_LONG_WRAP);

	//Set style for prtmb_label2. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->prtmb_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->prtmb_label2, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->prtmb_label2, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->prtmb_label2, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->prtmb_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->prtmb_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->prtmb_label2, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->prtmb_label2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->prtmb_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->prtmb_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->prtmb_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->prtmb_label2, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->prtmb_label2, &lv_font_arial_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->prtmb_label2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->prtmb_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->prtmb_label2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->prtmb_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->prtmb_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->prtmb_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->prtmb_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes prtmb_printer
	ui->prtmb_printer = lv_img_create(ui->prtmb);
	lv_obj_set_pos(ui->prtmb_printer, 77, 61);
	lv_obj_set_size(ui->prtmb_printer, 30, 48);
	lv_obj_set_scrollbar_mode(ui->prtmb_printer, LV_SCROLLBAR_MODE_OFF);

	//Set style for prtmb_printer. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->prtmb_printer, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->prtmb_printer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->prtmb_printer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->prtmb_printer, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->prtmb_printer,&_printer2_alpha_30x48);
	lv_img_set_pivot(ui->prtmb_printer, 0,0);
	lv_img_set_angle(ui->prtmb_printer, 0);

	//Write codes prtmb_img
	ui->prtmb_img = lv_img_create(ui->prtmb);
	lv_obj_set_pos(ui->prtmb_img, 117, 73);
	lv_obj_set_size(ui->prtmb_img, 12, 12);
	lv_obj_set_scrollbar_mode(ui->prtmb_img, LV_SCROLLBAR_MODE_OFF);

	//Set style for prtmb_img. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->prtmb_img, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->prtmb_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->prtmb_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->prtmb_img, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->prtmb_img,&_wave_alpha_12x12);
	lv_img_set_pivot(ui->prtmb_img, 0,0);
	lv_img_set_angle(ui->prtmb_img, 0);

	//Write codes prtmb_cloud
	ui->prtmb_cloud = lv_img_create(ui->prtmb);
	lv_obj_set_pos(ui->prtmb_cloud, 140, 63);
	lv_obj_set_size(ui->prtmb_cloud, 22, 48);
	lv_obj_set_scrollbar_mode(ui->prtmb_cloud, LV_SCROLLBAR_MODE_OFF);

	//Set style for prtmb_cloud. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->prtmb_cloud, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->prtmb_cloud, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->prtmb_cloud, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->prtmb_cloud, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->prtmb_cloud,&_phone_alpha_22x48);
	lv_img_set_pivot(ui->prtmb_cloud, 0,0);
	lv_img_set_angle(ui->prtmb_cloud, 0);
}