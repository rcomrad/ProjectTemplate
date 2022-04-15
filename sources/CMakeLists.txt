cmake_minimum_required(VERSION 3.21)

add_subdirectory(core)
target_include_directories(core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(${PROJECT_NAME} PRIVATE core)

add_subdirectory(main)
target_include_directories(main PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(${PROJECT_NAME} PRIVATE main)

