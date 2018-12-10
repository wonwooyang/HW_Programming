#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
	printf_s("\n20180369 �����\n");
	if (argc != 2) {
		printf("\n���� ���� : ���� �̸����� ��Ȯ�� �Է��ϼ��� (Ex: myfile.txt)\n");
		system("pause > nul");
		return 1;
	}

	vals counts = { 0, 0, 0 };
	int err1, err2;
	FILE *fp1, *fp2;

	err1 = fopen_s(&fp1, "OSParadigmShift.txt", "r");
	err2 = fopen_s(&fp2, "OSParadigmShift.rev", "w");

	if (err1 != 0 || err2 != 0) {
		printf_s("\n���� ���� ���� : Ȥ�� �ش� ������ ���� ������ ���� �� �ƴմϱ�?\n");
		return 1;
	}

	fclose(fp1);
	fclose(fp2);

	counts = count(fp1);
	printf_s("\n  <Count Result>\n");
	printf("\n Line count : %d\n Word count : %d\n Char count : %d\n", counts.lc, counts.wc, counts.cc);

	printf_s("\n  <Upper <-> Lower>\n");
	revf(fp1, fp2);
	printf("\n����� ������ OSParadigmShift.rev �� ����Ǿ����ϴ�.\n\n");
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