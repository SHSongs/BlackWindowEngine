#pragma once
#include "conio.h"
#include "windows.h"
#include "Object.h"
#include "Tools.h"
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
string w;
	Player() {

	}
	Player(FPosition p, string name, string shape) : Object(p, name, shape)
	{

	}

	void Work() // ���� �ȿ��� ���ư��� Work
	{
		Control();
	}

	void Control() {
		static int start = 0;
		int pressed_key; // ���� Ű�� ���ȴ���


		if (start == 0) { // ó�� �����Ҷ��� �������ֱ� ���ؼ�

			Move("��", false);
			start = 1; // ó�� �����Ҷ��� �������ֱ� ���ؼ�
		}

		else if (_kbhit()) { // ���� Ű�� ���ȴٸ� 
			pressed_key = _getch(); //���� Ű���� �Է�
			if (pressed_key == 72 || pressed_key == 119) { // ��(W)
				
				Move("��", true);
			}

			if (pressed_key == 75 || pressed_key == 97) { // ��(A)

				Move("��", true);
			}

			if (pressed_key == 80 || pressed_key == 115) { // ��(S)

				Move("��", true);
			}

			if (pressed_key == 77 || pressed_key == 100) { // ��(D)
	
				Move("��", true);
			}


			if (pressed_key == 32)
			{
				Object* o = WorldOutliner::FindObject("Player");

				Shot(o->GetShape());
				//WorldOutliner::AddObject(new Canon(GetPosition(), "canon2", "��", "��", Area({ 1,1 }), "��"));			}
			}

		}

	}
	void Move(string w, bool ifGo) {
		this->w = w;
		if (ifGo == true) {
			if (w == "��")
				Translate({ 0, -1 }, w);
			if (w == "��")
				Translate({ -1, 0 }, w);
			if (w == "��")
				Translate({ 0, +1 }, w);
			if (w == "��")
				Translate({ +1, 0 }, w);
		}
		else {
			Translate({0, 0}, w);
		}

	}

	void Shot(string D) {

		if (D == "��")
		{
			WorldOutliner::AddObject(new Canon({ GetPosition().x , GetPosition().y - 1 }, "canon2", "��", "��", Area({ 1,1 }), "��"));
		}
		if (D == "��")
		{
			WorldOutliner::AddObject(new Canon({ GetPosition().x , GetPosition().y + 1 }, "canon2", "��", "��", Area({ 1,1 }), "��"));
		}

		if (D == "��")
		{
			WorldOutliner::AddObject(new Canon({ GetPosition().x - 1 , GetPosition().y }, "canon2", "��", "��", Area({ 1,1 }), "��"));
		}
		if (D == "��")
		{
			WorldOutliner::AddObject(new Canon({ GetPosition().x +1 , GetPosition().y}, "canon2", "��", "��", Area({ 1,1 }), "��"));
		}
	}

	virtual void OnCollision(Object* other)
	{
		/*Object* o = WorldOutliner::FindObject("canon1");
		o->SetShape("ac");*/
		
		
		/*if (dynamic_cast<Canon*>(other))
			other->SetShape("ac");*/

		if (dynamic_cast<PushTrap*>(other))
			//Move(w, true);
			;

		else{
			if (w == "��")
				Translate({ 0, +1 }, w);
			if (w == "��")
				Translate({ +1, 0 }, w);
			if (w == "��")
				Translate({ 0, -1 }, w);
			if (w == "��")
				Translate({ -1, 0 }, w);
		}
	}
	string getW() {
		return w;
	}
};