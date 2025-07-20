add_executable(${NAME}
    main.c
)

# Adiciona o subdiretório da biblioteca
add_subdirectory(onewire_library)

# Vincula as bibliotecas necessárias
target_link_libraries(${NAME} 
    pico_stdlib
    FreeRTOS-Kernel-Heap4
    freertos_config 
    pico_cyw43_arch_lwip_threadsafe_background
    onewire_library
)

# Gera arquivos extra
pico_add_extra_outputs(${NAME})

# Includes
target_include_directories(${NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/onewire_library
)

# Saída via USB e UART
pico_enable_stdio_usb(${NAME} 1)
pico_enable_stdio_uart(${NAME} 1)

# UART padrão
target_compile_definitions(${NAME} PRIVATE
    PICO_DEFAULT_UART_RX_PIN=17
    PICO_DEFAULT_UART_TX_PIN=16
)
