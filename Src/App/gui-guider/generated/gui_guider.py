# Copyright 2022 NXP
# SPDX-License-Identifier: MIT
# The auto-generated can only be used on NXP devices

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct

lv.init()
SDL.init(w=480,h=320)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(480*10)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 480
disp_drv.ver_res = 320
disp_drv.register()

# Regsiter SDL mouse driver
indev_drv = lv.indev_drv_t()
indev_drv.init() 
indev_drv.type = lv.INDEV_TYPE.POINTER
indev_drv.read_cb = SDL.mouse_read
indev_drv.register()

# Below: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

COLOR_SIZE = lv.color_t.__SIZE__
COLOR_IS_SWAPPED = hasattr(lv.color_t().ch,'green_h')

class lodepng_error(RuntimeError):
    def __init__(self, err):
        if type(err) is int:
            super().__init__(png.error_text(err))
        else:
            super().__init__(err)

# Parse PNG file header
# Taken from https://github.com/shibukawa/imagesize_py/blob/ffef30c1a4715c5acf90e8945ceb77f4a2ed2d45/imagesize.py#L63-L85

def get_png_info(decoder, src, header):
    # Only handle variable image types

    if lv.img.src_get_type(src) != lv.img.SRC.VARIABLE:
        return lv.RES.INV

    data = lv.img_dsc_t.__cast__(src).data
    if data == None:
        return lv.RES.INV

    png_header = bytes(data.__dereference__(24))

    if png_header.startswith(b'\211PNG\r\n\032\n'):
        if png_header[12:16] == b'IHDR':
            start = 16
        # Maybe this is for an older PNG version.
        else:
            start = 8
        try:
            width, height = ustruct.unpack(">LL", png_header[start:start+8])
        except ustruct.error:
            return lv.RES.INV
    else:
        return lv.RES.INV

    header.always_zero = 0
    header.w = width
    header.h = height
    header.cf = lv.img.CF.TRUE_COLOR_ALPHA

    return lv.RES.OK

def convert_rgba8888_to_bgra8888(img_view):
    for i in range(0, len(img_view), lv.color_t.__SIZE__):
        ch = lv.color_t.__cast__(img_view[i:i]).ch
        ch.red, ch.blue = ch.blue, ch.red

# Read and parse PNG file

def open_png(decoder, dsc):
    img_dsc = lv.img_dsc_t.__cast__(dsc.src)
    png_data = img_dsc.data
    png_size = img_dsc.data_size
    png_decoded = png.C_Pointer()
    png_width = png.C_Pointer()
    png_height = png.C_Pointer()
    error = png.decode32(png_decoded, png_width, png_height, png_data, png_size)
    if error:
        raise lodepng_error(error)
    img_size = png_width.int_val * png_height.int_val * 4
    img_data = png_decoded.ptr_val
    img_view = img_data.__dereference__(img_size)

    if COLOR_SIZE == 4:
        convert_rgba8888_to_bgra8888(img_view)
    else:
        raise lodepng_error("Error: Color mode not supported yet!")

    dsc.img_data = img_data
    return lv.RES.OK

# Above: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

decoder = lv.img.decoder_create()
decoder.info_cb = get_png_info
decoder.open_cb = open_png

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def ta_event_cb(e,kb):
    code = e.get_code()
    ta = e.get_target()
    if code == lv.EVENT.FOCUSED:
        kb.set_textarea(ta)
        kb.move_foreground()
        kb.clear_flag(lv.obj.FLAG.HIDDEN)

    if code == lv.EVENT.DEFOCUSED:
        kb.set_textarea(None)
        kb.move_background()
        kb.add_flag(lv.obj.FLAG.HIDDEN)



# create home
home = lv.obj()
home.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_home_main_main_default
style_home_main_main_default = lv.style_t()
style_home_main_main_default.init()
style_home_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_home_main_main_default.set_bg_opa(0)

