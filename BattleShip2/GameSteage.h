#ifndef Game_STEAGE_H
#define Game_STEAGE_H

class GameSteage
{
public:
	
	// 各変数初期化	
	GameSteage();
	// 船設置
	void SetShip();
	// 勝利チェック
	bool CheckClear();

private:
	//  
	int Steage[10][10];

						// 船の大きさ(マス)
	bool PoachingBoat;	// 1	//漁船
	bool SmallShip;		// 2	//小艦
	bool Ship;			// 3	//中艦
	bool LargeShip;		// 4	//大艦
	bool BigShip;		// 5*2	//戦艦
	// bool
};


#endif