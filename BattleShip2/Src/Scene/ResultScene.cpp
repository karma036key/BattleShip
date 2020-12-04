#include"ResultScene.h"
#include"../Manager/SceneManager.h"
#include"../Manager/InputManager.h"
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
//	if (ResultScene::DetectEndArea())
		SceneManager::SetNextScene(SceneID::Title);



}

void ResultScene::Draw()
{

	LoadGraphScreen(origin_pos_x, origin_pos_y, "Src/Title.png", false);

}


bool ResultScene::DecideEnd()const
{


	return ResultScene::DetectEndArea();


}


bool ResultScene::DetectEndArea()const
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