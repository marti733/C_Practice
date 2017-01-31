//
//  merge_array.c
//  
//
//  Created by Cheyenne Martinez on 1/30/17.
//
//

#include <stdio.h>
#include <stdlib.h>

void sort_arrays(int *, int *, int, int);
void print_array(int *, int);

int main (int argc, char ** argv) {
   
   // Get array sizes
   int size1, size2;
   
   printf("Enter first array size: ");
   scanf("%d", &size1);
   
   printf("Enter second array size: ");
   scanf("%d", &size2);
   
   // Fill arrays
   int arr1[size1];
   int arr2[size2];
   int i;
   
   printf("Enter sorted first array: ");
   for(i = 0; i < size1; i++) {
      scanf("%d", &arr1[i]);
   }
   
   printf("Enter sorted second array: ");
   for(i = 0; i < size2; i++) {
      scanf("%d", &arr2[i]);
   }
   
   // Rearrage arrays
   sort_arrays(arr1, arr2, size1, size2);
   
   return EXIT_SUCCESS;
}

void sort_arrays(int * arr1, int * arr2, int size1, int size2) {
   int i, j;
   
   for( i = (size2 - 1); i >= 0; i--) {
      int last = arr1[size1 - 1];
      for (j = size1 - 2; j >= 0 && (arr1[j] > arr2[i]); j--) {
         arr1[j+1] = arr1[j];
      }
      if(j != size1-2 || last > arr2[i]) {
         arr1[j+1] = arr2[i];
         arr2[i] = last;
      }
   }
   
   printf("Sorted array: ");
   print_array(arr1, size1);
   print_array(arr2, size2);
   printf ("\n");
}

void print_array( int * arr, int size) {
   int i;
   for (i = 0; i < size; i++) {
      printf("%d ", arr[i]);
   }
}
