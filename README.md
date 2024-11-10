How to install Matplot++ 
Do this all in Cloin project Clone the whole project

git clone https://github.com/alandefreitas/matplotplusplus/ 
and add the subdirectory to your CMake project:

add_subdirectory(matplotplusplus) 
When creating your executable, link the library to the targets you want:

add_executable(my_target main.cpp) 
target_link_libraries(my_target PUBLIC matplot) 

Add this header to your source files:

#include <matplot/matplot.h>
