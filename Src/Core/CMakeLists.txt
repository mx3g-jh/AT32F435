add_library(core_lib STATIC)

target_sources(core_lib
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src/fonts.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/timer.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/freertos_tick.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/bsp_spi_lcd.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/lv_tick_custom.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/lv_tick_custom.c
)

target_compile_options(core_lib PRIVATE -Wno-address-of-packed-member)

target_include_directories(core_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(core_lib
  PUBLIC
    datacenter_lib
    mavlink_lib
    mpu6050_driver
    ili9341_driver
    tasks_lib
    lvgl_lib
    freertos_lib
    at32f435_437_lib
    i2c_application_lib
)