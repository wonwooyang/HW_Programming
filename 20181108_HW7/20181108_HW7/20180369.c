#include <stdio.h>
#include <math.h>
/*
Sum(자기끼리)
matrix의 index를 사용해서 > A[i][j]

Multiple
martix의 pointer를 사용해서 > ptr


pointer 를 사용해서 2X2 매트릭스 표현(책 확인)

매트릭스 이름이 곧 주소값
매트릭스 선언은 main 에서만
sum(a,b,c)
mult(a,b,c)
*/
int indexAddMat(int mat1[3][3], int mat2[3][3]);
int ptrProdMat(mat1, mat2);

main() {
	int mat1[3][3], mat2[3][3];
	
	printf_s("\n20180369 양원우\n");
	printf_s("\n3X3 Matrix 을 입력\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf_s("%d번째 줄 %d번째 칸 : ", i, j);
			scanf_s("%d", &mat1[i][j]);
		}
	}

	printf_s("\n==입력 값==\n");
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
