//
//  greatest_product.c
//  
//
//  Created by Cheyenne Martinez on 1/30/17.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

long long highest_product(int *, int);

int main( int argc, char ** argv) {
   
   int size = 5;
   int * array = (int *)malloc(sizeof(int) * size);
   int i;
   
   for(i = 0; i < size; i++) {
      array[i] = i + 1;
      printf("%d ", array[i]);
   }
   printf("\n");
   
   long long high = highest_product(array, size);
   
   printf("Highest product of 3: %lld\n", high);
   
   free(array);
   
   return 0;
}

long long highest_product(int * array, int size) {
   long long highest_of_2, highest_of_3, lowest_of_2, highest, lowest;
   int i;
   
   assert(size >= 3);
   
   // Initializations
   highest = MAX(array[0], array[1]);
   lowest = MIN(array[0], array[1]);
   
   highest_of_2 = array[0] * array[1];
   lowest_of_2 = array[0] * array[1];
   
   highest_of_3 = array[0] * array[1] * array[2];
   
   for (i = 2; i < size; i++) {
      long long temp;
      long long curr = array[i];
      
      // Check for new high of 3
      temp = MAX(highest_of_3, curr * highest_of_2);
      highest_of_3 = MAX(temp, curr * lowest_of_2);
      
      // Check for high of 2
      temp = MAX(highest_of_2, curr * highest);
      highest_of_2 = MAX(temp, curr * lowest);
      
      // Check for new low of 2
      temp = MIN(lowest_of_2, curr * highest);
      lowest_of_2 = MIN(temp, curr * lowest);
      
      // New highest
      highest = MAX(highest, curr);
      
      // New lowest
      lowest = MIN(lowest, curr);
   }
   
   return highest_of_3;
}
