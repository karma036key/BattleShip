#include"InputManager.h"
#include"DxLib.h"

int Input::button;
int Input::mouse_x;
int Input::mouse_y;
int Input::log_type;
bool Input::isHold = false;
bool Input::isRelease = true;

Input::Input()
{



}



Input::~Input()
{


}


void Input::Exec()
{



}


void Input::Draw()
{



}

bool Input::DetectClick()
{

	if ((GetMouseInputLog2(&button, &mouse_x, &mouse_y, &log_type, true) == 0))
	{

		if ((button & MOUSE_INPUT_LEFT) != 0) {
			if (log_type == MOUSE_INPUT_LOG_DOWN)
			{
				return true;
			}
		}
	}
	return false;

}


bool Input::DetectRelease()
{

	if ((GetMouseInputLog2(&button, &mouse_x, &mouse_y, &log_type, true) == 0))
	{
		if ((button & MOUSE_INPUT_LEFT) != 0)
			if (log_type == MOUSE_INPUT_LOG_UP)
			{
				return true;
			}
	}
	return false;

}

void Input::DetectDrag()
{

	if (DetectClick())
		isHold = true;


	if (DetectRelease())
		isHold = false;


}


int Input::GetMousePosX()
{ return mouse_x; }


int Input::GetMousePosY()
{ return mouse_y; }