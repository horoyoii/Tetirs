// ��Ʈ���� // 

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>
#include<time.h>
#include"Screen.h""
#include"PanData.h"
#include "MapUI.h"
#include "BlockData.h"
#include "BlockMove.h"

#define LEFT 75 
#define RIGHT 77 
#define UP 72 
#define DOWN 80 

int nScore = 0; // �������� for ��������  
int nBlockType;
int nRot; // ȸ�� ������ ��ǥ 0,1,2,3,0,1,2,3,0,1,2,3.... ���ѹݺ�





void init() {
	// �� �迭 ���� 20x10
	PanMap(nArr); // 22x12�迭���� �𼭸����� �� ������� �켱 ä���.
	
	// ���0 ����
	nBlockType = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			nArr[i + 1][j + 1] = Block0[0][i][j];
		}
	}

	nRot = 1;
}


clock_t Oldtime = 0;
void Update() {
	clock_t Curtime = clock();

	//��� �¿� �����̱�






	// ��� ������
	//===================================
	int n = 0;
	if (Curtime - Oldtime > 1000) {
		Oldtime = Curtime;
		// 1) ����ޱ�
		for (int i = 1; i < 21; i++) {
			for (int j = 1; j < 11; j++) {
				if (nArr[i][j] == 1) {
					nArr[i][j] = 0;
					Block_pos[n].Pos.x = i;
					Block_pos[n].Pos.y = j;
					n++;
				}
			}
		}

		// 2) ��迭�ϱ�
		for (int i = 0; i < 4; i++) {
			nArr[Block_pos[i].Pos.x + 1][Block_pos[i].Pos.y] = 1;
		}
	}
	//===================================
	
	



}

void Render() {
	ScreenClear();
	//����ڵ�
	MapScore(&nScore);


	//=============================
	// �迭�� ���
	//=============================
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 12; j++) {
			if (nArr[i][j] == 2) {
				ScreenPrint( j*2, i, "��");
			}
			else if (nArr[i][j] == 1) {
				ScreenPrint(j * 2, i, "��");
			}
			else {
				ScreenPrint( j*2, i, "  ");
			}
		}
	}



	//==============================
	ScreenFlipping();
}

void Release() {

}

int main(void) {
	
	ScreenInit();
	init(); // �ʱ�ȭ
	
	while (1) {
		int nKey;
		while (1) {
			if (_kbhit()) {
				nKey = _getch();
				if (nKey == 224) {
					nKey = _getch();
					switch (nKey) {
					case LEFT:
						Beep(200, 200);
						LeftMove(nArr); // �·� �̵�
						break;
					case RIGHT:
						Beep(200, 200);
						RightMove(nArr); // ��� �̵�
						break;
					case UP : // ȸ��
						Beep(200, 200);
						Rotate(nArr,nBlockType, Block_pos, nRot);
						if (nRot == 3) {
							nRot = -1;
						}
						nRot++;
						break;
					}
				}
				
			}
			Update();  // ������ ����
			Render();  // ȭ�����
		}
	

		
	}
	Release(); // ����
	ScreenRelease();
	return 0;
}