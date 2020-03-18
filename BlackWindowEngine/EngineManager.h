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


class EngineManager
{
private:

	Time time;
	SceneManager* scene;
public:
	EngineManager() 
	{
		this->EngineManager::EngineManager(new BasicScene());
		time = Time();
	}
	EngineManager(SceneManager* scene)
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

			
			//start
			scene->Render(time.deltaTime);
			//end

			scene->SceneManager::UploadMap(scene->worldOutliner.GetObjects());

			vector<Position> v = scene->mapPointer->ModifiedMap();
			for (Position i : v)
			{
				Tools::cersorMoveTo({ i.x, i.y });
				cout << scene->mapPointer->GetPartOfMap({ i.x, i.y });
			}
			Tools::backCersor();


			time.EndMeasure();
		}

	}


};