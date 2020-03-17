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
		worldOutliner.AddObject(new Object(Position({ 0,0 }), "o1", "¡ß"));
		
	}

	void Render(float dt)
	{
		Object* o = worldOutliner.FindObject("o1");

		o->Translate(Position({ 1,1 }));


		
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