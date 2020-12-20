#include"SelectSquare.h"
#include"../Manager/InputManager.h"
#include"../Manager/DrawManager.h"
#include"DxLib.h"

SelectSquare::SelectSquare()
	:exa{SquareID::NONE}
	,origin_x{0}
	,origin_y{0}
	,isChange{false}
{


}

SelectSquare::~SelectSquare()
{


}

void SelectSquare::Exec()
{



}

void SelectSquare::Draw()const
{
	switch (exa)
	{
	case SquareID::OFF:
		if (isChange) {
			DrawGraph(GetOriginX(), GetOriginY(), DrawManager::PassGHandle("Src/Draw/off.png"), false); break;
		}
		else {
			DrawGraph(GetOriginX(), GetOriginY(), DrawManager::PassGHandle("Src/Draw/none.png"), false);
		}break;
	case SquareID::HIT:
		if (isChange)
		{
			DrawGraph(GetOriginX(), GetOriginY(), DrawManager::PassGHandle("Src/Draw/hit.png"), false); break;
		}
		else
		{
			DrawGraph(GetOriginX(), GetOriginY(), DrawManager::PassGHandle("Src/Draw/none.png"), false);
		}break;
	case SquareID::NONE:
		DrawGraph(GetOriginX(), GetOriginY(), DrawManager::PassGHandle("Src/Draw/none.png"), false); break;
		break;
	}
}


void SelectSquare::ChangeSquareHit()
{
	exa = SquareID::HIT;
}
void SelectSquare::ChangeSquareOff()
{
	exa = SquareID::OFF;
}

void SelectSquare::DetectClickForSelect()
{
	if ((GetOriginX() < Input::GetClickMousePosX() && Input::GetClickMousePosX() < GetOriginX() + 32) && (GetOriginY() < Input::GetClickMousePosY() && Input::GetClickMousePosY() < GetOriginY() + 32) )//&& Input::NotifyOfDrag())
		isChange=true;


}


void SelectSquare::SetOriginX(int x)
{	origin_x = x;	}
void SelectSquare::SetOriginY(int y)
{	origin_y = y;}
int SelectSquare::GetOriginX()const
{	return origin_x;}

int SelectSquare::GetOriginY()const
{	return origin_y;}