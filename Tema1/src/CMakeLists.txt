# CMakeLists.txt din src
cmake_minimum_required(VERSION 3.0)

# Define the library target
add_library(myproject_library 
    Mycode.cpp
    Mycode.hpp
)

# Adaugă sursa executabilului
add_executable(myproject main.cpp)

# Link the library target to the executable
target_link_libraries(myproject PRIVATE myproject_library)

# Include the source directory for header files
target_include_directories(myproject 
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
