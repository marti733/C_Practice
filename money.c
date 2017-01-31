//
//  money.c
//  
//
//  Created by Cheyenne Martinez on 1/30/17.
//
//

#include <stdio.h>
#include <string.h>

int find_solutions(int, int *, int);

int main (int argc, char ** argv) {
   int amount = 8;
   int denominations[3] = {2, 6, 3};
   
   int ways = find_solutions(amount, denominations, 3);
   
   printf("Ways of creating amount: %d\n", ways);
   
   return 0;
}

int find_solutions(int amount, int * denominations, int n_denominations) {
   int permutations[amount + 1];
   int i;
   
   memset(permutations, 0, sizeof(permutations));
   permutations[0] = 1;
   
   for (i = 0; i < n_denominations; i++) {
      int high;
      int coin = denominations[i];
      
      for (high = coin; high < amount + 1; high++) {
         int remain = high - coin;
         permutations[high] += permutations[remain];
      }
   }
   
   return permutations[amount];
   
}
