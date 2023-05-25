cmake_minimum_required(VERSION 3.15)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)

# specify cross compilers and tools
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(SIZE arm-none-eabi-size)

# find additional toolchain executables
find_program(ARM_GDB_EXECUTABLE arm-none-eabi-gdb)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(AT_BSPACK_DIR ${CMAKE_SOURCE_DIR}/AT32F435_Firmware_Library)
set(CMAKE_DIR ${CMAKE_SOURCE_DIR}/cmake)
set(MCU_NAME -AT32F435CMU7)

# project settings
project(at32f435proj C CXX ASM)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

set(PROJECT_BINARY_DIR ${CMAKE_SOURCE_DIR}/build/output)
file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

set(MCPU cortex-m4 #[[TODO kernel type, ex cortex-m4]])
add_compile_definitions(AT32F435CMU7;USE_STDPERIPH_DRIVER;AT_START_F435_V1)

#Uncomment for hardware floating point
add_compile_definitions(ARM_MATH_CM4;ARM_MATH_MATRIX_CHECK;ARM_MATH_ROUNDING)
add_compile_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)
add_link_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)

#Uncomment for software floating point
#add_compile_options(-mfloat-abi=soft)

#Set the Extended SRAM for your chip (TODO check the docs)
add_compile_definitions(EXTEND_SRAM=0x00) #64K
#add_compile_definitions(EXTEND_SRAM=0x01) #16K
#add_compile_definitions(EXTEND_SRAM=0x03) #32K


add_compile_options(-mcpu=${MCPU} -mthumb -mthumb-interwork)
add_compile_options(-ffunction-sections -fdata-sections -fno-common -fmessage-length=0)
add_link_options(-specs=nosys.specs)

# uncomment to mitigate c++17 absolute addresses warnings
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-register")

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    message(STATUS "Maximum optimization for speed")
    add_compile_options(-Ofast)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    message(STATUS "Maximum optimization for speed, debug info included")
    add_compile_options(-Ofast -g)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    message(STATUS "Maximum optimization for size")
    add_compile_options(-Os)
else ()
    message(STATUS "Minimal optimization, debug info included")
    add_compile_options(-Og -g)
endif ()

MACRO(HEADER_DIRECTORIES START_DIR return_list)
    FILE(GLOB_RECURSE new_list
		"${START_DIR}/*.h"
	)
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

HEADER_DIRECTORIES(${AT_BSPACK_DIR}/middlewares middleware_headers)
list(LENGTH middleware_headers header_dir_list_count)
message(STATUS "[INFO] Found ${header_dir_list_count} header directories.")
foreach(L ${middleware_headers})
	message(${L})
endforeach()

