#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};
void prtnd(struct node* head);

void main() {
	typedef struct node node;
	node *head = NULL, *nd = NULL, *last = NULL;
	int key = 0, count = 0;
	char inp[10];

	while (1) {
		printf("\n정수 입력 (현재 %d 개)\n", count);
		/*
		VS말고 DEV c++ 에서 하면 돌아간다 함
		count=scanf("%d", &key);
		//printf("key : %d \n", scanf("%d", &key));
		if (count == EOF) {
			printf_s("EOF");
			exit(0);
		}
		*/


		if (gets_s(inp, 10) == EOF) {
			printf("!");  break;
		}

		nd = (node*)malloc(sizeof(node));
		nd->value = atoi(inp);
		nd->next = NULL;

		if (head == NULL) {
			head = &nd;
		}
		else {
			last->next = nd;
		}
		last = nd;
		count++;
	}

	prtnd(head);
}
void prtnd(struct node* head) {
	struct node *cur = head;
	printf("\n");
	while (cur->next) {
		cur = cur->next;
		printf("%d  ", cur->value);
	}

}
/*LAB 8 동적 메모리1 (자기참조 구조체)
void main() {

	typedef struct node node;

	node *head = NULL, *first = NULL, *second = NULL;
	first = (node*)malloc(sizeof(node));
	second = (node*)malloc(sizeof(node));

	first->value = 11;
	second->value = 90;

	head = &first;
	first->next = &second;
	second->next = NULL;

	printf_s("\nHead 값 : %d", head);
	printf_s("\nFirst node : \tAddr : %d\tvalue : %d \tnext : %d", &first, first->value, first->next);
	printf_s("\nSecond node : \tAddr : %d\tvalue : %d \tnext : %d", &second, second->value, second->next);

	free(first);
	free(second);
}
*/