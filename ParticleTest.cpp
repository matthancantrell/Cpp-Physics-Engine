#include "ParticleTest.h"
#include "Circle_Shape.h"
#include <iostream>

void ParticleTest::Initialize()
{
	Test::Initialize();
}

void ParticleTest::Run()
{
	UpdateEvents();

	m_input->Update();
	m_time->Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = randomUnitCircle() * randomf(100,200);
		auto po = new PhysicsObject(new Body(m_input->GetMousePosition(), velocity), new Circle_Shape(randomf(1,20), glm::vec4{randomf(1), randomf(1) , randomf(1) , randomf(1)}));
		m_world->AddPhysicsObject(po);
		
	}
	
	m_world->Step(m_time->TimeDelta());

	m_graphics->SetColor({ 0, 0, 0, 1 });
	m_graphics->Clear();

	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });

	m_world->Draw(m_graphics);

	m_graphics->Present();
}
