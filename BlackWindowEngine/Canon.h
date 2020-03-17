#pragma once

#include "Object.h"

class Canon : public Object
{
private:
	bool ch = true;
public:
	string shape2;
	Canon(FPosition p, string name, string shape, string shape2) : Object(p,name,shape)
	{
		this->shape2 = shape2;
	}

	void Work()
	{
		Translate(FPosition({ 0.5,0 }));
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
	
};