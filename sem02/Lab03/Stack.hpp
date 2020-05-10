#pragma once

class Stack
{
public:
	Stack ();
	~Stack ();
	int operator << (const int&);
	int operator >> (int);

	void Print ();
private:
	int* stack;
	int top;
	const int maxSize = 100;
};

