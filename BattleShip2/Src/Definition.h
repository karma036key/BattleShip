#ifndef DEFINITION_H
#define DEFINITION_H


// ÉVÅ[ÉìID
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

enum class ShipID
{
	SHIP2,
	SHIP3,
	SHIP4,
	SHIP5,
};


struct SquareState
{
	int pos_x;
	int pos_y;
	int center_x;
	int center_y;
	SquareID square;
	ShipID ship;
};

//struct ShipState
//{
//	int pos_x;
//	int pos_y;
//	int center_x;
//	int center_y;
//	SquareID square;
//	ShipID ship;
//};

const int count_width = 10;
const int count_height = 10;


#endif