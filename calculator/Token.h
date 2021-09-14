#pragma once

class Token
{
public:
	char kind;
	double value;
	Token(char ch)
		:kind(ch),value(0){}
	Token(char ch, double val)
		:kind(ch),value(val){}
};

class Token_stream
{
public:
	Token_stream(); // constructor
	Token get(); // get a Token
	void putback(Token t); // put a Token back
	void ignore(char c); // discard characters up to and including c
private:
	bool full;
	Token buffer; // our token buffer. Only enough space for one token.

};
