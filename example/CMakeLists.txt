
add_executable(example
	"main.cpp"
)

target_include_directories(example PRIVATE
	${CMAKE_SOURCE_DIR}/GLFramework/include
	${OPENGL_INCLUDE_DIRS}
	glfw
	${CMAKE_SOURCE_DIR}/vendor/include
)

target_link_libraries(example
	GLFramework
)