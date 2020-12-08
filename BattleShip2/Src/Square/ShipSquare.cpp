#include"ShipSquare.h"
#include"../Manager/InputManager.h"
#include"DxLib.h"


ShipSquare::ShipSquare()
	:isDrag{false}
{



}




ShipSquare::~ShipSquare()
{



}




void ShipSquare::Draw(int origin_x, int origin_y, SquareID square)const
{
	if (isDrag) {
		switch (square)
		{
		case SquareID::OFF:
			LoadGraphScreen(Input::GetDragMousePosX(), Input::GetDragMousePosY(), "Src/Draw/off.png", false); break;
			break;
		case SquareID::HIT:
			LoadGraphScreen(Input::GetDragMousePosX(), Input::GetDragMousePosY(), "Src/Draw/hit.png", false); break;
			break;
		}
	}
	else {
		switch (square)
		{
		case SquareID::OFF:
			LoadGraphScreen(origin_x, origin_y, "Src/Draw/off.png", false); break;
			break;
		case SquareID::HIT:
			LoadGraphScreen(origin_x, origin_y, "Src/Draw/hit.png", false); break;
			break;
		}
	}
}



void ShipSquare::ConvertIsDrag()
{
	Input::DetectDrag(isDrag);

}


bool ShipSquare::DetectDragArea(int origin_x, int origin_y)const
{
	if ((origin_x < Input::GetDragMousePosX() && Input::GetDragMousePosX() < origin_x + 32) &&
		(origin_y < Input::GetDragMousePosY() && Input::GetDragMousePosY() < origin_y + 32))
	{
		return true;
	}
	return false;
}














