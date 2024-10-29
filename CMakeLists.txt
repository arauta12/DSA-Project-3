cmake_minimum_required(VERSION 3.29)
project(DSA_Project3)

set(CMAKE_CXX_STANDARD 14)

add_executable(DSA_Project3
    main.cpp
        FileReadingAndPlotting.h)

add_subdirectory(matplotplusplus)
add_executable(my_target FileReadingAndPlotting.h)
target_link_libraries(my_target PUBLIC matplot)
