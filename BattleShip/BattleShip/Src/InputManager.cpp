
#include "DxLib.h"
#include "InputManager.h"

// ================================================================================
// �O���[�o���֐�
// ================================================================================
StKeyState		m_state[MY_INPUT_MAX];


// ================================================================================
// ���͏��������� (�Q�[���N�����Ɉ�x�����Ăяo��)
// ================================================================================
void InputInit()
{
	for( int i=0; i < MY_INPUT_MAX; i++ )
	{
		m_state[i].old	= false;
		m_state[i].push	= false;
		m_state[i].on	= false;
		m_state[i].pull	= false;
	}
}

// ================================================================================
// ���͍X�V����
// ================================================================================
void InputUpdate()
{
	for( int i=0; i < MY_INPUT_MAX; i++ )
	{
		const bool now	= (CheckHitKey(KEY_ASSIGN[i]) == 1);

		m_state[i].on   = now;
		m_state[i].push = now & !m_state[i].old;
		m_state[i].pull = !(now & m_state[i].old);

		m_state[i].old = now;
	}
}

// ================================================================================
// �L�[�������ꂽ��
// ================================================================================
bool IsPushKey( int key )
{
	if( MY_INPUT_START <= key && key < MY_INPUT_END )
	{
		return m_state[key].push;
	}
	return false;
}

// ================================================================================
// �L�[����������Ă��邩
// ================================================================================
bool IsOnKey( int key )
{
	if( MY_INPUT_START <= key && key < MY_INPUT_END )
	{
		return m_state[key].on;
	}
	return false;
}

// ================================================================================
// �L�[�������ꂽ��
// ================================================================================
bool IsPullKey( int key )
{
	if( MY_INPUT_START <= key && key < MY_INPUT_END )
	{
		return m_state[key].pull;
	}
	return false;
}


bool DetectOnCursor(int cursor_x, int cursor_y, int origin_x, int origin_y, int offset_x, int offset_y)
{
	if ((cursor_x > origin_x && cursor_x < (origin_x + offset_x)) && (cursor_y > origin_y && cursor_y < (origin_y + offset_y)))
	{
		return true;
	}
	return false;
}


bool ClickMouse()
{








}










