#ifndef INPUTMANGER_H
#define INPUTMANGER_H

#include "KeyDefionition.h"

// ================================================================================
// 入力処理で使う構造体
// ================================================================================
// キー状態構造体
struct StKeyState
{
	bool old;	// 前フレームの入力状態

	bool push;	// 押された瞬間か
	bool on;	// 押下されているか
	bool pull;	// 離された瞬間か
};

// ================================================================================
// 入力処理関数群
// ================================================================================
void InputInit();			// 入力処理初期化 (ゲーム起動時に一度だけ呼び出す)
void InputUpdate();			// 入力更新処理
bool IsPushKey( int key );	// キーが押されたか
bool IsOnKey( int key );	// キーが押下されているか
bool IsPullKey( int key );	// キーが離されたか


bool DetectOnCursor(int cursor_x, int cursor_y, int origin_x, int origin_y, int offset_x, int offset_y);

bool ClickMouse();

#endif