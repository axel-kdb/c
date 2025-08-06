#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int number;
	struct node *next;
} node;

int main() {
	node *list = NULL;

	for (int i = 0; i < 3; i++) {
		node *n = malloc(sizeof(node));
        n->number = i;
        n->next = list;
        list = n;
    }
    node *ptr = list;
    while (ptr != NULL) {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }

}
