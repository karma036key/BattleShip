#ifndef RESULTSCENE_H
#define RESULTSCENE_H

#include"SceneBasa.h"

class ResultScene :public SceneBase
{
public:
	ResultScene();
	virtual ~ResultScene();

	virtual void Exec();
	virtual void Draw();

	virtual bool DecideEnd()const;


	virtual void DetectClickForTrans();

private:
	const int origin_pos_x;
	const int origin_pos_y;
	const int offset_x;
	const int offset_y;



};

#endif