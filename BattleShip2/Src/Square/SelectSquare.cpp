#include"SelectSquare.h"
#include"../Manager/InputManager.h"
#include"../Manager/DrawManager.h"
#include"DxLib.h"

SelectSquare::SelectSquare()
	:exa{SquareID::NONE}
{


}

SelectSquare::~SelectSquare()
{


}


void SelectSquare::Draw(int origin_x, int origin_y)const
{
	switch (exa)
	{
	case SquareID::OFF:
		DrawGraph(origin_x, origin_y, DrawManager::PassGHandle("Src/Draw/off.png"), false); break;
		break;
	case SquareID::HIT:
		DrawGraph(origin_x, origin_y, DrawManager::PassGHandle("Src/Draw/hit.png"), false); break;
		break;
	case SquareID::NONE:
		DrawGraph(origin_x, origin_y, DrawManager::PassGHandle("Src/Draw/none.png"), false); break;
		break;
	}
}


void SelectSquare::ChangeSquareTarget()
{
	exa = SquareID::HIT;
}


