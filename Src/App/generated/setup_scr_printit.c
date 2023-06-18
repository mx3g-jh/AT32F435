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

static lv_obj_t * g_kb_printit;
static void kb_printit_event_cb(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *kb = lv_event_get_target(e);
	if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL){
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}
__attribute__((unused)) static void ta_printit_event_cb(lv_event_t *e)
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

void setup_scr_printit(lv_ui *ui){

	//Write codes printit
	ui->printit = lv_obj_create(NULL);

	//Create keyboard on printit
	g_kb_printit = lv_keyboard_create(ui->printit);
	lv_obj_add_event_cb(g_kb_printit, kb_printit_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(g_kb_printit, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_style_text_font(g_kb_printit, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_scrollbar_mode(ui->printit, LV_SCROLLBAR_MODE_OFF);

	//Set style for printit. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_bg_color(ui->printit, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->printit, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->printit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->printit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printit_cont0
	ui->printit_cont0 = lv_obj_create(ui->printit);
	lv_obj_set_pos(ui->printit_cont0, 0, 0);
	lv_obj_set_size(ui->printit_cont0, 240, 240);
	lv_obj_set_scrollbar_mode(ui->printit_cont0, LV_SCROLLBAR_MODE_OFF);

	//Set style for printit_cont0. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->printit_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->printit_cont0, lv_color_make(0xd2, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->printit_cont0, lv_color_make(0xd2, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->printit_cont0, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->printit_cont0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->printit_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->printit_cont0, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->printit_cont0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->printit_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->printit_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->printit_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->printit_cont0, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->printit_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->printit_cont0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->printit_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->printit_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->printit_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->printit_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printit_btnprtitback
	ui->printit_btnprtitback = lv_btn_create(ui->printit);
	lv_obj_set_pos(ui->printit_btnprtitback, 81, 167);
	lv_obj_set_size(ui->printit_btnprtitback, 67, 34);
	lv_obj_set_scrollbar_mode(ui->printit_btnprtitback, LV_SCROLLBAR_MODE_OFF);

	//Set style for printit_btnprtitback. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->printit_btnprtitback, 44, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->printit_btnprtitback, lv_color_make(0xd2, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->printit_btnprtitback, lv_color_make(0xd2, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->printit_btnprtitback, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->printit_btnprtitback, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->printit_btnprtitback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->printit_btnprtitback, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->printit_btnprtitback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->printit_btnprtitback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->printit_btnprtitback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->printit_btnprtitback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->printit_btnprtitback, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->printit_btnprtitback, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->printit_btnprtitback, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->printit_btnprtitback, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->printit_btnprtitback, &lv_font_simsun_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->printit_btnprtitback, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->printit_btnprtitback_label = lv_label_create(ui->printit_btnprtitback);
	lv_label_set_text(ui->printit_btnprtitback_label, "BACK");
	lv_obj_set_style_pad_all(ui->printit_btnprtitback, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->printit_btnprtitback_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes printit_label2
	ui->printit_label2 = lv_label_create(ui->printit);
	lv_obj_set_pos(ui->printit_label2, 5, 128);
	lv_obj_set_size(ui->printit_label2, 230, 26);
	lv_obj_set_scrollbar_mode(ui->printit_label2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->printit_label2, "No internet connection");
	lv_label_set_long_mode(ui->printit_label2, LV_LABEL_LONG_WRAP);

	//Set style for printit_label2. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->printit_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->printit_label2, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->printit_label2, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->printit_label2, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->printit_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->printit_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->printit_label2, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->printit_label2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->printit_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->printit_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->printit_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->printit_label2, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->printit_label2, &lv_font_arial_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->printit_label2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->printit_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->printit_label2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->printit_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->printit_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->printit_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->printit_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printit_printer
	ui->printit_printer = lv_img_create(ui->printit);
	lv_obj_set_pos(ui->printit_printer, 77, 61);
	lv_obj_set_size(ui->printit_printer, 30, 48);
	lv_obj_set_scrollbar_mode(ui->printit_printer, LV_SCROLLBAR_MODE_OFF);

	//Set style for printit_printer. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->printit_printer, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->printit_printer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->printit_printer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->printit_printer, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->printit_printer,&_printer2_alpha_30x48);
	lv_img_set_pivot(ui->printit_printer, 0,0);
	lv_img_set_angle(ui->printit_printer, 0);

	//Write codes printit_imgnotit
	ui->printit_imgnotit = lv_img_create(ui->printit);
	lv_obj_set_pos(ui->printit_imgnotit, 108, 54);
	lv_obj_set_size(ui->printit_imgnotit, 12, 12);
	lv_obj_set_scrollbar_mode(ui->printit_imgnotit, LV_SCROLLBAR_MODE_OFF);

	//Set style for printit_imgnotit. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->printit_imgnotit, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->printit_imgnotit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->printit_imgnotit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->printit_imgnotit, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->printit_imgnotit,&_no_internet_alpha_12x12);
	lv_img_set_pivot(ui->printit_imgnotit, 0,0);
	lv_img_set_angle(ui->printit_imgnotit, 0);

	//Write codes printit_cloud
	ui->printit_cloud = lv_img_create(ui->printit);
	lv_obj_set_pos(ui->printit_cloud, 129, 26);
	lv_obj_set_size(ui->printit_cloud, 27, 35);
	lv_obj_set_scrollbar_mode(ui->printit_cloud, LV_SCROLLBAR_MODE_OFF);

	//Set style for printit_cloud. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->printit_cloud, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->printit_cloud, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->printit_cloud, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->printit_cloud, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->printit_cloud,&_cloud_alpha_27x35);
	lv_img_set_pivot(ui->printit_cloud, 0,0);
	lv_img_set_angle(ui->printit_cloud, 0);
}