#pragma once

#include "interfaces.h"

class circle : public superClass
{
public:
	~circle() override = default;
	double radius = 0.0, xCentre = 0.0, yCentre = 0.0, Mass = 0.0;
	double square() const override;

	double perimeter() const override;

	void draw() const override;

	const char* classname() const override;

	unsigned int size() const override;

	void initFromDialog() override;

	double mass() const override;

	Vector2D position() const override;

	bool operator ==(const IPhysObject& ob) const override;

	bool operator <(const IPhysObject& ob) const override;
};
