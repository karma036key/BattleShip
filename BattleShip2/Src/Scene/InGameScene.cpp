#include"InGameScene.h"
#include"../Manager/SceneManager.h"
#include"../Manager/InputManager.h"
#include"../Manager/DrawManager.h"
#include"../Manager/DataManager.h"
#include"../Square/SelectSquare.h"
#include"DxLib.h"


InGameScene::InGameScene()
	:origin_pos_x{ 0 }
	, origin_pos_y{ 0 }
	, offset_x{ 128 }
	, offset_y{ 64 }
	, p_square{ nullptr }
	,pDataMng{DataManager::GetInstance()}
{

	for (int i = 0; i < count_height; i++)
	{
		for (int j = 0; j < count_width; j++)
		{
			p_square[i][j] = new SelectSquare();
		}
	}
	tmp_state[0] = pDataMng->PassData1();
	tmp_state[1] = pDataMng->PassData2();
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
	DetectClickForTrans();

	for (int y = 0; y < count_height; y++)
	{
		for (int x = 0; x < count_width; x++)
		{
			p_square[y][x]->SetOriginX(151 + x * 33);
			p_square[y][x]->SetOriginY(21 + y * 33);

			p_square[y][x]->ChangeSquareOff();

			p_square[y][x]->DetectClickForSelect();
		}

	}

	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < count_height - 1; i++)
		{
			for (int j = 0; j < count_width; j++)
			{
				if (tmp_state[k].center_x == (150 + (17 + (j * 33))) && tmp_state[k].center_y == (20 + (33 + (i * 33))))
				{
					p_square[i][j]->ChangeSquareHit();
					p_square[i + 1][j]->ChangeSquareHit();
				}
				//if(p_square[i][j]->DetectDragArea(101 + j * 33, 101 + i * 33)&&Input::GetLogType()== MOUSE_INPUT_LOG_DOWN)
				//p_square[i][j]->ConvertIsDrag();

			}
		}
	}
	if (isTrans)
	{
		isEnd = true;
		SceneManager::SetNextScene(SceneID::Result);
	}

}

void InGameScene::Draw()
{
	DrawManager::DrawFrame();
	for (int i = 0; i < count_height; i++)
	{
		for (int j = 0; j < count_width; j++)
		{
			p_square[i][j]->Draw();
		}
	}
	DrawGraph(origin_pos_x, origin_pos_y, DrawManager::PassGHandle("Src/Draw/Result.png"), false);
}


bool InGameScene::DecideEnd()const
{
	return isEnd;
}

void InGameScene::DetectClickForTrans()
{
	if (Input::NotifyOfClick()) {
		if ((origin_pos_x<Input::GetMousePosX() && (origin_pos_x + offset_x)>Input::GetMousePosX())
			&& (origin_pos_y<Input::GetMousePosY() && (origin_pos_y + offset_y)>Input::GetMousePosY()))
		{
			isTrans = true;
		}
	}
}



//bool InGameScene::DetectEndArea2()const
//{
//	if (Input::DetectClick()) {
//		if ((origin_pos_x<Input::GetMousePosX() && (origin_pos_x + offset_x)>Input::GetMousePosX())
//			&& (origin_pos_y<Input::GetMousePosY() && (origin_pos_y + offset_y)>Input::GetMousePosY()))
//		{
//			return true;
//		}
//	}
//	return false;
//}

