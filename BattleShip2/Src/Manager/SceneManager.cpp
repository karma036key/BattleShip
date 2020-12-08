#include"SceneManager.h"
#include"DrawManager.h"
#include"../Scene/SceneBasa.h"
#include"../Scene/TitleScene.h"
#include"../Scene/PreparationScene.h"
#include"../Scene/InGameScene.h"
#include"../Scene/ResultScene.h"

SceneID SceneManager::next_SceneID = SceneID::Invalid;

SceneManager::SceneManager()
	:p_scene(nullptr)
{
	// 最初に実行するシーンを作成する
	SetNextScene(SceneID::Title);
	p_scene = CreateNextScene();
}

SceneManager::~SceneManager()
{
	delete p_scene;
	p_scene = nullptr;
}

void SceneManager::Exec()
{
	if (p_scene == nullptr) { return; }

	p_scene->Exec();

	if (p_scene->DecideEnd())
	{
		delete p_scene;
		p_scene = CreateNextScene();
	}

}


void SceneManager::Draw()
{
	DrawManager::DrawBackGround();
	if (p_scene == nullptr) { return; }

	p_scene->Draw();
}

void SceneManager::SetNextScene(SceneID next_)
{
	next_SceneID = next_;
}


SceneBase* SceneManager::CreateNextScene()
{
	SceneBase* next = nullptr;
	switch (next_SceneID)
	{
		// ここにそれぞれSceneBaseを継承した派生クラスをnewする処理を書く
		// シーンの増減があってもヘッダのインクルードとここ以外に変更は必要ない
	case SceneID::Title:		next = new TitleScene(); break;
	case SceneID::Preparation:	next = new PreparationScene(); break;
	case SceneID::InGame:		next = new InGameScene(); break;
	case SceneID::Result:		next = new ResultScene(); break;
	default:break;
	}
	return next;

}
