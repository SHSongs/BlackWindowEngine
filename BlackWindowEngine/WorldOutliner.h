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

	Object FindObject(string name)
	{
		try
		{
			for (auto& o : objects)
			{
				if (name.compare(o.GetName()) == 0)
				{
					return o;
				}
			}
		}
		catch(exception e)
		{
				Tools::cersorMoveTo(Position({ 20, 30 }));
				cout << "ERROR : Not found" << name << endl;
				Tools::backCersor();
			
		}

	}

	vector<Object> GetObjects()
	{
		return objects;
	}
};
