#include"TitleScene.h"
#include"../Manager/SceneManager.h"
#include"../Manager/InputManager.h"
#include"../Manager/DrawManager.h"
#include"../Square/SelectSquare.h"
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
	DrawGraph(origin_pos_x, origin_pos_y, DrawManager::PassGraph("Src/Draw/Preparation.png"), false);

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