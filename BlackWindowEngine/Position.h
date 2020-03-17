#pragma once


struct Position
{
	int x;
	int y;
};

struct FPosition
{
	float x;
	float y;
};

class PositionTools
{
public:
	static Position FPtoIP(FPosition fp)
	{
		return Position{ (int)(fp.x),(int)(fp.y) };
	}
};