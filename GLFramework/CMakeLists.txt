# CMakeList.txt : CMake project for GLFramework, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_library (GLFramework "alibi.cpp" "window.cpp")

file(GLOB vendor_SRC
    "${CMAKE_SOURCE_DIR}/vendor/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/vendor/src/*.c"
)

target_sources(GLFramework PRIVATE
	${vendor_SRC}
)

target_include_directories(GLFramework PRIVATE
	include
	${OPENGL_INCLUDE_DIRS}
	glfw
	${CMAKE_SOURCE_DIR}/vendor/include
)

target_link_libraries(GLFramework
	${OPENGL_LIBRARIES}
	glfw
)


# TODO: Add tests and install targets if needed.
