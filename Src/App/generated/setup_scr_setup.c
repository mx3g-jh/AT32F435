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

static lv_obj_t * g_kb_setup;
static void kb_setup_event_cb(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *kb = lv_event_get_target(e);
	if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL){
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}
__attribute__((unused)) static void ta_setup_event_cb(lv_event_t *e)
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

void setup_scr_setup(lv_ui *ui){

	//Write codes setup
	ui->setup = lv_obj_create(NULL);

	//Create keyboard on setup
	g_kb_setup = lv_keyboard_create(ui->setup);
	lv_obj_add_event_cb(g_kb_setup, kb_setup_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(g_kb_setup, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_style_text_font(g_kb_setup, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_scrollbar_mode(ui->setup, LV_SCROLLBAR_MODE_OFF);

	//Set style for setup. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_bg_color(ui->setup, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->setup, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->setup, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->setup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes setup_cont0
	ui->setup_cont0 = lv_obj_create(ui->setup);
	lv_obj_set_pos(ui->setup_cont0, 0, 0);
	lv_obj_set_size(ui->setup_cont0, 240, 240);
	lv_obj_set_scrollbar_mode(ui->setup_cont0, LV_SCROLLBAR_MODE_OFF);

	//Set style for setup_cont0. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->setup_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->setup_cont0, lv_color_make(0xd2, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->setup_cont0, lv_color_make(0xd2, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->setup_cont0, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->setup_cont0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->setup_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->setup_cont0, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->setup_cont0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->setup_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->setup_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->setup_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->setup_cont0, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->setup_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->setup_cont0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->setup_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->setup_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->setup_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->setup_cont0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes setup_btnsetback
	ui->setup_btnsetback = lv_btn_create(ui->setup);
	lv_obj_set_pos(ui->setup_btnsetback, 80, 172);
	lv_obj_set_size(ui->setup_btnsetback, 67, 34);
	lv_obj_set_scrollbar_mode(ui->setup_btnsetback, LV_SCROLLBAR_MODE_OFF);

	//Set style for setup_btnsetback. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->setup_btnsetback, 44, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->setup_btnsetback, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->setup_btnsetback, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->setup_btnsetback, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->setup_btnsetback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->setup_btnsetback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->setup_btnsetback, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->setup_btnsetback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->setup_btnsetback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->setup_btnsetback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->setup_btnsetback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->setup_btnsetback, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->setup_btnsetback, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->setup_btnsetback, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->setup_btnsetback, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->setup_btnsetback, &lv_font_simsun_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->setup_btnsetback, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->setup_btnsetback_label = lv_label_create(ui->setup_btnsetback);
	lv_label_set_text(ui->setup_btnsetback_label, "BACK");
	lv_obj_set_style_pad_all(ui->setup_btnsetback, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->setup_btnsetback_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes setup_label2
	ui->setup_label2 = lv_label_create(ui->setup);
	lv_obj_set_pos(ui->setup_label2, 5, 128);
	lv_obj_set_size(ui->setup_label2, 230, 26);
	lv_obj_set_scrollbar_mode(ui->setup_label2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->setup_label2, "You have no permission to change the settings");
	lv_label_set_long_mode(ui->setup_label2, LV_LABEL_LONG_WRAP);

	//Set style for setup_label2. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->setup_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->setup_label2, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->setup_label2, lv_color_make(0x4a, 0xb2, 0x41), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->setup_label2, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->setup_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->setup_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->setup_label2, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->setup_label2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->setup_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->setup_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->setup_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->setup_label2, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->setup_label2, &lv_font_arial_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->setup_label2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->setup_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->setup_label2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->setup_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->setup_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->setup_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->setup_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes setup_printer
	ui->setup_printer = lv_img_create(ui->setup);
	lv_obj_set_pos(ui->setup_printer, 77, 61);
	lv_obj_set_size(ui->setup_printer, 30, 48);
	lv_obj_set_scrollbar_mode(ui->setup_printer, LV_SCROLLBAR_MODE_OFF);

	//Set style for setup_printer. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->setup_printer, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->setup_printer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->setup_printer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->setup_printer, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->setup_printer,&_printer2_alpha_30x48);
	lv_img_set_pivot(ui->setup_printer, 0,0);
	lv_img_set_angle(ui->setup_printer, 0);

	//Write codes setup_img
	ui->setup_img = lv_img_create(ui->setup);
	lv_obj_set_pos(ui->setup_img, 108, 54);
	lv_obj_set_size(ui->setup_img, 12, 12);
	lv_obj_set_scrollbar_mode(ui->setup_img, LV_SCROLLBAR_MODE_OFF);

	//Set style for setup_img. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->setup_img, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->setup_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->setup_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->setup_img, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->setup_img,&_no_internet_alpha_12x12);
	lv_img_set_pivot(ui->setup_img, 0,0);
	lv_img_set_angle(ui->setup_img, 0);

	//Write codes setup_cloud
	ui->setup_cloud = lv_img_create(ui->setup);
	lv_obj_set_pos(ui->setup_cloud, 129, 26);
	lv_obj_set_size(ui->setup_cloud, 27, 35);
	lv_obj_set_scrollbar_mode(ui->setup_cloud, LV_SCROLLBAR_MODE_OFF);

	//Set style for setup_cloud. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->setup_cloud, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->setup_cloud, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->setup_cloud, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->setup_cloud, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->setup_cloud,&_cloud_alpha_27x35);
	lv_img_set_pivot(ui->setup_cloud, 0,0);
	lv_img_set_angle(ui->setup_cloud, 0);
}