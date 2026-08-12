cmake_minimum_required(VERSION 3.20)

project(quickjs C)

set(CMAKE_C_STANDARD 11)

add_library(quickjs STATIC
    cutils.c
    dtoa.c
    #libbf.c
    libregexp.c
    libunicode.c
    quickjs.c
    quickjs-libc.c
)

target_include_directories(quickjs
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(quickjs
    PRIVATE
        CONFIG_BIGNUM
        CONFIG_VERSION="2025-01-01"
)

if(WIN32)
    target_compile_definitions(quickjs
        PRIVATE
            CONFIG_WIN32
    )
endif()
