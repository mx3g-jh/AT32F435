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
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(AT_BSPACK_DIR ./AT32F413_Firmware_Library)

# project settings
project(at-start-f413-examples C CXX ASM)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

set(PROJECT_BINARY_DIR ./output)
file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

set(MCPU cortex-m4 #[[TODO kernel type, ex cortex-m4]])
add_compile_definitions(AT32F413RCT7;USE_STDPERIPH_DRIVER;AT_START_F413_V1)

#Uncomment for hardware floating point
#add_compile_definitions(ARM_MATH_CM4;ARM_MATH_MATRIX_CHECK;ARM_MATH_ROUNDING)
#add_compile_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)
#add_link_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)

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
    ${AT_BSPACK_DIR}/libraries/cmsis/cm4/device_support/startup/gcc/startup_at32f413.s
    ${AT_BSPACK_DIR}/libraries/cmsis/cm4/device_support/system_at32f413.c
)
add_library(at32f_lib OBJECT ${LIB_SOURCES})
target_include_directories(at32f_lib PRIVATE
        ${AT_BSPACK_DIR}/libraries/drivers/inc
	${AT_BSPACK_DIR}/project/at_start_f413/templates/inc
        ${AT_BSPACK_DIR}/libraries/cmsis/cm4/device_support
        ${AT_BSPACK_DIR}/libraries/cmsis/cm4/core_support
        )

#Middlewares for Examples
file(GLOB_RECURSE MIDDLEWARES_SOURCES
	"${AT_BSPACK_DIR}/middlewares/i2c_application_library/*.c"
	"${AT_BSPACK_DIR}/middlewares/3rd_party/fatfs/source/*.c"
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
	${AT_BSPACK_DIR}/project/at_start_f413/templates/inc
)

#USB Middleware for USB Examples
file(GLOB_RECURSE USB_MIDDLEWARE_SOURCES
    "${AT_BSPACK_DIR}/middlewares/usbd_drivers/src/*.*"
    "${AT_BSPACK_DIR}/middlewares/usbd_class/*.c"
)

#AT32F Board Library
#add_library(board_lib OBJECT ${AT_BSPACK_DIR}/project/at32f413_board/at32f413_board.c)
#target_include_directories(board_lib PRIVATE
#	${AT_BSPACK_DIR}/libraries/drivers/inc
#        ${AT_BSPACK_DIR}/libraries/cmsis/cm4/device_support
#        ${AT_BSPACK_DIR}/libraries/cmsis/cm4/core_support
#        ${AT_BSPACK_DIR}/project/at32f413_board
#)


