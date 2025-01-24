# learncpp
https://www.learncpp.com


https://stackoverflow.com/questions/39622501/mingw-installation-on-linux

## sudo apt-get install gcc-mingw-w64-x86-64 g++-mingw-w64-x86-64 wine64


## The following NEW packages will be installed:

  binutils-mingw-w64-x86-64 g++-mingw-w64-x86-64
  g++-mingw-w64-x86-64-posix g++-mingw-w64-x86-64-win32
  gcc-mingw-w64-base gcc-mingw-w64-x86-64
  gcc-mingw-w64-x86-64-posix gcc-mingw-w64-x86-64-posix-runtime
  gcc-mingw-w64-x86-64-win32 gcc-mingw-w64-x86-64-win32-runtime
  mingw-w64-common mingw-w64-x86-64-dev


## Compile:

x86_64-w64-mingw32-gcc -g -o hello hello.c

x86_64-w64-mingw32-g++ -g -o ch17q2s2 main.cpp

update-alternatives: using /usr/bin/x86_64-w64-mingw32-gcc-posix to provide /usr/bin/x86_64-w64-mingw32-gcc (x86_64-w64-mingw32-gcc) in auto mode
update-alternatives: using /usr/bin/x86_64-w64-mingw32-gcc-win32 to provide /usr/bin/x86_64-w64-mingw32-gcc (x86_64-w64-mingw32-gcc) in auto mode
update-alternatives: using /usr/bin/x86_64-w64-mingw32-g++-win32 to provide /usr/bin/x86_64-w64-mingw32-g++ (x86_64-w64-mingw32-g++) in auto mode


https://askubuntu.com/questions/1451704/how-to-install-mingw-w64-x86-64-gtk3-in-ubuntu-22-04

### cd ~/temp28/quasi-msys2/env/shell.sh

win-clang++ hello_world.cpp `pkg-config --cflags --libs gtk4`


## Для запуска в режиме RELEASE

g++ -std=c++20 -O main.cpp