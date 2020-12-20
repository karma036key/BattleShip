#include"ShipSquare.h"
#include"../Manager/InputManager.h"
#include"../Manager/DrawManager.h"
#include"DxLib.h"


ShipSquare::ShipSquare()
	:isDrag{false}
	,isValid{false}
	, tmpPosX{0}
	, tmpPosY{0}
	,ship_id{ShipID::SHIP2}
{


}




ShipSquare::~ShipSquare()
{



}

void ShipSquare::Exec()
{
	if ((150 < Input::GetMousePosX() && Input::GetMousePosX() < 150 + (33 * 10)) && (20 < Input::GetMousePosY() && Input::GetMousePosY() < 20 + (33 * 10))					//cursor‚ª˜g“à‚É‚ ‚é‚©
		&&((GetDragPosXForDraw(GetCenterPosX())-16)<Input::GetDragMousePosX()&&Input::GetDragMousePosX()< GetDragPosXForDraw(GetCenterPosX())+16)&&			//‰æ‘œ‚Ì‰¡•“à‚É‚ ‚é‚©
		((GetDragPosYForDraw(GetCenterPosY()) - 32) < Input::GetDragMousePosY() && Input::GetDragMousePosY() < GetDragPosYForDraw(GetCenterPosY()) + 32))	//‰æ‘œ‚Ìc•“à‚É‚ ‚é‚©
	{
		isDrag = true;
		DetectShipArea();
		//if (Input::NotifyOfDrag()) {
			SetCenterPosX();
			SetCenterPosY();
		//}
	}
	else
	{
		isDrag = false;
		
	}

	//if ((150 < Input::GetMousePosX() && Input::GetMousePosX() < 150 + (33 * 10)) && (20 < Input::GetMousePosY() && Input::GetMousePosY() < 20 + (33 * 10))
	//	&& ((GetDragPosXForDraw2(GetReleasePosXForDraw2()) - 16) < Input::GetDragMousePosX() && Input::GetDragMousePosX() < GetDragPosXForDraw2(GetReleasePosXForDraw2()) + 16) &&
	//	((GetDragPosYForDraw2(GetReleasePosYForDraw2()) - 32) < Input::GetDragMousePosY() && Input::GetDragMousePosY() < GetDragPosYForDraw2(GetReleasePosYForDraw2()) + 32))
	//{
	//	isDrag = true;
	//	DetectShipArea();
	//	if (Input::NotifyOfDrag()) {
	//		SetReleasePosXForDraw2();
	//		SetReleasePosYForDraw2();
	//	}
	//}
	//else
	//{
	//	isDrag = false;
	//	Input::SetReleaseMousePosX(0);
	//	Input::SetReleaseMousePosY(0);
	//}

}


