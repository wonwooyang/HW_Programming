#include <stdio.h>
#include <math.h>
/*
Sum(�ڱⳢ��)
matrix�� index�� ����ؼ� > A[i][j]

Multiple
martix�� pointer�� ����ؼ� > ptr


pointer �� ����ؼ� 2X2 ��Ʈ���� ǥ��(å Ȯ��)

��Ʈ���� �̸��� �� �ּҰ�
��Ʈ���� ������ main ������
sum(a,b,c)
mult(a,b,c)
*/
int indexAddMat(int mat1[3][3], int mat2[3][3]);
int ptrProdMat(mat1, mat2);

main() {
	int mat1[3][3], mat2[3][3];
	
	printf_s("\n20180369 �����\n");
	printf_s("\n3X3 Matrix �� �Է�\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf_s("%d��° �� %d��° ĭ : ", i, j);
			scanf_s("%d", &mat1[i][j]);
		}
	}

	printf_s("\n==�Է� ��==\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf_s("%d  ", mat1[i][j]);
		}
		printf_s("\n");
	}

	indexAddMat(mat1, mat2);
	printf_s("\n==Sum==\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf_s("%d  ", mat2[i][j]);
		}
		printf_s("\n");
	}

	printf_s("\n==Product==\n");

	printf_s("");
}

int indexAddMat(int mat1[3][3], int mat2[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mat2[i][j] = mat1[i][j] + mat1[i][j];
		}
	}
}

int ptrProdMat(mat1, mat3) {
	return 0;
}
