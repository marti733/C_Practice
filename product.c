//
//  product.c
//  
//
//  Created by Cheyenne Martinez on 1/30/17.
//
//

#include <stdio.h>
#include <stdlib.h>

void get_product(int *, int, int *);

int main(int argc, char ** argv) {
   int size = 6;
   int array[size];
   int i;
   for (i = 0; i < size; i++) {
      array[i] = i + 1;
   }
   
   int * output = (int *)malloc(sizeof(int) * size);
   get_product(array, size, output);
   
   for (i = 0; i < size; i++) {
      printf("%d ", output[i]);
   }
   printf("\n");
   
   free(output);
   
   return 0;
}

void get_product(int * array, int size, int * output) {
   int i;
   long long product = 1;
   
   for(i = 0; i < size; i++) {
      output[i] = product;
      product *= array[i];
   }
   
   product = 1;
   for(i = size ; i > 0; i--) {
      output[i - 1] *= product;
      product *= array[i - 1];
   }

}
