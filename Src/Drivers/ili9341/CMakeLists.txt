add_library(ili9341_driver STATIC)

target_sources(ili9341_driver
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ili9341.c
    ${CMAKE_CURRENT_SOURCE_DIR}/fonts.c
    ${CMAKE_CURRENT_SOURCE_DIR}/touch_iic.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ili9341_touch.c
)

target_include_directories(ili9341_driver
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(ili9341_driver
  PUBLIC
  core_lib
  datacenter_lib
  freertos_lib
  at32f435_437_lib
)