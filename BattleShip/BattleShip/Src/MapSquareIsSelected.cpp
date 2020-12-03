#include"MapSquare.h"
#include"MapSquareIsSelected.h"



IsSelected::IsSelected()
	:squares{ 0,0,State::None }
{

}
IsSelected::~IsSelected()
{


}


void IsSelected::SetSquares(int x, int y, State state)
{
	squares = { x,y,state };
}

IsSelected::Squares IsSelected::GetSquares()
{
	return squares;
}

void IsSelected::DrawSquare(int x, int y)
{
	LoadGraphScreen(x, y, "Src/Hit.png", false);


}


void IsSelected::Confirmation(Scene& scene)
{
	Squares sq = GetSquares();
	switch (scene)
	{
	case Scene::Title:
		DrawString(0, 0, "�^�C�g��", GetColor(80, 80, 80));
		break;
	case Scene::Preparation:
		DrawString(0, 0, "�������", GetColor(80, 80, 80));
		break;
	case Scene::Playing:
		DrawString(0, 0, "�퓬���", GetColor(80, 80, 80));
		break;
	case Scene::Result:
		DrawString(0, 0, "���U���g", GetColor(80, 80, 80));
		break;




	}
}




IsSelected::State IsSelected::Notify()
{
	return State::Hit;


}
