#pragma once

#include "Object.h"

class Canon : public Object
{
private:
	bool ch = true;
	int way = 1;
public:
	
	string shape2;
	Canon(FPosition p, string name, string shape, string shape2, Area area, int way) : Object(p, name, shape, area)
	{
		this->shape2 = shape2;
		this->way = way;
	}

	virtual void start(FPosition p, string name, string shape, string shape2, Area area, int way)
	{
		Object::Start(p, name, shape, area);
		this->shape2 = shape2;
		this->way = way;
		
	}
	void test()
	{
		Instantiate(new Canon(FPosition({ 15,15 }), "canon1", "¡Ü", "¡Û", Area({ 2,8 }), 1));
	}

	virtual void Work()
	{
		Translate(FPosition({ 0,(float)(0.5 * way) }));
		SwapShape();
	}
	void SwapShape()
	{
		string tmp = shape;
		shape = shape2;
		shape2 = tmp;
	}
	void DoNothing()
	{
		
	}
	virtual void OnCollision(Object* other)
	{
		shape2 = shape;
		//delete this;
	}
	
};