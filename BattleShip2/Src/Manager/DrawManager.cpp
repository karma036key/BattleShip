#include"DrawManager.h"
#include"DxLib.h"

int DrawManager::Handle_Title;
int DrawManager::Handle_Preparation;
int DrawManager::Handle_InGame;
int DrawManager::Handle_Result;
int DrawManager::Handle_NONE;
int DrawManager::Handle_HIT;
int DrawManager::Handle_OFF;
int DrawManager::Handle_SHIP2;
int DrawManager::Handle_SHIP3;
int DrawManager::Handle_SHIP4;
int DrawManager::Handle_SHIP5;

DrawManager::DrawManager()
{



}




DrawManager::~DrawManager()
{


}




void DrawManager::DrawFrame()
{

	const int left = 150;
	const int right = 150 + (33 * 10);
	const int top = 20;
	const int bottom = 20 + (33 * 10);
	for (int i = 0; i <= 10; i++)
	{
		DrawLine(left + i * 33, top, left + i * 33, bottom, GetColor(0xFF, 0xFF, 0xFF));
	}
	for (int i = 0; i <= 10; i++)
	{
		DrawLine(left, top + i * 33, right, top + i * 33, GetColor(0xFF, 0xFF, 0xFF));
	}

}




void DrawManager::DrawFade()
{


}

void DrawManager::LoadAllGraph()
{
	Handle_Title = LoadGraph("Src/Draw/Title.png");
	Handle_Preparation = LoadGraph("Src/Draw/Preparation.png");	
	Handle_InGame = LoadGraph("Src/Draw/InGame.png");
	Handle_Result = LoadGraph("Src/Draw/Result.png");
	Handle_NONE = LoadGraph("Src/Draw/none.png");
	Handle_HIT = LoadGraph("Src/Draw/hit.png");
	Handle_OFF = LoadGraph("Src/Draw/off.png");
	Handle_SHIP2 = LoadGraph("Src/Draw/2ship.png");
	Handle_SHIP3 = LoadGraph("Src/Draw/3ship.png");
	Handle_SHIP4 = LoadGraph("Src/Draw/4ship.png");
	Handle_SHIP5 = LoadGraph("Src/Draw/5ship.png");
}



void DrawManager::DeleteAllGraph()
{
	DeleteGraph(Handle_Title);
	DeleteGraph(Handle_Preparation);
	DeleteGraph(Handle_InGame);
	DeleteGraph(Handle_Result);
	DeleteGraph(Handle_NONE);
	DeleteGraph(Handle_HIT);
	DeleteGraph(Handle_OFF);
	DeleteGraph(Handle_SHIP2);
	DeleteGraph(Handle_SHIP3);
	DeleteGraph(Handle_SHIP4);
	DeleteGraph(Handle_SHIP5);
}



int DrawManager::PassGraph(const char* filename)
{
	if(filename== "Src/Draw/Title.png")
	return Handle_Title;
	if (filename == "Src/Draw/Preparation.png")
		return Handle_Preparation;
	if (filename == "Src/Draw/InGame.png")
		return Handle_InGame;
	if (filename == "Src/Draw/Result.png")
		return Handle_Result;
	if (filename == "Src/Draw/none.png")
		return Handle_NONE;
	if (filename == "Src/Draw/hit.png")
		return Handle_HIT;
	if (filename == "Src/Draw/off.png")
		return Handle_OFF;
	if (filename == "Src/Draw/2ship.png")
		return Handle_SHIP2;
	if (filename == "Src/Draw/3ship.png")
		return Handle_SHIP3;
	if (filename == "Src/Draw/4ship.png")
		return Handle_SHIP4;
	if (filename == "Src/Draw/5ship.png")
		return Handle_SHIP5;

	return 0;
}