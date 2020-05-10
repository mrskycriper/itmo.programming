#pragma once

#include "Interfaces.h"

class rectangle : public superClass
{
public:
	~rectangle() override = default;
	Vector2D firstCorner, secondCorner, thirdCorner;
	double Mass = 0.0;

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
