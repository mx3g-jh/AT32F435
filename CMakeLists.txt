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

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/Src/Librarys/at32f435_437/cmsis/cm4/device_support/startup/gcc/linker/AT32F435xM_FLASH.ld)

add_link_options(-Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map)
add_link_options(-mcpu=${MCPU} -mthumb -mthumb-interwork)
add_link_options(-T ${LINKER_SCRIPT})

#add all the executables to build
set(PROJECT 
	mx3g/at32f435proj
)
	string(REPLACE "/" "-" PROJECT_NAME ${PROJECT})
	message( "Include PROJECT " ${PROJECT} " in build as " ${PROJECT_NAME})

	set(TARGET ${PROJECT_NAME}.elf)
	add_executable(${TARGET}
        ${CMAKE_SOURCE_DIR}/Src/Core/src/main.cpp
	)

	message("Target added: " ${TARGET})

    add_subdirectory(${CMAKE_SOURCE_DIR}/Src)
    target_link_libraries(${TARGET} PRIVATE
        tasks_lib
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
    # target_include_directories(${TARGET} PRIVATE $<TARGET_PROPERTY:common_lib,INTERFACE_INCLUDE_DIRECTORIES>)

	set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
	set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)

	add_custom_command(TARGET ${TARGET} POST_BUILD
	        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
	        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
	        COMMENT "Building ${HEX_FILE} \n\r Building ${BIN_FILE}"
	)

include(${CMAKE_DIR}/at32-gcc-jlink.cmake)