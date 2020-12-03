#ifndef MAPSQUARE_ISSELECTED_H
#define MAPSQUARE_ISSELECTED_H


class IsSelected :public Square
{
public:
	IsSelected();
	~IsSelected();
public:


	enum class State
	{
		None,
		Hit,
		Off,
	};
	struct Squares
	{
		int x;
		int y;
		State state;
	};
	Squares GetSquares();
	void SetSquares(int x, int y, State state);
	void DrawSquare(int x, int y);
	State Notify();
	void Confirmation(Scene& scene);
private:
	struct Squares squares;
};




#endif