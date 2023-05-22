#include "Joint.h"
#include "../Engine/Body.h"
#include "../Engine/Graphics.h"

Joint::Joint(Body* bodyA, Body* bodyB, float stiff, float restLength) : m_bodyA{ bodyA }, m_bodyB{ bodyB }, m_kStiffness{ stiff }, m_restLength{ restLength }
{
	if (m_restLength == 0) {
		m_restLength = glm::distance(bodyA->position, bodyB->position);
	}
}

void Joint::Step(float dt)
{
	glm::vec2 direction = m_bodyA->position - m_bodyB->position;
	if (direction == glm::vec2{ 0,0 }) return;

	float length = glm::length(direction);

	float x = length - m_restLength;
	//if (x < 0) return;
	float f = -m_kStiffness * x;

	glm::vec2 ndir = glm::normalize(direction);

	m_bodyA->ApplyForce(ndir * f);
	m_bodyB->ApplyForce(-ndir * f);
}

void Joint::Draw(Graphics* graphics)
{
	graphics->DrawLine(graphics->WorldToScreen(m_bodyA->position), graphics->WorldToScreen(m_bodyB->position), { 1, 1, 1, 1 });
}