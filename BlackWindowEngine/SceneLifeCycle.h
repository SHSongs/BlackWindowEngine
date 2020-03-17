#pragma once


#include "Object.h"
#include "Map.h"
#include "SceneLifeCycle.h"
#include "WorldOutliner.h"


class SceneLifeCycle
{
protected:
public:
	WorldOutliner worldOutliner;
	Map map;

	SceneLifeCycle()
	{
		worldOutliner = WorldOutliner();
		map = Map();
	};
	virtual void Create() = 0;			//Called when the Application is first created.
	virtual void Render(float dt) = 0;
	virtual void Resize(int x, int y) = 0;
	virtual void Input(float dt) = 0;
	virtual void Pause() = 0;			//Stop Game
	virtual ~SceneLifeCycle() {};				//Called when this Game should release all resources.

	void UploadMap(Object o)
	{
		map.SetPartOfMap(o.GetPosition(), o.GetNumber());
	}

	void UploadMap(vector<Object> vecO)
	{
		for (auto o : vecO)
		{
			map.SetPartOfMap(o.GetPosition(), o.GetNumber());
		}
	}

};