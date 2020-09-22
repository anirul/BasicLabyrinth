cmake_minimum_required(VERSION 3.14)

if(WIN32)
	add_compile_options("/std:c++latest")
endif(WIN32)

set(CMAKE_CXX_STANDARD 17)

project(BasicLabyrinth)

add_executable(BasicLabyrinth
	${PROJECT_SOURCE_DIR}/main.cpp
	${PROJECT_SOURCE_DIR}/room.cpp
	${PROJECT_SOURCE_DIR}/room.h
)
