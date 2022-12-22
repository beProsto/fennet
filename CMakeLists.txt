# Minimum version of cmake this will work on
cmake_minimum_required(VERSION 3.0.0)

# Project's name and version
set(project_name fennet)
project(${project_name} VERSION 1.0.0)

# Add ./include/ as an include directory
include_directories(include)

# Recursively search the include and src directories
file(GLOB_RECURSE srcs
	"include/*.hpp"
	"include/*.h"
	"src/*.cpp"
	"src/*.c"
)

# Compile the sources into a library, choosing the library type
#  and setting the build type macro accordingly
if(LIBTYPE STREQUAL "STATIC")
	add_library(${project_name} STATIC ${srcs})
	target_compile_definitions(${project_name} PRIVATE LIB_BUILD_STATIC)
else()
	add_library(${project_name} SHARED ${srcs})
	target_compile_definitions(${project_name} PRIVATE LIB_BUILD_SHARED)
endif()


# Link the library we just compiled and compile the examples with it
link_libraries(${project_name})
add_executable(HelloServer examples/HelloServer/main.c)