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


#include "SceneLifeCycle.h"


using namespace std;

class FirstScene : public SceneLifeCycle
{
private:
	WorldOutliner worldOutliner;
	Tools tool;
	Map map;
	bool i = true;

public:
	FirstScene() {};
	void Create()
	{
		worldOutliner = WorldOutliner();
		tool = Tools();
		map = Map();

		map.Print();
	}
	void Render(float dt)
	{
		map.CopyCurrentMap();
		if (i) {
			map.SetPartOfMap(5, 10, 2);
			i = false;
		}
		else {
			map.SetPartOfMap(5, 10, 0);
			i = true;
		}

		vector<Position> v = map.ModifiedMap();

		for (auto i : v)
		{
			tool.cersorMoveTo(i.x, i.y);
			cout << map.GetPartOfMap(i.x, i.y);
		}
		tool.backCersor();
	}
	void Resize(int x, int y)
	{

	}
	void Input(float dt)
	{

	}
	void Pause()
	{

	}
	~FirstScene() {};
};