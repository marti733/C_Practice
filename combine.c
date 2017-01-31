/* Join two sorted arrays input via text file into a single 
   sorted array. Tested using array1.txt and array2.txt */

#include "combine.h"

#include <stdio.h>
#include <stdlib.h>

void print_array(char *, int);
void join_array(char *, char *, int, int, char*);

int main (int argc, char ** argv) {
   
   FILE * fname1 = fopen(argv[1], "r");
   if (fname1 == NULL) {
      fprintf(stdout, "Error: Invalid file 1.\n");
      return EXIT_FAILURE;
   }
   
   FILE * fname2 = fopen(argv[2], "r");
   if (fname2 == NULL) {
      fprintf(stdout, "Error: Invalid file 2.\n");
      return EXIT_FAILURE;
   }
   
   char a;
   int size1 = 0, size2 = 0;
   char array1[100];
   char array2[100];
   char array[200];
   
   while((a = fgetc(fname1)) != EOF) {
      array1[size1++] = a;
   }
   
   rewind(fname2);
   while((a = fgetc(fname2)) != EOF) {
      array2[size2++] = a;
   }
   
   printf("ARRAY 1: \n");
   print_array(array1, --size1);
   printf("\nARRAY 2: \n");
   print_array(array2, --size2);
   
   printf("\nFINAL ARRAY: \n");
   join_array(array1, array2, size1, size2, array);
   
   fclose(fname1);
   fclose(fname2);
   
   return EXIT_SUCCESS;
}

void print_array(char * array, int size) {
   int i;
   
   for (i = 0; i < size; i++) {
      printf("%c", array[i]);
   }
   
   printf("\n");
}

void join_array(char * array1, char * array2, int size1, int size2, char * array) {
   int i = 0, j = 0, k = 0;
   
   while (i < size1 + size2) {
      if (k >= size2) {
         array[i++] = array1[j++];
      }
      else if (j >= size1) {
         array[i++] = array2[k++];
      }
      else if ((array1[j] < array2[k])) {
         array[i++] = array1[j++];
      }
      else {
         array[i++] = array2[k++];
      }
   }
   
   print_array(array, size1 + size2);
}
