#include"DxLib.h"
#include"Manager/SceneManager.h"
#include"Manager/DrawManager.h"


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	SetOutApplicationLogValidFlag(false);
	ChangeWindowMode(true);
	SetGraphMode(640, 360, 32);
	SetBackgroundColor(125, 125, 125);
	SetMainWindowText("BattleShip");


	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// 描画先を裏の画面に設定
	SetDrawScreen(DX_SCREEN_BACK);



	// 管理クラスの作成
	SceneManager* pSceneManager = new SceneManager();

	DrawManager::LoadAllGraph();


	while (true)
	{
		// Windowsのメッセージ処理に失敗したか、閉じられたら終了
		if (ProcessMessage() != 0)
		{
			break;
		}

		// DxLibのお約束：画面クリア
		ClearDrawScreen();
		clsDx();


		// 処理

		pSceneManager->Exec();



		// 描画
		pSceneManager->Draw();


		// DxLibのお約束：画面更新
		ScreenFlip();		// フロントバッファとバックバッファの入れ替え
	}

	// 管理クラスの後始末
	delete pSceneManager;
	pSceneManager = nullptr;
	DrawManager::DeleteAllGraph();

	// DXライブラリ使用に終了処理
	DxLib_End();

	return 0;


}
















