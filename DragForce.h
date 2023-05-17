#pragma once
#include "ForceGenerator.h"
#include <vector>

class DragForce : public ForceGenerator
{
public:
	DragForce(class Body* body, float drag) :
		ForceGenerator { body },
		m_drag { drag }
	{}

	void Apply(std::vector<class Body*> bodies) override;

protected:
	float m_drag { 0 };
};