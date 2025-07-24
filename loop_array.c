#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = malloc(5 * sizeof(int));

    for (int i = 0, j = 10; i < 5 && j <= 50; i ++, j += 10) {
    	arr[i] = j;
	printf("Arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);

    return 0;
}

