#pragma once

#include "SceneLifeCycle.h"


using namespace std;

class TestScene : public SceneLifeCycle
{
private:
public:

	TestScene() : SceneLifeCycle()
	{
		mapPointer = new Map(30, 30);
	};
	void Create()
	{
		worldOutliner.AddObject(Object(Position({ 1,2 }), "o1", "¡ß"));
		worldOutliner.AddObject(Object(Position({ 1,3 }), "o2", "¡ß"));

		for (int i = 0; i < 10; i++)
		{
		}
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
	~TestScene() 
	{

	}
};