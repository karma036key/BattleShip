#ifndef SCENEBASE_H
#define SCENEBASE_H
#include"../Definition.h"

class SceneBase
{
public:
	SceneBase();
	virtual  ~SceneBase();

	virtual void Exec() = 0;
	virtual void Draw() = 0;
	virtual bool DecideEnd()const = 0;
	virtual void DetectClickArea() = 0;
protected:
	bool isEnd;
	bool isTrans;
	bool isHold;
};





#endif