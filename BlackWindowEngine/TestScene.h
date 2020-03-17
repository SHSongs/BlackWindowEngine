#pragma once

#include "SceneLifeCycle.h"


using namespace std;

class TestScene : public SceneLifeCycle
{
private:
	vector<Object> obs;
public:

	TestScene() : SceneLifeCycle()
	{
		mapPointer = new Map(30, 30);
	};
	void Create()
	{
		for (int i = 0; i < 10; i++)
		{
			obs.push_back(Object({ i, 0 }));
			obs[i].SetNumber(2);
		}
	}

	void Render(float dt)
	{
		for (auto& o : obs)
		{
			o.Translate(Position({ 0,1 }));
		}
		SceneLifeCycle::UploadMap(obs);
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