cmake_minimum_required(VERSION 3.0.2)
project(kalman_filter_1D LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_RERQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_RERQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-std=c++17 -Wpedantic)

add_library(${PROJECT_NAME}_c src/c/src/${PROJECT_NAME}.c)
add_executable(driver_c src/driver.c)
target_link_libraries(driver_c ${PROJECT_NAME}_c)

add_library(${PROJECT_NAME}_cpp src/cpp/src/${PROJECT_NAME}.cpp)
add_executable(driver_cpp src/driver.cpp)
target_link_libraries(driver_cpp ${PROJECT_NAME}_cpp)
