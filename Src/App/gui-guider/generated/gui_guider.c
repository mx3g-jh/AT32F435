/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"


void init_scr_del_flag(lv_ui *ui){
	ui->home_del = true;
	ui->copyhome_del = true;
	ui->copynext_del = true;
	ui->scanhome_del = true;
	ui->prthome_del = true;
	ui->prtusb_del = true;
	ui->prtmb_del = true;
	ui->printit_del = true;
	ui->setup_del = true;
	ui->loader_del = true;
	ui->saved_del = true;
}

void setup_ui(lv_ui *ui){
	init_scr_del_flag(ui);
	setup_scr_home(ui);
	lv_scr_load(ui->home);
}
