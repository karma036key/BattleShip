#include"DrawManager.h"
#include"DxLib.h"
Draw::Draw()
{



}




Draw::~Draw()
{


}




void Draw::DrawFrame()
{

	const int left = 100;
	const int right = 100 + (33 * 10);
	const int top = 100;
	const int bottom = 100 + (33 * 10);
	for (int i = 0; i <= 10; i++)
	{
		DrawLine(left + i * 33, top, left + i * 33, bottom, GetColor(0xFF, 0xFF, 0xFF));
	}
	for (int i = 0; i <= 10; i++)
	{
		DrawLine(left, top + i * 33, right, top + i * 33, GetColor(0xFF, 0xFF, 0xFF));
	}

}

void Draw::DrawSquare(int pos_x, int pos_y, SquareID square)
{
	switch (square)
	{
	case SquareID::OFF:
		LoadGraphScreen(pos_x, pos_y, "Src/off.png", false); break;
	case SquareID::HIT:
		LoadGraphScreen(pos_x, pos_y, "Src/hit.png", false); break;
	}


}