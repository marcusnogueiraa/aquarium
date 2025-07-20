add_library(onewire_library STATIC
    onewire_library.c
)

pico_generate_pio_header(onewire_library ${CMAKE_CURRENT_LIST_DIR}/onewire_library.pio)

target_link_libraries(onewire_library
    pico_stdlib
    hardware_pio
)

target_include_directories(onewire_library PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)
