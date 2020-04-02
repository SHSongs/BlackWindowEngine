#pragma once
#include<iostream>
#include<vector>

#include "Object.h"

using namespace std;

class WorldOutliner
{
private:

	static vector<Object*> objects;
public:

	
	static void AddObject(Object* o)
	{
		objects.push_back(o);
	}
	static Object* FindObject(string name)
	{
		for (auto& o : objects)
		{
			if (name.compare(o->GetName()) == 0)
			{
				return o;
			}
		}

		Tools::cersorMoveTo(Position({ 20, 30 }));
		cout << "ERROR : Not found  " << name << endl;
		Tools::backCersor();
		return nullptr;
	}
	
	vector<Object*> GetObjects()
	{
		return objects;
	}
};

vector<Object*> WorldOutliner::objects;