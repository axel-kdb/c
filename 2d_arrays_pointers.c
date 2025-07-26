#include <stdio.h>
#include <stdlib.h>

int main() {
	int rows = 2;
	int cols = 3;
	int **arrayMap = malloc(rows * sizeof(int*));

	for (int i = 0; i < rows; i++) {
		arrayMap[i] = malloc(cols * sizeof(int));
	}
	
	int count = 1;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arrayMap[i][j] = count++;
		}
	}
	
	for (int i = 0; i < rows; i++) {
		printf("(");
		for (int j = 0; j < cols; j++) {
			printf("%d", arrayMap[i][j]);
			if (j < cols - 1) {
				printf(", ");
			}
		};
		printf(")\n");		
	};

	for (int i = 0; i < rows; i++) {
		free(arrayMap[i]);
	}

	free(arrayMap);
	
	return 0;	
}

