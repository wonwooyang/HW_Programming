#include <stdio.h>
/*
3~20(40 �̾���) ���� Ȧ���� ���� fibo ���

E-class ����
	�Է� : ����
	��� : 3~45 ��°������ ��� Ȧ����° fibo ���
*/
static int f2, f3;
static int f1= 1;
int rfibo(int n);
int sfibo(int n);

void main() {
	int start = 4, end = 45, rf = 0, sf = 0, num = 0;
	printf("\n20180369 �����\n");
	printf("\n 3 ���� 45 ��° ������ ��� Ȧ����° �Ǻ���ġ ������ ����մϴ�\n");
	printf("\nn��°\tRecursive\tStatic\n");

	for (int i = 0; i <= 45; i ++) {
		rf = rfibo(i);
		sf = sfibo(i);
		num = i+2;
		if (num%2==1) {
			printf("\n%d\t", num);
			printf("%d\t\t", rf);
			printf("%d", sf);
		}
	}
	printf("\n");
}

int rfibo(int n) {
	if (n < 2) {
		return 1;
	}
	return rfibo(n - 1) + rfibo(n - 2);
}

int sfibo(int n) {
	//static int f1, f2, f3;
	//�ʱⰪ > 0,1 �� �־������
	//f2 = 1;
	f3 = f1 + f2;
	f1 = f2;
	f2 = f3;

	return f3;
}