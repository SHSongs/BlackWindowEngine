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



class SceneLifeCycle
{
protected:
	WorldOutliner worldOutliner;
public:
	Map map;
	Tools tool;

	SceneLifeCycle()
	{
		worldOutliner = WorldOutliner();
		tool = Tools();
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

	}

};