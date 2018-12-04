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
	printf_s("\n20180369 �����\n");
	typedef struct node node;
	node *head = NULL, *nd = NULL, *last = NULL;
	int key = 0, count = 0, num = 0, eoeo=0;
	printf("\n== ������ �Է��ϼ��� ==\n== Ctrl+Z, Enter �� 3�� �ݺ��ϸ� ����˴ϴ� ==\n");
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
	printf_s("\n==�Է� ���� ���==\n");
	prtnd(head);
	printf_s("\n\n==�ڷ��� ����==\n %2d", count);
	printf_s("\n\n==�߰� ��ġ�� �ִ� �ڷ��� ��==\n");
	prtndM(head, count / 2);
	printf_s("\n\n==�Է� ���� ���==\n");
	prtndR(head, count-1);
	printf_s("\n\n==Ȧ����° ����(0��° ���� ����)==\n");
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