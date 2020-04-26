#pragma once
#include<iostream>
#include<vector>

#include "Tools.h"



class WorldOutliner
{
private:

	static std::vector<Object*> objects;
public:

	
	static void AddObject(Object* o)
	{
		objects.push_back(o);
	}
	static Object* FindObject(std::string name)
	{
		for (auto& o : objects)
		{
			if (name.compare(o->GetName()) == 0)
			{
				return o;
			}
		}

		Tools::cersorMoveTo(Position({ 20, 30 }));
		std::cout << "ERROR : Not found  " << name << std::endl;
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
	std::vector<Object*> GetObjects()
	{
		return objects;
	}
};

std::vector<Object*> WorldOutliner::objects;