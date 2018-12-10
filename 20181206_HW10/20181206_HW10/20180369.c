#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Line count
word count
character count
대문자 <-> 소문자 변환 후
확장자만 .rev 로 바꿔서 저장

--.rev 내용 출력

라인카운트 > 라인단위로 읽음
워드카운트 > 토큰단위로 잘라서 갯수 측정 > string 라이브러리 사용
케릭터카운트 > 워드 단위에서 length 사용 > 공백 만 빼고 나머지 다 카운트
*/
typedef struct Values
{
	int lc;
	int wc;
	int cc;
}vals;

vals count(FILE *fp1);
void revf(FILE *fp1, FILE *fp2);
char* atoA(char *str);

int main(int argc, char *argv[]) {
	printf_s("\n20180369 양원우\n");
	if (argc != 2) {
		printf("\n실행 실패 : 파일 이름만을 정확히 입력하세요 (Ex: myfile.txt)\n");
		system("pause > nul");
		return 1;
	}

	vals counts = { 0, 0, 0 };
	int err1, err2;
	FILE *fp1, *fp2;

	err1 = fopen_s(&fp1, "OSParadigmShift.txt", "r");
	err2 = fopen_s(&fp2, "OSParadigmShift.rev", "w");

	if (err1 != 0 || err2 != 0) {
		printf_s("\n파일 열기 실패 : 혹시 해당 파일이 같은 폴더에 없는 것 아닙니까?\n");
		return 1;
	}

	fclose(fp1);
	fclose(fp2);

	counts = count(fp1);
	printf_s("\n  <Count Result>\n");
	printf("\n Line count : %d\n Word count : %d\n Char count : %d\n", counts.lc, counts.wc, counts.cc);

	printf_s("\n  <Upper <-> Lower>\n");
	revf(fp1, fp2);
	printf("\n변경된 내용이 OSParadigmShift.rev 에 저장되었습니다.\n\n");
	system("pause > nul");
	return 0;
}
vals count(FILE *fp1) {
	vals counting = { 0, 0, 0 };
	char readstr[300];

	fopen_s(&fp1, "OSParadigmShift.txt", "r");
	
	while (fgets(readstr, 300, fp1) != NULL) {
		char *context;
		char *sptr = strtok_s(readstr, " ", &context);

		while (sptr != NULL) {
			counting.cc += strlen(sptr);
			sptr = strtok_s(NULL, " ", &context);
			counting.wc++;
		}
		counting.lc++;
	};
	fclose(fp1);
	
	return counting;
}
void revf(FILE *fp1, FILE *fp2) {
	char readstr[300];

	fopen_s(&fp1, "OSParadigmShift.txt", "r");
	fopen_s(&fp2, "OSParadigmShift.rev", "w");

	while (fgets(readstr, 300, fp1) != NULL) {
		strcpy_s(readstr, 300, atoA(readstr));
		fputs(readstr, fp2);
	}
	fclose(fp1);
	fclose(fp2);
}
char* atoA(char *str) {
	for (int i = 0; i < 300; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32;
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 32;
		}
	}
	return str;
}