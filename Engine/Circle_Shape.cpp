#include "Circle_Shape.h"
#include "../Engine/Graphics.h"

void Circle_Shape::Draw(Graphics* graphics, const glm::vec2& position)
{
	int r = graphics->WorldToPixels(radius);
	graphics->DrawFilledCircle(graphics->WorldToScreen(position), r, color);
}
