#pragma once
#include "Test.h"

#define POINT_FORCE
//#define AREA_FORCE
//#define DRAG_FORCE

class ForceTest : public Test
{
public:
	void Initialize();

	void Update() override;
	virtual void FixedUpdate() override;
	virtual void Render() override;
};