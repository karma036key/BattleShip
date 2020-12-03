
#include "DxLib.h"
#include "DrawManager.h"
#include"InputManager.h"

#define CELLSIZE			100		// �P�}�X�̃T�C�Y
#define CURSORSIZE			96		// �J�[�\���̃T�C�Y
#define CIRCLE_R			48		// �v���C���[�~�̔��a

#define DRAW_OFFSET_X		10		// �`��I�t�Z�b�g�w
#define DRAW_OFFSET_Y		60		// �`��I�t�Z�b�g�x

#define GAME_AREA_WIDTH		(STAGE_WIDTH * CELLSIZE)	// �Q�[���G���A��
#define GAME_AREA_HEIGHT	(STAGE_HEIGHT * CELLSIZE)	// �Q�[���G���A����


// ================================================================================
// �`�揈�������� (�Q�[���N�����Ɉ�x�����Ăяo��)
// ================================================================================
void DrawInit()
{
}

// ================================================================================
// �`�揈���I���@ (�Q�[���I�����ADxLib_End�̑O�Ɉ�x�����Ăяo��)
// ================================================================================
void DrawEnd()
{
}



// ================================================================================
// �J�[�\����`��
// x = �}�X�� x���W
// y = �}�X�� y���W
// ================================================================================
void DrawCursor( int x, int y )
{
	const int left		= DRAW_OFFSET_X + (x * CELLSIZE) + int((CELLSIZE - CURSORSIZE)*0.5);
	const int top		= DRAW_OFFSET_Y + (y * CELLSIZE) + int((CELLSIZE - CURSORSIZE)*0.5);
	DrawBox( left, top, left+ CURSORSIZE, top+ CURSORSIZE, GetColor( 0xFF, 0x00, 0x00), FALSE );
}

void DrawSelectSquare(int x, int y)
{
	const int center_x = DRAW_OFFSET_X + (x * CELLSIZE) + int(CELLSIZE * 0.5);
	const int center_y = DRAW_OFFSET_Y + (y * CELLSIZE) + int(CELLSIZE * 0.5);
	DrawCircle(center_x, center_y, CIRCLE_R, GetColor(0x00, 0x00, 0x00), TRUE);
}


void DrawDragGraphic(int x, int y)
{
	if (DetectOnCursor(x, y, 100, 100, 32, 32))
	{
		LoadGraphScreen(x, y, "Src/Hit.png", false);
	}
	else
		LoadGraphScreen(100, 100, "Src/Hit.png", false);
}