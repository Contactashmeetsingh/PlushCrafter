cmake_minimum_required(VERSION 3.5)

project(PlushCrafterApp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# List all your source files (.cpp) here
set(SOURCES
    main.cpp
    Application.cpp
    BearStorage.cpp
    PlushBear.cpp
)

# (Optional) List headers to show them in IDEs; not required to build
set(HEADERS
    Application.h
    BearStorage.h
    PlushBear.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# If later you add a Qt GUI, we will extend this CMake file with:
#   find_package(Qt6 REQUIRED COMPONENTS Widgets)
#   target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
# and we will switch to Qt's AUTOMOC/AUTOUIC/AUTORCC helpers.
