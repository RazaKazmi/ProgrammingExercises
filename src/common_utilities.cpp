#include "../include/common_utilities.h"

namespace common_utility
{

	void print(std::string s)
	{
		std::cout << s << '\n';
	}

	void keep_window_open()
	{
		std::cin.clear();
		std::cout << "Please enter a character to exit\n";
		char ch;
		std::cin >> ch;
		return;
	}

	void error(const std::string &s)
	{
		throw std::runtime_error(s);
	}

	void error(const std::string &s, const std::string &s2)
	{
		error(s + s2);
	}

	template <class T>
	std::string to_string(const T& t)
	{
		std::ostringstream os;
		os << t;
		return os.str();
	}

}