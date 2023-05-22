#pragma once
#include <list>
#include <vector>
#include <glm/glm.hpp>

class World
{
public:

	~World();

	void Step(float dt);
	void Draw(class Graphics* m_graphics);

	void AddBody(class Body* po);
	void RemoveBody(class Body* po);

	void AddJoint(class Joint* joint);
	void RemoveJoint(class Joint* joint);

	void AddForceGenerator(class ForceGenerator* forceGenerator);

	static glm::vec2 gravity;

	private:
		std::list<class Body*> m_bodies;
		std::list<class Joint*> m_joints;
		std::vector<class ForceGenerator*> m_ForceGenerators;
};