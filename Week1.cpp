#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int num;
	int* unsort = (int*)malloc(sizeof(int));
	int* sort = (int*)malloc(sizeof(int));
	printf("Enter a number : ");
	scanf("%d", &num);
	int cnt = 1;
	*sort = *unsort = num;
	while (1) {
		printf("unsorted : ");
		for (int i = 0; i < cnt; i++) {
			printf("%d ", unsort[i]);
		}
		printf("\n");
		printf("sorted :");
		for (int i = 0; i < cnt; i++) {
			printf("%d ", sort[i]);
		}
		printf("\n");
		printf("Enter a number : ");
		scanf("%d", &num);
		cnt++;
		realloc(unsort, sizeof(int) * cnt);
		realloc(sort, sizeof(int) * cnt);
		unsort[cnt - 1] = num;
		for (int i = cnt - 2; i >= 0; i--) {
			if (sort[i] > num) {
				sort[i+1] = sort[i];
			}
			else {
				sort[i+1] = num;
				break;
			}
		}
		if (sort[0] > num) sort[0] = num;
	}
	return 0;
}