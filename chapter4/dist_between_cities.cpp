//This program takes in distance between cities, without regard for a unit
//Assumes unit is the same for all distance values
//It then outputs some information about the distances, the smallest and largest distance between cities
//and the mean distance
//ch4_exercise_3

#include <iostream>
#include <vector>
#include "../include/common_utilities.h"

int main(){
	std::cout << "Keep entering distance values. To stop and calculate results, use ctrl+Z" << std::endl;
	double input_value = 0;
	std::vector<double> dist_between_cities;
	while(std::cin >> input_value){
		dist_between_cities.push_back(input_value);
		}
	double total_distance = 0;
	double smallest_distance = dist_between_cities[0];
	double largest_distance = dist_between_cities[0];
	for(int i = 0; i < dist_between_cities.size();i++){
		total_distance += dist_between_cities[i];
		smallest_distance = smallest_distance > dist_between_cities[i] 
		? dist_between_cities[i] : smallest_distance;
		largest_distance = largest_distance < dist_between_cities[i] 
		? dist_between_cities[i] : largest_distance;
		}
		std::cout << "Total distance between cities: " << total_distance
		<< '\n';
		std::cout << "Smallest distance between cities: " << smallest_distance
		<< '\n';
		std::cout << "Largest distance between cities: " << largest_distance
		<< '\n';
		std::cout << "The mean distance between cities: " <<
		total_distance / dist_between_cities.size();

	std::cout << std::endl;
	common_utility::KeepWindowOpen();
}
