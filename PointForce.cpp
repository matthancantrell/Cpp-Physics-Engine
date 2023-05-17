#include "PointForce.h"
#include "Body.h"

void PointForce::Apply(std::vector<class Body*> bodies)
{
	for (auto body : bodies)
	{
		if (!m_body->Intersects(body)) continue;
		glm::vec2 direction = m_body->position - body->position;
		glm::vec2 force = glm::normalize(direction);
		body->ApplyForce(force * m_forceMagnitude);
	}
}
