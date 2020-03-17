#pragma once
#include<iostream>
#include<vector>

#include "Position.h"
#include "Map.h"
#include "SceneLifeCycle.h"
#include "Time.h"
#include "BasicScene.h"
#include "Tools.h"

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
		scene->mapPointer->Print();

		 
		 
		
		while (true)
		{
			time.StartMeasure();


			scene->mapPointer->CopyCurrentMapANDRemoveCurrentMap();

			
			//strat
			scene->Render(time.deltaTime);
			//end

			scene->SceneLifeCycle::UploadMap(scene->worldOutliner.GetObjects());

			vector<Position> v = scene->mapPointer->ModifiedMap();
			for (auto i : v)
			{
				Tools::cersorMoveTo({ i.x, i.y });
				cout << scene->mapPointer->GetPartOfMap({ i.x, i.y });
			}
			Tools::backCersor();


			time.EndMeasure();
		}

	}


};