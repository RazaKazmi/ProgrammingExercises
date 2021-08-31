
file (GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(temperature_conversion temperature_conversion.cpp ${SRC_FILES} )
target_include_directories(temperature_conversion PUBLIC ${CMAKE_SOURCE_DIR}/include )

add_executable(sum_of_values sum_of_values.cpp ${SRC_FILES} )
target_include_directories(sum_of_values PUBLIC ${CMAKE_SOURCE_DIR}/include )

add_executable(bulls_and_cows bulls_and_cows.cpp ${SRC_FILES} )
target_include_directories(bulls_and_cows PUBLIC ${CMAKE_SOURCE_DIR}/include )