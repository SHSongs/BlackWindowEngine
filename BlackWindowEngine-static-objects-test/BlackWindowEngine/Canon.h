#pragma once

#include "WorldOutliner.h"
#include "Object.h"
#include "MovingTrap.h"
class Canon : public Object
{
private:
	bool ch = true;
	std::string Direction;
	float speed = 0.7;
public:
	
	std::string shape2;
	Canon(FPosition p, std::string name, std::string shape, std::string shape2, Area area, std::string Direction,
	      std::string Type);

	virtual void Work();

	void Move(std::string D);

	void SwapShape();

	void DoNothing();

	virtual void OnCollision(Object* other);
};

inline Canon::Canon(FPosition p, std::string name, std::string shape, std::string shape2, Area area,
                    std::string Direction, std::string Type): Object(p, name, shape, area, Type)
{
	this->shape2 = shape2;
	this->Direction = Direction;
}

inline void Canon::Work()
{
	Move(Direction);
	SwapShape();
}

inline void Canon::Move(std::string D)
{
	if (D == "¡è")
	{
		Translate(FPosition({0, (float)(-speed)}));
	}
	else if (D == "¡é")
	{
		Translate(FPosition({0, (float)(speed)}));
	}
	else if (D == "¡ç")
	{
		Translate(FPosition({(float)(-speed), 0}));
	}
	else if (D == "¡æ")
	{
		Translate(FPosition({(float)(+speed), 0}));
	}
	else if (D == "¡Ü")
	{
		Translate(FPosition({0, 0}));
	}
}

inline void Canon::SwapShape()
{
	std::string tmp = shape;
	shape = shape2;
	shape2 = tmp;
}

inline void Canon::DoNothing()
{
}

inline void Canon::OnCollision(Object* other)
{
	//shape2 = shape;

	WorldOutliner::Destroy(this);

	if (dynamic_cast<MovingTrap*>(other))
	{
		WorldOutliner::Destroy(other);
	}
}
