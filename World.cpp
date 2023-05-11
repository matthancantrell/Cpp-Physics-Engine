#include "World.h"
#include "Body.h"
#include "ForceGenerator.h"

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
	for (auto i : m_ForceGenerators) i->Apply(m_bodies);

	for (auto i : m_bodies) i->Step(dt);
}

void World::Draw(Graphics* m_graphics)
{
	// Call Draw() on all objects
	 
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

void World::AddForceGenerator(ForceGenerator* forceGenerator)
{
	m_ForceGenerators.push_back(forceGenerator);
}
