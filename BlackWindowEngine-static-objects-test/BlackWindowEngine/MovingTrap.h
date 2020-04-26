#pragma once
#include "Object.h"
#include "WorldOutliner.h"


class MovingTrap : public Object {
private:
	
public:
	std::string Direction;
	std::string ID;
	MovingTrap()
	{

	}
	MovingTrap(FPosition Position, std::string Name, std::string Shape, std::string Direction, std::string Type) : Object(Position, Name, Shape, Direction, Type)
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
		Object* o = WorldOutliner::FindObject(ID);
		if (o->getDirection() == "ก่") {
			o->setDirection("ก้");
		}
		else if (o->getDirection() == "ก้") {
			o->setDirection("ก่");
		}

		if (o->getDirection() == "ก็") {
			o->setDirection("กๆ");
		}
		else if (o->getDirection()== "กๆ") {
			o->setDirection("ก็");
		}
	}
	void Move()
	{
		Object* o = WorldOutliner::FindObject(ID);
		if (o->getDirection() == "ก่") {
			Translate(Up);
		}
		else if (o->getDirection() == "ก้") {
			Translate(Down);
		}

		if (o->getDirection() == "ก็") {
			Translate(Left);
		}
		else if (o->getDirection() == "กๆ") {
			Translate(Right);
		}
	}
};