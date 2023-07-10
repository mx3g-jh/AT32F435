add_library(mpu6050_driver STATIC)

target_sources(mpu6050_driver
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/mpu6050.c
)

target_include_directories(mpu6050_driver
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(mpu6050_driver
  PUBLIC

  core_lib
  datacenter_lib
  ili9341_driver
  freertos_lib
  at32f435_437_lib
  i2c_application_lib
)