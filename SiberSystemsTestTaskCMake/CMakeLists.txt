cmake_minimum_required(VERSION 3.5)

project(SiberSystemsTestTaskCMake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(SiberSystemsTestTaskCMake
               main.cpp
               mainwindow.cpp
               ../SiberSystemsTestTask/threelistclass.cpp
               validationlineedit.cpp
               images.qrc
               )

target_link_libraries(SiberSystemsTestTaskCMake PRIVATE Qt5::Widgets)
