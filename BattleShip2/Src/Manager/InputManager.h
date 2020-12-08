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
	static void DetectDrag(bool& isHold);
	static bool DetectClickForDrag(int origin_x, int origin_y);
	static int GetMousePosX();
	static int GetMousePosY();
	static int GetDragMousePosX();
	static int GetDragMousePosY();
	static void SetLogType(int logt_ype);
	static int GetLogType();


private:
	static int button;
	static int mouse_x;
	static int mouse_y;
	static int drag_mouse_x;
	static int drag_mouse_y;
	static int log_type;
	static int log_type2;
	static bool isHold;
	static bool isRelease;
};

#endif