#include "ParticleTest.h"
#include "ForceTest.h"
#include "JointTest.h"

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