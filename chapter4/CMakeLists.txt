
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

add_executable( chess_square_rice_grains chess_square_rice_grains.cpp)
target_link_libraries( chess_square_rice_grains PUBLIC common_utility)

add_executable( dist_between_cities dist_between_cities.cpp )
target_link_libraries( dist_between_cities PUBLIC common_utility)

add_executable( cpu_guess_number cpu_guess_number.cpp )
target_link_libraries( cpu_guess_number PUBLIC common_utility)

add_executable( rock_paper_scissors rock_paper_scissors.cpp )
target_link_libraries( rock_paper_scissors PUBLIC common_utility)

