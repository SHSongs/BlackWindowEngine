#pragma once

#include "Object.h"

class Canon : public Object
{
private:
	bool ch = true;
	int way = 1;
public:
	string shape2;
	Canon(FPosition p, string name, string shape, string shape2, int way) : Object(p,name,shape)
	{
		this->shape2 = shape2;
		this->way = way;
	}

	virtual void Work()
	{
		Translate(FPosition({ (float)(0.5 * way),0 }));
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
	virtual void CollisionEnter(Object* other)
	{
		shape2 = shape;
	}
	
};