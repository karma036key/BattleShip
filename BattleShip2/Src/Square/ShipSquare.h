#ifndef SHIPSQUARE_H
#define SHIPSQUARE_H
#include"SquareBase.h"

#define PI 3.14159265359

class ShipSquare :public SquareBase
{
public:
	ShipSquare();
	virtual ~ShipSquare();

	void Exec();
	virtual void Draw(int init_x, int init_y,ShipID ship)const;

	void DetectShipArea();
//	void ConvertIsDrag();


	int GetDragPosXForDraw(int x)const;
	int GetDragPosYForDraw(int y)const;

	void SetReleasePosXForDraw();
	void SetReleasePosYForDraw();
	int GetReleasePosXForDraw()const;
	int GetReleasePosYForDraw()const;

	int AdjustDrawPosX()const;
	int AdjustDrawPosY()const;

private:
	bool isDrag;
	bool isValid;
	int tmpPosX;
	int tmpPosY;
};

#endif