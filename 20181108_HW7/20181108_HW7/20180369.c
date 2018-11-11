#include <stdio.h>
/*
입력은 3x3 행렬을 입력합니다.

 -출력은 입력된 행렬의 연산 결과를 출력합니다.

  -행렬 1개만 입력받아 같은 행렬 2개로 계산하거나 2개 다 입력받아 계산하거나 상관 없습니다.

  -행렬의 합은 Array Indexing, 곱은 Pointer 방식으로 접근해야 합니다. (Parameter는 행렬로 받아도 문제 없음)
*/
int indexAddMat(int mat1[3][3], int mat2[3][3]);
int ptrProdMat(mat1, mat2);

void main() {
	int mat1[3][3], mat2[3][3];

	printf_s("\n20180369 양원우\n");
	printf_s("\n==3X3 Matrix 을 입력==\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf_s("%d번째 행 %d번째 열 : ", i, j);
			scanf_s("%d", &mat1[i][j]);
		}
	}

	printf_s("\n==입력 값==\n");
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
			*(*(pmat2 + i) + j) = 0; // mat2 에 sum 연산값이 들어가있음 >> 0으로 초기화
			for (int k = 0; k < 3; k++) {
				*(*(pmat2 + i) + j) += (*(*(pmat1 + i) + k) * *(*(pmat1 + k) + j));				
			}
		}
	}
	return 0;
}