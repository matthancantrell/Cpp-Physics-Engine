#include "DragForce.h"
#include "Body.h"

void DragForce::Apply(std::vector<class Body*> bodies)
{
	for (auto body : bodies)
	{
		if (!m_body->Intersects(body)) continue;
		float f = <compute the drag force using 0.5f * length sqr * m_drag>
		glm::vec2 force = glm::normalize(body->velocity);
		body->ApplyForce(<scale the force with - f>);
	}
}
