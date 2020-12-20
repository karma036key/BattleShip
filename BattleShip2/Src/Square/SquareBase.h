#ifndef SQUAREBASE_H
#define SQUAREBASE_H
#include"../Definition.h"

class SquareBase
{
public:
	SquareBase();
	virtual ~SquareBase();

	virtual void Draw()const;



protected:
	SquareState  status;



};

#endif