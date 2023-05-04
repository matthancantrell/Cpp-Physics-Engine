#include "Circle_Shape.h"
#include "Graphics.h"

void Circle_Shape::Draw(Graphics* graphics, const glm::vec2& position)
{
	graphics->DrawFilledCircle(position, radius, color);
}
