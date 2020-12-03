#ifndef SCENEBASE_H
#define SCENEBASE_H

class SceneBase
{
public:
	SceneBase();
	virtual  ~SceneBase();

	virtual void Exec() = 0;
	virtual void Draw() = 0;
	virtual bool DecideEnd()const = 0;

private:

};





#endif