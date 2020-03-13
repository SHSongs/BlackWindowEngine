#include<iostream>
#include<vector>
#include <Windows.h>

using namespace std;

struct Position {
	int x;
	int y;
};
class Object {
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

class Map {

private:
	vector<vector<int>> map;

public:
	void mapInitialization(int XSIZE, int YSIZE)	//map initialization
	{
		for (int i = 0; i < YSIZE; i++)
		{
			vector<int> tmp;
			map.push_back(tmp);
			for (int j = 0; j < XSIZE; j++)
			{
				map[i].push_back(0);
			}
		}
	}
	void mapPrint()
	{
		for (auto i : map)
		{
			for (auto j : i)
			{
				cout << j << " ";
			}
			cout << endl;
		}
	}
};

class Hierarchy {
public:
	vector<Object> object;

	Object findObject(string name) {

	}
};

class Tools {
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



int main() {

	const int XSIZE = 20;
	const int YSIZE = 20;

	Hierarchy hierarchy;

	Tools tool;
	Map map;

	map.mapInitialization(XSIZE, YSIZE);

	

	
}