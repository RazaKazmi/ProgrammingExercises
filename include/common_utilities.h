//This header contrains some common helper functions for basic and common utilities

#pragma once

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <random>

namespace common_utility
{

	void Print(std::string s);
	//Keeps console window open
	void keep_window_open();
	void Error(const std::string &s);
	void Error(const std::string &s, const std::string &s2);

	template <class T>
	std::string to_string(const T& t);

}
