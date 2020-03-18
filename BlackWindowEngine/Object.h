#pragma once

#include<iostream>
#include<vector>

#include "Position.h"


using namespace std;


class Object
{
protected:
	string name;
	string shape;
	FPosition position;
public:
	Object()
	{
		this->Object::Object({ 0,0 });
	}
	Object(FPosition p)
	{
		this->Object::Object(p, "object", "бр");
	}
	Object(FPosition p, string name, string shape)
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


	void Translate(FPosition p)
	{
		this->position.x += p.x;
		this->position.y += p.y;
	}
	void TryWork()
	{
		if(this)
			Work();
	
	}
	virtual void Work() = 0;
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