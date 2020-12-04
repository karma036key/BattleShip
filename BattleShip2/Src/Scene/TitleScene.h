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

	virtual bool DetectEndArea()const;

private:
	const int origin_pos_x;
	const int origin_pos_y;
	const int offset_x;
	const int offset_y;

};



#endif