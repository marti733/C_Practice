/* Make two linked list representing numbers i.e. 123 is formed as 
   1->2->3 in a linked list. Then add those numbers together and 
   make a resulting linked list representing the final number. Note
   that for a more complete solution you could reverse the origional
   linked lists and use a carry method to form a new list and then 
   reverse the resulting list for a better and more extensive 
   solution 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
   int data;
   struct _node * next;
} node;

long long get_number(node *);
node * make_list(long long);
node * add_node(node *, int);
void print_list(node *);

int main (int argc, char ** argv) {
   
   node * alist = make_list(123);
   node * blist = make_list(4567);
   
   // Make int out of numbers
   long long a = get_number(alist);
   long long b = get_number(blist);
   
   printf("First number: %lld\nSecond number: %lld\n", a, b);

   long long sum = a + b;
   
   node * final = make_list(sum);
   
   print_list(final);
   
   return EXIT_SUCCESS;
}

long long get_number(node * head) {
   long long total = 0;
   char arr[19];
   int i = 0;
   
   while (head != NULL) {
      arr[i++] = head->data + '0';
      head = head->next;
   }
   
   total = atoll(arr);
   
   return total;
}

node * make_list(long long data) {
   int result;
   node * head = NULL;
   
   while (data != 0) {
      result = data % 10;
      data /= 10;
      head = add_node(head, result);
   }
   
   return head;
}

node * add_node(node * head, int data) {
   node * new = (node *)malloc(sizeof(node));
   new->data = data;
   new->next = head;
   
   return new;
}

void print_list(node * head) {
   printf("Final solution: ");
   while(head != NULL) {
      printf("%d", head->data);
      head = head->next;
   }
   
   printf("\n");
}
