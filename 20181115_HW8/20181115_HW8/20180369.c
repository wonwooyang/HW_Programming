#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
1. ���� ���� �Է� > ���� �迭 ���� �Ҵ�
		�迭���� ������ �ƴ϶� ������ �ּҰ��� ������ (������ �迭)
2. ���� �Է� > ������ �� �޸𸮸� ���� �Ҵ�
*/

int prtList(struct Human* Harr[], int size);
int swap(struct Human *H1, struct Human *H2);
int sort(struct Human* Harr[], int size, int chk);

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
	printf_s("\n20180369 ����� 8���� �ǽ�����\n");
	int Hsize;
	printf_s("\n�Է��� ������ ������ �Է��Ͻÿ�(7~10) : ");
	scanf_s("%d", &Hsize);
	if (Hsize < 7 || Hsize > 10) {
		printf_s("\n 7 ���� 10 ������ ������ �Է��ϼ���\n");
		exit(1);
	}
	//struct Human *pH = malloc(sizeof(struct Human));
	struct Human **pHarr = (struct Human**)malloc(sizeof(struct Human*)*Hsize); // �����͸� �����ϴ� ������(�迭)
	for (int i = 0; i < Hsize; i++) {
		pHarr[i] = malloc(sizeof(struct Human));
	}	
	printf_s("\n�Է¾�� : �̸� �������(YYYY MM DD) ����(����/����) ��ȭ��ȣ(01012345678)\n\n");
	for (int i = 0; i < Hsize; i++) {
		char str[20];
		int year, month, date;
		printf_s("���� ���� �Է� %d/%d : ", i+1, Hsize);
		scanf_s("%s", str, 20);
		strcpy(pHarr[i]->name, str);
		scanf_s("%d %d %d", &year, &month, &date);
		pHarr[i]->birth.year = year;
		pHarr[i]->birth.month = month;
		pHarr[i]->birth.date = date;
		scanf_s("%s", str, 20);
		strcpy(pHarr[i]->gender, str);
		scanf_s("%s", str, 20);
		strcpy(pHarr[i]->num, str);		
	}

	printf_s("\n\n=========== �Ż���� ===========\n");
	prtList(pHarr, Hsize);
	printf_s("\n\n========== �̸� (��->��) ==========\n");
	sort(pHarr, Hsize, 0);
	prtList(pHarr, Hsize);
	printf_s("\n\n======== ������� (L->H) ========\n");
	sort(pHarr, Hsize, 1);
	prtList(pHarr, Hsize);
	printf_s("\n\n");
}

int prtList(struct Human* Harr[], int size) {//�Ż���� ���
	printf_s("\n�̸�\t\t�������\t����\t��ȭ��ȣ\n");
	for (int i = 0; i < size; i++) {
		printf_s("\n%s\t\t%4d-%02d-%02d\t%c%c\t", Harr[i]->name, Harr[i]->birth.year, Harr[i]->birth.month, Harr[i]->birth.date, Harr[i]->gender[0], Harr[i]->gender[1]);
		for (int j = 0; j < strlen(Harr[i]->num); j++) {
			if (j == 3 || j == 7) {
				printf_s("-%c", Harr[i]->num[j]);
			}
			else
				printf_s("%c", Harr[i]->num[j]);
		}
	}
}

int swap(struct Human *H1, struct Human *H2) {
	struct Human temp;
	temp = *H1;
	*H1 = *H2;
	*H2 = temp;
	return 0;
}

//0 > �̸���, 1 > ������ϼ� ����
int sort(struct Human* Harr[], int size, int chk) {
	if (chk == 0) {//�̸��� H > L
		for (int i = 0; i < size - 1; i++) {// Selction sort
			for (int j = i + 1; j < size; j++) {
				if (strcmp(Harr[i]->name, Harr[j]->name) < 0) {
					swap(Harr[i], Harr[j]); //no chg
				}
			}
		}
	}
	else if (chk == 1) {//������� L > H
		for (int i = 0; i < size - 1; i++) {// Selction sort
			for (int j = i + 1; j < size; j++) {
				if (Harr[i]->birth.year > Harr[j]->birth.year) {//Y �ٸ�
					swap(Harr[i], Harr[j]);
				}
				else if (Harr[i]->birth.year == Harr[j]->birth.year) {
					if (Harr[i]->birth.month > Harr[j]->birth.month) {//Y ���� M �ٸ�
						swap(Harr[i], Harr[j]);
					}
					else if (Harr[i]->birth.month == Harr[j]->birth.month) {
						if (Harr[i]->birth.date > Harr[j]->birth.date) {//Y M ���� D �ٸ�
							swap(Harr[i], Harr[j]);
						}
						else {//Y M D ����
						}
					}
				}
			}
		}
	}
}
