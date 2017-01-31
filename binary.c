/* This program assumes the file given contains numbers 
   seperated by spaces which will then be sorted into a 
   tree with two child nodes, left and right. Tested 
   with btest.txt, btest2.txt, and btest3.txt. Main has
   been commented out for inclusing in other programs */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node * left;
	struct _node * right;
} node;

node * add_node(node *, int *);
node * new_node(int *);
void print_tree(node *);
node * make_tree(FILE *);
/*
int main(int argc, char ** argv) {
   //Open file, allocate space for number, and initialize head
	FILE * fname = fopen(argv[1], "r");
   int * number = (int *)malloc(sizeof(int));
	node * head = NULL;
   
   //Check for successfully opened file
	if (fname == NULL) {
		printf("ERROR: Connot open file.\n");
		return EXIT_FAILURE;
	}
	
   //Reset file to beginning and get first number
   rewind(fname);
   fscanf(fname,"%i", number);

   //Read in numbers and add them to the tree
	while (!feof(fname)) {
      //printf("%d ", *number);
		head = add_node(head, number);
      fscanf(fname, "%i", number);
	}
   
   print_tree(head);
   printf("\n");
   
   free(number);
	return EXIT_SUCCESS;	
}
*/
node * new_node(int * data) {
	node * new = NULL;
	new = (node *)malloc(sizeof(node));

	new->data = *data;
	new->left = NULL;
	new->right = NULL;

	return new;
}

node * add_node(node * head, int * data) {
   
   node * new = new_node(data);
   node * curr = head;
   
   if (head == NULL) {
		head = new;
      return head;
   }
   
   
   while (curr != NULL) {
      if (*data == curr->data) {
         return head;
      }
      while (*data > curr->data) {
         if (curr->right == NULL) {
            curr->right = new;
            return head;
         }
         curr = curr->right;
      }
      while (*data < curr->data) {
         if (curr->left == NULL) {
            curr->left = new;
            return head;
         }
         curr = curr->left;
      }
      if (curr->right == NULL) {
         curr->right = new;
         return head;
      }
      curr = curr->right;

   }

	return head;
}

void print_tree(node * head) {
   if (head == NULL) {
      printf("NULL ");
      return;
   }
   
   printf("%d ", head->data);
   
   print_tree(head->left);
   print_tree(head->right);
   
}

node * make_tree(FILE * fname) {
   int * number = (int *)malloc(sizeof(int));
   node * head = NULL;
   
   //Read in numbers and add them to the tree
   while (!feof(fname)) {
      //printf("%d ", *number);
      head = add_node(head, number);
      fscanf(fname, "%i", number);
   }
   
   free(number);
   
   return head;
}
