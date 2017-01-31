#include <stdio.h>
#include <stdlib.h>

typedef struct _lnode {
	int data;
	struct _lond * next;
} lnode;

int main (int argc, char ** argv) {
	lnode * head, *temp;
	int i;
	for(i = 0; i < 10; i++) {
		temp = new_node(rand());

}
