#pragma once

#include<iostream>
#include<vector>

#include "Unit.h"
#include "WorldOutliner.h"

using namespace std;


class Object
{
protected:
	string name;
	string shape;
	FPosition position;

	Area area;

	WorldOutliner* P_world_outliner;
	
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

	Object(FPosition p, string name, string shape, Area area)
	{
		this->name = name;
		this->shape = shape;
		this->position = p;
		this->area.width = area.width;
		this->area.height = area.height;
	}

	void InitWordOutliner(WorldOutliner* w)
	{
		P_world_outliner = w;
	}
	
	virtual void Start(FPosition p, string name, string shape, Area area)
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


	void Instantiate(Object* o)
	{
		P_world_outliner->AddObject(o);
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