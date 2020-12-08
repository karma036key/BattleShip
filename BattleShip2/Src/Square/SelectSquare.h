#ifndef SELECTSQUARE_H
#define SELECTSQUARE_H
#include"SquareBase.h"

class SelectSquare :public SquareBase
{
public:
	SelectSquare();
	virtual ~SelectSquare();

	virtual void Draw(int origin_x,int origin_y,SquareID square)const;


private:
	bool isDrag;

};



#endif