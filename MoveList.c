//
//  MoveList.c
//  
//
//  Created by Cheyenne Martinez on 1/27/17.
//
//

#include "MoveList.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
   char * data;
   struct _node * next;
} node;

node * add_node(char *, node *);
node * new_node(char *);

int main(int argc, char ** argv) {
   FILE * fname = fopen(argv[1], "r");
   if (fname == NULL) {
      printf("ERROR: Invalid file name\n");
      return EXIT_FAILURE;
   }
   
   char name[50];
   node * head = NULL;
   
   while (fgets(name, 50, fname) != NULL) {
      head = add_node(name, head);
      //puts(head->data);
   }
   
   while (head != NULL) {
      puts(head->data);
      head = head->next;
   }
   
   fclose(fname);
   
   return EXIT_SUCCESS;
}

node * new_node (char * data) {
   node * new = (node *)malloc(sizeof(node));
   new->data = data;
   new->next = NULL;
   
   return new;
}

node * add_node (char * data, node * head) {
   
   puts(data);
   
   if (head == NULL) {
      head = new_node(data);
      return head;
   }
   
   node * new = new_node(data);
   new->next = head;
   
   return new;
}
