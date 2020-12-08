#ifndef SHIPSQUARE_H
#define SHIPSQUARE_H
#include"SquareBase.h"

#define PI 3.14159265359

class ShipSquare :public SquareBase
{
public:
	ShipSquare();
	virtual ~ShipSquare();

	virtual void Draw(int origin_x, int origin_y,SquareID square)const;
	void DetectDragForClick();
//	void ConvertIsDrag();

private:
	bool isDrag;
};

#endif