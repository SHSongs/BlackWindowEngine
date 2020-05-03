#include "BasicScene.h"

BasicScene::BasicScene(): SceneManager()
{

	mapPointer = new Map(30, 30);
}

void BasicScene::Create()
{
}

void BasicScene::Render(float dt)
{
}

void BasicScene::Resize(int x, int y)
{
}

void BasicScene::Input(float dt)
{
}

void BasicScene::Pause()
{
}

BasicScene::~BasicScene()
{
}
