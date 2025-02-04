# [www.learncpp.com](https://www.learncpp.com)


# [mingw installation on Linux](https://stackoverflow.com/questions/39622501/mingw-installation-on-linux)
```
sudo apt-get install gcc-mingw-w64-x86-64 g++-mingw-w64-x86-64 wine64
```
The following NEW packages will be installed:
```
  binutils-mingw-w64-x86-64 g++-mingw-w64-x86-64
  g++-mingw-w64-x86-64-posix g++-mingw-w64-x86-64-win32
  gcc-mingw-w64-base gcc-mingw-w64-x86-64
  gcc-mingw-w64-x86-64-posix gcc-mingw-w64-x86-64-posix-runtime
  gcc-mingw-w64-x86-64-win32 gcc-mingw-w64-x86-64-win32-runtime
  mingw-w64-common mingw-w64-x86-64-dev
```

Compile:
```
x86_64-w64-mingw32-gcc -g -o hello hello.c
x86_64-w64-mingw32-g++ -g -o ch17q2s2 main.cpp

update-alternatives: using /usr/bin/x86_64-w64-mingw32-gcc-posix to provide /usr/bin/x86_64-w64-mingw32-gcc (x86_64-w64-mingw32-gcc) in auto mode
update-alternatives: using /usr/bin/x86_64-w64-mingw32-gcc-win32 to provide /usr/bin/x86_64-w64-mingw32-gcc (x86_64-w64-mingw32-gcc) in auto mode
update-alternatives: using /usr/bin/x86_64-w64-mingw32-g++-win32 to provide /usr/bin/x86_64-w64-mingw32-g++ (x86_64-w64-mingw32-g++) in auto mode
```

# [How to install mingw-w64-x86_64-gtk3 in Ubuntu 22.04?](https://askubuntu.com/questions/1451704/how-to-install-mingw-w64-x86-64-gtk3-in-ubuntu-22-04)
- cd ~/temp28/quasi-msys2/env/shell.sh
- win-clang++ hello_world.cpp `pkg-config --cflags --libs gtk4`

```
sudo apt install make wget tar zstd gpg
git clone https://github.com/HolyBlackCat/quasi-msys2
cd quasi-msys2/
make install _gtk4   # equivalent to `make install mingw-w64-x86_64-gtk4`
```

I suggest using Clang, which can work with any MinGW flavor,
```
sudo apt install wine   # Optional.

# Install latest Clang
wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
sudo ./llvm.sh
rm llvm.sh

# Install more packages
make install _gcc _gdb    # We won't be using GCC, but we need libraries that come with it.

# Opens a new shell with the right environment variables configured.
env/shell.sh
```
Then, testing on Hello World from [here](https://www.gtk.org/docs/getting-started/hello-world):
```
# Notice `pkg-config` picking up the correct libraries.
win-clang++ hello_world.cpp `pkg-config --cflags --libs gtk4`
# This opens the app in Wine:
./a.exe
```

## Для компиляции в режиме RELEASE
```
g++ -std=c++20 -O main.cpp
```
