set(FILES_CPP	"MyFile.cpp"
				"RedStarApp.cpp"
				"Logging.cpp"
				"GLFWWindow.cpp" "GLFWOpenGLContext.cpp")

set(EDITOR_EXEC_NAME "RedStarEditor")
set(EDITOR_LIB_NAME "lib_RedStarEditor")

include_directories(${EDITOR_LIB_NAME} PUBLIC	"${CMAKE_SOURCE_DIR}/include/"
										"${CMAKE_SOURCE_DIR}/vendor/spdlog/include/"
										"${CMAKE_SOURCE_DIR}/vendor/glfw/include/"
										"${CMAKE_SOURCE_DIR}/vendor/glad/include/")

add_library(${EDITOR_LIB_NAME}	${FILES_CPP})
target_compile_definitions(${EDITOR_LIB_NAME} PUBLIC GLFW_INCLUDE_NONE)

add_executable (${EDITOR_EXEC_NAME} "main.cpp")

target_link_libraries (${EDITOR_EXEC_NAME} ${EDITOR_LIB_NAME})
target_link_libraries (${EDITOR_EXEC_NAME} glfw glad)