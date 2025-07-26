#include <stdio.h>
#include <stdlib.h>

int main() {
	int arrayMap[2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};
	
	for (int i = 0; i < 2; i++) {
		printf("(");
		for (int j = 0; j < 3; j++) {
			printf("%d", arrayMap[i][j]);
			if (j < 2) {
				printf(", ");
			}
		};
		printf(")\n");		
	};
	
	return 0;	
}

