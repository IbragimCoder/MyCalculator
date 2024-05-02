cmake_minimum_required(VERSION 3.26)
project(MyCalculator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(MAKE_PREFIX_PATH "C:\\Qt\\6.7.0\\mingw_64\\")

find_package(Qt6Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(MyCalculator main.cpp
        Calculator.cpp
        Calculator.h #[[bimbimbambam.png]])

target_link_libraries(MyCalculator Qt6::Widgets)