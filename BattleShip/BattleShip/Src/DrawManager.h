#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H
// ================================================================================
// �`�揈���֐��Q
// ================================================================================
void DrawInit();	// �`�揈�������� (�Q�[���N�����Ɉ�x�����Ăяo��)
void DrawEnd();		// �`�揈���I���@ (�Q�[���I�����ADxLib_End�̑O�Ɉ�x�����Ăяo��)

void DrawCursor( int x, int y );			// �J�[�\����`��
void DrawSelectSquare(int x, int y);


void DrawDragGraphic(int x, int y);

#endif