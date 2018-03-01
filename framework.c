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
#include "BlockSpwan.h"

#define LEFT 75 
#define RIGHT 77 
#define UP 72 
#define DOWN 80 

int nScore = 0; // �������� for ��������  
int nBlockType; // 0~6������ ��� ���� 
int nRot; // ȸ�� ������ ��ǥ 0,1,2,3,0,1,2,3,0,1,2,3.... ���ѹݺ�
int nSpawning; // 1�̸� �������� ��, 0�̸� �����غ�Ϸ�
int nSpeed; // �������� �ӵ� ����



void init() {
	// �� �迭 ���� 20x10
	PanMap(nArr); // 22x12�迭���� �𼭸����� �� ������� �켱 ä���.
	
	// ���n ����
	/*
	nBlockType = 0;
	int n = BlockSpwan();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			nArr[i + 1][j + 1] = Block1[0][i][j];
		}
	}
	*/
	nRot = 1;
	nSpawning = 0;
	nSpeed = 500; 
}


clock_t Oldtime = 0;
void Update() {
	clock_t Curtime = clock();

	// ��� �����ϱ� 
	// ���� 1,1 ��ǥ���� �����Ǿ� �����´�.
	if (nSpawning == 0) {
		BlockSpwan2(nArr, &nBlockType);
		nSpawning = 1;
	}






	// ��� ������
	//===================================
	int n = 0;
	if (Curtime - Oldtime > nSpeed) { // �������� �ӵ� ����
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

		// �浹ó��
		for (int i = 0; i < 4; i++) {
			if (nArr[Block_pos[i].Pos.x + 1][Block_pos[i].Pos.y] == 2) {// �������� �� ������ 2��� �浹...
				for (int j = 0; j < 4; j++) {
					nArr[Block_pos[j].Pos.x][Block_pos[j].Pos.y] = 2;
				}
				nSpawning = 0;
				nRot = 1;
				break;
			}
			// 2) ��ĭ���� ��迭�ϱ� ( ������ �浹���� �ʾҴٸ�)
			else if (i == 3) {
				for (int i = 0; i < 4; i++) {
					nArr[Block_pos[i].Pos.x + 1][Block_pos[i].Pos.y] = 1;
				}
			}
		}



	}
	//===================================
	
	// �ϼ��� �� �˻� �� ����
	int m = 0;
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j < 11; j++) {
			if (nArr[i][j] == 2) {
				m++;
			}
		}
		if (m == 10) { // �� �ϼ� ��
			nScore++; // 500�� �߰�
			for (int m = i; m >1; m--) {
				for (int n = 1; n < 11; n++) {
					nArr[m][n] = nArr[m-1][n];
				}
			}
		}
		m = 0;
	}

	// ���� �й� ���� - nArr�� 0�࿡ ���ο� 2�� ����ȴٸ� gg


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
	Map();


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
				int k = 1;
				if (nKey == 224) {
					nKey = _getch();
					switch (nKey) {
					case LEFT:
						Beep(200, 200);
						// ���� �浹ó��
						for (int i = 0; i < 4; i++) {
							if (nArr[Block_pos[i].Pos.x][Block_pos[i].Pos.y-1] == 2) { // �� ����.
								Beep(400, 200); 
								k = 0;
							}
						}
						// ���� �浹�ȵǸ� �� �� �ִ�.
						if (k) {
							LeftMove(nArr); // �·� �̵�
						}
						break;
					case RIGHT:
						Beep(200, 200);
						// ���� �浹ó��
						for (int i = 0; i < 4; i++) {
							if (nArr[Block_pos[i].Pos.x][Block_pos[i].Pos.y + 1] == 2) { // �� ����.
								Beep(400, 200);
								k = 0;
							}
						}
						// ���� �浹�ȵǸ� �� �� �ִ�.
						if (k) {
							RightMove(nArr); // ��� �̵�
						}
						break;
					case UP : // ȸ��
						Beep(200, 200);
						Rotate(nArr,nBlockType, Block_pos, nRot);
						if (nRot == 3) {
							nRot = -1;
						}
						nRot++;
						break;
					case DOWN: // �ٷ� ����������
						DownMove(nArr);
						nSpawning = 0;
						nRot = 1;
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