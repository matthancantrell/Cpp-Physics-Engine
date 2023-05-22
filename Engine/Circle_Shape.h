#pragma once
#include "Shape.h"

class Circle_Shape : public Shape
{
public:

	Circle_Shape(float radius, const glm::vec4& color) :
		radius{ radius },
		Shape{ color }
	{}

	virtual void Draw(Graphics* graphics, const glm::vec2& position) override;

public:

	float radius{ 1 };
};