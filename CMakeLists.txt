cmake_minimum_required(VERSION 3.14)

if(WIN32)
	add_compile_options("/std:c++latest")
endif(WIN32)

set(CMAKE_CXX_STANDARD 17)

project(ClassyLabyrinth)

add_executable(ClassyLabyrinth
	${PROJECT_SOURCE_DIR}/command.cpp
	${PROJECT_SOURCE_DIR}/command.h
	${PROJECT_SOURCE_DIR}/main.cpp
	${PROJECT_SOURCE_DIR}/character.cpp
	${PROJECT_SOURCE_DIR}/character.h
	${PROJECT_SOURCE_DIR}/enemy.cpp
	${PROJECT_SOURCE_DIR}/enemy.h
	${PROJECT_SOURCE_DIR}/hero.cpp
	${PROJECT_SOURCE_DIR}/hero.h
	${PROJECT_SOURCE_DIR}/world.cpp
	${PROJECT_SOURCE_DIR}/world.h
)
