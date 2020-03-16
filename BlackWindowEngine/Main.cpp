#include<iostream>
#include<vector>
#include <Windows.h>
#include<chrono>


#include "EngineLifeCycle.h"
#include "TestScene.h"


using namespace std;



int main()
{
    EngineLifeCycle Engine = EngineLifeCycle(new TestScene());

    return 0;
}