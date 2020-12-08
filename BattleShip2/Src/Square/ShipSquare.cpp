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
			LoadGraphScreen(Input::GetDragMousePosX(), Input::GetDragMousePosY(), "Src/Draw/off.png", false);
		
	}
	else {

			LoadGraphScreen(origin_x, origin_y, "Src/Draw/off.png", false); 

		
	}
}



void ShipSquare::ConvertIsDrag()
{
	Input::DetectDrag(isDrag);

}

















