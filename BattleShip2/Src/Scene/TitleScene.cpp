#include"TitleScene.h"
#include"../Manager/SceneManager.h"
#include"../Manager/InputManager.h"
#include"DxLib.h"

TitleScene::TitleScene()
	:origin_pos_x{0}
	,origin_pos_y{0}
	,offset_x{128}
	,offset_y{64}
{


}

TitleScene::~TitleScene()
{



}


void TitleScene::Exec()
{

	if (TitleScene::DetectEndArea()) {

		isEnd = true;
		SceneManager::SetNextScene(SceneID::Preparation);
	}
}

void TitleScene::Draw()
{
	LoadGraphScreen(origin_pos_x, origin_pos_y, "Src/Preparation.png", false);

}


bool TitleScene::DecideEnd()const
{
	return isEnd;
}


bool TitleScene::DetectEndArea()const
{

	if (Input::DetectClick()) {

		if ((origin_pos_x<Input::GetMousePosX() && (origin_pos_x + offset_x)>Input::GetMousePosX())
			&& (origin_pos_y<Input::GetMousePosY() && (origin_pos_y + offset_y)>Input::GetMousePosY()))
		{

			DrawString(120, 120, "ResultScene", GetColor(0, 0, 0));

			return true; 
		}
	}
	return false;
}