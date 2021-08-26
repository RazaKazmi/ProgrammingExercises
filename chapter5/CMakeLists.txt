
file (GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(temperature_conversion temperature_conversion.cpp ${SRC_FILES} )
target_include_directories(temperature_conversion PUBLIC ${CMAKE_SOURCE_DIR}/include )