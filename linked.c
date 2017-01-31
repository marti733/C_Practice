/* This code takes a file as an input and outputs the contents 
   of the file in ASCII order from least to greatest. The file
   should be called as "./linked filename.txt" where filename 
   is the name of the file that should be put in order */

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	char data;
	struct _node * next;
}node;

node * add_node (node *, char);
node * new_node( char);
int delete_list(node *);

int main (int argc, char ** argv) {
	FILE * fname = fopen(argv[1], "r");
	
	char c = fgetc(fname);
	node * start = NULL;
	
	while (c != EOF) {
		start = add_node(start, c);
		c = fgetc(fname);
//		printf(" %c", c);
	}
	
	node * print = start;
	while(print != NULL) {
		printf(" %c", print->data);
		print = print->next;
	}

	printf("\n");

	int done = delete_list(start);
	
	if (done == 1) {
		printf("List deleted\n");
	}
	
	fclose(fname);

	return 0;

}

node * add_node(node * start, char data) { 
	node * new = new_node(data);

	if (start == NULL) {
		start = new;
		return start;
	} else {
		node * next = start->next;
		node * curr = start;
		if (new->data <= curr->data) {
			new->next = start;
			start = new;
			return start;
		}	
		while (new->data > next->data) {
			curr = next;
			next = curr->next;

			if (next == NULL) {
				curr->next = new;
				return start;
			}
		}
		new->next = next;
		curr->next = new; 
	}

	return start;
}

node * new_node(char data) {
	node * new = (node *)malloc(sizeof(node));
	
	new->data = data;
	new->next = NULL;

	return new;
}

int delete_list(node * start) {
	node * temp;

	while (start != NULL) {
		temp = start->next;
		free(start);
		start = temp;
	}

	return 1;
}
