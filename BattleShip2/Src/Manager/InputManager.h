#ifndef INPUT_H
#define INPUT_H

class Input
{

public:
	Input();
	~Input();
		
	void Exec();
	void Draw();

	static bool DetectClick();
	static bool DetectRelease();
	static bool DetectDrag();
	static bool DetectClickForDrag(int origin_x, int origin_y);
	static bool DetectClickForTransition(int origin_x,int origin_y, int offset_x, int offset_y);
	static int GetMousePosX();
	static int GetMousePosY();
	static int GetDragMousePosX();
	static int GetDragMousePosY();
	static int GetClickMousePosX();
	static int GetClickMousePosY();
	static void SetClickMousePosX(int mouse);
	static void SetClickMousePosY(int mouse);
	static void SetLogType(int logt_ype);
	static int GetLogType();


private:
	static int button;
	static int mouse_x;
	static int mouse_y;
	static int drag_mouse_x;
	static int drag_mouse_y;
	static int click_mouse_x;
	static int click_mouse_y;
	static int log_type;
	static int log_type2;
	static bool isHold;
	static bool isRelease;
};

#endif