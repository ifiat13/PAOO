add_library(myproject_library 
    Mycode.cpp
)

# Include the source directory for header files
target_include_directories(myproject_library 
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../header
)
