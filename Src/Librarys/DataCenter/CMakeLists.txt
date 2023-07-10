add_library(datacenter_lib STATIC)

target_sources(datacenter_lib
  PRIVATE
    Account.cpp
    DataCenter.cpp
    PingPongBuffer/PingPongBuffer.c
)

target_include_directories(datacenter_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/PingPongBuffer
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/PingPongBuffer
)

target_compile_options(datacenter_lib PRIVATE -Wno-address-of-packed-member)

target_link_libraries(datacenter_lib
  PUBLIC
    at32f435_437_lib
    lvgl_lib
)