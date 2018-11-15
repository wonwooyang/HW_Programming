#include <stdio.h>
#include <stdlib.h>
/*
1. 명세서 개수 입력 > 명세서 배열 동적 할당
		배열에는 명세서가 아니라 명세서의 주소값이 들어가야함 (포인터 배열)
2. 명세서 입력 > 명세서가 들어갈 메모리를 동적 할당
*/

struct Birth {
	int year, month, date;
};
struct Human {
	char name[20];
	struct Birth birth;
	char gender[20];
	char num[20];
};

void main() {
	printf_s("\n20180369 양원우\n");
	int Hnum;
	printf_s("\n입력할 명세서의 개수를 입력하시오 : ");
	scanf_s("%d", &Hnum);

	struct Human **pHarr = malloc(sizeof(struct Human*)*Hnum); // 포인터를 저장하는 포인터(배열)
	struct Human *pH = malloc(sizeof(struct Human));

	for (int i = 0; i < Hnum; i++) {
		printf_s("개별 명세서 입력 %d : ", i+1);

		//printf_s("\n\n Size of H(ptr) %d, H %d, pH %d", sizeof(struct Human*), sizeof(struct Human), sizeof(pH));
		//pH->birth.year  =  (*pH).birth.year
		scanf_s("%s", pH->name);
		scanf_s("%d/%d/%d", pH->birth.year, pH->birth.month, pH->birth.date); // "/" 만 제외하고 입력받기
		scanf_s("%s", pH->gender);
		scanf_s("%s", pH->num);

		pHarr[i] = pH;
	}

	printf("\n\n\nhuehuehue : %d", pHarr[0]->birth.year); // 시발 왜 안됨
}