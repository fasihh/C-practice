#include <stdio.h>
#include <stdlib.h>

void SieveOfEratosthenes(int[], int);

int main() {
	int *numberList;
	int n;

	printf("Sieve of Eratosthenes\nPrints all prime numbers less than 'n'\n");
	printf("Input n: ");
	scanf("%d", &n);

	// creating list
	numberList = (int *)malloc((n - 3) * sizeof(int));

	if (numberList == NULL) {
		printf("Warning: didn't work");
		return 0;
	};

	// initializing list
	for(int i = 0; i < (n - 2); i++) {
		numberList[i] = i + 2;
	};

	printf("List of prime numbers:");
	SieveOfEratosthenes(numberList, n);

	free(numberList);
};

void SieveOfEratosthenes(int numberList[], int n) {
	int skip;

	// main loop 
	for(int j = 0; j < (n - 2); j++) {
		if(numberList[j] == 0) {continue;};

		skip = numberList[j];
		printf(" %d", skip);

		// removal loop
		for (int k = j; k < (n - 2); k += skip) {
			numberList[k] = 0;
		};
	};
};
