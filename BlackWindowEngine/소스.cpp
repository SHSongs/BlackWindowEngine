#include<iostream>
#include<vector>
#include <Windows.h>
#include<stdio.h>

using namespace std;

struct Position 
{
	int x;	
	int y;
};


class Object 
{
private:
	string name;
	Position position = {0,0};
public:
	Position getPosition() 
	{
		return position;
	}
	void setPosition(Position p) 
	{
		position = p;
	}
};

class Map 
{

private:
	int XSIZE;
	int YSIZE;
	vector<vector<int>> lastMap;

public:

	vector<vector<int>> currentMap;		//Pls, move to private

	void Initialization(int XSIZE, int YSIZE)	//map initialization
	{
		this->XSIZE = XSIZE;
		this->YSIZE = YSIZE;
		for (int i = 0; i < YSIZE; i++)
		{
			vector<int> tmp;
			currentMap.push_back(tmp);
			lastMap.push_back(tmp);
			for (int j = 0; j < XSIZE; j++)
			{
				currentMap[i].push_back(0);
				lastMap[i].push_back(0);
			}
		}
	}
	void Print()
	{
		for (auto y : currentMap)
		{
			for (auto x : y)
			{
				printf("%d", x);
				//wprintf(L"%lc",j);
			}
			printf("\n");
		}
	}
	void CopyCurrentMap() 
	{
		for (int y = 0; y < YSIZE; y++)
		{
			for (int x = 0; x < XSIZE; x++)
			{
				lastMap[y][x] = currentMap[y][x];
			}
		}
	}

	vector<Position> ModifiedMap() 
	{
		vector<Position> positions;
		for (int y = 0; y < YSIZE; y++)
		{
			for (int x = 0; x < XSIZE; x++)
			{
				if (currentMap[y][x] != lastMap[y][x]) {
					positions.push_back({ x,y });
				}
			}
		}

		return positions;

	}
};

class Hierarchy 
{
public:
	vector<Object> object;

	Object findObject(string name) {

	}
};

class Tools 
{
public:

	
	void cersorMoveTo(const int x, const int y)
	{
		COORD position = { x, y };
		static HANDLE handle;
		handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(handle, position);
	}
	void backCersor() {
		cersorMoveTo(0, 0);
	}

};



int main() 
{

	const int XSIZE = 20;
	const int YSIZE = 20;

	Hierarchy hierarchy;

	Tools tool;
	Map map;

	map.Initialization(XSIZE, YSIZE);
	map.Print();

	int i = 0;

	while (true)
	{
		map.CopyCurrentMap();


		//change current Map if input or prosses
		map.currentMap[2][5] = 10;


		vector<Position> v = map.ModifiedMap();

		for (auto i : v)
		{
			tool.cersorMoveTo(i.x, i.y);
			printf("%d", map.currentMap[i.y][i.x]);
		}

		tool.backCersor();
	}

	return 0;
	
}