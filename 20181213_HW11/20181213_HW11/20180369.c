#include <stdio.h>
#include <stdlib.h>

/*

�ѹ� �� �а� ���� close, fopen �������� rewind �� fseek(fp, 0, 0) offset, origin �Ѵ� 0���� �־ �� ó������ ��������

file indicator �� ���縦 �������� 4bite �� �Űܾ��� ���� ������ �Ѿ ���� > fseek ��� / ������ getw
*/
void main() {
	printf("\n20180369 �����\n");
	FILE *fp = NULL;
	int i = 0, arr[50];
	while (i < 50) {
		arr[i] = i * 3;
		i++;
	}
	fopen_s(&fp, "test.bin", "wb+");	
	if (fp == NULL) {
		printf("\n��ư �� �߸��� �ƴѵ�\n");
		exit(1);
	}
	fwrite(arr, sizeof(arr), 1, fp);
	fseek(fp, 0, 0);
	int get;

	printf("\n���Ͽ��� ����� �ڷ� : \n");	
	for (i = 0; i < 50; i++) {
		fread(&get, sizeof(int), 1, fp);
		printf("%d ", get);
	}
	fseek(fp, 0, 0);
	
	printf("\n\n�ϳ��� �ǳʶ� �ڷ� : \n");
	for (i = 0; i < 50; i+=2) {
		fread(&get, sizeof(int), 1, fp);
		printf("%d ", get);
		fseek(fp, (long)sizeof(int), SEEK_CUR);
	}	
}