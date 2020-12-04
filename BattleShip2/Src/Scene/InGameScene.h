#ifndef INGAMESCENE_H
#define INGAMESCENE_H
#include"SceneBasa.h"
class InGameScene :public SceneBase
{
public:
	InGameScene();
	~InGameScene();

	virtual void Exec();
	virtual void Draw();

	virtual bool DecideEnd()const;

	virtual bool DetectEndArea()const;

private:
	const int origin_pos_x;
	const int origin_pos_y;
	const int offset_x;
	const int offset_y;



};

#endif