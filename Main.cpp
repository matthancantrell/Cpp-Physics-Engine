#include "Tests/ForceTest.h"
#include "Tests/JointTest.h"
#include "Tests/ParticleTest.h"

int main(int argc, char* argv[])
{
    //Test* test = new Test();
    Test* Ptest = new JointTest();
    Ptest->Initialize();
    //test->Initialize();

    while (!Ptest->IsQuit()) { Ptest->Run(); }
    delete Ptest;

    return 0;
}