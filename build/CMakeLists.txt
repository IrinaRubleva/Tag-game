cmake_minimum_required(VERSION 3.10)

project(PLAY15)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(USE_LIST "Use list-based stack implementation" ON)

if(BUILD_SHARED_LIBS)
	set(LIBRARY_TYPE SHARED)
else()
	set(LIBRARY_TYPE STATIC)
endif()


if(USE_LIST)
	set(STACK_SOURCE stack_on_list.c)
else()
	set(STACK_SOURCE stack_on_massive.c)
endif()

add_library(play_in_15 ${LIBRARY_TYPE} ${STACK_SOURCE} play_in_15.h logic.c input.c)


target_include_directories(play_in_15 PUBLIC ${CMAKE_SOURCE_DIR})

add_executable(main main.c)
target_link_libraries(main play_in_15)	
