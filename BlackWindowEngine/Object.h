#pragma once

#include<iostream>
#include<vector>

#include "Position.h"


using namespace std;


class Object
{
private:
	string name;
	string shape;
	Position position;
public:
	Object()
	{
		this->Object::Object({ 0,0 });
	}
	Object(Position p)
	{
		this->Object::Object(p, "object", "бр");
	}
	Object(Position p, string name, string shape)
	{
		this->name = name;
		this->shape = shape;
		this->position = p;
	}

	string GetName()
	{
		return name;
	}
	void SetName(string name)
	{
		this->name = name;
	}

	Position GetPosition()
	{
		return position;
	}
	void SetPosition(Position p)
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


	void Translate(Position p)
	{
		this->position.x += p.x;
		this->position.y += p.y;
	}
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