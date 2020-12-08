#include"ShipSquare.h"
#include"../Manager/InputManager.h"
#include"../Manager/DrawManager.h"
#include"DxLib.h"


ShipSquare::ShipSquare()
	:isDrag{false}
{



}




ShipSquare::~ShipSquare()
{



}




void ShipSquare::Draw(int origin_x, int origin_y,SquareID square)const
{
	if (Input::DetectDrag()) {
			DrawRotaGraph(Input::GetDragMousePosX()-(Input::GetClickMousePosX()-origin_x), Input::GetDragMousePosY()-( Input::GetClickMousePosY()-origin_y), 1.0,0,DrawManager::PassGHandle("Src/Draw/2ship.png"), false);
	}
	else {

			DrawRotaGraph(origin_x, origin_y,1.0,0, DrawManager::PassGHandle("Src/Draw/2ship.png"),  false);
		
	}
}

void ShipSquare::DetectDragForClick()
{



}

//void ShipSquare::ConvertIsDrag()
//{
//	Input::DetectDrag(isDrag);
//
//}

















