#include"InputManager.h"
#include"DxLib.h"

int Input::button;
int Input::mouse_x;
int Input::mouse_y;
int Input::drag_mouse_x;
int Input::drag_mouse_y;
int Input::log_type;
int Input::log_type2;
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
	//int mouse_x2, mouse_y2;					//入力関係の関数を同フレームでも実行処理できた
	//GetMousePoint(&mouse_x2, &mouse_y2);		//同じフレームで同じ関数はNG、同フレームで別関数or別フレームで同関数は通る

	if ((GetMouseInputLog2(&button, &mouse_x, &mouse_y, &log_type, true) == 0))
	{

		if ((button & MOUSE_INPUT_LEFT) != 0) {
			if (log_type == MOUSE_INPUT_LOG_DOWN)
			{
				SetLogType(log_type);
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

void Input::DetectDrag(bool& isHold)
{

	if (GetMouseInput()==MOUSE_INPUT_LEFT)
	{
		isHold = true;
	}
	else
		isHold = false;
}

bool Input::DetectClickForDrag(int origin_x, int origin_y)
{
	if ((origin_x < Input::GetDragMousePosX() && Input::GetDragMousePosX() < origin_x + 32) &&
		(origin_y < Input::GetDragMousePosY() && Input::GetDragMousePosY() < origin_y + 32))
	{
		return true;
	}
	return false;
}


int Input::GetMousePosX()
{ return mouse_x; }


int Input::GetMousePosY()
{ return mouse_y; }



int Input::GetDragMousePosX()
{
	GetMousePoint(&drag_mouse_x, &drag_mouse_y);
	return drag_mouse_x;
}


int Input::GetDragMousePosY()
{
	GetMousePoint(&drag_mouse_x, &drag_mouse_y);
	return drag_mouse_y;


}

void Input::SetLogType(int log_type)
{
	log_type2 = log_type;
}

int Input::GetLogType()
{
	return log_type2;
}