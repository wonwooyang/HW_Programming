#include <stdio.h>
#include <stdlib.h>

int main() {
	printf_s("\n20180369 �����\n");
	int Csize = 100000, Heapsize = 0, count = 10;
	int *call = NULL;
	printf_s("\n ���� Csize : %6d\tcall �� size = %6d byte\n", Csize, Csize * sizeof(int));

	while(Csize >= 1) {
		call = (int*)malloc(Csize*(sizeof(int)));
		if (call == NULL) {
			//call �� NULL > �Ҵ� ���� > �޸� ����! > Callsize �� �������� ���δ�
			printf_s("\n %d ��\tcall �� Size = %6d byte\tHeap size : %d byte", count, Csize * sizeof(int), Heapsize);
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