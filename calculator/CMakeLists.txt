add_executable(simpleCalculator calculator.cpp Token.cpp variable.cpp)
target_include_directories(simpleCalculator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(simpleCalculator PUBLIC common_utility)