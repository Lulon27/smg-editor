set(FILES_CPP	"MyFile.cpp")

set(EDITOR_EXEC_NAME "SMGEditor")
set(EDITOR_LIB_NAME "lib_SMGEditor")

include_directories(SMGEditor PUBLIC	"${CMAKE_SOURCE_DIR}/include/"
										"${CMAKE_SOURCE_DIR}/vendor/spdlog/include/")

add_library(${EDITOR_LIB_NAME}	${FILES_CPP})

add_executable (${EDITOR_EXEC_NAME} "main.cpp")

target_link_libraries (${EDITOR_EXEC_NAME} ${EDITOR_LIB_NAME})