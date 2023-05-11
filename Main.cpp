#include "ParticleTest.h"
#include "ForceTest.h"

int main(int argc, char* argv[])
{
    //Test* test = new Test();
    Test* Ptest = new ForceTest();
    Ptest->Initialize();
    //test->Initialize();

    while (!Ptest->IsQuit()) { Ptest->Run(); }
    delete Ptest;

    return 0;
}