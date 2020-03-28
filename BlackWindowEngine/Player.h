#pragma once
#include "conio.h"
#include "windows.h"
#include "Object.h"
#include "Tools.h"
#include "WorldOutliner.h"

#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 


class Player : public Object {
private:

public:
string w;
	Player() {

	}
	Player(FPosition p, string name, string shape) : Object(p, name, shape)
	{

	}

	void Work() // 랜더 안에서 돌아가는 Work
	{
		Control();
	}

	void Control() {
		static int start = 0;
		int pressed_key; // 무슨 키가 눌렸는지


		if (start == 0) { // 처음 시작할때만 설정해주기 위해서

			Move("↑", false);
			start = 1; // 처음 시작할때만 설정해주기 위해서
		}

		else if (_kbhit()) { // 만약 키가 눌렸다면 
			pressed_key = _getch(); //무슨 키인지 입력
			if (pressed_key == 72 || pressed_key == 119) { // ↑(W)
				
				Move("↑", true);
			}

			if (pressed_key == 75 || pressed_key == 97) { // ←(A)

				Move("←", true);
			}

			if (pressed_key == 80 || pressed_key == 115) { // ↓(S)

				Move("↓", true);
			}

			if (pressed_key == 77 || pressed_key == 100) { // →(D)
	
				Move("→", true);
			}


			if (pressed_key == 32)
			{
				WorldOutliner::AddObject(new Canon(GetPosition(), "canon2", "●", "○", Area({ 1,1 }), 1));
			}

		}

	}
	void Move(string w, bool ifGo) {
		this->w = w;
		if (ifGo == true) {
			//StrCh(player_x, player_y, "  ");
			if (w == "↑")
				Translate({ 0, -1 }, w);
			if (w == "←")
				Translate({ -1, 0 }, w);
			if (w == "↓")
				Translate({ 0, +1 }, w);
			if (w == "→")
				Translate({ +1, 0 }, w);

			//textcolor(LIGHTBLUE, BLACK);
			//StrCh(player_x, player_y, w);
			//textcolor(WHITE, BLACK);
		}
		else {
			//textcolor(LIGHTBLUE, BLACK);
			Translate({0, 0}, w);
			
			//textcolor(WHITE, BLACK);
		}

	}

	void textcolor(int foreground, int background)
	{
		int color = foreground + background * 16;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	}
	void gotoxy(int x, int y) {
		COORD posXY = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posXY);
	}

	virtual void OnCollision(Object* other)
	{
		Object* o = WorldOutliner::FindObject("canon1");
		o->SetShape("ac");
		
		if (w == "↑")
			Translate({ 0, +1 }, w);
		if (w == "←")
			Translate({ +1, 0 }, w);
		if (w == "↓")
			Translate({ 0, -1 }, w);
		if (w == "→")
			Translate({ -1, 0 }, w);
	}
	string getW() {
		return w;
	}
};