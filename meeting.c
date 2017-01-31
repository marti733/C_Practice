//
//  meeting.c
//
//
//  Created by Cheyenne Martinez on 1/30/17.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct _meeting {
   int start;
   int end;
} meeting;

meeting * get_schedule(meeting *, int, meeting *, int, int *);
int meetingsort(const void *, const void *);

//meeting * sort_meetings(meeting *, int);

int main(int argc, char ** argv) {
   int n_events = 6;
   int i;
   
   meeting * group = (meeting *)malloc(sizeof(meeting) * n_events);
   meeting * output = (meeting*)malloc(sizeof(meeting) * n_events);
   
   (group[0]).start = 1;
   (group[1]).start = 3;
   (group[2]).start = 4;
   (group[3]).start = 6;
   (group[4]).start = 1;
   (group[5]).start = 2;
   
   (group[0]).end = 2;
   (group[1]).end = 4;
   (group[2]).end = 5;
   (group[3]).end = 10;
   (group[4]).end = 5;
   (group[5]).end = 7;
   
   printf("Number of events: %d\n", n_events);
   for (i = 0; i < n_events; i++) {
      printf("Event %d: %d to %d\n", i, group[i].start, group[i].end);
   }
   
   output = get_schedule(group, n_events, output, n_events, &n_events);
   
   printf("Number of events: %d\n", n_events);
   for (i = 0; i < n_events; i++) {
      printf("Event %d: %d to %d\n", i, output[i].start, output[i].end);
   }
   
   free(group);
   
   return 0;
}

meeting * get_schedule(meeting * input, int n_events, meeting * output, int out_size, int * final_size) {
   meeting * sorted = (meeting *)malloc(sizeof(meeting) * n_events);
   
   assert(sorted != NULL);
   
   memcpy(sorted, input, sizeof(meeting) * n_events);
   
   qsort(sorted, n_events, sizeof(meeting), meetingsort);
   
   output[0] = sorted[0];
   int curr_length = 1, i;
   
   for (i = 0; i < n_events; i++) {
      meeting * curr = &sorted[i];
      meeting * last = &output[curr_length - 1];
      
      if (curr->start <= last->end) {
         last->end = MAX(last->end, curr->end);
      }
      else {
         curr_length++;
         output[curr_length - 1] = *curr;
      }
   }
   
   *final_size = curr_length;
   
   free(sorted);
   
   return output;
}

int meetingsort(const void *meetingA, const void *meetingB) {
   meeting * a = (meeting *)meetingA;
   meeting * b = (meeting *)meetingB;
   
   return (a->start - b->start);
}

