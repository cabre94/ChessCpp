cmake_minimum_required(VERSION 3.13.0)

project(ChessCpp LANGUAGES CXX)	# This sets CMAKE_PROJECT_NAME, but nested
								# calls changes PROJECT_NAME, CMAKE_PROJECT_NAME

# Ensure minimum C++ version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build options
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    set(COMPILER_WARNINGS -Wall -Wextra -Werror -Wpedantic -Wshadow -Wconversion -Wmissing-declarations -Werror=missing-include-dirs  -Werror=undef)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(COMPILER_WARNINGS "/W4 /WX")
endif()


# Create executable
add_executable(chess_main)
target_compile_options(chess_main PRIVATE ${COMPILER_WARNINGS})

# source files
target_sources(chess_main PRIVATE "main.cpp")

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/)
message(STATUS "Include path: ${INCLUDE_DIR}")

# set include directory
target_include_directories(
	chess_main PRIVATE
	"${INCLUDE_DIR}"
)

add_subdirectory("src")

# TODO: use variable to activate tests
enable_testing()
add_subdirectory(test)