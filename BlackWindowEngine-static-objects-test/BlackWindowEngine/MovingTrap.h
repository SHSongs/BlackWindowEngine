#pragma once
#include "Object.h"
#include "WorldOutliner.h"
#include "SceneManager.h"
class MovingTrap : public Object {
private:
	
public:
	string Direction;
	string ID;
	MovingTrap()
	{

	}
	MovingTrap(FPosition Position, string Name, string Shape, string Direction) : Object(Position, Name, Shape, Direction)
	{
		ID = Name;
		this->Direction = Direction;
	}



	void Work() 
	{
		Move();
	}

	/*void OnCollision(Object* other) 
	{
		Object* o = WorldOutliner::FindObject(ID);
		if (o->getDirection() == "ก่") {
			o->setDirection("ก้");
		}
		if (o->getDirection() == "ก้") {
			o->setDirection("ก่");
		}

		if (o->getDirection() == "ก็") {
			Translate({ +5, 0 });
			o->setDirection("กๆ");
			
		}
		if (o->getDirection() == "กๆ") {
			o->setDirection("ก็");
		}
	}*/

	void OnCollision(Object* other)
	{
	//	Object* o = WorldOutliner::FindObject(ID);
		if (Direction == "ก่") {
			Direction = "ก้";
		}
		else if (Direction == "ก้") {
			Direction = "ก่";
		}

		if (Direction == "ก็") {
			Direction ="กๆ";
		}
		else if (Direction == "กๆ") {
			Direction = "ก็";
		}
	}
	void Move()
	{
	//	Object* o = WorldOutliner::FindObject(ID);
		if (Direction == "ก่") {
			Translate(Up);
		}
		else if (Direction == "ก้") {
			Translate(Down);
		}

		if (Direction == "ก็") {
			Translate(Left);
		}
		else if (Direction == "กๆ") {
			Translate(Right);
		}
	}
};