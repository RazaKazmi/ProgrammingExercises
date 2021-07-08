/* This program is based off the chess board grain of rice story variation.
There is 1 grain of rice for the first square of the chessboard, and every
next square after it, the rice doubles in value from what is was from the previous square.
The user enters the amount of rice grains they want to view, and the program will output how many
squares it takes to get that much rice.

ch4_exercise_8
*/
#include <iostream>
#include "../include/common_utilities.h"

int main(){
	std::cout << "Enter the amount of rice grains: ";
	double rice_grains_input = 0;
	double rice_grains = 1;
	int square = 1;
	double total_rice = 1;
	std::cin >> rice_grains_input;
	std::cout << "Rice grains: " << rice_grains << " square: " << square << '\n';
	while(rice_grains < rice_grains_input){
		rice_grains *= 2;
		total_rice += rice_grains;
		square++;
		std::cout << "Rice grains current: " << rice_grains << " square: " 
		<< square << " Total Rice: " << total_rice << '\n';
	}

	common_utility::keep_window_open();
}
