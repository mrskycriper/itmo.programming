#include <iostream>
#include "Complex.hpp"
#include "Stack.hpp"

/*
 * Variant 19
 * Complex number (a+bi)
 * Stack
 */

int main ()
{
	std::cout << "#Complex numbers#" << std::endl;
	std::cout << "Enter 2 complex numbers (a+bi) and 1 number with floating point:" << std::endl;
	Complex testComplex1, testComplex2;
	double testDouble;
	std::cin >> testComplex1 >> testComplex2 >> testDouble;

	std::cout << "Input: " << testComplex1 << ' ' << testComplex2 << ' ' << testDouble << std::endl;

	std::cout << "-First complex * floating point-" << std::endl;
	std::cout << "Explicit: " << testComplex1 * testDouble << std::endl;
	std::cout << "Implicit: " << testComplex1.operator * (testDouble) << std::endl;

	std::cout << "-First complex + second complex-" << std::endl;
	std::cout << "Explicit: " << testComplex1 + testComplex2 << std::endl;
	std::cout << "Implicit: " << testComplex1.operator + (testComplex2) << std::endl;

	std::cout << "-First complex * second complex-" << std::endl;
	std::cout << "Explicit: " << testComplex1 * testComplex2 << std::endl;
	std::cout << "Implicit: " << testComplex1.operator * (testComplex2) << std::endl;

	std::cout << "-First complex length-" << std::endl;
	std::cout << "Explicit: " << (double) testComplex1 << std::endl;
	std::cout << "Implicit: " << testComplex1.operator double () << std::endl << std::endl;

	std::cout << "#Integer stack of 100 elements#" << std::endl;
	Stack intStack;
	for (int i = 0; i < 100; ++i)
	{
		intStack << i;
	}

	std::cout << "Print: ";
	intStack.Print ();
	std::cout << std::endl;

	std::cout << "Pop: ";
	for (int i = 0; i < 100; ++i)
	{
		std::cout << (intStack >> 0) << ' ';
	}
	std::cout << std::endl;
	return 0;
}
