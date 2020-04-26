#pragma once

#include<iostream>
#include<vector>

class Map
{

private:
	int XSIZE;
	int YSIZE;
public:

	std::vector<std::vector<std::string>>* lastMap;
	std::vector<std::vector<std::string>>* currentMap;

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
		lastMap = new std::vector<std::vector<std::string>>(YSIZE, std::vector<std::string>(XSIZE, "  "));
		currentMap = new std::vector<std::vector<std::string>>(YSIZE, std::vector<std::string>(XSIZE, "  "));

	}

	void Print()
	{
		for (auto y : *currentMap)
		{
			for (auto x : y)
			{
				std::cout << x;
			}
			std::cout << "\n";
		}
	}
	void CopyCurrentMapANDRemoveCurrentMap()
	{
		*lastMap = *currentMap;
		currentMap->clear();
		currentMap = new std::vector<std::vector<std::string>>(YSIZE, std::vector<std::string>(XSIZE, "  "));
	}

	std::vector<Position> ModifiedMap()
	{
		std::vector<Position> positions;
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


	std::string GetPartOfMap(Position p)			
	{
		return currentMap->at(p.y).at(p.x);
	}

	void SetPartOfMap(Position p, std::string change, Area area)	
	{
		for(int y = p.y; y < area.height + p.y; y++)
		{
			for(int x = p.x; x < area.width + p.x; x++)
			{
				currentMap->at(y).at(x) = change;
			}
		}
	}

	int GetYSIZE()
	{
		return YSIZE;
	}

	
};