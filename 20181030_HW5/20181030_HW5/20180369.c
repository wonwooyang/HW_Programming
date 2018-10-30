#include <stdio.h>
/*
3~20(40 이었나) 까지 홀수들 전부 fibo 출력

E-class 과제
	입력 : 없음
	출력 : 3~45 까지의 모든 홀수 fibo 출력


*/
int rfibo(int n);
int sfibo(int n);

void main() {
	int start = 4, end = 45;
	printf("\n20180369 양원우\n");
	printf("\n 3 ~ 45 사이의 모든 홀수번째 피보나치 수열을 출력합니다\n");

	for (int i = 3; i <= end; i += 2) {
		printf("\n%d : ", i);
		printf("%d", rfibo(i));
	}

	/*
	// 3 ~ 45 사이의 피보나치 수열 출력
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