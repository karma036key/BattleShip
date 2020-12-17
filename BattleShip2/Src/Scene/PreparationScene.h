#ifndef PREPARATIONSCENE_H
#define PREPARATIONSCENE_H
#include"SceneBasa.h"

class PreparationScene :public SceneBase
{
public:
	PreparationScene();
	virtual ~PreparationScene();

	virtual void Exec();
	virtual void Draw();

	virtual bool DecideEnd()const;


	virtual void DetectClickForTrans();

private:
	const int origin_pos_x;
	const int origin_pos_y;
	const int offset_x;
	const int offset_y;
	bool isTouch;

	class SelectSquare* p_square[count_height][count_width];
	class ShipSquare* p_ship[7];

	// SquareBase�̕������ނ��킩��₷���H��ShipID��SquareID�𕪂����ň��������X��₱�����Ȃ�̂Ōp���N���X�ŃC���X�^���X�쐬
	//class SquareBase* p_square[count_height][count_width];
	//class SquareBase* p_ship[7];
};


#endif