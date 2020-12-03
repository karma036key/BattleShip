#include "MapSquare.h"


Square::Square()
	:origin_pos_x{50}
	, origin_pos_y{ 50 }
	, count_width{ 10 }
	, count_height{ 10 }
	, size_width{ 33 }
	, size_height{ 33 }
{
}


Square::~Square()
{



}

int Square::GetOriginPosX()const
{
	return origin_pos_x;
}

int Square::GetOriginPosY()const
{
	return origin_pos_y;
}
int Square::GetCountW()const
{
	return count_width;
}

int Square::GetCountH()const
{
	return count_height;
}

int Square::GetSizeW()const
{
	return size_width;
}

int Square::GetSizeH()const
{
	return size_height;
}

void Square::DrawFrame()const
{
	const int left = GetOriginPosX();
	const int right = GetOriginPosX()+(GetSizeW()*GetCountW());
	const int top = GetOriginPosY();
	const int bottom = GetOriginPosY() + (GetSizeH() * GetCountH());
	for (int i = 0; i <= GetCountW(); i++)
	{
		DrawLine(left+i*GetSizeW(), top, left + i * GetSizeW(), bottom, GetColor(0xFF, 0xFF, 0xFF));
	}
	for (int i = 0; i <= GetCountH(); i++)
	{
		DrawLine(left, top + i * GetSizeH(), right, top + i * GetSizeH(), GetColor(0xFF, 0xFF, 0xFF));
	}
}

void Square::DrawBackGround()const
{


	LoadGraphScreen(GetOriginPosX(), GetOriginPosY(), "Src/BG2.png", false);
}


