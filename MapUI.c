// Map.h
//========================
// ���� UI�� �����ϴ� �κ�
//========================
#define _CRT_SECURE_NO_WARNINGS
#include "MapUI.h"
#include "Screen.h"
#include <stdio.h>

// ��ü Ʋ
void Map(void) {
	ScreenPrint(0, 0, "�������������");
	for (int i = 1; i < 21; i++) {
		ScreenPrint(0, i, "��                    ��");
	}
	ScreenPrint(0, 21, "�������������");
}

// ���� Ʋ
void MapScore(int* nScore) {
	char chScore[10];
	sprintf(chScore, "Score : %d", *nScore);
	ScreenPrint(25, 10, chScore);
}