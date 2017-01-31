#include <stdio.h>

int main (int argc, char ** argv) {
	int size, i, temp;	

	printf("Enter array size: ");
	scanf("%d", &size);

	int arr[size];
	
	printf("Enter %d numbers: ", size);
	for (i = 0; i <  size; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < size / 2; i++) {
		temp = arr[size - i - 1];
		arr[size - i - 1] = arr[i];
		arr[i] = temp;
	}

	printf("[");
	for (i = 0; i < size; i++) {
		printf(" %d", arr[i]);
	}
	printf("]\n");

	return 0;	
}
