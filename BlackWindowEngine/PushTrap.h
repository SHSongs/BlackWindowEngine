#pragma once

#include "Object.h"
#include "WorldOutliner.h"
#include "SceneManager.h"

class PushTrap : public Object {
private:

public:
	string Direction;
	
	PushTrap() {

	}
	PushTrap(string name) {
	}
	PushTrap(FPosition p, string name, string shape) : Object(p, name, shape)
	{

	}
	PushTrap(FPosition p, string name, string shape, Area area) : Object(p, name, shape, area)
	{

	}
	void Create()
	{
		
	}

	void Work() // 랜더 안에서 돌아가는 Work
	{
		
	}

	void OnCollision(Object* o)
	{
		
	}
};