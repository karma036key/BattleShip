#ifndef SOUND_H
#define SOUND_H
#include"Manager/SceneManager.h"
class Sound
{
public:
	Sound();
	~Sound();	// �S���[�h�T�E���h����

	// �V�[���ʂɃ��[�h
	void LoadSound(SceneID Scene);

	// �e�V�[���T�E���h�Đ�
	void TitleSound();
	void StageSound();
	void GameSound();
	void ResultSound();

	//�T�E���h�N���A
	void ClearSound(int delete_soundHandle);

private:
	// �Đ��Ǘ�
	bool TitleBGM;
	bool TitleNextSound;
	bool StageBGM;
	bool GameBGM;
	bool GameCheckSound;
	bool ResultBGM;
	bool NextSceneSound;
	
	// �n���h��(����)�Ǘ�
	int titleBGM;
	int titleNextSound;
	int stageBGM;
	int gameBGM;
	int gameCheckSound;
	int resultBGM;
	int nextSceneSound;
};

#endif
