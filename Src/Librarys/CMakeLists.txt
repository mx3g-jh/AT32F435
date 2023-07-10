add_library(mavlink_lib INTERFACE)

target_include_directories(mavlink_lib
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/mavlink_v2/cubepilot
    ${CMAKE_CURRENT_SOURCE_DIR}/mavlink_v2/ASLUAV
    ${CMAKE_CURRENT_SOURCE_DIR}/mavlink_v2/common
    ${CMAKE_CURRENT_SOURCE_DIR}/mavlink_v2/csAirLink
    ${CMAKE_CURRENT_SOURCE_DIR}/mavlink_v2/cubepilot
    ${CMAKE_CURRENT_SOURCE_DIR}/mavlink_v2/development
    ${CMAKE_CURRENT_SOURCE_DIR}/mavlink_v2/icarous
    ${CMAKE_CURRENT_SOURCE_DIR}/mavlink_v2/matrixpilot
    ${CMAKE_CURRENT_SOURCE_DIR}/mavlink_v2/minimal
    ${CMAKE_CURRENT_SOURCE_DIR}/mavlink_v2/standard
    ${CMAKE_CURRENT_SOURCE_DIR}/mavlink_v2/test
    ${CMAKE_CURRENT_SOURCE_DIR}/mavlink_v2/uAvionix
    ${CMAKE_CURRENT_SOURCE_DIR}/mavlink_v2
)

target_compile_options(mavlink_lib INTERFACE -Wno-address-of-packed-member)

add_subdirectory(DataCenter)
add_subdirectory(lvgl)
add_subdirectory(middlewares)
add_subdirectory(at32f435_437)