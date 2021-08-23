
#Using file( GLOB ) 
#CMake will not automatically rebuild if a new file is added

# If necessary, use the RELATIVE flag, otherwise each source file may be listed
# with full pathname. RELATIVE may makes it easier to extract an executable name
# automatically.
#file( GLOB SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp )

#for each src_file in SRC_FILES
#foreach( src_file ${SRC_FILES} )
    #string replace to remove .cpp
    #string( REPLACE ".cpp" "" src_name ${src_file} )
    #add_executable( ${src_name} ${src_file} )

    #set_target_properties()
    #target_link_libraries( ${src_name} yourLib)
#endforeach( src_file ${SRC_FILES} )

file (GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable( chess_square_rice_grains chess_square_rice_grains.cpp ${SRC_FILES} )
target_include_directories(chess_square_rice_grains PUBLIC ${CMAKE_SOURCE_DIR}/include )

add_executable( dist_between_cities dist_between_cities.cpp ${SRC_FILES} )
target_include_directories(dist_between_cities PUBLIC ${CMAKE_SOURCE_DIR}/include )

add_executable( cpu_guess_number cpu_guess_number.cpp ${SRC_FILES} )
target_include_directories(cpu_guess_number PUBLIC ${CMAKE_SOURCE_DIR}/include )

add_executable( rock_paper_scissors rock_paper_scissors.cpp ${SRC_FILES} )
target_include_directories(rock_paper_scissors PUBLIC ${CMAKE_SOURCE_DIR}/include )

