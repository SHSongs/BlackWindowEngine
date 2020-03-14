#include<iostream>
#include<vector>
#include <Windows.h>
#include<chrono>


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
		for (int y = 0; y < YSIZE; y++)		//바꾸기
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

class Hierarchy 
{
private:
	vector<Object> object;

public:
	// add Obgect
	
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
		cersorMoveTo(0,0);
	}

};



int main() 
{

	// class 로 만들기
	Hierarchy hierarchy;		

	Tools tool;
	Map map = Map();
	map.Print();


	bool i = true;


	while (true)
	{

		map.CopyCurrentMap();

		//change current Map if input or prosses
		if (i) {
			map.SetPartOfMap(5, 10, 2);
			i = false;
		}
		else {
			map.SetPartOfMap(5, 10, 0);
			i = true;
		}

		vector<Position> v = map.ModifiedMap();

		for (auto i : v)
		{
			tool.cersorMoveTo(i.x, i.y);
			cout << map.GetPartOfMap(i.x, i.y);
		}
		tool.backCersor();


	}


	return 0;
}