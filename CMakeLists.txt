cmake_minimum_required (VERSION 3.8)

project (SMGEditor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(CTest)

add_subdirectory("src")

if(BUILD_TESTING)
    add_subdirectory("tests")
endif()