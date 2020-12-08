#include"SelectSquare.h"
#include"../Manager/InputManager.h"
#include"../Manager/DrawManager.h"
#include"DxLib.h"

SelectSquare::SelectSquare()
	:isDrag{ false }
{


}

SelectSquare::~SelectSquare()
{


}


void SelectSquare::Draw(int origin_x, int origin_y, SquareID square)const
{
	switch (square)
	{
	case SquareID::OFF:
		DrawGraph(origin_x, origin_y, DrawManager::PassGraph("Src/Draw/off.png"), false); break;
		break;
	case SquareID::HIT:
		DrawGraph(origin_x, origin_y, DrawManager::PassGraph("Src/Draw/hit.png"), false); break;
		break;
	}
}





