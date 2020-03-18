#pragma once

#include "Canon.h"
#include "SceneManager.h"


using namespace std;

class TestScene : public SceneManager
{
private:
public:

	TestScene() : SceneManager()
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
		
		Object* canon1 = worldOutliner.FindObject("canon1");
		if (canon1) canon1->Work();
		
		worldOutliner.FindObject("nothing")->TryWork();
		
		
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