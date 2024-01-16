cmake_minimum_required(VERSION 3.5.0)

project(skymake VERSION 1.0.2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(skymake
    skymake.cpp
)

target_link_libraries(skymake Qt5::Widgets Qt5::Core Qt5::Gui)
