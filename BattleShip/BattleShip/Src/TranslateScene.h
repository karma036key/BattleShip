#ifndef TRANSLATESCENE_H
#define TRANSLATESCENE_H




enum class Scene
{
	Title,
	Preparation,
	Playing,
	Result,
};


void TranslateScene(Scene& scene, int click_x, int click_y);

void DrawSceneButton(Scene& scene,int origin_x,int origin_y);




#endif