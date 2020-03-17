#pragma once

#include <Windows.h>


//change Static 
class Tools
{
public:

	static void cersorMoveTo(Position p)
	{
		COORD position = {(short)p.x * 2, (short)p.y};
		static HANDLE handle;
		handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(handle, position);
	}
	static void backCersor() {
		cersorMoveTo({ 0, 0 });
	}

};