#include <iostream>
#include <vector>
#include "Algorithms.hpp"
#include "Complex.hpp"

/*
 * Variant 19:
 * all_of
 * is_sorted
 * find_backward
 */


int main ()
{
	std::cout << "--all_of--" << std::endl;
	std::vector <Complex> Numbers;
	Complex buffer;
	std::cout << "Enter 5 complex numbers in \"a+bi\" format:" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		std::cin >> buffer;
		Numbers.push_back (buffer);
	}
	std::cout << "Enter single complex number in \"a+bi\" format to check if all other are less than it:" << std::endl;
	std::cin >> buffer;
	std::cout << "Verdict: ";
	if (Algorithms::all_of (Numbers.begin (), Numbers.end (), [buffer] (Complex& in) -> bool
	{return in < buffer;}))
	{
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl << std::endl;
	}


	std::cout << "--is_sorted--" << std::endl;
	std::cout << "Is this array sorted in non-decrease order?" << std::endl;
	if (Algorithms::is_sorted (Numbers.begin (), Numbers.end (), Greater <Complex> ()))
	{
		std::cout << "yes" << std::endl;
	}
	else
	{
		std::cout << "no" << std::endl;
	}
	std::cout << std::endl;


	std::cout << "--find_backward--" << std::endl;
	std::cout << "Enter single complex number for find:" << std::endl;
	std::cin >> buffer;
	std::vector <Complex>::iterator result;
	result = Algorithms::find_backwards (Numbers.begin (), Numbers.end (), buffer);
	std::cout << "Verdict: ";
	if (result == Numbers.begin ())
	{
		if (*result == buffer)
		{
			std::cout << *result << " found" << std::endl;
		}
		else
		{
			std::cout << "not found" << std::endl;
		}
	}
	else
	{
		std::cout << *result << " found" << std::endl;
	}
	return 0;
}