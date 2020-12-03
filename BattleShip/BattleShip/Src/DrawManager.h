#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H
// ================================================================================
// 描画処理関数群
// ================================================================================
void DrawInit();	// 描画処理初期化 (ゲーム起動時に一度だけ呼び出す)
void DrawEnd();		// 描画処理終了　 (ゲーム終了時、DxLib_Endの前に一度だけ呼び出す)

void DrawCursor( int x, int y );			// カーソルを描画
void DrawSelectSquare(int x, int y);


void DrawDragGraphic(int x, int y);

#endif