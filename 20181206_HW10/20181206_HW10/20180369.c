#include <stdio.h>
#include <string.h>

/*

Line count
word count
character count
�빮�� <-> �ҹ��� ��ȯ ��
Ȯ���ڸ� .rev �� �ٲ㼭 ����

--.rev ���� ���

����ī��Ʈ > ���δ����� ����
����ī��Ʈ > ��ū������ �߶� ���� ���� > string ���̺귯�� ���
�ɸ���ī��Ʈ > ���� �������� length ��� > ���� �� ���� ������ �� ī��Ʈ
*/

void main() {
	printf_s("\n20180369 �����\n");
	int lc, wc, cc;
	char readstr[300];
	FILE *fp1, *fp2;

	fopen(&fp1, "OSParadigmShift.txt", "r"); 
	fopen(&fp2, "OSParadigmShift.rev", "w");
	if (fp1 && fp2) {
		printf_s("\n���� ����\n");
	}
	else {
		printf_s("\n���� �ȿ���\n");
	}
	
	char * sptr = strtok(;
	while (fgets(fp1, 300, readstr) != EOF) {

		strtok()
		
		//strtok ��� delimeter �� ������ �־ word ������ �ڸ��� https://dojang.io/mod/page/view.php?id=376 ����
		//str ���̺귯���� ���ô�
		lc++;
	};
	
	fclose(fp1);
	
	printf_s("\n<Count Result>\n");
}


/*
void reverse(FILE * fp);
void main() {
	printf_s("\n20180369 �����\n");
	char name[20], email[20];
	FILE *fp;

	printf_s("\n\n�̸��� email �ּҸ� �Է��ϼ���.\n�̸� : ");
	scanf_s("%s", name, sizeof(name));
	printf_s("�ּ� : ");
	scanf_s("%s", email, sizeof(email));

	fopen_s(&fp, "myinfo.txt", "w");
	if (fp) {
		printf_s("\n���� W���� ����\n");
	}
	else {
		printf_s("\n���� W���� ����\n");
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
		printf_s("\n���� R���� ����\n");
	}
	else {
		printf_s("\n���� R���� ����\n");
	}

	fgets(readstr, 40, fp);
	puts(readstr); // �̰� reverse �� �ص�
	fclose(fp);
}
*/