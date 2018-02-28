#include "BlockData.h"




// �·� �̵�
void LeftMove(int(*arr)[12]) {
	// 1) ����ޱ�
	int n = 0;
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j < 11; j++) {
			if (arr[i][j] == 1) {
				arr[i][j] = 0;
				Block_pos[n].Pos.x = i;
				Block_pos[n].Pos.y = j;
				n++;
			}
		}
	}

	// 2) (�·�) ��迭�ϱ�
	for (int i = 0; i < 4; i++) {
		arr[Block_pos[i].Pos.x][Block_pos[i].Pos.y - 1] = 1;
	}
}


// ��� �̵�
void RightMove(int(*arr)[12]) {
	// 1) ����ޱ�
	int n = 0;
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j < 11; j++) {
			if (arr[i][j] == 1) {
				arr[i][j] = 0;
				Block_pos[n].Pos.x = i;
				Block_pos[n].Pos.y = j;
				n++;
			}
		}
	}

	// 2) (�·�) ��迭�ϱ�
	for (int i = 0; i < 4; i++) {
		arr[Block_pos[i].Pos.x][Block_pos[i].Pos.y + 1] = 1;
	}
}


// ȸ��
void Rotate(int(*arr)[12], int nType, BLOCK_POS* pos, int nRot) {
	
	switch (nType) {
	case 0:
		// 1) ����ޱ�
		int n = 0;
		for (int i = 1; i < 21; i++) {
			for (int j = 1; j < 11; j++) {
				if (arr[i][j] == 1) {
					arr[i][j] = 0;
					Block_pos[n].Pos.x = i;
					Block_pos[n].Pos.y = j;
					n++;
				}
			}
		}

		// 2) ȸ������ ��迭�ϱ�
		if (nRot % 2 != 0) {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (Block1[nRot][i][j] == 1) {
						arr[i + Block_pos[1].Pos.x-1][j + Block_pos[1].Pos.y] = Block1[nRot][i][j];
					}
				}
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (Block1[nRot][i][j] == 1) {
						arr[i + Block_pos[1].Pos.x-1][j + Block_pos[1].Pos.y - 2] = Block1[nRot][i][j]; // �迭��� ������ �������� ȸ�� �� ����� �������ش�.
					}
				}
			}
		}
		break;
	}
	
	

}