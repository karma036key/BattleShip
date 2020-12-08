#ifndef DEFINITION_H
#define DEFINITION_H


// �V�[��ID
enum class SceneID
{
	Title,
	Preparation,
	InGame,
	Result,

	Max,
	Invalid,


};

enum class SquareID
{
	NONE,
	HIT,
	OFF,
};



struct SquareState
{
	int pos_x;
	int pos_y;
	int center_x;
	int center_y;
	SquareID square;
};

const int count_width = 10;
const int count_height = 10;


#endif