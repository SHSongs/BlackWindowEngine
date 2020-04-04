#pragma once

#include<iostream>
#include<vector>

#include "Unit.h"

using namespace std;


class Object
{
protected:
	string name;
	string shape;
	string Type;
	FPosition position;
	Area area;
	string Direction;
	
	float Speed = 0.2;
	FPosition Up = { 0, Speed };
	FPosition Down = { 0, -Speed };
	FPosition Left = { -Speed, 0 };
	FPosition Right = { Speed, 0 };
	
public:
	Object()
	{
		this->Object::Object({ 0,0 });
	}
	Object(FPosition p)
	{
		this->Object::Object(p, "object", "¡à", "Unknown");
	}
	
	Object(FPosition p, string name, string shape, string Type)
	{
		this->Object::Object(p, name, shape, Area({ 1, 1 }),Type);

	}

	Object(FPosition p, string name, string shape, Area area, string Type)
	{
		this->Object::Object(p, name, shape, area, "", Type);
	}

	Object(FPosition p, string name, string shape, string direction, string Type)
	{
		this->Object::Object(p, name, shape, Area{ 1,1 }, direction, Type);
	}

	Object(FPosition p, string name, string shape, Area Area, string direction, string Type)
	{
		this->name = name;
		this->shape = shape;
		this->position = p;
		this->Direction = direction;
		this->area.width = Area.width;
		this->area.height = Area.height;
		this->Type = Type;
	}


	string GetName()
	{
		return name;
	}
	void SetName(string name)
	{
		this->name = name;
	}

	FPosition GetPosition()
	{
		return position;
	}
	void SetPosition(FPosition p)
	{
		position = p;
	}

	string GetShape()
	{
		return shape;
	}
	void SetShape(string shape)
	{
		// if shape size is 1 : add " "
		this->shape = shape;
	}
	string getDirection()
	{
		return Direction;
	}
	void setDirection(string D)
	{
		this->Direction = D;
	}
	string getType()
	{
		return Type;
	}
	void setType(string t)
	{
		this->Type = t;
	}

	void Push(string Direction) {
		if (Direction == "¡è")
			Translate({ 0, -1 });
		if (Direction == "¡ç")
			Translate({ -1, 0 });
		if (Direction == "¡é")
			Translate({ 0, +1 });
		if (Direction == "¡æ")
			Translate({ +1, 0 });
	}

	void Translate(FPosition p)
	{
		this->position.x += p.x;
		this->position.y += p.y;
	}
	void Translate(FPosition p, string shape)
	{
		this->position.x += p.x;
		this->position.y += p.y;
		this->shape = shape;
	}
	void TryWork()
	{
		if(this)
			Work();
	}
	Area GetArea()
	{
		return area;
	}
	virtual void Work() {}
	virtual void OnCollision(Object* other){}


};


class ObjectList
{
public:
	vector<Object> list;
	string name;

	ObjectList(string name)
	{

	}
};