add_definitions(#[[TODO insert definitions, ex. -DUSE_HAL_DRIVER -DCORE_CM4 -DDEBUG -DSTM32H745xx]])

# include_directories(
# 	${CMAKE_SOURCE_DIR}/Src/Drivers/st7789/inc
# 	${CMAKE_SOURCE_DIR}/Src/Core/inc
# 	${CMAKE_SOURCE_DIR}/Src/Drivers/st7789/inc
# 	${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/drivers
# 	${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos
# 	${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/widgets
# 	${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music
# 	${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/benchmark
# 	${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/stress
# 	${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl 
# 	${AT_BSPACK_DIR}/libraries/drivers/inc
# 	${AT_BSPACK_DIR}/libraries/cmsis/cm4/device_support
# 	${AT_BSPACK_DIR}/libraries/cmsis/cm4/core_support
# 	${AT_BSPACK_DIR}/project/at32f435_437_board
# 	${middleware_headers} ##This might be bad - because I think we have conflicts.... but we can put it after the libs
# 	${CMAKE_SOURCE_DIR}/Src/Core/inc
# 	${CMAKE_SOURCE_DIR}/Src/App
# )

#AT32F BSP Libraries
file(GLOB_RECURSE LIB_SOURCES
    "${AT_BSPACK_DIR}/libraries/drivers/src/*.*"
    ${AT_BSPACK_DIR}/libraries/cmsis/cm4/device_support/startup/gcc/startup_at32f435_437.s
    ${AT_BSPACK_DIR}/libraries/cmsis/cm4/device_support/system_at32f435_437.c
)
add_library(at32f_lib OBJECT ${LIB_SOURCES})
target_include_directories(at32f_lib PRIVATE
        ${AT_BSPACK_DIR}/libraries/drivers/inc
        ${CMAKE_SOURCE_DIR}/Src/Core/inc
        ${AT_BSPACK_DIR}/libraries/cmsis/cm4/device_support
        ${AT_BSPACK_DIR}/libraries/cmsis/cm4/core_support
        )

#LVGL Libraries
set(LVGL_LIBS_SRC
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/core/lv_group.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/core/lv_refr.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/core/lv_obj_scroll.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/core/lv_obj_style_gen.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/core/lv_obj_tree.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/core/lv_theme.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/core/lv_indev_scroll.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/core/lv_obj.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/core/lv_obj_draw.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/core/lv_obj_class.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/core/lv_disp.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/core/lv_event.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/core/lv_obj_style.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/core/lv_indev.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/core/lv_obj_pos.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_area.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_anim.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_color.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_txt.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_math.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_style_gen.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_log.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_anim_timeline.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_async.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_lru.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_txt_ap.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_style.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_timer.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_printf.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_utils.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_templ.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_tlsf.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_fs.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_bidi.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_mem.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_ll.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/misc/lv_gc.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/hal/lv_hal_disp.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/hal/lv_hal_indev.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/hal/lv_hal_tick.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/widgets/lv_dropdown.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/widgets/lv_table.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/widgets/lv_slider.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/widgets/lv_roller.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/widgets/lv_arc.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/widgets/lv_textarea.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/widgets/lv_line.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/widgets/lv_btn.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/widgets/lv_canvas.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/widgets/lv_img.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/widgets/lv_bar.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/widgets/lv_objx_templ.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/widgets/lv_btnmatrix.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/widgets/lv_label.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/widgets/lv_checkbox.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/widgets/lv_switch.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_26.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_34.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_8.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_18.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_16.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_32.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_simsun_16_cjk.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_28.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_36.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_44.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_30.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_24.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_28_compressed.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_42.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_22.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_40.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_46.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_10.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_48.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_fmt_txt.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_38.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_loader.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_14.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_dejavu_16_persian_hebrew.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_12.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_unscii_16.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_unscii_8.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_20.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/font/lv_font_montserrat_12_subpx.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/others/snapshot/lv_snapshot.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/others/ime/lv_ime_pinyin.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/others/monkey/lv_monkey.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/others/imgfont/lv_imgfont.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/others/gridnav/lv_gridnav.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/others/msg/lv_msg.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/others/fragment/lv_fragment_manager.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/others/fragment/lv_fragment.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/themes/mono/lv_theme_mono.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/themes/default/lv_theme_default.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/themes/basic/lv_theme_basic.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/layouts/grid/lv_grid.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/layouts/flex/lv_flex.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/widgets/list/lv_list.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/widgets/imgbtn/lv_imgbtn.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/widgets/calendar/lv_calendar.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/widgets/win/lv_win.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/widgets/colorwheel/lv_colorwheel.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/widgets/tileview/lv_tileview.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/widgets/tabview/lv_tabview.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/widgets/span/lv_span.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/widgets/animimg/lv_animimg.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/widgets/keyboard/lv_keyboard.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/widgets/meter/lv_meter.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/widgets/spinner/lv_spinner.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/widgets/menu/lv_menu.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/widgets/chart/lv_chart.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/widgets/led/lv_led.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/widgets/msgbox/lv_msgbox.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/widgets/spinbox/lv_spinbox.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/libs/bmp/lv_bmp.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/libs/sjpg/tjpgd.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/libs/sjpg/lv_sjpg.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/libs/gif/gifdec.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/libs/gif/lv_gif.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/libs/freetype/lv_freetype.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/libs/fsdrv/lv_fs_win32.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/libs/fsdrv/lv_fs_stdio.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/libs/fsdrv/lv_fs_posix.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/libs/ffmpeg/lv_ffmpeg.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/libs/png/lodepng.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/libs/png/lv_png.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/libs/qrcode/qrcodegen.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/libs/qrcode/lv_qrcode.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/libs/rlottie/lv_rlottie.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/extra/lv_extra.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/lv_draw.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/swm341_dma2d/lv_gpu_swm341_dma2d.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/lv_draw_mask.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/lv_draw_arc.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/nxp/pxp/lv_draw_pxp.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/nxp/vglite/lv_vglite_buf.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/nxp/vglite/lv_vglite_utils.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/stm32_dma2d/lv_gpu_stm32_dma2d.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/lv_draw_layer.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/lv_draw_line.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sdl/lv_draw_sdl_rect.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sdl/lv_draw_sdl_label.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sdl/lv_draw_sdl_layer.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sdl/lv_draw_sdl_mask.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sdl/lv_draw_sdl_composite.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sdl/lv_draw_sdl_line.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sdl/lv_draw_sdl_utils.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sdl/lv_draw_sdl_bg.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sdl/lv_draw_sdl_img.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sdl/lv_draw_sdl_arc.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sdl/lv_draw_sdl.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sdl/lv_draw_sdl_polygon.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/lv_draw_rect.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/lv_draw_transform.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/lv_img_buf.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/arm2d/lv_gpu_arm2d.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/lv_draw_img.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/lv_draw_label.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/lv_img_decoder.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/lv_img_cache.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sw/lv_draw_sw_layer.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sw/lv_draw_sw_blend.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sw/lv_draw_sw.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sw/lv_draw_sw_letter.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sw/lv_draw_sw_transform.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sw/lv_draw_sw_img.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sw/lv_draw_sw_line.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sw/lv_draw_sw_arc.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sw/lv_draw_sw_gradient.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sw/lv_draw_sw_dither.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sw/lv_draw_sw_polygon.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/sw/lv_draw_sw_rect.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/src/draw/lv_draw_triangle.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/stress/lv_demo_stress.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/benchmark/lv_demo_benchmark.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb565a8.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/widgets/lv_demo_widgets.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/widgets/assets/img_clothes.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/widgets/assets/img_demo_widgets_avatar.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/widgets/assets/img_lvgl_logo.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/lv_demo_music_main.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/lv_demo_music.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/lv_demo_music_list.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_cover_2_large.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_icon_1_large.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_slider_knob.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_corner_left.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_corner_right_large.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_btn_loop.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_btn_prev.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_corner_left_large.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_icon_4.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_cover_3_large.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_btn_pause_large.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_btn_next.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_btn_corner_large.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_btn_play_large.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_cover_1.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_icon_3.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_corner_right.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_wave_bottom_large.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_btn_play.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_icon_1.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_cover_3.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_logo.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_wave_bottom.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_btn_list_pause.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_list_border_large.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_wave_top.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_slider_knob_large.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_btn_list_play.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_icon_2.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_icon_3_large.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_btn_prev_large.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_btn_rnd.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_btn_next_large.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_btn_list_pause_large.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_cover_1_large.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_icon_2_large.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_icon_4_large.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_cover_2.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_btn_list_play_large.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_btn_pause.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_btn_loop_large.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_wave_top_large.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_list_border.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music/assets/img_lv_demo_music_btn_rnd_large.c
    # ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/keypad_encoder/lv_demo_keypad_encoder.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/drivers/lv_port_indev.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/drivers/lv_port_disp.c
    ${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/drivers/lv_port_fs.c
)

# add_library(lvgl_lib OBJECT ${LVGL_LIBS_SRC})
# include_directories(lvgl_lib PRIVATE
# 		${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/drivers
# 		${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos
# 		${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/widgets
# 		${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music
# 		${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/benchmark
# 		${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/stress
# 		${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl
#         )

#Middlewares for Examples
file(GLOB_RECURSE MIDDLEWARES_SOURCES
	"${AT_BSPACK_DIR}/middlewares/i2c_application_library/*.c"
)
list(FILTER MIDDLEWARES_SOURCES EXCLUDE REGEX ".*diskio.c$") #Remove the stub implementation
foreach(MW ${MIDDLEWARES_SOURCES})
	message("Including middleware: " ${MW})
endforeach()
add_library(middlewares_lib OBJECT ${MIDDLEWARES_SOURCES})
target_include_directories(middlewares_lib PRIVATE
        ${middleware_headers}
        ${AT_BSPACK_DIR}/libraries/cmsis/cm4/device_support
        ${AT_BSPACK_DIR}/libraries/cmsis/cm4/core_support
        ${AT_BSPACK_DIR}/libraries/drivers/inc
        ${CMAKE_SOURCE_DIR}/Src/Core/inc
)

#USB Middleware for USB Examples
file(GLOB_RECURSE USB_MIDDLEWARE_SOURCES
    "${AT_BSPACK_DIR}/middlewares/usbd_drivers/src/*.*"
    "${AT_BSPACK_DIR}/middlewares/usbd_class/*.c"
)

set(LINKER_SCRIPT ${AT_BSPACK_DIR}/libraries/cmsis/cm4/device_support/startup/gcc/linker/AT32F435xM_FLASH.ld)

add_link_options(-Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map)
add_link_options(-mcpu=${MCPU} -mthumb -mthumb-interwork)
add_link_options(-T ${LINKER_SCRIPT})

#Special depends for USB examples
set(USB_DEPENDS)
macro(add_usb_depends MODULE)
	set(DEPENDS_LIST ${ARGN})
	list(JOIN DEPENDS_LIST ":" DEPENDS_STR)
	list(APPEND USB_DEPENDS ${MODULE}:${DEPENDS_STR})	
endmacro()

macro(get_usb_depends MODULE)
 	set(FOUND_USB_DEPENDS)
	foreach(D ${USB_DEPENDS})
		#Turn D into a list - with replace!
		string(REGEX REPLACE ":" ";" D_LIST ${D})
		list(POP_FRONT D_LIST MODULE_KEY)
		if(${MODULE} STREQUAL ${MODULE_KEY})
			set(FOUND_USB_DEPENDS ${D_LIST})
		endif()
	endforeach()
endmacro()

add_usb_depends(usb_device/msc ${AT_BSPACK_DIR}/middlewares/usbd_class/msc)
add_usb_depends(usb_device/audio ${AT_BSPACK_DIR}/middlewares/usbd_class/audio)
add_usb_depends(usb_device/mouse ${AT_BSPACK_DIR}/middlewares/usbd_class/mouse)
add_usb_depends(usb_device/keyboard ${AT_BSPACK_DIR}/middlewares/usbd_class/keyboard)
add_usb_depends(usb_device/printer ${AT_BSPACK_DIR}/middlewares/usbd_class/printer)
add_usb_depends(usb_device/custom_hid ${AT_BSPACK_DIR}/middlewares/usbd_class/custom_hid)
add_usb_depends(usb_device/composite_audio_hid ${AT_BSPACK_DIR}/middlewares/usbd_class/audio_hid)
add_usb_depends(usb_device/composite_vcp_keyboard ${AT_BSPACK_DIR}/middlewares/usbd_class/composite_cdc_keyboard)
add_usb_depends(usb_device/vcp_loopback ${AT_BSPACK_DIR}/middlewares/usbd_class/cdc)
add_usb_depends(usb_device/virtual_msc_iap ${AT_BSPACK_DIR}/middlewares/usbd_class/msc)
add_usb_depends(acc/calibration ${AT_BSPACK_DIR}/middlewares/usbd_class/cdc)

#add all the executables to build
set(PROJECT 
	mx3g/at32f435proj
)
	string(REPLACE "/" "-" PROJECT_NAME ${PROJECT})
	message( "Include PROJECT " ${PROJECT} " in build as " ${PROJECT_NAME})
	file(GLOB_RECURSE CORE_SOURCES "${CMAKE_SOURCE_DIR}/Src/Core/src/*.*")
	file(GLOB_RECURSE APP_SOURCES "${CMAKE_SOURCE_DIR}/Src/App/*.c" "${CMAKE_SOURCE_DIR}/Src/App/*.cpp")

	set(TARGET ${PROJECT_NAME}.elf)
	add_executable(${TARGET} 
		$<TARGET_OBJECTS:at32f_lib>
		$<TARGET_OBJECTS:middlewares_lib>
		${AT_BSPACK_DIR}/project/at32f435_437_board/at32f435_437_board.c
		${LVGL_LIBS_SRC}		
		${CORE_SOURCES}
		${APP_SOURCES}
		${LINKER_SCRIPT}
	)
	# target_link_libraries(${TARGET} PUBLIC lvgl_lib)
	message("Target added: " ${TARGET})
	target_include_directories(${TARGET} PRIVATE 
        	${AT_BSPACK_DIR}/libraries/drivers/inc
	        ${AT_BSPACK_DIR}/libraries/cmsis/cm4/device_support
	        ${AT_BSPACK_DIR}/libraries/cmsis/cm4/core_support
			${AT_BSPACK_DIR}/project/at32f435_437_board
	        ${middleware_headers} ##This might be bad - because I think we have conflicts.... but we can put it after the libs
			${CMAKE_SOURCE_DIR}/Src/Core/inc
			${CMAKE_SOURCE_DIR}/Src/App
			${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/drivers
			${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos
			${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/widgets
			${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/music
			${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/benchmark
			${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl/demos/stress
			${CMAKE_SOURCE_DIR}/Src/Librarys/lvgl/lvgl
	)

	if(${PROJECT} MATCHES "usb.*|acc.*")
#		add_library(usbmiddleware_lib OBJECT ${USB_MIDDLEWARE_SOURCES})
#		target_include_directories(usbmiddleware_lib PRIVATE
#			${middleware_headers}
#		)

		#USB Middleware for USB Examples
		file(GLOB_RECURSE USB_EXTRA_SOURCES
		    "${AT_BSPACK_DIR}/middlewares/usbd_drivers/src/*.*"
		)
		target_sources(${TARGET} PRIVATE ${USB_EXTRA_SOURCES})

		get_usb_depends(${PROJECT})
		message( "Adding USB sources " ${FOUND_USB_DEPENDS})
		foreach(D ${FOUND_USB_DEPENDS})
			file(GLOB_RECURSE USB_EXTRA_SOURCES
			    "${D}/*.c"
			)	
			target_sources(${TARGET} PRIVATE ${USB_EXTRA_SOURCES})
		endforeach()

#		target_sources(${TARGET} PRIVATE $<TARGET_OBJECTS:usbmiddleware_lib>)
	endif()

	set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
	set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)

	add_custom_command(TARGET ${TARGET} POST_BUILD
	        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
	        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
	        COMMENT "Building ${HEX_FILE} \n\r Building ${BIN_FILE}"
	)

include(${CMAKE_DIR}/at32-gcc-jlink.cmake)