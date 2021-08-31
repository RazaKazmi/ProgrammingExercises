//This header contrains some common helper functions for basic and common utilities

#pragma once

#include <iostream>
#include <sstream>
#include <stdexcept>

namespace common_utility
{

	void Print(std::string s);
	void KeepWindowOpen(); //Keeps console window open
	
	//Error handling
	void Error(const std::string &s);
	void Error(const std::string &s, const std::string &s2);

	//Conversions
	template <class T>
	std::string ToString(const T& t);
	
	//returns the number of digits an integer has
	int NumberOfDigits(int n);
}
