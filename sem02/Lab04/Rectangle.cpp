#include "Rectangle.h"

double rectangle::square() const
{
	return sqrt(pow(firstCorner.x - secondCorner.x, 2) + pow(firstCorner.y - secondCorner.y, 2)) *
		   sqrt(pow(secondCorner.x - thirdCorner.x, 2) + pow(secondCorner.y - thirdCorner.y, 2));
}

double rectangle::perimeter() const
{
	return 2 * sqrt(pow(firstCorner.x - secondCorner.x, 2) + pow(firstCorner.y - secondCorner.y, 2)) +
		   2 * sqrt(pow(secondCorner.x - thirdCorner.x, 2) + pow(secondCorner.y - thirdCorner.y, 2));
}

void rectangle::draw() const
{
	cout << "First corner coordinates: X = " << firstCorner.x << " Y = " << firstCorner.y << endl;
	cout << "Second corner coordinates: X = " << secondCorner.x << " Y = " << secondCorner.y << endl;
	cout << "Third corner coordinates: X = " << thirdCorner.x << " Y = " << thirdCorner.y << endl;
	cout << "Mass: M = " << Mass << endl;
}

const char* rectangle::classname() const
{
	return "Rectangle";
}

unsigned int rectangle::size() const
{
	return sizeof(*this);
}

void rectangle::initFromDialog()
{
	cout << "Enter X and Y coordinates of the first corner by spaces:" << endl;
	cin >> firstCorner.x >> firstCorner.y;
	cout << "Enter X and Y coordinates of the second corner by spaces:" << endl;
	cin >> secondCorner.x >> secondCorner.y;
	cout << "Enter X and Y coordinates of the third corner by spaces:" << endl;
	cin >> thirdCorner.x >> thirdCorner.y;
	cout << "Enter Mass:" << endl;
	cin >> Mass;
}

double rectangle::mass() const
{
	return Mass;
}

Vector2D rectangle::position() const
{
	Vector2D result;
	result.x = (firstCorner.x + thirdCorner.x) / 2.0;
	result.y = (firstCorner.y + thirdCorner.y) / 2.0;
	return result;
}

bool rectangle::operator ==(const IPhysObject& ob) const
{
	return mass() == ob.mass();
}

bool rectangle::operator <(const IPhysObject& ob) const
{
	return mass() < ob.mass();
}
