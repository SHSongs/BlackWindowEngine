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
		worldOutliner.AddObject(new Canon(FPosition({ 0,0 }), "canon1", "¡Ü", "¡Û", Area({ 2,8 }), 1));
		worldOutliner.AddObject(new Canon(FPosition({ 5,0 }), "canon2", "¡Ü", "¡Û", Area({1,1}),0));
		worldOutliner.AddObject(new Canon(FPosition({ 0,10 }), "canon3", "¡Ü", "¡Û", Area({10,1}),0));
	}

	void Render(float dt)
	{
	
		//worldOutliner.FindObject("canon1")->TryWork();

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