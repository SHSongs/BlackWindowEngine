#pragma once
#include<iostream>
#include<vector>
#include <Windows.h>
#include<chrono>

#include "Position.h"
#include "Map.h"
#include "SceneLifeCycle.h"
#include "Object.h"
#include "WorldOutliner.h"
#include "Time.h"
#include "BasicScene.h"


using namespace std;


class EngineLifeCycle
{
private:

	Time time;
	SceneLifeCycle* scene;
public:
	EngineLifeCycle() 
	{
		this->EngineLifeCycle::EngineLifeCycle(new BasicScene());
		time = Time();
	}
	EngineLifeCycle(SceneLifeCycle* scene)
	{
		this->scene = scene;

		start();
	}
	void start()
	{
		scene->Create();

		while (true)
		{
			time.StartMeasure();
			scene->Render(time.deltaTime);

			time.EndMeasure();
		}

	}


};