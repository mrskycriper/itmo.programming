#pragma once

#include <iostream>

class Complex
{
public:
	Complex ();
	Complex (const double&, const double&);
	Complex operator * (const double&) const;
	Complex operator + (const Complex&) const;
	Complex operator * (const Complex&) const;
	explicit operator double () const;
	friend std::istream& operator >> (std::istream&, Complex&);
	friend std::ostream& operator << (std::ostream&, const Complex&);
private:
	double realPart;
	double imaginaryPart;
};

