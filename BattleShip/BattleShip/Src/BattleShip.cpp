



#include "DxLib.h"
#include "InputManager.h"
#include "DrawManager.h"
#include <stdio.h>
#include <time.h>
#include"MapSquare.h"
#include"TranslateScene.h"
#include"MapSquareIsSelected.h"

#define WINDOW_W	640
#define WINDOW_H	480

 // ==============================
 // グローバル変数
 // ==============================

Scene scene;



// ==============================
// 関数プロトタイプ宣言
// ==============================







// ==============================
// Main関数
// ==============================
int WINAPI WinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR lpCmdLine,_In_ int nCmdShow)
{
	// ＤＸライブラリを使う上での初期化処理
	// ----------------------------------------------------
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetGraphMode(WINDOW_W, WINDOW_H, 32);
	SetBackgroundColor(125, 125, 255);
	SetMainWindowText("Battle Ship");
	if (DxLib_Init() == -1) { return -1; }

	SetDrawScreen(DX_SCREEN_BACK);

	// ローカル変数宣言
	// ----------------------------------------------------


	int mouse_x;
	int mouse_y;
	int mouse_x_dd;
	int mouse_y_dd;
	int button;
	int log_type;

	IsSelected* player1[10][10] = { nullptr };




	// 各種初期化処理
	// ----------------------------------------------------
	InputInit();			// 入力処理初期化関数の呼び出し
	DrawInit();				// 描画処理初期化関数の呼び出し

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			player1[i][j] = new IsSelected();
			player1[i][j]->SetSquares(51+33 * i, 51+33 * j, IsSelected::State::None);
		}
	}


	// ゲームのメインループ
	// 画面を１回表示する毎にwhile分を１回処理する
	// ----------------------------------------------------
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// ＤＸライブラリを使う上で、１フレーム分の処理を始めるためのお約束
		// ----------------------------------------------------
		ClearDrawScreen();
		clsDx();

		// 以下、毎フレーム更新する処理
		// ----------------------------------------------------
		InputUpdate();			// 入力処理更新関数の呼び出し

		GetMousePoint(&mouse_x_dd, &mouse_y_dd);
		if ((GetMouseInputLog2(&button, &mouse_x, &mouse_y, &log_type, true) == 0))
		{
			if ((button & MOUSE_INPUT_LEFT) != 0)
				if (log_type == MOUSE_INPUT_LOG_DOWN)
				{	
					TranslateScene(scene, mouse_x, mouse_y);
				}
		}

		switch (scene)
		{
		case Scene::Title:
			break;
		case Scene::Preparation:
		
			break;
		case Scene::Playing:

			break;
		case Scene::Result:

			break;


		}






		// 以下、描画処理
		// ----------------------------------------------------

		player1[0][0]->Confirmation(scene);
		switch (scene)
		{
		case Scene::Title:
			DrawSceneButton(scene, 500, 100);

			break;
		case Scene::Preparation:
			DrawDragGraphic(mouse_x_dd,mouse_y_dd);
			DrawSceneButton(scene, 500, 200);
			break;
		case Scene::Playing:
			DrawSceneButton(scene, 500, 300);
			player1[0][0]->DrawBackGround();
			player1[0][0]->DrawFrame();
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					player1[i][j]->DrawSquare(player1[i][j]->GetSquares().x, player1[i][j]->GetSquares().y);
				}
			}
			break;
		case Scene::Result:
			DrawSceneButton(scene, 500, 400);
			break;
		}


		// ＤＸライブラリを使う上で、モニターへゲーム画面を表示するためのお約束
		// 必ずループの最後で呼び出す
		// ----------------------------------------------------
		ScreenFlip();
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			delete player1[i][j];
		}
	}
	// 後始末
	// ----------------------------------------------------
	DrawEnd();		// 描画処理終了

	// ＤＸライブラリを使う上での終了処理
	// ----------------------------------------------------
	DxLib_End();
	return 0;
}

