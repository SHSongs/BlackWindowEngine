#pragma once

#include "SceneLifeCycle.h"


using namespace std;

class FirstScene : public SceneLifeCycle
{
private:
	Object ob;
	bool i = true;

public:

	FirstScene() : SceneLifeCycle()
	{
		ob = Object({ 5,5 });
	};
	void Create()
	{
		map.Print();
	}
	void Render(float dt)
	{
		
		if (i)
		{
			ob.SetNumber(8);
			i = false;
		}
		else 
		{
			ob.SetNumber(1);
			i = true;
		}


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
	~FirstScene() 
	{

	}
};