cmake_minimum_required(VERSION 3.29)
project(DSA_Project3)

set(CMAKE_CXX_STANDARD 17)

# Find GTK 4 package
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

# Include GTK 4 headers and link libraries
add_subdirectory(matplotplusplus)

# Set up the executable and link GTK 4 libraries
add_executable(DSA_Project3
        main.cpp
        HomeWindow.h
        DataWindow.h
        FileIO.h
        Graphing.h
        School.h
        HomeWindow.cpp
        DataWindow.cpp
)
target_link_libraries(DSA_Project3 matplot)
target_include_directories(DSA_Project3 PUBLIC ${GTKMM_INCLUDE_DIRS})
target_link_directories(DSA_Project3 PUBLIC ${GTKMM_LIBRARY_DIRS})
target_link_libraries(DSA_Project3 ${GTKMM_LIBRARIES})