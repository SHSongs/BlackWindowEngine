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
	Wall(FPosition p, string name, string shape, string Type) : Object(p, name, shape, Type)
	{
		
	}
	Wall(FPosition p, string name, string shape, Area area, string Type) : Object(p, name, shape, area, Type)
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