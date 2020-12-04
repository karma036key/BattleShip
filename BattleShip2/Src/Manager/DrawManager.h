#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H
#include"../Definition.h"

class Draw
{
public:
	Draw();
	~Draw();

	static void DrawFrame();
	static void DrawSquare(int pos_x, int pos_y, SquareID square);



};





#endif