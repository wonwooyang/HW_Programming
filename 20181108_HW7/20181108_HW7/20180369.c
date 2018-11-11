#include <stdio.h>
/*
�Է��� 3x3 ����� �Է��մϴ�.

 -����� �Էµ� ����� ���� ����� ����մϴ�.

  -��� 1���� �Է¹޾� ���� ��� 2���� ����ϰų� 2�� �� �Է¹޾� ����ϰų� ��� �����ϴ�.

  -����� ���� Array Indexing, ���� Pointer ������� �����ؾ� �մϴ�. (Parameter�� ��ķ� �޾Ƶ� ���� ����)
*/
int indexAddMat(int mat1[3][3], int mat2[3][3]);
int ptrProdMat(mat1, mat2);

void main() {
	int mat1[3][3], mat2[3][3];

	printf_s("\n20180369 �����\n");
	printf_s("\n==3X3 Matrix �� �Է�==\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf_s("%d��° �� %d��° �� : ", i, j);
			scanf_s("%d", &mat1[i][j]);
		}
	}

	printf_s("\n==�Է� ��==\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf_s("%3d  ", mat1[i][j]);
		}
		printf_s("\n");
	}

	indexAddMat(mat1, mat2);
	printf_s("\n==Self Sum==\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf_s("%3d  ", mat2[i][j]);
		}
		printf_s("\n");
	}

	ptrProdMat(mat1, mat2);
	printf_s("\n==Self Product==\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf_s("%3d  ", mat2[i][j]);
		}
		printf_s("\n");
	}
}

int indexAddMat(int mat1[3][3], int mat2[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mat2[i][j] = mat1[i][j] + mat1[i][j];
		}
	}
	return 0;
}

int ptrProdMat(mat1, mat2) {
	int(*pmat1)[3] = mat1;
	int(*pmat2)[3] = mat2;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			*(*(pmat2 + i) + j) = 0; // mat2 �� sum ���갪�� ������ >> 0���� �ʱ�ȭ
			for (int k = 0; k < 3; k++) {
				*(*(pmat2 + i) + j) += (*(*(pmat1 + i) + k) * *(*(pmat1 + k) + j));				
			}
		}
	}
	return 0;
}