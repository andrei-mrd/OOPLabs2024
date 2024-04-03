#pragma once
class Number
{
	// add data members
	char * value;
	int base;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(const Number& d);
	Number(Number&& d);
	Number(int v);
	~Number();

	// add operators and copy/move constructor

	friend Number& operator += (Number& n1, Number& n2);
	friend Number& operator -= (Number& n1, Number& n2);
	friend Number& operator + (Number& n1, Number& n2);
	friend Number& operator - (Number& n1, Number& n2);

	bool operator > (Number& arg);
	bool operator < (Number& arg);
	bool operator >= (Number& arg);
	bool operator == (Number& arg);
	bool operator <= (Number& arg);
	void operator = (int value);
	void operator = (Number& arg);
	void operator = (const char* arg);
	Number& operator --(); //prefixat
	void operator --(int arg); //postfixat
	char operator [](int arg);

	void SwitchBase(int newBase);
	void Print();
	int GetDigitsCount(); // returns the number of digits for the current number
	int GetBase(); // returns the current base
};