void ShipSquare::Draw()const
{
	if (isDrag) {
		switch (ship_id)
		{
		case ShipID::SHIP2:
			if (Input::NotifyOfDrag()) {
				DrawRotaGraph(GetDragPosXForDraw(GetCenterPosX()), GetDragPosYForDraw(GetCenterPosY()), 1.0, 0, DrawManager::PassGHandle("Src/Draw/2ship.png"), false);
			}
			else {
				DrawRotaGraph(GetCenterPosX(), GetCenterPosY(), 1.0, 0, DrawManager::PassGHandle("Src/Draw/2ship.png"), false);
			}
			break;
		case ShipID::SHIP3:
			//if (Input::NotifyOfDrag()) {
			//	DrawRotaGraph(GetDragPosXForDraw2(GetReleasePosXForDraw2()), GetDragPosYForDraw2(GetReleasePosYForDraw2()), 1.0, 0, DrawManager::PassGHandle("Src/Draw/2ship.png"), false);
			//}
			//else {
			//	DrawRotaGraph(GetReleasePosXForDraw2(), GetReleasePosYForDraw2(), 1.0, 0, DrawManager::PassGHandle("Src/Draw/2ship.png"), false);
			//}
			break;
			break;

		case ShipID::SHIP4:
			break;


		case ShipID::SHIP5:
			break;


		}
	}
	else
	{
		switch (ship_id)
		{
		case ShipID::SHIP2:
			//if (Input::NotifyOfDrag()) {
			//	DrawRotaGraph(GetDrawDragPosX(init_x), GetDrawDragPosY(init_y), 1.0, 0, DrawManager::PassGHandle("Src/Draw/2ship.png"), false);
			//}
			//else {
				DrawRotaGraph(GetCenterPosX(), GetCenterPosY(), 1.0, 0, DrawManager::PassGHandle("Src/Draw/2ship.png"), false);
			//}
			break;
		case ShipID::SHIP3:
	//		DrawRotaGraph(GetReleasePosXForDraw2(), GetReleasePosYForDraw2(), 1.0, 0, DrawManager::PassGHandle("Src/Draw/2ship.png"), false);
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
	//if (((tmpPosX - 12) < Input::GetMousePosX() && Input::GetMousePosX() < (tmpPosX + 12)) && ((tmpPosY - 32) < Input::GetMousePosY() && Input::GetMousePosY() < (tmpPosY + 32)))
	//	isValid = true;
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


void ShipSquare::SetCenterPosX()
{
	for (int i = 0; i < 10; i++)
	{
		if (((150 + i * 33) < Input::GetReleaseMousePosX()&& Input::GetReleaseMousePosX()< (150 + (i + 1) * 33))&&(20<Input::GetReleaseMousePosY()&& Input::GetReleaseMousePosY() <350))
			tmpPosX = (150 + (17 + (i *33)));
	}
}

void ShipSquare::SetCenterPosY()
{
	for (int i = 0; i < 9; i++)
	{
		if (((20 + i * 33 )< Input::GetReleaseMousePosY() && Input::GetReleaseMousePosY() < (20 + (i + 1) * 33))&&(150<Input::GetReleaseMousePosX()&& Input::GetReleaseMousePosX() <480))
			tmpPosY = (20 + (33 + (i *33)));
	}
}

int ShipSquare::GetCenterPosX()const
{
	return tmpPosX;


}

int ShipSquare::GetCenterPosY()const
{
	return tmpPosY;


}


//
//int ShipSquare::GetDragPosXForDraw2(int x)const
//{
//	return (Input::GetDragMousePosX() - (Input::GetClickMousePosX() - x));
//}
//
//int ShipSquare::GetDragPosYForDraw2(int y)const
//{
//	return (Input::GetDragMousePosY() - (Input::GetClickMousePosY() - y));
//}
//
//
//void ShipSquare::SetReleasePosXForDraw2()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		if ((150 + i * 33 < Input::GetReleaseMousePosX() && Input::GetReleaseMousePosX() < 150 + (i + 1) * 33) && (20 < Input::GetReleaseMousePosY()&& Input::GetReleaseMousePosY() < 540))
//			tmpPosX2 = (150 + (17 + (i * 33)));
//	}
//}
//
//void ShipSquare::SetReleasePosYForDraw2()
//{
//	for (int i = 0; i < 9; i++)
//	{
//		if ((20 + i * 33 < Input::GetReleaseMousePosY() && Input::GetReleaseMousePosY() < 20 + (i + 1) * 33) && (150 < Input::GetReleaseMousePosX() && Input::GetReleaseMousePosX() < 502))
//			tmpPosY2 = (20 + (33 + (i * 33)));
//	}
//}
//
//int ShipSquare::GetReleasePosXForDraw2()const
//{
//	return tmpPosX2;
//
//
//}
//
//int ShipSquare::GetReleasePosYForDraw2()const
//{
//	return tmpPosY2;
//
//
//}


void ShipSquare::SetInit(int x,int y,ShipID id)
{
	tmpPosX = x;
	tmpPosY = y;
	ship_id = id;

}

bool ShipSquare::GetIsDrag()
{
	return isDrag;
}