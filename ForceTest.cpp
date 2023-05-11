#include "ForceTest.h"
#include "GravGenerator.h"
#include "Body.h"
#include "Circle_Shape.h"

void ForceTest::Initialize()
{
	Test::Initialize();

	auto forceGenerator = new GravGenerator(3000);
	m_world->AddForceGenerator(forceGenerator);

}

void ForceTest::Update()
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

void ForceTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void ForceTest::Render()
{
	m_world->Draw(m_graphics);
	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });
}
