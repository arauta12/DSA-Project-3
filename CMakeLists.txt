cmake_minimum_required(VERSION 3.29)
project(DSA_Project3)

set(CMAKE_CXX_STANDARD 14)

# Find GTK 4 package
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

# Include GTK 4 headers and link libraries
include_directories(${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})
add_definitions(${GTK4_CFLAGS_OTHER})

# Set up the executable and link GTK 4 libraries
add_executable(DSA_Project3 main.cpp
        School.h
        Graphing.h)
target_link_libraries(DSA_Project3 ${GTK4_LIBRARIES})
