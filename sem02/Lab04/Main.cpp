#include "Interfaces.h"
#include "Circle.h"
#include "Rectangle.h"

/*
Variant 20:
* A. Circle
* D. Rectangle
*/

int main()
{
	vector <superClass*> figures;

	int numberOfFigures = 0;
	cout << "Enter number of figures:" << endl;
	cin >> numberOfFigures;
	if (numberOfFigures <= 0)
	{
		cerr << "Enter at least one figure" << endl;
		return 1;
	}

	cout << "Supported types of figures:" << endl;
	cout << "1: Circle" << endl;
	cout << "2: Rectangle" << endl;

	for (int i = 0; i < numberOfFigures; ++i)
	{
		int type;
		do
		{
			cout << "Enter type:" << endl;
			cin >> type;
		} while (!(type == 1 || type == 2));
		if (type == 1)
		{
			figures.push_back(new circle);
		}
		else
		{
			figures.push_back(new rectangle);
		}
		figures.back()->initFromDialog();
	}

	cout << endl << "Figures list:" << endl;
	int count = 0;
	for (auto i : figures)
	{
		cout << ++count << "): " << i->classname() << endl;
		i->draw();
		cout << endl;
	}

	cout << endl << "Total Area:" << endl;
	double totalArea = 0.0;
	for (auto i : figures)
	{
		totalArea += i->square();
	}
	cout << totalArea << endl;

	cout << endl << "Total Perimeter:" << endl;
	double totalPerimeter = 0.0;
	for (auto i : figures)
	{
		totalPerimeter += i->perimeter();
	}
	cout << totalPerimeter << endl;

	cout << endl << "Total Size:" << endl;
	unsigned int totalSize = 0;
	for (auto i : figures)
	{
		totalSize += i->size();
	}
	cout << totalSize << endl;

	cout << endl << "Centre coordinates:" << endl;
	count = 0;
	for (auto i : figures)
	{
		cout << ++count << "): " << endl;
		i->position().print();
	}

	for (auto& i : figures)
	{
		delete i;
	}

	return 0;
}
