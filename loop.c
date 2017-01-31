/* Finds a loop, if there is one, in a linked list. Tested using
   test.txt */

#include <stdio.h>
#include "reverse.c" // Includes functions for make_list

node * loop_list(node *);
void find_loop(node *);

int main(int argc, char ** argv) {
   
   FILE * fname = fopen(argv[1], "r");
   
   node * head = make_list(fname);
   find_loop(head);

   head = loop_list(head);
   find_loop(head);
   
   fclose(fname);
   
   return EXIT_SUCCESS;
   
}

/* Takes a singly linked list and loops the list into a circle */
node * loop_list (node * head) {
   if (head == NULL) {
      return NULL;
   }
   
   node * curr = head;
   node * next = NULL;
   node * prev = NULL;
   
   while (curr != NULL) {
      next = curr->next;
      prev = curr;
      curr = next;
   }
   
   prev->next = head;
   
   return head;
}

/* Finds a loop (if there is one) in a linked list*/
void find_loop (node * head) {
   node * curr = head;
   node * probe = head->next;
   
   while ((curr != probe) && (probe != NULL)) {
      curr = curr->next;
      probe = probe->next;
      if (probe != NULL) {
         probe = probe->next;
      }
   }
   
   if (probe == NULL) {
      printf("No linked list detected\n");
   } else {
      printf("Linked list detected\n");
   }
}

