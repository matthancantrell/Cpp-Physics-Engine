#include "Tests/ParticleTest.h"
#include "Tests/ForceTest.h"
#include "Tests/JointTest.h"
#include "Tests/CollisionTest.h"

int main(int argc, char* argv[]) 
{
	Test* pTest = new CollisionTest();
	pTest->Initialize();
	while (!pTest->IsQuit()) { pTest->Run(); }
	delete pTest;

	return 0;
}
