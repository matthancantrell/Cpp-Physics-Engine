#include "ParticleTest.h"

int main(int argc, char* argv[])
{
    //Test* test = new Test();
    ParticleTest* Ptest = new ParticleTest();
    Ptest->Initialize();
    //test->Initialize();

    while (!Ptest->IsQuit()) { Ptest->Run(); }
    delete Ptest;

    return 0;
}