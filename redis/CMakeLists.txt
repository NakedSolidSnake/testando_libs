cmake_minimum_required(VERSION 3.16)
project(Redis)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_BUILD_TYPE Debug)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(redis "")
target_link_libraries(redis ${CONAN_LIBS})
target_sources(redis 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/src/main.c
    )
