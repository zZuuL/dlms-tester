cmake_minimum_required(VERSION 3.5)

project(dlms-tester)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ui)

include_directories(include)

file(GLOB SOURCES
    src/*.h
    src/*.cpp
    res/*.qrc
    ui/*.ui
)

add_executable (${PROJECT_NAME} ${SOURCES})

find_package(Qt5 CONFIG REQUIRED COMPONENTS
    Widgets
    Network
    Xml
)

target_link_libraries(${PROJECT_NAME}
    Qt5::Widgets
    Qt5::Network
    Qt5::Xml
)

