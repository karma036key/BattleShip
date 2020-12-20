#include"PreparationScene.h"
#include"../Manager/SceneManager.h"
#include"../Manager/InputManager.h"
#include"../Manager/DrawManager.h"
#include"DxLib.h"

#include"../Square/SelectSquare.h"
#include"../Square/ShipSquare.h"


PreparationScene::PreparationScene()
	:origin_pos_x{ 0 }
	, origin_pos_y{ 0 }
	, offset_x{ 128 }
	, offset_y{ 64 }
	,isTouch{false}
	,pDataMng{DataManager::GetInstance()}
	, p_square{ nullptr }
	,p_ship{nullptr}
{
	for (int i = 0; i < count_height; i++)
	{
		for (int j = 0; j < count_width; j++)
		{
			p_square[i][j] = new SelectSquare();
		}
	}
	for (int i = 0; i < 7; i++)
	{
		p_ship[i] = new ShipSquare();
	}
	p_ship[0]->SetInit(167, 53, ShipID::SHIP2);
	p_ship[1]->SetInit(233, 53, ShipID::SHIP2);
}

PreparationScene::~PreparationScene()
{
	pDataMng->ReceiveData1(*p_ship[0]);
	pDataMng->ReceiveData2(*p_ship[1]);
	for (int i = 0; i < count_height; i++)
	{
		for (int j = 0; j < count_width; j++)
		{
			delete p_square[i][j];
			p_square[i][j] = nullptr;
		}
	}
	for (int i = 0; i < 7; i++)
	{
		delete p_ship[i];
		p_ship[i] = nullptr;
	}
}


void PreparationScene::Exec()
{
	DetectClickForTrans();

			//if(p_square[i][j]->DetectDragArea(101 + j * 33, 101 + i * 33)&&Input::GetLogType()== MOUSE_INPUT_LOG_DOWN)
			//p_square[i][j]->ConvertIsDrag();
	if (isTouch) {
		p_ship[0]->Exec();
		p_ship[1]->Exec();

		for (int i = 0; i < 2; i++)
		{
			if (p_ship[i]->GetIsDrag())
			{	continue;	}

			Input::SetReleaseMousePosX(0);
			Input::SetReleaseMousePosY(0);

		}
	}
	
	if (isTrans)
	{
		isEnd = true;
		SceneManager::SetNextScene(SceneID::InGame);
	}

}

void PreparationScene::Draw()
{
	DrawManager::DrawFrame();
	p_ship[0]->Draw();
	p_ship[1]->Draw();/*
	p_ship[2]->Draw(167, 53, ShipID::SHIP4);
	p_ship[3]->Draw(167, 53, ShipID::SHIP5);
	p_ship[4]->Draw(167, 53, ShipID::SHIP2);
	p_ship[5]->Draw(167, 53, ShipID::SHIP2);
	p_ship[6]->Draw(167, 53, ShipID::SHIP2);*/
	DrawGraph(origin_pos_x, origin_pos_y, DrawManager::PassGHandle("Src/Draw/InGame.png"), false);

}


bool PreparationScene::DecideEnd()const
{


	return isEnd;

}

void PreparationScene::DetectClickForTrans()
{
	if (Input::NotifyOfClick()) {

		if ((origin_pos_x<Input::GetMousePosX() && (origin_pos_x + offset_x)>Input::GetMousePosX())
			&& (origin_pos_y<Input::GetMousePosY() && (origin_pos_y + offset_y)>Input::GetMousePosY()))
		{
			isTrans = true;
		}
		else
			isTouch = true;
	}

}