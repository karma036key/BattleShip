#ifndef RESULTSCENE_H
#define RESULTSCENE_H

#include"SceneBasa.h"

class ResultScene :public SceneBase
{
public:
	ResultScene();
	~ResultScene();

	virtual void Exec();
	virtual void Draw();

	virtual bool DecideEnd()const;




};

#endif