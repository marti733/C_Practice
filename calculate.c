/* stdin is used as input for a program that will calcuate a value based
   on the user input of a base and power */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

double calculate (double, int);

int main (int argc, char ** argv) {
	//Check for number of inputs
	if (argc < 3) {
		printf("Error: Base is input followed by exponent. \n Example: \n ./P1 2 2 \n");
		return EXIT_FAILURE;
	}

	//Convert Strings to numbers
	const char * err_str = NULL;

	double base =  strtod(argv[1], NULL);
	int power = atoi(argv[2]);

	//Check for successful conversions
	if (err_str != NULL) {
		printf("Error: The string input is %s.\n", err_str);
		return EXIT_FAILURE;
	}

	//Calculate Output
	double output = calculate(base, power);

	printf("Total is: %f \n", output);

	return EXIT_SUCCESS;
}

double calculate (double base, int power) {
	double total = base; 
	int i;

	if (power == 0) {
		total = 1;
	}
	else if (power > 0) {
		for (i = 1; i < power; i++) {
			total *= base;
		}
	} else {
		for (i = power + 1; i < 0; i++) {
			total *= base;
		}
		total = 1 / total;
	}

	return total;
}

