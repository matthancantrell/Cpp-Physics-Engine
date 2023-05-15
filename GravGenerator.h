#pragma once
#include "ForceGenerator.h"

class GravGenerator : public ForceGenerator
{
public:
	GravGenerator(float strength) : m_strength{ strength } {}

	virtual void Apply(std::vector<class Body*> bodies) override;
private:
	float m_strength{ 0 };
};