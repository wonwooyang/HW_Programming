#include <stdio.h>
/*
3~20(40 �̾���) ���� Ȧ���� ���� fibo ���

E-class ����
	�Է� : ����
	��� : 3~45 ������ ��� Ȧ�� fibo ���


*/
int rfibo(int n);
int sfibo(int n);

void main() {
	int start = 4, end = 45;
	printf("\n20180369 �����\n");
	printf("\n 3 ~ 45 ������ ��� Ȧ����° �Ǻ���ġ ������ ����մϴ�\n");

	for (int i = 3; i <= end; i += 2) {
		printf("\n%d : ", i);
		printf("%d", rfibo(i));
	}

	/*
	// 3 ~ 45 ������ �Ǻ���ġ ���� ���
	while (rfibo(start) <= end) {
		printf("%d  ", rfibo(start));
		start++;
	}
	*/
	printf("\n");
}

int rfibo(int n) {
	if (n < 2) {
		return n;
	}
	return rfibo(n - 1) + rfibo(n - 2);
}