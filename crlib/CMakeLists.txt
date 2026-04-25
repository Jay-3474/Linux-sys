cmake_minimum_required(VERSION 3.10)
project(main)

# Create a static library named 'mylib' from source files
add_library(oplib STATIC mul_fun.cpp sum_fun.cpp)

# Define the main executable
add_executable(main main.cpp)

# Link the static library to the executable
target_link_libraries(main PRIVATE oplib)

###########

# Create the shared library target
# On Linux this produces libmy_lib.so, on Windows my_lib.dll
add_library(shoplib SHARED mul_fun.cpp sum_fun.cpp)

add_executable(my_app main.cpp)

# Link the library to your executable
target_link_libraries(my_app PRIVATE shoplib)
