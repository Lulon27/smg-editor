
set(EDITOR_LIB_NAME "lib_RedStarEditor")
set(GTEST_PATH "vendor/googletest")

include(GoogleTest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory("${CMAKE_SOURCE_DIR}/${GTEST_PATH}" "${GTEST_PATH}")

mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

macro(redstar_add_test TESTNAME)

    include_directories(${TESTNAME} PUBLIC "${CMAKE_SOURCE_DIR}/include/")
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} gtest gmock gtest_main ${EDITOR_LIB_NAME})
    gtest_discover_tests(${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

redstar_add_test(ExampleTest test_file.cpp)
