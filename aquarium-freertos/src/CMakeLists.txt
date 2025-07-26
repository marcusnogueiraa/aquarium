# Defina o executável
add_executable(${PROJECT_NAME}
    main.c
    ../lib/dnsserver/dnsserver.c
    ../lib/dhcpserver/dhcpserver.c
    #temp_task.c
)

# Adiciona subdiretórios das bibliotecas
add_subdirectory(../lib/onewire_library ${CMAKE_BINARY_DIR}/onewire_library)

# Vincula as bibliotecas necessárias
target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    FreeRTOS-Kernel-Heap4
    freertos_config
    pico_cyw43_arch_lwip_threadsafe_background
    onewire_library
)

# Define diretórios de inclusão
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../include  # Para os cabeçalhos no include
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib/onewire_library  # Biblioteca de onewire
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib/dhcpserver  # Inclui diretório do dhcpserver
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib/dnsserver   # Inclui diretório do dnsserver
)

# Gera arquivos extra como binário, map, hex, uf2
pico_add_extra_outputs(${PROJECT_NAME})

# Ativa a saída via USB e UART
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 1)

# Define os pinos padrão de UART
target_compile_definitions(${PROJECT_NAME} PRIVATE
    PICO_DEFAULT_UART_RX_PIN=17
    PICO_DEFAULT_UART_TX_PIN=16
)

pico_configure_ip4_address(${PROJECT_NAME} PRIVATE
    CYW43_DEFAULT_IP_AP_ADDRESS 192.168.4.1
)
