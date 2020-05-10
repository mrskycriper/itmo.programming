#include <cmath>
#include "Complex.hpp"

Complex::Complex ()
{
	this->realPart = 0.0;
	this->imaginaryPart = 0.0;
}

Complex::Complex (const double& inReal, const double& inImaginary)
{
	this->realPart = inReal;
	this->imaginaryPart = inImaginary;
}

Complex Complex::operator * (const double& number) const
{
	return Complex (number * this->realPart, number * this->imaginaryPart);
}

Complex Complex::operator + (const Complex& number) const
{
	return Complex (this->realPart + number.realPart, this->imaginaryPart + number.imaginaryPart);
}

Complex Complex::operator * (const Complex& number) const
{
	return Complex (this->realPart * number.realPart - this->imaginaryPart * number.imaginaryPart,
					this->realPart * number.realPart + this->imaginaryPart * number.imaginaryPart);
}

Complex::operator double () const
{
	return sqrt (pow (this->realPart, 2) + pow (this->imaginaryPart, 2));
}

std::istream& operator >> (std::istream& input, Complex& number)
{
	char i;
	input >> number.realPart >> number.imaginaryPart >> i;
	return input;
}

std::ostream& operator << (std::ostream& output, const Complex& number)
{
	output << number.realPart;
	if (number.imaginaryPart > 0.0)
	{
		output << '+' << number.imaginaryPart << 'i';
	}
	else if (number.imaginaryPart < 0.0)
	{
		output << number.imaginaryPart << 'i';
	}
	return output;
}

