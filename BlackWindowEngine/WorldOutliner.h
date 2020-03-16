#pragma once
#include<iostream>
#include<vector>
#include <Windows.h>

#include "Object.h"

using namespace std;

class WorldOutliner
{
private:
	vector<Object> objects;

public:
	void AddObject(Object o)
	{
		objects.push_back(o);
	}

	Object FindObject(string name)
	{
		for (auto o : objects)
		{
			if (name.compare(o.GetName()))
			{
				return o;
			}
		}

		//return NULL;
	}

	vector<Object> GetObjects()
	{
		return objects;
	}
};
