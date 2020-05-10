#pragma once

template <class Type>
void Swap(Type& first, Type& second)
{
	Type tmp = first;
	first = second;
	second = tmp;
}
