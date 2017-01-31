//
//  stock.c
//  
//
//  Created by Cheyenne Martinez on 1/30/17.
//
//

#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

int max_profit(int *, int);
int max_profit_slow(int *, int);

int main(int argc, char ** argv) {
   int stock_prices_yesterday[100000];
   
   int i;
   for (i = 0; i < 100000; i++) {
      stock_prices_yesterday[i] = i;
   }
   
   int max = max_profit(stock_prices_yesterday, 100000);
   
   printf("Max profit: %d\n", max);
   
   return EXIT_SUCCESS;
}

int max_profit_slow(int * stock, int num) {
   int i, j, profit;
   int max = 0;
   
   for(i = 0; i < num; i++) {
      for (j = i + 1; j < num; j++) {
         profit = stock[j] - stock[i];
         
         if (profit > max) {
            max = profit;
         }
      }
   }
   
   return max;
}

int max_profit(int * stock, int num) {
   int i;
   
   if (num < 2) {
      return 0;
   }
   
   int min_price = stock[0];
   int max = stock[1] - stock[0];
   
   for (i = 1; i < num; i++) {
      int curr = stock[i];
      int profit = curr - min_price;
      max = MAX(max, profit);
      min_price = MIN(min_price, curr);
   }
   
   return max;
   
}
