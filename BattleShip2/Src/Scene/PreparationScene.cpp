#include"PreparationScene.h"
#include"../Manager/SceneManager.h"
#include"../Manager/InputManager.h"
#include"../Manager/DrawManager.h"
#include"DxLib.h"




PreparationScene::PreparationScene()
	:origin_pos_x{ 0 }
	, origin_pos_y{ 0 }
	, offset_x{ 128 }
	, offset_y{ 64 }
{


}

PreparationScene::~PreparationScene()
{



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
	Draw::DrawFrame();
	Draw::DrawSquare(101, 101, SquareID::OFF);
	Draw::DrawSquare(134, 134, SquareID::HIT);
	LoadGraphScreen(origin_pos_x, origin_pos_y, "Src/InGame.png", false);

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