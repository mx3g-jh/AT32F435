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
set(MCU_NAME AT32F435CMU7)

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

#AT32F BSP Libraries
file(GLOB_RECURSE LIB_SOURCES
    "${AT_BSPACK_DIR}/libraries/drivers/src/*.*"
    ${AT_BSPACK_DIR}/libraries/cmsis/cm4/device_support/startup/gcc/startup_at32f435_437.s
    ${AT_BSPACK_DIR}/libraries/cmsis/cm4/device_support/system_at32f435_437.c
)
add_library(at32f_lib OBJECT ${LIB_SOURCES})
target_include_directories(at32f_lib PRIVATE
        ${AT_BSPACK_DIR}/libraries/drivers/inc
	${AT_BSPACK_DIR}/project/at_start_f435/templates/inc
        ${AT_BSPACK_DIR}/libraries/cmsis/cm4/device_support
        ${AT_BSPACK_DIR}/libraries/cmsis/cm4/core_support
        )

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
	${AT_BSPACK_DIR}/project/at_start_f435/templates/inc
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
	file(GLOB_RECURSE PROJECT_SOURCES "${CMAKE_SOURCE_DIR}/Src/Core/src/*.*")

	set(TARGET ${PROJECT_NAME}.elf)
	add_executable(${TARGET} 
		$<TARGET_OBJECTS:at32f_lib>
		$<TARGET_OBJECTS:middlewares_lib>
		${AT_BSPACK_DIR}/project/at32f435_437_board/at32f435_437_board.c		
		${PROJECT_SOURCES}
		${LINKER_SCRIPT}
	)
	message("Target added: " ${TARGET})
	target_include_directories(${TARGET} PRIVATE 
        	${AT_BSPACK_DIR}/libraries/drivers/inc
	        ${AT_BSPACK_DIR}/libraries/cmsis/cm4/device_support
	        ${AT_BSPACK_DIR}/libraries/cmsis/cm4/core_support
			${AT_BSPACK_DIR}/project/at32f435_437_board
	        ${middleware_headers} ##This might be bad - because I think we have conflicts.... but we can put it after the libs
			${CMAKE_SOURCE_DIR}/Src/Core/inc
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