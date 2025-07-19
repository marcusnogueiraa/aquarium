cmake_minimum_required(VERSION 3.12)

set(NAME aquarium) 

set(PICO_BOARD pico_w)
set(PICO_PLATFORM rp2040)

include("$ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake")

project(${NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
add_compile_definitions(PICO_CXX_DISABLE_ALLOCATION_OVERRIDES)

pico_sdk_init()

# switch to your freertos path
SET(FREERTOS_KERNEL_PATH "/home/marcus-leloq/Documentos/ufc/7-term/rtos/RPIPicoFreeRTOSCourse/lib/FreeRTOS-Kernel" CACHE STRING "Common Lib")

SET(FREERTOS_CONFIG_FILE_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/port/FreeRTOS-Kernel" CACHE STRING "Local Config")
include("${FREERTOS_CONFIG_FILE_DIRECTORY}/freertos_config.cmake") 
include(FreeRTOS_Kernel_import.cmake)

add_subdirectory(src)

install(CODE "execute_process(COMMAND $ENV{HOME}/bin/picoDeploy.sh ${CMAKE_CURRENT_BINARY_DIR}/src/${NAME}.elf)")

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/src/${NAME}.uf2
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_GENERATOR "ZIP" "TGZ")
include(CPack)
