#ifndef PREPARATIONSCENE_H
#define PREPARATIONSCENE_H
#include"SceneBasa.h"

class PreparationScene :public SceneBase
{
public:
	PreparationScene();
	~PreparationScene();

	virtual void Exec();
	virtual void Draw();

	virtual bool DecideEnd()const;




};


#endif