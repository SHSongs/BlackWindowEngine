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

class Time
{
private:
	LARGE_INTEGER start, end, f;
	unsigned int fps = 0;
	float elapsed_time = 0;
public:
	float deltaTime = 0;

	void StartMeasure() 
	{
		fps++;
		QueryPerformanceFrequency(&f);
		QueryPerformanceCounter(&start);
	}
	void EndMeasure() 
	{
		elapsed_time += deltaTime;
		Sleep(100);		
		QueryPerformanceCounter(&end);
		deltaTime = (end.QuadPart - start.QuadPart) / (float)f.QuadPart;
	}
};

class Game
{
public:
	Game() {};
	virtual void Create() = 0;			//Called when the Application is first created.
	virtual void Render(float dt) = 0;
	virtual void Resize(int x, int y) = 0;
	virtual void Input(float dt) = 0;	
	virtual void Pause() = 0;			//Stop Game
	virtual ~Game() {};				//Called when this Game should release all resources.
};
int main() 
{

	// class 로 만들기
	Hierarchy hierarchy;		
	Time time;
	Tools tool;
	Map map = Map();
	map.Print();


	bool i = true;


	while (true)
	{
		time.StartMeasure();


		map.CopyCurrentMap();
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


		time.EndMeasure();
	}


	return 0;
}