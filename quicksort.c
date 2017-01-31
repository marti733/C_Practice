#include <stdio.h>
#include <stdlib.h>

void quicksort( int *, int, int);
int main (int argc, char ** argv) {
	int * array = NULL;
	int size, i;

	printf("Enter the size of the array: ");
	scanf("%d", &size);

	array = (int *) malloc(sizeof(int) * size);
	if (array == NULL) {
		printf("Error: Cannot allocate memory");
		free(array);
		return EXIT_FAILURE;
	}

	printf("Enter %d elements: ", size);
	for (i = 0; i < size; i++) {
		scanf("%d", &array[i]);
	}

	quicksort(array, 0, size - 1);

	printf("Sorted elements:");
	for (i = 0; i < size; i++) {
		printf(" %d", array[i]);
	}
	printf("\n");

	// free(array);

	return EXIT_SUCCESS;
}

void quicksort (int * array, int low, int high) {
	int pivot, i, j, temp;

	if (low < high) {
		pivot = low;
		i = low;
		j = high;
		
		while( i < j) {
			while (array[i] < array[pivot] && (i < high)) {
				i++;
			}
		
			while (array[j] > array[pivot]) {
				j--;
			}
			
			if ( i < j) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
		
		temp = array[pivot];
		array[pivot] = array[j];
		array[j] = temp;
	
		quicksort(array, j + 1, high);
		quicksort(array, low, j - 1);

	}
}
