#pragma once
#include<iostream>
#include<vector>

#include "Tools.h"


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

	static void Destroy(Object *object)
	{
		auto iter = objects.begin();
		
		for(iter; iter != objects.end();)
		{
			if(*iter == object)
			{
				iter = objects.erase(iter);
				return;
			}
			else
			{
				iter++;
			}
		}
	}
	vector<Object*> GetObjects()
	{
		return objects;
	}
};

vector<Object*> WorldOutliner::objects;