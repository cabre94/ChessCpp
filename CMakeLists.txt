# cmake_minimum_required(VERSION 3.10)
cmake_minimum_required(VERSION 3.13.0)

project(ChessCpp)

# add_executable(chess_main main.cpp)
add_executable(chess_main)
target_sources(chess_main PRIVATE "main.cpp")

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/)
message(STATUS "Include path: ${INCLUDE_DIR}")

# set include directory
target_include_directories(
	chess_main PRIVATE
	"${INCLUDE_DIR}"
	"${INCLUDE_DIR}/Boards"
	"${INCLUDE_DIR}/Pieces"
	"${INCLUDE_DIR}/Players"
)

add_subdirectory("src")
