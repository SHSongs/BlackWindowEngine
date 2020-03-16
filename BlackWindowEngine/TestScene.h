#pragma once

#include "SceneLifeCycle.h"


using namespace std;

class TestScene : public SceneLifeCycle
{
private:

	Object ob;
	Object ob2;
public:

	TestScene() : SceneLifeCycle()
	{
	};
	void Create()
	{
		ob2 = Object({ 0,0 });
		ob2.SetNumber(8);
		ob = Object({ 0,0 });
		ob.SetNumber(5);
		map.Print();
	}
	void Render(float dt)
	{
		ob2.Translate({0, 1 });
		ob.Translate({ 1, 1 });
			
		SceneLifeCycle::UploadMap(ob);
		SceneLifeCycle::UploadMap(ob2);

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