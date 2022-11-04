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


## kalman_filter_1D.hpp and kalman_filter_1D.cpp
Defines the types. One is a struct that holds the filter's state and the second is the filter itself which holds the functions and a state object.

The state object is consisting of double values which are mentioned in the [Formulas](#formulas) section and nothing more.

The filter object holds the state object privately to prevent the users intervening unnecessarily or accidentally.

All the funtctions are non throwing including two constructors that take state objects either as an lvalue reference or an rvalue reference.

The filter has 3 important functions. `update`, `reset` and `get_state`.

`update` has two overloads. One of them takes a single double value as const which represents the latest measurement value given to the system. Outputs a double value which represents the current estimate after the latest measurement has been processed.

The current estimate is calculated according to formulas above.

The second overload is the same but for vector of double values which represents the measurements. It makes the same calculations as the single double value version of the function but for all the values in the input vector. The estimation after each measurement is pushed to a vector which then gets returned as the estimations. If the input vector is empty the returned vector will be empty.

`reset` has two overloads that either copies the given state object to filter's state object or moves it using [std::move](https://en.cppreference.com/w/cpp/utility/move). As the name suggest it is used to reset the state of the filter to desired values.

`get_state` is a simple getter function.


## kalman_filter_1D.h

Holds filter's type definiton and the function signatures.

## kalman_filter_1D.c

The function and variable names are direct translations of the formulas above.


## Notes
Please do not hesitate to reach me for the notes below. Any suggestion, solution or improvement advice will be welcome.

- I couldn't find a good way to overload the `update` function to take an rvalue reference of vector of double. I'm not even sure that it is a good idea. I don't know what happens if I can call the const lvalue reference overload with rvalue. Is it a good practice to do so or should I overload it with an rvalue reference and explicitly move it using [std::move](https://en.cppreference.com/w/cpp/utility/move) to a temporary local variable? What are the possible scenarios and what are the advantages/disadvantages of them?

- I couldn't bind the `update` function that takes a single value using [std::bind](https://en.cppreference.com/w/cpp/utility/functional/bind) so I ended up in code duplication in two overloads of the same function.

- Is there a way to get rid of the designated initializer warnings without using the c++20 standard when compiling?

- How to get rid of the `command line option ‘-std=c++17’ is valid for C++/ObjC++ but not for C` warning?

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
