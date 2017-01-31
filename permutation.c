/* This function prints every permutation of a given string. This
   has been tested using the perm.txt file. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void permutation(char *, char *);

int main (int argc, char ** argv) {
   FILE * fname = fopen(argv[1], "r");

   if (fname == NULL) {
      printf("Error: Invalid file name.\n");
      return EXIT_FAILURE;
   }
   
   char str[50];

   while (fgets(str, 50, fname)) {
      str[strlen(str) - 1] = '\0';
      permutation(str, str);
   }
   
   
   return EXIT_SUCCESS;
   
}

void permutation (char * str, char * begin) {
   
   char * strch = NULL;
   char temp;
   
   if (*begin == '\0') {
      puts(str);
      return;
   }
   
   for (strch = begin; *strch != '\0'; strch++) {
      
      temp = * strch;
      * strch = * begin;
      * begin = temp;
      
      permutation(str, begin + 1);
      
      temp = * strch;
      * strch = * begin;
      * begin = temp;
   }
   
}
