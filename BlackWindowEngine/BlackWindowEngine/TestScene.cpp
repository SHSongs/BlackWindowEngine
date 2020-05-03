#include "TestScene.h"

TestScene::TestScene(): SceneManager()
{
	mapPointer = new Map(30, 30);
}

void TestScene::Create()
{
	WorldOutliner::AddObject(new Player(FPosition({2, 28}), "Player", "¡è", "Player"));
	WorldOutliner::AddObject(new PushTrap(FPosition({15, 15}), "PushTrap_1", "@@", "PushTrap"));
	WorldOutliner::AddObject(new MovingTrap(FPosition({20, 20}), "MovingTrap_1", "HH", "¡ç", "MovingTrap"));
	WorldOutliner::AddObject(new MovingTrap(FPosition({25, 20}), "MovingTrap_2", "HH", "¡ç", "MovingTrap"));
	WorldOutliner::AddObject(new MovingTrap(FPosition({28, 28}), "MovingTrap_3", "VV", "¡è", "MovingTrap"));
	WorldOutliner::AddObject(new MovingTrap(FPosition({28, 14}), "MovingTrap_4", "VV", "¡è", "MovingTrap"));
	WorldOutliner::AddObject(new MovingTrap(FPosition({2, 2}), "MovingTrap_5", "¢È", "¡ç", "MovingTrap"));
	WorldOutliner::AddObject(new MovingTrap(FPosition({6, 3}), "MovingTrap_6", "¢È", "¡ç", "MovingTrap"));


	WorldOutliner::AddObject(new Wall(FPosition({3, 4}), "Hwall1", Area({10, 1})));
	WorldOutliner::AddObject(new Wall(FPosition({1, 10}), "Hwall2", Area({15, 1})));
	WorldOutliner::AddObject(new Wall(FPosition({1, 20}), "Hwall3", Area({10, 1})));
	WorldOutliner::AddObject(new Wall(FPosition({10, 2}), "Vwall1", Area({1, 7})));
	WorldOutliner::AddObject(new Wall(FPosition({7, 8}), "Vwall2", Area({1, 7})));


	Map_Make();
}

void TestScene::Render(float dt)
{
	//		worldOutliner.FindObject("MovingTrap_1")->TryWork();

	//dynamic_cast<Player*>(worldOutliner.FindObject("canon1"))->getW();
}

void TestScene::Resize(int x, int y)
{
}

void TestScene::Input(float dt)
{
}

void TestScene::Pause()
{
}

TestScene::~TestScene()
{
}

void TestScene::Map_Make()
{
	WorldOutliner::AddObject(new Wall(FPosition({0, 0}), "Wall_Top", "¡á", Area({Size, 1}), "Wall"));
	WorldOutliner::AddObject(new Wall(FPosition({0, 0}), "Wall_Left", "¡á", Area({1, Size}), "Wall"));
	WorldOutliner::AddObject(new Wall(FPosition({(float)Size - 1, 0}), "Wall_Right", "¡á", Area({1, Size}), "Wall"));
	WorldOutliner::AddObject(new Wall(FPosition({0, (float)Size - 1}), "Wall_Bottom", "¡á", Area({Size, 1}), "Wall"));
}

std::string TestScene::getW()
{
	return worldOutliner.FindObject("Player")->GetShape();
}
