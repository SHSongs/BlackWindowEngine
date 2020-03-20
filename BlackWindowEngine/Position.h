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

	static bool IsEqual(FPosition m, FPosition o)
	{
		Position me = FPtoIP(m);
		Position other = FPtoIP(o);

		if ((me.x == other.x) && (me.y == other.y))
			return true;
		else
			return false;
		
	}
	
};