#include <stdio.h>
/*
3~20(40 이었나) 까지 홀수들 전부 fibo 출력

E-class 과제
	입력 : 없음
	출력 : 3~45 번째까지의 모든 홀수번째 fibo 출력
*/
static int f2, f3;
static int f1= 1;
int rfibo(int n);
int sfibo(int n);

void main() {
	int start = 4, end = 45, rf = 0, sf = 0, num = 0;
	printf("\n20180369 양원우\n");
	printf("\n 3 에서 45 번째 까지의 모든 홀수번째 피보나치 수열을 출력합니다\n");
	printf("\nn번째\tRecursive\tStatic\n");

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
	//초기값 > 0,1 을 넣어줘야함
	//f2 = 1;
	f3 = f1 + f2;
	f1 = f2;
	f2 = f3;

	return f3;
}