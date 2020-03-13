#include<iostream>
#include<vector>
#include <Windows.h>

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
	vector<vector<int>> currentMap;

public:

	Map()
	{
		this->XSIZE = 20;
		this->YSIZE = 20;
		for (int i = 0; i < YSIZE; i++)		//for 바꾸기
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
	Map(int XSIZE, int YSIZE)	//map initialization
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
				cout << x;
			}
			cout << endl;
		}
	}
	void CopyCurrentMap() 
	{
		lastMap = currentMap;
	}

	vector<Position> ModifiedMap() 
	{
		vector<Position> positions;
		for (int y = 0; y < YSIZE; y++)		//바꾸기
		{
			for (int x = 0; x < XSIZE; x++)
			{
				if (currentMap[y][x] != lastMap[y][x]) 
					positions.push_back({ x,y });
			}
		}

		return positions;
	}
};

class Hierarchy 
{
private:
	vector<Object> object;

public:
	// 객체 추가
	
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
	// class 로 만들기
	// class 로 만들기
	Hierarchy hierarchy;		

	Tools tool;
	Map map = Map();
	map.Print();


	while (true)		
	{
		map.CopyCurrentMap();

		//change current Map if input or prosses
		

		vector<Position> v = map.ModifiedMap();

		for (auto i : v)	
			tool.cersorMoveTo(i.x, i.y);

		tool.backCersor();
	}
	return 0;
}