#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int oper(int *a, int *b, char *op) {
	int res;
	switch(*op) {
		case '+':
			res = *a + *b;
			break;
		case '-':
			res = *a - *b;
			break;
		case '*':
			res = *a * *b;
			break;
		case '/':
			if (*b == 0) {
				printf("Error\n");
				return INT_MIN;
			}
			res = *a / *b;
			break;
		case '%':
			if (*b == 0) {
				printf("Error\n");
				return INT_MIN;
			}
			res = *a % *b;
			break;

		default:
			printf("Invalid sign\n");
			break;
			return INT_MIN;
	}
	return res;
}

int main() {
	int *a = malloc(sizeof(int));
	int *b = malloc(sizeof(int));
	char *op = malloc(sizeof(char));
	
	if (a == NULL || b == NULL) {
		printf("Error\n");

		return 1;
	}
	
	printf("Enter first num: \n");	
	scanf("%d", a);
	
	printf("Enter operator: \n");	
	scanf(" %c", op);

	printf("Enter second num: \n");	
	scanf("%d", b);
	
	int result = oper(a, b, op);
	
	if (result != INT_MIN) {
		printf("Result: %d\n", result);
	}

	free(a);
	free(b);
	free(op);

	return 0;
}
