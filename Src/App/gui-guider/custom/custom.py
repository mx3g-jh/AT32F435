class ScreenEnum:
    SCR_HOME = 0
    SCR_COPY_HOME = 1
    SCR_COPY_NEXT = 2
    SCR_SCAN_HOME = 3
    SCR_PRT_HOME = 4
    SCR_PRT_USB = 5
    SCR_PRT_MB = 6
    SCR_PRT_IT = 7
    SCR_SETUP = 8
    SCR_LOADER = 9
    SCR_SAVED = 10

LV_DEMO_PRINTER_ANIM_DELAY=40
LV_DEMO_PRINTER_ANIM_TIME=150
LV_DEMO_PRINTER_ANIM_TIME_BG=300
LOAD_ANIM_TIME=1000
lightness_act = 0
hue_act = 180
cur_scr = ScreenEnum.SCR_HOME
copy_counter = 1
prtusb_counter = 1
save_src = 0


def get_scr_by_id(scr_id):
    if(scr_id == ScreenEnum.SCR_HOME):
        return home
    elif(scr_id == ScreenEnum.SCR_COPY_HOME):
        return copyhome
    elif(scr_id == ScreenEnum.SCR_COPY_NEXT):
        return copynext
    elif(scr_id == ScreenEnum.SCR_SCAN_HOME):
        return scanhome
    elif(scr_id == ScreenEnum.SCR_PRT_HOME):
        return prthome
    elif(scr_id == ScreenEnum.SCR_PRT_USB):
        return prtusb
    elif(scr_id == ScreenEnum.SCR_PRT_MB):
        return prtmb
    elif(scr_id == ScreenEnum.SCR_PRT_IT):
        return printit
    elif(scr_id == ScreenEnum.SCR_SETUP):
        return setup
    elif(scr_id == ScreenEnum.SCR_LOADER):
        return loader
    elif(scr_id == ScreenEnum.SCR_SAVED):
        return saved

def load_disbtn_home_cb(e):
    code = e.get_code()
    if(code == lv.EVENT.PRESSED):
        guider_load_screen(ScreenEnum.SCR_HOME)
        lv_demo_printer_anim_in_all(home, 100)

def load_copy_next_cb(e):
    code = e.get_code()
    if(code == lv.EVENT.PRESSED):
         guider_load_screen(ScreenEnum.SCR_COPY_NEXT)
         lv_demo_printer_anim_in_all(copynext, 200)

def hue_slider_event_cb(e, obj):
    src = e.get_target()
    code = e.get_code()
    if(code == lv.EVENT.VALUE_CHANGED):
        global hue_act
        hue_act = src.get_value()
        scan_img_color_refr(obj)


def lightness_slider_event_cb(e, obj):
    src = e.get_target()
    code = e.get_code()
    if(code == lv.EVENT.VALUE_CHANGED):
        global lightness_act
        lightness_act = src.get_value()
        scan_img_color_refr(obj)

def loader_anim_cb(arc, v):
    if(v > 100):
        v = 100
    arc.set_angles(270, int(v * 360 / 100 + 270))
    loader_loadlabel.set_text(str(v))

def copy_counter_event_cb(e, obj):
    code = e.get_code()
    print(code)
    if(code == lv.EVENT.PRESSED):
        global copy_counter
        if (obj == copynext_up):
            if(copy_counter < 200):
                copy_counter += 1
        else:
            if (copy_counter > 1):
                copy_counter -= 1
        print(copy_counter, obj)
        copynext_labelcnt.set_text(str(copy_counter))

def prtusb_counter_event_cb(e, obj):
    code = e.get_code()
    if(code == lv.EVENT.PRESSED):
        global prtusb_counter
        if (obj == prtusb_up):
            if(prtusb_counter < 200):
                prtusb_counter += 1
        else:
            if (prtusb_counter > 1):
                prtusb_counter -= 1
        print(prtusb_counter, obj)
        prtusb_labelcnt.set_text(str(prtusb_counter))

def load_print_finish_cb(e):
    code = e.get_code()
    if(code == lv.EVENT.PRESSED):
        global save_src
        save_src = 2
        guider_load_screen(ScreenEnum.SCR_LOADER)
        add_loader(load_save)

def load_save_cb(e):
    code = e.get_code()
    if(code == lv.EVENT.PRESSED):
        guider_load_screen(ScreenEnum.SCR_LOADER)
        global save_src
        save_src = 1
        add_loader(load_save)

