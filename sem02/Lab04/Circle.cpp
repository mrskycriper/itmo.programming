#include "Circle.h"

double circle::perimeter() const
{
	return 2.0 * 3.14 * radius;
}

double circle::square() const
{
	return 3.14 * pow(radius, 2);
}

void circle::draw() const
{
	cout << "Centre coordinates: X = " << xCentre << " Y =" << yCentre << endl;
	cout << "Radius: R = " << radius << endl;
	cout << "Mass: M = " << Mass << endl;
}

const char* circle::classname() const
{
	return "Circle";
}

unsigned int circle::size() const
{
	return sizeof(*this);
}

void circle::initFromDialog()
{
	cout << "Enter X and Y coordinates by spaces:" << endl;
	cin >> xCentre >> yCentre;
	cout << "Enter Radius:" << endl;
	cin >> radius;
	cout << "Enter Mass:" << endl;
	cin >> Mass;
}

double circle::mass() const
{
	return Mass;
}

Vector2D circle::position() const
{
	Vector2D result;
	result.x = xCentre;
	result.y = yCentre;
	return result;
}

bool circle::operator ==(const IPhysObject& ob) const
{
	return mass() == ob.mass();
}

bool circle::operator <(const IPhysObject& ob) const
{
	return mass() < ob.mass();
}
