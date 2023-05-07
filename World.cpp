#include "World.h"

World::~World()
{
	// Delete All Objects
	// Clear Objects From List

	for (auto i : m_objects)
	{
		delete i;
	}

	m_objects.clear();
}

void World::Step(float dt)
{
	// Call Step on ALL objects

	for (auto i : m_objects)
	{
		i->Step(dt);
	}
}

void World::Draw(Graphics* m_graphics)
{
	// Call Draw() on all objects

	for (auto i : m_objects)
	{
		i->Draw(m_graphics);
	}
}

void World::AddPhysicsObject(PhysicsObject* po)
{
	// Push Back On The po onto objects list

	m_objects.push_back(po);
}

void World::RemovePhysicsObject(PhysicsObject* po)
{
	// remove po from objects list

	m_objects.remove(po);
}
