#include"PreparationScene.h"
#include"../Manager/SceneManager.h"
#include"../Manager/InputManager.h"
#include"../Manager/DrawManager.h"
#include"DxLib.h"

#include"../Square/SelectSquare.h"


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
}


void PreparationScene::Exec()
{


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