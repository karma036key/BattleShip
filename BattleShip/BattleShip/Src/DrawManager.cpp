
#include "DxLib.h"
#include "DrawManager.h"
#include"InputManager.h"

#define CELLSIZE			100		// １マスのサイズ
#define CURSORSIZE			96		// カーソルのサイズ
#define CIRCLE_R			48		// プレイヤー円の半径

#define DRAW_OFFSET_X		10		// 描画オフセットＸ
#define DRAW_OFFSET_Y		60		// 描画オフセットＹ

#define GAME_AREA_WIDTH		(STAGE_WIDTH * CELLSIZE)	// ゲームエリア幅
#define GAME_AREA_HEIGHT	(STAGE_HEIGHT * CELLSIZE)	// ゲームエリア高さ


// ================================================================================
// 描画処理初期化 (ゲーム起動時に一度だけ呼び出す)
// ================================================================================
void DrawInit()
{
}

// ================================================================================
// 描画処理終了　 (ゲーム終了時、DxLib_Endの前に一度だけ呼び出す)
// ================================================================================
void DrawEnd()
{
}



// ================================================================================
// カーソルを描画
// x = マスの x座標
// y = マスの y座標
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