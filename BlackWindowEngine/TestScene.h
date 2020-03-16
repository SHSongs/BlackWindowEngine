#pragma once

#include "SceneLifeCycle.h"


using namespace std;

class TestScene : public SceneLifeCycle
{
private:

public:

	Object ob;

	TestScene() : SceneLifeCycle()
	{
	};
	void Create()
	{

		ob = Object({ 0,0 });
		ob.SetNumber(5);
		map.Print();
	}
	void Render(float dt)
	{
		
		ob.Translate({ 1, 1 });
			
		SceneLifeCycle::UploadMap(ob);

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