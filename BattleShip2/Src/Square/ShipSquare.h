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
	virtual void Draw()const;

	void DetectShipArea();
//	void ConvertIsDrag();

	int GetCenterPosX()const;
	int GetCenterPosY()const;
	void SetInit(int x, int y, ShipID i);
	void SetIsHold(bool isTouch);
	bool GetIsHold()const;

private:
	bool isDrag;
	bool isValid;
	bool isHold;
	int tmpPosX;
	int tmpPosY;
	ShipID ship_id;

	int GetDragPosXForDraw(int x)const;
	int GetDragPosYForDraw(int y)const;

	void SetCenterPosX();
	void SetCenterPosY();

	bool GetIsDrag();

	//int GetDragPosXForDraw2(int x)const;
	//int GetDragPosYForDraw2(int y)const;
	//void SetReleasePosXForDraw2();
	//void SetReleasePosYForDraw2();
	//int GetReleasePosXForDraw2()const;
	//int GetReleasePosYForDraw2()const;



};

#endif