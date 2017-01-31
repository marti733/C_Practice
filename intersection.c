//
//  intersection.c
//  
//
//  Created by Cheyenne Martinez on 1/30/17.
//
//

#include <stdio.h>

typedef struct {
   int x;
   int y;
   int width;
   int height;
} box;

box find_overlap(box, box);

int main (int argc, char ** argv) {
   box a, b;
   
   a.x = 0;
   a.y = 0;
   a.width = 10;
   a.height = 10;
   
   b.x = 10;
   b.y = 2;
   b.width = 2;
   b.height = 7;
   
   box overlap = find_overlap(a, b);
   
   if (overlap.width == 0) {
      printf("No box created\n");
      return 0;
   }
   printf("X: %d\nY: %d\nWidth: %d\nHeight: %d\n", overlap.x, overlap.y, overlap.width, overlap.height);
   
   return 0;
}

box find_overlap(box a, box b) {
   box result;
   
   // Find left bound and width
   if ((a.x >= b.x) && (a.x <= (b.x + b.width))) {
      result.x = a.x;
      result.width = b.x + b.width - a.x;
   }
   else if ((b.x >= a.x) && (b.x <= (a.x + a.width))) {
      result.x = b.x;
      result.width = a.x + a.width - b.x;
   }
   else {
      result.x = 0;
      result.y = 0;
      result.width = 0;
      result.height = 0;
      return result;
   }
   
   // Find bottom bound and height
   if ((a.y >= b.y) && (a.y <= (b.y + b.height))){
      result.y = a.y;
      result.height = b.y + b.height - a.y;
   }
   else if ((b.y >= a.y) && (b.y <= (a.y + a.height))) {
      result.y = b.y;
      result.height = a.y + a.height - b.y;
   }
   else {
      result.x = 0;
      result.y = 0;
      result.width = 0;
      result.height = 0;
      return result;
   }
   
   return result;
   
}
