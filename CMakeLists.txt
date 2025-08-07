cmake_minimum_required(VERSION 3.10)
project(FG7)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Function to add an executable from a single file
function(add_single_file_executable FILE_PATH)
    get_filename_component(FILE_NAME ${FILE_PATH} NAME_WE)
    add_executable(${FILE_NAME} ${FILE_PATH})
endfunction()

# Example usage (uncomment and modify as needed):
add_single_file_executable(arrays/src/basics.cpp)
# add_single_file_executable(src/another_file.cpp)

# Or, automatically add all .cpp files in a directory:
# file(GLOB CPP_FILES "src/*.cpp")
# foreach(CPP_FILE ${CPP_FILES})
#     add_single_file_executable(${CPP_FILE})
# endforeach()