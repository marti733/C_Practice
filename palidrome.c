/* Palidrome detector via an array */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char ** argv) {
	bool state = true;
	char * word = NULL;
	int i, size;
	
	printf("Enter a word: ");
	gets(word);

	size = strlen(word);

	for (i = 0; i < size / 2; i++) {
		printf("Here\n");
		if (word[i] != word[size - i - 1]) {
			state = false;
		}
	}
	

	if (state == false) {
		printf("The word entered is not a palidrome.\n");
	} else {
		printf("The word entered is a palidrome. \n");
	}

	return 0;
}
