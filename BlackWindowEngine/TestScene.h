#pragma once

#include "Canon.h"
#include "SceneManager.h"
#include <optional>

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
		worldOutliner.AddObject(new Canon(FPosition({ 0,0 }), "canon1", "¡Ü","¡Û", 1));
		worldOutliner.AddObject(new Canon(FPosition({ 5,0 }), "canon2", "¡Ü","¡Û", -1));
	}

	void Render(float dt)
	{
	
		
		worldOutliner.FindObject("canon1")->TryWork();
		worldOutliner.FindObject("canon2")->TryWork();

		
		
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