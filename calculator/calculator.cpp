/*
Simple calculator
This program is a learning exercise from Bjarne Stroustroups book. 
It was originally written and revised by Bjarne Stroustroup.
I only iterated on it with the exercises provided in his book.

The program implements a basic expression calculator.
The current grammar for the calculator is:

Statement:
	Expression
	Print
	Quit

Print:
	;
Quit:
	q
Expression:
	Term
	Expression + Term
	Expression - Term
Term:
	Secondary
	Term * Secondary
	Term / Secondary
	Term % Secondary
Secondary:
	Primary
	Secondary!
Primary:
	Number
	{ Expression }
	( Expression )
	-Primary
	+Primary
Number:
	floating point-literal
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <exception>

#include "Token.h"
#include "../include/common_utilities.h"

static const char number = '8';
static const char quit = 'q';
static const char print = ';';

Token_stream ts;

double expression(); // declaration so that primary can call experssion()
int factorial(int n);

const std::string prompt = "> ";
const std::string result = "= ";

double primary()
{
	Token t = ts.get();
	switch(t.kind)
	{
	case '{':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != '}')
			common_utility::Error("'}' expected");
		return d;
	}
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')')
			common_utility::Error("')' expected");
		return d;
	}
	case number:
		return t.value;
	case '-':
		return -primary();
	case '+':
		return primary();
	default:
		common_utility::Error("Primary expected");
	}
}

double secondary()
{
	double left = primary();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '!':
			left = factorial((int)left);
			t = ts.get();
			break;

		default:
			ts.putback(t);
			return left;
		}
	}

}

double term()
{
	double left = secondary();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '*':
			left *= secondary();
			t = ts.get();
			break;
		case '/':
		{
			double d = secondary();
			if (d == 0)
				common_utility::Error("Divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		/*
		case '%':
		{
			int i1 = common_utility::narrow_cast<int>(left);
			int i2 = common_utility::narrow_cast<int>(secondary());
			if (i2 == 0)
				common_utility::Error("%: divide by zero");
			left = i1 % i2;
			t = ts.get();
			break;
		}
		*/
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	Token t = ts.get();

	while(true)
	{
		switch(t.kind)
		{
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

int factorial(int n)
{
	if (n < 0)
		common_utility::Error("Negative factorial inputted");

	if (n > 1)
		return n * factorial(n - 1);
	else
		return 1;


}

void clean_up_mess()
{
	ts.ignore(print);
}

void calculate() // expression evaluation loop
{
	while (std::cin)
		try {
			std::cout << prompt; //print prompt
			Token t = ts.get();

			while (t.kind == print) //first discard all "prints"
				t = ts.get();
			if (t.kind == quit)
			{
				return;
			}
			ts.putback(t);
			std::cout << result << expression() << '\n';
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << '\n';
			clean_up_mess();
		}
	
}


int main()
{
	try
	{
		std::cout << "Welcome to our simple calculator." << std::endl;
		std::cout << "The operators available are '+', '-', '*', '/' '(', ')' " << std::endl;
		std::cout << "To print the result of the expression, use '='. " << std::endl;
		std::cout << "Press 'q' to exit the program" << std::endl;
		std::cout << "Please enter expressions using floating-point numbers" << std::endl;
		
		calculate();
		common_utility::KeepWindowOpen();
		return 0;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		common_utility::KeepWindowOpen();
		return 1;
	}
	catch (...)
	{
		std::cerr << "Unknown Exception!" << std::endl;
		common_utility::KeepWindowOpen();
		return 2;
	}

}
