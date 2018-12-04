#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};
void prtnd(struct node* head);
void prtndM(struct node* head, int mid);
void prtndR(struct node* head, int last);
void delodd(struct node* head, int size);

void main() {
	printf_s("\n20180369 양원우\n");
	typedef struct node node;
	node *head = NULL, *nd = NULL, *last = NULL;
	int key = 0, count = 0, num = 0, eoeo=0;
	printf("\n== 정수를 입력하세요 ==\n== Ctrl+Z, Enter 를 3번 반복하면 종료됩니다 ==\n");
	while (1) {
		if (scanf_s("%d", &num) == EOF) {
			break;
		}
		nd = (node*)malloc(sizeof(node));
		nd->value = num;
		nd->next = NULL;

		if (head == NULL) {
			head = nd;
		}
		else {
			last->next = nd;
		}
		last = nd;
		count++;
	}
	printf_s("\n==입력 순서 출력==\n");
	prtnd(head);
	printf_s("\n\n==자료의 개수==\n %2d", count);
	printf_s("\n\n==중간 위치에 있는 자료의 값==\n");
	prtndM(head, count / 2);
	printf_s("\n\n==입력 역순 출력==\n");
	prtndR(head, count-1);
	printf_s("\n\n==홀수번째 삭제(0번째 부터 시작)==\n");
	delodd(head, count);
	prtnd(head);
	printf_s("\n\n");
}

void prtnd(struct node* head) {
	struct node *cur = head;
	while (cur) {
		printf(" %2d", cur->value);
		cur = cur->next;
	}
}
void prtndM(struct node* head, int mid) {
	struct node *cur = head;
	int cnt = 0;
	while (cur) {
		if (cnt == mid) {
			printf(" %2d", cur->value);
		}		
		cur = cur->next;
		cnt++;
	}
}
void prtndR(struct node* head, int last) {
	struct node *cur = head;
	int cnt = 0;
	while (last >= 0) {
		while (cur) {
			if (cnt == last) {
				printf(" %2d", cur->value);
			}
			cur = cur->next;
			cnt++;
		}
		cur = head;
		cnt = 0;
		last--;
	}	
}
void delodd(struct node* head, int size) {
	struct node *cur = head;
	int cnt = 0;
	while (cur->next != NULL) {
		if (cnt % 2 == 0) {
			cur->next = cur->next->next;
			size--;
			cnt--;
		}
		cnt++;
		cur = cur->next;
	}
}