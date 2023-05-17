#include "Body.h"
#include "World.h"
#include "Shape.h"
#include "Integrator.h"
#include "Circle_Shape.h"

void Body::ApplyForce(const glm::vec2& force)
{
	this->force += force;
}

void Body::Step(float dt)
{
	Integrator::ExplicitEuler(*this, dt);
	ClearForce();
	
	velocity *= 1.0f / (1.0f + (damping * dt));
}

void Body::Draw(Graphics* graphics)
{
	shape->Draw(graphics, position);
}

bool Body::Intersects(Body* body)
{
	glm::vec2 direction = this->position - body->position;
	float distance = glm::length(direction);
	float radius = dynamic_cast<Circle_Shape*>(shape)->radius + dynamic_cast<Circle_Shape*>(body->shape)->radius;
	return distance <= radius;
}
