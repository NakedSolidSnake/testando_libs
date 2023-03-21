cmake_minimum_required(VERSION 3.16)
project(Kafka)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_BUILD_TYPE Debug)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(producer "")
target_link_libraries(producer ${CONAN_LIBS})
target_sources(producer 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/src/producer.c
    ${CMAKE_CURRENT_LIST_DIR}/src/common.c
    )
target_include_directories(producer
     PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src/
)

add_executable(consumer "")
target_link_libraries(consumer ${CONAN_LIBS})
target_sources(consumer 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/src/consumer.c
    ${CMAKE_CURRENT_LIST_DIR}/src/common.c
    )
target_include_directories(consumer
    PUBLIC
   ${CMAKE_CURRENT_LIST_DIR}/src/
)

add_custom_command(TARGET producer POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_SOURCE_DIR}/getting-started.ini 
    ${CMAKE_BINARY_DIR}/bin/getting-started.ini) 