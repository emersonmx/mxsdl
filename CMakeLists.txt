cmake_minimum_required(VERSION 3.11)
project(mxsdl LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(mxsdl_VERSION_MAJOR 0)
set(mxsdl_VERSION_MINOR 1)
set(mxsdl_VERSION_REVISION 0)

# Configs
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Options
option(BUILD_TESTS "Build tests" OFF)
option(BUILD_EXAMPLES "Build examples" OFF)

# Compiler settings
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING
        "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
        FORCE)
endif(NOT CMAKE_BUILD_TYPE)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic")
endif()

if (CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fmessage-length=0")
endif()
if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmessage-length=0")
endif()

if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__NO_INLINE__ -D_USE_MATH_DEFINES")
    set(CMAKE_EXE_LINKER_FLAGS "-Wl,--subsystem,windows")
endif()

# Libs
include(ExternalProject)
include(FindPkgConfig)

include(thirdparty/mxg.cmake)

pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2_IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2_TTF REQUIRED SDL2_ttf>=2.0.0)
pkg_search_module(SDL2_MIXER REQUIRED SDL2_mixer>=2.0.0)
include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
    ${SDL2_MIXER_INCLUDE_DIRS}
)

# Build settings
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(src/mxsdl)

if (BUILD_TESTS)
    add_subdirectory(test)
endif()

if (BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
