#include <stdio.h>
#include <string.h>

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

void main() {
	printf_s("\n20180369 양원우\n");
	int lc, wc, cc;
	char readstr[300];
	FILE *fp1, *fp2;

	fopen(&fp1, "OSParadigmShift.txt", "r"); 
	fopen(&fp2, "OSParadigmShift.rev", "w");
	if (fp1 && fp2) {
		printf_s("\n파일 열림\n");
	}
	else {
		printf_s("\n파일 안열림\n");
	}
	
	char * sptr = strtok(;
	while (fgets(fp1, 300, readstr) != EOF) {

		strtok()
		
		//strtok 사용 delimeter 로 여러개 넣어서 word 단위로 자르기 https://dojang.io/mod/page/view.php?id=376 참고
		//str 라이브러리를 씁시다
		lc++;
	};
	
	fclose(fp1);
	
	printf_s("\n<Count Result>\n");
}


/*
void reverse(FILE * fp);
void main() {
	printf_s("\n20180369 양원우\n");
	char name[20], email[20];
	FILE *fp;

	printf_s("\n\n이름과 email 주소를 입력하세요.\n이름 : ");
	scanf_s("%s", name, sizeof(name));
	printf_s("주소 : ");
	scanf_s("%s", email, sizeof(email));

	fopen_s(&fp, "myinfo.txt", "w");
	if (fp) {
		printf_s("\n파일 W열기 성공\n");
	}
	else {
		printf_s("\n파일 W열기 실패\n");
	}

	fputs(name, fp);
	fputs("\n", fp);
	fputs(email, fp);

	fclose(fp);

	reverse(fp);
}
void reverse(FILE * fp) {
	char readstr[40];
	fopen_s(&fp, "myinfo.txt", "r"); 
	if (fp) {
		printf_s("\n파일 R열기 성공\n");
	}
	else {
		printf_s("\n파일 R열기 실패\n");
	}

	fgets(readstr, 40, fp);
	puts(readstr); // 이거 reverse 만 해둠
	fclose(fp);
}
*/