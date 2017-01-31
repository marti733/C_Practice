/* Create a linked list from stdin input */
#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int val;
	struct _node * next;
}node;

node * make_node(int);
node * add_node(node *, node *);
void print_list(node *);

int main (int argc, char ** argv) {

	int size, i, val;
   node * curr = (node *)malloc(sizeof(node));
   node * head = (node *)malloc(sizeof(node));

	printf("Enter the number of data points: ");
	scanf("%d", &size);

	printf("Enter the data points: ");
	for (i = 0; i < size; i++) {
		scanf("%d", &val);
      curr = make_node(val);
      head = add_node(curr, head);
	}
   
   if (head == NULL) {
      printf("Error: No list created \n");
      
   }
   
   print_list(head);

	return EXIT_SUCCESS;
}

node * make_node(int val) {
	node * ptr = NULL;
   
   ptr = (node *)malloc(sizeof(node));
   
   ptr->val = val;
   ptr->next = NULL;

	return ptr;
}

node * add_node(node * curr, node * head) {
   node * next = (node *)malloc(sizeof(node));
   next = head->next;
   curr->next = head;
   
   if (head == NULL) {
      curr->next = head;
      head = curr;
      return head;
   }
   
   while (curr->val > next->val) {
      curr->next = next;
      next = next->next;
   }
   
   return head;
}

void print_list (node * head) {
   
}
