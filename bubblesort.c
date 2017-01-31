/* Use stdin as input for array that will be bubble sorted */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int * bubble(int *, int); 

int main(int argc, char ** argv) {
	int arr[200];
	int size = 0;
	int i, j;
	char new;

	printf("Enter each number on a new line, enter d when done \n");
	
	for (i = 0; i <= size; i++) {
		scanf("%c", &new);
		if (new != 'd') {
			size++;
			arr[i] = new - '0';
		}
		scanf("%c", &new);
	}

	int *arr2 = (int*)malloc(sizeof(int) * (size + 1));

	memcpy(arr2, arr, (size + 1) * sizeof(int));

	arr2 = bubble(arr2, size);

	printf("Sorted %d inputs: \n", size);
	
	for (j = 1; j <= size; j++) {
		printf(" %d", arr2[j]);
	}
	
	printf("\n");

	free(arr2);
}

int * bubble(int* arr, int size) {

	int i, j, temp;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	return arr;
} 
