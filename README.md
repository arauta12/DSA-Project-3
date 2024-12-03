# How to Install GTKmm-4.0 (for Windows)
1) Go to https://www.msys2.org/ and install MSYS2
2) Go to MSYS2 terminal
3) Run: pacman -S mingw-w64-x86_64-gtk4
4) Run: pacman -S mingw-w64-x86_64-gcc
5) Run: pacman -S mingw-w64-x86_64-pkg-config
6) Add msys2/mingw64 path in environment variables
7) Reconfigure toolchain (CLoin settings) to msys2/mingw64 (ctrl+alt+s then change toolset to C:\msys64\mingw64)
8) Run pacman -S mingw-w64-x86_64-gtkmm-4.0


# How to Add Matplotplusplus
1) Even though matplot++ is a file when cloned still run git clone https://github.com/alandefreitas/matplotplusplus/ (files are missing when cloned and this fixes that)
2) Download gnuplot from http://www.gnuplot.info/ and add it to file path

# How to Add a file to file path (Windows)
1) Press the window key + r and type sysdm.cpl hit enter
2) Go to advanced and click "Environmental Variables"
3) Then click path in system varialbes and edit
4) Click new and then add the bin file path for msys and gnuplot
5) Click ok until all windows are closed

# How to run
1) Click run and enter your sorting options and click sort
2) If click view sort stats **MUST** close the graph window and press enter in the console in that order to continue (a matplot thing)
3) Can continue sorting and resorting with other buttons on the GUI
4) For the graph may have to readjust window size to see both axis titles
