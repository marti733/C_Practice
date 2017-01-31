//
//  temperature.c
//  
//
//  Created by Cheyenne Martinez on 1/30/17.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

typedef struct {
   int min;
   int max;
   
   int occurrences[111];
   int max_occurrence;
   int mode;
   
   double n_total;
   double total_sum;
   double mean;
} tracker;

void insert(tracker * current, int new);
int getmax(tracker * current);
int getmin(tracker * current);
double getmean(tracker * current);
int getmode(tracker * current);

int main (int argc, char ** argv) {
   tracker * new = (tracker *)malloc(sizeof(tracker));
   assert(new != NULL);
   
   new->min = 110;
   new->max = 0;
   memset(new->occurrences, 0, sizeof(new->occurrences));
   new->max_occurrence = 0;
   new->mode = 0;
   new->n_total = 0;
   new->total_sum = 0;
   new->mean = 0;
   
   insert(new, 70);
   insert(new, 80);
   insert(new, 65);
   insert(new, 70);
   insert(new, 75);

   printf("\nMinimum temperature: %d\n", new->min);
   printf("Maximum temperature: %d\n", new->max);
   printf("Mode:                %d\n", new->mode);
   printf("Mean:                %.2f\n\n", new->mean);
   
   return 0;
}

int getmax(tracker * current) {
   return current->max;
}

int getmin(tracker * current) {
   return current->min;
}

void insert(tracker * current, int new) {
   // Check within temp bounds
   assert(new >= 0 && new < 111);
   
   // Update min and max
   current->min = MIN(current->min, new);
   current->max = MAX(current->max, new);
   
   // Update mode
   current->occurrences[new]++;
   if (current->occurrences[new] > current->max_occurrence) {
      current->max_occurrence = current->occurrences[new];
      current->mode = new;
   }
   
   // Update mean
   current->n_total++;
   current->total_sum += new;
   current->mean = current->total_sum / current->n_total;

}

double getmean(tracker * current) {
   return current->mean;
}

int getmode(tracker * current) {
   return current->mode;
}
