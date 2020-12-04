#include"InGameScene.h"
#include"../Manager/SceneManager.h"
#include"../Manager/InputManager.h"
#include"../Manager/DrawManager.h"
#include"DxLib.h"

InGameScene::InGameScene()
	:origin_pos_x{ 0 }
	, origin_pos_y{ 0 }
	, offset_x{ 128 }
	, offset_y{ 64 }
{


}

InGameScene::~InGameScene()
{



}


void InGameScene::Exec()
{


//	if (InGameScene::DetectEndArea())
		SceneManager::SetNextScene(SceneID::Result);


}

void InGameScene::Draw()
{
	Draw::DrawFrame();
	LoadGraphScreen(origin_pos_x, origin_pos_y, "Src/Result.png", false);

}


bool InGameScene::DecideEnd()const
{
	return InGameScene::DetectEndArea();



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




