/* For an array of integers from 0 to n - 1 wth each number appearing
   once find the missing number. Tested using num.txt */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int missing_num(int *, int);

int main (int argc, char ** argv) {
   FILE * fname = fopen(argv[1], "r");
   
   if (fname == NULL) {
      printf("Error: Invalid file name.\n");
   }
   
   char str[50];
   int arr[50];
   int i = 0;
   
   while (fgets(str, 50, fname)) {
      str[strlen(str) - 1] = '\0';
      arr[i++] = atoi(str);
   }
   
   int missing = missing_num(arr, i);
   
   printf("Missing number: %d\n", missing);
}

int missing_num(int * arr, int length) {
   int i, sum2, missing;
   int sum1 = 0;
   
   for (i = 0; i < length; i++) {
      sum1 += arr[i];
   }
   
   sum2 = length * (length + 1) / 2;
   
   missing = sum2 - sum1;
   
   return missing;
}
