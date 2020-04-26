#pragma once
#include "Object.h"
#include "WorldOutliner.h"
#include "SceneManager.h"
#include <string.h>
#include "Unit.h"
//#include "Player.h"

class PushTrap : public Object {
private:

public:
	std::string Direction;
	std::string ID;
	PushTrap() {

	}
	PushTrap(string name) {
		ID = name;
	}
	PushTrap(FPosition p, std::string name, std::string shape, std::string Type) : Object(p, name, shape, Type)
	{
		ID = name;
	}
	PushTrap(FPosition p, string name, string shape, Area area, string Type) : Object(p, name, shape, area, Type)
	{
		ID = name;
	}
	void Create()
	{
		
	}

	void Work() // 랜더 안에서 돌아가는 Work
	{
		
	}

	void OnCollision(Object* other)
	{
		string Direction;
		static string back;

		Object* o = WorldOutliner::FindObject("Player");
		//Direction = o->GetShape();
		Object* Pushtrap = WorldOutliner::FindObject(ID);

		if (other->getType() == "Player") {
			Direction = o->GetShape();

			if (Direction == "↑") {
				Translate({ 0, -1 });
				back = Direction;
			}
			if (Direction == "←") {
				Translate({ -1, 0 });
				back = Direction;
			}
			if (Direction == "↓") {
				Translate({ 0, +1 });
				back = Direction;
			}
			if (Direction == "→") {
				Translate({ +1, 0 });
				back = Direction;
			}
		}
		else if (other->getType()=="Wall") 
		{
			FPosition object_Position = o->GetPosition();
			FPosition Pushtrap_Position = Pushtrap->GetPosition();
			Direction = o->GetShape();	
			if (back == "↑") {
				Translate({ 0, +1 });
				o->Translate({ 0, +1 });
			}
			if (back == "←") {
				Translate({ +1, 0 });
				o->Translate({ +1, 0 });
			}
			if (back == "↓") {
				Translate({ 0, -1 });
				o->Translate({ 0, -1 });
			}
			if (back == "→") {
				Translate({ -1, 0 });
				o->Translate({ -1, 0 });
			}
		}

	}
	void Push(std::string w)
	{

	}
};