def load_print_usb_cb(e):
    code = e.get_code()
    if(code == lv.EVENT.PRESSED):
        guider_load_screen(ScreenEnum.SCR_PRT_USB)
        lv_demo_printer_anim_in_all(prtusb, 200)

def load_print_mobile_cb(e):
    code = e.get_code()
    if(code == lv.EVENT.PRESSED):
        guider_load_screen(ScreenEnum.SCR_PRT_MB)
        lv_demo_printer_anim_in_all(prtmb, 200)

def load_print_it_cb(e):
    code = e.get_code()
    if(code == lv.EVENT.PRESSED):
        guider_load_screen(ScreenEnum.SCR_PRT_IT)
        lv_demo_printer_anim_in_all(printit, 200)

def copy_home_event_init():
    copyhome_btncopyback.add_event_cb(lambda e: load_disbtn_home_cb(e), lv.EVENT.CLICKED, None)

def scan_img_color_refr(obj):
    if lightness_act > 0:
        s = 100 - lightness_act
        v = 100
    else:
        s = 100
        v = 100 + lightness_act
    c = lv.color_hsv_to_rgb(hue_act,s,v)
    obj.set_style_img_recolor_opa(v, 0)
    obj.set_style_img_recolor(c, 0)

def anim_y_cb(obj, v):
    obj.set_y(v)

def lv_demo_printer_anim_in_all(obj, delay):
    child_cnts = lv.obj.get_child_cnt(obj)
    for i in range(child_cnts):
        child = lv.obj.get_child(obj, i)
        child.update_layout()
        # a = lv.anim_t()
        # a.init()
        # a.set_var(child)
        # a.set_time(LV_DEMO_PRINTER_ANIM_TIME)
        # a.set_delay(delay)
        # a.set_custom_exec_cb(lambda a, val: anim_y_cb(child,val))
        # a.set_values(child.get_y() - int(lv.scr_act().get_disp().driver.ver_res / 20), child.get_y())
        # lv.anim_t.start(a)
        child.fade_in(LV_DEMO_PRINTER_ANIM_TIME - 100, delay)


def load_copy(a):
    guider_load_screen(ScreenEnum.SCR_COPY_HOME)
    lv_demo_printer_anim_in_all(copyhome, 200)

def load_save(a):
    guider_load_screen(ScreenEnum.SCR_SAVED)
    if(save_src == 1):
        saved_label2.set_x(157)
        saved_label2.set_text("File saved")
    elif(save_src == 2):
        saved_label2.set_x(157)
        saved_label2.set_text("Printing finished")
    else:
        saved_label2.set_x(157)
        saved_label2.set_text("File saved")
    lv_demo_printer_anim_in_all(saved, 200)

def load_home(a):
    guider_load_screen(ScreenEnum.SCR_HOME)


def load_scan(a):
    guider_load_screen(ScreenEnum.SCR_SCAN_HOME)
    lv_demo_printer_anim_in_all(scanhome, 200)

def load_setup(a):
    guider_load_screen(ScreenEnum.SCR_SETUP)
    lv_demo_printer_anim_in_all(setup, 200)

def load_print(a):
    guider_load_screen(ScreenEnum.SCR_PRT_HOME)
    lv_demo_printer_anim_in_all(prthome, 200)

# loading event function support.
def add_loader(end_cb):
    loader_loadarc.set_angles(270, 270)
    a = lv.anim_t()
    a.init()
    a.set_time(LOAD_ANIM_TIME)
    a.set_values(0, 110)
    a.set_var(loader_loadarc)
    a.set_custom_exec_cb(lambda a,val: loader_anim_cb(loader_loadarc,val))
    a.set_ready_cb(end_cb)
    lv.anim_t.start(a)


