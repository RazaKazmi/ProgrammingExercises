//This header contrains some common helper functions for basic and common utilities

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <random>

namespace common_utility{
	
void print(std::string s)
{
	std::cout << s << '\n';
}

inline void keep_window_open()
{
	std::cin.clear();
	std::cout << "Please enter a character to exit\n";
	char ch;
	std::cin >> ch;
	return;
}

inline void error(const std::string& s)
{
	throw std::runtime_error(s);
}

inline void error(const std::string& s, const std::string& s2)
{
	error(s+s2);
}

template<class T> std::string to_string(const T& t)
{
	std::ostringstream os;
	os << t;
	return os.str();
}

}

