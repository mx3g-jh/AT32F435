/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"


void events_init(lv_ui *ui)
{
}

void video_play(lv_ui *ui)
{

}

static void home_imgbtncopy_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		guider_load_screen(SCR_LOADER);
		add_loader(load_copy);
	}
		break;
	case LV_EVENT_RELEASED:
	{
	}
		break;
	default:
		break;
	}
}

static void home_imgbtnset_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		guider_load_screen(SCR_SETUP); 
		lv_demo_printer_anim_in_all(guider_ui.setup, 200);
	}
		break;
	default:
		break;
	}
}

static void home_imgbtnscan_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		guider_load_screen(SCR_LOADER);
		add_loader(load_scan);
	}
		break;
	case LV_EVENT_RELEASED:
	{
	}
		break;
	default:
		break;
	}
}

static void home_imgbtnprt_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		guider_load_screen(SCR_LOADER);
		add_loader(load_print);
	}
		break;
	default:
		break;
	}
}

static void home_imgcopy_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		guider_load_screen(SCR_LOADER);
		add_loader(load_copy);
	}
		break;
	default:
		break;
	}
}

static void home_imgscan_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		guider_load_screen(SCR_LOADER);
		add_loader(load_scan);
	}
		break;
	default:
		break;
	}
}

static void home_imgprt_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		guider_load_screen(SCR_LOADER);
		add_loader(load_print);
	}
		break;
	default:
		break;
	}
}

static void home_imgset_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		guider_load_screen(SCR_SETUP); 
		lv_demo_printer_anim_in_all(guider_ui.setup, 200);
	}
		break;
	default:
		break;
	}
}

void events_init_home(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->home_imgbtncopy, home_imgbtncopy_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->home_imgbtnset, home_imgbtnset_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->home_imgbtnscan, home_imgbtnscan_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->home_imgbtnprt, home_imgbtnprt_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->home_imgcopy, home_imgcopy_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->home_imgscan, home_imgscan_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->home_imgprt, home_imgprt_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->home_imgset, home_imgset_event_handler, LV_EVENT_ALL, ui);
}
