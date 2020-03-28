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
	FPosition position;
	Area area;
	string w;
	
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
		this->Object::Object(p, name, shape, Area({ 1, 1 }));

	}

	Object(FPosition p, string name, string shape, string w)
	{
		this->Object::Object(p, name, shape, w);

	}

	Object(FPosition p, string name, string shape, Area area)
	{
		this->name = name;
		this->shape = shape;
		this->position = p;
		this->area.width = area.width;
		this->area.height = area.height;
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