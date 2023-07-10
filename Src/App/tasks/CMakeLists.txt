add_library(tasks_lib STATIC)

target_sources(tasks_lib
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/list/GT911_touch_task.c
  ${CMAKE_CURRENT_SOURCE_DIR}/list/Led_toggle.c
  ${CMAKE_CURRENT_SOURCE_DIR}/list/Lvgl_display_task.c
  ${CMAKE_CURRENT_SOURCE_DIR}/list/Debug_print.c
  ${CMAKE_CURRENT_SOURCE_DIR}/list/Lvgl_task.c
  ${CMAKE_CURRENT_SOURCE_DIR}/freertos_tasks.c
)

target_include_directories(tasks_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/list
)

target_link_libraries(tasks_lib
  PUBLIC
    core_lib
    datacenter_lib
    mavlink_lib
    mpu6050_driver
    ili9341_driver
    lvgl_lib
    freertos_lib
    at32f435_437_lib
    i2c_application_lib
)