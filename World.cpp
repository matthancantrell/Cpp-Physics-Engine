#include "World.h"
#include "Body.h"
#include "ForceGenerator.h"
#include "Joint.h"

glm::vec2 World::gravity = { 0, -9.8 };

World::~World()
{
	// Delete All Objects
	// Clear Objects From List

	for (auto i : m_bodies) { delete i; }

	m_bodies.clear();
}

void World::Step(float dt)
{
	// Call Step on ALL objects
	if (m_bodies.size() > 0 && m_ForceGenerators.size() > 0)
	{
		std::vector<Body*> bodies(m_bodies.begin(), m_bodies.end());

		for (auto i : m_ForceGenerators) i->Apply(bodies);
	}
	for (auto i : m_joints) i->Step(dt);
	for (auto i : m_bodies) i->Step(dt);
}

void World::Draw(Graphics* m_graphics)
{
	// Call Draw() on all objects
	for (auto i : m_joints) i->Draw(m_graphics);
	for (auto i : m_ForceGenerators) { i->Draw(m_graphics); }
	for (auto i : m_bodies) { i->Draw(m_graphics); }
}

void World::AddBody(Body* po)
{
	// Push Back On The po onto objects list

	m_bodies.push_back(po);
}

void World::RemoveBody(Body* po)
{
	// remove po from objects list

	m_bodies.remove(po);
}

void World::AddJoint(class Joint* joint) { m_joints.push_back(joint); }
void World::RemoveJoint(class Joint* joint) { m_joints.remove(joint); }

void World::AddForceGenerator(ForceGenerator* forceGenerator)
{
	m_ForceGenerators.push_back(forceGenerator);
}
