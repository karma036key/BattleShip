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
	, p_square{ nullptr }
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
}

PreparationScene::~PreparationScene()
{
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
	for (int i = 0; i < count_height; i++)
	{
		for (int j = 0; j < count_width; j++)
		{
			//if(p_square[i][j]->DetectDragArea(101 + j * 33, 101 + i * 33)&&Input::GetLogType()== MOUSE_INPUT_LOG_DOWN)
			//p_square[i][j]->ConvertIsDrag();

		}
	}
	if (PreparationScene::DetectEndArea())
	{
		isEnd = true;
		SceneManager::SetNextScene(SceneID::InGame);
	}

}

void PreparationScene::Draw()
{
	DrawManager::DrawFrame();
	DrawGraph(origin_pos_x, origin_pos_y, DrawManager::PassGraph("Src/Draw/InGame.png"), false);

}


bool PreparationScene::DecideEnd()const
{


	return isEnd;

}

bool PreparationScene::DetectEndArea()const
{
	if (Input::DetectClick()) {
		if ((origin_pos_x<Input::GetMousePosX() && (origin_pos_x + offset_x)>Input::GetMousePosX())
			&& (origin_pos_y<Input::GetMousePosY() && (origin_pos_y + offset_y)>Input::GetMousePosY()))
		{


			return true;
		}
	}
	return false;
}