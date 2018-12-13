#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main() {
	char str[100] = "";
	int a[4][4] = { {0} };
	char *pf;
	int i = 0;
	int j = 0;
	char *ret;
	int total = 0;

	FILE *pFile;
	pFile = fopen("score.csv", "r");

	while (fgets(str, 100, pFile)) {


		printf("%s\n", str);

		pf = strtok(str, ",");
		
		while (pf != NULL)
		{
			a[i][j] = atoi(pf);
			j++;
			pf = strtok(NULL, ",");
			
		}
		i++;
		j = 0;
	}
	
}