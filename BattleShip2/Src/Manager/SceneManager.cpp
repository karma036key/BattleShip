#include"SceneManager.h"

#include"../Scene/SceneBase.h"
#include"../Scene/TitleScene.h"
#include"../Scene/PreparationScene.h"
#include"../Scene/InGameScene.h"
#include"../Scene/ResultScene.h"

SceneID SceneManager::next_SceneID = SceneID_Invalid;

SceneManager::SceneManager()
	:p_scene(nullptr)
{
	// �ŏ��Ɏ��s����V�[�����쐬����
	SetNextScene(SceneID_Title);
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
		// �����ɂ��ꂼ��SceneBase���p�������h���N���X��new���鏈��������
		// �V�[���̑����������Ă��w�b�_�̃C���N���[�h�Ƃ����ȊO�ɕύX�͕K�v�Ȃ�
	case SceneID_Title:			next = new TitleScene(); break;
	case SceneID_Preparation:	next = new PreparationScene(); break;
	case SceneID_InGame:		next = new InGameScene(); break;
	case SceneID_Result:		next = new ResultScene(); break;
	default:break;
	}
	return next;

}
