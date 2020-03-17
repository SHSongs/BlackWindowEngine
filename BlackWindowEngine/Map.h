#pragma once

#include<iostream>
#include<vector>
using namespace std;

class Map
{

private:
	int XSIZE;
	int YSIZE;
public:

	vector<vector<string>>* lastMap;
	vector<vector<string>>* currentMap;

	Map()
	{
		this->Map::Map(20, 20);
	}
	Map(int XSIZE, int YSIZE)
	{
		this->XSIZE = XSIZE;
		this->YSIZE = YSIZE;
		MapInit();
	}
	
	void MapInit()
	{
		lastMap = new vector<vector<string>>(YSIZE, vector<string>(XSIZE, "¡à"));
		currentMap = new vector<vector<string>>(YSIZE, vector<string>(XSIZE, "¡à"));

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
	void CopyCurrentMapANDRemoveCurrentMap()
	{
		*lastMap = *currentMap;
		currentMap->clear();
		currentMap = new vector<vector<string>>(YSIZE, vector<string>(XSIZE, "¡à"));
	}

	vector<Position> ModifiedMap()
	{
		vector<Position> positions;
		for (int y = 0; y < YSIZE; y++)		//¹Ù²Ù±â
		{
			for (int x = 0; x < XSIZE; x++)
			{
				if (currentMap->at(y).at(x) != lastMap->at(y).at(x))
					positions.push_back({x,y});
			}
		}

		return positions;
	}

	
	string GetPartOfMap(Position p)			//Pls, change bast method name
	{
		return currentMap->at(p.y).at(p.x);
	}

	void SetPartOfMap(Position p, string change)	//Pls, change the change variable best name
	{
		currentMap->at(p.y).at(p.x) = change;
	}

	int GetYSIZE()
	{
		return YSIZE;
	}

	
};