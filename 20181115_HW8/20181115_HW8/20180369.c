#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
1. 명세서 개수 입력 > 명세서 배열 동적 할당
		배열에는 명세서가 아니라 명세서의 주소값이 들어가야함 (포인터 배열)
2. 명세서 입력 > 명세서가 들어갈 메모리를 동적 할당
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
	printf_s("\n20180369 양원우 8주차 실습과제\n");
	int Hsize;
	printf_s("\n입력할 명세서의 개수를 입력하시오(7~10) : ");
	scanf_s("%d", &Hsize);
	if (Hsize < 7 || Hsize > 10) {
		printf_s("\n 7 에서 10 사이의 정수를 입력하세요\n");
		exit(1);
	}
	//struct Human *pH = malloc(sizeof(struct Human));
	struct Human **pHarr = (struct Human**)malloc(sizeof(struct Human*)*Hsize); // 포인터를 저장하는 포인터(배열)
	for (int i = 0; i < Hsize; i++) {
		pHarr[i] = malloc(sizeof(struct Human));
	}	
	printf_s("\n입력양식 : 이름 생년월일(YYYY MM DD) 성별(남자/여자) 전화번호(01012345678)\n\n");
	for (int i = 0; i < Hsize; i++) {
		char str[20];
		int year, month, date;
		printf_s("개별 명세서 입력 %d/%d : ", i+1, Hsize);
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

	printf_s("\n\n=========== 신상명세서 ===========\n");
	prtList(pHarr, Hsize);
	printf_s("\n\n========== 이름 (ㅎ->ㄱ) ==========\n");
	sort(pHarr, Hsize, 0);
	prtList(pHarr, Hsize);
	printf_s("\n\n======== 생년월일 (L->H) ========\n");
	sort(pHarr, Hsize, 1);
	prtList(pHarr, Hsize);
	printf_s("\n\n");
}

int prtList(struct Human* Harr[], int size) {//신상명세서 출력
	printf_s("\n이름\t\t생년월일\t성별\t전화번호\n");
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

//0 > 이름순, 1 > 생년월일순 정렬
int sort(struct Human* Harr[], int size, int chk) {
	if (chk == 0) {//이름순 H > L
		for (int i = 0; i < size - 1; i++) {// Selction sort
			for (int j = i + 1; j < size; j++) {
				if (strcmp(Harr[i]->name, Harr[j]->name) < 0) {
					swap(Harr[i], Harr[j]); //no chg
				}
			}
		}
	}
	else if (chk == 1) {//생년월일 L > H
		for (int i = 0; i < size - 1; i++) {// Selction sort
			for (int j = i + 1; j < size; j++) {
				if (Harr[i]->birth.year > Harr[j]->birth.year) {//Y 다름
					swap(Harr[i], Harr[j]);
				}
				else if (Harr[i]->birth.year == Harr[j]->birth.year) {
					if (Harr[i]->birth.month > Harr[j]->birth.month) {//Y 동일 M 다름
						swap(Harr[i], Harr[j]);
					}
					else if (Harr[i]->birth.month == Harr[j]->birth.month) {
						if (Harr[i]->birth.date > Harr[j]->birth.date) {//Y M 동일 D 다름
							swap(Harr[i], Harr[j]);
						}
						else {//Y M D 동일
						}
					}
				}
			}
		}
	}
}
