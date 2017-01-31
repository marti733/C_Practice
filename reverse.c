/* This function as is performs the reversal of a linked list 
   tested with the file test.txt */

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
   char data;
   struct _node * next;
} node;

node * add_node(char, node *);
node * new_node(char);
node * reverse_list(node *);
node * reverse_half(node *);
void delete_list(node *);
node * make_list(FILE *);

/* int main (int argc, char ** argv) {
   // Open filename given
   FILE * fname = fopen(argv[1], "r");
   if (fname == NULL) {
      fprintf(stdout, "Error: Incorrect file format input");
      return EXIT_FAILURE;
   }
   
   // Create linked list from file
   node * head = make_list(fname);

   // Print origional list
   node * temp = head;
   while (temp != NULL) {
      printf("%c", temp->data);
      temp = temp->next;
   }
   
   printf("\n");
 
   // Print the reversed list
   head = reverse_list(head);
   temp = head;
   while (temp != NULL) {
      printf("%c", temp->data);
      temp = temp->next;
   }
   
   printf("\n");
 
 
   // Print the reversed list with the last half reversed again
   head = reverse_half(head);
   temp = head;
   while (temp != NULL) {
      printf("%c", temp->data);
      temp = temp->next;
   }
   
   printf("\n");
   
   delete_list(head);

   return EXIT_SUCCESS;
}
*/

/* Take the current list and add a new node to the beginning of the current
   list. The first input is a single character and the second is the current
   head of the list. The new head of the list is returned to the calling
   function */
node * add_node ( char data, node * head) {
   node * new = new_node(data);
   
   if (head == NULL) {
      head = new;
   } else {
      new->next = head;
      head = new;
   }
   
   return head;
}

/* Dynamically makes space for a new node, creates the node with the provided
   input of the character for the new node. The pointer to the new node is 
   returned to the calling function */
node * new_node (char data) {
   node * new = (node *)malloc(sizeof(node));
   new->data = data;
   new->next = NULL;
   
   return new;
}

/* Reverse the linked list given the head node by iteration by keeping track
   of the previous, current, and next node of the linked list. Initializing 
   the previous and next nodes to NULL ensures that list shorter than 3 nodes
   can be properly reversed as well. */

node * reverse_list (node * head) {
   node * curr = head;
   node * prev = NULL;
   node * next = NULL;
   
   while (curr != NULL) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
   }
   
   return prev;
}


/* Search through half a linked list and then reverse the second half of the
   list. Returns the head of the rearranged list to the calling function. */
node * reverse_half ( node * head) {
   
   node * probe = head;
   node * curr = head;
   node * next = NULL;
   node * prev = NULL;
   node * temp = NULL;
   
   while (probe != NULL) {
      probe = probe->next;
      if (probe != NULL) {
         probe = probe->next;
         next = curr->next;
         prev = curr;
         curr = next;
      }
   }
   
   temp = prev;
   
   temp->next = reverse_list(curr);
   
   return head;
}

/* Deleates the allocated space created while making a linked list */

void delete_list (node * head) {
   node * temp = head;
   while (head != NULL) {
      temp = head;
      head = head->next;
      free(temp);
   }
}


node * make_list (FILE * fname) {
   char c;
   node * head = NULL;
   
   while ((c = fgetc(fname)) != EOF) {
      head = add_node(c, head);
   }
   
   return head;
}