def guider_load_screen(scr_id):
    scr = None
    if(scr_id == ScreenEnum.SCR_HOME):
        scr = home
    elif(scr_id == ScreenEnum.SCR_COPY_HOME):
        scr = copyhome
        copyhome_img3.set_style_radius(8, lv.STATE.DEFAULT)
        copyhome_img3.set_style_clip_corner(True, lv.STATE.DEFAULT)
        copyhome_img3.set_style_bg_img_recolor_opa(180, lv.STATE.DEFAULT)

    elif(scr_id == ScreenEnum.SCR_COPY_NEXT):
        scr = copynext
        global copy_counter
        copy_counter = 1
        copynext_labelcnt.set_text(str(copy_counter))
        copynext_print.clear_flag(False)
    elif(scr_id == ScreenEnum.SCR_SCAN_HOME):
        scr = scanhome
        scanhome_img3.set_style_radius(8, lv.STATE.DEFAULT)
        scanhome_img3.set_style_clip_corner(True, lv.STATE.DEFAULT)
        scanhome_img3.set_style_bg_img_recolor_opa(180, lv.STATE.DEFAULT)
    elif(scr_id == ScreenEnum.SCR_PRT_HOME):
        scr = prthome
        global prtusb_counter
        prtusb_counter = 1
        prtusb_labelcnt.set_text(str(prtusb_counter))
    elif(scr_id == ScreenEnum.SCR_PRT_USB):
        scr = prtusb
    elif(scr_id == ScreenEnum.SCR_PRT_MB):
        scr = prtmb
    elif(scr_id == ScreenEnum.SCR_PRT_IT):
        scr = printit
    elif(scr_id == ScreenEnum.SCR_SETUP):
        scr = setup
    elif(scr_id == ScreenEnum.SCR_LOADER):
        scr = loader
        # loader_loadarc.add_style(lv.STATE.DEFAULT)
    elif(scr_id == ScreenEnum.SCR_SAVED):
        scr = saved
        saved_btnsavecontinue_label.set_style_text_font(lv.font_montserrat_14, lv.STATE.DEFAULT)
    else:
        scr = None
    
    lv.scr_load(scr)

copyhome_btncopyback.add_event_cb(load_disbtn_home_cb, lv.EVENT.ALL, None)
copyhome_btncopynext.add_event_cb(load_copy_next_cb, lv.EVENT.ALL, None)
copyhome_sliderhue.add_event_cb(lambda e: hue_slider_event_cb(e, copyhome_img3), lv.EVENT.ALL, None)
copyhome_sliderbright.add_event_cb(lambda e: lightness_slider_event_cb(e, copyhome_img3), lv.EVENT.ALL, None)
copynext_up.add_event_cb(lambda e: copy_counter_event_cb(e, copynext_up),lv.EVENT.ALL, None)
copynext_down.add_event_cb(lambda e: copy_counter_event_cb(e, copynext_down),lv.EVENT.ALL, None)
copynext_print.add_event_cb(lambda e: load_print_finish_cb(e), lv.EVENT.ALL, None)
scanhome_btnscanback.add_event_cb(lambda e: load_disbtn_home_cb(e), lv.EVENT.ALL, None)
scanhome_btnscansave.add_event_cb(lambda e: load_save_cb(e), lv.EVENT.ALL, None)
scanhome_sliderhue.add_event_cb(lambda e: hue_slider_event_cb(e, scanhome_img3), lv.EVENT.ALL, None)
scanhome_sliderbright.add_event_cb(lambda e: lightness_slider_event_cb(e, scanhome_img3), lv.EVENT.ALL, None)
prthome_imgbtnusb.add_event_cb(load_print_usb_cb, lv.EVENT.ALL, None)
prthome_imgbtnmobile.add_event_cb(load_print_mobile_cb, lv.EVENT.ALL, None)
prthome_imgbtnit.add_event_cb(load_print_it_cb, lv.EVENT.ALL, None)
prthome_btnprintback.add_event_cb(load_disbtn_home_cb, lv.EVENT.ALL, None)
prtusb_back.add_event_cb(load_disbtn_home_cb, lv.EVENT.ALL, None)
prtusb_btnprint.add_event_cb(load_print_finish_cb, lv.EVENT.ALL, None)
prtusb_up.add_event_cb(lambda e: prtusb_counter_event_cb(e, prtusb_up),lv.EVENT.ALL, None)
prtusb_down.add_event_cb(lambda e: prtusb_counter_event_cb(e, prtusb_down),lv.EVENT.ALL, None)
prtmb_btnback.add_event_cb(load_disbtn_home_cb, lv.EVENT.ALL, None)
printit_btnprtitback.add_event_cb(load_disbtn_home_cb, lv.EVENT.ALL, None)
setup_btnsetback.add_event_cb(load_disbtn_home_cb, lv.EVENT.ALL, None)
saved_btnsavecontinue.add_event_cb(lambda e: load_disbtn_home_cb(e), lv.EVENT.ALL, None)
