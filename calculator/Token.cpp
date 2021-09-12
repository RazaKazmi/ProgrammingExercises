#include <iostream>

#include "../include/common_utilities.h"
#include "Token.h"

Token_stream::Token_stream()
	:full(false), buffer(0)
{
}

Token Token_stream::get() 
	//read characters from cin and compose a Token
{
	if(full) // check if we already have a token ready
	{
		full = false; // remove Token from buffer
		return buffer;
	}
	char ch;
	std::cin >> ch; // Note: >> skips whitespace (space, newline, tab,etc)

	switch(ch)
	{
	case quit:	// for "print"
	case print:	// for "quit"
	case '{': case '}':
	case '(': case ')': 
	case '+': 
	case '-': 
	case '*': 
	case '/':
	case '!': 
	case '%':
		return Token{ ch }; // let each character represent itself
	case '.':				// a floating point literal can start with a dot
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':		//numeric literal
	{
		std::cin.putback(ch); // put digit back into the input stream
		double val;
		std::cin >> val; //read a floating point number
		return Token{number,val};
	}
	default:
		common_utility::Error("Bad token");
	}
}

void Token_stream::putback(Token t)
{
	if (full)
		common_utility::Error("putback() into a full buffer");
	buffer = t; // copy t to buffer
	full = true; // buffer is now full
}

void Token_stream::ignore(char c)
	// c represents a token
{
	//first look in buffer
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}
	full = false;

	//now search input
	char ch = 0;
	while (std::cin >> ch)
		if (ch == c)
			return;
}
