#include <stdio.h>
#include <stdlib.h>
/*
1. ���� ���� �Է� > ���� �迭 ���� �Ҵ�
		�迭���� ������ �ƴ϶� ������ �ּҰ��� ������ (������ �迭)
2. ���� �Է� > ������ �� �޸𸮸� ���� �Ҵ�
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
	printf_s("\n20180369 �����\n");
	int Hnum;
	printf_s("\n�Է��� ������ ������ �Է��Ͻÿ� : ");
	scanf_s("%d", &Hnum);

	struct Human **pHarr = malloc(sizeof(struct Human*)*Hnum); // �����͸� �����ϴ� ������(�迭)
	struct Human *pH = malloc(sizeof(struct Human));

	for (int i = 0; i < Hnum; i++) {
		printf_s("���� ���� �Է� %d : ", i+1);

		//printf_s("\n\n Size of H(ptr) %d, H %d, pH %d", sizeof(struct Human*), sizeof(struct Human), sizeof(pH));
		//pH->birth.year  =  (*pH).birth.year
		scanf_s("%s", pH->name);
		scanf_s("%d/%d/%d", pH->birth.year, pH->birth.month, pH->birth.date); // "/" �� �����ϰ� �Է¹ޱ�
		scanf_s("%s", pH->gender);
		scanf_s("%s", pH->num);

		pHarr[i] = pH;
	}

	printf("\n\n\nhuehuehue : %d", pHarr[0]->birth.year); // �ù� �� �ȵ�
}