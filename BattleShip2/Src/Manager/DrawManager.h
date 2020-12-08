#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H
#include"../Definition.h"

class DrawManager
{
public:
	DrawManager();
	~DrawManager();

	static void DrawFrame();
	static void DrawFade();
	static void LoadAllGraph();
	static void DeleteAllGraph();
	static int PassGraph(const char* filename);
private:
	static int Handle_Title;
	static int Handle_Preparation;
	static int Handle_InGame;
	static int Handle_Result;
	static int Handle_NONE;
	static int Handle_HIT;
	static int Handle_OFF;
	static int Handle_SHIP2;
	static int Handle_SHIP3;
	static int Handle_SHIP4;
	static int Handle_SHIP5;
};





#endif