# kalman_filter_1D


Implementation of [Kalman Filter](https://en.wikipedia.org/wiki/Kalman_filter) in one dimension based on what I have learned from this [playlist](https://www.youtube.com/watch?v=CaCcOwJPytQ&list=PLX2gX-ftPVXU3oUFNATxGXY90AULiqnWT)


## Requirements
gcc 9.4.0

More info on [compiler](#compiler)

## How to compile
```console
cd /path/to/kalman_filter_1D
bash clean_build.sh
```

## How to run
C library
```console
cd /path/to/kalman_filter_1D
./build/driver_c
```

C++ library
```console
cd /path/to/kalman_filter_1D
./build/driver_cpp
```

## clean_build.sh
A trivial shell script that checks and deletes if `build` folder exists.
Calls the cmake and make to build and compile the source code

## CMakeLists.txt
A basic cmake file to specify C and C++ standards, build type and compile options. The libraries are linked seperately with their drivers which are clearly named and direct.

## Formulas


$K$ stands for `kalman_gain`

$E_{est}$ stands for `error_in_estimate`

$E_{mea}$ stands for `error_in_measurement`

$$K = \frac{E_{est}}{E_{est} + E_{mea}}$$

So

$$ 0 \leq K \leq 1 $$

$X_{t-1}$ stands for `previous_estimate`

$X_t$ stands for `current_estimate`

$M$ stands for `current_measurement`

$$X_t = X_{t-1} + K(M - X_{t-1})$$

$E_{est_{t-1}}$ stands for `previous_error_in_estimate`

$$E_{est} = (1 - K) E_{est_{t-1}}$$


## kalman_filter_1D.cpp

## kalman_filter_1D.hpp

## kalman_filter_1D.c

## kalman_filter_1D.h

## Compiler
I'm using docker desktop on MacOS Ventura 13.0. So the `g++` on the system outputs the following lines.

```zsh
g++ -v
Apple clang version 14.0.0 (clang-1400.0.29.202)
Target: arm64-apple-darwin22.1.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```
Inside the docker
```bash
root@33f028642cdf:/# g++ -v
Using built-in specs.
COLLECT_GCC=g++
COLLECT_LTO_WRAPPER=/usr/lib/gcc/aarch64-linux-gnu/9/lto-wrapper
Target: aarch64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 9.4.0-1ubuntu1~20.04.1' --with-bugurl=file:///usr/share/doc/gcc-9/README.Bugs --enable-languages=c,ada,c++,go,d,fortran,objc,obj-c++,gm2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-9 --program-prefix=aarch64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-libquadmath --disable-libquadmath-support --enable-plugin --enable-default-pie --with-system-zlib --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --enable-fix-cortex-a53-843419 --disable-werror --enable-checking=release --build=aarch64-linux-gnu --host=aarch64-linux-gnu --target=aarch64-linux-gnu
Thread model: posix
gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04.1)
```
The gcc outputs the following lines

```zsh
gcc -v
Apple clang version 14.0.0 (clang-1400.0.29.202)
Target: arm64-apple-darwin22.1.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```

Inside the docker

```bash
root@33f028642cdf:/# gcc -v
Using built-in specs.
COLLECT_GCC=gcc
COLLECT_LTO_WRAPPER=/usr/lib/gcc/aarch64-linux-gnu/9/lto-wrapper
Target: aarch64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 9.4.0-1ubuntu1~20.04.1' --with-bugurl=file:///usr/share/doc/gcc-9/README.Bugs --enable-languages=c,ada,c++,go,d,fortran,objc,obj-c++,gm2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-9 --program-prefix=aarch64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-libquadmath --disable-libquadmath-support --enable-plugin --enable-default-pie --with-system-zlib --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --enable-fix-cortex-a53-843419 --disable-werror --enable-checking=release --build=aarch64-linux-gnu --host=aarch64-linux-gnu --target=aarch64-linux-gnu
Thread model: posix
gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04.1)
```
