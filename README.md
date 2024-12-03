# How to Install GTK (for Windows)
1) Go to https://www.msys2.org/ and install MSYS2
2) Go to MSYS2 terminal
3) Run: pacman -S mingw-w64-x86_64-gtk4
4) Run: pacman -S mingw-w64-x86_64-gcc
5) Run: pacman -S mingw-w64-x86_64-pkg-config
6) Add msys2/mingw64 path in environment variables
7) Reconfigure toolchain (settings) to msys2/mingw64
8) Link gtk4 to CMAKE (use cmake file in github)
9) Run main.cpp. If it works, you should see a small window.

# How to Install Gtkmm 4.0 (for Windows)
1) In msys2 terminal, run this: pacman -S mingw-w64-x86_64-gtkmm-4.0
2) Follow CMAKE to link it locally to your machine.

# How to Add Matplotplusplus
1) Go to https://github.com/alandefreitas/matplotplusplus
2) Clone the repository above in your local machine in a folder
3) Move the folder to your C++ project directory
4) Link as a subdirectory in CMAKE
