#pragma once
#include<iostream>
#include<vector>

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

	vector<Object> FindObject(string name)
	{
		vector<Object> obs;
		for (auto o : objects)
		{
			if (name.compare(o.GetName()))
			{
				obs.push_back(o);
			}
		}

		return obs;
	}

	vector<Object> GetObjects()
	{
		return objects;
	}
};
