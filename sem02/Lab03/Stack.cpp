#include <iostream>
#include "Stack.hpp"

Stack::Stack () : top (0)
{
	stack = new int[maxSize];
}

Stack::~Stack ()
{
	delete[] stack;
}

int Stack::operator << (const int& number)
{
	if (top < maxSize)
	{
		stack[top] = number;
		++top;
		return 0;
	}
	return -1;
}

int Stack::operator >> (int)
{
	if (top > 0)
	{
		--top;
		return stack[top];
	}
	return -1;
}

void Stack::Print ()
{
	for (int i = 0; i < top; ++i)
	{
		std::cout << stack[i] << ' ';
	}
	std::cout << std::endl;
}
