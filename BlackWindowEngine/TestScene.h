#pragma once

#include "Canon.h"
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
		worldOutliner.AddObject(new Canon(FPosition({ 0,0 }), "canon1", "¡Û","¡Ü"));
		
	}

	void Render(float dt)
	{
		dynamic_cast<Canon*>(worldOutliner.FindObject("canon1"))->DoNothing();	
		worldOutliner.FindObject("canon1")->Work();
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