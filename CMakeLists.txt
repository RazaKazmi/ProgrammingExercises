cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set project name
project(ProgrammingExercises)

#fetch googletest
include(FetchContent)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG        d4e3b8cedf4f57922efa586cb3c796c8fee2d3f3 #Release 1.11.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#googletest
enable_testing()

include(GoogleTest)

#libraries
file (GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_library(common_utility STATIC ${SRC_FILES})
target_include_directories(common_utility PUBLIC ${CMAKE_SOURCE_DIR}/include)

#subdirectories
add_subdirectory(src)
add_subdirectory(chapter4)
add_subdirectory(chapter5)


