#ifndef Game_STEAGE_H
#define Game_STEAGE_H

class GameSteage
{
public:
	
	// �e�ϐ�������	
	GameSteage();
	// �D�ݒu
	void SetShip();
	// �����`�F�b�N
	bool CheckClear();

private:
	//  
	int Steage[10][10];

						// �D�̑傫��(�}�X)
	bool PoachingBoat;	// 1	//���D
	bool SmallShip;		// 2	//����
	bool Ship;			// 3	//����
	bool LargeShip;		// 4	//���
	bool BigShip;		// 5*2	//���
	// bool
};


#endif