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
	int number;
public:
	Object()
	{
		this->Object::Object({ 0,0 });
	}
	Object(Position p)
	{
		this->name = "object";
		this->shape = "бр";
		this->position = p;
		this->number = 0;
	}
	Object(Position p, string name, string shape)
	{

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

	int GetNumber() 
	{
		return number;
	}
	void SetNumber(int number)
	{
		this->number = number;
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