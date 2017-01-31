/* Find the maximum depth of a binary tree. Tested with depth.txt */

#include <stdio.h>
#include "binary.c"

int find_depth (node *);

int main (int argc, char ** argv) {
   FILE * fname = fopen(argv[1], "r");
   
   node * head = make_tree(fname);
   
   int depth = find_depth(head);
   printf("Depth: %d\n", depth - 1);
   
   return EXIT_SUCCESS;
}

int find_depth(node * head) {
   if (head == NULL) {
      return 0;
   }
   
   int depthL = find_depth(head->left);
   int depthR = find_depth(head->right);
   
   return (depthL > depthR) ? (depthL + 1) : (depthR + 1);
}
