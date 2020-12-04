#include"InGameScene.h"
#include"../Manager/SceneManager.h"
#include"../Manager/InputManager.h"
#include"../Manager/DrawManager.h"
#include"../Square/SelectSquare.h"
#include"DxLib.h"

InGameScene::InGameScene()
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

InGameScene::~InGameScene()
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


void InGameScene::Exec()
{


	if (InGameScene::DetectEndArea())
	{
		isEnd = true;
		SceneManager::SetNextScene(SceneID::Result);
	}

}

void InGameScene::Draw()
{
	Draw::DrawFrame();
	LoadGraphScreen(origin_pos_x, origin_pos_y, "Src/Result.png", false);

}


bool InGameScene::DecideEnd()const
{
	return isEnd;



}

bool InGameScene::DetectEndArea()const
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




