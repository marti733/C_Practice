/* Find the nth number in the fibinocci sequence */

#include <stdio.h>
#include <stdlib.h>

long long find_fib(int);
long long n_fib(int);

int main (int argc, char ** argv){
   int n = atoi(argv[1]);
   
   //long long sum = find_fib(n);
   long long sum = n_fib(n);
   
   printf("Fibinocci %d is %lld\n", n, sum);
   
   return EXIT_SUCCESS;
}

long long find_fib(int n) {
   if (n <= 0){
      return 0;
   }
   if (n == 1) {
      return 1;
   }
   
   return (find_fib(n - 1) + find_fib(n - 2));
}

long long n_fib(int n) {
   int result[2] = {0, 1};
   if (n < 2) {
      return result[n];
   }
   
   long long fib1 = 1;
   long long fib2 = 0;
   long long fibn = 0;
   int i;
   
   for (i = 2; i <= n; ++i) {
      fibn = fib1 + fib2;
      fib2 = fib1;
      fib1 = fibn;
   }
   
   return fibn;
}
