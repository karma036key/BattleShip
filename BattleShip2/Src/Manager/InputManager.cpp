#include"InputManager.h"
#include"DxLib.h"

int Input::button;
int Input::mouse_x;
int Input::mouse_y;
int Input::drag_mouse_x;
int Input::drag_mouse_y;
int Input::click_mouse_x;
int Input::click_mouse_y;
int Input::release_mouse_x;
int Input::release_mouse_y;
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

bool Input::NotifyOfClick()
{
	//int mouse_x2, mouse_y2;					//入力関係の関数を同フレームでも実行処理できた
	//GetMousePoint(&mouse_x2, &mouse_y2);		//同じフレームで同じ関数はNG、同フレームで別関数or別フレームで同関数は通る

	if ((GetMouseInputLog2(&button, &mouse_x, &mouse_y, &log_type, TRUE) == 0))
	{

		if ((button & MOUSE_INPUT_LEFT) != 0) {
			if (log_type == MOUSE_INPUT_LOG_DOWN)
			{
				SetClickMousePosX(mouse_x);
				SetClickMousePosY(mouse_y);
				SetLogType(log_type);
				return true;
			}
			SetLogType(log_type);
			SetReleaseMousePosX(mouse_x);
			SetReleaseMousePosY(mouse_y);
		}
	}
	return false;

}


bool Input::NotifyOfRelease()
{

	if ((GetMouseInputLog2(&button, &mouse_x, &mouse_y, &log_type, TRUE) == 0))
	{
		if ((button & MOUSE_INPUT_LEFT) != 0)
			if (log_type == MOUSE_INPUT_LOG_UP)
			{

				return true;
			}
	}
	return false;

}

bool Input::NotifyOfDrag()
{

	if (GetMouseInput()==MOUSE_INPUT_LEFT)
	{
		return true;
	}
	else
		return false;
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


bool Input::DetectClickForTransition(int origin_x, int origin_y, int offset_x, int offset_y)
{

	if (Input::NotifyOfClick()) {

		if ((origin_x<Input::GetMousePosX() && (origin_x + offset_x)>Input::GetMousePosX())
			&& (origin_y<Input::GetMousePosY() && (origin_y + offset_y)>Input::GetMousePosY()))
		{

			return true;
		}
	}

	return false;
}


int Input::GetMousePosX()
{
	GetMousePoint(&mouse_x, &mouse_y);
	return mouse_x; 
}


int Input::GetMousePosY()
{ 
	GetMousePoint(&mouse_x, &mouse_y);
	return mouse_y;
}



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

int Input::GetClickMousePosX()
{
	return click_mouse_x;
}


int Input::GetClickMousePosY()
{
	return click_mouse_y;
}

int Input::GetReleaseMousePosX()
{
	return release_mouse_x;
}

int Input::GetReleaseMousePosY()
{
	return release_mouse_y;
}

void Input::SetClickMousePosX(int mouse)
{
	click_mouse_x = mouse;
}

void Input::SetClickMousePosY(int mouse)
{
	click_mouse_y = mouse;
}

void Input::SetReleaseMousePosX(int mouse)
{
	release_mouse_x = mouse;
}

void Input::SetReleaseMousePosY(int mouse)
{
	release_mouse_y = mouse;
}

void Input::SetLogType(int log_type)
{
	log_type2 = log_type;
}

int Input::GetLogType()
{
	return log_type2;
}