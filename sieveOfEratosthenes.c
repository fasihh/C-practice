#include <stdio.h>
#include <stdlib.h>

int SieveOfErathenoeous(int);

void main() {
	int n;

	printf("Sieve of Eratosthenes\nPrints all prime numbers less than 'n'\n");
	printf("Input n: 25\n");
	scanf("%d", n);

	printf("List of prime numbers:");
	SieveOfErathenoeous(n);
};

int SieveOfErathenoeous(int n) {
	int *numberList;
	int skip;

	numberList = (int *)malloc((n - 3) * sizeof(int));

	if (numberList == NULL) {
		printf("Warning: didn't work");
		return 0;
	};

	// initializing list
	for(int i = 0; i < (n - 2); i++) {
		numberList[i] = i + 2;
	};

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