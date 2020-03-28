#pragma once

#include "Canon.h"
#include "SceneManager.h"
#include <optional>
#include "Player.h"
#include "Wall.h"
#include "PushTrap.h"
using namespace std;

class TestScene : public SceneManager
{
private:
public:
	
	int Size = 30;
	TestScene() : SceneManager()
	{
		mapPointer = new Map(30, 30);
	};
	void Create()
	{
		
		worldOutliner.AddObject(new Canon(FPosition({ 1,1 }), "canon1", "¡Ü", "¡Û", Area({ 2,8 }), 0));
		worldOutliner.AddObject(new Canon(FPosition({ 5,1 }), "canon2", "¡Ü", "¡Û", Area({1,1}),0));
		worldOutliner.AddObject(new Canon(FPosition({ 1,10 }), "canon3", "¡Ü", "¡Û", Area({10,1}),0));
		worldOutliner.AddObject(new Player(FPosition({ 2,28 }), "Player", "¡è"));
	
		Map_Make();
	}

	void Render(float dt)
	{
	
		
		//dynamic_cast<Player*>(worldOutliner.FindObject("canon1"))->getW();

		
		
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
	void Map_Make() 
	{
		worldOutliner.AddObject(new Wall(FPosition({ 0,0 }), "Wall_Top", "¡á", Area({ Size, 1 })));
		worldOutliner.AddObject(new Wall(FPosition({ 0,0 }), "Wall_Left", "¡á", Area({ 1, Size })));
		worldOutliner.AddObject(new Wall(FPosition({ (float) Size-1, 0 }), "Wall_Right", "¡á", Area({ 1, Size })));
		worldOutliner.AddObject(new Wall(FPosition({ 0, (float) Size-1 }), "Wall_Bottom", "¡á", Area({ Size, 1 })));
	}
	string getW()
	{
		worldOutliner.FindObject("Player")->GetShape();
	}
};