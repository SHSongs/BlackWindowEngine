#pragma once

#include<iostream>
#include<vector>
#include <Windows.h>
#include<chrono>

#include "SceneLifeCycle.h"

class Tools
{
public:

	void cersorMoveTo(Position p)
	{
		COORD position = { p.x, p.y };
		static HANDLE handle;
		handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(handle, position);
	}
	void backCersor() {
		cersorMoveTo({ 0, 0 });
	}

};