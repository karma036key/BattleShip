#ifndef SQUAREBASE_H
#define SQUAREBASE_H
#include"../Definition.h"

class SquareBase
{
public:
	SquareBase();
	virtual ~SquareBase();

	virtual void Draw(int origin_x, int origin_y, SquareID square)const = 0;



protected:
	SquareState  status;



};

#endif