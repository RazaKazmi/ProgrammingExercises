#include "../include/common_utilities.h"

namespace common_utility
{

	void Print(std::string s)
	{
		std::cout << s << '\n';
	}

	void KeepWindowOpen()
	{
		std::cin.clear();
		std::cout << "Please enter a character to exit\n";
		char ch;
		std::cin >> ch;
		return;
	}

	void Error(const std::string &s)
	{
		throw std::runtime_error(s);
	}

	void Error(const std::string &s, const std::string &s2)
	{
		Error(s + s2);
	}

	template <class T>
	std::string ToString(const T& t)
	{
		std::ostringstream os;
		os << t;
		return os.str();
	}

	int NumberOfDigits(int n)
	{
		unsigned int number_of_digits = 0;
		unsigned int base = 10;
		do {
			number_of_digits++;
			n /= base;
		} while(n);
		return number_of_digits;
	}

	bool DistinctDigits(int n)
	{
		return false;
	}

}