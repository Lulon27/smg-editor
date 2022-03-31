set(FILES_CPP	
				"RedStarApp.cpp"
				"Logging.cpp"
				"GLFWWindow.cpp"
				"GLFWOpenGLContext.cpp"
				"LayerStack.cpp"
				"Input.cpp"
				"ImGuiLayer.cpp"

				"ImGui/ImGuiRenderer.cpp"
				"ImGui/ImGuiRenderer_GLFW_OpenGL3.cpp")

# To copy the imgui.ini file to the build directory when CMake
# is configured. This is so that the windows are docked correctly
# when a user builds the application for the first time.
# In the future, Dear ImGui's DockBuilder API should be used probably.
configure_file("${CMAKE_SOURCE_DIR}/imgui.ini" "imgui.ini" COPYONLY)

set(EDITOR_EXEC_NAME "RedStarEditor")
set(EDITOR_LIB_NAME "lib_RedStarEditor")

include_directories(${EDITOR_LIB_NAME} PUBLIC	"${CMAKE_SOURCE_DIR}/include/"
												"${CMAKE_SOURCE_DIR}/vendor/spdlog/include/"
												"${CMAKE_SOURCE_DIR}/vendor/glfw/include/"
												"${CMAKE_SOURCE_DIR}/vendor/glad/include/"
												"${CMAKE_SOURCE_DIR}/vendor/imgui/")

add_library(${EDITOR_LIB_NAME}	${FILES_CPP})
target_compile_definitions(${EDITOR_LIB_NAME} PUBLIC GLFW_INCLUDE_NONE)

add_executable (${EDITOR_EXEC_NAME} "main.cpp")

target_link_libraries (${EDITOR_EXEC_NAME} ${EDITOR_LIB_NAME})
target_link_libraries (${EDITOR_EXEC_NAME} glfw glad imgui)