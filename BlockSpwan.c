#include<time.h>
#include<stdlib.h>
#include"BlockData.h"

// ��� ��� ����
int BlockSpwan(void) {
	srand(time(NULL));
	return rand() % 7; // 0~6����...

}



// ������ ��� �� ������ ����ϱ�
void BlockSpwan2(int(*arr)[12], int* nType) {
	//*nType = BlockSpwan();

	switch (*nType) {
	case  0:
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				arr[i][j+4] = Block0[0][i][j];
			}
		}
		break;
	case 1:
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				arr[i][j + 4] = Block1[0][i][j];
			}
		}
		break;
	case 2:
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				arr[i][j + 4] = Block2[0][i][j];
			}
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				arr[i][j + 4] = Block3[0][i][j];
			}
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				arr[i][j +4] = Block4[0][i][j];
			}
		}
		break;
	case 5:
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				arr[i][j + 4] = Block5[0][i][j];
			}
		}
		break;
	case 6:
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				arr[i][j + 4] = Block6[0][i][j];
			}
		}
		break;
	}
}