# add style for home
home.add_style(style_home_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create home_cont1
home_cont1 = lv.obj(home)
home_cont1.set_pos(int(0),int(0))
home_cont1.set_size(480,117)
home_cont1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_home_cont1_main_main_default
style_home_cont1_main_main_default = lv.style_t()
style_home_cont1_main_main_default.init()
style_home_cont1_main_main_default.set_radius(0)
style_home_cont1_main_main_default.set_bg_color(lv.color_make(0x2f,0x32,0x43))
style_home_cont1_main_main_default.set_bg_grad_color(lv.color_make(0x2f,0x32,0x43))
style_home_cont1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_home_cont1_main_main_default.set_bg_opa(255)
style_home_cont1_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_home_cont1_main_main_default.set_border_width(0)
style_home_cont1_main_main_default.set_border_opa(255)
style_home_cont1_main_main_default.set_pad_left(0)
style_home_cont1_main_main_default.set_pad_right(0)
style_home_cont1_main_main_default.set_pad_top(0)
style_home_cont1_main_main_default.set_pad_bottom(0)

# add style for home_cont1
home_cont1.add_style(style_home_cont1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create home_whitebg
home_whitebg = lv.obj(home)
home_whitebg.set_pos(int(0),int(117))
home_whitebg.set_size(480,202)
home_whitebg.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_home_whitebg_main_main_default
style_home_whitebg_main_main_default = lv.style_t()
style_home_whitebg_main_main_default.init()
style_home_whitebg_main_main_default.set_radius(0)
style_home_whitebg_main_main_default.set_bg_color(lv.color_make(0xd6,0xdc,0xd6))
style_home_whitebg_main_main_default.set_bg_grad_color(lv.color_make(0xd9,0xd9,0xd9))
style_home_whitebg_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_home_whitebg_main_main_default.set_bg_opa(255)
style_home_whitebg_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_home_whitebg_main_main_default.set_border_width(0)
style_home_whitebg_main_main_default.set_border_opa(255)
style_home_whitebg_main_main_default.set_pad_left(0)
style_home_whitebg_main_main_default.set_pad_right(0)
style_home_whitebg_main_main_default.set_pad_top(0)
style_home_whitebg_main_main_default.set_pad_bottom(0)

# add style for home_whitebg
home_whitebg.add_style(style_home_whitebg_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create home_cont2
home_cont2 = lv.obj(home)
home_cont2.set_pos(int(40),int(94))
home_cont2.set_size(380,141)
home_cont2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_home_cont2_main_main_default
style_home_cont2_main_main_default = lv.style_t()
style_home_cont2_main_main_default.init()
style_home_cont2_main_main_default.set_radius(0)
style_home_cont2_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_home_cont2_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_home_cont2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_home_cont2_main_main_default.set_bg_opa(255)
style_home_cont2_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_home_cont2_main_main_default.set_border_width(0)
style_home_cont2_main_main_default.set_border_opa(255)
style_home_cont2_main_main_default.set_pad_left(0)
style_home_cont2_main_main_default.set_pad_right(0)
style_home_cont2_main_main_default.set_pad_top(0)
style_home_cont2_main_main_default.set_pad_bottom(0)

# add style for home_cont2
home_cont2.add_style(style_home_cont2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create home_labeldate
home_labeldate = lv.label(home)
home_labeldate.set_pos(int(240),int(35))
home_labeldate.set_size(225,35)
home_labeldate.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_labeldate.set_text("20 Nov 2020 08:08")
home_labeldate.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_labeldate_main_main_default
style_home_labeldate_main_main_default = lv.style_t()
style_home_labeldate_main_main_default.init()
style_home_labeldate_main_main_default.set_radius(0)
style_home_labeldate_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_home_labeldate_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_home_labeldate_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_home_labeldate_main_main_default.set_bg_opa(0)
style_home_labeldate_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_home_labeldate_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_home_labeldate_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_home_labeldate_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_labeldate_main_main_default.set_text_letter_space(2)
style_home_labeldate_main_main_default.set_text_line_space(0)
style_home_labeldate_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_labeldate_main_main_default.set_pad_left(0)
style_home_labeldate_main_main_default.set_pad_right(0)
style_home_labeldate_main_main_default.set_pad_top(0)
style_home_labeldate_main_main_default.set_pad_bottom(0)

# add style for home_labeldate
home_labeldate.add_style(style_home_labeldate_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create home_imgbtncopy
home_imgbtncopy = lv.imgbtn(home)
home_imgbtncopy.set_pos(int(50),int(105))
home_imgbtncopy.set_size(85,117)
home_imgbtncopy.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1321466565.png','rb') as f:
        home_imgbtncopy_imgReleased_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1321466565.png')
    sys.exit()

home_imgbtncopy_imgReleased = lv.img_dsc_t({
  'data_size': len(home_imgbtncopy_imgReleased_data),
  'header': {'always_zero': 0, 'w': 85, 'h': 117, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgbtncopy_imgReleased_data
})
home_imgbtncopy.set_src(lv.imgbtn.STATE.RELEASED, None, home_imgbtncopy_imgReleased, None)

try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1321466565.png','rb') as f:
        home_imgbtncopy_imgPressed_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1321466565.png')
    sys.exit()

home_imgbtncopy_imgPressed = lv.img_dsc_t({
  'data_size': len(home_imgbtncopy_imgPressed_data),
  'header': {'always_zero': 0, 'w': 85, 'h': 117, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgbtncopy_imgPressed_data
})
home_imgbtncopy.set_src(lv.imgbtn.STATE.PRESSED, None, home_imgbtncopy_imgPressed, None)


try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1321466565.png','rb') as f:
        home_imgbtncopy_imgCheckedReleased_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1321466565.png')
    sys.exit()

home_imgbtncopy_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(home_imgbtncopy_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 85, 'h': 117, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgbtncopy_imgCheckedReleased_data
})
home_imgbtncopy.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, None, home_imgbtncopy_imgCheckedReleased, None)

try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1321466565.png','rb') as f:
        home_imgbtncopy_imgCheckedPressed_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1321466565.png')
    sys.exit()

home_imgbtncopy_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(home_imgbtncopy_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 85, 'h': 117, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgbtncopy_imgCheckedPressed_data
})
home_imgbtncopy.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, None, home_imgbtncopy_imgCheckedPressed, None)

# create style style_home_imgbtncopy_main_main_default
style_home_imgbtncopy_main_main_default = lv.style_t()
style_home_imgbtncopy_main_main_default.init()
style_home_imgbtncopy_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_imgbtncopy_main_main_default.set_text_font(lv.font_arial_12)
except AttributeError:
    try:
        style_home_imgbtncopy_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_imgbtncopy_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_imgbtncopy_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_imgbtncopy_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_home_imgbtncopy_main_main_default.set_img_recolor_opa(0)
style_home_imgbtncopy_main_main_default.set_img_opa(255)

# add style for home_imgbtncopy
home_imgbtncopy.add_style(style_home_imgbtncopy_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_home_imgbtncopy_main_main_pressed
style_home_imgbtncopy_main_main_pressed = lv.style_t()
style_home_imgbtncopy_main_main_pressed.init()
style_home_imgbtncopy_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_home_imgbtncopy_main_main_pressed.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_home_imgbtncopy_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_home_imgbtncopy_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_home_imgbtncopy_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_home_imgbtncopy_main_main_pressed.set_img_recolor_opa(0)
style_home_imgbtncopy_main_main_pressed.set_img_opa(255)

# add style for home_imgbtncopy
home_imgbtncopy.add_style(style_home_imgbtncopy_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_home_imgbtncopy_main_main_checked
style_home_imgbtncopy_main_main_checked = lv.style_t()
style_home_imgbtncopy_main_main_checked.init()
style_home_imgbtncopy_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_home_imgbtncopy_main_main_checked.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_home_imgbtncopy_main_main_checked.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_home_imgbtncopy_main_main_checked.set_text_font(lv.font_montserrat_16)
style_home_imgbtncopy_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_home_imgbtncopy_main_main_checked.set_img_recolor_opa(0)
style_home_imgbtncopy_main_main_checked.set_img_opa(255)

# add style for home_imgbtncopy
home_imgbtncopy.add_style(style_home_imgbtncopy_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)


# create home_labelcopy
home_labelcopy = lv.label(home)
home_labelcopy.set_pos(int(60),int(182))
home_labelcopy.set_size(62,23)
home_labelcopy.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_labelcopy.set_text("COPY")
home_labelcopy.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_labelcopy_main_main_default
style_home_labelcopy_main_main_default = lv.style_t()
style_home_labelcopy_main_main_default.init()
style_home_labelcopy_main_main_default.set_radius(0)
style_home_labelcopy_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_home_labelcopy_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_home_labelcopy_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_home_labelcopy_main_main_default.set_bg_opa(0)
style_home_labelcopy_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_home_labelcopy_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_home_labelcopy_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_home_labelcopy_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_labelcopy_main_main_default.set_text_letter_space(2)
style_home_labelcopy_main_main_default.set_text_line_space(0)
style_home_labelcopy_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_labelcopy_main_main_default.set_pad_left(0)
style_home_labelcopy_main_main_default.set_pad_right(0)
style_home_labelcopy_main_main_default.set_pad_top(0)
style_home_labelcopy_main_main_default.set_pad_bottom(0)

# add style for home_labelcopy
home_labelcopy.add_style(style_home_labelcopy_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create home_imgbtnset
home_imgbtnset = lv.imgbtn(home)
home_imgbtnset.set_pos(int(320),int(105))
home_imgbtnset.set_size(85,117)
home_imgbtnset.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1587409699.png','rb') as f:
        home_imgbtnset_imgReleased_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1587409699.png')
    sys.exit()

home_imgbtnset_imgReleased = lv.img_dsc_t({
  'data_size': len(home_imgbtnset_imgReleased_data),
  'header': {'always_zero': 0, 'w': 85, 'h': 117, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgbtnset_imgReleased_data
})
home_imgbtnset.set_src(lv.imgbtn.STATE.RELEASED, None, home_imgbtnset_imgReleased, None)

try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1587409699.png','rb') as f:
        home_imgbtnset_imgPressed_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1587409699.png')
    sys.exit()

home_imgbtnset_imgPressed = lv.img_dsc_t({
  'data_size': len(home_imgbtnset_imgPressed_data),
  'header': {'always_zero': 0, 'w': 85, 'h': 117, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgbtnset_imgPressed_data
})
home_imgbtnset.set_src(lv.imgbtn.STATE.PRESSED, None, home_imgbtnset_imgPressed, None)


try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1587409699.png','rb') as f:
        home_imgbtnset_imgCheckedReleased_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1587409699.png')
    sys.exit()

home_imgbtnset_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(home_imgbtnset_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 85, 'h': 117, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgbtnset_imgCheckedReleased_data
})
home_imgbtnset.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, None, home_imgbtnset_imgCheckedReleased, None)

try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1587409699.png','rb') as f:
        home_imgbtnset_imgCheckedPressed_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1587409699.png')
    sys.exit()

home_imgbtnset_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(home_imgbtnset_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 85, 'h': 117, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgbtnset_imgCheckedPressed_data
})
home_imgbtnset.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, None, home_imgbtnset_imgCheckedPressed, None)

# create style style_home_imgbtnset_main_main_default
style_home_imgbtnset_main_main_default = lv.style_t()
style_home_imgbtnset_main_main_default.init()
style_home_imgbtnset_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_imgbtnset_main_main_default.set_text_font(lv.font_arial_12)
except AttributeError:
    try:
        style_home_imgbtnset_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_imgbtnset_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_imgbtnset_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_imgbtnset_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_home_imgbtnset_main_main_default.set_img_recolor_opa(0)
style_home_imgbtnset_main_main_default.set_img_opa(255)

# add style for home_imgbtnset
home_imgbtnset.add_style(style_home_imgbtnset_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_home_imgbtnset_main_main_pressed
style_home_imgbtnset_main_main_pressed = lv.style_t()
style_home_imgbtnset_main_main_pressed.init()
style_home_imgbtnset_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_home_imgbtnset_main_main_pressed.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_home_imgbtnset_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_home_imgbtnset_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_home_imgbtnset_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_home_imgbtnset_main_main_pressed.set_img_recolor_opa(0)
style_home_imgbtnset_main_main_pressed.set_img_opa(255)

# add style for home_imgbtnset
home_imgbtnset.add_style(style_home_imgbtnset_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_home_imgbtnset_main_main_checked
style_home_imgbtnset_main_main_checked = lv.style_t()
style_home_imgbtnset_main_main_checked.init()
style_home_imgbtnset_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_home_imgbtnset_main_main_checked.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_home_imgbtnset_main_main_checked.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_home_imgbtnset_main_main_checked.set_text_font(lv.font_montserrat_16)
style_home_imgbtnset_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_home_imgbtnset_main_main_checked.set_img_recolor_opa(0)
style_home_imgbtnset_main_main_checked.set_img_opa(255)

# add style for home_imgbtnset
home_imgbtnset.add_style(style_home_imgbtnset_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)


# create home_imgbtnscan
home_imgbtnscan = lv.imgbtn(home)
home_imgbtnscan.set_pos(int(140),int(105))
home_imgbtnscan.set_size(85,117)
home_imgbtnscan.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1649449313.png','rb') as f:
        home_imgbtnscan_imgReleased_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1649449313.png')
    sys.exit()

home_imgbtnscan_imgReleased = lv.img_dsc_t({
  'data_size': len(home_imgbtnscan_imgReleased_data),
  'header': {'always_zero': 0, 'w': 85, 'h': 117, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgbtnscan_imgReleased_data
})
home_imgbtnscan.set_src(lv.imgbtn.STATE.RELEASED, None, home_imgbtnscan_imgReleased, None)

try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1649449313.png','rb') as f:
        home_imgbtnscan_imgPressed_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1649449313.png')
    sys.exit()

home_imgbtnscan_imgPressed = lv.img_dsc_t({
  'data_size': len(home_imgbtnscan_imgPressed_data),
  'header': {'always_zero': 0, 'w': 85, 'h': 117, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgbtnscan_imgPressed_data
})
home_imgbtnscan.set_src(lv.imgbtn.STATE.PRESSED, None, home_imgbtnscan_imgPressed, None)


try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1649449313.png','rb') as f:
        home_imgbtnscan_imgCheckedReleased_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1649449313.png')
    sys.exit()

home_imgbtnscan_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(home_imgbtnscan_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 85, 'h': 117, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgbtnscan_imgCheckedReleased_data
})
home_imgbtnscan.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, None, home_imgbtnscan_imgCheckedReleased, None)

try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1649449313.png','rb') as f:
        home_imgbtnscan_imgCheckedPressed_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1649449313.png')
    sys.exit()

home_imgbtnscan_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(home_imgbtnscan_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 85, 'h': 117, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgbtnscan_imgCheckedPressed_data
})
home_imgbtnscan.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, None, home_imgbtnscan_imgCheckedPressed, None)

# create style style_home_imgbtnscan_main_main_default
style_home_imgbtnscan_main_main_default = lv.style_t()
style_home_imgbtnscan_main_main_default.init()
style_home_imgbtnscan_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_imgbtnscan_main_main_default.set_text_font(lv.font_arial_12)
except AttributeError:
    try:
        style_home_imgbtnscan_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_imgbtnscan_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_imgbtnscan_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_imgbtnscan_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_home_imgbtnscan_main_main_default.set_img_recolor_opa(0)
style_home_imgbtnscan_main_main_default.set_img_opa(255)

# add style for home_imgbtnscan
home_imgbtnscan.add_style(style_home_imgbtnscan_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_home_imgbtnscan_main_main_pressed
style_home_imgbtnscan_main_main_pressed = lv.style_t()
style_home_imgbtnscan_main_main_pressed.init()
style_home_imgbtnscan_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_home_imgbtnscan_main_main_pressed.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_home_imgbtnscan_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_home_imgbtnscan_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_home_imgbtnscan_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_home_imgbtnscan_main_main_pressed.set_img_recolor_opa(0)
style_home_imgbtnscan_main_main_pressed.set_img_opa(255)

# add style for home_imgbtnscan
home_imgbtnscan.add_style(style_home_imgbtnscan_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_home_imgbtnscan_main_main_checked
style_home_imgbtnscan_main_main_checked = lv.style_t()
style_home_imgbtnscan_main_main_checked.init()
style_home_imgbtnscan_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_home_imgbtnscan_main_main_checked.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_home_imgbtnscan_main_main_checked.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_home_imgbtnscan_main_main_checked.set_text_font(lv.font_montserrat_16)
style_home_imgbtnscan_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_home_imgbtnscan_main_main_checked.set_img_recolor_opa(0)
style_home_imgbtnscan_main_main_checked.set_img_opa(255)

# add style for home_imgbtnscan
home_imgbtnscan.add_style(style_home_imgbtnscan_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)


# create home_imgbtnprt
home_imgbtnprt = lv.imgbtn(home)
home_imgbtnprt.set_pos(int(230),int(105))
home_imgbtnprt.set_size(85,117)
home_imgbtnprt.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1618429506.png','rb') as f:
        home_imgbtnprt_imgReleased_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1618429506.png')
    sys.exit()

home_imgbtnprt_imgReleased = lv.img_dsc_t({
  'data_size': len(home_imgbtnprt_imgReleased_data),
  'header': {'always_zero': 0, 'w': 85, 'h': 117, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgbtnprt_imgReleased_data
})
home_imgbtnprt.set_src(lv.imgbtn.STATE.RELEASED, None, home_imgbtnprt_imgReleased, None)

try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1618429506.png','rb') as f:
        home_imgbtnprt_imgPressed_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1618429506.png')
    sys.exit()

home_imgbtnprt_imgPressed = lv.img_dsc_t({
  'data_size': len(home_imgbtnprt_imgPressed_data),
  'header': {'always_zero': 0, 'w': 85, 'h': 117, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgbtnprt_imgPressed_data
})
home_imgbtnprt.set_src(lv.imgbtn.STATE.PRESSED, None, home_imgbtnprt_imgPressed, None)


try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1618429506.png','rb') as f:
        home_imgbtnprt_imgCheckedReleased_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1618429506.png')
    sys.exit()

home_imgbtnprt_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(home_imgbtnprt_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 85, 'h': 117, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgbtnprt_imgCheckedReleased_data
})
home_imgbtnprt.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, None, home_imgbtnprt_imgCheckedReleased, None)

try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1618429506.png','rb') as f:
        home_imgbtnprt_imgCheckedPressed_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1618429506.png')
    sys.exit()

home_imgbtnprt_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(home_imgbtnprt_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 85, 'h': 117, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgbtnprt_imgCheckedPressed_data
})
home_imgbtnprt.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, None, home_imgbtnprt_imgCheckedPressed, None)

# create style style_home_imgbtnprt_main_main_default
style_home_imgbtnprt_main_main_default = lv.style_t()
style_home_imgbtnprt_main_main_default.init()
style_home_imgbtnprt_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_imgbtnprt_main_main_default.set_text_font(lv.font_arial_12)
except AttributeError:
    try:
        style_home_imgbtnprt_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_imgbtnprt_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_imgbtnprt_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_imgbtnprt_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_home_imgbtnprt_main_main_default.set_img_recolor_opa(0)
style_home_imgbtnprt_main_main_default.set_img_opa(255)

# add style for home_imgbtnprt
home_imgbtnprt.add_style(style_home_imgbtnprt_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_home_imgbtnprt_main_main_pressed
style_home_imgbtnprt_main_main_pressed = lv.style_t()
style_home_imgbtnprt_main_main_pressed.init()
style_home_imgbtnprt_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_home_imgbtnprt_main_main_pressed.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_home_imgbtnprt_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_home_imgbtnprt_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_home_imgbtnprt_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_home_imgbtnprt_main_main_pressed.set_img_recolor_opa(0)
style_home_imgbtnprt_main_main_pressed.set_img_opa(255)

# add style for home_imgbtnprt
home_imgbtnprt.add_style(style_home_imgbtnprt_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_home_imgbtnprt_main_main_checked
style_home_imgbtnprt_main_main_checked = lv.style_t()
style_home_imgbtnprt_main_main_checked.init()
style_home_imgbtnprt_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_home_imgbtnprt_main_main_checked.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_home_imgbtnprt_main_main_checked.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_home_imgbtnprt_main_main_checked.set_text_font(lv.font_montserrat_16)
style_home_imgbtnprt_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_home_imgbtnprt_main_main_checked.set_img_recolor_opa(0)
style_home_imgbtnprt_main_main_checked.set_img_opa(255)

# add style for home_imgbtnprt
home_imgbtnprt.add_style(style_home_imgbtnprt_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)


# create home_labelscan
home_labelscan = lv.label(home)
home_labelscan.set_pos(int(150),int(182))
home_labelscan.set_size(60,23)
home_labelscan.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_labelscan.set_text("SCAN")
home_labelscan.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_labelscan_main_main_default
style_home_labelscan_main_main_default = lv.style_t()
style_home_labelscan_main_main_default.init()
style_home_labelscan_main_main_default.set_radius(0)
style_home_labelscan_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_home_labelscan_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_home_labelscan_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_home_labelscan_main_main_default.set_bg_opa(0)
style_home_labelscan_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_home_labelscan_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_home_labelscan_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_home_labelscan_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_labelscan_main_main_default.set_text_letter_space(2)
style_home_labelscan_main_main_default.set_text_line_space(0)
style_home_labelscan_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_labelscan_main_main_default.set_pad_left(0)
style_home_labelscan_main_main_default.set_pad_right(0)
style_home_labelscan_main_main_default.set_pad_top(0)
style_home_labelscan_main_main_default.set_pad_bottom(0)

# add style for home_labelscan
home_labelscan.add_style(style_home_labelscan_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create home_labelprt
home_labelprt = lv.label(home)
home_labelprt.set_pos(int(240),int(182))
home_labelprt.set_size(70,23)
home_labelprt.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_labelprt.set_text("PRINT")
home_labelprt.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_labelprt_main_main_default
style_home_labelprt_main_main_default = lv.style_t()
style_home_labelprt_main_main_default.init()
style_home_labelprt_main_main_default.set_radius(0)
style_home_labelprt_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_home_labelprt_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_home_labelprt_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_home_labelprt_main_main_default.set_bg_opa(0)
style_home_labelprt_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_home_labelprt_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_home_labelprt_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_home_labelprt_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_labelprt_main_main_default.set_text_letter_space(2)
style_home_labelprt_main_main_default.set_text_line_space(0)
style_home_labelprt_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_labelprt_main_main_default.set_pad_left(0)
style_home_labelprt_main_main_default.set_pad_right(0)
style_home_labelprt_main_main_default.set_pad_top(0)
style_home_labelprt_main_main_default.set_pad_bottom(0)

# add style for home_labelprt
home_labelprt.add_style(style_home_labelprt_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create home_labelset
home_labelset = lv.label(home)
home_labelset.set_pos(int(328),int(182))
home_labelset.set_size(75,23)
home_labelset.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_labelset.set_text("SETUP")
home_labelset.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_labelset_main_main_default
style_home_labelset_main_main_default = lv.style_t()
style_home_labelset_main_main_default.init()
style_home_labelset_main_main_default.set_radius(0)
style_home_labelset_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_home_labelset_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_home_labelset_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_home_labelset_main_main_default.set_bg_opa(0)
style_home_labelset_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_home_labelset_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_home_labelset_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_home_labelset_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_labelset_main_main_default.set_text_letter_space(2)
style_home_labelset_main_main_default.set_text_line_space(0)
style_home_labelset_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_labelset_main_main_default.set_pad_left(0)
style_home_labelset_main_main_default.set_pad_right(0)
style_home_labelset_main_main_default.set_pad_top(0)
style_home_labelset_main_main_default.set_pad_bottom(0)

# add style for home_labelset
home_labelset.add_style(style_home_labelset_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create home_labelnote
home_labelnote = lv.label(home)
home_labelnote.set_pos(int(16),int(264))
home_labelnote.set_size(276,23)
home_labelnote.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_labelnote.set_text("What do you want to do today?")
home_labelnote.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_labelnote_main_main_default
style_home_labelnote_main_main_default = lv.style_t()
style_home_labelnote_main_main_default.init()
style_home_labelnote_main_main_default.set_radius(0)
style_home_labelnote_main_main_default.set_bg_color(lv.color_make(0xf6,0xfa,0xff))
style_home_labelnote_main_main_default.set_bg_grad_color(lv.color_make(0xf6,0xfa,0xff))
style_home_labelnote_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_home_labelnote_main_main_default.set_bg_opa(0)
style_home_labelnote_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_labelnote_main_main_default.set_text_font(lv.font_arial_14)
except AttributeError:
    try:
        style_home_labelnote_main_main_default.set_text_font(lv.font_montserrat_14)
    except AttributeError:
        style_home_labelnote_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_labelnote_main_main_default.set_text_letter_space(2)
style_home_labelnote_main_main_default.set_text_line_space(0)
style_home_labelnote_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_labelnote_main_main_default.set_pad_left(0)
style_home_labelnote_main_main_default.set_pad_right(0)
style_home_labelnote_main_main_default.set_pad_top(0)
style_home_labelnote_main_main_default.set_pad_bottom(0)

# add style for home_labelnote
home_labelnote.add_style(style_home_labelnote_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create home_contbars
home_contbars = lv.obj(home)
home_contbars.set_pos(int(300),int(241))
home_contbars.set_size(150,58)
home_contbars.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_home_contbars_main_main_default
style_home_contbars_main_main_default = lv.style_t()
style_home_contbars_main_main_default.init()
style_home_contbars_main_main_default.set_radius(0)
style_home_contbars_main_main_default.set_bg_color(lv.color_make(0xde,0xde,0xde))
style_home_contbars_main_main_default.set_bg_grad_color(lv.color_make(0xd9,0xd9,0xd9))
style_home_contbars_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_home_contbars_main_main_default.set_bg_opa(255)
style_home_contbars_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_home_contbars_main_main_default.set_border_width(0)
style_home_contbars_main_main_default.set_border_opa(255)
style_home_contbars_main_main_default.set_pad_left(0)
style_home_contbars_main_main_default.set_pad_right(0)
style_home_contbars_main_main_default.set_pad_top(0)
style_home_contbars_main_main_default.set_pad_bottom(0)

# add style for home_contbars
home_contbars.add_style(style_home_contbars_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create home_bar1
home_bar1 = lv.bar(home)
home_bar1.set_pos(int(315),int(258))
home_bar1.set_size(20,35)
home_bar1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_bar1.set_style_anim_time(1000, 0)
home_bar1.set_mode(lv.bar.MODE.NORMAL)
home_bar1.set_value(60, lv.ANIM.ON)
# create style style_home_bar1_main_main_default
style_home_bar1_main_main_default = lv.style_t()
style_home_bar1_main_main_default.init()
style_home_bar1_main_main_default.set_radius(5)
style_home_bar1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_home_bar1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_home_bar1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_home_bar1_main_main_default.set_bg_opa(255)

# add style for home_bar1
home_bar1.add_style(style_home_bar1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_home_bar1_main_indicator_default
style_home_bar1_main_indicator_default = lv.style_t()
style_home_bar1_main_indicator_default.init()
style_home_bar1_main_indicator_default.set_radius(5)
style_home_bar1_main_indicator_default.set_bg_color(lv.color_make(0x2e,0xdc,0xb0))
style_home_bar1_main_indicator_default.set_bg_grad_color(lv.color_make(0x05,0xd6,0xa2))
style_home_bar1_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_home_bar1_main_indicator_default.set_bg_opa(255)

# add style for home_bar1
home_bar1.add_style(style_home_bar1_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)


# create home_bar2
home_bar2 = lv.bar(home)
home_bar2.set_pos(int(350),int(258))
home_bar2.set_size(20,35)
home_bar2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_bar2.set_style_anim_time(1000, 0)
home_bar2.set_mode(lv.bar.MODE.NORMAL)
home_bar2.set_value(40, lv.ANIM.ON)
# create style style_home_bar2_main_main_default
style_home_bar2_main_main_default = lv.style_t()
style_home_bar2_main_main_default.init()
style_home_bar2_main_main_default.set_radius(5)
style_home_bar2_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_home_bar2_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_home_bar2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_home_bar2_main_main_default.set_bg_opa(255)

# add style for home_bar2
home_bar2.add_style(style_home_bar2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_home_bar2_main_indicator_default
style_home_bar2_main_indicator_default = lv.style_t()
style_home_bar2_main_indicator_default.init()
style_home_bar2_main_indicator_default.set_radius(5)
style_home_bar2_main_indicator_default.set_bg_color(lv.color_make(0xe5,0xe9,0x07))
style_home_bar2_main_indicator_default.set_bg_grad_color(lv.color_make(0xf2,0xf6,0x09))
style_home_bar2_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_home_bar2_main_indicator_default.set_bg_opa(255)

# add style for home_bar2
home_bar2.add_style(style_home_bar2_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)


# create home_bar3
home_bar3 = lv.bar(home)
home_bar3.set_pos(int(385),int(258))
home_bar3.set_size(20,35)
home_bar3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_bar3.set_style_anim_time(1000, 0)
home_bar3.set_mode(lv.bar.MODE.NORMAL)
home_bar3.set_value(80, lv.ANIM.ON)
# create style style_home_bar3_main_main_default
style_home_bar3_main_main_default = lv.style_t()
style_home_bar3_main_main_default.init()
style_home_bar3_main_main_default.set_radius(5)
style_home_bar3_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_home_bar3_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_home_bar3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_home_bar3_main_main_default.set_bg_opa(255)

# add style for home_bar3
home_bar3.add_style(style_home_bar3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_home_bar3_main_indicator_default
style_home_bar3_main_indicator_default = lv.style_t()
style_home_bar3_main_indicator_default.init()
style_home_bar3_main_indicator_default.set_radius(5)
style_home_bar3_main_indicator_default.set_bg_color(lv.color_make(0xa2,0x0e,0xd8))
style_home_bar3_main_indicator_default.set_bg_grad_color(lv.color_make(0xae,0x00,0xd1))
style_home_bar3_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_home_bar3_main_indicator_default.set_bg_opa(255)

# add style for home_bar3
home_bar3.add_style(style_home_bar3_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)


# create home_bar4
home_bar4 = lv.bar(home)
home_bar4.set_pos(int(425),int(258))
home_bar4.set_size(20,35)
home_bar4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_bar4.set_style_anim_time(1000, 0)
home_bar4.set_mode(lv.bar.MODE.NORMAL)
home_bar4.set_value(30, lv.ANIM.ON)
# create style style_home_bar4_main_main_default
style_home_bar4_main_main_default = lv.style_t()
style_home_bar4_main_main_default.init()
style_home_bar4_main_main_default.set_radius(5)
style_home_bar4_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_home_bar4_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_home_bar4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_home_bar4_main_main_default.set_bg_opa(255)

# add style for home_bar4
home_bar4.add_style(style_home_bar4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_home_bar4_main_indicator_default
style_home_bar4_main_indicator_default = lv.style_t()
style_home_bar4_main_indicator_default.init()
style_home_bar4_main_indicator_default.set_radius(5)
style_home_bar4_main_indicator_default.set_bg_color(lv.color_make(0x98,0xe5,0x24))
style_home_bar4_main_indicator_default.set_bg_grad_color(lv.color_make(0x8c,0xed,0x2c))
style_home_bar4_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_home_bar4_main_indicator_default.set_bg_opa(255)

# add style for home_bar4
home_bar4.add_style(style_home_bar4_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)


# create home_wifi
home_wifi = lv.img(home)
home_wifi.set_pos(int(56),int(36))
home_wifi.set_size(29,22)
home_wifi.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_wifi.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-115793845.png','rb') as f:
        home_wifi_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-115793845.png')
    sys.exit()

home_wifi_img = lv.img_dsc_t({
  'data_size': len(home_wifi_img_data),
  'header': {'always_zero': 0, 'w': 29, 'h': 22, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_wifi_img_data
})

home_wifi.set_src(home_wifi_img)
home_wifi.set_pivot(0,0)
home_wifi.set_angle(0)
# create style style_home_wifi_main_main_default
style_home_wifi_main_main_default = lv.style_t()
style_home_wifi_main_main_default.init()
style_home_wifi_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_home_wifi_main_main_default.set_img_recolor_opa(0)
style_home_wifi_main_main_default.set_img_opa(255)

# add style for home_wifi
home_wifi.add_style(style_home_wifi_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create home_tel
home_tel = lv.img(home)
home_tel.set_pos(int(105),int(35))
home_tel.set_size(21,24)
home_tel.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_tel.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp765608813.png','rb') as f:
        home_tel_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp765608813.png')
    sys.exit()

home_tel_img = lv.img_dsc_t({
  'data_size': len(home_tel_img_data),
  'header': {'always_zero': 0, 'w': 21, 'h': 24, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_tel_img_data
})

home_tel.set_src(home_tel_img)
home_tel.set_pivot(0,0)
home_tel.set_angle(0)
# create style style_home_tel_main_main_default
style_home_tel_main_main_default = lv.style_t()
style_home_tel_main_main_default.init()
style_home_tel_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_home_tel_main_main_default.set_img_recolor_opa(0)
style_home_tel_main_main_default.set_img_opa(255)

# add style for home_tel
home_tel.add_style(style_home_tel_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create home_eco
home_eco = lv.img(home)
home_eco.set_pos(int(147),int(35))
home_eco.set_size(21,24)
home_eco.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_eco.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp1522567395.png','rb') as f:
        home_eco_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp1522567395.png')
    sys.exit()

home_eco_img = lv.img_dsc_t({
  'data_size': len(home_eco_img_data),
  'header': {'always_zero': 0, 'w': 21, 'h': 24, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_eco_img_data
})

home_eco.set_src(home_eco_img)
home_eco.set_pivot(0,0)
home_eco.set_angle(0)
# create style style_home_eco_main_main_default
style_home_eco_main_main_default = lv.style_t()
style_home_eco_main_main_default.init()
style_home_eco_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_home_eco_main_main_default.set_img_recolor_opa(0)
style_home_eco_main_main_default.set_img_opa(255)

# add style for home_eco
home_eco.add_style(style_home_eco_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create home_pc
home_pc = lv.img(home)
home_pc.set_pos(int(198),int(35))
home_pc.set_size(21,24)
home_pc.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_pc.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1282496797.png','rb') as f:
        home_pc_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1282496797.png')
    sys.exit()

home_pc_img = lv.img_dsc_t({
  'data_size': len(home_pc_img_data),
  'header': {'always_zero': 0, 'w': 21, 'h': 24, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_pc_img_data
})

home_pc.set_src(home_pc_img)
home_pc.set_pivot(0,0)
home_pc.set_angle(0)
# create style style_home_pc_main_main_default
style_home_pc_main_main_default = lv.style_t()
style_home_pc_main_main_default.init()
style_home_pc_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_home_pc_main_main_default.set_img_recolor_opa(0)
style_home_pc_main_main_default.set_img_opa(255)

# add style for home_pc
home_pc.add_style(style_home_pc_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create home_imgcopy
home_imgcopy = lv.img(home)
home_imgcopy.set_pos(int(90),int(127))
home_imgcopy.set_size(29,34)
home_imgcopy.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_imgcopy.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp1007853260.png','rb') as f:
        home_imgcopy_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp1007853260.png')
    sys.exit()

home_imgcopy_img = lv.img_dsc_t({
  'data_size': len(home_imgcopy_img_data),
  'header': {'always_zero': 0, 'w': 29, 'h': 34, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgcopy_img_data
})

home_imgcopy.set_src(home_imgcopy_img)
home_imgcopy.set_pivot(0,0)
home_imgcopy.set_angle(0)
# create style style_home_imgcopy_main_main_default
style_home_imgcopy_main_main_default = lv.style_t()
style_home_imgcopy_main_main_default.init()
style_home_imgcopy_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_home_imgcopy_main_main_default.set_img_recolor_opa(0)
style_home_imgcopy_main_main_default.set_img_opa(255)

# add style for home_imgcopy
home_imgcopy.add_style(style_home_imgcopy_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create home_imgscan
home_imgscan = lv.img(home)
home_imgscan.set_pos(int(180),int(127))
home_imgscan.set_size(29,34)
home_imgscan.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_imgscan.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-813228588.png','rb') as f:
        home_imgscan_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-813228588.png')
    sys.exit()

home_imgscan_img = lv.img_dsc_t({
  'data_size': len(home_imgscan_img_data),
  'header': {'always_zero': 0, 'w': 29, 'h': 34, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgscan_img_data
})

home_imgscan.set_src(home_imgscan_img)
home_imgscan.set_pivot(0,0)
home_imgscan.set_angle(0)
# create style style_home_imgscan_main_main_default
style_home_imgscan_main_main_default = lv.style_t()
style_home_imgscan_main_main_default.init()
style_home_imgscan_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_home_imgscan_main_main_default.set_img_recolor_opa(0)
style_home_imgscan_main_main_default.set_img_opa(255)

# add style for home_imgscan
home_imgscan.add_style(style_home_imgscan_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create home_imgprt
home_imgprt = lv.img(home)
home_imgprt.set_pos(int(270),int(127))
home_imgprt.set_size(29,34)
home_imgprt.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_imgprt.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp1531464678.png','rb') as f:
        home_imgprt_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp1531464678.png')
    sys.exit()

home_imgprt_img = lv.img_dsc_t({
  'data_size': len(home_imgprt_img_data),
  'header': {'always_zero': 0, 'w': 29, 'h': 34, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgprt_img_data
})

home_imgprt.set_src(home_imgprt_img)
home_imgprt.set_pivot(0,0)
home_imgprt.set_angle(0)
# create style style_home_imgprt_main_main_default
style_home_imgprt_main_main_default = lv.style_t()
style_home_imgprt_main_main_default.init()
style_home_imgprt_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_home_imgprt_main_main_default.set_img_recolor_opa(0)
style_home_imgprt_main_main_default.set_img_opa(255)

# add style for home_imgprt
home_imgprt.add_style(style_home_imgprt_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create home_imgset
home_imgset = lv.img(home)
home_imgset.set_pos(int(360),int(127))
home_imgset.set_size(29,34)
home_imgset.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_imgset.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp256271286.png','rb') as f:
        home_imgset_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp256271286.png')
    sys.exit()

home_imgset_img = lv.img_dsc_t({
  'data_size': len(home_imgset_img_data),
  'header': {'always_zero': 0, 'w': 29, 'h': 34, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgset_img_data
})

home_imgset.set_src(home_imgset_img)
home_imgset.set_pivot(0,0)
home_imgset.set_angle(0)
# create style style_home_imgset_main_main_default
style_home_imgset_main_main_default = lv.style_t()
style_home_imgset_main_main_default.init()
style_home_imgset_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_home_imgset_main_main_default.set_img_recolor_opa(0)
style_home_imgset_main_main_default.set_img_opa(255)

# add style for home_imgset
home_imgset.add_style(style_home_imgset_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copyhome
copyhome = lv.obj()
copyhome.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_copyhome_main_main_default
style_copyhome_main_main_default = lv.style_t()
style_copyhome_main_main_default.init()
style_copyhome_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_copyhome_main_main_default.set_bg_opa(0)

# add style for copyhome
copyhome.add_style(style_copyhome_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copyhome_cont1
copyhome_cont1 = lv.obj(copyhome)
copyhome_cont1.set_pos(int(0),int(0))
copyhome_cont1.set_size(480,117)
copyhome_cont1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_copyhome_cont1_main_main_default
style_copyhome_cont1_main_main_default = lv.style_t()
style_copyhome_cont1_main_main_default.init()
style_copyhome_cont1_main_main_default.set_radius(0)
style_copyhome_cont1_main_main_default.set_bg_color(lv.color_make(0x2f,0x32,0x43))
style_copyhome_cont1_main_main_default.set_bg_grad_color(lv.color_make(0x2f,0x32,0x43))
style_copyhome_cont1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copyhome_cont1_main_main_default.set_bg_opa(255)
style_copyhome_cont1_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_copyhome_cont1_main_main_default.set_border_width(0)
style_copyhome_cont1_main_main_default.set_border_opa(255)
style_copyhome_cont1_main_main_default.set_pad_left(0)
style_copyhome_cont1_main_main_default.set_pad_right(0)
style_copyhome_cont1_main_main_default.set_pad_top(0)
style_copyhome_cont1_main_main_default.set_pad_bottom(0)

# add style for copyhome_cont1
copyhome_cont1.add_style(style_copyhome_cont1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copyhome_cont2
copyhome_cont2 = lv.obj(copyhome)
copyhome_cont2.set_pos(int(0),int(117))
copyhome_cont2.set_size(480,202)
copyhome_cont2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_copyhome_cont2_main_main_default
style_copyhome_cont2_main_main_default = lv.style_t()
style_copyhome_cont2_main_main_default.init()
style_copyhome_cont2_main_main_default.set_radius(0)
style_copyhome_cont2_main_main_default.set_bg_color(lv.color_make(0xde,0xde,0xde))
style_copyhome_cont2_main_main_default.set_bg_grad_color(lv.color_make(0xde,0xde,0xde))
style_copyhome_cont2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copyhome_cont2_main_main_default.set_bg_opa(255)
style_copyhome_cont2_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_copyhome_cont2_main_main_default.set_border_width(0)
style_copyhome_cont2_main_main_default.set_border_opa(255)
style_copyhome_cont2_main_main_default.set_pad_left(0)
style_copyhome_cont2_main_main_default.set_pad_right(0)
style_copyhome_cont2_main_main_default.set_pad_top(0)
style_copyhome_cont2_main_main_default.set_pad_bottom(0)

# add style for copyhome_cont2
copyhome_cont2.add_style(style_copyhome_cont2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copyhome_label1
copyhome_label1 = lv.label(copyhome)
copyhome_label1.set_pos(int(136),int(35))
copyhome_label1.set_size(225,23)
copyhome_label1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
copyhome_label1.set_text("ADJUST IMAGE")
copyhome_label1.set_long_mode(lv.label.LONG.WRAP)
# create style style_copyhome_label1_main_main_default
style_copyhome_label1_main_main_default = lv.style_t()
style_copyhome_label1_main_main_default.init()
style_copyhome_label1_main_main_default.set_radius(0)
style_copyhome_label1_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_copyhome_label1_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_copyhome_label1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copyhome_label1_main_main_default.set_bg_opa(0)
style_copyhome_label1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_copyhome_label1_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_copyhome_label1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_copyhome_label1_main_main_default.set_text_font(lv.font_montserrat_16)
style_copyhome_label1_main_main_default.set_text_letter_space(2)
style_copyhome_label1_main_main_default.set_text_line_space(0)
style_copyhome_label1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_copyhome_label1_main_main_default.set_pad_left(0)
style_copyhome_label1_main_main_default.set_pad_right(0)
style_copyhome_label1_main_main_default.set_pad_top(0)
style_copyhome_label1_main_main_default.set_pad_bottom(0)

# add style for copyhome_label1
copyhome_label1.add_style(style_copyhome_label1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copyhome_img3
copyhome_img3 = lv.img(copyhome)
copyhome_img3.set_pos(int(27),int(88))
copyhome_img3.set_size(300,202)
copyhome_img3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
copyhome_img3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-625774500.png','rb') as f:
        copyhome_img3_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-625774500.png')
    sys.exit()

copyhome_img3_img = lv.img_dsc_t({
  'data_size': len(copyhome_img3_img_data),
  'header': {'always_zero': 0, 'w': 300, 'h': 202, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': copyhome_img3_img_data
})

copyhome_img3.set_src(copyhome_img3_img)
copyhome_img3.set_pivot(0,0)
copyhome_img3.set_angle(0)
# create style style_copyhome_img3_main_main_default
style_copyhome_img3_main_main_default = lv.style_t()
style_copyhome_img3_main_main_default.init()
style_copyhome_img3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_copyhome_img3_main_main_default.set_img_recolor_opa(0)
style_copyhome_img3_main_main_default.set_img_opa(255)

# add style for copyhome_img3
copyhome_img3.add_style(style_copyhome_img3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copyhome_cont4
copyhome_cont4 = lv.obj(copyhome)
copyhome_cont4.set_pos(int(368),int(94))
copyhome_cont4.set_size(80,152)
copyhome_cont4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_copyhome_cont4_main_main_default
style_copyhome_cont4_main_main_default = lv.style_t()
style_copyhome_cont4_main_main_default.init()
style_copyhome_cont4_main_main_default.set_radius(0)
style_copyhome_cont4_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_copyhome_cont4_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_copyhome_cont4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copyhome_cont4_main_main_default.set_bg_opa(255)
style_copyhome_cont4_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_copyhome_cont4_main_main_default.set_border_width(0)
style_copyhome_cont4_main_main_default.set_border_opa(255)
style_copyhome_cont4_main_main_default.set_pad_left(0)
style_copyhome_cont4_main_main_default.set_pad_right(0)
style_copyhome_cont4_main_main_default.set_pad_top(0)
style_copyhome_cont4_main_main_default.set_pad_bottom(0)

# add style for copyhome_cont4
copyhome_cont4.add_style(style_copyhome_cont4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copyhome_btncopynext
copyhome_btncopynext = lv.btn(copyhome)
copyhome_btncopynext.set_pos(int(368),int(260))
copyhome_btncopynext.set_size(80,47)
copyhome_btncopynext.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
copyhome_btncopynext_label = lv.label(copyhome_btncopynext)
copyhome_btncopynext_label.set_text("NEXT")
copyhome_btncopynext.set_style_pad_all(0, lv.STATE.DEFAULT)
copyhome_btncopynext_label.align(lv.ALIGN.CENTER,0,0)
# create style style_copyhome_btncopynext_main_main_default
style_copyhome_btncopynext_main_main_default = lv.style_t()
style_copyhome_btncopynext_main_main_default.init()
style_copyhome_btncopynext_main_main_default.set_radius(50)
style_copyhome_btncopynext_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_copyhome_btncopynext_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_copyhome_btncopynext_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copyhome_btncopynext_main_main_default.set_bg_opa(255)
style_copyhome_btncopynext_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_copyhome_btncopynext_main_main_default.set_border_width(0)
style_copyhome_btncopynext_main_main_default.set_border_opa(255)
style_copyhome_btncopynext_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_copyhome_btncopynext_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_copyhome_btncopynext_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_copyhome_btncopynext_main_main_default.set_text_font(lv.font_montserrat_16)
style_copyhome_btncopynext_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for copyhome_btncopynext
copyhome_btncopynext.add_style(style_copyhome_btncopynext_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copyhome_sliderhue
copyhome_sliderhue = lv.slider(copyhome)
copyhome_sliderhue.set_pos(int(420),int(135))
copyhome_sliderhue.set_size(8,94)
copyhome_sliderhue.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
copyhome_sliderhue.set_range(0, 100)
copyhome_sliderhue.set_value(50, False)

# create style style_copyhome_sliderhue_main_main_default
style_copyhome_sliderhue_main_main_default = lv.style_t()
style_copyhome_sliderhue_main_main_default.init()
style_copyhome_sliderhue_main_main_default.set_radius(50)
style_copyhome_sliderhue_main_main_default.set_bg_color(lv.color_make(0x2f,0x32,0x43))
style_copyhome_sliderhue_main_main_default.set_bg_grad_color(lv.color_make(0x2f,0x32,0x43))
style_copyhome_sliderhue_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copyhome_sliderhue_main_main_default.set_bg_opa(255)
style_copyhome_sliderhue_main_main_default.set_outline_color(lv.color_make(0x21,0x95,0xf6))
style_copyhome_sliderhue_main_main_default.set_outline_width(0)
style_copyhome_sliderhue_main_main_default.set_outline_opa(0)

# add style for copyhome_sliderhue
copyhome_sliderhue.add_style(style_copyhome_sliderhue_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_copyhome_sliderhue_main_indicator_default
style_copyhome_sliderhue_main_indicator_default = lv.style_t()
style_copyhome_sliderhue_main_indicator_default.init()
style_copyhome_sliderhue_main_indicator_default.set_radius(50)
style_copyhome_sliderhue_main_indicator_default.set_bg_color(lv.color_make(0xd4,0xd7,0xd9))
style_copyhome_sliderhue_main_indicator_default.set_bg_grad_color(lv.color_make(0xdd,0xd7,0xd9))
style_copyhome_sliderhue_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copyhome_sliderhue_main_indicator_default.set_bg_opa(255)

# add style for copyhome_sliderhue
copyhome_sliderhue.add_style(style_copyhome_sliderhue_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_copyhome_sliderhue_main_knob_default
style_copyhome_sliderhue_main_knob_default = lv.style_t()
style_copyhome_sliderhue_main_knob_default.init()
style_copyhome_sliderhue_main_knob_default.set_radius(50)
style_copyhome_sliderhue_main_knob_default.set_bg_color(lv.color_make(0x29,0x30,0x41))
style_copyhome_sliderhue_main_knob_default.set_bg_grad_color(lv.color_make(0x29,0x30,0x41))
style_copyhome_sliderhue_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copyhome_sliderhue_main_knob_default.set_bg_opa(255)

# add style for copyhome_sliderhue
copyhome_sliderhue.add_style(style_copyhome_sliderhue_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)


# create copyhome_sliderbright
copyhome_sliderbright = lv.slider(copyhome)
copyhome_sliderbright.set_pos(int(380),int(135))
copyhome_sliderbright.set_size(8,94)
copyhome_sliderbright.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
copyhome_sliderbright.set_range(0, 100)
copyhome_sliderbright.set_value(50, False)

# create style style_copyhome_sliderbright_main_main_default
style_copyhome_sliderbright_main_main_default = lv.style_t()
style_copyhome_sliderbright_main_main_default.init()
style_copyhome_sliderbright_main_main_default.set_radius(50)
style_copyhome_sliderbright_main_main_default.set_bg_color(lv.color_make(0x2f,0x32,0x43))
style_copyhome_sliderbright_main_main_default.set_bg_grad_color(lv.color_make(0x2f,0x32,0x43))
style_copyhome_sliderbright_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copyhome_sliderbright_main_main_default.set_bg_opa(255)
style_copyhome_sliderbright_main_main_default.set_outline_color(lv.color_make(0x21,0x95,0xf6))
style_copyhome_sliderbright_main_main_default.set_outline_width(0)
style_copyhome_sliderbright_main_main_default.set_outline_opa(0)

# add style for copyhome_sliderbright
copyhome_sliderbright.add_style(style_copyhome_sliderbright_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_copyhome_sliderbright_main_indicator_default
style_copyhome_sliderbright_main_indicator_default = lv.style_t()
style_copyhome_sliderbright_main_indicator_default.init()
style_copyhome_sliderbright_main_indicator_default.set_radius(50)
style_copyhome_sliderbright_main_indicator_default.set_bg_color(lv.color_make(0xd4,0xd7,0xd9))
style_copyhome_sliderbright_main_indicator_default.set_bg_grad_color(lv.color_make(0xdd,0xd7,0xd9))
style_copyhome_sliderbright_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copyhome_sliderbright_main_indicator_default.set_bg_opa(255)

# add style for copyhome_sliderbright
copyhome_sliderbright.add_style(style_copyhome_sliderbright_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_copyhome_sliderbright_main_knob_default
style_copyhome_sliderbright_main_knob_default = lv.style_t()
style_copyhome_sliderbright_main_knob_default.init()
style_copyhome_sliderbright_main_knob_default.set_radius(50)
style_copyhome_sliderbright_main_knob_default.set_bg_color(lv.color_make(0x29,0x30,0x41))
style_copyhome_sliderbright_main_knob_default.set_bg_grad_color(lv.color_make(0x29,0x30,0x41))
style_copyhome_sliderbright_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copyhome_sliderbright_main_knob_default.set_bg_opa(255)

# add style for copyhome_sliderbright
copyhome_sliderbright.add_style(style_copyhome_sliderbright_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)


# create copyhome_bright
copyhome_bright = lv.img(copyhome)
copyhome_bright.set_pos(int(372),int(96))
copyhome_bright.set_size(24,28)
copyhome_bright.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
copyhome_bright.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1514305359.png','rb') as f:
        copyhome_bright_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1514305359.png')
    sys.exit()

copyhome_bright_img = lv.img_dsc_t({
  'data_size': len(copyhome_bright_img_data),
  'header': {'always_zero': 0, 'w': 24, 'h': 28, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': copyhome_bright_img_data
})

copyhome_bright.set_src(copyhome_bright_img)
copyhome_bright.set_pivot(0,0)
copyhome_bright.set_angle(0)
# create style style_copyhome_bright_main_main_default
style_copyhome_bright_main_main_default = lv.style_t()
style_copyhome_bright_main_main_default.init()
style_copyhome_bright_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_copyhome_bright_main_main_default.set_img_recolor_opa(0)
style_copyhome_bright_main_main_default.set_img_opa(255)

# add style for copyhome_bright
copyhome_bright.add_style(style_copyhome_bright_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copyhome_hue
copyhome_hue = lv.img(copyhome)
copyhome_hue.set_pos(int(413),int(97))
copyhome_hue.set_size(21,24)
copyhome_hue.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
copyhome_hue.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-31944374.png','rb') as f:
        copyhome_hue_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-31944374.png')
    sys.exit()

copyhome_hue_img = lv.img_dsc_t({
  'data_size': len(copyhome_hue_img_data),
  'header': {'always_zero': 0, 'w': 21, 'h': 24, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': copyhome_hue_img_data
})

copyhome_hue.set_src(copyhome_hue_img)
copyhome_hue.set_pivot(0,0)
copyhome_hue.set_angle(0)
# create style style_copyhome_hue_main_main_default
style_copyhome_hue_main_main_default = lv.style_t()
style_copyhome_hue_main_main_default.init()
style_copyhome_hue_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_copyhome_hue_main_main_default.set_img_recolor_opa(0)
style_copyhome_hue_main_main_default.set_img_opa(255)

# add style for copyhome_hue
copyhome_hue.add_style(style_copyhome_hue_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copyhome_btncopyback
copyhome_btncopyback = lv.btn(copyhome)
copyhome_btncopyback.set_pos(int(50),int(29))
copyhome_btncopyback.set_size(30,35)
copyhome_btncopyback.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
copyhome_btncopyback_label = lv.label(copyhome_btncopyback)
copyhome_btncopyback_label.set_text("<")
copyhome_btncopyback.set_style_pad_all(0, lv.STATE.DEFAULT)
copyhome_btncopyback_label.align(lv.ALIGN.CENTER,0,0)
# create style style_copyhome_btncopyback_main_main_default
style_copyhome_btncopyback_main_main_default = lv.style_t()
style_copyhome_btncopyback_main_main_default.init()
style_copyhome_btncopyback_main_main_default.set_radius(50)
style_copyhome_btncopyback_main_main_default.set_bg_color(lv.color_make(0x2f,0x32,0x43))
style_copyhome_btncopyback_main_main_default.set_bg_grad_color(lv.color_make(0x2f,0x32,0x43))
style_copyhome_btncopyback_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copyhome_btncopyback_main_main_default.set_bg_opa(255)
style_copyhome_btncopyback_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_copyhome_btncopyback_main_main_default.set_border_width(0)
style_copyhome_btncopyback_main_main_default.set_border_opa(255)
style_copyhome_btncopyback_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_copyhome_btncopyback_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_copyhome_btncopyback_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_copyhome_btncopyback_main_main_default.set_text_font(lv.font_montserrat_16)
style_copyhome_btncopyback_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for copyhome_btncopyback
copyhome_btncopyback.add_style(style_copyhome_btncopyback_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copynext
copynext = lv.obj()
copynext.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_copynext_main_main_default
style_copynext_main_main_default = lv.style_t()
style_copynext_main_main_default.init()
style_copynext_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_copynext_main_main_default.set_bg_opa(0)

# add style for copynext
copynext.add_style(style_copynext_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copynext_cont1
copynext_cont1 = lv.obj(copynext)
copynext_cont1.set_pos(int(0),int(0))
copynext_cont1.set_size(480,117)
copynext_cont1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_copynext_cont1_main_main_default
style_copynext_cont1_main_main_default = lv.style_t()
style_copynext_cont1_main_main_default.init()
style_copynext_cont1_main_main_default.set_radius(0)
style_copynext_cont1_main_main_default.set_bg_color(lv.color_make(0x2f,0x32,0x43))
style_copynext_cont1_main_main_default.set_bg_grad_color(lv.color_make(0x2f,0x32,0x43))
style_copynext_cont1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_cont1_main_main_default.set_bg_opa(255)
style_copynext_cont1_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_copynext_cont1_main_main_default.set_border_width(0)
style_copynext_cont1_main_main_default.set_border_opa(255)
style_copynext_cont1_main_main_default.set_pad_left(0)
style_copynext_cont1_main_main_default.set_pad_right(0)
style_copynext_cont1_main_main_default.set_pad_top(0)
style_copynext_cont1_main_main_default.set_pad_bottom(0)

# add style for copynext_cont1
copynext_cont1.add_style(style_copynext_cont1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copynext_cont2
copynext_cont2 = lv.obj(copynext)
copynext_cont2.set_pos(int(0),int(117))
copynext_cont2.set_size(480,202)
copynext_cont2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_copynext_cont2_main_main_default
style_copynext_cont2_main_main_default = lv.style_t()
style_copynext_cont2_main_main_default.init()
style_copynext_cont2_main_main_default.set_radius(0)
style_copynext_cont2_main_main_default.set_bg_color(lv.color_make(0xde,0xde,0xde))
style_copynext_cont2_main_main_default.set_bg_grad_color(lv.color_make(0xde,0xde,0xde))
style_copynext_cont2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_cont2_main_main_default.set_bg_opa(255)
style_copynext_cont2_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_copynext_cont2_main_main_default.set_border_width(0)
style_copynext_cont2_main_main_default.set_border_opa(255)
style_copynext_cont2_main_main_default.set_pad_left(0)
style_copynext_cont2_main_main_default.set_pad_right(0)
style_copynext_cont2_main_main_default.set_pad_top(0)
style_copynext_cont2_main_main_default.set_pad_bottom(0)

# add style for copynext_cont2
copynext_cont2.add_style(style_copynext_cont2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copynext_label1
copynext_label1 = lv.label(copynext)
copynext_label1.set_pos(int(136),int(35))
copynext_label1.set_size(225,23)
copynext_label1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
copynext_label1.set_text("ADJUST IMAGE")
copynext_label1.set_long_mode(lv.label.LONG.WRAP)
# create style style_copynext_label1_main_main_default
style_copynext_label1_main_main_default = lv.style_t()
style_copynext_label1_main_main_default.init()
style_copynext_label1_main_main_default.set_radius(0)
style_copynext_label1_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_copynext_label1_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_copynext_label1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_label1_main_main_default.set_bg_opa(0)
style_copynext_label1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_copynext_label1_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_copynext_label1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_copynext_label1_main_main_default.set_text_font(lv.font_montserrat_16)
style_copynext_label1_main_main_default.set_text_letter_space(2)
style_copynext_label1_main_main_default.set_text_line_space(0)
style_copynext_label1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_copynext_label1_main_main_default.set_pad_left(0)
style_copynext_label1_main_main_default.set_pad_right(0)
style_copynext_label1_main_main_default.set_pad_top(0)
style_copynext_label1_main_main_default.set_pad_bottom(0)

# add style for copynext_label1
copynext_label1.add_style(style_copynext_label1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copynext_img3
copynext_img3 = lv.img(copynext)
copynext_img3.set_pos(int(27),int(88))
copynext_img3.set_size(250,161)
copynext_img3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
copynext_img3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp272731706.png','rb') as f:
        copynext_img3_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp272731706.png')
    sys.exit()

copynext_img3_img = lv.img_dsc_t({
  'data_size': len(copynext_img3_img_data),
  'header': {'always_zero': 0, 'w': 250, 'h': 161, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': copynext_img3_img_data
})

copynext_img3.set_src(copynext_img3_img)
copynext_img3.set_pivot(0,0)
copynext_img3.set_angle(0)
# create style style_copynext_img3_main_main_default
style_copynext_img3_main_main_default = lv.style_t()
style_copynext_img3_main_main_default.init()
style_copynext_img3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_copynext_img3_main_main_default.set_img_recolor_opa(0)
style_copynext_img3_main_main_default.set_img_opa(255)

# add style for copynext_img3
copynext_img3.add_style(style_copynext_img3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copynext_cont4
copynext_cont4 = lv.obj(copynext)
copynext_cont4.set_pos(int(305),int(94))
copynext_cont4.set_size(150,152)
copynext_cont4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_copynext_cont4_main_main_default
style_copynext_cont4_main_main_default = lv.style_t()
style_copynext_cont4_main_main_default.init()
style_copynext_cont4_main_main_default.set_radius(0)
style_copynext_cont4_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_copynext_cont4_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_copynext_cont4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_cont4_main_main_default.set_bg_opa(255)
style_copynext_cont4_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_copynext_cont4_main_main_default.set_border_width(0)
style_copynext_cont4_main_main_default.set_border_opa(255)
style_copynext_cont4_main_main_default.set_pad_left(0)
style_copynext_cont4_main_main_default.set_pad_right(0)
style_copynext_cont4_main_main_default.set_pad_top(0)
style_copynext_cont4_main_main_default.set_pad_bottom(0)

# add style for copynext_cont4
copynext_cont4.add_style(style_copynext_cont4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copynext_ddlist2
copynext_ddlist2 = lv.dropdown(copynext)
copynext_ddlist2.set_pos(int(166),int(268))
copynext_ddlist2.set_size(100,23)
copynext_ddlist2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
copynext_ddlist2.set_options("72 DPI\n96 DPI\n150 DPI\n300 DPI\n600 DPI\n900 DPI\n1200 DPI")

copynext_ddlist2_list = copynext_ddlist2.get_list()
# create style style_copynext_ddlist2_extra_list_selected_checked
style_copynext_ddlist2_extra_list_selected_checked = lv.style_t()
style_copynext_ddlist2_extra_list_selected_checked.init()
style_copynext_ddlist2_extra_list_selected_checked.set_radius(3)
style_copynext_ddlist2_extra_list_selected_checked.set_bg_color(lv.color_make(0x00,0xa1,0xb5))
style_copynext_ddlist2_extra_list_selected_checked.set_bg_grad_color(lv.color_make(0x00,0xa1,0xb5))
style_copynext_ddlist2_extra_list_selected_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_copynext_ddlist2_extra_list_selected_checked.set_bg_opa(255)
style_copynext_ddlist2_extra_list_selected_checked.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_copynext_ddlist2_extra_list_selected_checked.set_border_width(1)
style_copynext_ddlist2_extra_list_selected_checked.set_border_opa(255)
style_copynext_ddlist2_extra_list_selected_checked.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_copynext_ddlist2_extra_list_selected_checked.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_copynext_ddlist2_extra_list_selected_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_copynext_ddlist2_extra_list_selected_checked.set_text_font(lv.font_montserrat_16)

# add style for copynext_ddlist2_list
copynext_ddlist2_list.add_style(style_copynext_ddlist2_extra_list_selected_checked, lv.PART.SELECTED|lv.STATE.CHECKED)

# create style style_copynext_ddlist2_extra_list_main_default
style_copynext_ddlist2_extra_list_main_default = lv.style_t()
style_copynext_ddlist2_extra_list_main_default.init()
style_copynext_ddlist2_extra_list_main_default.set_radius(3)
style_copynext_ddlist2_extra_list_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_copynext_ddlist2_extra_list_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_copynext_ddlist2_extra_list_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_ddlist2_extra_list_main_default.set_bg_opa(255)
style_copynext_ddlist2_extra_list_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_copynext_ddlist2_extra_list_main_default.set_border_width(1)
style_copynext_ddlist2_extra_list_main_default.set_border_opa(255)
style_copynext_ddlist2_extra_list_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_copynext_ddlist2_extra_list_main_default.set_text_font(lv.font_arial_12)
except AttributeError:
    try:
        style_copynext_ddlist2_extra_list_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_copynext_ddlist2_extra_list_main_default.set_text_font(lv.font_montserrat_16)
style_copynext_ddlist2_extra_list_main_default.set_max_height(90)

# add style for copynext_ddlist2_list
copynext_ddlist2_list.add_style(style_copynext_ddlist2_extra_list_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_copynext_ddlist2_extra_list_scrollbar_default
style_copynext_ddlist2_extra_list_scrollbar_default = lv.style_t()
style_copynext_ddlist2_extra_list_scrollbar_default.init()
style_copynext_ddlist2_extra_list_scrollbar_default.set_radius(3)
style_copynext_ddlist2_extra_list_scrollbar_default.set_bg_color(lv.color_make(0x00,0xff,0x00))
style_copynext_ddlist2_extra_list_scrollbar_default.set_bg_opa(255)

# add style for copynext_ddlist2_list
copynext_ddlist2_list.add_style(style_copynext_ddlist2_extra_list_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

# create style style_copynext_ddlist2_main_main_default
style_copynext_ddlist2_main_main_default = lv.style_t()
style_copynext_ddlist2_main_main_default.init()
style_copynext_ddlist2_main_main_default.set_radius(3)
style_copynext_ddlist2_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_copynext_ddlist2_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_copynext_ddlist2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_ddlist2_main_main_default.set_bg_opa(255)
style_copynext_ddlist2_main_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_copynext_ddlist2_main_main_default.set_border_width(1)
style_copynext_ddlist2_main_main_default.set_border_opa(255)
style_copynext_ddlist2_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_copynext_ddlist2_main_main_default.set_text_font(lv.font_arial_12)
except AttributeError:
    try:
        style_copynext_ddlist2_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_copynext_ddlist2_main_main_default.set_text_font(lv.font_montserrat_16)
style_copynext_ddlist2_main_main_default.set_pad_left(6)
style_copynext_ddlist2_main_main_default.set_pad_right(6)
style_copynext_ddlist2_main_main_default.set_pad_top(0)

# add style for copynext_ddlist2
copynext_ddlist2.add_style(style_copynext_ddlist2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copynext_btncopyback
copynext_btncopyback = lv.btn(copynext)
copynext_btncopyback.set_pos(int(50),int(29))
copynext_btncopyback.set_size(30,35)
copynext_btncopyback.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
copynext_btncopyback_label = lv.label(copynext_btncopyback)
copynext_btncopyback_label.set_text("<")
copynext_btncopyback.set_style_pad_all(0, lv.STATE.DEFAULT)
copynext_btncopyback_label.align(lv.ALIGN.CENTER,0,0)
# create style style_copynext_btncopyback_main_main_default
style_copynext_btncopyback_main_main_default = lv.style_t()
style_copynext_btncopyback_main_main_default.init()
style_copynext_btncopyback_main_main_default.set_radius(50)
style_copynext_btncopyback_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_copynext_btncopyback_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_copynext_btncopyback_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_btncopyback_main_main_default.set_bg_opa(0)
style_copynext_btncopyback_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_copynext_btncopyback_main_main_default.set_border_width(0)
style_copynext_btncopyback_main_main_default.set_border_opa(255)
style_copynext_btncopyback_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_copynext_btncopyback_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_copynext_btncopyback_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_copynext_btncopyback_main_main_default.set_text_font(lv.font_montserrat_16)
style_copynext_btncopyback_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for copynext_btncopyback
copynext_btncopyback.add_style(style_copynext_btncopyback_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copynext_swcolor
copynext_swcolor = lv.switch(copynext)
copynext_swcolor.set_pos(int(323),int(205))
copynext_swcolor.set_size(40,23)
copynext_swcolor.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_copynext_swcolor_main_main_default
style_copynext_swcolor_main_main_default = lv.style_t()
style_copynext_swcolor_main_main_default.init()
style_copynext_swcolor_main_main_default.set_radius(100)
style_copynext_swcolor_main_main_default.set_bg_color(lv.color_make(0xd4,0xd7,0xd9))
style_copynext_swcolor_main_main_default.set_bg_grad_color(lv.color_make(0xd4,0xd7,0xd9))
style_copynext_swcolor_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_swcolor_main_main_default.set_bg_opa(255)
style_copynext_swcolor_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_copynext_swcolor_main_main_default.set_border_width(0)
style_copynext_swcolor_main_main_default.set_border_opa(255)

# add style for copynext_swcolor
copynext_swcolor.add_style(style_copynext_swcolor_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_copynext_swcolor_main_indicator_checked
style_copynext_swcolor_main_indicator_checked = lv.style_t()
style_copynext_swcolor_main_indicator_checked.init()
style_copynext_swcolor_main_indicator_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_copynext_swcolor_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_copynext_swcolor_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_swcolor_main_indicator_checked.set_bg_opa(255)
style_copynext_swcolor_main_indicator_checked.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_copynext_swcolor_main_indicator_checked.set_border_width(0)
style_copynext_swcolor_main_indicator_checked.set_border_opa(255)

# add style for copynext_swcolor
copynext_swcolor.add_style(style_copynext_swcolor_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

# create style style_copynext_swcolor_main_knob_default
style_copynext_swcolor_main_knob_default = lv.style_t()
style_copynext_swcolor_main_knob_default.init()
style_copynext_swcolor_main_knob_default.set_radius(100)
style_copynext_swcolor_main_knob_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_copynext_swcolor_main_knob_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_copynext_swcolor_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_swcolor_main_knob_default.set_bg_opa(255)
style_copynext_swcolor_main_knob_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_copynext_swcolor_main_knob_default.set_border_width(0)
style_copynext_swcolor_main_knob_default.set_border_opa(255)

# add style for copynext_swcolor
copynext_swcolor.add_style(style_copynext_swcolor_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)


# create copynext_labelcopy
copynext_labelcopy = lv.label(copynext)
copynext_labelcopy.set_pos(int(346),int(101))
copynext_labelcopy.set_size(64,23)
copynext_labelcopy.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
copynext_labelcopy.set_text("Copies")
copynext_labelcopy.set_long_mode(lv.label.LONG.WRAP)
# create style style_copynext_labelcopy_main_main_default
style_copynext_labelcopy_main_main_default = lv.style_t()
style_copynext_labelcopy_main_main_default.init()
style_copynext_labelcopy_main_main_default.set_radius(0)
style_copynext_labelcopy_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_copynext_labelcopy_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_copynext_labelcopy_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_labelcopy_main_main_default.set_bg_opa(0)
style_copynext_labelcopy_main_main_default.set_text_color(lv.color_make(0x20,0x18,0x18))
try:
    style_copynext_labelcopy_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_copynext_labelcopy_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_copynext_labelcopy_main_main_default.set_text_font(lv.font_montserrat_16)
style_copynext_labelcopy_main_main_default.set_text_letter_space(2)
style_copynext_labelcopy_main_main_default.set_text_line_space(0)
style_copynext_labelcopy_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_copynext_labelcopy_main_main_default.set_pad_left(0)
style_copynext_labelcopy_main_main_default.set_pad_right(0)
style_copynext_labelcopy_main_main_default.set_pad_top(0)
style_copynext_labelcopy_main_main_default.set_pad_bottom(0)

# add style for copynext_labelcopy
copynext_labelcopy.add_style(style_copynext_labelcopy_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copynext_up
copynext_up = lv.btn(copynext)
copynext_up.set_pos(int(417),int(129))
copynext_up.set_size(20,23)
copynext_up.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
copynext_up_label = lv.label(copynext_up)
copynext_up_label.set_text("+")
copynext_up.set_style_pad_all(0, lv.STATE.DEFAULT)
copynext_up_label.align(lv.ALIGN.CENTER,0,0)
# create style style_copynext_up_main_main_default
style_copynext_up_main_main_default = lv.style_t()
style_copynext_up_main_main_default.init()
style_copynext_up_main_main_default.set_radius(4)
style_copynext_up_main_main_default.set_bg_color(lv.color_make(0x2f,0x32,0x43))
style_copynext_up_main_main_default.set_bg_grad_color(lv.color_make(0x2f,0x32,0x43))
style_copynext_up_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_up_main_main_default.set_bg_opa(255)
style_copynext_up_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_copynext_up_main_main_default.set_border_width(0)
style_copynext_up_main_main_default.set_border_opa(255)
style_copynext_up_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_copynext_up_main_main_default.set_text_font(lv.font_simsun_18)
except AttributeError:
    try:
        style_copynext_up_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_copynext_up_main_main_default.set_text_font(lv.font_montserrat_16)
style_copynext_up_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for copynext_up
copynext_up.add_style(style_copynext_up_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copynext_down
copynext_down = lv.btn(copynext)
copynext_down.set_pos(int(322),int(129))
copynext_down.set_size(20,23)
copynext_down.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
copynext_down_label = lv.label(copynext_down)
copynext_down_label.set_text("-")
copynext_down.set_style_pad_all(0, lv.STATE.DEFAULT)
copynext_down_label.align(lv.ALIGN.CENTER,0,0)
# create style style_copynext_down_main_main_default
style_copynext_down_main_main_default = lv.style_t()
style_copynext_down_main_main_default.init()
style_copynext_down_main_main_default.set_radius(4)
style_copynext_down_main_main_default.set_bg_color(lv.color_make(0x2f,0x32,0x43))
style_copynext_down_main_main_default.set_bg_grad_color(lv.color_make(0x2f,0x32,0x43))
style_copynext_down_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_down_main_main_default.set_bg_opa(255)
style_copynext_down_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_copynext_down_main_main_default.set_border_width(0)
style_copynext_down_main_main_default.set_border_opa(255)
style_copynext_down_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_copynext_down_main_main_default.set_text_font(lv.font_simsun_18)
except AttributeError:
    try:
        style_copynext_down_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_copynext_down_main_main_default.set_text_font(lv.font_montserrat_16)
style_copynext_down_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for copynext_down
copynext_down.add_style(style_copynext_down_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copynext_labelcnt
copynext_labelcnt = lv.label(copynext)
copynext_labelcnt.set_pos(int(348),int(132))
copynext_labelcnt.set_size(56,23)
copynext_labelcnt.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
copynext_labelcnt.set_text("1")
copynext_labelcnt.set_long_mode(lv.label.LONG.WRAP)
# create style style_copynext_labelcnt_main_main_default
style_copynext_labelcnt_main_main_default = lv.style_t()
style_copynext_labelcnt_main_main_default.init()
style_copynext_labelcnt_main_main_default.set_radius(0)
style_copynext_labelcnt_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_copynext_labelcnt_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_copynext_labelcnt_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_labelcnt_main_main_default.set_bg_opa(0)
style_copynext_labelcnt_main_main_default.set_text_color(lv.color_make(0x0a,0x06,0x06))
try:
    style_copynext_labelcnt_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_copynext_labelcnt_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_copynext_labelcnt_main_main_default.set_text_font(lv.font_montserrat_16)
style_copynext_labelcnt_main_main_default.set_text_letter_space(2)
style_copynext_labelcnt_main_main_default.set_text_line_space(0)
style_copynext_labelcnt_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_copynext_labelcnt_main_main_default.set_pad_left(0)
style_copynext_labelcnt_main_main_default.set_pad_right(0)
style_copynext_labelcnt_main_main_default.set_pad_top(0)
style_copynext_labelcnt_main_main_default.set_pad_bottom(0)

# add style for copynext_labelcnt
copynext_labelcnt.add_style(style_copynext_labelcnt_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copynext_labelcolor
copynext_labelcolor = lv.label(copynext)
copynext_labelcolor.set_pos(int(314),int(171))
copynext_labelcolor.set_size(50,23)
copynext_labelcolor.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
copynext_labelcolor.set_text("Color")
copynext_labelcolor.set_long_mode(lv.label.LONG.WRAP)
# create style style_copynext_labelcolor_main_main_default
style_copynext_labelcolor_main_main_default = lv.style_t()
style_copynext_labelcolor_main_main_default.init()
style_copynext_labelcolor_main_main_default.set_radius(0)
style_copynext_labelcolor_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_copynext_labelcolor_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_copynext_labelcolor_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_labelcolor_main_main_default.set_bg_opa(0)
style_copynext_labelcolor_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_copynext_labelcolor_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_copynext_labelcolor_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_copynext_labelcolor_main_main_default.set_text_font(lv.font_montserrat_16)
style_copynext_labelcolor_main_main_default.set_text_letter_space(2)
style_copynext_labelcolor_main_main_default.set_text_line_space(0)
style_copynext_labelcolor_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_copynext_labelcolor_main_main_default.set_pad_left(0)
style_copynext_labelcolor_main_main_default.set_pad_right(0)
style_copynext_labelcolor_main_main_default.set_pad_top(0)
style_copynext_labelcolor_main_main_default.set_pad_bottom(0)

# add style for copynext_labelcolor
copynext_labelcolor.add_style(style_copynext_labelcolor_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copynext_labelvert
copynext_labelvert = lv.label(copynext)
copynext_labelvert.set_pos(int(380),int(171))
copynext_labelvert.set_size(70,23)
copynext_labelvert.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
copynext_labelvert.set_text("Vertical")
copynext_labelvert.set_long_mode(lv.label.LONG.WRAP)
# create style style_copynext_labelvert_main_main_default
style_copynext_labelvert_main_main_default = lv.style_t()
style_copynext_labelvert_main_main_default.init()
style_copynext_labelvert_main_main_default.set_radius(0)
style_copynext_labelvert_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_copynext_labelvert_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_copynext_labelvert_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_labelvert_main_main_default.set_bg_opa(0)
style_copynext_labelvert_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_copynext_labelvert_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_copynext_labelvert_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_copynext_labelvert_main_main_default.set_text_font(lv.font_montserrat_16)
style_copynext_labelvert_main_main_default.set_text_letter_space(2)
style_copynext_labelvert_main_main_default.set_text_line_space(0)
style_copynext_labelvert_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_copynext_labelvert_main_main_default.set_pad_left(0)
style_copynext_labelvert_main_main_default.set_pad_right(0)
style_copynext_labelvert_main_main_default.set_pad_top(0)
style_copynext_labelvert_main_main_default.set_pad_bottom(0)

# add style for copynext_labelvert
copynext_labelvert.add_style(style_copynext_labelvert_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copynext_swvert
copynext_swvert = lv.switch(copynext)
copynext_swvert.set_pos(int(390),int(205))
copynext_swvert.set_size(40,23)
copynext_swvert.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_copynext_swvert_main_main_default
style_copynext_swvert_main_main_default = lv.style_t()
style_copynext_swvert_main_main_default.init()
style_copynext_swvert_main_main_default.set_radius(100)
style_copynext_swvert_main_main_default.set_bg_color(lv.color_make(0xd4,0xd7,0xd9))
style_copynext_swvert_main_main_default.set_bg_grad_color(lv.color_make(0xd4,0xd7,0xd9))
style_copynext_swvert_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_swvert_main_main_default.set_bg_opa(255)
style_copynext_swvert_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_copynext_swvert_main_main_default.set_border_width(0)
style_copynext_swvert_main_main_default.set_border_opa(255)

# add style for copynext_swvert
copynext_swvert.add_style(style_copynext_swvert_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_copynext_swvert_main_indicator_checked
style_copynext_swvert_main_indicator_checked = lv.style_t()
style_copynext_swvert_main_indicator_checked.init()
style_copynext_swvert_main_indicator_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_copynext_swvert_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_copynext_swvert_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_swvert_main_indicator_checked.set_bg_opa(255)
style_copynext_swvert_main_indicator_checked.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_copynext_swvert_main_indicator_checked.set_border_width(0)
style_copynext_swvert_main_indicator_checked.set_border_opa(255)

# add style for copynext_swvert
copynext_swvert.add_style(style_copynext_swvert_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

# create style style_copynext_swvert_main_knob_default
style_copynext_swvert_main_knob_default = lv.style_t()
style_copynext_swvert_main_knob_default.init()
style_copynext_swvert_main_knob_default.set_radius(100)
style_copynext_swvert_main_knob_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_copynext_swvert_main_knob_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_copynext_swvert_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_swvert_main_knob_default.set_bg_opa(255)
style_copynext_swvert_main_knob_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_copynext_swvert_main_knob_default.set_border_width(0)
style_copynext_swvert_main_knob_default.set_border_opa(255)

# add style for copynext_swvert
copynext_swvert.add_style(style_copynext_swvert_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)


# create copynext_ddlist1
copynext_ddlist1 = lv.dropdown(copynext)
copynext_ddlist1.set_pos(int(31),int(267))
copynext_ddlist1.set_size(100,23)
copynext_ddlist1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
copynext_ddlist1.set_options("Best\nNormal\nDraft")

copynext_ddlist1_list = copynext_ddlist1.get_list()
# create style style_copynext_ddlist1_extra_list_selected_checked
style_copynext_ddlist1_extra_list_selected_checked = lv.style_t()
style_copynext_ddlist1_extra_list_selected_checked.init()
style_copynext_ddlist1_extra_list_selected_checked.set_radius(3)
style_copynext_ddlist1_extra_list_selected_checked.set_bg_color(lv.color_make(0x00,0xa1,0xb5))
style_copynext_ddlist1_extra_list_selected_checked.set_bg_grad_color(lv.color_make(0x00,0xa1,0xb5))
style_copynext_ddlist1_extra_list_selected_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_copynext_ddlist1_extra_list_selected_checked.set_bg_opa(255)
style_copynext_ddlist1_extra_list_selected_checked.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_copynext_ddlist1_extra_list_selected_checked.set_border_width(1)
style_copynext_ddlist1_extra_list_selected_checked.set_border_opa(255)
style_copynext_ddlist1_extra_list_selected_checked.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_copynext_ddlist1_extra_list_selected_checked.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_copynext_ddlist1_extra_list_selected_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_copynext_ddlist1_extra_list_selected_checked.set_text_font(lv.font_montserrat_16)

# add style for copynext_ddlist1_list
copynext_ddlist1_list.add_style(style_copynext_ddlist1_extra_list_selected_checked, lv.PART.SELECTED|lv.STATE.CHECKED)

# create style style_copynext_ddlist1_extra_list_main_default
style_copynext_ddlist1_extra_list_main_default = lv.style_t()
style_copynext_ddlist1_extra_list_main_default.init()
style_copynext_ddlist1_extra_list_main_default.set_radius(3)
style_copynext_ddlist1_extra_list_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_copynext_ddlist1_extra_list_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_copynext_ddlist1_extra_list_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_ddlist1_extra_list_main_default.set_bg_opa(255)
style_copynext_ddlist1_extra_list_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_copynext_ddlist1_extra_list_main_default.set_border_width(1)
style_copynext_ddlist1_extra_list_main_default.set_border_opa(255)
style_copynext_ddlist1_extra_list_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_copynext_ddlist1_extra_list_main_default.set_text_font(lv.font_arial_12)
except AttributeError:
    try:
        style_copynext_ddlist1_extra_list_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_copynext_ddlist1_extra_list_main_default.set_text_font(lv.font_montserrat_16)
style_copynext_ddlist1_extra_list_main_default.set_max_height(90)

# add style for copynext_ddlist1_list
copynext_ddlist1_list.add_style(style_copynext_ddlist1_extra_list_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_copynext_ddlist1_extra_list_scrollbar_default
style_copynext_ddlist1_extra_list_scrollbar_default = lv.style_t()
style_copynext_ddlist1_extra_list_scrollbar_default.init()
style_copynext_ddlist1_extra_list_scrollbar_default.set_radius(3)
style_copynext_ddlist1_extra_list_scrollbar_default.set_bg_color(lv.color_make(0x00,0xff,0x00))
style_copynext_ddlist1_extra_list_scrollbar_default.set_bg_opa(255)

# add style for copynext_ddlist1_list
copynext_ddlist1_list.add_style(style_copynext_ddlist1_extra_list_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

# create style style_copynext_ddlist1_main_main_default
style_copynext_ddlist1_main_main_default = lv.style_t()
style_copynext_ddlist1_main_main_default.init()
style_copynext_ddlist1_main_main_default.set_radius(3)
style_copynext_ddlist1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_copynext_ddlist1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_copynext_ddlist1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_ddlist1_main_main_default.set_bg_opa(255)
style_copynext_ddlist1_main_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_copynext_ddlist1_main_main_default.set_border_width(1)
style_copynext_ddlist1_main_main_default.set_border_opa(255)
style_copynext_ddlist1_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_copynext_ddlist1_main_main_default.set_text_font(lv.font_arial_12)
except AttributeError:
    try:
        style_copynext_ddlist1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_copynext_ddlist1_main_main_default.set_text_font(lv.font_montserrat_16)
style_copynext_ddlist1_main_main_default.set_pad_left(6)
style_copynext_ddlist1_main_main_default.set_pad_right(6)
style_copynext_ddlist1_main_main_default.set_pad_top(0)

# add style for copynext_ddlist1
copynext_ddlist1.add_style(style_copynext_ddlist1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create copynext_print
copynext_print = lv.btn(copynext)
copynext_print.set_pos(int(320),int(262))
copynext_print.set_size(118,47)
copynext_print.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
copynext_print_label = lv.label(copynext_print)
copynext_print_label.set_text("PRINT")
copynext_print.set_style_pad_all(0, lv.STATE.DEFAULT)
copynext_print_label.align(lv.ALIGN.CENTER,0,0)
# create style style_copynext_print_main_main_default
style_copynext_print_main_main_default = lv.style_t()
style_copynext_print_main_main_default.init()
style_copynext_print_main_main_default.set_radius(50)
style_copynext_print_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_copynext_print_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_copynext_print_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_copynext_print_main_main_default.set_bg_opa(255)
style_copynext_print_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_copynext_print_main_main_default.set_border_width(0)
style_copynext_print_main_main_default.set_border_opa(255)
style_copynext_print_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_copynext_print_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_copynext_print_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_copynext_print_main_main_default.set_text_font(lv.font_montserrat_16)
style_copynext_print_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for copynext_print
copynext_print.add_style(style_copynext_print_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create scanhome
scanhome = lv.obj()
scanhome.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_scanhome_main_main_default
style_scanhome_main_main_default = lv.style_t()
style_scanhome_main_main_default.init()
style_scanhome_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_scanhome_main_main_default.set_bg_opa(0)

# add style for scanhome
scanhome.add_style(style_scanhome_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create scanhome_cont0
scanhome_cont0 = lv.obj(scanhome)
scanhome_cont0.set_pos(int(0),int(0))
scanhome_cont0.set_size(480,117)
scanhome_cont0.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_scanhome_cont0_main_main_default
style_scanhome_cont0_main_main_default = lv.style_t()
style_scanhome_cont0_main_main_default.init()
style_scanhome_cont0_main_main_default.set_radius(0)
style_scanhome_cont0_main_main_default.set_bg_color(lv.color_make(0x2f,0x32,0x43))
style_scanhome_cont0_main_main_default.set_bg_grad_color(lv.color_make(0x2f,0x32,0x43))
style_scanhome_cont0_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_scanhome_cont0_main_main_default.set_bg_opa(255)
style_scanhome_cont0_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_scanhome_cont0_main_main_default.set_border_width(0)
style_scanhome_cont0_main_main_default.set_border_opa(255)
style_scanhome_cont0_main_main_default.set_pad_left(0)
style_scanhome_cont0_main_main_default.set_pad_right(0)
style_scanhome_cont0_main_main_default.set_pad_top(0)
style_scanhome_cont0_main_main_default.set_pad_bottom(0)

# add style for scanhome_cont0
scanhome_cont0.add_style(style_scanhome_cont0_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create scanhome_label1
scanhome_label1 = lv.label(scanhome)
scanhome_label1.set_pos(int(136),int(35))
scanhome_label1.set_size(225,23)
scanhome_label1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
scanhome_label1.set_text("ADJUST IMAGE")
scanhome_label1.set_long_mode(lv.label.LONG.WRAP)
# create style style_scanhome_label1_main_main_default
style_scanhome_label1_main_main_default = lv.style_t()
style_scanhome_label1_main_main_default.init()
style_scanhome_label1_main_main_default.set_radius(0)
style_scanhome_label1_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_scanhome_label1_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_scanhome_label1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_scanhome_label1_main_main_default.set_bg_opa(0)
style_scanhome_label1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_scanhome_label1_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_scanhome_label1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_scanhome_label1_main_main_default.set_text_font(lv.font_montserrat_16)
style_scanhome_label1_main_main_default.set_text_letter_space(2)
style_scanhome_label1_main_main_default.set_text_line_space(0)
style_scanhome_label1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_scanhome_label1_main_main_default.set_pad_left(0)
style_scanhome_label1_main_main_default.set_pad_right(0)
style_scanhome_label1_main_main_default.set_pad_top(0)
style_scanhome_label1_main_main_default.set_pad_bottom(0)

# add style for scanhome_label1
scanhome_label1.add_style(style_scanhome_label1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create scanhome_cont2
scanhome_cont2 = lv.obj(scanhome)
scanhome_cont2.set_pos(int(0),int(117))
scanhome_cont2.set_size(480,202)
scanhome_cont2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_scanhome_cont2_main_main_default
style_scanhome_cont2_main_main_default = lv.style_t()
style_scanhome_cont2_main_main_default.init()
style_scanhome_cont2_main_main_default.set_radius(0)
style_scanhome_cont2_main_main_default.set_bg_color(lv.color_make(0xde,0xde,0xde))
style_scanhome_cont2_main_main_default.set_bg_grad_color(lv.color_make(0xde,0xde,0xde))
style_scanhome_cont2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_scanhome_cont2_main_main_default.set_bg_opa(255)
style_scanhome_cont2_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_scanhome_cont2_main_main_default.set_border_width(0)
style_scanhome_cont2_main_main_default.set_border_opa(255)
style_scanhome_cont2_main_main_default.set_pad_left(0)
style_scanhome_cont2_main_main_default.set_pad_right(0)
style_scanhome_cont2_main_main_default.set_pad_top(0)
style_scanhome_cont2_main_main_default.set_pad_bottom(0)

# add style for scanhome_cont2
scanhome_cont2.add_style(style_scanhome_cont2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create scanhome_img3
scanhome_img3 = lv.img(scanhome)
scanhome_img3.set_pos(int(27),int(88))
scanhome_img3.set_size(300,202)
scanhome_img3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
scanhome_img3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-625774500.png','rb') as f:
        scanhome_img3_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-625774500.png')
    sys.exit()

scanhome_img3_img = lv.img_dsc_t({
  'data_size': len(scanhome_img3_img_data),
  'header': {'always_zero': 0, 'w': 300, 'h': 202, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': scanhome_img3_img_data
})

scanhome_img3.set_src(scanhome_img3_img)
scanhome_img3.set_pivot(0,0)
scanhome_img3.set_angle(0)
# create style style_scanhome_img3_main_main_default
style_scanhome_img3_main_main_default = lv.style_t()
style_scanhome_img3_main_main_default.init()
style_scanhome_img3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_scanhome_img3_main_main_default.set_img_recolor_opa(0)
style_scanhome_img3_main_main_default.set_img_opa(255)

# add style for scanhome_img3
scanhome_img3.add_style(style_scanhome_img3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create scanhome_cont4
scanhome_cont4 = lv.obj(scanhome)
scanhome_cont4.set_pos(int(368),int(94))
scanhome_cont4.set_size(80,152)
scanhome_cont4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_scanhome_cont4_main_main_default
style_scanhome_cont4_main_main_default = lv.style_t()
style_scanhome_cont4_main_main_default.init()
style_scanhome_cont4_main_main_default.set_radius(0)
style_scanhome_cont4_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_scanhome_cont4_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_scanhome_cont4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_scanhome_cont4_main_main_default.set_bg_opa(255)
style_scanhome_cont4_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_scanhome_cont4_main_main_default.set_border_width(0)
style_scanhome_cont4_main_main_default.set_border_opa(255)
style_scanhome_cont4_main_main_default.set_pad_left(0)
style_scanhome_cont4_main_main_default.set_pad_right(0)
style_scanhome_cont4_main_main_default.set_pad_top(0)
style_scanhome_cont4_main_main_default.set_pad_bottom(0)

# add style for scanhome_cont4
scanhome_cont4.add_style(style_scanhome_cont4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create scanhome_btnscansave
scanhome_btnscansave = lv.btn(scanhome)
scanhome_btnscansave.set_pos(int(368),int(260))
scanhome_btnscansave.set_size(80,47)
scanhome_btnscansave.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
scanhome_btnscansave_label = lv.label(scanhome_btnscansave)
scanhome_btnscansave_label.set_text("SAVE")
scanhome_btnscansave.set_style_pad_all(0, lv.STATE.DEFAULT)
scanhome_btnscansave_label.align(lv.ALIGN.CENTER,0,0)
# create style style_scanhome_btnscansave_main_main_default
style_scanhome_btnscansave_main_main_default = lv.style_t()
style_scanhome_btnscansave_main_main_default.init()
style_scanhome_btnscansave_main_main_default.set_radius(50)
style_scanhome_btnscansave_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_scanhome_btnscansave_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_scanhome_btnscansave_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_scanhome_btnscansave_main_main_default.set_bg_opa(255)
style_scanhome_btnscansave_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_scanhome_btnscansave_main_main_default.set_border_width(0)
style_scanhome_btnscansave_main_main_default.set_border_opa(255)
style_scanhome_btnscansave_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_scanhome_btnscansave_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_scanhome_btnscansave_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_scanhome_btnscansave_main_main_default.set_text_font(lv.font_montserrat_16)
style_scanhome_btnscansave_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for scanhome_btnscansave
scanhome_btnscansave.add_style(style_scanhome_btnscansave_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create scanhome_sliderhue
scanhome_sliderhue = lv.slider(scanhome)
scanhome_sliderhue.set_pos(int(420),int(135))
scanhome_sliderhue.set_size(8,94)
scanhome_sliderhue.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
scanhome_sliderhue.set_range(0, 100)
scanhome_sliderhue.set_value(50, False)

# create style style_scanhome_sliderhue_main_main_default
style_scanhome_sliderhue_main_main_default = lv.style_t()
style_scanhome_sliderhue_main_main_default.init()
style_scanhome_sliderhue_main_main_default.set_radius(50)
style_scanhome_sliderhue_main_main_default.set_bg_color(lv.color_make(0x2f,0x32,0x43))
style_scanhome_sliderhue_main_main_default.set_bg_grad_color(lv.color_make(0x2f,0x32,0x43))
style_scanhome_sliderhue_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_scanhome_sliderhue_main_main_default.set_bg_opa(255)
style_scanhome_sliderhue_main_main_default.set_outline_color(lv.color_make(0x21,0x95,0xf6))
style_scanhome_sliderhue_main_main_default.set_outline_width(0)
style_scanhome_sliderhue_main_main_default.set_outline_opa(0)

# add style for scanhome_sliderhue
scanhome_sliderhue.add_style(style_scanhome_sliderhue_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_scanhome_sliderhue_main_indicator_default
style_scanhome_sliderhue_main_indicator_default = lv.style_t()
style_scanhome_sliderhue_main_indicator_default.init()
style_scanhome_sliderhue_main_indicator_default.set_radius(50)
style_scanhome_sliderhue_main_indicator_default.set_bg_color(lv.color_make(0xd4,0xd7,0xd9))
style_scanhome_sliderhue_main_indicator_default.set_bg_grad_color(lv.color_make(0xdd,0xd7,0xd9))
style_scanhome_sliderhue_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_scanhome_sliderhue_main_indicator_default.set_bg_opa(255)

# add style for scanhome_sliderhue
scanhome_sliderhue.add_style(style_scanhome_sliderhue_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_scanhome_sliderhue_main_knob_default
style_scanhome_sliderhue_main_knob_default = lv.style_t()
style_scanhome_sliderhue_main_knob_default.init()
style_scanhome_sliderhue_main_knob_default.set_radius(50)
style_scanhome_sliderhue_main_knob_default.set_bg_color(lv.color_make(0x29,0x30,0x41))
style_scanhome_sliderhue_main_knob_default.set_bg_grad_color(lv.color_make(0x29,0x30,0x41))
style_scanhome_sliderhue_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_scanhome_sliderhue_main_knob_default.set_bg_opa(255)

# add style for scanhome_sliderhue
scanhome_sliderhue.add_style(style_scanhome_sliderhue_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)


# create scanhome_sliderbright
scanhome_sliderbright = lv.slider(scanhome)
scanhome_sliderbright.set_pos(int(380),int(135))
scanhome_sliderbright.set_size(8,94)
scanhome_sliderbright.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
scanhome_sliderbright.set_range(0, 100)
scanhome_sliderbright.set_value(50, False)

# create style style_scanhome_sliderbright_main_main_default
style_scanhome_sliderbright_main_main_default = lv.style_t()
style_scanhome_sliderbright_main_main_default.init()
style_scanhome_sliderbright_main_main_default.set_radius(50)
style_scanhome_sliderbright_main_main_default.set_bg_color(lv.color_make(0x2f,0x32,0x43))
style_scanhome_sliderbright_main_main_default.set_bg_grad_color(lv.color_make(0x2f,0x32,0x43))
style_scanhome_sliderbright_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_scanhome_sliderbright_main_main_default.set_bg_opa(255)
style_scanhome_sliderbright_main_main_default.set_outline_color(lv.color_make(0x21,0x95,0xf6))
style_scanhome_sliderbright_main_main_default.set_outline_width(0)
style_scanhome_sliderbright_main_main_default.set_outline_opa(0)

# add style for scanhome_sliderbright
scanhome_sliderbright.add_style(style_scanhome_sliderbright_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_scanhome_sliderbright_main_indicator_default
style_scanhome_sliderbright_main_indicator_default = lv.style_t()
style_scanhome_sliderbright_main_indicator_default.init()
style_scanhome_sliderbright_main_indicator_default.set_radius(50)
style_scanhome_sliderbright_main_indicator_default.set_bg_color(lv.color_make(0xd4,0xd7,0xd9))
style_scanhome_sliderbright_main_indicator_default.set_bg_grad_color(lv.color_make(0xdd,0xd7,0xd9))
style_scanhome_sliderbright_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_scanhome_sliderbright_main_indicator_default.set_bg_opa(255)

# add style for scanhome_sliderbright
scanhome_sliderbright.add_style(style_scanhome_sliderbright_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_scanhome_sliderbright_main_knob_default
style_scanhome_sliderbright_main_knob_default = lv.style_t()
style_scanhome_sliderbright_main_knob_default.init()
style_scanhome_sliderbright_main_knob_default.set_radius(50)
style_scanhome_sliderbright_main_knob_default.set_bg_color(lv.color_make(0x29,0x30,0x41))
style_scanhome_sliderbright_main_knob_default.set_bg_grad_color(lv.color_make(0x29,0x30,0x41))
style_scanhome_sliderbright_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_scanhome_sliderbright_main_knob_default.set_bg_opa(255)

# add style for scanhome_sliderbright
scanhome_sliderbright.add_style(style_scanhome_sliderbright_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)


# create scanhome_bright
scanhome_bright = lv.img(scanhome)
scanhome_bright.set_pos(int(372),int(96))
scanhome_bright.set_size(24,28)
scanhome_bright.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
scanhome_bright.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1514305359.png','rb') as f:
        scanhome_bright_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1514305359.png')
    sys.exit()

scanhome_bright_img = lv.img_dsc_t({
  'data_size': len(scanhome_bright_img_data),
  'header': {'always_zero': 0, 'w': 24, 'h': 28, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': scanhome_bright_img_data
})

scanhome_bright.set_src(scanhome_bright_img)
scanhome_bright.set_pivot(0,0)
scanhome_bright.set_angle(0)
# create style style_scanhome_bright_main_main_default
style_scanhome_bright_main_main_default = lv.style_t()
style_scanhome_bright_main_main_default.init()
style_scanhome_bright_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_scanhome_bright_main_main_default.set_img_recolor_opa(0)
style_scanhome_bright_main_main_default.set_img_opa(255)

# add style for scanhome_bright
scanhome_bright.add_style(style_scanhome_bright_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create scanhome_hue
scanhome_hue = lv.img(scanhome)
scanhome_hue.set_pos(int(413),int(97))
scanhome_hue.set_size(21,24)
scanhome_hue.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
scanhome_hue.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-31944374.png','rb') as f:
        scanhome_hue_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-31944374.png')
    sys.exit()

scanhome_hue_img = lv.img_dsc_t({
  'data_size': len(scanhome_hue_img_data),
  'header': {'always_zero': 0, 'w': 21, 'h': 24, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': scanhome_hue_img_data
})

scanhome_hue.set_src(scanhome_hue_img)
scanhome_hue.set_pivot(0,0)
scanhome_hue.set_angle(0)
# create style style_scanhome_hue_main_main_default
style_scanhome_hue_main_main_default = lv.style_t()
style_scanhome_hue_main_main_default.init()
style_scanhome_hue_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_scanhome_hue_main_main_default.set_img_recolor_opa(0)
style_scanhome_hue_main_main_default.set_img_opa(255)

# add style for scanhome_hue
scanhome_hue.add_style(style_scanhome_hue_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create scanhome_btnscanback
scanhome_btnscanback = lv.btn(scanhome)
scanhome_btnscanback.set_pos(int(50),int(29))
scanhome_btnscanback.set_size(30,35)
scanhome_btnscanback.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
scanhome_btnscanback_label = lv.label(scanhome_btnscanback)
scanhome_btnscanback_label.set_text("<")
scanhome_btnscanback.set_style_pad_all(0, lv.STATE.DEFAULT)
scanhome_btnscanback_label.align(lv.ALIGN.CENTER,0,0)
# create style style_scanhome_btnscanback_main_main_default
style_scanhome_btnscanback_main_main_default = lv.style_t()
style_scanhome_btnscanback_main_main_default.init()
style_scanhome_btnscanback_main_main_default.set_radius(50)
style_scanhome_btnscanback_main_main_default.set_bg_color(lv.color_make(0x2f,0x32,0x43))
style_scanhome_btnscanback_main_main_default.set_bg_grad_color(lv.color_make(0x2f,0x32,0x43))
style_scanhome_btnscanback_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_scanhome_btnscanback_main_main_default.set_bg_opa(255)
style_scanhome_btnscanback_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_scanhome_btnscanback_main_main_default.set_border_width(0)
style_scanhome_btnscanback_main_main_default.set_border_opa(255)
style_scanhome_btnscanback_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_scanhome_btnscanback_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_scanhome_btnscanback_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_scanhome_btnscanback_main_main_default.set_text_font(lv.font_montserrat_16)
style_scanhome_btnscanback_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for scanhome_btnscanback
scanhome_btnscanback.add_style(style_scanhome_btnscanback_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prthome
prthome = lv.obj()
prthome.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_prthome_main_main_default
style_prthome_main_main_default = lv.style_t()
style_prthome_main_main_default.init()
style_prthome_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_prthome_main_main_default.set_bg_opa(0)

# add style for prthome
prthome.add_style(style_prthome_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prthome_cont0
prthome_cont0 = lv.obj(prthome)
prthome_cont0.set_pos(int(0),int(0))
prthome_cont0.set_size(480,117)
prthome_cont0.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_prthome_cont0_main_main_default
style_prthome_cont0_main_main_default = lv.style_t()
style_prthome_cont0_main_main_default.init()
style_prthome_cont0_main_main_default.set_radius(0)
style_prthome_cont0_main_main_default.set_bg_color(lv.color_make(0x2f,0x32,0x43))
style_prthome_cont0_main_main_default.set_bg_grad_color(lv.color_make(0x2f,0x32,0x43))
style_prthome_cont0_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prthome_cont0_main_main_default.set_bg_opa(255)
style_prthome_cont0_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_prthome_cont0_main_main_default.set_border_width(0)
style_prthome_cont0_main_main_default.set_border_opa(255)
style_prthome_cont0_main_main_default.set_pad_left(0)
style_prthome_cont0_main_main_default.set_pad_right(0)
style_prthome_cont0_main_main_default.set_pad_top(0)
style_prthome_cont0_main_main_default.set_pad_bottom(0)

# add style for prthome_cont0
prthome_cont0.add_style(style_prthome_cont0_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prthome_cont3
prthome_cont3 = lv.obj(prthome)
prthome_cont3.set_pos(int(0),int(117))
prthome_cont3.set_size(480,202)
prthome_cont3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_prthome_cont3_main_main_default
style_prthome_cont3_main_main_default = lv.style_t()
style_prthome_cont3_main_main_default.init()
style_prthome_cont3_main_main_default.set_radius(0)
style_prthome_cont3_main_main_default.set_bg_color(lv.color_make(0xde,0xde,0xde))
style_prthome_cont3_main_main_default.set_bg_grad_color(lv.color_make(0xde,0xde,0xde))
style_prthome_cont3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prthome_cont3_main_main_default.set_bg_opa(255)
style_prthome_cont3_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_prthome_cont3_main_main_default.set_border_width(0)
style_prthome_cont3_main_main_default.set_border_opa(255)
style_prthome_cont3_main_main_default.set_pad_left(0)
style_prthome_cont3_main_main_default.set_pad_right(0)
style_prthome_cont3_main_main_default.set_pad_top(0)
style_prthome_cont3_main_main_default.set_pad_bottom(0)

# add style for prthome_cont3
prthome_cont3.add_style(style_prthome_cont3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prthome_cont1
prthome_cont1 = lv.obj(prthome)
prthome_cont1.set_pos(int(40),int(70))
prthome_cont1.set_size(400,164)
prthome_cont1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_prthome_cont1_main_main_default
style_prthome_cont1_main_main_default = lv.style_t()
style_prthome_cont1_main_main_default.init()
style_prthome_cont1_main_main_default.set_radius(0)
style_prthome_cont1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_prthome_cont1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_prthome_cont1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prthome_cont1_main_main_default.set_bg_opa(255)
style_prthome_cont1_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_prthome_cont1_main_main_default.set_border_width(0)
style_prthome_cont1_main_main_default.set_border_opa(255)
style_prthome_cont1_main_main_default.set_pad_left(0)
style_prthome_cont1_main_main_default.set_pad_right(0)
style_prthome_cont1_main_main_default.set_pad_top(0)
style_prthome_cont1_main_main_default.set_pad_bottom(0)

# add style for prthome_cont1
prthome_cont1.add_style(style_prthome_cont1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prthome_label4
prthome_label4 = lv.label(prthome)
prthome_label4.set_pos(int(169),int(18))
prthome_label4.set_size(137,35)
prthome_label4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prthome_label4.set_text("PRINT MENU")
prthome_label4.set_long_mode(lv.label.LONG.WRAP)
# create style style_prthome_label4_main_main_default
style_prthome_label4_main_main_default = lv.style_t()
style_prthome_label4_main_main_default.init()
style_prthome_label4_main_main_default.set_radius(0)
style_prthome_label4_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_prthome_label4_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_prthome_label4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prthome_label4_main_main_default.set_bg_opa(0)
style_prthome_label4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_prthome_label4_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_prthome_label4_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_prthome_label4_main_main_default.set_text_font(lv.font_montserrat_16)
style_prthome_label4_main_main_default.set_text_letter_space(2)
style_prthome_label4_main_main_default.set_text_line_space(0)
style_prthome_label4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_prthome_label4_main_main_default.set_pad_left(0)
style_prthome_label4_main_main_default.set_pad_right(0)
style_prthome_label4_main_main_default.set_pad_top(0)
style_prthome_label4_main_main_default.set_pad_bottom(0)

# add style for prthome_label4
prthome_label4.add_style(style_prthome_label4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prthome_imgbtnit
prthome_imgbtnit = lv.imgbtn(prthome)
prthome_imgbtnit.set_pos(int(325),int(70))
prthome_imgbtnit.set_size(115,164)
prthome_imgbtnit.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1856464703.png','rb') as f:
        prthome_imgbtnit_imgReleased_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1856464703.png')
    sys.exit()

prthome_imgbtnit_imgReleased = lv.img_dsc_t({
  'data_size': len(prthome_imgbtnit_imgReleased_data),
  'header': {'always_zero': 0, 'w': 115, 'h': 164, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': prthome_imgbtnit_imgReleased_data
})
prthome_imgbtnit.set_src(lv.imgbtn.STATE.RELEASED, None, prthome_imgbtnit_imgReleased, None)

try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1856464703.png','rb') as f:
        prthome_imgbtnit_imgPressed_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1856464703.png')
    sys.exit()

prthome_imgbtnit_imgPressed = lv.img_dsc_t({
  'data_size': len(prthome_imgbtnit_imgPressed_data),
  'header': {'always_zero': 0, 'w': 115, 'h': 164, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': prthome_imgbtnit_imgPressed_data
})
prthome_imgbtnit.set_src(lv.imgbtn.STATE.PRESSED, None, prthome_imgbtnit_imgPressed, None)


try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1856464703.png','rb') as f:
        prthome_imgbtnit_imgCheckedReleased_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1856464703.png')
    sys.exit()

prthome_imgbtnit_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(prthome_imgbtnit_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 115, 'h': 164, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': prthome_imgbtnit_imgCheckedReleased_data
})
prthome_imgbtnit.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, None, prthome_imgbtnit_imgCheckedReleased, None)

try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1856464703.png','rb') as f:
        prthome_imgbtnit_imgCheckedPressed_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-1856464703.png')
    sys.exit()

prthome_imgbtnit_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(prthome_imgbtnit_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 115, 'h': 164, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': prthome_imgbtnit_imgCheckedPressed_data
})
prthome_imgbtnit.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, None, prthome_imgbtnit_imgCheckedPressed, None)

# create style style_prthome_imgbtnit_main_main_default
style_prthome_imgbtnit_main_main_default = lv.style_t()
style_prthome_imgbtnit_main_main_default.init()
style_prthome_imgbtnit_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_prthome_imgbtnit_main_main_default.set_text_font(lv.font_arial_12)
except AttributeError:
    try:
        style_prthome_imgbtnit_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_prthome_imgbtnit_main_main_default.set_text_font(lv.font_montserrat_16)
style_prthome_imgbtnit_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_prthome_imgbtnit_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_prthome_imgbtnit_main_main_default.set_img_recolor_opa(0)
style_prthome_imgbtnit_main_main_default.set_img_opa(255)

# add style for prthome_imgbtnit
prthome_imgbtnit.add_style(style_prthome_imgbtnit_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_prthome_imgbtnit_main_main_pressed
style_prthome_imgbtnit_main_main_pressed = lv.style_t()
style_prthome_imgbtnit_main_main_pressed.init()
style_prthome_imgbtnit_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_prthome_imgbtnit_main_main_pressed.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_prthome_imgbtnit_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_prthome_imgbtnit_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_prthome_imgbtnit_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_prthome_imgbtnit_main_main_pressed.set_img_recolor_opa(0)
style_prthome_imgbtnit_main_main_pressed.set_img_opa(255)

# add style for prthome_imgbtnit
prthome_imgbtnit.add_style(style_prthome_imgbtnit_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_prthome_imgbtnit_main_main_checked
style_prthome_imgbtnit_main_main_checked = lv.style_t()
style_prthome_imgbtnit_main_main_checked.init()
style_prthome_imgbtnit_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_prthome_imgbtnit_main_main_checked.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_prthome_imgbtnit_main_main_checked.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_prthome_imgbtnit_main_main_checked.set_text_font(lv.font_montserrat_16)
style_prthome_imgbtnit_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_prthome_imgbtnit_main_main_checked.set_img_recolor_opa(0)
style_prthome_imgbtnit_main_main_checked.set_img_opa(255)

# add style for prthome_imgbtnit
prthome_imgbtnit.add_style(style_prthome_imgbtnit_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)


# create prthome_imgbtnusb
prthome_imgbtnusb = lv.imgbtn(prthome)
prthome_imgbtnusb.set_pos(int(40),int(70))
prthome_imgbtnusb.set_size(115,164)
prthome_imgbtnusb.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp515274559.png','rb') as f:
        prthome_imgbtnusb_imgReleased_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp515274559.png')
    sys.exit()

prthome_imgbtnusb_imgReleased = lv.img_dsc_t({
  'data_size': len(prthome_imgbtnusb_imgReleased_data),
  'header': {'always_zero': 0, 'w': 115, 'h': 164, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': prthome_imgbtnusb_imgReleased_data
})
prthome_imgbtnusb.set_src(lv.imgbtn.STATE.RELEASED, None, prthome_imgbtnusb_imgReleased, None)

try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp515274559.png','rb') as f:
        prthome_imgbtnusb_imgPressed_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp515274559.png')
    sys.exit()

prthome_imgbtnusb_imgPressed = lv.img_dsc_t({
  'data_size': len(prthome_imgbtnusb_imgPressed_data),
  'header': {'always_zero': 0, 'w': 115, 'h': 164, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': prthome_imgbtnusb_imgPressed_data
})
prthome_imgbtnusb.set_src(lv.imgbtn.STATE.PRESSED, None, prthome_imgbtnusb_imgPressed, None)


try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp515274559.png','rb') as f:
        prthome_imgbtnusb_imgCheckedReleased_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp515274559.png')
    sys.exit()

prthome_imgbtnusb_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(prthome_imgbtnusb_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 115, 'h': 164, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': prthome_imgbtnusb_imgCheckedReleased_data
})
prthome_imgbtnusb.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, None, prthome_imgbtnusb_imgCheckedReleased, None)

try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp515274559.png','rb') as f:
        prthome_imgbtnusb_imgCheckedPressed_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp515274559.png')
    sys.exit()

prthome_imgbtnusb_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(prthome_imgbtnusb_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 115, 'h': 164, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': prthome_imgbtnusb_imgCheckedPressed_data
})
prthome_imgbtnusb.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, None, prthome_imgbtnusb_imgCheckedPressed, None)

# create style style_prthome_imgbtnusb_main_main_default
style_prthome_imgbtnusb_main_main_default = lv.style_t()
style_prthome_imgbtnusb_main_main_default.init()
style_prthome_imgbtnusb_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_prthome_imgbtnusb_main_main_default.set_text_font(lv.font_arial_12)
except AttributeError:
    try:
        style_prthome_imgbtnusb_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_prthome_imgbtnusb_main_main_default.set_text_font(lv.font_montserrat_16)
style_prthome_imgbtnusb_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_prthome_imgbtnusb_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_prthome_imgbtnusb_main_main_default.set_img_recolor_opa(0)
style_prthome_imgbtnusb_main_main_default.set_img_opa(255)

# add style for prthome_imgbtnusb
prthome_imgbtnusb.add_style(style_prthome_imgbtnusb_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_prthome_imgbtnusb_main_main_pressed
style_prthome_imgbtnusb_main_main_pressed = lv.style_t()
style_prthome_imgbtnusb_main_main_pressed.init()
style_prthome_imgbtnusb_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_prthome_imgbtnusb_main_main_pressed.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_prthome_imgbtnusb_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_prthome_imgbtnusb_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_prthome_imgbtnusb_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_prthome_imgbtnusb_main_main_pressed.set_img_recolor_opa(0)
style_prthome_imgbtnusb_main_main_pressed.set_img_opa(255)

# add style for prthome_imgbtnusb
prthome_imgbtnusb.add_style(style_prthome_imgbtnusb_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_prthome_imgbtnusb_main_main_checked
style_prthome_imgbtnusb_main_main_checked = lv.style_t()
style_prthome_imgbtnusb_main_main_checked.init()
style_prthome_imgbtnusb_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_prthome_imgbtnusb_main_main_checked.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_prthome_imgbtnusb_main_main_checked.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_prthome_imgbtnusb_main_main_checked.set_text_font(lv.font_montserrat_16)
style_prthome_imgbtnusb_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_prthome_imgbtnusb_main_main_checked.set_img_recolor_opa(0)
style_prthome_imgbtnusb_main_main_checked.set_img_opa(255)

# add style for prthome_imgbtnusb
prthome_imgbtnusb.add_style(style_prthome_imgbtnusb_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)


# create prthome_imgbtnmobile
prthome_imgbtnmobile = lv.imgbtn(prthome)
prthome_imgbtnmobile.set_pos(int(183),int(70))
prthome_imgbtnmobile.set_size(115,164)
prthome_imgbtnmobile.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp1476888576.png','rb') as f:
        prthome_imgbtnmobile_imgReleased_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp1476888576.png')
    sys.exit()

prthome_imgbtnmobile_imgReleased = lv.img_dsc_t({
  'data_size': len(prthome_imgbtnmobile_imgReleased_data),
  'header': {'always_zero': 0, 'w': 115, 'h': 164, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': prthome_imgbtnmobile_imgReleased_data
})
prthome_imgbtnmobile.set_src(lv.imgbtn.STATE.RELEASED, None, prthome_imgbtnmobile_imgReleased, None)

try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp1476888576.png','rb') as f:
        prthome_imgbtnmobile_imgPressed_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp1476888576.png')
    sys.exit()

prthome_imgbtnmobile_imgPressed = lv.img_dsc_t({
  'data_size': len(prthome_imgbtnmobile_imgPressed_data),
  'header': {'always_zero': 0, 'w': 115, 'h': 164, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': prthome_imgbtnmobile_imgPressed_data
})
prthome_imgbtnmobile.set_src(lv.imgbtn.STATE.PRESSED, None, prthome_imgbtnmobile_imgPressed, None)


try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp1476888576.png','rb') as f:
        prthome_imgbtnmobile_imgCheckedReleased_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp1476888576.png')
    sys.exit()

prthome_imgbtnmobile_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(prthome_imgbtnmobile_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 115, 'h': 164, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': prthome_imgbtnmobile_imgCheckedReleased_data
})
prthome_imgbtnmobile.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, None, prthome_imgbtnmobile_imgCheckedReleased, None)

try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp1476888576.png','rb') as f:
        prthome_imgbtnmobile_imgCheckedPressed_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp1476888576.png')
    sys.exit()

prthome_imgbtnmobile_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(prthome_imgbtnmobile_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 115, 'h': 164, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': prthome_imgbtnmobile_imgCheckedPressed_data
})
prthome_imgbtnmobile.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, None, prthome_imgbtnmobile_imgCheckedPressed, None)

# create style style_prthome_imgbtnmobile_main_main_default
style_prthome_imgbtnmobile_main_main_default = lv.style_t()
style_prthome_imgbtnmobile_main_main_default.init()
style_prthome_imgbtnmobile_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_prthome_imgbtnmobile_main_main_default.set_text_font(lv.font_arial_12)
except AttributeError:
    try:
        style_prthome_imgbtnmobile_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_prthome_imgbtnmobile_main_main_default.set_text_font(lv.font_montserrat_16)
style_prthome_imgbtnmobile_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_prthome_imgbtnmobile_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_prthome_imgbtnmobile_main_main_default.set_img_recolor_opa(0)
style_prthome_imgbtnmobile_main_main_default.set_img_opa(255)

# add style for prthome_imgbtnmobile
prthome_imgbtnmobile.add_style(style_prthome_imgbtnmobile_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_prthome_imgbtnmobile_main_main_pressed
style_prthome_imgbtnmobile_main_main_pressed = lv.style_t()
style_prthome_imgbtnmobile_main_main_pressed.init()
style_prthome_imgbtnmobile_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_prthome_imgbtnmobile_main_main_pressed.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_prthome_imgbtnmobile_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_prthome_imgbtnmobile_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_prthome_imgbtnmobile_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_prthome_imgbtnmobile_main_main_pressed.set_img_recolor_opa(0)
style_prthome_imgbtnmobile_main_main_pressed.set_img_opa(255)

# add style for prthome_imgbtnmobile
prthome_imgbtnmobile.add_style(style_prthome_imgbtnmobile_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_prthome_imgbtnmobile_main_main_checked
style_prthome_imgbtnmobile_main_main_checked = lv.style_t()
style_prthome_imgbtnmobile_main_main_checked.init()
style_prthome_imgbtnmobile_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_prthome_imgbtnmobile_main_main_checked.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_prthome_imgbtnmobile_main_main_checked.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_prthome_imgbtnmobile_main_main_checked.set_text_font(lv.font_montserrat_16)
style_prthome_imgbtnmobile_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_prthome_imgbtnmobile_main_main_checked.set_img_recolor_opa(0)
style_prthome_imgbtnmobile_main_main_checked.set_img_opa(255)

# add style for prthome_imgbtnmobile
prthome_imgbtnmobile.add_style(style_prthome_imgbtnmobile_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)


# create prthome_labelusb
prthome_labelusb = lv.label(prthome)
prthome_labelusb.set_pos(int(58),int(188))
prthome_labelusb.set_size(74,23)
prthome_labelusb.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prthome_labelusb.set_text("USB")
prthome_labelusb.set_long_mode(lv.label.LONG.WRAP)
# create style style_prthome_labelusb_main_main_default
style_prthome_labelusb_main_main_default = lv.style_t()
style_prthome_labelusb_main_main_default.init()
style_prthome_labelusb_main_main_default.set_radius(0)
style_prthome_labelusb_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_prthome_labelusb_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_prthome_labelusb_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prthome_labelusb_main_main_default.set_bg_opa(0)
style_prthome_labelusb_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_prthome_labelusb_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_prthome_labelusb_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_prthome_labelusb_main_main_default.set_text_font(lv.font_montserrat_16)
style_prthome_labelusb_main_main_default.set_text_letter_space(2)
style_prthome_labelusb_main_main_default.set_text_line_space(0)
style_prthome_labelusb_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_prthome_labelusb_main_main_default.set_pad_left(0)
style_prthome_labelusb_main_main_default.set_pad_right(0)
style_prthome_labelusb_main_main_default.set_pad_top(0)
style_prthome_labelusb_main_main_default.set_pad_bottom(0)

# add style for prthome_labelusb
prthome_labelusb.add_style(style_prthome_labelusb_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prthome_labelmobile
prthome_labelmobile = lv.label(prthome)
prthome_labelmobile.set_pos(int(198),int(188))
prthome_labelmobile.set_size(74,23)
prthome_labelmobile.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prthome_labelmobile.set_text("MOBILE")
prthome_labelmobile.set_long_mode(lv.label.LONG.WRAP)
# create style style_prthome_labelmobile_main_main_default
style_prthome_labelmobile_main_main_default = lv.style_t()
style_prthome_labelmobile_main_main_default.init()
style_prthome_labelmobile_main_main_default.set_radius(0)
style_prthome_labelmobile_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_prthome_labelmobile_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_prthome_labelmobile_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prthome_labelmobile_main_main_default.set_bg_opa(0)
style_prthome_labelmobile_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_prthome_labelmobile_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_prthome_labelmobile_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_prthome_labelmobile_main_main_default.set_text_font(lv.font_montserrat_16)
style_prthome_labelmobile_main_main_default.set_text_letter_space(2)
style_prthome_labelmobile_main_main_default.set_text_line_space(0)
style_prthome_labelmobile_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_prthome_labelmobile_main_main_default.set_pad_left(0)
style_prthome_labelmobile_main_main_default.set_pad_right(0)
style_prthome_labelmobile_main_main_default.set_pad_top(0)
style_prthome_labelmobile_main_main_default.set_pad_bottom(0)

# add style for prthome_labelmobile
prthome_labelmobile.add_style(style_prthome_labelmobile_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prthome_labelit
prthome_labelit = lv.label(prthome)
prthome_labelit.set_pos(int(340),int(188))
prthome_labelit.set_size(85,23)
prthome_labelit.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prthome_labelit.set_text("INTERNET")
prthome_labelit.set_long_mode(lv.label.LONG.WRAP)
# create style style_prthome_labelit_main_main_default
style_prthome_labelit_main_main_default = lv.style_t()
style_prthome_labelit_main_main_default.init()
style_prthome_labelit_main_main_default.set_radius(0)
style_prthome_labelit_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_prthome_labelit_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_prthome_labelit_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prthome_labelit_main_main_default.set_bg_opa(0)
style_prthome_labelit_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_prthome_labelit_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_prthome_labelit_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_prthome_labelit_main_main_default.set_text_font(lv.font_montserrat_16)
style_prthome_labelit_main_main_default.set_text_letter_space(2)
style_prthome_labelit_main_main_default.set_text_line_space(0)
style_prthome_labelit_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_prthome_labelit_main_main_default.set_pad_left(0)
style_prthome_labelit_main_main_default.set_pad_right(0)
style_prthome_labelit_main_main_default.set_pad_top(0)
style_prthome_labelit_main_main_default.set_pad_bottom(0)

# add style for prthome_labelit
prthome_labelit.add_style(style_prthome_labelit_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prthome_label2
prthome_label2 = lv.label(prthome)
prthome_label2.set_pos(int(16),int(256))
prthome_label2.set_size(440,35)
prthome_label2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prthome_label2.set_text("From where do you want to print ?")
prthome_label2.set_long_mode(lv.label.LONG.WRAP)
# create style style_prthome_label2_main_main_default
style_prthome_label2_main_main_default = lv.style_t()
style_prthome_label2_main_main_default.init()
style_prthome_label2_main_main_default.set_radius(0)
style_prthome_label2_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_prthome_label2_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_prthome_label2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prthome_label2_main_main_default.set_bg_opa(0)
style_prthome_label2_main_main_default.set_text_color(lv.color_make(0x25,0x1d,0x1d))
try:
    style_prthome_label2_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_prthome_label2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_prthome_label2_main_main_default.set_text_font(lv.font_montserrat_16)
style_prthome_label2_main_main_default.set_text_letter_space(2)
style_prthome_label2_main_main_default.set_text_line_space(0)
style_prthome_label2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_prthome_label2_main_main_default.set_pad_left(0)
style_prthome_label2_main_main_default.set_pad_right(0)
style_prthome_label2_main_main_default.set_pad_top(0)
style_prthome_label2_main_main_default.set_pad_bottom(0)

# add style for prthome_label2
prthome_label2.add_style(style_prthome_label2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prthome_usb
prthome_usb = lv.img(prthome)
prthome_usb.set_pos(int(100),int(100))
prthome_usb.set_size(30,35)
prthome_usb.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prthome_usb.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-2044325228.png','rb') as f:
        prthome_usb_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-2044325228.png')
    sys.exit()

prthome_usb_img = lv.img_dsc_t({
  'data_size': len(prthome_usb_img_data),
  'header': {'always_zero': 0, 'w': 30, 'h': 35, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': prthome_usb_img_data
})

prthome_usb.set_src(prthome_usb_img)
prthome_usb.set_pivot(0,0)
prthome_usb.set_angle(0)
# create style style_prthome_usb_main_main_default
style_prthome_usb_main_main_default = lv.style_t()
style_prthome_usb_main_main_default.init()
style_prthome_usb_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_prthome_usb_main_main_default.set_img_recolor_opa(0)
style_prthome_usb_main_main_default.set_img_opa(255)

# add style for prthome_usb
prthome_usb.add_style(style_prthome_usb_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prthome_mobile
prthome_mobile = lv.img(prthome)
prthome_mobile.set_pos(int(242),int(100))
prthome_mobile.set_size(30,35)
prthome_mobile.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prthome_mobile.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-633239088.png','rb') as f:
        prthome_mobile_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-633239088.png')
    sys.exit()

prthome_mobile_img = lv.img_dsc_t({
  'data_size': len(prthome_mobile_img_data),
  'header': {'always_zero': 0, 'w': 30, 'h': 35, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': prthome_mobile_img_data
})

prthome_mobile.set_src(prthome_mobile_img)
prthome_mobile.set_pivot(0,0)
prthome_mobile.set_angle(0)
# create style style_prthome_mobile_main_main_default
style_prthome_mobile_main_main_default = lv.style_t()
style_prthome_mobile_main_main_default.init()
style_prthome_mobile_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_prthome_mobile_main_main_default.set_img_recolor_opa(0)
style_prthome_mobile_main_main_default.set_img_opa(255)

# add style for prthome_mobile
prthome_mobile.add_style(style_prthome_mobile_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prthome_internet
prthome_internet = lv.img(prthome)
prthome_internet.set_pos(int(383),int(100))
prthome_internet.set_size(30,35)
prthome_internet.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prthome_internet.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp187744175.png','rb') as f:
        prthome_internet_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp187744175.png')
    sys.exit()

prthome_internet_img = lv.img_dsc_t({
  'data_size': len(prthome_internet_img_data),
  'header': {'always_zero': 0, 'w': 30, 'h': 35, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': prthome_internet_img_data
})

prthome_internet.set_src(prthome_internet_img)
prthome_internet.set_pivot(0,0)
prthome_internet.set_angle(0)
# create style style_prthome_internet_main_main_default
style_prthome_internet_main_main_default = lv.style_t()
style_prthome_internet_main_main_default.init()
style_prthome_internet_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_prthome_internet_main_main_default.set_img_recolor_opa(0)
style_prthome_internet_main_main_default.set_img_opa(255)

# add style for prthome_internet
prthome_internet.add_style(style_prthome_internet_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prthome_btnprintback
prthome_btnprintback = lv.btn(prthome)
prthome_btnprintback.set_pos(int(50),int(15))
prthome_btnprintback.set_size(30,35)
prthome_btnprintback.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prthome_btnprintback_label = lv.label(prthome_btnprintback)
prthome_btnprintback_label.set_text("<")
prthome_btnprintback.set_style_pad_all(0, lv.STATE.DEFAULT)
prthome_btnprintback_label.align(lv.ALIGN.CENTER,0,0)
# create style style_prthome_btnprintback_main_main_default
style_prthome_btnprintback_main_main_default = lv.style_t()
style_prthome_btnprintback_main_main_default.init()
style_prthome_btnprintback_main_main_default.set_radius(50)
style_prthome_btnprintback_main_main_default.set_bg_color(lv.color_make(0x2f,0x32,0x43))
style_prthome_btnprintback_main_main_default.set_bg_grad_color(lv.color_make(0x2f,0x32,0x43))
style_prthome_btnprintback_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prthome_btnprintback_main_main_default.set_bg_opa(255)
style_prthome_btnprintback_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_prthome_btnprintback_main_main_default.set_border_width(0)
style_prthome_btnprintback_main_main_default.set_border_opa(255)
style_prthome_btnprintback_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_prthome_btnprintback_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_prthome_btnprintback_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_prthome_btnprintback_main_main_default.set_text_font(lv.font_montserrat_16)
style_prthome_btnprintback_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for prthome_btnprintback
prthome_btnprintback.add_style(style_prthome_btnprintback_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtusb
prtusb = lv.obj()
prtusb.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_prtusb_main_main_default
style_prtusb_main_main_default = lv.style_t()
style_prtusb_main_main_default.init()
style_prtusb_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_main_main_default.set_bg_opa(0)

# add style for prtusb
prtusb.add_style(style_prtusb_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtusb_cont0
prtusb_cont0 = lv.obj(prtusb)
prtusb_cont0.set_pos(int(0),int(0))
prtusb_cont0.set_size(480,117)
prtusb_cont0.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_prtusb_cont0_main_main_default
style_prtusb_cont0_main_main_default = lv.style_t()
style_prtusb_cont0_main_main_default.init()
style_prtusb_cont0_main_main_default.set_radius(0)
style_prtusb_cont0_main_main_default.set_bg_color(lv.color_make(0x2f,0x32,0x43))
style_prtusb_cont0_main_main_default.set_bg_grad_color(lv.color_make(0x2f,0x32,0x43))
style_prtusb_cont0_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_cont0_main_main_default.set_bg_opa(255)
style_prtusb_cont0_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_prtusb_cont0_main_main_default.set_border_width(0)
style_prtusb_cont0_main_main_default.set_border_opa(255)
style_prtusb_cont0_main_main_default.set_pad_left(0)
style_prtusb_cont0_main_main_default.set_pad_right(0)
style_prtusb_cont0_main_main_default.set_pad_top(0)
style_prtusb_cont0_main_main_default.set_pad_bottom(0)

# add style for prtusb_cont0
prtusb_cont0.add_style(style_prtusb_cont0_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtusb_cont2
prtusb_cont2 = lv.obj(prtusb)
prtusb_cont2.set_pos(int(0),int(117))
prtusb_cont2.set_size(480,202)
prtusb_cont2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_prtusb_cont2_main_main_default
style_prtusb_cont2_main_main_default = lv.style_t()
style_prtusb_cont2_main_main_default.init()
style_prtusb_cont2_main_main_default.set_radius(0)
style_prtusb_cont2_main_main_default.set_bg_color(lv.color_make(0xde,0xde,0xde))
style_prtusb_cont2_main_main_default.set_bg_grad_color(lv.color_make(0xde,0xde,0xde))
style_prtusb_cont2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_cont2_main_main_default.set_bg_opa(255)
style_prtusb_cont2_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_prtusb_cont2_main_main_default.set_border_width(0)
style_prtusb_cont2_main_main_default.set_border_opa(255)
style_prtusb_cont2_main_main_default.set_pad_left(0)
style_prtusb_cont2_main_main_default.set_pad_right(0)
style_prtusb_cont2_main_main_default.set_pad_top(0)
style_prtusb_cont2_main_main_default.set_pad_bottom(0)

# add style for prtusb_cont2
prtusb_cont2.add_style(style_prtusb_cont2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtusb_labeltitle
prtusb_labeltitle = lv.label(prtusb)
prtusb_labeltitle.set_pos(int(136),int(35))
prtusb_labeltitle.set_size(225,35)
prtusb_labeltitle.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prtusb_labeltitle.set_text("PRINTING FROM USB")
prtusb_labeltitle.set_long_mode(lv.label.LONG.WRAP)
# create style style_prtusb_labeltitle_main_main_default
style_prtusb_labeltitle_main_main_default = lv.style_t()
style_prtusb_labeltitle_main_main_default.init()
style_prtusb_labeltitle_main_main_default.set_radius(0)
style_prtusb_labeltitle_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_prtusb_labeltitle_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_prtusb_labeltitle_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_labeltitle_main_main_default.set_bg_opa(0)
style_prtusb_labeltitle_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_prtusb_labeltitle_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_prtusb_labeltitle_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_prtusb_labeltitle_main_main_default.set_text_font(lv.font_montserrat_16)
style_prtusb_labeltitle_main_main_default.set_text_letter_space(2)
style_prtusb_labeltitle_main_main_default.set_text_line_space(0)
style_prtusb_labeltitle_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_prtusb_labeltitle_main_main_default.set_pad_left(0)
style_prtusb_labeltitle_main_main_default.set_pad_right(0)
style_prtusb_labeltitle_main_main_default.set_pad_top(0)
style_prtusb_labeltitle_main_main_default.set_pad_bottom(0)

# add style for prtusb_labeltitle
prtusb_labeltitle.add_style(style_prtusb_labeltitle_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtusb_cont4
prtusb_cont4 = lv.obj(prtusb)
prtusb_cont4.set_pos(int(305),int(94))
prtusb_cont4.set_size(150,152)
prtusb_cont4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_prtusb_cont4_main_main_default
style_prtusb_cont4_main_main_default = lv.style_t()
style_prtusb_cont4_main_main_default.init()
style_prtusb_cont4_main_main_default.set_radius(0)
style_prtusb_cont4_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_cont4_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_cont4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_cont4_main_main_default.set_bg_opa(255)
style_prtusb_cont4_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_prtusb_cont4_main_main_default.set_border_width(0)
style_prtusb_cont4_main_main_default.set_border_opa(255)
style_prtusb_cont4_main_main_default.set_pad_left(0)
style_prtusb_cont4_main_main_default.set_pad_right(0)
style_prtusb_cont4_main_main_default.set_pad_top(0)
style_prtusb_cont4_main_main_default.set_pad_bottom(0)

# add style for prtusb_cont4
prtusb_cont4.add_style(style_prtusb_cont4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtusb_btnprint
prtusb_btnprint = lv.btn(prtusb)
prtusb_btnprint.set_pos(int(320),int(262))
prtusb_btnprint.set_size(118,47)
prtusb_btnprint.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prtusb_btnprint_label = lv.label(prtusb_btnprint)
prtusb_btnprint_label.set_text("PRINT")
prtusb_btnprint.set_style_pad_all(0, lv.STATE.DEFAULT)
prtusb_btnprint_label.align(lv.ALIGN.CENTER,0,0)
# create style style_prtusb_btnprint_main_main_default
style_prtusb_btnprint_main_main_default = lv.style_t()
style_prtusb_btnprint_main_main_default.init()
style_prtusb_btnprint_main_main_default.set_radius(50)
style_prtusb_btnprint_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_prtusb_btnprint_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_prtusb_btnprint_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_btnprint_main_main_default.set_bg_opa(255)
style_prtusb_btnprint_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_btnprint_main_main_default.set_border_width(0)
style_prtusb_btnprint_main_main_default.set_border_opa(255)
style_prtusb_btnprint_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_prtusb_btnprint_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_prtusb_btnprint_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_prtusb_btnprint_main_main_default.set_text_font(lv.font_montserrat_16)
style_prtusb_btnprint_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for prtusb_btnprint
prtusb_btnprint.add_style(style_prtusb_btnprint_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtusb_back
prtusb_back = lv.btn(prtusb)
prtusb_back.set_pos(int(50),int(29))
prtusb_back.set_size(30,35)
prtusb_back.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prtusb_back_label = lv.label(prtusb_back)
prtusb_back_label.set_text("<")
prtusb_back.set_style_pad_all(0, lv.STATE.DEFAULT)
prtusb_back_label.align(lv.ALIGN.CENTER,0,0)
# create style style_prtusb_back_main_main_default
style_prtusb_back_main_main_default = lv.style_t()
style_prtusb_back_main_main_default.init()
style_prtusb_back_main_main_default.set_radius(50)
style_prtusb_back_main_main_default.set_bg_color(lv.color_make(0x2f,0x32,0x43))
style_prtusb_back_main_main_default.set_bg_grad_color(lv.color_make(0x2f,0x32,0x43))
style_prtusb_back_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_back_main_main_default.set_bg_opa(255)
style_prtusb_back_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_back_main_main_default.set_border_width(0)
style_prtusb_back_main_main_default.set_border_opa(255)
style_prtusb_back_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_prtusb_back_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_prtusb_back_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_prtusb_back_main_main_default.set_text_font(lv.font_montserrat_16)
style_prtusb_back_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for prtusb_back
prtusb_back.add_style(style_prtusb_back_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtusb_swcolor
prtusb_swcolor = lv.switch(prtusb)
prtusb_swcolor.set_pos(int(323),int(205))
prtusb_swcolor.set_size(40,23)
prtusb_swcolor.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_prtusb_swcolor_main_main_default
style_prtusb_swcolor_main_main_default = lv.style_t()
style_prtusb_swcolor_main_main_default.init()
style_prtusb_swcolor_main_main_default.set_radius(100)
style_prtusb_swcolor_main_main_default.set_bg_color(lv.color_make(0xd4,0xd7,0xd9))
style_prtusb_swcolor_main_main_default.set_bg_grad_color(lv.color_make(0xd4,0xd7,0xd9))
style_prtusb_swcolor_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_swcolor_main_main_default.set_bg_opa(255)
style_prtusb_swcolor_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_prtusb_swcolor_main_main_default.set_border_width(0)
style_prtusb_swcolor_main_main_default.set_border_opa(255)

# add style for prtusb_swcolor
prtusb_swcolor.add_style(style_prtusb_swcolor_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_prtusb_swcolor_main_indicator_checked
style_prtusb_swcolor_main_indicator_checked = lv.style_t()
style_prtusb_swcolor_main_indicator_checked.init()
style_prtusb_swcolor_main_indicator_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_prtusb_swcolor_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_prtusb_swcolor_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_swcolor_main_indicator_checked.set_bg_opa(255)
style_prtusb_swcolor_main_indicator_checked.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_prtusb_swcolor_main_indicator_checked.set_border_width(0)
style_prtusb_swcolor_main_indicator_checked.set_border_opa(255)

# add style for prtusb_swcolor
prtusb_swcolor.add_style(style_prtusb_swcolor_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

# create style style_prtusb_swcolor_main_knob_default
style_prtusb_swcolor_main_knob_default = lv.style_t()
style_prtusb_swcolor_main_knob_default.init()
style_prtusb_swcolor_main_knob_default.set_radius(100)
style_prtusb_swcolor_main_knob_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_swcolor_main_knob_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_swcolor_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_swcolor_main_knob_default.set_bg_opa(255)
style_prtusb_swcolor_main_knob_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_prtusb_swcolor_main_knob_default.set_border_width(0)
style_prtusb_swcolor_main_knob_default.set_border_opa(255)

# add style for prtusb_swcolor
prtusb_swcolor.add_style(style_prtusb_swcolor_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)


# create prtusb_labelcopy
prtusb_labelcopy = lv.label(prtusb)
prtusb_labelcopy.set_pos(int(345),int(102))
prtusb_labelcopy.set_size(64,23)
prtusb_labelcopy.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prtusb_labelcopy.set_text("Copies")
prtusb_labelcopy.set_long_mode(lv.label.LONG.WRAP)
# create style style_prtusb_labelcopy_main_main_default
style_prtusb_labelcopy_main_main_default = lv.style_t()
style_prtusb_labelcopy_main_main_default.init()
style_prtusb_labelcopy_main_main_default.set_radius(0)
style_prtusb_labelcopy_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_prtusb_labelcopy_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_prtusb_labelcopy_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_labelcopy_main_main_default.set_bg_opa(0)
style_prtusb_labelcopy_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_prtusb_labelcopy_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_prtusb_labelcopy_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_prtusb_labelcopy_main_main_default.set_text_font(lv.font_montserrat_16)
style_prtusb_labelcopy_main_main_default.set_text_letter_space(2)
style_prtusb_labelcopy_main_main_default.set_text_line_space(0)
style_prtusb_labelcopy_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_prtusb_labelcopy_main_main_default.set_pad_left(0)
style_prtusb_labelcopy_main_main_default.set_pad_right(0)
style_prtusb_labelcopy_main_main_default.set_pad_top(0)
style_prtusb_labelcopy_main_main_default.set_pad_bottom(0)

# add style for prtusb_labelcopy
prtusb_labelcopy.add_style(style_prtusb_labelcopy_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtusb_up
prtusb_up = lv.btn(prtusb)
prtusb_up.set_pos(int(410),int(129))
prtusb_up.set_size(20,23)
prtusb_up.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prtusb_up_label = lv.label(prtusb_up)
prtusb_up_label.set_text("+")
prtusb_up.set_style_pad_all(0, lv.STATE.DEFAULT)
prtusb_up_label.align(lv.ALIGN.CENTER,0,0)
# create style style_prtusb_up_main_main_default
style_prtusb_up_main_main_default = lv.style_t()
style_prtusb_up_main_main_default.init()
style_prtusb_up_main_main_default.set_radius(4)
style_prtusb_up_main_main_default.set_bg_color(lv.color_make(0x2f,0x32,0x43))
style_prtusb_up_main_main_default.set_bg_grad_color(lv.color_make(0x2f,0x32,0x43))
style_prtusb_up_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_up_main_main_default.set_bg_opa(255)
style_prtusb_up_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_up_main_main_default.set_border_width(0)
style_prtusb_up_main_main_default.set_border_opa(255)
style_prtusb_up_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_prtusb_up_main_main_default.set_text_font(lv.font_simsun_18)
except AttributeError:
    try:
        style_prtusb_up_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_prtusb_up_main_main_default.set_text_font(lv.font_montserrat_16)
style_prtusb_up_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for prtusb_up
prtusb_up.add_style(style_prtusb_up_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtusb_down
prtusb_down = lv.btn(prtusb)
prtusb_down.set_pos(int(322),int(129))
prtusb_down.set_size(20,23)
prtusb_down.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prtusb_down_label = lv.label(prtusb_down)
prtusb_down_label.set_text("-")
prtusb_down.set_style_pad_all(0, lv.STATE.DEFAULT)
prtusb_down_label.align(lv.ALIGN.CENTER,0,0)
# create style style_prtusb_down_main_main_default
style_prtusb_down_main_main_default = lv.style_t()
style_prtusb_down_main_main_default.init()
style_prtusb_down_main_main_default.set_radius(4)
style_prtusb_down_main_main_default.set_bg_color(lv.color_make(0x2f,0x32,0x43))
style_prtusb_down_main_main_default.set_bg_grad_color(lv.color_make(0x2f,0x32,0x43))
style_prtusb_down_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_down_main_main_default.set_bg_opa(255)
style_prtusb_down_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_down_main_main_default.set_border_width(0)
style_prtusb_down_main_main_default.set_border_opa(255)
style_prtusb_down_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_prtusb_down_main_main_default.set_text_font(lv.font_simsun_18)
except AttributeError:
    try:
        style_prtusb_down_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_prtusb_down_main_main_default.set_text_font(lv.font_montserrat_16)
style_prtusb_down_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for prtusb_down
prtusb_down.add_style(style_prtusb_down_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtusb_labelcnt
prtusb_labelcnt = lv.label(prtusb)
prtusb_labelcnt.set_pos(int(332),int(129))
prtusb_labelcnt.set_size(90,35)
prtusb_labelcnt.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prtusb_labelcnt.set_text("1")
prtusb_labelcnt.set_long_mode(lv.label.LONG.WRAP)
# create style style_prtusb_labelcnt_main_main_default
style_prtusb_labelcnt_main_main_default = lv.style_t()
style_prtusb_labelcnt_main_main_default.init()
style_prtusb_labelcnt_main_main_default.set_radius(0)
style_prtusb_labelcnt_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_prtusb_labelcnt_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_prtusb_labelcnt_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_labelcnt_main_main_default.set_bg_opa(0)
style_prtusb_labelcnt_main_main_default.set_text_color(lv.color_make(0x14,0x10,0x10))
try:
    style_prtusb_labelcnt_main_main_default.set_text_font(lv.font_arial_21)
except AttributeError:
    try:
        style_prtusb_labelcnt_main_main_default.set_text_font(lv.font_montserrat_21)
    except AttributeError:
        style_prtusb_labelcnt_main_main_default.set_text_font(lv.font_montserrat_16)
style_prtusb_labelcnt_main_main_default.set_text_letter_space(2)
style_prtusb_labelcnt_main_main_default.set_text_line_space(0)
style_prtusb_labelcnt_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_prtusb_labelcnt_main_main_default.set_pad_left(0)
style_prtusb_labelcnt_main_main_default.set_pad_right(0)
style_prtusb_labelcnt_main_main_default.set_pad_top(0)
style_prtusb_labelcnt_main_main_default.set_pad_bottom(0)

# add style for prtusb_labelcnt
prtusb_labelcnt.add_style(style_prtusb_labelcnt_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtusb_labelcolor
prtusb_labelcolor = lv.label(prtusb)
prtusb_labelcolor.set_pos(int(314),int(171))
prtusb_labelcolor.set_size(50,23)
prtusb_labelcolor.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prtusb_labelcolor.set_text("Color")
prtusb_labelcolor.set_long_mode(lv.label.LONG.WRAP)
# create style style_prtusb_labelcolor_main_main_default
style_prtusb_labelcolor_main_main_default = lv.style_t()
style_prtusb_labelcolor_main_main_default.init()
style_prtusb_labelcolor_main_main_default.set_radius(0)
style_prtusb_labelcolor_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_prtusb_labelcolor_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_prtusb_labelcolor_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_labelcolor_main_main_default.set_bg_opa(0)
style_prtusb_labelcolor_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_prtusb_labelcolor_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_prtusb_labelcolor_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_prtusb_labelcolor_main_main_default.set_text_font(lv.font_montserrat_16)
style_prtusb_labelcolor_main_main_default.set_text_letter_space(2)
style_prtusb_labelcolor_main_main_default.set_text_line_space(0)
style_prtusb_labelcolor_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_prtusb_labelcolor_main_main_default.set_pad_left(0)
style_prtusb_labelcolor_main_main_default.set_pad_right(0)
style_prtusb_labelcolor_main_main_default.set_pad_top(0)
style_prtusb_labelcolor_main_main_default.set_pad_bottom(0)

# add style for prtusb_labelcolor
prtusb_labelcolor.add_style(style_prtusb_labelcolor_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtusb_labelvert
prtusb_labelvert = lv.label(prtusb)
prtusb_labelvert.set_pos(int(380),int(171))
prtusb_labelvert.set_size(70,23)
prtusb_labelvert.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prtusb_labelvert.set_text("Vertical")
prtusb_labelvert.set_long_mode(lv.label.LONG.WRAP)
# create style style_prtusb_labelvert_main_main_default
style_prtusb_labelvert_main_main_default = lv.style_t()
style_prtusb_labelvert_main_main_default.init()
style_prtusb_labelvert_main_main_default.set_radius(0)
style_prtusb_labelvert_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_prtusb_labelvert_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_prtusb_labelvert_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_labelvert_main_main_default.set_bg_opa(0)
style_prtusb_labelvert_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_prtusb_labelvert_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_prtusb_labelvert_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_prtusb_labelvert_main_main_default.set_text_font(lv.font_montserrat_16)
style_prtusb_labelvert_main_main_default.set_text_letter_space(2)
style_prtusb_labelvert_main_main_default.set_text_line_space(0)
style_prtusb_labelvert_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_prtusb_labelvert_main_main_default.set_pad_left(0)
style_prtusb_labelvert_main_main_default.set_pad_right(0)
style_prtusb_labelvert_main_main_default.set_pad_top(0)
style_prtusb_labelvert_main_main_default.set_pad_bottom(0)

# add style for prtusb_labelvert
prtusb_labelvert.add_style(style_prtusb_labelvert_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtusb_swvert
prtusb_swvert = lv.switch(prtusb)
prtusb_swvert.set_pos(int(390),int(205))
prtusb_swvert.set_size(40,23)
prtusb_swvert.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_prtusb_swvert_main_main_default
style_prtusb_swvert_main_main_default = lv.style_t()
style_prtusb_swvert_main_main_default.init()
style_prtusb_swvert_main_main_default.set_radius(100)
style_prtusb_swvert_main_main_default.set_bg_color(lv.color_make(0xd4,0xd7,0xd9))
style_prtusb_swvert_main_main_default.set_bg_grad_color(lv.color_make(0xd4,0xd7,0xd9))
style_prtusb_swvert_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_swvert_main_main_default.set_bg_opa(255)
style_prtusb_swvert_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_prtusb_swvert_main_main_default.set_border_width(0)
style_prtusb_swvert_main_main_default.set_border_opa(255)

# add style for prtusb_swvert
prtusb_swvert.add_style(style_prtusb_swvert_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_prtusb_swvert_main_indicator_checked
style_prtusb_swvert_main_indicator_checked = lv.style_t()
style_prtusb_swvert_main_indicator_checked.init()
style_prtusb_swvert_main_indicator_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_prtusb_swvert_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_prtusb_swvert_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_swvert_main_indicator_checked.set_bg_opa(255)
style_prtusb_swvert_main_indicator_checked.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_prtusb_swvert_main_indicator_checked.set_border_width(0)
style_prtusb_swvert_main_indicator_checked.set_border_opa(255)

# add style for prtusb_swvert
prtusb_swvert.add_style(style_prtusb_swvert_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

# create style style_prtusb_swvert_main_knob_default
style_prtusb_swvert_main_knob_default = lv.style_t()
style_prtusb_swvert_main_knob_default.init()
style_prtusb_swvert_main_knob_default.set_radius(100)
style_prtusb_swvert_main_knob_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_swvert_main_knob_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_swvert_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_swvert_main_knob_default.set_bg_opa(255)
style_prtusb_swvert_main_knob_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_prtusb_swvert_main_knob_default.set_border_width(0)
style_prtusb_swvert_main_knob_default.set_border_opa(255)

# add style for prtusb_swvert
prtusb_swvert.add_style(style_prtusb_swvert_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)


# create prtusb_list16
prtusb_list16 = lv.list(prtusb)
prtusb_list16.set_pos(int(31),int(97))
prtusb_list16.set_size(240,145)
prtusb_list16.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_prtusb_list16_extra_btns_main_default
style_prtusb_list16_extra_btns_main_default = lv.style_t()
style_prtusb_list16_extra_btns_main_default.init()
style_prtusb_list16_extra_btns_main_default.set_radius(3)
style_prtusb_list16_extra_btns_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_list16_extra_btns_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_list16_extra_btns_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_list16_extra_btns_main_default.set_bg_opa(255)
style_prtusb_list16_extra_btns_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_prtusb_list16_extra_btns_main_default.set_text_font(lv.font_arial_12)
except AttributeError:
    try:
        style_prtusb_list16_extra_btns_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_prtusb_list16_extra_btns_main_default.set_text_font(lv.font_montserrat_16)


prtusb_list16_btn_0 = prtusb_list16.add_btn(None, "Contract 12.pdf")

# add style for prtusb_list16_btn_0
prtusb_list16_btn_0.add_style(style_prtusb_list16_extra_btns_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

prtusb_list16_btn_1 = prtusb_list16.add_btn(None, "Scanned_05_21.pdf")

# add style for prtusb_list16_btn_1
prtusb_list16_btn_1.add_style(style_prtusb_list16_extra_btns_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

prtusb_list16_btn_2 = prtusb_list16.add_btn(None, "Photo_2.jpg")

# add style for prtusb_list16_btn_2
prtusb_list16_btn_2.add_style(style_prtusb_list16_extra_btns_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

prtusb_list16_btn_3 = prtusb_list16.add_btn(None, "Photo_3.jpg")

# add style for prtusb_list16_btn_3
prtusb_list16_btn_3.add_style(style_prtusb_list16_extra_btns_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_prtusb_list16_main_main_default
style_prtusb_list16_main_main_default = lv.style_t()
style_prtusb_list16_main_main_default.init()
style_prtusb_list16_main_main_default.set_radius(3)
style_prtusb_list16_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_list16_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_list16_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_list16_main_main_default.set_bg_opa(255)
style_prtusb_list16_main_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_prtusb_list16_main_main_default.set_border_width(1)
style_prtusb_list16_main_main_default.set_border_opa(255)
style_prtusb_list16_main_main_default.set_pad_left(5)
style_prtusb_list16_main_main_default.set_pad_right(5)
style_prtusb_list16_main_main_default.set_pad_top(5)
style_prtusb_list16_main_main_default.set_pad_bottom(5)

# add style for prtusb_list16
prtusb_list16.add_style(style_prtusb_list16_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_prtusb_list16_main_scrollbar_default
style_prtusb_list16_main_scrollbar_default = lv.style_t()
style_prtusb_list16_main_scrollbar_default.init()
style_prtusb_list16_main_scrollbar_default.set_radius(3)
style_prtusb_list16_main_scrollbar_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_list16_main_scrollbar_default.set_bg_opa(255)

# add style for prtusb_list16
prtusb_list16.add_style(style_prtusb_list16_main_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)


# create prtusb_ddlist1
prtusb_ddlist1 = lv.dropdown(prtusb)
prtusb_ddlist1.set_pos(int(28),int(258))
prtusb_ddlist1.set_size(100,24)
prtusb_ddlist1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prtusb_ddlist1.set_options("Best\nNormal\nDraft")

prtusb_ddlist1_list = prtusb_ddlist1.get_list()
# create style style_prtusb_ddlist1_extra_list_selected_checked
style_prtusb_ddlist1_extra_list_selected_checked = lv.style_t()
style_prtusb_ddlist1_extra_list_selected_checked.init()
style_prtusb_ddlist1_extra_list_selected_checked.set_radius(3)
style_prtusb_ddlist1_extra_list_selected_checked.set_bg_color(lv.color_make(0x00,0xa1,0xb5))
style_prtusb_ddlist1_extra_list_selected_checked.set_bg_grad_color(lv.color_make(0x00,0xa1,0xb5))
style_prtusb_ddlist1_extra_list_selected_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_prtusb_ddlist1_extra_list_selected_checked.set_bg_opa(255)
style_prtusb_ddlist1_extra_list_selected_checked.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_prtusb_ddlist1_extra_list_selected_checked.set_border_width(1)
style_prtusb_ddlist1_extra_list_selected_checked.set_border_opa(255)
style_prtusb_ddlist1_extra_list_selected_checked.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_prtusb_ddlist1_extra_list_selected_checked.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_prtusb_ddlist1_extra_list_selected_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_prtusb_ddlist1_extra_list_selected_checked.set_text_font(lv.font_montserrat_16)

# add style for prtusb_ddlist1_list
prtusb_ddlist1_list.add_style(style_prtusb_ddlist1_extra_list_selected_checked, lv.PART.SELECTED|lv.STATE.CHECKED)

# create style style_prtusb_ddlist1_extra_list_main_default
style_prtusb_ddlist1_extra_list_main_default = lv.style_t()
style_prtusb_ddlist1_extra_list_main_default.init()
style_prtusb_ddlist1_extra_list_main_default.set_radius(3)
style_prtusb_ddlist1_extra_list_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_ddlist1_extra_list_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_ddlist1_extra_list_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_ddlist1_extra_list_main_default.set_bg_opa(255)
style_prtusb_ddlist1_extra_list_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_prtusb_ddlist1_extra_list_main_default.set_border_width(1)
style_prtusb_ddlist1_extra_list_main_default.set_border_opa(255)
style_prtusb_ddlist1_extra_list_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_prtusb_ddlist1_extra_list_main_default.set_text_font(lv.font_arial_12)
except AttributeError:
    try:
        style_prtusb_ddlist1_extra_list_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_prtusb_ddlist1_extra_list_main_default.set_text_font(lv.font_montserrat_16)
style_prtusb_ddlist1_extra_list_main_default.set_max_height(90)

# add style for prtusb_ddlist1_list
prtusb_ddlist1_list.add_style(style_prtusb_ddlist1_extra_list_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_prtusb_ddlist1_extra_list_scrollbar_default
style_prtusb_ddlist1_extra_list_scrollbar_default = lv.style_t()
style_prtusb_ddlist1_extra_list_scrollbar_default.init()
style_prtusb_ddlist1_extra_list_scrollbar_default.set_radius(3)
style_prtusb_ddlist1_extra_list_scrollbar_default.set_bg_color(lv.color_make(0x00,0xff,0x00))
style_prtusb_ddlist1_extra_list_scrollbar_default.set_bg_opa(255)

# add style for prtusb_ddlist1_list
prtusb_ddlist1_list.add_style(style_prtusb_ddlist1_extra_list_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

# create style style_prtusb_ddlist1_main_main_default
style_prtusb_ddlist1_main_main_default = lv.style_t()
style_prtusb_ddlist1_main_main_default.init()
style_prtusb_ddlist1_main_main_default.set_radius(3)
style_prtusb_ddlist1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_ddlist1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_ddlist1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_ddlist1_main_main_default.set_bg_opa(255)
style_prtusb_ddlist1_main_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_prtusb_ddlist1_main_main_default.set_border_width(1)
style_prtusb_ddlist1_main_main_default.set_border_opa(255)
style_prtusb_ddlist1_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_prtusb_ddlist1_main_main_default.set_text_font(lv.font_arial_12)
except AttributeError:
    try:
        style_prtusb_ddlist1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_prtusb_ddlist1_main_main_default.set_text_font(lv.font_montserrat_16)
style_prtusb_ddlist1_main_main_default.set_pad_left(6)
style_prtusb_ddlist1_main_main_default.set_pad_right(6)
style_prtusb_ddlist1_main_main_default.set_pad_top(4)

# add style for prtusb_ddlist1
prtusb_ddlist1.add_style(style_prtusb_ddlist1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtusb_ddlist2
prtusb_ddlist2 = lv.dropdown(prtusb)
prtusb_ddlist2.set_pos(int(166),int(258))
prtusb_ddlist2.set_size(100,27)
prtusb_ddlist2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prtusb_ddlist2.set_options("72 DPI\n96 DPI\n150 DPI\n300 DPI\n600 DPI\n900 DPI\n1200 DPI")

prtusb_ddlist2_list = prtusb_ddlist2.get_list()
# create style style_prtusb_ddlist2_extra_list_selected_checked
style_prtusb_ddlist2_extra_list_selected_checked = lv.style_t()
style_prtusb_ddlist2_extra_list_selected_checked.init()
style_prtusb_ddlist2_extra_list_selected_checked.set_radius(3)
style_prtusb_ddlist2_extra_list_selected_checked.set_bg_color(lv.color_make(0x00,0xa1,0xb5))
style_prtusb_ddlist2_extra_list_selected_checked.set_bg_grad_color(lv.color_make(0x00,0xa1,0xb5))
style_prtusb_ddlist2_extra_list_selected_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_prtusb_ddlist2_extra_list_selected_checked.set_bg_opa(255)
style_prtusb_ddlist2_extra_list_selected_checked.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_prtusb_ddlist2_extra_list_selected_checked.set_border_width(1)
style_prtusb_ddlist2_extra_list_selected_checked.set_border_opa(255)
style_prtusb_ddlist2_extra_list_selected_checked.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_prtusb_ddlist2_extra_list_selected_checked.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_prtusb_ddlist2_extra_list_selected_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_prtusb_ddlist2_extra_list_selected_checked.set_text_font(lv.font_montserrat_16)

# add style for prtusb_ddlist2_list
prtusb_ddlist2_list.add_style(style_prtusb_ddlist2_extra_list_selected_checked, lv.PART.SELECTED|lv.STATE.CHECKED)

# create style style_prtusb_ddlist2_extra_list_main_default
style_prtusb_ddlist2_extra_list_main_default = lv.style_t()
style_prtusb_ddlist2_extra_list_main_default.init()
style_prtusb_ddlist2_extra_list_main_default.set_radius(3)
style_prtusb_ddlist2_extra_list_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_ddlist2_extra_list_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_ddlist2_extra_list_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_ddlist2_extra_list_main_default.set_bg_opa(255)
style_prtusb_ddlist2_extra_list_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_prtusb_ddlist2_extra_list_main_default.set_border_width(1)
style_prtusb_ddlist2_extra_list_main_default.set_border_opa(255)
style_prtusb_ddlist2_extra_list_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_prtusb_ddlist2_extra_list_main_default.set_text_font(lv.font_arial_12)
except AttributeError:
    try:
        style_prtusb_ddlist2_extra_list_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_prtusb_ddlist2_extra_list_main_default.set_text_font(lv.font_montserrat_16)
style_prtusb_ddlist2_extra_list_main_default.set_max_height(90)

# add style for prtusb_ddlist2_list
prtusb_ddlist2_list.add_style(style_prtusb_ddlist2_extra_list_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_prtusb_ddlist2_extra_list_scrollbar_default
style_prtusb_ddlist2_extra_list_scrollbar_default = lv.style_t()
style_prtusb_ddlist2_extra_list_scrollbar_default.init()
style_prtusb_ddlist2_extra_list_scrollbar_default.set_radius(3)
style_prtusb_ddlist2_extra_list_scrollbar_default.set_bg_color(lv.color_make(0x00,0xff,0x00))
style_prtusb_ddlist2_extra_list_scrollbar_default.set_bg_opa(255)

# add style for prtusb_ddlist2_list
prtusb_ddlist2_list.add_style(style_prtusb_ddlist2_extra_list_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

# create style style_prtusb_ddlist2_main_main_default
style_prtusb_ddlist2_main_main_default = lv.style_t()
style_prtusb_ddlist2_main_main_default.init()
style_prtusb_ddlist2_main_main_default.set_radius(3)
style_prtusb_ddlist2_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_ddlist2_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_prtusb_ddlist2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtusb_ddlist2_main_main_default.set_bg_opa(255)
style_prtusb_ddlist2_main_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_prtusb_ddlist2_main_main_default.set_border_width(1)
style_prtusb_ddlist2_main_main_default.set_border_opa(255)
style_prtusb_ddlist2_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_prtusb_ddlist2_main_main_default.set_text_font(lv.font_arial_12)
except AttributeError:
    try:
        style_prtusb_ddlist2_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_prtusb_ddlist2_main_main_default.set_text_font(lv.font_montserrat_16)
style_prtusb_ddlist2_main_main_default.set_pad_left(6)
style_prtusb_ddlist2_main_main_default.set_pad_right(6)
style_prtusb_ddlist2_main_main_default.set_pad_top(4)

# add style for prtusb_ddlist2
prtusb_ddlist2.add_style(style_prtusb_ddlist2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtmb
prtmb = lv.obj()
prtmb.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_prtmb_main_main_default
style_prtmb_main_main_default = lv.style_t()
style_prtmb_main_main_default.init()
style_prtmb_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_prtmb_main_main_default.set_bg_opa(0)

# add style for prtmb
prtmb.add_style(style_prtmb_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtmb_cont0
prtmb_cont0 = lv.obj(prtmb)
prtmb_cont0.set_pos(int(0),int(0))
prtmb_cont0.set_size(480,320)
prtmb_cont0.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_prtmb_cont0_main_main_default
style_prtmb_cont0_main_main_default = lv.style_t()
style_prtmb_cont0_main_main_default.init()
style_prtmb_cont0_main_main_default.set_radius(0)
style_prtmb_cont0_main_main_default.set_bg_color(lv.color_make(0x2f,0x32,0x43))
style_prtmb_cont0_main_main_default.set_bg_grad_color(lv.color_make(0x2f,0x32,0x43))
style_prtmb_cont0_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtmb_cont0_main_main_default.set_bg_opa(255)
style_prtmb_cont0_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_prtmb_cont0_main_main_default.set_border_width(0)
style_prtmb_cont0_main_main_default.set_border_opa(255)
style_prtmb_cont0_main_main_default.set_pad_left(0)
style_prtmb_cont0_main_main_default.set_pad_right(0)
style_prtmb_cont0_main_main_default.set_pad_top(0)
style_prtmb_cont0_main_main_default.set_pad_bottom(0)

# add style for prtmb_cont0
prtmb_cont0.add_style(style_prtmb_cont0_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtmb_btnback
prtmb_btnback = lv.btn(prtmb)
prtmb_btnback.set_pos(int(171),int(230))
prtmb_btnback.set_size(134,45)
prtmb_btnback.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prtmb_btnback_label = lv.label(prtmb_btnback)
prtmb_btnback_label.set_text("BACK")
prtmb_btnback.set_style_pad_all(0, lv.STATE.DEFAULT)
prtmb_btnback_label.align(lv.ALIGN.CENTER,0,0)
# create style style_prtmb_btnback_main_main_default
style_prtmb_btnback_main_main_default = lv.style_t()
style_prtmb_btnback_main_main_default.init()
style_prtmb_btnback_main_main_default.set_radius(50)
style_prtmb_btnback_main_main_default.set_bg_color(lv.color_make(0x2f,0x32,0x43))
style_prtmb_btnback_main_main_default.set_bg_grad_color(lv.color_make(0x2f,0x32,0x43))
style_prtmb_btnback_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtmb_btnback_main_main_default.set_bg_opa(255)
style_prtmb_btnback_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_prtmb_btnback_main_main_default.set_border_width(2)
style_prtmb_btnback_main_main_default.set_border_opa(255)
style_prtmb_btnback_main_main_default.set_text_color(lv.color_make(0xf4,0xec,0xec))
try:
    style_prtmb_btnback_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_prtmb_btnback_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_prtmb_btnback_main_main_default.set_text_font(lv.font_montserrat_16)
style_prtmb_btnback_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for prtmb_btnback
prtmb_btnback.add_style(style_prtmb_btnback_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtmb_label2
prtmb_label2 = lv.label(prtmb)
prtmb_label2.set_pos(int(10),int(171))
prtmb_label2.set_size(460,35)
prtmb_label2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prtmb_label2.set_text("Put your phone near to the printer")
prtmb_label2.set_long_mode(lv.label.LONG.WRAP)
# create style style_prtmb_label2_main_main_default
style_prtmb_label2_main_main_default = lv.style_t()
style_prtmb_label2_main_main_default.init()
style_prtmb_label2_main_main_default.set_radius(0)
style_prtmb_label2_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_prtmb_label2_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_prtmb_label2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_prtmb_label2_main_main_default.set_bg_opa(0)
style_prtmb_label2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_prtmb_label2_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_prtmb_label2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_prtmb_label2_main_main_default.set_text_font(lv.font_montserrat_16)
style_prtmb_label2_main_main_default.set_text_letter_space(2)
style_prtmb_label2_main_main_default.set_text_line_space(0)
style_prtmb_label2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_prtmb_label2_main_main_default.set_pad_left(0)
style_prtmb_label2_main_main_default.set_pad_right(0)
style_prtmb_label2_main_main_default.set_pad_top(0)
style_prtmb_label2_main_main_default.set_pad_bottom(0)

# add style for prtmb_label2
prtmb_label2.add_style(style_prtmb_label2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtmb_printer
prtmb_printer = lv.img(prtmb)
prtmb_printer.set_pos(int(154),int(82))
prtmb_printer.set_size(60,64)
prtmb_printer.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prtmb_printer.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp433613375.png','rb') as f:
        prtmb_printer_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp433613375.png')
    sys.exit()

prtmb_printer_img = lv.img_dsc_t({
  'data_size': len(prtmb_printer_img_data),
  'header': {'always_zero': 0, 'w': 60, 'h': 64, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': prtmb_printer_img_data
})

prtmb_printer.set_src(prtmb_printer_img)
prtmb_printer.set_pivot(0,0)
prtmb_printer.set_angle(0)
# create style style_prtmb_printer_main_main_default
style_prtmb_printer_main_main_default = lv.style_t()
style_prtmb_printer_main_main_default.init()
style_prtmb_printer_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_prtmb_printer_main_main_default.set_img_recolor_opa(0)
style_prtmb_printer_main_main_default.set_img_opa(255)

# add style for prtmb_printer
prtmb_printer.add_style(style_prtmb_printer_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtmb_img
prtmb_img = lv.img(prtmb)
prtmb_img.set_pos(int(235),int(97))
prtmb_img.set_size(25,29)
prtmb_img.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prtmb_img.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp962601778.png','rb') as f:
        prtmb_img_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp962601778.png')
    sys.exit()

prtmb_img_img = lv.img_dsc_t({
  'data_size': len(prtmb_img_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 29, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': prtmb_img_img_data
})

prtmb_img.set_src(prtmb_img_img)
prtmb_img.set_pivot(0,0)
prtmb_img.set_angle(0)
# create style style_prtmb_img_main_main_default
style_prtmb_img_main_main_default = lv.style_t()
style_prtmb_img_main_main_default.init()
style_prtmb_img_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_prtmb_img_main_main_default.set_img_recolor_opa(0)
style_prtmb_img_main_main_default.set_img_opa(255)

# add style for prtmb_img
prtmb_img.add_style(style_prtmb_img_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create prtmb_cloud
prtmb_cloud = lv.img(prtmb)
prtmb_cloud.set_pos(int(280),int(84))
prtmb_cloud.set_size(45,64)
prtmb_cloud.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
prtmb_cloud.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp1920970686.png','rb') as f:
        prtmb_cloud_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp1920970686.png')
    sys.exit()

prtmb_cloud_img = lv.img_dsc_t({
  'data_size': len(prtmb_cloud_img_data),
  'header': {'always_zero': 0, 'w': 45, 'h': 64, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': prtmb_cloud_img_data
})

prtmb_cloud.set_src(prtmb_cloud_img)
prtmb_cloud.set_pivot(0,0)
prtmb_cloud.set_angle(0)
# create style style_prtmb_cloud_main_main_default
style_prtmb_cloud_main_main_default = lv.style_t()
style_prtmb_cloud_main_main_default.init()
style_prtmb_cloud_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_prtmb_cloud_main_main_default.set_img_recolor_opa(0)
style_prtmb_cloud_main_main_default.set_img_opa(255)

# add style for prtmb_cloud
prtmb_cloud.add_style(style_prtmb_cloud_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create printit
printit = lv.obj()
printit.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_printit_main_main_default
style_printit_main_main_default = lv.style_t()
style_printit_main_main_default.init()
style_printit_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_printit_main_main_default.set_bg_opa(0)

# add style for printit
printit.add_style(style_printit_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create printit_cont0
printit_cont0 = lv.obj(printit)
printit_cont0.set_pos(int(0),int(0))
printit_cont0.set_size(480,320)
printit_cont0.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_printit_cont0_main_main_default
style_printit_cont0_main_main_default = lv.style_t()
style_printit_cont0_main_main_default.init()
style_printit_cont0_main_main_default.set_radius(0)
style_printit_cont0_main_main_default.set_bg_color(lv.color_make(0xd2,0x00,0x00))
style_printit_cont0_main_main_default.set_bg_grad_color(lv.color_make(0xd2,0x00,0x00))
style_printit_cont0_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_printit_cont0_main_main_default.set_bg_opa(255)
style_printit_cont0_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_printit_cont0_main_main_default.set_border_width(0)
style_printit_cont0_main_main_default.set_border_opa(255)
style_printit_cont0_main_main_default.set_pad_left(0)
style_printit_cont0_main_main_default.set_pad_right(0)
style_printit_cont0_main_main_default.set_pad_top(0)
style_printit_cont0_main_main_default.set_pad_bottom(0)

# add style for printit_cont0
printit_cont0.add_style(style_printit_cont0_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create printit_btnprtitback
printit_btnprtitback = lv.btn(printit)
printit_btnprtitback.set_pos(int(163),int(223))
printit_btnprtitback.set_size(134,45)
printit_btnprtitback.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
printit_btnprtitback_label = lv.label(printit_btnprtitback)
printit_btnprtitback_label.set_text("BACK")
printit_btnprtitback.set_style_pad_all(0, lv.STATE.DEFAULT)
printit_btnprtitback_label.align(lv.ALIGN.CENTER,0,0)
# create style style_printit_btnprtitback_main_main_default
style_printit_btnprtitback_main_main_default = lv.style_t()
style_printit_btnprtitback_main_main_default.init()
style_printit_btnprtitback_main_main_default.set_radius(50)
style_printit_btnprtitback_main_main_default.set_bg_color(lv.color_make(0xd2,0x00,0x00))
style_printit_btnprtitback_main_main_default.set_bg_grad_color(lv.color_make(0xd2,0x00,0x00))
style_printit_btnprtitback_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_printit_btnprtitback_main_main_default.set_bg_opa(255)
style_printit_btnprtitback_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_printit_btnprtitback_main_main_default.set_border_width(2)
style_printit_btnprtitback_main_main_default.set_border_opa(255)
style_printit_btnprtitback_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_printit_btnprtitback_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_printit_btnprtitback_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_printit_btnprtitback_main_main_default.set_text_font(lv.font_montserrat_16)
style_printit_btnprtitback_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for printit_btnprtitback
printit_btnprtitback.add_style(style_printit_btnprtitback_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create printit_label2
printit_label2 = lv.label(printit)
printit_label2.set_pos(int(10),int(171))
printit_label2.set_size(460,35)
printit_label2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
printit_label2.set_text("No internet connection")
printit_label2.set_long_mode(lv.label.LONG.WRAP)
# create style style_printit_label2_main_main_default
style_printit_label2_main_main_default = lv.style_t()
style_printit_label2_main_main_default.init()
style_printit_label2_main_main_default.set_radius(0)
style_printit_label2_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_printit_label2_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_printit_label2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_printit_label2_main_main_default.set_bg_opa(0)
style_printit_label2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_printit_label2_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_printit_label2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_printit_label2_main_main_default.set_text_font(lv.font_montserrat_16)
style_printit_label2_main_main_default.set_text_letter_space(2)
style_printit_label2_main_main_default.set_text_line_space(0)
style_printit_label2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_printit_label2_main_main_default.set_pad_left(0)
style_printit_label2_main_main_default.set_pad_right(0)
style_printit_label2_main_main_default.set_pad_top(0)
style_printit_label2_main_main_default.set_pad_bottom(0)

# add style for printit_label2
printit_label2.add_style(style_printit_label2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create printit_printer
printit_printer = lv.img(printit)
printit_printer.set_pos(int(154),int(82))
printit_printer.set_size(60,64)
printit_printer.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
printit_printer.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp433613375.png','rb') as f:
        printit_printer_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp433613375.png')
    sys.exit()

printit_printer_img = lv.img_dsc_t({
  'data_size': len(printit_printer_img_data),
  'header': {'always_zero': 0, 'w': 60, 'h': 64, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': printit_printer_img_data
})

printit_printer.set_src(printit_printer_img)
printit_printer.set_pivot(0,0)
printit_printer.set_angle(0)
# create style style_printit_printer_main_main_default
style_printit_printer_main_main_default = lv.style_t()
style_printit_printer_main_main_default.init()
style_printit_printer_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_printit_printer_main_main_default.set_img_recolor_opa(0)
style_printit_printer_main_main_default.set_img_opa(255)

# add style for printit_printer
printit_printer.add_style(style_printit_printer_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create printit_imgnotit
printit_imgnotit = lv.img(printit)
printit_imgnotit.set_pos(int(217),int(72))
printit_imgnotit.set_size(25,29)
printit_imgnotit.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
printit_imgnotit.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp29235034.png','rb') as f:
        printit_imgnotit_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp29235034.png')
    sys.exit()

printit_imgnotit_img = lv.img_dsc_t({
  'data_size': len(printit_imgnotit_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 29, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': printit_imgnotit_img_data
})

printit_imgnotit.set_src(printit_imgnotit_img)
printit_imgnotit.set_pivot(0,0)
printit_imgnotit.set_angle(0)
# create style style_printit_imgnotit_main_main_default
style_printit_imgnotit_main_main_default = lv.style_t()
style_printit_imgnotit_main_main_default.init()
style_printit_imgnotit_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_printit_imgnotit_main_main_default.set_img_recolor_opa(0)
style_printit_imgnotit_main_main_default.set_img_opa(255)

# add style for printit_imgnotit
printit_imgnotit.add_style(style_printit_imgnotit_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create printit_cloud
printit_cloud = lv.img(printit)
printit_cloud.set_pos(int(258),int(35))
printit_cloud.set_size(55,47)
printit_cloud.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
printit_cloud.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-168699991.png','rb') as f:
        printit_cloud_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-168699991.png')
    sys.exit()

printit_cloud_img = lv.img_dsc_t({
  'data_size': len(printit_cloud_img_data),
  'header': {'always_zero': 0, 'w': 55, 'h': 47, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': printit_cloud_img_data
})

printit_cloud.set_src(printit_cloud_img)
printit_cloud.set_pivot(0,0)
printit_cloud.set_angle(0)
# create style style_printit_cloud_main_main_default
style_printit_cloud_main_main_default = lv.style_t()
style_printit_cloud_main_main_default.init()
style_printit_cloud_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_printit_cloud_main_main_default.set_img_recolor_opa(0)
style_printit_cloud_main_main_default.set_img_opa(255)

# add style for printit_cloud
printit_cloud.add_style(style_printit_cloud_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create setup
setup = lv.obj()
setup.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_setup_main_main_default
style_setup_main_main_default = lv.style_t()
style_setup_main_main_default.init()
style_setup_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_setup_main_main_default.set_bg_opa(0)

# add style for setup
setup.add_style(style_setup_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create setup_cont0
setup_cont0 = lv.obj(setup)
setup_cont0.set_pos(int(0),int(0))
setup_cont0.set_size(480,320)
setup_cont0.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_setup_cont0_main_main_default
style_setup_cont0_main_main_default = lv.style_t()
style_setup_cont0_main_main_default.init()
style_setup_cont0_main_main_default.set_radius(0)
style_setup_cont0_main_main_default.set_bg_color(lv.color_make(0xd2,0x00,0x00))
style_setup_cont0_main_main_default.set_bg_grad_color(lv.color_make(0xd2,0x00,0x00))
style_setup_cont0_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_setup_cont0_main_main_default.set_bg_opa(255)
style_setup_cont0_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_setup_cont0_main_main_default.set_border_width(0)
style_setup_cont0_main_main_default.set_border_opa(255)
style_setup_cont0_main_main_default.set_pad_left(0)
style_setup_cont0_main_main_default.set_pad_right(0)
style_setup_cont0_main_main_default.set_pad_top(0)
style_setup_cont0_main_main_default.set_pad_bottom(0)

# add style for setup_cont0
setup_cont0.add_style(style_setup_cont0_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create setup_btnsetback
setup_btnsetback = lv.btn(setup)
setup_btnsetback.set_pos(int(161),int(230))
setup_btnsetback.set_size(134,45)
setup_btnsetback.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
setup_btnsetback_label = lv.label(setup_btnsetback)
setup_btnsetback_label.set_text("BACK")
setup_btnsetback.set_style_pad_all(0, lv.STATE.DEFAULT)
setup_btnsetback_label.align(lv.ALIGN.CENTER,0,0)
# create style style_setup_btnsetback_main_main_default
style_setup_btnsetback_main_main_default = lv.style_t()
style_setup_btnsetback_main_main_default.init()
style_setup_btnsetback_main_main_default.set_radius(50)
style_setup_btnsetback_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_setup_btnsetback_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_setup_btnsetback_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_setup_btnsetback_main_main_default.set_bg_opa(0)
style_setup_btnsetback_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_setup_btnsetback_main_main_default.set_border_width(2)
style_setup_btnsetback_main_main_default.set_border_opa(255)
style_setup_btnsetback_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_setup_btnsetback_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setup_btnsetback_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setup_btnsetback_main_main_default.set_text_font(lv.font_montserrat_16)
style_setup_btnsetback_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for setup_btnsetback
setup_btnsetback.add_style(style_setup_btnsetback_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create setup_label2
setup_label2 = lv.label(setup)
setup_label2.set_pos(int(10),int(171))
setup_label2.set_size(460,35)
setup_label2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
setup_label2.set_text("You have no permission to change the settings")
setup_label2.set_long_mode(lv.label.LONG.WRAP)
# create style style_setup_label2_main_main_default
style_setup_label2_main_main_default = lv.style_t()
style_setup_label2_main_main_default.init()
style_setup_label2_main_main_default.set_radius(0)
style_setup_label2_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_setup_label2_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_setup_label2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_setup_label2_main_main_default.set_bg_opa(0)
style_setup_label2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_setup_label2_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_setup_label2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_setup_label2_main_main_default.set_text_font(lv.font_montserrat_16)
style_setup_label2_main_main_default.set_text_letter_space(2)
style_setup_label2_main_main_default.set_text_line_space(0)
style_setup_label2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setup_label2_main_main_default.set_pad_left(0)
style_setup_label2_main_main_default.set_pad_right(0)
style_setup_label2_main_main_default.set_pad_top(0)
style_setup_label2_main_main_default.set_pad_bottom(0)

# add style for setup_label2
setup_label2.add_style(style_setup_label2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create setup_printer
setup_printer = lv.img(setup)
setup_printer.set_pos(int(154),int(82))
setup_printer.set_size(60,64)
setup_printer.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
setup_printer.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp433613375.png','rb') as f:
        setup_printer_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp433613375.png')
    sys.exit()

setup_printer_img = lv.img_dsc_t({
  'data_size': len(setup_printer_img_data),
  'header': {'always_zero': 0, 'w': 60, 'h': 64, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': setup_printer_img_data
})

setup_printer.set_src(setup_printer_img)
setup_printer.set_pivot(0,0)
setup_printer.set_angle(0)
# create style style_setup_printer_main_main_default
style_setup_printer_main_main_default = lv.style_t()
style_setup_printer_main_main_default.init()
style_setup_printer_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_setup_printer_main_main_default.set_img_recolor_opa(0)
style_setup_printer_main_main_default.set_img_opa(255)

# add style for setup_printer
setup_printer.add_style(style_setup_printer_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create setup_img
setup_img = lv.img(setup)
setup_img.set_pos(int(217),int(72))
setup_img.set_size(25,29)
setup_img.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
setup_img.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp29235034.png','rb') as f:
        setup_img_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp29235034.png')
    sys.exit()

setup_img_img = lv.img_dsc_t({
  'data_size': len(setup_img_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 29, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': setup_img_img_data
})

setup_img.set_src(setup_img_img)
setup_img.set_pivot(0,0)
setup_img.set_angle(0)
# create style style_setup_img_main_main_default
style_setup_img_main_main_default = lv.style_t()
style_setup_img_main_main_default.init()
style_setup_img_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_setup_img_main_main_default.set_img_recolor_opa(0)
style_setup_img_main_main_default.set_img_opa(255)

# add style for setup_img
setup_img.add_style(style_setup_img_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create setup_cloud
setup_cloud = lv.img(setup)
setup_cloud.set_pos(int(258),int(35))
setup_cloud.set_size(55,47)
setup_cloud.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
setup_cloud.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-168699991.png','rb') as f:
        setup_cloud_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp-168699991.png')
    sys.exit()

setup_cloud_img = lv.img_dsc_t({
  'data_size': len(setup_cloud_img_data),
  'header': {'always_zero': 0, 'w': 55, 'h': 47, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': setup_cloud_img_data
})

setup_cloud.set_src(setup_cloud_img)
setup_cloud.set_pivot(0,0)
setup_cloud.set_angle(0)
# create style style_setup_cloud_main_main_default
style_setup_cloud_main_main_default = lv.style_t()
style_setup_cloud_main_main_default.init()
style_setup_cloud_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_setup_cloud_main_main_default.set_img_recolor_opa(0)
style_setup_cloud_main_main_default.set_img_opa(255)

# add style for setup_cloud
setup_cloud.add_style(style_setup_cloud_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create loader
loader = lv.obj()
loader.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_loader_main_main_default
style_loader_main_main_default = lv.style_t()
style_loader_main_main_default.init()
style_loader_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_loader_main_main_default.set_bg_opa(0)

# add style for loader
loader.add_style(style_loader_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create loader_cont0
loader_cont0 = lv.obj(loader)
loader_cont0.set_pos(int(0),int(0))
loader_cont0.set_size(480,320)
loader_cont0.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_loader_cont0_main_main_default
style_loader_cont0_main_main_default = lv.style_t()
style_loader_cont0_main_main_default.init()
style_loader_cont0_main_main_default.set_radius(0)
style_loader_cont0_main_main_default.set_bg_color(lv.color_make(0x2f,0x32,0x43))
style_loader_cont0_main_main_default.set_bg_grad_color(lv.color_make(0x2f,0x32,0x43))
style_loader_cont0_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_loader_cont0_main_main_default.set_bg_opa(255)
style_loader_cont0_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_loader_cont0_main_main_default.set_border_width(0)
style_loader_cont0_main_main_default.set_border_opa(255)
style_loader_cont0_main_main_default.set_pad_left(0)
style_loader_cont0_main_main_default.set_pad_right(0)
style_loader_cont0_main_main_default.set_pad_top(0)
style_loader_cont0_main_main_default.set_pad_bottom(0)

# add style for loader_cont0
loader_cont0.add_style(style_loader_cont0_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create loader_loadarc
loader_loadarc = lv.arc(loader)
loader_loadarc.set_pos(int(180),int(94))
loader_loadarc.set_size(110,129)
loader_loadarc.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
loader_loadarc.set_mode(lv.arc.MODE.NORMAL)
loader_loadarc.set_range(0, 100)
loader_loadarc.set_bg_angles(0, 360)
loader_loadarc.set_angles(271, 271)
loader_loadarc.set_rotation(0)
loader_loadarc.set_style_arc_rounded(False, lv.PART.INDICATOR | lv.STATE.DEFAULT)
loader_loadarc.set_style_arc_rounded(False, lv.PART.MAIN | lv.STATE.DEFAULT)
# create style style_loader_loadarc_main_main_default
style_loader_loadarc_main_main_default = lv.style_t()
style_loader_loadarc_main_main_default.init()
style_loader_loadarc_main_main_default.set_radius(6)
style_loader_loadarc_main_main_default.set_bg_color(lv.color_make(0x00,0x23,0x46))
style_loader_loadarc_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x23,0x46))
style_loader_loadarc_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_loader_loadarc_main_main_default.set_bg_opa(0)
style_loader_loadarc_main_main_default.set_border_width(0)
style_loader_loadarc_main_main_default.set_pad_left(20)
style_loader_loadarc_main_main_default.set_pad_right(20)
style_loader_loadarc_main_main_default.set_pad_top(20)
style_loader_loadarc_main_main_default.set_pad_bottom(20)
style_loader_loadarc_main_main_default.set_arc_color(lv.color_make(0xe6,0xe6,0xe6))
style_loader_loadarc_main_main_default.set_arc_width(12)

# add style for loader_loadarc
loader_loadarc.add_style(style_loader_loadarc_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_loader_loadarc_main_indicator_default
style_loader_loadarc_main_indicator_default = lv.style_t()
style_loader_loadarc_main_indicator_default.init()
style_loader_loadarc_main_indicator_default.set_arc_color(lv.color_make(0x21,0x95,0xf6))
style_loader_loadarc_main_indicator_default.set_arc_width(12)

# add style for loader_loadarc
loader_loadarc.add_style(style_loader_loadarc_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_loader_loadarc_main_knob_default
style_loader_loadarc_main_knob_default = lv.style_t()
style_loader_loadarc_main_knob_default.init()
style_loader_loadarc_main_knob_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_loader_loadarc_main_knob_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_loader_loadarc_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_loader_loadarc_main_knob_default.set_bg_opa(255)
style_loader_loadarc_main_knob_default.set_pad_all(5)

# add style for loader_loadarc
loader_loadarc.add_style(style_loader_loadarc_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)


# create loader_loadlabel
loader_loadlabel = lv.label(loader)
loader_loadlabel.set_pos(int(201),int(147))
loader_loadlabel.set_size(80,23)
loader_loadlabel.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
loader_loadlabel.set_text("0 %")
loader_loadlabel.set_long_mode(lv.label.LONG.WRAP)
# create style style_loader_loadlabel_main_main_default
style_loader_loadlabel_main_main_default = lv.style_t()
style_loader_loadlabel_main_main_default.init()
style_loader_loadlabel_main_main_default.set_radius(0)
style_loader_loadlabel_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_loader_loadlabel_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_loader_loadlabel_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_loader_loadlabel_main_main_default.set_bg_opa(0)
style_loader_loadlabel_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_loader_loadlabel_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_loader_loadlabel_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_loader_loadlabel_main_main_default.set_text_font(lv.font_montserrat_16)
style_loader_loadlabel_main_main_default.set_text_letter_space(2)
style_loader_loadlabel_main_main_default.set_text_line_space(0)
style_loader_loadlabel_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_loader_loadlabel_main_main_default.set_pad_left(0)
style_loader_loadlabel_main_main_default.set_pad_right(0)
style_loader_loadlabel_main_main_default.set_pad_top(0)
style_loader_loadlabel_main_main_default.set_pad_bottom(0)

# add style for loader_loadlabel
loader_loadlabel.add_style(style_loader_loadlabel_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create saved
saved = lv.obj()
saved.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_saved_main_main_default
style_saved_main_main_default = lv.style_t()
style_saved_main_main_default.init()
style_saved_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_saved_main_main_default.set_bg_opa(0)

# add style for saved
saved.add_style(style_saved_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create saved_cont0
saved_cont0 = lv.obj(saved)
saved_cont0.set_pos(int(0),int(0))
saved_cont0.set_size(480,320)
saved_cont0.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_saved_cont0_main_main_default
style_saved_cont0_main_main_default = lv.style_t()
style_saved_cont0_main_main_default.init()
style_saved_cont0_main_main_default.set_radius(0)
style_saved_cont0_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x43))
style_saved_cont0_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x43))
style_saved_cont0_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_saved_cont0_main_main_default.set_bg_opa(255)
style_saved_cont0_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_saved_cont0_main_main_default.set_border_width(0)
style_saved_cont0_main_main_default.set_border_opa(255)
style_saved_cont0_main_main_default.set_pad_left(0)
style_saved_cont0_main_main_default.set_pad_right(0)
style_saved_cont0_main_main_default.set_pad_top(0)
style_saved_cont0_main_main_default.set_pad_bottom(0)

# add style for saved_cont0
saved_cont0.add_style(style_saved_cont0_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create saved_btnsavecontinue
saved_btnsavecontinue = lv.btn(saved)
saved_btnsavecontinue.set_pos(int(168),int(229))
saved_btnsavecontinue.set_size(140,47)
saved_btnsavecontinue.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
saved_btnsavecontinue_label = lv.label(saved_btnsavecontinue)
saved_btnsavecontinue_label.set_text("CONTINUE")
saved_btnsavecontinue.set_style_pad_all(0, lv.STATE.DEFAULT)
saved_btnsavecontinue_label.align(lv.ALIGN.CENTER,0,0)
# create style style_saved_btnsavecontinue_main_main_default
style_saved_btnsavecontinue_main_main_default = lv.style_t()
style_saved_btnsavecontinue_main_main_default.init()
style_saved_btnsavecontinue_main_main_default.set_radius(50)
style_saved_btnsavecontinue_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_saved_btnsavecontinue_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_saved_btnsavecontinue_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_saved_btnsavecontinue_main_main_default.set_bg_opa(255)
style_saved_btnsavecontinue_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_saved_btnsavecontinue_main_main_default.set_border_width(2)
style_saved_btnsavecontinue_main_main_default.set_border_opa(255)
style_saved_btnsavecontinue_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_saved_btnsavecontinue_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_saved_btnsavecontinue_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_saved_btnsavecontinue_main_main_default.set_text_font(lv.font_montserrat_16)
style_saved_btnsavecontinue_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for saved_btnsavecontinue
saved_btnsavecontinue.add_style(style_saved_btnsavecontinue_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create saved_label2
saved_label2 = lv.label(saved)
saved_label2.set_pos(int(150),int(188))
saved_label2.set_size(180,23)
saved_label2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
saved_label2.set_text("File saved")
saved_label2.set_long_mode(lv.label.LONG.WRAP)
# create style style_saved_label2_main_main_default
style_saved_label2_main_main_default = lv.style_t()
style_saved_label2_main_main_default.init()
style_saved_label2_main_main_default.set_radius(0)
style_saved_label2_main_main_default.set_bg_color(lv.color_make(0x4a,0xb2,0x41))
style_saved_label2_main_main_default.set_bg_grad_color(lv.color_make(0x4a,0xb2,0x41))
style_saved_label2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_saved_label2_main_main_default.set_bg_opa(0)
style_saved_label2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_saved_label2_main_main_default.set_text_font(lv.font_arial_16)
except AttributeError:
    try:
        style_saved_label2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_saved_label2_main_main_default.set_text_font(lv.font_montserrat_16)
style_saved_label2_main_main_default.set_text_letter_space(2)
style_saved_label2_main_main_default.set_text_line_space(0)
style_saved_label2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_saved_label2_main_main_default.set_pad_left(0)
style_saved_label2_main_main_default.set_pad_right(0)
style_saved_label2_main_main_default.set_pad_top(0)
style_saved_label2_main_main_default.set_pad_bottom(0)

# add style for saved_label2
saved_label2.add_style(style_saved_label2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create saved_img1
saved_img1 = lv.img(saved)
saved_img1.set_pos(int(185),int(47))
saved_img1.set_size(100,117)
saved_img1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
saved_img1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('/home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp1439365306.png','rb') as f:
        saved_img1_img_data = f.read()
except:
    print('Could not open /home/mx3g/GUI-Guider-Projects/TFT3/generated/mPythonImages/mp1439365306.png')
    sys.exit()

saved_img1_img = lv.img_dsc_t({
  'data_size': len(saved_img1_img_data),
  'header': {'always_zero': 0, 'w': 100, 'h': 117, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': saved_img1_img_data
})

saved_img1.set_src(saved_img1_img)
saved_img1.set_pivot(0,0)
saved_img1.set_angle(0)
# create style style_saved_img1_main_main_default
style_saved_img1_main_main_default = lv.style_t()
style_saved_img1_main_main_default.init()
style_saved_img1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_saved_img1_main_main_default.set_img_recolor_opa(0)
style_saved_img1_main_main_default.set_img_opa(255)

# add style for saved_img1
saved_img1.add_style(style_saved_img1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)



def home_imgbtnset_pressed_2_event_cb(e):
    src = e.get_target()
    code = e.get_code()
    guider_load_screen(ScreenEnum.SCR_SETUP)
    lv_demo_printer_anim_in_all(setup, 200)

home_imgbtnset.add_event_cb(lambda e: home_imgbtnset_pressed_2_event_cb(e), lv.EVENT.PRESSED, None)


def home_imgbtnprt_pressed_2_event_cb(e):
    src = e.get_target()
    code = e.get_code()
    guider_load_screen(ScreenEnum.SCR_LOADER)
    add_loader(load_print)

home_imgbtnprt.add_event_cb(lambda e: home_imgbtnprt_pressed_2_event_cb(e), lv.EVENT.PRESSED, None)


def home_imgbtnscan_released_2_event_cb(e):
    src = e.get_target()
    code = e.get_code()
    guider_load_screen(ScreenEnum.SCR_LOADER)
    add_loader(load_scan)

home_imgbtnscan.add_event_cb(lambda e: home_imgbtnscan_released_2_event_cb(e), lv.EVENT.RELEASED, None)


def home_imgbtncopy_released_2_event_cb(e):
    src = e.get_target()
    code = e.get_code()
    guider_load_screen(ScreenEnum.SCR_LOADER)
    add_loader(load_copy)
    

home_imgbtncopy.add_event_cb(lambda e: home_imgbtncopy_released_2_event_cb(e), lv.EVENT.RELEASED, None)







# content from custom.pyclass ScreenEnum:
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


# Load the default screen
lv.scr_load(home)

while SDL.check():
    time.sleep_ms(5)
