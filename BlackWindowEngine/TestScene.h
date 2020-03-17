#pragma once

#include "SceneLifeCycle.h"


using namespace std;

class TestScene : public SceneLifeCycle
{
private:
	vector<Object> obs;
	Object ob;
	Object ob2;
public:

	TestScene() : SceneLifeCycle()
	{
		
	};
	void Create()
	{
		for (int i = 0; i < 10; i++)
		{
			obs.push_back(Object({ i, 0 }));
			obs[i].SetNumber(2);
		}
		ob2 = Object({ 0,0 });
		ob2.SetNumber(8);
		ob = Object({ 0,0 });
		ob.SetNumber(5);
		map.Print();
	}

	void Render(float dt)
	{
		ob2.Translate({0, 1 });
		ob.Translate({1, 1 });
		
		for (auto& o : obs)
		{
			o.Translate(Position({ 0,1 }));
		}

		SceneLifeCycle::UploadMap(ob);
		SceneLifeCycle::UploadMap(ob2);
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