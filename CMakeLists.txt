cmake_minimum_required(VERSION 3.0.2)
project(kalman_filter_1D LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_RERQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-std=c++17 -Wpedantic)

add_executable(${PROJECT_NAME}_c src/c/${PROJECT_NAME}.c)
add_library(${PROJECT_NAME}_cpp src/cpp/src/${PROJECT_NAME}.cpp)