set(LINKER_SCRIPT ${AT_BSPACK_DIR}/libraries/cmsis/cm4/device_support/startup/gcc/linker/AT32F413xC_FLASH.ld)

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
foreach(EXAMPLE 
	adc/combine_mode_ordinary_simult
	adc/current_vref_value_check
	adc/exint_trigger_partitioned
	adc/internal_temperature_sensor
	adc/software_trigger_repeat
	adc/tmr_trigger_automatic_preempted
	adc/voltage_monitoring
	bpr/bpr_data
	bpr/tamper
	can/communication_mode
	can/filter
	can/loopback_mode
	cortex_m4/bit_band
	cortex_m4/fpu
	cortex_m4/systick_interrupt
	crc/calculation
	crm/clock_failure_detection
	crm/sysclk_switch
	debug/tmr1
	dma/data_to_gpio_flexible
	dma/flash_to_sram
	exint/exint_config
	exint/exint_software_trigger
	flash/flash_write_read
	flash/operate_spim
	flash/run_in_spim
	gpio/led_toggle
	gpio/swjtag_remap
	i2c/communication_dma
	i2c/communication_int
	i2c/communication_poll
	i2c/eeprom
	i2s/halfduplex_dma
	i2s/halfduplex_interrupt
	i2s/spii2s_switch_halfduplex_polling
	pwc/deepsleep_rtc
	pwc/power_voltage_monitor
	pwc/sleep_tmr2
	pwc/sleep_usart1
	pwc/standby_rtc
	pwc/standby_wakeup_pin
	rtc/calendar
	rtc/lick_calibration
	sdio/sdio_fatfs
	sdio/sd_mmc_card
	spi/crc_transfer_polling
	spi/fullduplex_polling
	spi/halfduplex_interrupt
	spi/halfduplex_transceiver_switch
	spi/only_receive_mode_polling
	spi/use_jtagpin_hardwarecs_dma
	spi/w25q_flash
	sram/extend_sram
	tmr/6_steps
	tmr/7_pwm_output
	tmr/cascade_synchro
	tmr/complementary_signals
	tmr/dma
	tmr/dma_burst
	tmr/encoder_tmr2
	tmr/external_clock
	tmr/hall_xor_tmr2
	tmr/hang_mode
	tmr/input_capture
	tmr/oc_high
	tmr/oc_low
	tmr/oc_toggle_tmr3
	tmr/oc_toggle_tmr9
	tmr/one_cycle
	tmr/parallel_synchro
	tmr/pwm_input
	tmr/pwm_input_dma
	tmr/pwm_output_simulate
	tmr/pwm_output_tmr10
	tmr/pwm_output_tmr3
	tmr/timer_base
	tmr/tmr1_synchro
	tmr/tmr2_32bit
	usart/half_duplex
	usart/hw_flow_control
	usart/idle_detection
	usart/interrupt
	usart/irda
	usart/polling
	usart/printf
	usart/receiver_mute
	usart/smartcard
	usart/synchronous
	usart/transfer_by_dma_interrupt
	usart/transfer_by_dma_polling
	acc/calibration
	usb_device/audio
	usb_device/composite_audio_hid
	usb_device/composite_vcp_keyboard
	usb_device/custom_hid
	usb_device/keyboard
	usb_device/mouse
	usb_device/msc
	usb_device/printer
	usb_device/vcp_loopback
	usb_device/virtual_msc_iap
	wdt/wdt_reset
	wwdt/wwdt_reset
)
	string(REPLACE "/" "-" EXAMPLE_NAME ${EXAMPLE})
	message( "Include example " ${EXAMPLE} " in build as " ${EXAMPLE_NAME})
	file(GLOB_RECURSE EXAMPLE_SOURCES "${AT_BSPACK_DIR}/project/at_start_f413/examples/${EXAMPLE}/src/*.*")

	set(TARGET ${EXAMPLE_NAME}.elf)
	add_executable(${TARGET} 
		$<TARGET_OBJECTS:at32f_lib>
		$<TARGET_OBJECTS:middlewares_lib>
		${AT_BSPACK_DIR}/project/at32f413_board/at32f413_board.c		
		${EXAMPLE_SOURCES}
		${LINKER_SCRIPT}
	)
	message("Target added: " ${TARGET})
	target_include_directories(${TARGET} PRIVATE 
        	${AT_BSPACK_DIR}/libraries/drivers/inc
	        ${AT_BSPACK_DIR}/libraries/cmsis/cm4/device_support
	        ${AT_BSPACK_DIR}/libraries/cmsis/cm4/core_support
		${AT_BSPACK_DIR}/project/at32f413_board
	        ${middleware_headers} ##This might be bad - because I think we have conflicts.... but we can put it after the libs
		${AT_BSPACK_DIR}/project/at_start_f413/examples/${EXAMPLE}/inc
	)

	if(${EXAMPLE} MATCHES "usb.*|acc.*")
#		add_library(usbmiddleware_lib OBJECT ${USB_MIDDLEWARE_SOURCES})
#		target_include_directories(usbmiddleware_lib PRIVATE
#			${middleware_headers}
#		)

		#USB Middleware for USB Examples
		file(GLOB_RECURSE USB_EXTRA_SOURCES
		    "${AT_BSPACK_DIR}/middlewares/usbd_drivers/src/*.*"
		)
		target_sources(${TARGET} PRIVATE ${USB_EXTRA_SOURCES})

		get_usb_depends(${EXAMPLE})
		message( "Adding USB sources " ${FOUND_USB_DEPENDS})
		foreach(D ${FOUND_USB_DEPENDS})
			file(GLOB_RECURSE USB_EXTRA_SOURCES
			    "${D}/*.c"
			)	
			target_sources(${TARGET} PRIVATE ${USB_EXTRA_SOURCES})
		endforeach()

#		target_sources(${TARGET} PRIVATE $<TARGET_OBJECTS:usbmiddleware_lib>)
	endif()

	set(HEX_FILE ${PROJECT_BINARY_DIR}/${EXAMPLE_NAME}.hex)
	set(BIN_FILE ${PROJECT_BINARY_DIR}/${EXAMPLE_NAME}.bin)

	add_custom_command(TARGET ${TARGET} POST_BUILD
	        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${EXAMPLE_NAME}.elf> ${HEX_FILE}
	        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${EXAMPLE_NAME}.elf> ${BIN_FILE}
	        COMMENT "Building ${HEX_FILE} \n\r Building ${BIN_FILE}"
	)
endforeach()
