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
	static int GetMousePosX();
	static int GetMousePosY();

private:
	static int button;
	static int mouse_x;
	static int mouse_y;
	static int log_type;
};

#endif