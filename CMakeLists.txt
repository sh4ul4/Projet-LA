cmake_minimum_required(VERSION 3.1.0)

project(TreeApp)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()


find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(TreeApp
    TreeApp/mainwindow.ui
    TreeApp/mainwindow.cpp
    TreeApp/mainwindow.h
    TreeApp/line.cpp
    TreeApp/line.h
    TreeApp/panel.cpp
    TreeApp/panel.h
    TreeApp/Sommet.cpp
    TreeApp/Sommet.h
    TreeApp/Tree.cpp
    TreeApp/Tree.h
    TreeApp/main.cpp
)

target_link_libraries(TreeApp Qt5::Widgets)