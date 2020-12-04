#ifndef SELECTSQUARE_H
#define SELECTSQUARE_H
#include"SquareBase.h"

class SelectSquare :public SquareBase
{
public:
	SelectSquare();
	~SelectSquare();

	void Draw(int origin_x,int origin_y,SquareID square);

	void Confirmation();


};



#endif