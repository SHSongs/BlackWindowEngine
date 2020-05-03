#pragma once
#include<iostream>
#include<vector>

#include "Object.h"


class WorldOutliner
{
private:

	static std::vector<Object*> objects;
public:


	static void AddObject(Object* o);

	static Object* FindObject(std::string name);

	static void Destroy(Object* object);

	static void Clear();
	std::vector<Object*> GetObjects();
};
