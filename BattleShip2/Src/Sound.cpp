#include"DxLib.h"
#include"Sound.h"



Sound::Sound()
	:TitleBGM		(false)
	,TitleNextSound	(false)
	,StageBGM		(false)
	,GameBGM		(false)
	,GameCheckSound	(false)
	,ResultBGM		(false)
	,NextSceneSound	(false)
	,titleBGM	    (-1)
	,titleNextSound (-1)
	,stageBGM	    (-1)
	,gameBGM	    (-1)
	,gameCheckSound (-1)
	,resultBGM	    (-1)
	,nextSceneSound (-1)
{
	
}

Sound::~Sound()
{
	InitSoundMem();
}

void Sound::LoadSound(SceneID Scene)
{
	switch (Scene) {
	case SceneID::Title:
		titleBGM = LoadSoundMem("aaaa");
		titleNextSound = LoadSoundMem("bbbbbbbb");
		nextSceneSound = LoadSoundMem("gggggggggg");
		break;

	case SceneID::Preparation:
		stageBGM = LoadSoundMem("ccccccc");
		break;

	case SceneID::InGame:
		gameBGM = LoadSoundMem("dddddddd");
		gameCheckSound = LoadSoundMem("eeeeeeeeee");
		break;

	case SceneID::Result:
		resultBGM = LoadSoundMem("fffffffffffff");
		break;
	}
}


void Sound::TitleSound()
{
	if (TitleNextSound)
	{
		PlaySoundMem(titleNextSound, DX_PLAYTYPE_NORMAL);
	}
}

void Sound::StageSound()
{
	if(StageBGM)
	{
		PlaySoundMem(stageBGM, DX_PLAYTYPE_BACK);
	}
}

void Sound::GameSound()
{
	if(GameBGM)
	{
		PlaySoundMem(gameBGM, DX_PLAYTYPE_BACK);
	}
	if(GameCheckSound)
	{
		PlaySoundMem(gameCheckSound, DX_PLAYTYPE_NORMAL);
	}

}

void Sound::ResultSound()
{
	if (ResultBGM)
	{
		PlaySoundMem(resultBGM, DX_PLAYTYPE_BACK);
	}
}


void Sound::ClearSound(int delete_soundHandle)
{
	DeleteSoundMem(delete_soundHandle);
}
