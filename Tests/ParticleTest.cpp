#include "ParticleTest.h"
#include "../Engine/Body.h"
#include "../Engine/Circle_Shape.h"
#include <iostream>

void ParticleTest::Initialize()
{
	Test::Initialize();
}

void ParticleTest::Update()
{
	Test::Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = randomUnitCircle() * randomf(100, 200);
		auto body = new Body(new Circle_Shape(randomf(1, 20), glm::vec4{ randomf(), randomf() , randomf() , randomf() }), m_input->GetMousePosition(), velocity);
		//body->damping = 1;
		m_world->AddBody(body);
	}
}

void ParticleTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void ParticleTest::Render()
{
	m_world->Draw(m_graphics);
	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });
}
