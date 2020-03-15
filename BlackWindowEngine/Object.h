#pragma once

#include<iostream>
#include<vector>
#include <Windows.h>

#include "Position.h"


using namespace std;


class Object
{
private:
	string name;
	Position position = { 0,0 };
public:
	Position getPosition()
	{
		return position;
	}
	void setPosition(Position p)
	{
		position = p;
	}
};
