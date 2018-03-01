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
	for (int i = 1; i < 18; i++) {
		ScreenPrint(0, i, "��");
		ScreenPrint(22, i, "��");
	}
	ScreenPrint(0, 18, "�������������");
}

// ���� Ʋ
void MapScore(int* nScore) {
	char chScore[15];
	sprintf(chScore, "Score : %d", (*nScore)*500);
	ScreenPrint(25, 10, chScore);
}

void MapNext(void) {
	//
}


// �غ��
void MapReady1(void) {
	ScreenPrint(6, 5, "T E T R I S");
}

// �غ��
void MapReady2(void) {

	ScreenPrint(4, 10, "Press Enter" );
	ScreenPrint(12, 11, "to Start");
}

//�����
void MapResult(int* nScore) {

	ScreenPrint(5, 5, "Game Over~");
	char chScore[15];
	sprintf(chScore, "Score : %d", (*nScore) * 500);
	ScreenPrint(5, 10, chScore);
	for (int i = 1; i < 11; i++) {
		ScreenPrint(i*2, 17, "  ");
	}

}