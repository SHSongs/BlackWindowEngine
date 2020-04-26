#pragma once
#include "Canon.h"
#include "conio.h"
#include "Object.h"
#include "WorldOutliner.h"
#include "PushTrap.h"

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
	std::string w;
	Player() {

	}
	Player(FPosition p, std::string name, std::string shape, std::string Type) : Object(p, name, shape, Type)
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
				Object* o = WorldOutliner::FindObject("Player");

				Shot(o->GetShape());
				//WorldOutliner::AddObject(new Canon(GetPosition(), "canon2", "●", "○", Area({ 1,1 }), "↓"));			}
			}

		}

	}
	void Move(std::string w, bool ifGo) {
		this->w = w;
		if (ifGo == true) {
			if (w == "↑")
				Translate({ 0, -1 }, w);
			if (w == "←")
				Translate({ -1, 0 }, w);
			if (w == "↓")
				Translate({ 0, +1 }, w);
			if (w == "→")
				Translate({ +1, 0 }, w);
		}
		else {
			Translate({0, 0}, w);
		}

	}

	void Shot(std::string D) {

		if (D == "↑")
		{
			WorldOutliner::AddObject(new Canon({ GetPosition().x , GetPosition().y - 1 }, "canon2", "▲", "△", Area({ 1,1 }), "↑", "Canon"));
		}
		if (D == "↓")
		{
			WorldOutliner::AddObject(new Canon({ GetPosition().x , GetPosition().y + 1 }, "canon2", "▼", "▽", Area({ 1,1 }), "↓", "Canon"));
		}

		if (D == "←")
		{
			WorldOutliner::AddObject(new Canon({ GetPosition().x - 1 , GetPosition().y }, "canon2", "◀", "◁", Area({ 1,1 }), "←", "Canon"));
		}
		if (D == "→")
		{
			WorldOutliner::AddObject(new Canon({ GetPosition().x +1 , GetPosition().y}, "canon2", "▶", "▷", Area({ 1,1 }), "→", "Canon"));
		}
	}

	virtual void OnCollision(Object* other)
	{
		/*Object* o = WorldOutliner::FindObject("canon1");
		o->SetShape("ac");*/
		
		
		/*if (dynamic_cast<Canon*>(other))
			other->SetShape("ac");*/

		//if (dynamic_cast<PushTrap*>(other))
			//Move(w, true);
		if (other->getType() == "Wall")
		{
			if (w == "↑")
				Translate({ 0, +1 }, w);
			else if (w == "←")
				Translate({ +1, 0 }, w);
			else if (w == "↓")
				Translate({ 0, -1 }, w);
			else if (w == "→")
				Translate({ -1, 0 }, w);
		}
		else {
			std::string D = other->getDirection();
			if (D == "↑")
				Translate({ 0, -1 }, D);
			else if (D == "←")
				Translate({ -1, 0 }, D);
			else if (D == "↓")
				Translate({ 0, +1 }, D);
			else if (D == "→")
				Translate({ +1, 0 }, D);
		}
	}

	std::string getW() {
		return w;
	}
};