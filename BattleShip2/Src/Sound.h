#ifndef SOUND_H
#define SOUND_H
#include"Manager/SceneManager.h"
class Sound
{
public:
	Sound();
	~Sound();	// 全ロードサウンド消去

	// シーン別にロード
	void LoadSound(SceneID Scene);

	// 各シーンサウンド再生
	void TitleSound();
	void StageSound();
	void GameSound();
	void ResultSound();

	//サウンドクリア
	void ClearSound(int delete_soundHandle);

private:
	// 再生管理
	bool TitleBGM;
	bool TitleNextSound;
	bool StageBGM;
	bool GameBGM;
	bool GameCheckSound;
	bool ResultBGM;
	bool NextSceneSound;
	
	// ハンドル(音源)管理
	int titleBGM;
	int titleNextSound;
	int stageBGM;
	int gameBGM;
	int gameCheckSound;
	int resultBGM;
	int nextSceneSound;
};

#endif
