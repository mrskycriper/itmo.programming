#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class IGeoFig
{
public:
	virtual double square() const = 0;
	virtual double perimeter() const = 0;
};

class Vector2D
{
public:
	double x = 0.0, y = 0.0;
	void print()
	{
		cout << "X = " << x << " Y = " << y << endl;
	}
};

class IPhysObject
{
public:
	virtual double mass() const = 0;
	virtual Vector2D position() const = 0;
	virtual bool operator ==(const IPhysObject& ob) const = 0;
	virtual bool operator <(const IPhysObject& ob) const = 0;
};

class IPrintable
{
public:
	virtual void draw() const = 0;
};

class IDialogInitiable
{
public:
	virtual void initFromDialog() = 0;
};

class BaseObject
{
public:
	virtual const char* classname() const = 0;
	virtual unsigned int size() const = 0;
};

class superClass : public BaseObject, public IGeoFig, public IDialogInitiable, public IPrintable, public IPhysObject
{
public:
	virtual ~superClass() = default;
};
