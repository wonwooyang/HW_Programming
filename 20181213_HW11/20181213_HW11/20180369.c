#include <stdio.h>
#include <stdlib.h>

/*

한번 다 읽고 나면 close, fopen 하지말고 rewind 나 fseek(fp, 0, 0) offset, origin 둘다 0으로 넣어서 맨 처음으로 가져오기

file indicator 는 현재를 기준으로 4bite 씩 옮겨야지 다음 정수로 넘어갈 것임 > fseek 사용 / 읽을땐 getw
*/
void main() {
	printf("\n20180369 양원우\n");
	FILE *fp = NULL;
	int i = 0, arr[50];
	while (i < 50) {
		arr[i] = i * 3;
		i++;
	}
	fopen_s(&fp, "test.bin", "wb+");	
	if (fp == NULL) {
		printf("\n암튼 내 잘못은 아닌듯\n");
		exit(1);
	}
	fwrite(arr, sizeof(arr), 1, fp);
	fseek(fp, 0, 0);
	int get;

	printf("\n파일에서 출력한 자료 : \n");	
	for (i = 0; i < 50; i++) {
		fread(&get, sizeof(int), 1, fp);
		printf("%d ", get);
	}
	fseek(fp, 0, 0);
	
	printf("\n\n하나씩 건너뛴 자료 : \n");
	for (i = 0; i < 50; i+=2) {
		fread(&get, sizeof(int), 1, fp);
		printf("%d ", get);
		fseek(fp, (long)sizeof(int), SEEK_CUR);
	}	
}