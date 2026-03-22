cmake_minimum_required(VERSION 3.19)
project(NCTorus
    VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# setup external packages
#include(CTest)

option(ENABLE_WARNINGS "Enable compiler warnings" ON)
option(STRICT_WARNINGS "Enable strict compiler warnings" ON)
option(ERROR_ON_WARNING "Treat warnings to errors" OFF)
#option(BUILD_DOC "Build documentation" OFF)
#option(FULL_TEST "Run full test set (may be slow)." OFF)

add_library(nctorus_warnings INTERFACE)
if(ENABLE_WARNINGS)
    target_compile_options(nctorus_warnings INTERFACE
        $<$<CXX_COMPILER_ID:GNU,Clang>: -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wundef>
        $<$<AND:$<BOOL:${STRICT_WARNINGS}>,$<CXX_COMPILER_ID:GNU,Clang>>: -Wconversion>
        $<$<CXX_COMPILER_ID:Clang>: -Wdocumentation>

        $<$<AND:$<BOOL:${ERROR_ON_WARNING}>,$<CXX_COMPILER_ID:GNU,Clang>>: -Werror>)
endif()

#if(BUILD_DOC)
#    add_subdirectory(doc)
#endif()

add_subdirectory(externals)
add_subdirectory(src)

#if(BUILD_TESTING)
#    add_subdirectory(tests)
#endif()
