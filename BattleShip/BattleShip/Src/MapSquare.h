#ifndef MAPSQUARE_H
#define MAPSQUARE_H

#include "DxLib.h"
#include"TranslateScene.h"

class Square
{
public:
	Square();
	virtual ~Square();

public:
	int GetOriginPosX()const;
	int GetOriginPosY()const;
	int GetCountW()const;
	int GetCountH()const;
	int GetSizeW()const;
	int GetSizeH()const;
	virtual void DrawSquare(int x, int y) = 0;
	void DrawFrame()const;
	void DrawBackGround()const;

protected:
	int origin_pos_x;
	int origin_pos_y;
	int count_width;
	int count_height;
	int size_width;
	int size_height;
};

class OnTheShip :public Square
{
public:





private:
	


};





#endif