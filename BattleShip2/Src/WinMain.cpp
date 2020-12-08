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

	// �`���𗠂̉�ʂɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);



	// �Ǘ��N���X�̍쐬
	SceneManager* pSceneManager = new SceneManager();

	DrawManager::LoadAllGraph();


	while (true)
	{
		// Windows�̃��b�Z�[�W�����Ɏ��s�������A����ꂽ��I��
		if (ProcessMessage() != 0)
		{
			break;
		}

		// DxLib�̂��񑩁F��ʃN���A
		ClearDrawScreen();
		clsDx();


		// ����

		pSceneManager->Exec();



		// �`��
		pSceneManager->Draw();


		// DxLib�̂��񑩁F��ʍX�V
		ScreenFlip();		// �t�����g�o�b�t�@�ƃo�b�N�o�b�t�@�̓���ւ�
	}

	// �Ǘ��N���X�̌�n��
	delete pSceneManager;
	pSceneManager = nullptr;
	DrawManager::DeleteAllGraph();

	// DX���C�u�����g�p�ɏI������
	DxLib_End();

	return 0;


}
















