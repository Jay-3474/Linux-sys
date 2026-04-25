#!/bin/bash

######################################################## static #########################################
# creates object files
gcc -c main.c mul.c sum.c 

ls

# ar command to generate archive/satic library with .a extenstion (r-> replace / c-> create / s-> index)
ar rcs libop.a main.o mul.o sum.o

ls

# nm command to display list of symbols and referance addresses
nm libop.a 

# ar with options (t-> display files / d-> delete from archive / r-> add to archive)
ar t libop.a 
ar d libop.a main.o
ar t libop.a

nm libop.a 

ls
# command to link the library and generate executable
gcc main.c -L. -lop -o main
ls
./main
ls

if [ -d "build" ]; then
  rm -rf "build"
fi

# Create a build directory
mkdir build && cd build
#Generate build files
cmake ..
#Compile the project
cmake --build .
nm liboplib.a
ar t liboplib.a
./main 

# cleanup
cd ..
rm main mul.o sum.o libop.a main.o
rm -rf ./build

############################################ Dynamic ########################################

# create object files
gcc -c mul.c sum.c

# generate the shared library
cc -shared -o libop.so mul.o sum.o

ls

# check the dynamic library creation
ldd libop.so

# compile and link the dipendency 
gcc main.c -L. -lop -o myprogram
ls

# generates the error for shared library
./myprogram 

# exports the library path
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
./myprogram

if [ -d "build" ]; then
  rm -rf "build"
fi

# Create a build directory
mkdir build && cd build
#Generate build files
cmake ..
#Compile the project
cmake --build .
ldd libshoplib.so
./my_app


# cleanup
cd ..
rm myprogram mul.o sum.o libop.so
rm -rf ./build

############################################### dl_functionality #################

# create shared library
gcc -fPIC -shared -o libcalc.so sum.c mul.c

#compile with main program and link with the -ldl library to use the dl functions
gcc dl_function.c -o dl_function -ldl

./dl_function 
ls

#cleanup
rm dl_function libcalc.so



