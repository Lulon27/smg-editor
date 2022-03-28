set(FILES_CPP	"imgui.cpp"
				"imgui_draw.cpp"
				"imgui_tables.cpp"
				"imgui_widgets.cpp"

				"backends/imgui_impl_glfw.cpp"
				"backends/imgui_impl_opengl3.cpp")

include_directories(imgui PUBLIC "${CMAKE_SOURCE_DIR}/vendor/imgui")
add_library(imgui ${FILES_CPP})
target_link_libraries (imgui glfw)