#include "Body.h"
#include "World.h"
#include "Integrator.h";

void Body::ApplyForce(const glm::vec2& force)
{
	this->force += force;
}

void Body::Step(float dt)
{
	Integrator::ExplicitEuler(*this, dt);
	ClearForce();
	
	velocity *= 1.0f / (1.0f + (3.0f * dt));
}

void Body::Draw(Graphics* graphics)
{
	shape->Draw(graphics, position);
}
