#pragma once

#include "Object.h"

class Wall : public Object {
private:

public:
	//WorldOutliner worldOutliner;
	Wall() {

	}
	Wall(string name) {
	}
	Wall(FPosition p, string name, string shape)
	{
		
	}
	Wall(FPosition p, string name, string shape, Area area) : Object(p, name, shape, area)
	{

	}

	void Work() // 랜더 안에서 돌아가는 Work
	{
		Make();
	}

	void Make() {
		//SceneManager.worldOutliner.AddObject(new Wall(FPosition({ 5,5 }), "Wall_10,10", "ㅁ"));
	}
	void OnCollision(Object* other)
	{
		;
	}
	
	
	
	
	void Pause()
	{

	}
	~Wall()
	{

	}
};