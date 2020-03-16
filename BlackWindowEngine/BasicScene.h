
#pragma once

#include<iostream>
#include<vector>
#include <Windows.h>
#include<chrono>

#include "SceneLifeCycle.h"


using namespace std;

class BasicScene : public SceneLifeCycle
{
public:
	BasicScene():SceneLifeCycle()
	{

	}
	void Create()
	{

	}
	void Render(float dt)
	{

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
	~BasicScene()
	{

	}
};