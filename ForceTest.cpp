#include "ForceTest.h"
#include "GravGenerator.h"

void ForceTest::Initialize()
{
	Test::Initialize();

	auto forceGenerator = new GravGenerator(3000);

}