cmake_minimum_required (VERSION 3.8)

project (RedStarEditor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(BUILD_TESTING "BUILD_TESTING" OFF)
include(CTest)

add_subdirectory("src")
add_subdirectory("vendor/glfw")
add_subdirectory("vendor/glad")
add_subdirectory("vendor/imgui")

if(BUILD_TESTING)
    add_subdirectory("tests")
endif()