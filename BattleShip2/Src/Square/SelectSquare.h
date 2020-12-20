#ifndef SELECTSQUARE_H
#define SELECTSQUARE_H
#include"SquareBase.h"

class SelectSquare :public SquareBase
{
public:
	SelectSquare();
	virtual ~SelectSquare();
	
	void Exec();
	virtual void Draw()const;
	void ChangeSquareHit();
	void ChangeSquareOff();
	void DetectClickForSelect();
	void SetOriginX(int x);
	void SetOriginY(int y);
	int GetOriginX()const;
	int GetOriginY()const;
private:
	SquareID exa;
	int origin_x;
	int origin_y;
	bool isChange;
};



#endif