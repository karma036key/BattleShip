#ifndef INPUTMANGER_H
#define INPUTMANGER_H

#include "KeyDefionition.h"

// ================================================================================
// ���͏����Ŏg���\����
// ================================================================================
// �L�[��ԍ\����
struct StKeyState
{
	bool old;	// �O�t���[���̓��͏��

	bool push;	// �����ꂽ�u�Ԃ�
	bool on;	// ��������Ă��邩
	bool pull;	// �����ꂽ�u�Ԃ�
};

// ================================================================================
// ���͏����֐��Q
// ================================================================================
void InputInit();			// ���͏��������� (�Q�[���N�����Ɉ�x�����Ăяo��)
void InputUpdate();			// ���͍X�V����
bool IsPushKey( int key );	// �L�[�������ꂽ��
bool IsOnKey( int key );	// �L�[����������Ă��邩
bool IsPullKey( int key );	// �L�[�������ꂽ��


bool DetectOnCursor(int cursor_x, int cursor_y, int origin_x, int origin_y, int offset_x, int offset_y);

bool ClickMouse();

#endif