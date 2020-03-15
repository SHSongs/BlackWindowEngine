#pragma once

#include<iostream>
#include<vector>
#include <Windows.h>
#include<chrono>


using namespace std;




class Map
{

private:
	int XSIZE;
	int YSIZE;
	vector<vector<int>>* lastMap;
public:

	vector<vector<int>>* currentMap;
	Map()
	{
		this->XSIZE = 20;
		this->YSIZE = 20;
		MapInit();
	}
	Map(int XSIZE, int YSIZE)
	{
		this->XSIZE = XSIZE;
		this->YSIZE = YSIZE;
		MapInit();
	}

	void MapInit()
	{
		lastMap = new vector<vector<int>>(YSIZE, vector<int>(XSIZE, 0));
		currentMap = new vector<vector<int>>(YSIZE, vector<int>(XSIZE, 0));

	}

	void Print()
	{
		for (auto y : *currentMap)
		{
			for (auto x : y)
			{
				cout << x;
			}
			cout << "\n";
		}
	}
	void CopyCurrentMap()
	{
		*lastMap = *currentMap;
	}

	vector<Position> ModifiedMap()
	{
		vector<Position> positions;
		for (int y = 0; y < YSIZE; y++)		//¹Ù²Ù±â
		{
			for (int x = 0; x < XSIZE; x++)
			{
				if (currentMap->at(y).at(x) != lastMap->at(y).at(x))
					positions.push_back({ x,y });
			}
		}

		return positions;
	}

	int GetPartOfMap(int x, int y)			//Pls, change bast method name
	{
		return currentMap->at(y).at(x);
	}
	void SetPartOfMap(int x, int y, int change)	//Pls, change the change variable best name
	{
		currentMap->at(y).at(x) = change;
	}
};