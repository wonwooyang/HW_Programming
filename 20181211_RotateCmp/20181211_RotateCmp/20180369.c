#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*
랜덤 길이의 String 을 랜덤으로 할당받음 1~10000
Rotate distance 를 랜덤으로 할당받음 -5000~+5000  - left + right

trival
juggle
bw
reverse

필요한 함수
1. 문자열 동적할당 생성 함수	int size >> char* str
	생성된 문자열은 random 으로 생성된 알파벳 대문자로 이루어짐
2. 각 회전함수 > 총 4개		char* coppiedstr >> char* rotatedstr
3. 시간측정 함수???
XXXX 4. 출력 함수					int size, int Rdis, char* rotatedstr, elapsedTime >> 출력
5. 메인함수
	비교 표 이름 출력
	for loop
		문자열 길이, 회전수 랜덤 생성
		길이를 바탕으로 문자열 동적할당 및 생성
		생성된 문자열을 같은 길이의 문자열로 복사
		복사된 문자열을 각 회전함수에 넣기 > 돌린후에 다시 복사하여 문자열 복구
		회전결과 출력함수
6. 일단 4개 함수는 먼저 *char 반환값으로 정상작동을 확인 > 이후에 int time 반환하는 함수로 변경
*/
char* ranstr(int size);
int gcd(int a, int b);
void swap(int str[], int fi, int si, int d);
void rvereseArray(char* str, int start, int end);
void trivial(char* str, int rdis, int size);
void juggle(char* str, int rdis, int size);
void blockswap(char* str, int rdis, int size);
void reverse(char* str, int rdis, int size);

int main() {
	int size = 0, rdis = 0, tt = 0, jt = 0, bt = 0, rt = 0;
	char *str_org = NULL;
	srand(time(NULL));

	printf("\n\t\t\t\t\t\tElapsed time(measured) for 4 rotate");
	printf("\n STR length\tROTATE distance\t\tT.trivial\tT.juggle\tT.bw\t\tT.reverse");
	   

	str_org = "abcdefgh";
	size = 7;
	rdis = 3;
	printf("\n%s\n", str_org);
	juggle(str_org, rdis, size);
	printf("\n%s\n",str_org);

	/*
	for (int i = 0; i < 20; i++) {
		size = (rand() % 10000) + 1;
		rdis = (rand() % 10001) - 5000;
		printf("\nsize : %d\trdis : %d", size, rdis);

		str_org = ranstr(size);
		//나중에는 tt=trival(); 로 걸린 시간만 가져와서 출력할거
		//printf("\nCHK1\n");
		//trivial(str_org, rdis, size);

		//printf("\nCHK2\n");
		//juggle(str_org, rdis, size);

		//printf("\nCHK3\n");
		//blockswap(str_org, rdis, size);

		//printf("\nCHK4\n");
		//reverse(str_org, rdis, size);
		
		printf("\n %d\t\t%d\t\t\t%d\t\t%d\t\t%d\t\t%d", size, rdis, tt, jt, bt, rt);
		
	}*/
	printf("\n\n\n");
	return 0;
}
char* ranstr(int size) {	
	char *ranstr = NULL;
	ranstr = (char*)malloc(sizeof(char)*size);
	for (int i = 0; i < size; i++) {
		ranstr[i] = 'a' + (rand() % 26);
	}
	ranstr[size] = '\0';
	return ranstr;
}
void trivial(char* str, int rdis, int size) {
	char first;
	if (rdis > 0) {
		rdis = size - rdis;
	}
	for (int i = 0; i < rdis; i++) {
		first = str[0];
		for (int j = 0; j < size - 1; j++) {
			str[j] = str[j + 1];
		}		
		str[size - 1] = first;
	}
}
int gcd(int a, int b) {
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return abs(a);
}
void juggle(char* str, int rdis, int size) {
	int i, j, k, temp;
	for (i = 0; i < gcd(rdis, size); i++) {
		temp = str[i];
		j = i;
		while (1) {
			k = j + rdis;
			if (k >= size)
				k = k - size;
			if (k == i)
				break;
			str[j] = str[k];
			j = k;
		}
		str[j] = temp;
	}
}
/*This function swaps d elements starting at index fi 
  with d elements starting at index si */
void swap(char* str, int fi, int si, int d)
{
	int i, temp;
	for (i = 0; i < d; i++)
	{
		temp = str[fi + i];
		str[fi + i] = str[si + i];
		str[si + i] = temp;
	}
}
void blockswap(char* str, int rdis, int size) {
	if (rdis > 0) {
		rdis = size - rdis;
	}
	/* Return If number of elements to be rotated is
	zero or equal to array size */
	if (rdis == 0 || rdis == size)
		return;

	/*If number of elements to be rotated is exactly
	  half of array size */
	if (size - rdis == rdis)
	{
		swap(str, 0, size - rdis, rdis);
		return;
	}

	/* If A is shorter*/
	if (rdis < size - rdis)
	{
		swap(str, 0, size - rdis, rdis);
		blockswap(str, rdis, size - rdis);
	}
	else /* If B is shorter*/
	{
		swap(str, 0, rdis, size - rdis);
		blockswap(str + size - rdis, 2 * rdis - size, rdis); /*This is tricky*/
	}
}
void rvereseArray(char* str, int start, int end)
{
	int temp;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

void reverse(char* str, int rdis, int size) { 
	if (rdis > 0) {
		rdis = size - rdis;
	}
	rvereseArray(str, 0, rdis - 1);
	rvereseArray(str, rdis, size - 1);
	rvereseArray(str, 0, size - 1);
}