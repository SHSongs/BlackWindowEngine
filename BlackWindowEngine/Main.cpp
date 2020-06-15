#include<iostream>
#include<vector>
#include <Windows.h>
#include<chrono>


#include "EngineManager.h"
#include "TestScene.h"
#include "BasicScene.h"

using namespace std;



int main()
{
    EngineManager Engine = EngineManager(new TestScene());

    return 0;
}