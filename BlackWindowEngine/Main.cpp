#include<iostream>
#include<vector>
#include <Windows.h>
#include<chrono>

#include "Position.h"
#include "Map.h"
#include "LifeCycle.h"
#include "Object.h"
#include "WorldOutliner.h"
#include "Time.h"

using namespace std;







int main() 
{

	// class 로 만들기
	WorldOutliner WorldOutliner;
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