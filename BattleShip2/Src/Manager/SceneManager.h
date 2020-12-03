#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include"../Definition.h"

class SceneManager
{
	SceneManager();
	~SceneManager();

	void Exec();
	void Draw();

	static void SetNextScene(SceneID nextID);

private:
	class SceneBase* CreateNextScene();

private:
	class SceneBase* p_scene;
	static SceneID next_SceneID;

};


#endif