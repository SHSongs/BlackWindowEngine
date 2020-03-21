#pragma once
#include<iostream>
#include<vector>

#include "Unit.h"
#include "Map.h"
#include "SceneManager.h"
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


			// 충돌검사
			for(auto my : scene->worldOutliner.GetObjects())
			{
				for(auto other : scene->worldOutliner.GetObjects())
				{
					if(my != other)
					{
						Position myP = PositionTools::FPtoIP(my->GetPosition());
						Area myA = my->GetArea();
						Position otherP = PositionTools::FPtoIP(
							other->GetPosition());
						Area otherA = other->GetArea();

						if(myP.x + myA.width > otherP.x && myP.x < otherP.x + otherA.width)
						{
							if(myP.y + myA.height > otherP.y && myP.y < otherP.y + otherA.height)
							{
								my->OnCollision(other);
							}
						}
						/*if(PositionTools::IsEqual(my->GetPosition(),other->GetPosition()))
						{
						}*/
					}
				}
			}
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