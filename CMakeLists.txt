cmake_minimum_required(VERSION 3.21)
project(ProjectTemplate VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

add_executable(${PROJECT_NAME} "sources/main/main.cpp")

add_subdirectory("sources")

set(Configuration "D")

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/$<0:>)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}")
set_target_properties(${PROJECT_NAME}  PROPERTIES SUFFIX "_V${CMAKE_PROJECT_VERSION}_${Configuration}.exe")

#target_compile_definitions(${PROJECT_NAME} PROJECT_PATH = "${CMAKE_CURRENT_SOURCE_DIR}")