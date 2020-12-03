#ifndef INGAMESCENE_H
#define INGAMESCENE_H
#include"SceneBasa.h"

class iInGameScene :public SceneBase
{
public:
	iInGameScene();
	~iInGameScene();

	virtual void Exec();
	virtual void Draw();

	virtual bool DecideEnd()const;




};

#endif