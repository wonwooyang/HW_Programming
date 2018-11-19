#include <stdio.h>
#include <stdlib.h>

int main() {
	printf_s("\n20180369 양원우\n");
	int Csize = 100000, Heapsize = 0, count = 10;
	int *call = NULL;
	printf_s("\n 최초 Csize : %6d\tcall 의 size = %6d byte\n", Csize, Csize * sizeof(int));

	while(Csize >= 1) {
		call = (int*)malloc(Csize*(sizeof(int)));
		if (call == NULL) {
			//call 이 NULL > 할당 실패 > 메모리 부족! > Callsize 를 절반으로 줄인다
			printf_s("\n %d 번\tcall 의 Size = %6d byte\tHeap size : %d byte", count, Csize * sizeof(int), Heapsize);
			Csize = Csize / 2;
		}
		else {
			Heapsize += _msize(call);
		}
		count++;
	}	
	printf_s("\n\nTotal Heap Size = %d byte\n\n", Heapsize);
	return 0;
}