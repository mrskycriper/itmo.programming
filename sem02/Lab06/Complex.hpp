#pragma once
#include <iostream>

class Complex
{
public:
	Complex ();
	Complex(Complex&);
	Complex(const Complex& object);
	Complex (const double&, const double&);

	Complex operator * (const double&) const;
	Complex operator + (const Complex&) const;
	Complex operator * (const Complex&) const;

	friend std::istream& operator >> (std::istream&, Complex&);
	friend std::ostream& operator << (std::ostream&, const Complex&);

	bool operator < (const Complex&) const;
	bool operator > (const Complex&) const;
	bool operator == (const Complex&) const;
	bool operator <= (const Complex&) const;
	bool operator >= (const Complex&) const;
	bool operator != (const Complex&) const;

	double module() const;
private:
	double realPart;
	double imaginaryPart;
};

