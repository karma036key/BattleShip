#ifndef INGAMESCENE_H
#define INGAMESCENE_H
#include"SceneBasa.h"
#include"../Manager/DataManager.h"
class InGameScene :public SceneBase
{
public:
	InGameScene();
	virtual ~InGameScene();

	virtual void Exec();
	virtual void Draw();

	virtual bool DecideEnd()const;

	virtual void DetectClickForTrans();

	//bool DetectEndArea2()const;		//DetectEndAreaと同じ内容を書いてlogtype検証。同フレームでは維持されるかと思ったが同メソッド内でしか持たないらしい

private:
	const int origin_pos_x;
	const int origin_pos_y;
	const int offset_x;
	const int offset_y;

	class SelectSquare* p_square[count_height][count_width];
	DataManager* pDataMng;
	SquareState tmp_state[2];
};

#endif