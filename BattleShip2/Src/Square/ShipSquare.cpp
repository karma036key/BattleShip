#include"ShipSquare.h"
#include"../Manager/InputManager.h"
#include"../Manager/DrawManager.h"
#include"DxLib.h"


ShipSquare::ShipSquare()
	:isDrag{false}
	, tmpPosX{167}
	, tmpPosY{53}
{


}




ShipSquare::~ShipSquare()
{



}

void ShipSquare::Exec()
{
	if ((150 < Input::GetMousePosX() && Input::GetMousePosX() < 150 + (33 * 10)) && (20 < Input::GetMousePosY() && Input::GetMousePosY() < 20 + (33 * 10)))
	{
		isDrag = true;
		DetectShipArea();
		if (Input::NotifyOfDrag) {
			SetReleasePosXForDraw();
			SetReleasePosYForDraw();
		}
	}
	else
	{
		isDrag = false;
		Input::SetReleaseMousePosX(0);
		Input::SetReleaseMousePosY(0);
	}

}


void ShipSquare::Draw(int init_x, int init_y,ShipID ship)const
{
	if (isDrag) {
		switch (ship)
		{
		case ShipID::SHIP2:
			if (Input::NotifyOfDrag()) {
				DrawRotaGraph(GetDragPosXForDraw(GetReleasePosXForDraw()), GetDragPosYForDraw(GetReleasePosYForDraw()), 1.0, 0, DrawManager::PassGHandle("Src/Draw/2ship.png"), false);
			}
			else {
				DrawRotaGraph(GetReleasePosXForDraw(), GetReleasePosYForDraw(), 1.0, 0, DrawManager::PassGHandle("Src/Draw/2ship.png"), false);
			}
			break;
		case ShipID::SHIP3:
			break;

		case ShipID::SHIP4:
			break;


		case ShipID::SHIP5:
			break;


		}
	}
	else
	{
		switch (ship)
		{
		case ShipID::SHIP2:
			//if (Input::NotifyOfDrag()) {
			//	DrawRotaGraph(GetDrawDragPosX(init_x), GetDrawDragPosY(init_y), 1.0, 0, DrawManager::PassGHandle("Src/Draw/2ship.png"), false);
			//}
			//else {
				DrawRotaGraph(tmpPosX, tmpPosY, 1.0, 0, DrawManager::PassGHandle("Src/Draw/2ship.png"), false);
			//}
			break;
		case ShipID::SHIP3:
			break;

		case ShipID::SHIP4:
			break;


		case ShipID::SHIP5:
			break;


		}
	}
}

void ShipSquare::DetectShipArea()
{

}

//void ShipSquare::DetectClickForDrag()
//{
//	if (Input::GetLogType() == MOUSE_INPUT_LOG_UP)
//		isDrag = true;
//
//
//}

//void ShipSquare::ConvertIsDrag()
//{
//	Input::DetectDrag(isDrag);
//
//}




int ShipSquare::GetDragPosXForDraw(int x)const
{
	return (Input::GetDragMousePosX() - (Input::GetClickMousePosX() - x));
}

int ShipSquare::GetDragPosYForDraw(int y)const
{
	return (Input::GetDragMousePosY() - (Input::GetClickMousePosY() - y));
}


void ShipSquare::SetReleasePosXForDraw()
{
	for (int i = 0; i < 10; i++)
	{
		if ((150 + i * 33 < Input::GetReleaseMousePosX()&& Input::GetReleaseMousePosX()< 150 + (i + 1) * 33)&&(20<Input::GetReleaseMousePosY() <540))
			tmpPosX = (150 + (17 + (i *33)));
	}
}

void ShipSquare::SetReleasePosYForDraw()
{
	for (int i = 0; i < 9; i++)
	{
		if ((20 + i * 33 < Input::GetReleaseMousePosY() && Input::GetReleaseMousePosY() < 20 + (i + 1) * 33)&&(150<Input::GetReleaseMousePosX() <502))
			tmpPosY = (20 + (33 + (i *33)));
	}
}

int ShipSquare::GetReleasePosXForDraw()const
{
	return tmpPosX;


}

int ShipSquare::GetReleasePosYForDraw()const
{
	return tmpPosY;


}


int ShipSquare::AdjustDrawPosX()const
{

	return (Input::GetClickMousePosX() - tmpPosX);
}

int ShipSquare::AdjustDrawPosY()const
{
	return (Input::GetClickMousePosY() - tmpPosY);


}