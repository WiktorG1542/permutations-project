# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.0)

# Set the project name
project(permutations)

# Add the source files for the permutations executable
add_executable(permutations 
    display_vector.cpp
    factorial.cpp
    how_many_cycles.cpp
    main.cpp
    number_of_inversions.cpp
)

# Add the source file for the checkinput1 executable
add_executable(checkinput1
    checkinput1.cpp
)

# Add the source file for the checkinput2 executable
add_executable(checkinput2
    checkinput2.cpp
)
