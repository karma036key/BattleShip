#include"DxLib.h"
#include"Manager/SceneManager.h"


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	SetOutApplicationLogValidFlag(false);
	ChangeWindowMode(true);
	SetGraphMode(640, 480, 32);
	SetBackgroundColor(125, 125, 125);
	SetMainWindowText("BattleShip");


	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// �`���𗠂̉�ʂɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);


	// �Ǘ��N���X�̍쐬




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




		// �`��



		// DxLib�̂��񑩁F��ʍX�V
		ScreenFlip();		// �t�����g�o�b�t�@�ƃo�b�N�o�b�t�@�̓���ւ�
	}

	// �Ǘ��N���X�̌�n��



	// DX���C�u�����g�p�ɏI������
	DxLib_End();

	return 0;


}
















