#include"ResultScene.h"
#include"../Manager/SceneManager.h"
#include"../Manager/InputManager.h"
#include"../Manager/DrawManager.h"
#include"DxLib.h"




ResultScene::ResultScene()
	:origin_pos_x{ 0 }
	, origin_pos_y{ 0 }
	, offset_x{ 128 }
	, offset_y{ 64 }
{


}

ResultScene::~ResultScene()
{



}


void ResultScene::Exec()
{
	DetectClickArea();

	if (isTrans)
	{
		isEnd = true;
		SceneManager::SetNextScene(SceneID::Title);
	}


}

void ResultScene::Draw()
{

	DrawGraph(origin_pos_x, origin_pos_y, DrawManager::PassGHandle("Src/Draw/Title.png"), false);

}


bool ResultScene::DecideEnd()const
{


	return isEnd;


}


void ResultScene::DetectClickArea()
{

	if (Input::DetectClick()) {
		if ((origin_pos_x<Input::GetMousePosX() && (origin_pos_x + offset_x)>Input::GetMousePosX())
			&& (origin_pos_y<Input::GetMousePosY() && (origin_pos_y + offset_y)>Input::GetMousePosY()))
		{
			isTrans = true;
		}
	}
}