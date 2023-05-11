#pragma once
#include <vector>
#include <list>

class ForceGenerator
{
public:
	ForceGenerator(class Body* body) : m_body{ body } {}
	virtual void Apply(std::list<class Body*> bodies) = 0;
	virtual void Draw(class Graphics* graphics);
protected:
	class Body* m_body { nullptr };
};