cmake_minimum_required(VERSION 3.10)
project(Interview_CPP_Germany)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_FILES src/**/*.cpp)

foreach(file ${SRC_FILES})
    get_filename_component(name ${file} NAME_WE)
    add_executable(${name} ${file})
endforeach()