add_library(i2c_application_lib STATIC)

target_sources(i2c_application_lib
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/i2c_application.c
)

target_include_directories(i2c_application_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(i2c_application_lib
  PUBLIC
    at32f435_437_lib
)