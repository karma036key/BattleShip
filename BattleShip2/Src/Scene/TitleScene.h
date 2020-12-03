#ifndef TITLESCENE_H
#define TITLESCENE_H
#include"SceneBasa.h"

class TitleScene :public SceneBase
{
public:
	TitleScene();
	~TitleScene();

	virtual void Exec();
	virtual void Draw();

	virtual bool DecideEnd()const;




};



#endif