add_library(freertos_lib STATIC)

target_sources(freertos_lib
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/source/list.c
  ${CMAKE_CURRENT_SOURCE_DIR}/source/event_groups.c
  ${CMAKE_CURRENT_SOURCE_DIR}/source/croutine.c
  ${CMAKE_CURRENT_SOURCE_DIR}/source/portable/memmang/heap_4.c
  # ${CMAKE_CURRENT_SOURCE_DIR}/source/portable/common/mpu_wrappers.c
  ${CMAKE_CURRENT_SOURCE_DIR}/source/portable/GCC/ARM_CM4F/port.c
  ${CMAKE_CURRENT_SOURCE_DIR}/source/timers.c
  ${CMAKE_CURRENT_SOURCE_DIR}/source/queue.c
  ${CMAKE_CURRENT_SOURCE_DIR}/source/stream_buffer.c
  ${CMAKE_CURRENT_SOURCE_DIR}/source/tasks.c
)

target_include_directories(freertos_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/source/include
    ${CMAKE_CURRENT_SOURCE_DIR}/source/portable/GCC/ARM_CM4F
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/source
    # ${CMAKE_CURRENT_SOURCE_DIR}/source/portable/common
    ${CMAKE_CURRENT_SOURCE_DIR}/source/portable/memmang
    ${CMAKE_CURRENT_SOURCE_DIR}/source/portable/GCC/ARM_CM4F
)

target_link_libraries(datacenter_lib
  PUBLIC
    at32f435_437_lib
)