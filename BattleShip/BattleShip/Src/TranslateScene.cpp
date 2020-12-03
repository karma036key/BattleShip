#include"TranslateScene.h"
#include"InputManager.h"







void TranslateScene(Scene& scene,int click_x,int click_y)
{
	switch (scene)
	{
	case Scene::Title:
		if (DetectOnCursor(click_x, click_y, 500, 100, 128, 64))
		{	scene = Scene::Preparation;	}			 
		break;										 
	case Scene::Preparation:						 
		if (DetectOnCursor(click_x, click_y, 500, 200, 128, 64))
		{	scene = Scene::Playing;	}				 
		break;										 
	case Scene::Playing:							 
		if (DetectOnCursor(click_x, click_y, 500, 300, 128, 64))
		{	scene = Scene::Result;	}				 
		break;										 
	case Scene::Result:								 
		if (DetectOnCursor(click_x, click_y, 500, 400, 128, 64))
		{	scene = Scene::Title;	}
		break;
	}


}


void DrawSceneButton(Scene& scene,int origin_x, int origin_y)
{
	switch (scene)
	{
	case Scene::Title:

		LoadGraphScreen(origin_x, origin_y, "Src/Preparation.png", false);
		break;

	case Scene::Preparation:

		LoadGraphScreen(origin_x, origin_y, "Src/Playing.png", false);
		break;

	case Scene::Playing:
		LoadGraphScreen(origin_x, origin_y, "Src/Result.png", false);
		break;
	
	case Scene::Result:
		LoadGraphScreen(origin_x, origin_y, "Src/Title.png", false);
		break;
	
	}


}


