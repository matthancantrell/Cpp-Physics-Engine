#include "ForceTest.h"
#include "../Physics/GravGenerator.h"
#include "../Engine/Body.h"
#include "../Engine/Circle_Shape.h"
#include "../Physics/AreaForce.h"
#include "../Physics/PointForce.h"
#include "../Physics/DragForce.h"

void ForceTest::Initialize()
{
	Test::Initialize();

#if defined(POINT_FORCE)
	auto body = new Body(new Circle_Shape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::STATIC);
	ForceGenerator* forceGenerator = new PointForce(body, 2000);
	m_world->AddForceGenerator(forceGenerator);
#elif defined(AREA_FORCE)
	auto body = new Body(new Circle_Shape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::STATIC);
	ForceGenerator* forceGenerator = new AreaForce(body, 2000, -90);
	m_world->AddForceGenerator(forceGenerator);
#elif defined(DRAG_FORCE)
	auto body = new Body(new Circle_Shape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::STATIC);
	ForceGenerator* forceGenerator = new DragForce(body, 0.5f);
	m_world->AddForceGenerator(forceGenerator);
#endif

	//auto forceGenerator = new GravGenerator(400);
	//m_world->AddForceGenerator(forceGenerator);

}

void ForceTest::Update()
{
	Test::Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = randomUnitCircle() * randomf(100, 200);
		auto body = new Body(new Circle_Shape(randomf(1, 20), glm::vec4{ randomf(), randomf() , randomf() , randomf() }), m_input->GetMousePosition(), velocity);
		body->damping = 7.0f;
		body->gravityScale = 30;
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
