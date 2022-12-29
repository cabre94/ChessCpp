cmake_minimum_required(VERSION 3.10)

project(ChessCpp)

add_executable(main main.cpp)

# list(APPEND includePath "/include" "/include/Boards" "/include/Boards")
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/)

message(STATUS "Include path: ${INCLUDE_DIR}")

# list(APPEND includePath "/some/dir" "/some/other/dir")

# set include directory
target_include_directories(
	main PUBLIC
	"${INCLUDE_DIR}"
	"${INCLUDE_DIR}/Boards"
	"${INCLUDE_DIR}/Pieces"
)